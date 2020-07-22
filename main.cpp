#include <iostream>
#include <windows.h>
//#include <thread>
//#include <string>
//#include <tchar.h>
#include <conio.h>
//#include <wincon.h>
//#include <codecvt>
//#include <locale>
#include "asciipaintstructure.h"
using namespace std;

/*string utf8_to_string(const char *utf8str, const locale& loc)
{
    wstring_convert<codecvt_utf8<wchar_t>> wconv;
    wstring wstr = wconv.from_bytes(utf8str);

    //vector<char> buf(wstr.size());
    //use_facet<ctype<wchar_t>>(loc).narrow(wstr.data(),wstr.data()+wstr.size()'?',buf.data());
    //return string (buf.data(),buf.size());
}*/

int main(/*int argc, char* argv*/)
{
    /*string ansi;
    char utf8txt[] = {0xc3, 0xa1, 0};

    ansi = utf8_to_string(utf8txt, locale(".1252"));*/
    /* BETA 0.4.0
    BOOL SetWindowTextA(){
        HWND hWnd,
        LPCSTR lpString
    };
    */
    //BETA: Code to set window title 0.4.0
    /*
    TCHAR szOldTitle[MAX_PATH];
    TCHAR szNewTitle[MAX_PATH];
    if(GetConsoleTitle(szOldTitle, MAX_PATH))
        {
            StringCchPrintf(szNewTitle, MAX_PATH, TEXT("TEST: A%s"), szOldTitle);
            if(!SetConsoleTitle(szNewTitle))
            {
                _tprintf(TEXT("SetConsoleTitle failed (%d)\n"), GetLastError());
                return 1;
            }else{
                _tprintf(TEXT("Character Painter\n"));
            }
        }
    */
    //Main Program
    system("title ASCIIPaint v1.2.0.1 beta");
    asciiPaintStructure asciiPaintStructureObject;
    asciiPaintStructureObject.asciiPaintInfo();

    return 0;
}
