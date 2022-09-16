#pragma once
#include <windows.h>

#include "wxMainFormBase.h"

#include <mmsystem.h>

#include <Propidl.h>
//#include <Functiondiscoverykeys_devpkey.h>
#include <iostream>
#include <mmdeviceapi.h>

#include "PolicyConfig.h"

#pragma comment(lib, "Winmm.lib")

class MainForm :
	public MainFormBase
{

public:
	HRESULT SetDefaultAudioPlaybackDevice(LPCWSTR devID);
	MainForm(wxWindow* parent);
	~MainForm();
};

