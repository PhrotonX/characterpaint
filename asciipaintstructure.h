#ifndef ASCIIPAINTSTRUCTURE_H
#define ASCIIPAINTSTRUCTURE_H

#define verMajor 1
#define verMinor 1
#define verPatch 0
#define verDevPr
#define testType ""
#define build 600

class asciiPaintStructure
{
    public:
        void asciiPaintInfo();
        void paintMenu();
        void getHelp();
        void info();
        void exit();
        void saveMode();
        void settings(int clearScreenMode);
        void loadFile();

        //void paintStructure();

    protected:

    private:
};

#endif // ASCIIPAINTSTRUCTURE_H
