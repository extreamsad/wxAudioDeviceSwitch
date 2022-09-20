#pragma once
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/snglinst.h>

#include "MainForm.h"

#include <map>
#include <string>

using namespace std;

class wxMyApp : public wxApp
{
	wxSingleInstanceChecker *m_checker = nullptr;
	MainForm *m_mainform = nullptr;
public:
	wxMyApp();
	~wxMyApp();
	virtual bool OnInit() override;
	virtual int OnExit() override;
	virtual int FilterEvent(wxEvent& event) override;
};

