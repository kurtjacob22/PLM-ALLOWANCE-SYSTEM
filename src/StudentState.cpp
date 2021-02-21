#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void centerText();
void displayConsoleName();
void inputHere();
int getScreenSize();
void header();
int getVectorIndex();

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
                    system("pause");
                    studentMenu("");
                }
            }
            StudentAuth("Wrong Details, Enter Username");         
        }

        // TODO:
        void studentMenu(string type){
            cout << "MENU";
        }
    
};