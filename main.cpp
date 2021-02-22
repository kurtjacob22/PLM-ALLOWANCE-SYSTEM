#include <iostream>
#include <string>

#include "./src/Design.cpp" //? For Design UI
#include "./src/AdminState.cpp" //? Admin Functions
#include "./src/StudentState.cpp" //? Student Functions

using namespace std;

void header(){
    system("cls");
    displayConsoleName("PAMANTASAN NG LUNGSOD NG MAYNILA ALLOWANCE SYSTEM", "-");
    cout << endl;
}

void menu(){//start of the program -> back to menu
    int windowSize = getScreenSize();//-> constant number depending on the length of your Console

    int optionInput;
    do{
        // system("cls");
        // displayConsoleName("PAMANTASAN NG LUNGSOD NG MAYNILA ALLOWANCE SYSTEM", "-");
        header();
        centerText(windowSize / 2, " ", "1. Student");
        centerText(windowSize / 2, " ", "2. Admin");
        
        centerText(windowSize / 2, " ", "Select Option(1-2)");
        cout << endl;

        inputHere();
        cin >> optionInput;

        if(optionInput == 1){
            // Student State
            StudentState student;
            student.StudentAuth("Enter Username");
            break;
        }else if(optionInput == 2){
            // Admin State
            AdminState admin;
            admin.AdminAuth();
            break;
        }
    }while(true);
}

main(){
    menu();
}

