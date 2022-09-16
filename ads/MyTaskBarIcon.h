#pragma once

#include <wx/wx.h>
#include <wx/taskbar.h>


class MyTaskBarIcon : public wxTaskBarIcon
{
public:
	MyTaskBarIcon();
	~MyTaskBarIcon();

	void OnLeftButtonDClick(wxTaskBarIconEvent&);
	void OnMenuRestore(wxCommandEvent&);
	void OnMenuExit(wxCommandEvent&);
	void OnMenuSetNewIcon(wxCommandEvent&);
	wxMenu *CreatePopupMenu() override;
};

