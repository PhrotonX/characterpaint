#include "characters.h"
#include "asciipaintStructure.h"
#include "saveMechanics.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <codecvt>
#include <locale>
#include <fstream>
using namespace std;

asciiPaintStructure asciiPaintStructureObject;
saveMechanics saveMechanicsObject;

static char block;
static int directScreenClear;
/*
No label: v0.1.0 Blocks
w/ label: Other versions
*/

void characters::clearScreen(int clearScreenMode){
    cout << "ENABLE CLEAR SCREEN? (BETA)\n\n";
    cout << "To use clear screen on painting mode, press W.\n";
    cout << "1 = Enable, 0 - Disable\n";
    cin >> clearScreenMode;
    switch(clearScreenMode){
    case 1:
        clearScreenMode = 1;
        system("cls");
        asciiPaintStructureObject.settings(clearScreenMode);
        //directScreenClear = clearScreenMode;
        directScreenClear = 1;
        break;
    case 0:
        clearScreenMode = 0;
        asciiPaintStructureObject.settings(clearScreenMode);
        //directScreenClear = clearScreenMode;
        directScreenClear = 0;
        break;
    }

}

void characters::paintCharacters(){


    cin >> block;

    fstream file("saveData.txt",ios::in|ios::out|ios::app);
        if(file.is_open()){
            file << block;
            file.seekg(256);
            string line;
            while(block=='0'){
                getline(file,line);
                file << block << "\n";
                paintCharacters();
        }
        while(!file.is_open()){
            file.close();
            }
        }

    const WORD colors[] =
    {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
        0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
        0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
        0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
        0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
        0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
        0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
        0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
        0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
        0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
        0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
        0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
    };

    HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
	WORD   index   = 0;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi);


    switch(block){
/*
case 's': //@note Plan for 0.4.0
    cout << "SAVE BUTTON - COMING SOON" << endl;
    paintCharacters();
    break;
*/
case 'A':   //v0.1.0
    static char letterBlock;
    cin >> letterBlock;
    switch(letterBlock){ //Unlabeled = 0.2.0
    case 'A': //0.2.0
        cout << "A";
        paintCharacters();
        break;
    case 'a': //0.2.0
        cout << "a";
        paintCharacters();
        break;
    case 'B': //0.2.0
        cout << "B";
        paintCharacters();
        break;
    case 'b': //0.2.0
        cout << "b";
        paintCharacters();
        break;
    case 'C': //0.2.0
        cout << "C";
        paintCharacters();
        break;
    case 'c': //0.2.0
        cout << "c";
        paintCharacters();
        break;
    case 'D': //Letters A-Z Except Letter 'O' 'o' came from 0.2.0
        cout << "D";
        paintCharacters();
        break;
    case 'd':
        cout << "d";
        paintCharacters();
        break;
    case 'E':
        cout << "E";
        paintCharacters();
        break;
    case 'e':
        cout << "e";
        paintCharacters();
        break;
    case 'F':
        cout << "F";
        paintCharacters();
        break;
    case 'f':
        cout << "f";
        paintCharacters();
        break;
    case 'G':
        cout << "G";
        paintCharacters();
        break;
    case 'g':
        cout << "g";
        paintCharacters();
        break;
    case 'H':
        cout << "H";
        paintCharacters();
        break;
    case 'h':
        cout << "h";
        paintCharacters();
        break;
    case 'I':
        cout << "I";
        paintCharacters();
        break;
    case 'i':
        cout << "i";
        paintCharacters();
        break;
    case 'J':
        cout << "J";
        paintCharacters();
        break;
    case 'j':
        cout << "j";
        paintCharacters();
        break;
    case 'K':
        cout << "K";
        paintCharacters();
        break;
    case 'k':
        cout << "K";
        paintCharacters();
        break;
    case 'L':
        cout << "L";
        paintCharacters();
        break;
    case 'l':
        cout << "l";
        paintCharacters();
        break;
    case 'M':
        cout << "M";
        paintCharacters();
        break;
    case 'm':
        cout << "m";
        paintCharacters();
        break;
    case 'N':
        cout << "N";
        paintCharacters();
        break;
    case 'n':
        cout << "n";
        paintCharacters();
        break;
    case 'O': //0.1.0
        cout << "O";
        paintCharacters();
        break;
    case 'o': //0.1.0
        cout << "o";
        paintCharacters();
        break;
    case 'P':
        cout << "P";
        paintCharacters();
        break;
    case 'p':
        cout << "p";
        paintCharacters();
        break;
    case 'Q':
        cout << "Q";
        paintCharacters();
        break;
    case 'q':
        cout << "q";
        paintCharacters();
        break;
    case 'R':
        cout << "R";
        paintCharacters();
        break;
    case 'r':
        cout << "r";
        paintCharacters();
        break;
    case 'S':
        cout << "S";
        paintCharacters();
        break;
    case 's':
        cout << "s";
        paintCharacters();
        break;
    case 'T':
        cout << "T";
        paintCharacters();
        break;
    case 't':
        cout << "t";
        paintCharacters();
        break;
    case 'U':
        cout << "U";
        paintCharacters();
        break;
    case 'u':
        cout << "u";
        paintCharacters();
        break;
    case 'V':
        cout << "V";
        paintCharacters();
        break;
    case 'v':
        cout << "v";
        paintCharacters();
        break;
    case 'W':
        cout << "W";
        paintCharacters();
        break;
    case 'w':
        cout << "w";
        paintCharacters();
        break;
    case 'X':
        cout << "X";
        paintCharacters();
        break;
    case 'x':
        cout << "x";
        paintCharacters();
        break;
    case 'Y':
        cout << "Y";
        paintCharacters();
        break;
    case 'y':
        cout << "y";
        paintCharacters();
        break;
    case 'Z':
        cout << "Z";
        paintCharacters();
        break;
    case 'z':
        cout << "z";
        paintCharacters();
         break;
    }
case 'N': //NUMBERS 0.3.0
    static char numberBlock;
    cin >> numberBlock;
    switch (numberBlock){
    case '0'://0.1.0 - 0.3.0
        cout << "0";
        paintCharacters();
        break;
    case '1':
        cout << "1";
        paintCharacters();
        break;
    case '2':
        cout << "2";
        paintCharacters();
        break;
    case '3':
        cout << "3";
        paintCharacters();
        break;
    case '4':
        cout << "4";
        paintCharacters();
        break;
    case '5':
        cout << "5";
        paintCharacters();
        break;
    case '6':
        cout << "6";
        paintCharacters();
        break;
    case '7':
        cout << "7";
        paintCharacters();
        break;
    case '8':
        cout << "8";
        paintCharacters();
        break;
    case '9':
        cout << "9";
        paintCharacters();
        break;
    }
case '~':
    static char symbolBlock;
    cin >> symbolBlock;
    switch(symbolBlock){
    case '!': //0.4.0
        cout << "!";
        paintCharacters();
        break;
    case '@':
        cout << "@";
        paintCharacters();
        break;
    case '#':
        cout << "#";
        paintCharacters();
        break;
    case '$':
        cout << "$";
        paintCharacters();
        break;
    case '%':
        cout << "%";
        paintCharacters();
        break;
    case '^':
        cout << "^";
        paintCharacters();
        break;
    case '&':
        cout << "&";
        paintCharacters();
        break;
    case '*':
        cout << "*";
        paintCharacters();
        break;
    case '(':
        cout << "(";
        paintCharacters();
        break;
    case ')':
        cout << ")";
        paintCharacters();
        break;
    case '[': //0.1.0 //Labeled under 0.1.0, moved to access variable ~ with 0.4.0
        cout << "["; //Classified as Line. L = Line
        paintCharacters(); // L
        break;
    case '\\': //0.1.0 L
        cout << "\\";
        paintCharacters();
        break;
    case '|': //0.1.0 L
        cout << "|";
        paintCharacters();
        break;
    case '-': //0.1.0 L
        cout << "-";
        paintCharacters();
        break;
    case '_': //0.1.0 L
        cout << "_";
        paintCharacters();
        break;
    case '{':
        cout << "{";
        paintCharacters();
        break;
    case '}':
        cout << "}";
        paintCharacters();
        break;
    case '/': //0.4.0 L
        cout << "/";
        paintCharacters();
        break;
    case '\'':
        cout << "'";
        paintCharacters();
        break;
    case '"':
        cout << "\"";
        paintCharacters();
        break;
    case ';':
        cout << ";";
        paintCharacters();
        break;
    case ':':
        cout << ":";
        paintCharacters();
        break;
    case '<': //L
        cout << "<";
        paintCharacters();
        break;
    case '>': //L
        cout << ">";
        paintCharacters();
        break;
    case ',':
        cout << ",";
        paintCharacters();
        break;
    case '.':
        cout << ".";
        paintCharacters();
        break;
    case '?':
        cout << "?";
        paintCharacters();
        break;
    case '+':
        cout << "+";
        paintCharacters();
        break;
    case '=': //L
        cout << "=";
        paintCharacters();
        break;
    case '~': //L
        cout << "~";
        paintCharacters();
        break;
    }
case '`':
    static char specialLetterBlock;
    cin >> specialLetterBlock;
    switch(specialLetterBlock){
    case 'q': //0.5.0
        cout << "€";
        paintCharacters();
        break;
    case 'w':
        cout << "";
        paintCharacters();
        break;
    case 'e':
        cout << "‚";
        paintCharacters();
        break;
    case 'r':
        cout << "ƒ";
        paintCharacters();
        break;
    case 't':
        cout << "„";
        paintCharacters();
        break;
    case 'y':
        cout << "…";
        paintCharacters();
        break;
    case 'u':
        cout << "†";
        paintCharacters();
        break;
    case 'i':
        cout << "‡";
        paintCharacters();
        break;
    case 'o':
        cout << "ˆ";
        paintCharacters();
        break;
    case 'p':
        cout << "‰";
        paintCharacters();
        break;
    case 'a':
        cout << "Š";
        paintCharacters();
        break;
    case 's':
        cout << "Œ";
        paintCharacters();
        break;
    case 'd':
        cout << "";
        paintCharacters();
        break;
    case 'f':
        cout << "Ž";
        paintCharacters();
        break;
    case 'g':
        cout << "";
        paintCharacters();
        break;
    case 'h':
        cout << "";
        paintCharacters();
        break;
    case 'j':
        cout << "‹";
        paintCharacters();
        break;
    case 'k':
        cout << "‘";
        paintCharacters();
        break;
    case 'l':
        cout << "’";
        paintCharacters();
        break;
    case 'z':
        cout << "“";
        paintCharacters();
        break;
    case 'x':
        cout << "”";
        paintCharacters();
        break;
    case 'c':
        cout << "•";
        paintCharacters();
        break;
    case 'v':
        cout << "–";
        paintCharacters();
        break;
    case 'b':
        cout << "—";
        paintCharacters();
         break;
    case 'n':
        cout << "™";
        paintCharacters();
        break;
    case 'm':
        cout << "š";
        paintCharacters();
        break;
    case 'Q':
        cout << "˜";
        paintCharacters();
        break;
    case 'W':
        cout << "œ";
        paintCharacters();
        break;
    case 'E':
        cout << "";
        paintCharacters();
        break;
    case 'R':
        cout << "ž";
        paintCharacters();
        break;
    case 'T':
        cout << "Ÿ";
        paintCharacters();
        break;
    case 'Y':
        cout << " ";
        paintCharacters();
        break;
    case 'U':
        cout << "¡";
        paintCharacters();
        break;
    case 'I':
        cout << "¢";
        paintCharacters();
        break;
    case 'O':
        cout << "£";
        paintCharacters();
        break;
    case 'P':
        cout << "¤";
        paintCharacters();
        break;
    case 'A':
        cout << "¥";
        paintCharacters();
        break;
    case 'S':
        cout << "›";
        paintCharacters();
        break;
    case 'D': //0.7.0
        cout << "à";
        paintCharacters();
        break;
    case 'F':
        cout << "á";
        paintCharacters();
        break;
    case 'G':
        cout << "â";
        paintCharacters();
        break;
    case 'H':
        cout << "ã";
        paintCharacters();
        break;
    case 'J':
        cout << "ä";
        paintCharacters();
        break;
    case 'K':
        cout << "å";
        paintCharacters();
        break;
    case 'L':
        cout << "æ";
        paintCharacters();
        break;
    case 'Z':
        cout << "ç";
        paintCharacters();
        break;
    case 'X':
        cout << "è";
        paintCharacters();
        break;
    case 'C':
        cout << "é";
        paintCharacters();
        break;
    case 'V':
        cout << "ê";
        paintCharacters();
        break;
    case 'B':
        cout << "ë";
        paintCharacters();
        break;
    case 'N':
        cout << "ì";
        paintCharacters();
        break;
    case 'M':
        cout << "í";
        paintCharacters();
        break;
    case ',':
        cout << "î";
        paintCharacters();
        break;
    case '.':
        cout << "ï";
        paintCharacters();
        break;
    case '/':
        cout << "ð";
        paintCharacters();
        break;
    }
case 'z':
    static char specialSymbolBlock;
    cin >> specialSymbolBlock;
    char special1;
    switch(specialSymbolBlock){
    case 'q': //0.6.0
        cout << "¦";
        paintCharacters();
        break;
    case 'w':
        cout << "§";
        paintCharacters();
        break;
    case 'e':
        cout << "¨";
        paintCharacters();
        break;
    case 'r':
        cout << "©";
        paintCharacters();
        break;
    case 't':
        cout << "ª";
        paintCharacters();
        break;
    case 'y':
        cout << "«";
        paintCharacters();
        break;
    case 'u':
        cout << "¬";
        paintCharacters();
        break;
    case 'i':
        cout << "­";
        paintCharacters();
        break;
    case 'o': //0.8.0
        cout << "ñ";
        paintCharacters();
        break;
    case 'p':
        cout << "ò";
        paintCharacters();
        break;
    case 'a':
        cout << "ó";
        paintCharacters();
        break;
    case 's': //0.9.0
        cout << "ô";
        paintCharacters();
        break;
    case 'd':
        cout << "õ";
        paintCharacters();
        break;
    case 'f':
        cout << "ö";
        paintCharacters();
        break;
    case 'g':
        cout << "÷";
        paintCharacters();
        break;
    case 'h':
        cout << "ø";
        paintCharacters();
        break;
    case 'j': //0.10.0
        cout << "ù";
        paintCharacters();
        break;
    case 'k':
        cout << "ú";
        paintCharacters();
        break;
    case 'l':
        cout << "û";
        paintCharacters();
        break;
    case 'x':
        cout << "ü";
        paintCharacters();
        break;
    case 'c': //0.11.0
        cout << "ý";
        paintCharacters();
        break;
    case 'v':
        cout << "þ";
        paintCharacters();
        break;
    case 'b':
        cout << "ÿ";
        paintCharacters();
        break;
    case ';':
        special1 = 1;
        cout << special1;
        paintCharacters();
        break;
    case ':':
        special1 = 2;
        cout << special1;
        paintCharacters();
        break;
    case '<':
        special1 = 3;
        cout << special1;
        paintCharacters();
        break;
    case '>':
        special1 = 4;
        cout << special1;
        paintCharacters();
        break;
    case '?':
        special1 = 5;
        cout << special1;
        paintCharacters();
        break;
    case '\'':
        special1 = 6;
        cout << special1;
        paintCharacters();
        break;
    case '"':
        special1 = 383;
        cout << special1;
        paintCharacters();
        break;
    case '|':
        special1 = 510;
        cout << special1;
        paintCharacters();
        break;
    }
case 'a':
    cout << "Ê";
    paintCharacters();
    break;
case ',':
    cout << " ";
    paintCharacters();
    break;
case 'm':
    asciiPaintStructureObject.paintMenu();
    break;
case 'h':
    asciiPaintStructureObject.getHelp();
    break;
case 'q':
    cout << "°";
    paintCharacters();
    break;
case 'w':
    cout << "±";
    paintCharacters();
    break;
case 'E':
    cout << "²";
    paintCharacters();
    break;
case 'e':
    cout << "³";
    paintCharacters();
    break;
case 'r':
    cout << "´";
    paintCharacters();
    break;
case 't':
    cout << "µ";
    paintCharacters();
    break;
case 'y':
    cout << "¶";
    paintCharacters();
    break;
case 'u':
    cout << "·";
    paintCharacters();
    break;
case 'i':
    cout << "¸";
    paintCharacters();
    break;
case 'p':
    cout << "¹";
    paintCharacters();
    break;
case 'd':
    cout << "º";
    paintCharacters();
    break;
case 'f':
    cout << "»";
    paintCharacters();
    break;
case 'g':
    cout << "¼";
    paintCharacters();
    break;
case 'j':
    cout << "½";
    paintCharacters();
    break;
case 'k':
    cout << "¾";
    paintCharacters();
    break;
case 'l':
    cout << "¿";
    paintCharacters();
    break;
case 'Z':
    cout << "À";
    paintCharacters();
    break;
case 'c':
    cout << "Á";
    paintCharacters();
    break;
case 'v':
    cout << "Â";
    paintCharacters();
    break;
case 'b':
    cout << "Ã";
    paintCharacters();
    break;
case 'n':
    cout << "Ä";
    paintCharacters();
    break;
case 'Q':
    cout << "Å";
    paintCharacters();
    break;
case 'R':
    cout << "Æ";
    paintCharacters();
    break;
case 'P':
    cout << "Ç";
    paintCharacters();
    break;
case 'S':
    cout << "È";
    paintCharacters();
    break;
case 'D':
    cout << "É";
    paintCharacters();
    break;
case 'F':
    cout << "Ë";
    paintCharacters();
    break;
case 'G':
    cout << "Ì";
    paintCharacters();
    break;
case 'J':
    cout << "Í";
    paintCharacters();
    break;
case 'K':
    cout << "Î";
    paintCharacters();
    break;
case 'L':
    cout << "Ï";
    paintCharacters();
    break;
case 'B':
    cout << "Ð";
    paintCharacters();
    break;
case 'M':
    cout << "Ñ";
    paintCharacters();
    break;
case '1':
    cout << "Ò";
    paintCharacters();
    break;
case '2':
    cout << "Ó";
    paintCharacters();
    break;
case '3':
    cout << "Ô";
    paintCharacters();
    break;
case '4':
    cout << "Õ";
    paintCharacters();
    break;
case '5':
    cout << "Ö";
    paintCharacters();
    break;
case '6':
    cout << "×";
    paintCharacters();
    break;
case '7':
    cout << "Ø";
    paintCharacters();
    break;
case '8':
    cout << "Ù";
    paintCharacters();
    break;
case '9':
    cout << "Ú";
    paintCharacters();
    break;
case '[':
    cout << "Û";
    paintCharacters();
    break;
case ']':
    cout << "Ü";
    paintCharacters();
    break;
case '{':
    cout << "Ý";
    paintCharacters();
    break;
case '}':
    cout << "Þ";
    paintCharacters();
    break;
case '?':
    cout << "ß";
    paintCharacters();
    break;
case 'x':
    cout << "®";
    paintCharacters();
    break;
case 'X':
    cout << "¯";
    paintCharacters();
    break;
case 'C': //1.0.0
    static char colorBlock;
    cin >> colorBlock;
    switch(colorBlock){
    case '0':
        static char color0Block;
        cin >> color0Block;
        switch(color0Block){
        case '0':
            SetConsoleTextAttribute(hstdout,0x00);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0x01);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0x02);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0x03);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0x04);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0x05);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0x06);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0x07);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0x08);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0x09);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0x0A);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0x0B);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0x0C);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0x0D);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0x0E);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0x0F);
            paintCharacters();
            break;
        }
    case '1':
        static char color1Block;
        cin >> color1Block;
        switch(color1Block){
        case '0':
            SetConsoleTextAttribute(hstdout,0x10);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0x11);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0x12);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0x13);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0x14);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0x15);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0x16);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0x17);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0x18);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0x19);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0x1A);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0x1B);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0x1C);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0x1D);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0x1E);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0x1F);
            paintCharacters();
            break;
        }
    case '2':
        static char color2Block;
        cin >> color2Block;
        switch(color2Block){
        case '0':
            SetConsoleTextAttribute(hstdout,0x20);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0x21);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0x22);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0x23);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0x24);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0x25);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0x26);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0x27);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0x28);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0x29);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0x2A);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0x2B);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0x2C);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0x2D);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0x2E);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0x2F);
            paintCharacters();
            break;
        }
    case '3':
        static char color3Block;
        cin >> color3Block;
        switch(color3Block){
        case '0':
            SetConsoleTextAttribute(hstdout,0x30);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0x31);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0x32);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0x33);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0x34);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0x35);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0x36);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0x37);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0x38);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0x39);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0x3A);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0x3B);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0x3C);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0x3D);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0x3E);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0x3F);
            paintCharacters();
            break;
        }
    case '4':
        static char color4Block;
        cin >> color4Block;
        switch(color4Block){
        case '0':
            SetConsoleTextAttribute(hstdout,0x40);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0x41);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0x42);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0x43);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0x44);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0x45);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0x46);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0x47);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0x48);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0x49);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0x4A);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0x4B);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0x4C);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0x4D);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0x4E);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0x4F);
            paintCharacters();
            break;
        }
    case '5':
        static char color5Block;
        cin >> color5Block;
        switch(color5Block){
        case '0':
            SetConsoleTextAttribute(hstdout,0x50);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0x51);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0x52);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0x53);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0x54);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0x55);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0x56);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0x57);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0x58);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0x59);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0x5A);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0x5B);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0x5C);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0x5D);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0x5E);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0x5F);
            paintCharacters();
            break;
        }
    case '6':
        static char color6Block;
        cin >> color6Block;
        switch(color6Block){
        case '0':
            SetConsoleTextAttribute(hstdout,0x60);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0x61);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0x62);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0x63);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0x64);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0x65);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0x66);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0x67);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0x68);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0x69);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0x6A);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0x6B);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0x6C);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0x6D);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0x6E);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0x6F);
            paintCharacters();
            break;
        }
    case '7':
        static char color7Block;
        cin >> color7Block;
        switch(color7Block){
        case '0':
            SetConsoleTextAttribute(hstdout,0x70);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0x71);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0x72);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0x73);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0x74);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0x75);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0x76);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0x77);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0x78);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0x79);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0x7A);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0x7B);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0x7C);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0x7D);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0x7E);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0x7F);
            paintCharacters();
            break;
        }
    case '8':
        static char color8Block;
        cin >> color8Block;
        switch(color8Block){
        case '0':
            SetConsoleTextAttribute(hstdout,0x80);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0x81);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0x82);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0x83);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0x84);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0x85);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0x86);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0x87);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0x88);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0x89);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0x8A);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0x8B);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0x8C);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0x8D);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0x8E);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0x8F);
            paintCharacters();
            break;
        }
    case '9':
        static char color9Block;
        cin >> color9Block;
        switch(color9Block){
        case '0':
            SetConsoleTextAttribute(hstdout,0x90);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0x91);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0x92);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0x93);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0x94);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0x95);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0x96);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0x97);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0x98);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0x99);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0x9A);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0x9B);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0x9C);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0x9D);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0x9E);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0x9F);
            paintCharacters();
            break;
        }
    case 'A':
        static char colorABlock;
        cin >> colorABlock;
        switch(colorABlock){
        case '0':
            SetConsoleTextAttribute(hstdout,0xA0);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0xA1);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0xA2);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0xA3);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0xA4);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0xA5);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0xA6);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0xA7);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0xA8);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0xA9);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0xAA);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0xAB);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0xAC);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0xAD);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0xAE);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0xAF);
            paintCharacters();
            break;
        }
    case 'B':
        static char colorBBlock;
        cin >> colorBBlock;
        switch(colorBBlock){
        case '0':
            SetConsoleTextAttribute(hstdout,0xB0);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0xB1);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0xB2);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0xB3);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0xB4);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0xB5);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0xB6);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0xB7);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0xB8);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0xB9);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0xBA);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0xBB);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0xBC);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0xBD);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0xBE);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0xBF);
            paintCharacters();
            break;
        }
    case 'C':
        static char colorCBlock;
        cin >> colorCBlock;
        switch(colorCBlock){
        case '0':
            SetConsoleTextAttribute(hstdout,0xC0);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0xC1);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0xC2);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0xC3);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0xC4);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0xC5);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0xC6);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0xC7);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0xC8);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0xC9);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0xCA);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0xCB);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0xCC);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0xCD);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0xCE);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0xCF);
            paintCharacters();
            break;
        }
    case 'D':
        static char colorDBlock;
        cin >> colorDBlock;
        switch(colorDBlock){
        case '0':
            SetConsoleTextAttribute(hstdout,0xD0);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0xD1);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0xD2);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0xD3);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0xD4);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0xD5);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0xD6);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0xD7);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0xD8);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0xD9);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0xDA);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0xDB);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0xDC);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0xDD);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0xDE);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0xDF);
            paintCharacters();
            break;
        }
    case 'E':
        static char colorEBlock;
        cin >> colorEBlock;
        switch(colorEBlock){
        case '0':
            SetConsoleTextAttribute(hstdout,0xE0);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0xE1);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0xE2);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0xE3);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0xE4);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0xE5);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0xE6);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0xE7);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0xE8);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0xE9);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0xEA);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0xEB);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0xEC);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0xED);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0xEE);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0xEF);
            paintCharacters();
            break;
        }
    case 'F':
        static char colorFBlock;
        cin >> colorFBlock;
        switch(colorFBlock){
        case '0':
            SetConsoleTextAttribute(hstdout,0xF0);
            paintCharacters();
            break;
        case '1':
            SetConsoleTextAttribute(hstdout,0xF1);
            paintCharacters();
            break;
        case '2':
            SetConsoleTextAttribute(hstdout,0xF2);
            paintCharacters();
            break;
        case '3':
            SetConsoleTextAttribute(hstdout,0xF3);
            paintCharacters();
            break;
        case '4':
            SetConsoleTextAttribute(hstdout,0xF4);
            paintCharacters();
            break;
        case '5':
            SetConsoleTextAttribute(hstdout,0xF5);
            paintCharacters();
            break;
        case '6':
            SetConsoleTextAttribute(hstdout,0xF6);
            paintCharacters();
            break;
        case '7':
            SetConsoleTextAttribute(hstdout,0xF7);
            paintCharacters();
            break;
        case '8':
            SetConsoleTextAttribute(hstdout,0xF8);
            paintCharacters();
            break;
        case '9':
            SetConsoleTextAttribute(hstdout,0xF9);
            paintCharacters();
            break;
        case 'A':
            SetConsoleTextAttribute(hstdout,0xFA);
            paintCharacters();
            break;
        case 'B':
            SetConsoleTextAttribute(hstdout,0xFB);
            paintCharacters();
            break;
        case 'C':
            SetConsoleTextAttribute(hstdout,0xFC);
            paintCharacters();
            break;
        case 'D':
            SetConsoleTextAttribute(hstdout,0xFD);
            paintCharacters();
            break;
        case 'E':
            SetConsoleTextAttribute(hstdout,0xFE);
            paintCharacters();
            break;
        case 'F':
            SetConsoleTextAttribute(hstdout,0xFF);
            paintCharacters();
            break;
        }
    case 'R':
        SetConsoleTextAttribute(hstdout,0x07);
        paintCharacters();
        break;
        }
    case '0':
        cout << "\n";
        paintCharacters();
        break;
    case 's':
        cout << "\n";
        paintCharacters();
        break;
    case 'W':
        system("cls");
        if(directScreenClear==1){
            system("cls");
        }
        paintCharacters();
        break;
        }
    }

void characters::saveFileVoid(){
    saveMechanicsObject.saveMechanicsVoid(block);
}
