#include "helpPage.h"
#include "asciipaintstructure.h"
#include <iostream>
#include <windows.h>
using namespace std;

static char helpPageVariable;

void helpPage::all(){
    alphabetAndNumbers();
    borderBlocks();
    symbolsAndLines();
    specialCharacters();
    specialSymbols();
    color16Bit();
    accessLetters();
}

asciiPaintStructure asciiPaintStructureObjectHelpPage;

void helpPage::alphabetAndNumbers(){
    cout << "Alphabets:" << endl;
    cout << "AA - A\tAa - a\tAB - B\tAb - b\tAC - C\tAc - c\t\n\n";
    cout << "AD - D\tAd - d\tAE - E\tAe - e\tAF - F\tAf - f\t\n\n";
    cout << "AG - G\tAg - g\tAH - H\tAh - h\tAI - I\tAi - i\t\n\n";
    cout << "AJ - J\tAj - j\tAK - K\tAk - k\tAL - L\tAl - l\t\n\n";
    cout << "AM - M\tAm - m\tAN - N\tAn - n\tAO - O\tAo - o\t\n\n";
    cout << "AP - P\tAp - p\tAQ - Q\tAq - q\tAR - R\tAr - r\t\n\n";
    cout << "AS - S\tAs - s\tAT - T\tAt - t\tAU - U\tAu - u\t\n\n";
    cout << "AV - V\tAv - v\tAW - W\tAw - w\tAX - X\tAx - x\t\n\n";
    cout << "AY - Y\tAy = y\tAZ - Z\tAz - z\t\n\n";
    cout << "Numbers:" << endl;
    cout << "N1 - 1\tN2 - 2\tN3 - 3\tN4 - 4\tN5 - 5\tN6 - 6\t\n\n";
    cout << "N7 - 7\tN8 - 8\tN9 - 9\tN0 - 0\t\n\n";
    helpPageCursor();
}

void helpPage::borderBlocks(){
    cout << "Borders:" << endl;
    cout << "a - Ê\t, -  \tr - ´\tt - µ\ty - ¶\tu - ·\t\n\n";
    cout << "i - ¸\tp - ¹\td - º\tf - »\tg - ¼\tj - ½\t\n\n";
    cout << "k - ¾\tl - ¿\tZ - À\tc - Á\tv - Â\tb - Ã\t\n\n";
    cout << "n - Ä\tQ - Å\tR - Æ\tP - Ç\tS - È\tD - É\t\n\n";
    cout << "F - Ë\tG - Ì\tJ - Í\tK - Î\tL - Ï\tB - Ð\t\n\n";
    cout << "M - Ñ\t1 - Ò\t2 - Ó\t3 - Ô\t4 - Õ\t5 - Ö\t\n\n";
    cout << "6 - ×\t7 - Ø\t8 - Ù\t9 - Ú\t\n\n";
    cout << "Blocks:" << endl;
    cout << "q - °\tw - ±\tE - ²\t[ - Û\t] - Ü\t{ - Ý\t\n\n";
    cout << "} - Þ\t? - ß\n\n";
    helpPageCursor();
}

void helpPage::symbolsAndLines(){
    cout << "Symbols:" << endl;
    cout << "~! - !\t~@ - @\t~# - #\t~$ - $\t~% - %\t~^ - ^\t\n\n";
    cout << "~& - &\t~* - *\t~( - (\t~) - )\t~{ - {\t~} - }\t\n\n";
    cout << "~\' - \'\t~\" - \"\t~; - ;\t~: - :\t~, - ,\t~. - .\t\n\n";
    cout << "~? - ?\t~+ - +\ts - NEW LINE\n\n";
    cout << "Lines:" << endl;
    cout << "x - ®\tX - ¯\t~[ - [\t~] - ]\t~\\ - \\\t~| - |\t\n\n";
    cout << "~- - -\t~_ - _\t~/ - /\t~< - <\t~> - >\t~= - =\t\n\n";
    cout << "~~ - ~\t\n\n";
    helpPageCursor();
}

void helpPage::specialCharacters(){
    cout << "Special Characters:" << endl;
    cout << "`q - €\t`w - \t`e - ‚\t`r - ƒ\tt - „\t`y - …\t\n\n";
    cout << "`u - †\t`i - ‡\t`o - ˆ\t`p - ‰\t`a - Š\t`s - Œ\t\n\n";
    cout << "`d - \t`f - Ž\t`g - \t`h - \t`j - ‹\t`k - ‘\t\n\n";
    cout << "`l - ’\t`z - “\t`x - ”\t`c - •\t`v - –\t`b - —\t\n\n";
    cout << "`n - ™\t`m - š\t`Q - ˜\t`W - œ\t`E - \t`R - ž\t\n\n";
    cout << "`T - Ÿ\t`Y -  \t`U - ¡\t`I - ¢\t`O - £\t`P - ¤\t\n\n";
    cout << "`A - ¥\t`S - ›\t`D - à\t`F - á\t`G - â\t`H - ã\t\n\n";
    cout << "`J - ä\t`K - å\t`L - æ\t`Z - ç\t`X - è\t`C - é\t\n\n";
    cout << "`V - ê\t`B - ë\t`N - ì\t`M - í\t`, - î\t`. - ï\t\n\n";
    cout << "`/ - ð\t\n\n";
    helpPageCursor();
}

