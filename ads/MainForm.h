#pragma once
#include "resource.h"

#include <windows.h>

#include <memory>

#include "wxMainFormBase.h"
#include "MyTaskBarIcon.h"

#include <wx/log.h>

#include <mmsystem.h>
#include <Propidl.h>
#include <mmdeviceapi.h>
#include "AudioPlaybackControl.h"

#include "PolicyConfig.h"

#pragma comment(lib, "Winmm.lib")

enum {
	HotKeyRegister = 105, 
	HotKeyUnregister
};

class MyTaskBarIcon;
class MainForm :
	public MainFormBase
{
	std::shared_ptr<MyTaskBarIcon> m_taskbar;
public:
	static HRESULT SetDefaultAudioPlaybackDevice(LPCWSTR devID);
	static std::vector<WAVEOUTCAPS> GetAudioPlaybackDevices();
	
	virtual void OnClose(wxCloseEvent& event) override;
	virtual void OnMainMenuClose(wxCommandEvent& event) override;
	
	void OnHotkey(wxKeyEvent& event);
	void OnRegisterHotKey(wxCommandEvent& WXUNUSED(event));
	void OnUnregisterHotKey(wxCommandEvent& WXUNUSED(event));
	MainForm(wxWindow* parent);
	~MainForm();
};

