#pragma once

#include "MainForm.h"
#include "AudioPlaybackControl.h"

#include <wx/taskbar.h>
#include <wx/msw/registry.h>
#include <wx/stdpaths.h>

class MainForm;
class MyTaskBarIcon : 
	public wxTaskBarIcon
{	
	MainForm *m_main_form = nullptr;
	wxString m_autorun_key_path = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
	wxString m_key_name = "ads";
	//std::shared_ptr<wxRegKey> key_hklm_run;
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

