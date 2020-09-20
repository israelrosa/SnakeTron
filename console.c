#include <windows.h>
#include <direct.h>
#include <stdbool.h>
#include "console.h"

/*
    Modulo de auxilio para posicionamento de cursor e mudan�a de cores
*/
// Define coordenadas da janela
void setWindow(int Width, int Height) {
    /// codigo original: http://www.mediafire.com/file/pc1l6l3v9sij75x/C+++console+game.zip
    COORD coord;
    coord.X = Width;
    coord.Y = Height;

    SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}


// Posiciona cursor na posicao x,y
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Define cor de fundo
void setBackgroundColor(int c) {
    /// codigo original: http://tapiov.net/rlutil/
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);

    SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFF0F) | (((WORD)c) << 4)); // Background colors take up the second-least significant byte
#else
    RLUTIL_PRINT(getANSIBackgroundColor(c));
#endif
}

// Define cor dos caracteres
void setColor(int ForgC) {
    /// codigo original: Fonte: https://stackoverflow.com/questions/29574849/how-to-change-text-color-and-console-color-in-codeblocks
    WORD wColor;
    //This handle is needed to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //csbi is used for wAttributes word
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        //To mask out all but the background attribute, and to add the color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void maximizeWindow(){
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
}

void runCursor(int xPos, int yPos){
    hideCursor(true);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD pos = {xPos, yPos};
    DWORD esc;
    DWORD tam = csbi.dwSize.X *csbi.dwSize.Y;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),' ',tam,pos,&esc);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void hideCursor(bool hide){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = !hide;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void getSizeWindow(int *width, int *heigth){
    CONSOLE_SCREEN_BUFFER_INFO cmd;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cmd);
    *width = cmd.srWindow.Right - cmd.srWindow.Left +1;
    *heigth = cmd.srWindow.Bottom - cmd.srWindow.Top +1;
}
