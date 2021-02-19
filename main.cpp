#include <iostream>
#include <string>

#include "./src/CreateAccount.cpp" //? class for creating account
#include "./src/Design.cpp" //? For Design UI
// #include "./src/AdminState.cpp" //? Admin Functions

using namespace std;
class AdminState{
    public: 
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
                    adminMenu();
                    break;
                }else{
                    centerText(windowSize / 2, " ", "PLEASE ENTER VALID INFORMATION");
                    loadData();
                }


            }while(true);
            
        }

        void adminMenu(){

            int windowSize = getScreenSize();//-> constant number depending on the length of your Console
            system("cls");
            displayConsoleName("PAMANTASAN NG LUNGSOD NG MAYNILA ALLOWANCE SYSTEM", "-");
            cout << endl;
            centerText(windowSize / 2, " ", "1.REGISTER ACCOUNT");
            centerText(windowSize / 2, " ", "2.BALANCE ENQUIRY");
            centerText(windowSize / 2, " ", "3.VIEW ALL ACCOUNT HOLDER LIST");
            centerText(windowSize / 2, " ", "4.MODIFY AN ACCOUNT");
            centerText(windowSize / 2, " ", "5.ARCHIVE");
            centerText(windowSize / 2, " ", "6.EXIT");
        }
};
// END OF ADMIN STATE

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
            AdminState admin;
            admin.AdminAuth();
            break;
        }
    }while(true);
}

