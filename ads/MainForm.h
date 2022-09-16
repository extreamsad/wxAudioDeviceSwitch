#pragma once

#include <windows.h>

#include "wxMainFormBase.h"
#include "MyTaskBarIcon.h"


#include <mmsystem.h>
#include <Propidl.h>
#include <mmdeviceapi.h>

#include "PolicyConfig.h"

#pragma comment(lib, "Winmm.lib")

class MyTaskBarIcon;
class MainForm :
	public MainFormBase
{
	MyTaskBarIcon *m_taskbar = nullptr;
public:
	HRESULT SetDefaultAudioPlaybackDevice(LPCWSTR devID);
	virtual void OnMainMenuClose(wxCommandEvent& event) override;
	MainForm(wxWindow* parent);
	~MainForm();
};

