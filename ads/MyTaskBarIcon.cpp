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

void MyTaskBarIcon::OnMenuExit(wxCommandEvent &)
{
	m_main_form->Destroy();
}

void MyTaskBarIcon::OnMenuSetNewIcon(wxCommandEvent &)
{
}

wxMenu * MyTaskBarIcon::CreatePopupMenu()
{		
	wxMenu *popup_menu = new wxMenu();
	wxMenuItem *menu_close = new wxMenuItem(popup_menu, wxID_ANY, wxString(wxT("Exit")), wxEmptyString, wxITEM_NORMAL);
	wxMenuItem *menu_options = new wxMenuItem(popup_menu, wxID_ANY, wxString(wxT("Options")), wxEmptyString, wxITEM_NORMAL);

	auto devs = MainForm::GetAudioPlaybackDevices();
	for (auto &d : devs)
	{
		wxMenuItem *devs_menu= new wxMenuItem(popup_menu, wxID_ANY, wxString(d.szPname), wxEmptyString, wxITEM_NORMAL);
		popup_menu->Append(devs_menu);
	}
	popup_menu->AppendSeparator();
	popup_menu->Append(menu_options);
	popup_menu->Append(menu_close);

	popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuExit), this, menu_close->GetId());
	popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuOptions), this, menu_options->GetId());
	return popup_menu;
}
