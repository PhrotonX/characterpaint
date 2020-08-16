#include "characters.h"
#include "asciipaintstructure.h"
#include  "helpPage.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int clearScreenMode;

characters charactersObject;
helpPage helpPageObject;

void asciiPaintStructure::paintMenu(){
    cout << "Character Paint " << verMajor << "." << verMinor << "." << verPatch << /*"." << verDevPr <<*/ " " << testType << " - By Phroton" << endl;
    cout << "S - Start\n";
    cout << "L - Load (Beta)\n";
    cout << "T - Settings\n";
    cout << "H - Help\n";
    cout << "I - Info\n";
    cout << "X - Exit\n";
    static char menuCursor;
    cin >> menuCursor;
    cout << "-----------------------------------" << endl;
    /*switch(menuCursor){
    case 'S'|'s':
        charactersObject.paintCharacters();
        break;
    case 'H'|'h':
        getHelp();
        break;
    case 'I'|'i':
        info();
        break;
    case 'X'|'x':
        exit();
    default:
        paintMenu();
    }
*/
    while((menuCursor=='S')|(menuCursor=='s')){
        charactersObject.paintCharacters();
    }
    while((menuCursor=='H')|(menuCursor=='h')){
        getHelp();
    }
    while((menuCursor=='I')|(menuCursor=='i')){
        info();
    }
    while((menuCursor=='X')|(menuCursor=='x')){
        exit();
    }
    while((menuCursor=='L')|(menuCursor=='l')){
        loadFile();
    }
    while((menuCursor=='T')|(menuCursor=='t')){
        settings(clearScreenMode);
    }
    while((menuCursor!='X')|(menuCursor!='x')|(menuCursor!='S')|(menuCursor!='s')|(menuCursor!='H')
       |(menuCursor!='h')|(menuCursor!='I')|(menuCursor|='i')|(menuCursor=='L')|(menuCursor=='l')|
          (menuCursor=='T')|(menuCursor=='t')){
        cout << " " << endl;
        paintMenu();
       }
}

void asciiPaintStructure::asciiPaintInfo(){
    paintMenu();
}

void asciiPaintStructure::getHelp(){
    cout << "Format: INPUT LETTER -> OUTPUT LETTER\n";
    cout << "Other Format: ACCESS LETTER | INPUT LETTER -> OUTPUT LETTER\n";
    cout << "Press the following to continue: " << endl;
    cout << "X - ALL" << endl;
    cout << "A - Alphabets and Numbers\n";
    cout << "B - Border and Blocks\n";
    cout << "~ - Symbols and Lines\n";
    cout << "` - Special Characters\n";
    cout << "z - Special Symbols\n";
    cout << "C - Colors\n";
    cout << "Q - Access Letters\n\n";
    cout << "Others:\nm - Menu\nh - Help\ns - Save Mechanics\nw - Clear screen (Beta)\n\n";
    cout << "Press E to continue\n";

    static char helpMenuCursor;
    cin >> helpMenuCursor;
    cout << "-----------------------------------" << endl;
    while((helpMenuCursor=='A')|(helpMenuCursor=='a')){
        helpPageObject.alphabetAndNumbers();
    }
    while((helpMenuCursor=='B')|(helpMenuCursor=='b')){
        helpPageObject.borderBlocks();
    }
    while(helpMenuCursor=='~'){
        helpPageObject.symbolsAndLines();
    }
    while(helpMenuCursor=='`'){
        helpPageObject.specialCharacters();
    }
    while((helpMenuCursor=='Q')|(helpMenuCursor=='q')){
        helpPageObject.accessLetters();
    }
    while((helpMenuCursor=='X')|(helpMenuCursor=='x')){
        helpPageObject.all();
    }
    while((helpMenuCursor=='E')|(helpMenuCursor=='e')){
        if(clearScreenMode==1){
            system("cls");
        }
        paintMenu();
    }
    while((helpMenuCursor=='Z')|(helpMenuCursor=='z')){
        helpPageObject.specialSymbols();
    }
    while((helpMenuCursor=='C')|(helpMenuCursor=='c')){
        helpPageObject.color16Bit();
    }
    while((helpMenuCursor=='S')|(helpMenuCursor=='s')){
        helpPageObject.saveMechanics();
    }

}

void asciiPaintStructure::info(){
    cout << "Character Painter is a program used to draw with characters. This program uses OEM ASCII character set.\n";
    cout << "Version " << verMajor << "." << verMinor << "." << verPatch << /*"." << verDevPr <<*/ " " << testType << endl;
    cout << "Program made by: Phroton\n";
    cout << "Collaborators: None\n\n";
    cout << "Program Created: - May 1, 2020\n";
    cout << "Release 0.1.0 - May 6, 2020\n";
    cout << "Release " << verMajor << "." << verMinor << "." << verPatch << /*"." << verDevPr <<*/ " " << testType << " - " << __DATE__ << " " << __TIME__ << endl << endl;
    cout << "C++ Formatting: " << __cplusplus << endl;
    cout << "STDC: " << __STDC__ << endl;
    cout << "Build " << build << endl;
    cout << "-----------------------------------" << endl;
    paintMenu();
}

void asciiPaintStructure::exit(){
    exit();
}

void asciiPaintStructure::saveMode(){
    cout << "Turning on Save Mode (Beta) may cause frequent crashes.\n Press 1 to continue, Press 0 to cancel.\n This will reset until the program is restarted\n" << endl;
    charactersObject.saveFileVoid();
}

void asciiPaintStructure::settings(int clearScreenMode){
    cout << "S - Save Mode\n";
    cout << "C - Allow screen clearing\n";
    cout << "R - Reset a saved file\n";
    cout << "M - Main Menu\n";
    static char settingsBlock;
    static char confirmBlock;
    cin >> settingsBlock;
    cout << "-----------------------------------" << endl;
    while((settingsBlock=='R')|(settingsBlock=='r')){
    cout << "Confirm Reset. Press E to Continue." << endl;
    cin >> confirmBlock;
    while((confirmBlock=='E')|(confirmBlock=='e')){
    fstream file;
    file.open("saveData.txt",ios::in|ios::out|ios::trunc);
    if(!file.is_open()){
        cout << "Error" << endl;
        paintMenu();
    }else{
    cout << "File reset successfully" << endl << endl;
    file.close();
    }
    if(clearScreenMode==1){
        system("cls");
    }
    settings(clearScreenMode);
    }
    while((confirmBlock=='X')|(confirmBlock=='x')){
        if(clearScreenMode==1){
        system("cls");
        }settings(clearScreenMode);
    }


    }
    while((settingsBlock=='C')|(settingsBlock=='c')){
        charactersObject.clearScreen(clearScreenMode);
    }
    while((settingsBlock=='M')|(settingsBlock=='m')){
        if(clearScreenMode==1){
            system("cls");
        }
        paintMenu();
    }
    while((settingsBlock=='S')|(settingsBlock=='s')){
        saveMode();
    }
}

void asciiPaintStructure::loadFile(){
    ifstream file;
    file.open("saveData.txt");
    if(!file.is_open()){
        cout << "Error" << endl;
        paintMenu();
    }else{
    cout << "Reading from a file..." << endl;
    string line;
    while(file.good()){ //use while statement when multiple lines
    getline(file,line);
    cout << line << endl;
    paintMenu();
    }
    }
}