void helpPage::specialSymbols(){
    char special1 = 1;
    char special2 = 2;
    char special3 = 3;
    char special4 = 4;
    char special5 = 5;
    char special6 = 6;
    char special7 = 383;
    char special8 = 510;
    cout << "Special Symbols:" << endl;
    cout << "zq - ¦\tzw - §\tze - ¨\tzr - ©\tzt - ª\tzy - «\t\n\n";
    cout << "zu - ¬\tzi - ­\tzo - ñ\tzp - ò\tza - ó\tzs - ô\t\n\n";
    cout << "zd - õ\tzf - ö\tzg - ÷\tzh - ø\tzj - ù\tzk - ú\t\n\n";
    cout << "zl - û\tzx - ü\tzc - ý\tzv - þ\tzb - ÿ\tz; - "<<special1<<"\n\n";
    cout << "z: - "<<special2<<"\tz< - "<<special3<<"\tz> - "<<special4<<"\tz? - "<<special5<<"\tz\\ - "<<special6<<"\tz\" - "<<special7<<endl<<endl;
    cout << "z| - "<<special8<<endl<<endl;
    helpPageCursor();
}

void helpPage::color16Bit(){

    const WORD colors[] =
    {
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0xF0
    };

    HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
	WORD   index   = 0;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi);

    cout << "Colors: (16-Bit, 256 Colors)" << endl;
    cout << "Format: ACCESS LETTER \'C\' | BACKGROUND | FOREGROUND\nExample: C40 - Red Background, Black Foreground\n\n";
    cout << "Colors in HEX format:\n\n";

    SetConsoleTextAttribute(hstdout,0xF0);
    cout << "0 - Black\t";
    SetConsoleTextAttribute(hstdout,0x08);
    cout << "8 - Gray\n";
    SetConsoleTextAttribute(hstdout,0x01);
    cout << "1 - Blue\t";
    SetConsoleTextAttribute(hstdout,0x09);
    cout << "9 - Light Blue\n";
    SetConsoleTextAttribute(hstdout,0x02);
    cout << "2 - Green\t";
    SetConsoleTextAttribute(hstdout,0x0A);
    cout << "A - Light Green\n";
    SetConsoleTextAttribute(hstdout,0x03);
    cout << "3 - Aqua\t";
    SetConsoleTextAttribute(hstdout,0x0B);
    cout << "B - Light Aqua\n";
    SetConsoleTextAttribute(hstdout,0x04);
    cout << "4 - Red\t\t";
    SetConsoleTextAttribute(hstdout,0x0C);
    cout << "C - Light Red\n";
    SetConsoleTextAttribute(hstdout,0x05);
    cout << "5 - Purple\t";
    SetConsoleTextAttribute(hstdout,0x0D);
    cout << "D - Light Purple\n";
    SetConsoleTextAttribute(hstdout,0x06);
    cout << "6 - Yellow\t";
    SetConsoleTextAttribute(hstdout,0x0E);
    cout << "E - Light Yellow\n";
    SetConsoleTextAttribute(hstdout,0x07);
    cout << "7 - White\t";
    SetConsoleTextAttribute(hstdout,0x0F);
    cout << "F - Bright White\n\n";

    SetConsoleTextAttribute(hstdout,0x07);
    cout << "R - Reset\n\n";
    helpPageCursor();
}

void helpPage::accessLetters(){
    cout << "FORMAT: ACCESS LETTER | INPUT LETTER -> OUTPUT LETTER\n\n";
    cout << "A - Access to Alphabets\n";
    cout << "N - Access to Numbers\n";
    cout << "~ - Access to Symbols and Lines\n";
    cout << "` - Access to Special Characters\n";
    cout << "z - Access to Special Symbols\n";
    cout << "C - Access to Colors\n\n";
    helpPageCursor();
}

void helpPage::saveMechanics(){
    cout << "SAVE MECHANICS (BETA):\n";
    cout << "-To make sure you save your work: Go to Settings>Save Mode (Beta)>Press and Enter 1(Boolean: True)>Start writing\n";
    cout << "-To Load your work: Load(Beta)>Enter. Copy the work and replace Zeros with 'S' for new line.\n";
    cout << "-To save your work without using these save mechanics: Copy your work, Save to notepad, Unicode: Unicode/UTF-8. Might not work with ANSI encoding\n";
    cout << "FAQ:\n";
    cout << "@This program crashes so much after the 1.0 release compared to 0.11.\n";
    cout << "-There was a saving error causing frequent crashes after exceeding to unknown digit limit.\n\n";
    helpPageCursor();
}

void helpPage::helpPageCursor(){
    cout << "Press E to go back, Press C to Continue" << endl;
    cin >> helpPageVariable;
    while(helpPageVariable=='E'|helpPageVariable=='e'){
        asciiPaintStructureObjectHelpPage.getHelp();
    }
}
