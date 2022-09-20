#include "MainForm.h"



HRESULT MainForm::SetDefaultAudioPlaybackDevice(LPCWSTR devID)
{
	IPolicyConfigVista *pPolicyConfig;
	ERole reserved = eConsole;

	HRESULT hr = CoCreateInstance(__uuidof(CPolicyConfigVistaClient),
		NULL, CLSCTX_ALL, __uuidof(IPolicyConfigVista), (LPVOID *)&pPolicyConfig);
	if (SUCCEEDED(hr))
	{
		hr = pPolicyConfig->SetDefaultEndpoint(devID, reserved);
		
		pPolicyConfig->Release();
	}
	return hr;

}

std::vector<WAVEOUTCAPS> MainForm::GetAudioPlaybackDevices()
{
	int nSoundCardCount = waveOutGetNumDevs();
	std::vector<WAVEOUTCAPS> devs;	
	for (int i = 0; i < nSoundCardCount; i++)
	{		
		WAVEOUTCAPS woc;
		waveOutGetDevCaps(i, &woc, sizeof(WAVEOUTCAPS));
		devs.emplace_back(woc);
	}
	return devs;
}

void MainForm::OnClose(wxCloseEvent & event)
{
	Show(false);
}

void MainForm::OnMainMenuClose(wxCommandEvent & event)
{
	Destroy();
}

void MainForm::OnHotkey(wxKeyEvent & event)
{
}

void MainForm::OnRegisterHotKey(wxCommandEvent & WXUNUSED)
{
	 if ( RegisterHotKey(0, wxMOD_ALT | wxMOD_SHIFT, WXK_HOME) )
		{
			//m_logText->AppendText("Try pressing Alt-Shift-Home anywhere now.\n");
		}
		else
		{
			//m_logText->AppendText("Failed to register hot key.\n");
		}
}

void MainForm::OnUnregisterHotKey(wxCommandEvent & WXUNUSED)
{
	/*
	if ( !UnregisterHotKey(0) )
		{
			m_logText->AppendText("Failed to unregister hot key.\n");
		}
		*/
}

MainForm::MainForm(wxWindow* parent) :
	MainFormBase(parent),
	m_taskbar(new MyTaskBarIcon(this))
{
	Bind(wxEVT_HOTKEY, &MainForm::OnHotkey, this);
	Bind(wxEVT_MENU, &MainForm::OnRegisterHotKey, this, HotKeyRegister);
	Bind(wxEVT_MENU, &MainForm::OnUnregisterHotKey, this, HotKeyUnregister);
//	NextAudioPlaybackDevice();
	//auto devs = EnumAudioPlaybackDevices();
	/*if (!m_taskbar->SetIcon(wxArtProvider::GetBitmapBundle(wxART_WX_LOGO, wxART_OTHER, wxSize(32, 32)),
		"Audio device switch\n"
		"(Created by eXtream)"))
	{
		wxLogError("Could not set icon.");
	} */
	
	/*/
	/*int nSoundCardCount = waveOutGetNumDevs();
	std::vector<std::wstring> devs;
	WAVEOUTCAPS *woc = new WAVEOUTCAPS();
	for (int i = 0; i < nSoundCardCount; i++)
	{
		
		ZeroMemory(woc, sizeof(WAVEOUTCAPS));
		waveOutGetDevCaps(i, woc, sizeof(WAVEOUTCAPS));
		devs.emplace_back(woc->szPname);
	}*/
}

MainForm::~MainForm()
{
}
