#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void centerText();
void displayConsoleName();
void inputHere();
int getScreenSize();
void header();
void menu();

class StudentState{

    public:
        void StudentAuth(string message){// ! TRACK INDEX
            int windowSize = getScreenSize();//-> constant number depending on the length of your Console
            
            AdminState getVector;
            string userName;
            string passWord;

            fstream studentNumberFile, studentPasswordFile;
            studentNumberFile.open(".\\src\\Database\\student_number.dat", ios::in | ios::out | ios::app);
            studentPasswordFile.open(".\\src\\Database\\password.dat", ios::in | ios::out | ios::app);

            vector<string> studentNumber, studentPassword;
            string input;
            while(getline(studentNumberFile, input)){
                studentNumber.push_back(input);
            }
            while(getline(studentPasswordFile, input)){
                studentPassword.push_back(input);
            }

            studentNumberFile.close();
            studentPasswordFile.close();

            cin.clear();
            cin.sync();
            
            header();

            centerText(windowSize / 2, " ", message);
            inputHere();
            getline(cin, userName);

            int index = getVector.getVectorIndex(userName, studentNumber);
            if(index != -1){ //! if the user exists
                centerText(windowSize / 2, " ", "Enter Password");
                inputHere();
                getline(cin, passWord);
                if(studentPassword[index] == passWord){
                    // Proceed to Menu
                    loadData();
                    cout << endl;
                    centerText(windowSize / 2, " ", "SUCCESS!");
                    system("pause");
                    studentMenu("", userName);
                }
            }else{
                
            }
            StudentAuth("Wrong Details, Enter Username");         
        }

        void studentMenu(string type, string username){
            int windowSize = getScreenSize();//-> constant number depending on the length of your Console
            int optMenu;

            if(type == "BackToMenu"){
                header();
                cout << endl;
                centerText(windowSize / 2, " ", "Transaction Sucess");
                loadData();
            }

            header();
            centerText(windowSize / 2, " ", "HI! " + username);
            centerText(windowSize / 2, " ", "1.CHANGE PASSWORD");
            centerText(windowSize / 2, " ", "2.WITHDRAW");
            centerText(windowSize / 2, " ", "3.CHECK BALANCE ");
            centerText(windowSize / 2, " ", "4.LOGOUT");
            centerText(windowSize / 2, " ", "5.EXIT");
            cout << endl;
            centerText(windowSize / 2, " ", "Select Option");
            inputHere();
            cin >> optMenu;

            if(optMenu == 1){
                // Change password
                changePassword(username);
            }else if(optMenu == 2){
                // Withdraw
                withDraw(username);
            }else if(optMenu == 3){
                AdminState admin;
                admin.balanceInquiry("STUDENT", username);
                studentMenu("BackToMenu", username);
            }else if(optMenu == 4){
                // logout
                loadData();
                menu();
            }else if(optMenu == 5){
                // exit
                system("cls");
                system("exit");
            }else{
                studentMenu("", username);
            }
        }

