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

MainForm::MainForm(wxWindow* parent) :
	MainFormBase(parent)
{
	int nSoundCardCount = waveOutGetNumDevs();

	for (int i = 0; i < nSoundCardCount; i++)
	{
		WAVEOUTCAPS woc;
		waveOutGetDevCaps(i, &woc, sizeof(woc));
		
	}
}

MainForm::~MainForm()
{
}
