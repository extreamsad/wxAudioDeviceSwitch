#pragma once

#include "MainForm.h"
#include <wx/taskbar.h>

class MainForm;
class MyTaskBarIcon : 
	public wxTaskBarIcon
{	
	MainForm *m_main_form = nullptr;
public:
	MyTaskBarIcon(wxWindow * parent);
	~MyTaskBarIcon();

	void OnLeftButtonDClick(wxTaskBarIconEvent&);
	void OnMenuRestore(wxCommandEvent&);
	void OnMenuExit(wxCommandEvent&);
	void OnMenuSetNewIcon(wxCommandEvent&);
	wxMenu *CreatePopupMenu() override;
};

