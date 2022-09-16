#pragma once

#include "MainForm.h"
#include <wx/taskbar.h>

class MainForm;
class MyTaskBarIcon : 
	public wxTaskBarIcon
{	
	MainForm *m_main_form = nullptr;	
public:
	MyTaskBarIcon(MainForm* parent);
	~MyTaskBarIcon();

	void OnLeftButtonDClick(wxTaskBarIconEvent&);
	void OnMenuOptions(wxCommandEvent&);
	void OnShowPopupMenu(wxUpdateUIEvent& event);
	void OnMenuExit(wxCommandEvent&);
	void OnMenuSetNewIcon(wxCommandEvent&);
	void OnMenuAudioDevice(wxCommandEvent&);
	wxMenu *CreatePopupMenu() override;
};

