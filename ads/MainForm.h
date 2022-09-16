#pragma once

#include <windows.h>

#include <memory>

#include "wxMainFormBase.h"
#include "MyTaskBarIcon.h"

#include <wx/log.h>

#include <mmsystem.h>
#include <Propidl.h>
#include <mmdeviceapi.h>

#include "PolicyConfig.h"

#pragma comment(lib, "Winmm.lib")

class MyTaskBarIcon;
class MainForm :
	public MainFormBase
{
	std::shared_ptr<MyTaskBarIcon> m_taskbar;
public:
	static HRESULT SetDefaultAudioPlaybackDevice(LPCWSTR devID);
	static std::vector<WAVEOUTCAPS> GetAudioPlaybackDevices();
	virtual void OnMenuTest(wxCommandEvent& event) override;
	virtual void OnClose(wxCloseEvent& event) override;
	virtual void OnMainMenuClose(wxCommandEvent& event) override;
	MainForm(wxWindow* parent);
	~MainForm();
};