        void withDraw(string studentId){
            int windowSize = getScreenSize();//-> constant number depending on the length of your Console

            fstream studentNumFile, studentNameFile, amountFile;
            studentNumFile.open(".\\src\\Database\\student_number.dat", ios::in | ios::out | ios::app);
            studentNameFile.open(".\\src\\Database\\student_name.dat", ios::in | ios::out | ios::app);
            amountFile.open(".\\src\\Database\\student_balance.dat", ios::in | ios::out | ios::app);

            vector<string> studentNumber, studentName, studentBalance;
            string input;
            while(getline(studentNumFile, input)){
                studentNumber.push_back(input);
            }
            while(getline(studentNameFile, input)){
                studentName.push_back(input);
            }
            while(getline(amountFile, input)){
                studentBalance.push_back(input);
            }

            studentNumFile.close();
            studentNameFile.close();
            amountFile.close();
            
            AdminState admin;
            int index = admin.getVectorIndex(studentId, studentNumber);
            int amountWithdraw;

            header();
            centerText(windowSize / 2, " ", "Hi! " + studentName[index] + " your remaining balance is: " + studentBalance[index]);
            centerText(windowSize / 2, " ", "Please enter amount to withdraw");
            inputHere();
            cin >> amountWithdraw;
            int amountRemaining;
            if(amountWithdraw >= 0){
                amountRemaining = stoi(studentBalance[index]) - amountWithdraw;

                if(amountRemaining < 0){
                    centerText(windowSize / 2, " ", "NOT ENOUGH CASH, YOU HAVE! " + studentBalance[index] + " Balance");
                    loadData();
                    cout << endl;
                    system("pause");
                    studentMenu("BackToMenu", studentId);
                }else{
                    // Withdraw Process
                    amountRemaining = stoi(studentBalance[index]) - amountWithdraw;
                    replaceData(index, to_string(amountRemaining), studentBalance, ".\\src\\Database\\student_balance.dat");

                    loadData();
                    cout << endl;
                    centerText(windowSize / 2, " ", "SUCCESS!");
                    system("pause");
                    studentMenu("BackToMenu", studentId);
                }
                
            }else{
                
                withDraw(studentId);
            }
        }

        void changePassword(string studentId){
            cin.ignore();
            cin.sync();
            int windowSize = getScreenSize();//-> constant number depending on the length of your Console

            fstream studentNumFile, studentNameFile, studentPasswordFile;
            studentNumFile.open(".\\src\\Database\\student_number.dat", ios::in | ios::out | ios::app);
            studentNameFile.open(".\\src\\Database\\student_name.dat", ios::in | ios::out | ios::app);
            studentPasswordFile.open(".\\src\\Database\\password.dat", ios::in | ios::out | ios::app);

            vector<string> studentNumber, studentName, studentPassword;
            string input;
            while(getline(studentNumFile, input)){
                studentNumber.push_back(input);
            }
            while(getline(studentNameFile, input)){
                studentName.push_back(input);
            }
            while(getline(studentPasswordFile, input)){
                studentPassword.push_back(input);
            }

            studentNumFile.close();
            studentNameFile.close();
            studentPasswordFile.close();

            AdminState admin;
            int index = admin.getVectorIndex(studentId, studentNumber);
            string newPassword;

            header();
            centerText(windowSize / 2, " ", "Hi! " + studentName[index]);
            centerText(windowSize / 2, " ", "Please Enter your new Password");
            inputHere();
            getline(cin, newPassword);

            if(newPassword == "" || newPassword == studentPassword[index]){
                loadData();
                cout << endl;
                centerText(windowSize / 2, " ", "Please Enter valid information and do not use your previous password");
                system("pause");
            }else{
                string retypedPassword;

                header();
                centerText(windowSize / 2, " ", "Hi! " + studentName[index]);
                centerText(windowSize / 2, " ", "Please re-type your new Password");
                inputHere();
                getline(cin, retypedPassword);

                if(retypedPassword != newPassword){
                    loadData();
                    cout << endl;
                    centerText(windowSize / 2, " ", "Failed Changing Your Password");
                    system("pause");
                    studentMenu("BackToMenu", studentId);
                }else if(retypedPassword == newPassword){
                    replaceData(index, retypedPassword, studentPassword, ".\\src\\Database\\password.dat");
                    loadData();
                    cout << endl;
                    centerText(windowSize / 2, " ", "SUCCESS!");
                    system("pause");
                    studentMenu("BackToMenu", studentId);
                }
            }

            studentMenu("BackToMenu", studentId);

        }

        void replaceData(int index, string replacedData, vector<string> vectorArray, string filename){
            vectorArray[index] = replacedData;
            if( remove(filename.c_str()) != 0){
                perror("There's an error in deleting the file.");
            }else{
                fstream newFile(filename.c_str(), ios::in | ios::out | ios::app);
                for(string i : vectorArray){
                    newFile << i << endl;
                }
                newFile.close();
            }
        }
    
};