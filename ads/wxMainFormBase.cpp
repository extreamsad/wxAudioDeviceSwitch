///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-231-gdf7791bf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxMainFormBase.h"

///////////////////////////////////////////////////////////////////////////

MainFormBase::MainFormBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_main_menu = new wxMenuBar( 0 );
	m_mm_file = new wxMenu();
	wxMenuItem* m_mm_close;
	m_mm_close = new wxMenuItem( m_mm_file, wxID_ANY, wxString( wxT("Close") ) , wxEmptyString, wxITEM_NORMAL );
	m_mm_file->Append( m_mm_close );

	m_main_menu->Append( m_mm_file, wxT("File") );

	this->SetMenuBar( m_main_menu );

	m_main_status_bar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	m_mm_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFormBase::OnMainMenuClose ), this, m_mm_close->GetId());
}

MainFormBase::~MainFormBase()
{
	// Disconnect Events

}
