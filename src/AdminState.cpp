#include <iostream>
#include <string>
#include <conio.h>

// #include "././main.cpp"
// #include "./Design.cpp"

using namespace std;

void AdminAuth(){

    int windowSize = getScreenSize();//-> constant number depending on the length of your Console

    string userName, passWord;

    do{
        cin.clear();
        cin.sync();
        system("cls");
        
        displayConsoleName("PAMANTASAN NG LUNGSOD NG MAYNILA ALLOWANCE SYSTEM", "-");
        cout << endl;
        centerText(windowSize / 2, " ", "Enter Username");
        inputHere();
        getline(cin, userName);

        centerText(windowSize / 2, " ", "Enter Password");
        inputHere();
        getline(cin, passWord);

        if(userName == "ADMIN" && passWord == "1234PLM"){
            centerText(windowSize / 2, " ", "THANKYOU FOR LOGGING IN");
            loadData();
            break;
        }else{
            centerText(windowSize / 2, " ", "PLEASE ENTER VALID INFORMATION");
            loadData();
        }


    }while(true);
    
}





