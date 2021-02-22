#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;



// HELPER UI
int getScreenSize(){ //? to get the screen size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int windowSize;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    windowSize = csbi.srWindow.Right - csbi.srWindow.Left - 2;
    // windowSize / 2 - to center string

    return windowSize;
}

string indentText(int bufferSize, string symbol){ //? half version of the center function
    string textDisplay; 
    for(int j = 0; j<=bufferSize; j++){
        textDisplay += symbol;
    }
    
    return textDisplay;
}

void addSpace(int bufferSize, string symbol){ //? half version of the center function
    for(int j = 0; j<=bufferSize; j++){
        cout << symbol;
    }
}

void centerText(int bufferSize, string symbol, string text){ //? to have a more appealing interface
    for(int j = 0; j<=bufferSize - text.length() / 2; j++){
        cout << symbol;
    }

    cout << text;

    for(int j = 0; j<=bufferSize - text.length() / 2; j++){
        cout << symbol;
    }

    cout << endl;
    
}

// CONSOLE INTERFACE

void displayConsoleName(string title, string symbol){
    int size = getScreenSize();
    centerText(size / 2, symbol, title);
}

void inputHere(){
    int size = getScreenSize();
    addSpace(size / 2, " ");
    cout <<"-> ";
}

void loadData(){
    int size = getScreenSize();

    cout << endl;
    addSpace(size / 2, " ");
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";

}