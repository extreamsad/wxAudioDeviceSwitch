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
	m_mainform = new MainForm(NULL);
	m_mainform->Show(false);
	
	return true;
}

int wxMyApp::OnExit()
{
	delete m_checker;
	return 0;

}

int wxMyApp::FilterEvent(wxEvent & event)
{
	if((event.GetEventType() == wxEVT_KEY_DOWN) &&
		(((wxKeyEvent&)event).GetKeyCode() == WXK_F1))
	{
		//m_mainform->OnHelpF1((wxKeyEvent&)event);
		return true;
	}

	return -1;
}

IMPLEMENT_APP(wxMyApp)
