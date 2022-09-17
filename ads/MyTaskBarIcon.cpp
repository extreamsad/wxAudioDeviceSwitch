#include "MyTaskBarIcon.h"



MyTaskBarIcon::MyTaskBarIcon(MainForm* parent) 
{	
	m_main_form = parent;	
	this->Bind(wxEVT_TASKBAR_LEFT_DCLICK, &MyTaskBarIcon::OnLeftButtonDClick, this);
}


MyTaskBarIcon::~MyTaskBarIcon()
{
}

void MyTaskBarIcon::OnLeftButtonDClick(wxTaskBarIconEvent &)
{
	m_main_form->Show();
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
}

wxMenu * MyTaskBarIcon::CreatePopupMenu()
{		
	wxMenu *popup_menu = new wxMenu();
	wxMenuItem *menu_close = new wxMenuItem(popup_menu, wxID_ANY, wxString(wxT("Exit")), wxEmptyString, wxITEM_NORMAL);
	//wxMenuItem *menu_options = new wxMenuItem(popup_menu, wxID_ANY, wxString(wxT("Options")), wxEmptyString, wxITEM_NORMAL);

	m_devices.reset(new std::vector<WAVEOUTCAPS>());
	bool bDefDev = true;

	for (auto &device : MainForm::GetAudioPlaybackDevices())
	{
		m_devices->emplace_back(device);

		wxString dev_name{ device.szPname };		
		wxMenuItem *devs_menu = new wxMenuItem(popup_menu, wxID_ANY, dev_name, wxEmptyString, wxITEM_CHECK);
		
		popup_menu->Append(devs_menu);		
		popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, [device](wxCommandEvent&)
		{
			std::wstring str = wxString::Format(L"%d", 1).ToStdWstring();
			MainForm::SetDefaultAudioPlaybackDevice(str.c_str());
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
	
	popup_options_subm->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuAutorun), this, submenu_autorun->GetId());
	popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuExit), this, menu_close->GetId());
	//popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuOptions), this, menu_options->GetId());
	return popup_menu;
}
