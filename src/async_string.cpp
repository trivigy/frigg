#include <iostream>
#include "async_string.h"
#include "include/cef_app.h"

AsyncString::AsyncString() {}

//The string will contain the html
void AsyncString::Visit(const CefString &string) {
    std::cout << string.ToString() << std::endl;
    CefQuitMessageLoop();
}






