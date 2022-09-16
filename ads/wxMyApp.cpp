#include "wxMyApp.h"

wxMyApp::wxMyApp()
{
}


wxMyApp::~wxMyApp()
{
}

bool wxMyApp::OnInit()
{

	wxInitAllImageHandlers();
	MainForm *mainForm = new MainForm(NULL);
	mainForm->Show(true);
	return true;
}

IMPLEMENT_APP(wxMyApp)
