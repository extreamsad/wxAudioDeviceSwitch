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


void MainForm::OnMainMenuClose(wxCommandEvent & event)
{
	Close();
}

MainForm::MainForm(wxWindow* parent) :
	MainFormBase(parent)
{

	//**m_taskbar = new MyTaskBarIcon(this);
	if (!m_taskbar->SetIcon(wxArtProvider::GetBitmapBundle(wxART_WX_LOGO, wxART_OTHER, wxSize(32, 32)),
		"Audio Device Switcher\n"
		"(created by extream)"))
	{
//		wxLogError("Could not set icon.");
	} /*/
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
