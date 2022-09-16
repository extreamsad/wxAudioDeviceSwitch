#pragma once
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif


#include <map>
#include <string>

using namespace std;

class wxMyApp : public wxApp
{
public:
	wxMyApp();
	~wxMyApp();
	virtual bool OnInit() override;
};

