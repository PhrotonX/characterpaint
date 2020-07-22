#include "saveMechanics.h"
#include "characters.h"
#include <iostream>
#include <fstream>
using namespace std;

characters charactersObjectSaveMechanics;
asciiPaintStructure asciiPaintStructureObjectSaveMechanics;

void saveMechanics::saveMechanicsVoid(char block){
static bool saveFileMode;
    cin >> saveFileMode;
    cout << "-----------------------------------" << endl;
    if(saveFileMode==true){
        fstream file("saveData.txt",ios::in|ios::out|ios::app);
        if(file.is_open()){
            file << block;
            file.seekg(999999);

            string line;
            while(block=='0'){
                getline(file,line);
                file << block << "\n";
                charactersObjectSaveMechanics.paintCharacters();
        }
        while(!file.is_open()){
            file.close();
            }
        }
        charactersObjectSaveMechanics.paintCharacters();
    }else{
        asciiPaintStructureObjectSaveMechanics.paintMenu();
    }
}
