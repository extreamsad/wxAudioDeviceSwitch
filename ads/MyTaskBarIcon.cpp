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

void MyTaskBarIcon::OnMenuAudioDevice(wxCommandEvent &)
{
}

wxMenu * MyTaskBarIcon::CreatePopupMenu()
{		
	wxMenu *popup_menu = new wxMenu();
	wxMenuItem *menu_close = new wxMenuItem(popup_menu, wxID_ANY, wxString(wxT("Exit")), wxEmptyString, wxITEM_NORMAL);
	wxMenuItem *menu_options = new wxMenuItem(popup_menu, wxID_ANY, wxString(wxT("Options")), wxEmptyString, wxITEM_NORMAL);

	m_devices.reset(new std::vector<WAVEOUTCAPS>());
	bool bDefDev = true;

	for (auto &d : MainForm::GetAudioPlaybackDevices())
	{
		m_devices->emplace_back(d);

		wxString dev_name{ d.szPname };		
		wxMenuItem *devs_menu = new wxMenuItem(popup_menu, wxID_ANY, dev_name, wxEmptyString, wxITEM_CHECK);

		popup_menu->Append(devs_menu);
		popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuAudioDevice), this, devs_menu->GetId());
		this->Connect(devs_menu->GetId(), wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyTaskBarIcon::OnMenuItemUpdateUI));

		if (bDefDev) 
		{
			devs_menu->Check(bDefDev);
			bDefDev = false;
		}
	}
	popup_menu->AppendSeparator();
	popup_menu->Append(menu_options);
	popup_menu->Append(menu_close);
	
	popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuExit), this, menu_close->GetId());
	popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuOptions), this, menu_options->GetId());
	return popup_menu;
}
