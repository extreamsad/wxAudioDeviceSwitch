#pragma once

#include "MainForm.h"
#include "AudioPlaybackControl.h"
#include <wx/taskbar.h>


class MainForm;
class MyTaskBarIcon : 
	public wxTaskBarIcon
{	
	MainForm *m_main_form = nullptr;	
	//std::shared_ptr<std::vector<WAVEOUTCAPS>> m_devices;
public:
	MyTaskBarIcon(MainForm* parent);
	~MyTaskBarIcon();

	void OnLeftButtonDClick(wxTaskBarIconEvent&);
	void OnMenuOptions(wxCommandEvent&);
	void OnMenuItemUpdateUI(wxUpdateUIEvent& event);
	void OnMenuExit(wxCommandEvent&);
	void OnMenuSetNewIcon(wxCommandEvent&);
	void OnMenuAutorun(wxCommandEvent&);
	wxMenu *CreatePopupMenu() override;
};

