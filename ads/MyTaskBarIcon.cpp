#include "MyTaskBarIcon.h"



MyTaskBarIcon::MyTaskBarIcon(MainForm* parent)	
{	
	m_main_form = parent;	
	this->Bind(wxEVT_TASKBAR_LEFT_DCLICK, &MyTaskBarIcon::OnLeftButtonDClick, this);
	//SetIcon(wxBitmapBundle::FromBitmaps(wxBitmap("main.bmp", wxBITMAP_TYPE_BMP_RESOURCE), wxBitmap()));
	SetIcon(wxBitmapBundle::FromBitmaps(wxBitmap(wxT("#103"), wxBITMAP_TYPE_ICO_RESOURCE), wxBitmap()));
}


MyTaskBarIcon::~MyTaskBarIcon()
{	
}

void MyTaskBarIcon::OnLeftButtonDClick(wxTaskBarIconEvent &)
{
}

void MyTaskBarIcon::OnMenuOptions(wxCommandEvent &)
{
	m_main_form->Show();
}

void MyTaskBarIcon::OnMenuItemUpdateUI(wxUpdateUIEvent & event)
{	
	if (!event.GetChecked()) 
	{
	}
	//event.Check(*bflag);
}

void MyTaskBarIcon::OnMenuExit(wxCommandEvent &)
{
	m_main_form->Destroy();
}

void MyTaskBarIcon::OnMenuSetNewIcon(wxCommandEvent &)
{
}

void MyTaskBarIcon::OnMenuAutorun(wxCommandEvent &)
{
	wxRegKey key_hklm_run(wxRegKey::HKLM, m_autorun_key_path);
	key_hklm_run.Open();
	
	!key_hklm_run.HasValue(m_key_name) ?			
		key_hklm_run.SetValue(m_key_name, wxString::Format("\"%s\"", wxStandardPaths::Get().GetExecutablePath())) :
		key_hklm_run.DeleteValue(m_key_name);
	key_hklm_run.Close();
}

wxMenu * MyTaskBarIcon::CreatePopupMenu()
{		
	wxMenu *popup_menu = new wxMenu();
	wxMenuItem *menu_close = new wxMenuItem(popup_menu, wxID_ANY, wxString(wxT("Exit")), wxEmptyString, wxITEM_NORMAL);
	//wxMenuItem *menu_options = new wxMenuItem(popup_menu, wxID_ANY, wxString(wxT("Options")), wxEmptyString, wxITEM_NORMAL);

	bool bDefDev = true;

	for (auto &device : EnumAudioPlaybackDevices())
	{
		wxMenuItem *devs_menu = new wxMenuItem(popup_menu, wxID_ANY, device.first, wxEmptyString, wxITEM_CHECK);
		std::wstring DevID = device.second;
		popup_menu->Append(devs_menu);		
		popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, [DevID](wxCommandEvent& event)
		{			
			MainForm::SetDefaultAudioPlaybackDevice(DevID.c_str());
		}, devs_menu->GetId());
		this->Connect(devs_menu->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyTaskBarIcon::OnMenuItemUpdateUI));

		if (bDefDev) 
		{
			devs_menu->Check(bDefDev);
			bDefDev = false;
		}
	}
	popup_menu->AppendSeparator();

	wxMenu *popup_options_subm = new wxMenu();
	wxMenuItem *submenu_autorun = new wxMenuItem(popup_options_subm, wxID_ANY, wxString(wxT("Start with system")), wxEmptyString, wxITEM_CHECK);
	

	popup_options_subm->Append(submenu_autorun);
	popup_menu->AppendSubMenu(popup_options_subm, wxString(wxT("Options")));

	wxMenu *popup_languages_subm = new wxMenu();
	popup_options_subm->AppendSubMenu(popup_languages_subm, wxString(wxT("Languages")));

	popup_menu->AppendSeparator();
	//popup_menu->Append(menu_options);
	popup_menu->Append(menu_close);	

	wxRegKey key_hklm_run(wxRegKey::HKLM, m_autorun_key_path);
	submenu_autorun->Check(key_hklm_run.HasValue(m_key_name));
	key_hklm_run.Close();

	popup_options_subm->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuAutorun), this, submenu_autorun->GetId());
	popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuExit), this, menu_close->GetId());
	//popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuOptions), this, menu_options->GetId());
	return popup_menu;
}
