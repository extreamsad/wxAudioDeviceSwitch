#include "wxMyApp.h"

wxMyApp::wxMyApp()	
{
}


wxMyApp::~wxMyApp()
{
}

bool wxMyApp::OnInit()
{
	m_checker = new wxSingleInstanceChecker();
	if (m_checker->IsAnotherRunning())
	{
		//wxLogError(_("Another program instance is already running, aborting."));
		delete m_checker; // OnExit() won't be called if we return false
		m_checker = NULL;

		return false;
	}

	wxInitAllImageHandlers();
	MainForm *mainForm = new MainForm(NULL);
	mainForm->Show(false);
	return true;
}

int wxMyApp::OnExit()
{
	delete m_checker;
	return 0;

}

IMPLEMENT_APP(wxMyApp)
