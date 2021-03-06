#ifndef FRIGG_CLIENT_HANDLER_H
#define FRIGG_CLIENT_HANDLER_H


#include "include/cef_render_process_handler.h"
#include "include/cef_client.h"
#include "include/cef_v8.h"
#include "include/cef_browser.h"

#include <list>
#include <mqueue.h>

#define RENDER_WIDTH 1920
#define RENDER_HEIGHT 1080

class ClientHandle : public CefClient,
                      public CefLifeSpanHandler,
                      public CefLoadHandler {
    //                      public CefLoadHandler,
    //                      public CefRenderHandler {
public:
    ClientHandle();
    ClientHandle(char uid[37], mqd_t cli_mq);
    ~ClientHandle();

    CefRefPtr<CefBrowser> getMainBrowser();

    // CefClient methods
    virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE {return this;}
    virtual CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE {return this;}
    //    virtual CefRefPtr<CefRenderHandler> GetRenderHandler() OVERRIDE {return this;}

    // CefLifeSpanHandler methods
    virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
    virtual bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
    virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;

    // CefLoadHandler methods
    virtual void OnLoadEnd(
        CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        int httpStatusCode
    ) OVERRIDE;

    //    // CefRenderHandler methods
    //    virtual bool GetViewRect(CefRefPtr<CefBrowser> browser,
    //                             CefRect &rect) OVERRIDE;
    //    virtual void OnPaint(CefRefPtr<CefBrowser> browser,
    //                         CefRenderHandler::PaintElementType type,
    //                         const CefRenderHandler::RectList &dirtyRects,
    //                         const void *buffer, int width, int height) OVERRIDE;

private:
    typedef std::list<CefRefPtr<CefBrowser>> BrowserList;
    BrowserList browser_list;
    mqd_t cli_mq;
    char uid[37];

IMPLEMENT_REFCOUNTING(ClientHandle);
};

#endif  // FRIGG_CLIENT_HANDLER_H
