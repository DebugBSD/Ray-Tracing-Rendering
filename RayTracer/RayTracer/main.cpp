#include "stdafx.h"
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/timer.h>
#include <wx/dcclient.h>
#include <wx/rawbmp.h>
#include "MainFrame.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit() wxOVERRIDE;
};

wxDECLARE_APP(MyApp);

bool MyApp::OnInit()
{
    MainFrame* frame = new MainFrame(NULL);
    frame->Show();
    return true;
}

wxIMPLEMENT_APP(MyApp);