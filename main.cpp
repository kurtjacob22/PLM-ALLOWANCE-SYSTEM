#include <iostream>

#include "./src/CreateAccount.cpp" //? class for creating account
#include "./src/Design.cpp" //? For Design UI
#include "./src/AdminState.cpp" //? Admin Functions

using namespace std;


main(){
    int windowSize = getScreenSize();//-> constant number depending on the length of your Console

    int optionInput;
    do{
        system("cls");
        displayConsoleName("PAMANTASAN NG LUNGSOD NG MAYNILA ALLOWANCE SYSTEM", "-");
        centerText(windowSize / 2, " ", "1. Student");
        centerText(windowSize / 2, " ", "2. Admin");

        cout << endl;
        centerText(windowSize / 2, " ", "Select Option(1-2)");
        cout << endl;

        inputHere();
        cin >> optionInput;

        if(optionInput == 1){
            // Student State
            cout << "Student";
            break;
        }else if(optionInput == 2){
            // Admin State
            AdminAuth();
            break;
        }
    }while(true);


}