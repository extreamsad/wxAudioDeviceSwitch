#include "MyTaskBarIcon.h"



MyTaskBarIcon::MyTaskBarIcon(wxWindow * parent)
{	
}


MyTaskBarIcon::~MyTaskBarIcon()
{
}

void MyTaskBarIcon::OnLeftButtonDClick(wxTaskBarIconEvent &)
{
	m_main_form->Show();
}

void MyTaskBarIcon::OnMenuRestore(wxCommandEvent &)
{
	m_main_form->Show();
}

void MyTaskBarIcon::OnMenuExit(wxCommandEvent &)
{
	m_main_form->Close(true);
}

void MyTaskBarIcon::OnMenuSetNewIcon(wxCommandEvent &)
{
}

wxMenu * MyTaskBarIcon::CreatePopupMenu()
{	
	wxMenu * popup_menu = new wxMenu();
	wxMenuItem *menu_close = new wxMenuItem(popup_menu, wxID_ANY, wxString(wxT("Exit")), wxEmptyString, wxITEM_NORMAL);
	wxMenuItem *menu_restore = new wxMenuItem(popup_menu, wxID_ANY, wxString(wxT("Restore")), wxEmptyString, wxITEM_NORMAL);
	popup_menu->Append(menu_restore);
	popup_menu->Append(menu_close);
	
	popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuExit), this, menu_close->GetId());
	popup_menu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyTaskBarIcon::OnMenuRestore), this, menu_restore->GetId());
	this->Bind(wxEVT_TASKBAR_LEFT_DCLICK, &MyTaskBarIcon::OnLeftButtonDClick, this);
	return popup_menu;
}
