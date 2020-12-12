#pragma once
#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/dcclient.h>
#include <wx/rawbmp.h>

class MainFrame :
    public wxFrame
{
public:
    MainFrame(wxWindow* parent, int id = wxID_ANY, wxString title = "RayTracer",
        wxPoint pos = wxDefaultPosition, wxSize size = wxDefaultSize,
        int style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

    ~MainFrame();


private:
    // Event Handlers
    void OnPaint(wxPaintEvent& event);
    void OnTimer(wxTimerEvent& event);

    // Helper function
    void RebuildBufferAndRefresh();

    // Private data
    wxWindow* m_renderSurface;
    int m_width;
    int m_height;
    wxBitmap m_bitmapBuffer;
    wxTimer m_timer;
    int m_curRGB;
    unsigned char* m_pixelData;

};

