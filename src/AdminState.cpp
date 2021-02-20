#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void centerText();
void displayConsoleName();
void inputHere();
int getScreenSize();
void header();

class AdminState{
    public: 
        void AdminAuth(){

            int windowSize = getScreenSize();//-> constant number depending on the length of your Console

            string userName;
            string passWord;

            do{
                cin.clear();
                cin.sync();
                
                header();

                centerText(windowSize / 2, " ", "Enter Username");
                inputHere();
                getline(cin, userName);

                centerText(windowSize / 2, " ", "Enter Password");
                inputHere();
                getline(cin, passWord);

                if(userName == "ADMIN" && passWord == "1234PLM"){
                    centerText(windowSize / 2, " ", "THANKYOU FOR LOGGING IN");
                    loadData();
                    adminMenu("");
                    break;
                }else{
                    centerText(windowSize / 2, " ", "PLEASE ENTER VALID INFORMATION");
                    loadData();
                }


            }while(true);
            
        }

        void adminMenu(string type){

            int windowSize = getScreenSize();//-> constant number depending on the length of your Console
            int optMenu;

            if(type == "BackToMenu"){
                header();
                cout << endl;
                centerText(windowSize / 2, " ", "Transaction Sucess");
                loadData();
            }
            
            do{
                header();

                centerText(windowSize / 2, " ", "1.REGISTER ACCOUNT");
                centerText(windowSize / 2, " ", "2.BALANCE INQUIRY");
                centerText(windowSize / 2, " ", "3.VIEW ALL ACCOUNT HOLDER LIST");
                centerText(windowSize / 2, " ", "4.MODIFY AN ACCOUNT");
                centerText(windowSize / 2, " ", "5.ARCHIVE");
                centerText(windowSize / 2, " ", "6.EXIT");
                cout << endl;
                centerText(windowSize / 2, " ", "Select Option");
                inputHere();
                cin >> optMenu;

                if(optMenu == 1){
                    registerAccount();
                    break;
                }else if(optMenu == 2){
                    balanceInquiry();
                    break;
                }else if(optMenu == 3){
                    viewAllAccounts();
                    break;
                }else if(optMenu == 4){
                    modifyAccount();
                }

            }while(true);

        }

        void registerAccount(){
            
            int windowSize = getScreenSize();//-> constant number depending on the length of your Console
            int recordCount;

            header();

            centerText(windowSize / 2, " ", "How many record do you want to insert");
            inputHere();
            cin >> recordCount;

            fstream studentNumFile, studentNameFile, studentAddressFile, studentPhoneNumberFile, studentCourseFile, studentSectionFile, dateEnrolledFile, birthdayFile, amountFile;
            studentNumFile.open(".\\src\\Database\\student_number.dat", ios::in | ios::out | ios::app);
            studentNameFile.open(".\\src\\Database\\student_name.dat", ios::in | ios::out | ios::app);
            studentAddressFile.open(".\\src\\Database\\student_address.dat", ios::in | ios::out | ios::app);
            studentPhoneNumberFile.open(".\\src\\Database\\student_phone_number.dat", ios::in | ios::out | ios::app);
            studentCourseFile.open(".\\src\\Database\\student_course.dat", ios::in | ios::out | ios::app);
            studentSectionFile.open(".\\src\\Database\\student_section.dat", ios::in | ios::out | ios::app);
            dateEnrolledFile.open(".\\src\\Database\\student_date_enrolled.dat", ios::in | ios::out | ios::app);
            birthdayFile.open(".\\src\\Database\\student_birthday.dat", ios::in | ios::out | ios::app);
            amountFile.open(".\\src\\Database\\student_balance.dat", ios::in | ios::out | ios::app);

            cin.ignore();
            cin.sync();

            for (int i = 0; i < recordCount; i++){
                string capt;
                // ! student number     
                string stdId;
                bool checkIfValidUser;
                do{
                    header();
                    capt = "Enter student number (" + to_string(i + 1) + ")";
                    centerText(windowSize / 2, " ", capt);
                    inputHere();
                    getline(cin, stdId);

                }while(stdId == "" || checkIfValidUser == true);
                studentNumFile << stdId << endl;

                // ! student full name
                string stdName;
                do{
                    header();
                    capt = "Enter full name (" + to_string(i + 1) + ")";
                    centerText(windowSize / 2, " ", capt);
                    inputHere();
                    getline(cin, stdName);
                }while(stdName == "");
                studentNameFile << stdName << endl;

                // ! student address
                string stdEmailAddress;
                do{
                    header();
                    capt = "Enter Email Address (" + to_string(i + 1) + ")";
                    centerText(windowSize / 2, " ", capt);
                    inputHere();
                    getline(cin, stdEmailAddress);
                }while(stdEmailAddress == "");
                studentAddressFile << stdEmailAddress << endl;

                // ! phone number
                string stdPhone;
                do{
                    header();
                    capt = "Enter Phone number (" + to_string(i + 1) + ")";
                    centerText(windowSize / 2, " ", capt);
                    inputHere();
                    getline(cin, stdPhone);
                }while(stdPhone == "");
                studentPhoneNumberFile << stdPhone << endl;

                // ! course
                string stdCourse;
                do{
                    header();
                    capt = "Enter Course (" + to_string(i + 1) + ")";
                    centerText(windowSize / 2, " ", capt);
                    inputHere();
                    getline(cin, stdCourse);
                }while(stdCourse == "");
                studentCourseFile << stdCourse << endl;

                // ! section
                string stdSection;
                do{
                    header();
                    capt = "Enter Section -YR - Sect (" + to_string(i + 1) + ")";
                    centerText(windowSize / 2, " ", capt);
                    inputHere();
                    getline(cin, stdSection);
                }while(stdSection == "");
                studentSectionFile << stdSection << endl;

                // ! date enrolled MM\DD\YY format
                string dateEnrolled;
                do{
                    header();
                    capt = "Enter Date Enrolled - MM\\DD\\YY format (" + to_string(i + 1) + ")";
                    centerText(windowSize / 2, " ", capt);
                    inputHere();
                    getline(cin, dateEnrolled);
                }while(dateEnrolled == "");
                dateEnrolledFile << dateEnrolled << endl;

                //! birthday MM\DD\YY format
                string stdBirthday;
                do{
                    header();
                    capt = "Enter BirthDay - MM\\DD\\YY format (" + to_string(i + 1) + ")";
                    centerText(windowSize / 2, " ", capt);
                    inputHere();
                    getline(cin, stdBirthday);
                }while(stdBirthday == "");
                birthdayFile << stdBirthday << endl;

                //! enter amount balance
                string stdBalance;
                do{
                    header();
                    capt = "Enter Amount? - YES or NO (" + to_string(i + 1) + ")";
                    centerText(windowSize / 2, " ", capt);
                    inputHere();
                    getline(cin, stdBalance);
                }while(stdBalance == "");
                if(stdBalance == "YES" || stdBalance == "yes"){
                    amountFile << 1000 << endl;
                }else{
                    amountFile << 0 << endl;
                }
            }
            
            studentNumFile.close();
            studentNameFile.close();
            studentAddressFile.close();
            studentPhoneNumberFile.close();
            studentCourseFile.close();
            studentSectionFile.close();
            dateEnrolledFile.close();
            birthdayFile.close();
            amountFile.close();

            adminMenu("BackToMenu");
        }

        void balanceInquiry(){
            cin.ignore();
            cin.sync();
            
            int windowSize = getScreenSize();//-> constant number depending on the length of your Console

            fstream studentNumFile, studentNameFile, studentAddressFile, studentPhoneNumberFile, studentCourseFile, studentSectionFile, dateEnrolledFile, birthdayFile, amountFile;
            studentNumFile.open(".\\src\\Database\\student_number.dat", ios::in | ios::out | ios::app);
            amountFile.open(".\\src\\Database\\student_balance.dat", ios::in | ios::out | ios::app);

            int index;
            vector<string> accountsNumber, accountBalance;
            string input, stdInput;
            while(getline(studentNumFile, input)){
                accountsNumber.push_back(input); // inserts data to a temporary vector
            }
            while(getline(amountFile, input)){
                accountBalance.push_back(input); // inserts data to a temporary vector
            }

            header();
            centerText(windowSize / 2, " ", "Enter Student Number: ");
            inputHere();
            getline(cin, stdInput);
            index = getVectorIndex(stdInput, accountsNumber);
            if(index != -1){
                string msg = "The remaining balance of " + accountsNumber[index] + " is: " + accountBalance[index];
                loadData();
                header();
                centerText(windowSize / 2, " ", msg);
                system("pause");
                
            }else{
                string msg = stdInput + " is an invalid user";
                loadData();
                header();
                centerText(windowSize / 2, " ", msg);
                system("pause");
            }

            studentNumFile.close();
            amountFile.close();

            adminMenu("BackToMenu");
        }

        void viewAllAccounts(){
            cin.ignore();
            cin.sync();
            int windowSize = getScreenSize();//-> constant number depending on the length of your Console

            header();
            centerText(windowSize / 2, " ", "Student Accounts");

            fstream studentNumFile, studentNameFile, studentAddressFile, studentPhoneNumberFile, studentCourseFile, studentSectionFile, dateEnrolledFile, birthdayFile, amountFile;
            studentNumFile.open(".\\src\\Database\\student_number.dat", ios::in | ios::out | ios::app);
            studentNameFile.open(".\\src\\Database\\student_name.dat", ios::in | ios::out | ios::app);
            studentAddressFile.open(".\\src\\Database\\student_address.dat", ios::in | ios::out | ios::app);
            studentPhoneNumberFile.open(".\\src\\Database\\student_phone_number.dat", ios::in | ios::out | ios::app);
            studentCourseFile.open(".\\src\\Database\\student_course.dat", ios::in | ios::out | ios::app);
            studentSectionFile.open(".\\src\\Database\\student_section.dat", ios::in | ios::out | ios::app);
            dateEnrolledFile.open(".\\src\\Database\\student_date_enrolled.dat", ios::in | ios::out | ios::app);
            birthdayFile.open(".\\src\\Database\\student_birthday.dat", ios::in | ios::out | ios::app);
            amountFile.open(".\\src\\Database\\student_balance.dat", ios::in | ios::out | ios::app);

            vector<string> studentNumber, studentName, studentAddress, studentPhoneNumber, studentCourse, studentSection, studentEnrolledDate, studentBirthday, studentBalance;
            int buff = 20;

            string input;
            while(getline(studentNumFile, input)){
                studentNumber.push_back(input);
            }
            while(getline(studentNameFile, input)){
                studentName.push_back(input);
            }
            while(getline(studentAddressFile, input)){
                studentAddress.push_back(input);
            }
            while(getline(studentPhoneNumberFile, input)){
                studentPhoneNumber.push_back(input);
            }
            while(getline(studentCourseFile, input)){
                studentCourse.push_back(input);
            }
            while(getline(studentSectionFile, input)){
                studentSection.push_back(input);
            }
            while(getline(dateEnrolledFile, input)){
                studentEnrolledDate.push_back(input);
            }
            while(getline(birthdayFile, input)){
                studentBirthday.push_back(input);
            }
            while(getline(amountFile, input)){
                studentBalance.push_back(input);
            }

            string msg, title;
            cout << endl;
            title = studentNumber[0] + " " + indentText(buff - studentNumber[0].length(), " ") + 
                        " " + studentName[0] + " " + indentText((buff + 7) - studentName[0].length(), " ") + 
                        " " + studentAddress[0] + " " + indentText((buff + 10) - studentAddress[0].length(), " ") + 
                        " " + studentPhoneNumber[0] + " " + indentText(buff - studentPhoneNumber[0].length(), " ") + 
                        " " + studentCourse[0] + " " + indentText(buff - studentCourse[0].length(), " ") +
                        " " + studentEnrolledDate[0] + " " + indentText(buff - studentEnrolledDate[0].length(), " ") +
                        " " + studentBirthday[0] + " " + indentText(buff - studentBirthday[0].length(), " ") +
                        " " + studentBalance[0] + " " + indentText(buff - studentBalance[0].length(), "");
            
            cout << title << endl;
            
            for(int i = 1; i < studentNumber.size(); i++){
                msg = studentNumber[i] + " " + indentText(buff - studentNumber[i].length(), "-") + 
                        " " + studentName[i] + " " + indentText((buff + 7) - studentName[i].length(), "-") + 
                        " " + studentAddress[i] + " " + indentText((buff + 10) - studentAddress[i].length(), "-") + 
                        " " + studentPhoneNumber[i] + " " + indentText(buff - studentPhoneNumber[i].length(), "-") + 
                        " " + studentCourse[i] + " " + indentText(buff - studentCourse[i].length(), "-") +
                        " " + studentEnrolledDate[i] + " " + indentText(buff - studentEnrolledDate[i].length(), "-") +
                        " " + studentBirthday[i] + " " + indentText(buff - studentBirthday[i].length(), "-") +
                        " " + studentBalance[i] + " " + indentText(buff - studentBalance[i].length(), "");
                cout << msg;
                cout << endl;
                
            } 

            studentNumFile.close();
            studentNameFile.close();
            studentAddressFile.close();
            studentPhoneNumberFile.close();
            studentCourseFile.close();
            studentSectionFile.close();
            dateEnrolledFile.close();
            birthdayFile.close();
            amountFile.close();

            system("pause");
            adminMenu("BackToMenu");

        }

        void modifyAccount(){
            cin.ignore();
            cin.sync();

            int windowSize = getScreenSize();//-> constant number depending on the length of your Console
            fstream studentNumFile, studentNameFile, studentAddressFile, studentPhoneNumberFile, studentCourseFile, studentSectionFile, dateEnrolledFile, birthdayFile, amountFile;
            studentNumFile.open(".\\src\\Database\\student_number.dat", ios::in | ios::out | ios::app);
            studentNameFile.open(".\\src\\Database\\student_name.dat", ios::in | ios::out | ios::app);
            studentAddressFile.open(".\\src\\Database\\student_address.dat", ios::in | ios::out | ios::app);
            studentPhoneNumberFile.open(".\\src\\Database\\student_phone_number.dat", ios::in | ios::out | ios::app);
            studentCourseFile.open(".\\src\\Database\\student_course.dat", ios::in | ios::out | ios::app);
            studentSectionFile.open(".\\src\\Database\\student_section.dat", ios::in | ios::out | ios::app);
            dateEnrolledFile.open(".\\src\\Database\\student_date_enrolled.dat", ios::in | ios::out | ios::app);
            birthdayFile.open(".\\src\\Database\\student_birthday.dat", ios::in | ios::out | ios::app);
            amountFile.open(".\\src\\Database\\student_balance.dat", ios::in | ios::out | ios::app);

            vector<string> studentNumber, studentName, studentAddress, studentPhoneNumber, studentCourse, studentSection, studentEnrolledDate, studentBirthday, studentBalance;

            string input;
            while(getline(studentNumFile, input)){
                studentNumber.push_back(input);
            }
            while(getline(studentNameFile, input)){
                studentName.push_back(input);
            }
            while(getline(studentAddressFile, input)){
                studentAddress.push_back(input);
            }
            while(getline(studentPhoneNumberFile, input)){
                studentPhoneNumber.push_back(input);
            }
            while(getline(studentCourseFile, input)){
                studentCourse.push_back(input);
            }
            while(getline(studentSectionFile, input)){
                studentSection.push_back(input);
            }
            while(getline(dateEnrolledFile, input)){
                studentEnrolledDate.push_back(input);
            }
            while(getline(birthdayFile, input)){
                studentBirthday.push_back(input);
            }
            while(getline(amountFile, input)){
                studentBalance.push_back(input);
            }

            studentNumFile.close();
            studentNameFile.close();
            studentAddressFile.close();
            studentPhoneNumberFile.close();
            studentCourseFile.close();
            studentSectionFile.close();
            dateEnrolledFile.close();
            birthdayFile.close();
            amountFile.close();

            // ! start part
            string stdInput;
            header();
            centerText(windowSize / 2, " ", "Enter Student Number: ");
            inputHere();
            getline(cin, stdInput);

            int index = getVectorIndex(stdInput, studentNumber);

            if(index != -1){ //? if exists
                header();
                centerText(windowSize / 2, " ", "Here's The Data");
                cout << endl;
                centerText(windowSize / 2, " ", "Student Number: " + studentNumber[index]);
                centerText(windowSize / 2, " ", "Student Name: " + studentName[index]);
                centerText(windowSize / 2, " ", "Email Address: " + studentAddress[index]);
                centerText(windowSize / 2, " ", "Phone Number: " + studentPhoneNumber[index]);
                centerText(windowSize / 2, " ", "Course: " + studentCourse[index]);
                centerText(windowSize / 2, " ", "Section: " + studentSection[index]);
                centerText(windowSize / 2, " ", "Enrolled Date: " + studentEnrolledDate[index]);
                centerText(windowSize / 2, " ", "Birthday: " + studentBirthday[index]);
                centerText(windowSize / 2, " ", "Balance: " + studentBalance[index]);
                system("pause");

                string editData;
                centerText(windowSize / 2, " ", "Leave it blank if you don't wish to modify it");
                changeData(index, editData, studentNumber, ".\\src\\Database\\student_number.dat", "Change Student Number into: ");
                changeData(index, editData, studentName, ".\\src\\Database\\student_name.dat", "Change Student Name into: ");
                changeData(index, editData, studentAddress, ".\\src\\Database\\student_address.dat", "Change Email Address into: ");
                changeData(index, editData, studentPhoneNumber, ".\\src\\Database\\student_phone_number.dat", "Change Phone Number into: ");
                changeData(index, editData, studentCourse, ".\\src\\Database\\student_course.dat", "Change Course into: ");
                changeData(index, editData, studentSection, ".\\src\\Database\\student_section.dat", "Change Section into: ");
                changeData(index, editData, studentEnrolledDate, ".\\src\\Database\\student_date_enrolled.dat", "Change Date Enrolled into: ");
                changeData(index, editData, studentBirthday, ".\\src\\Database\\student_birthday.dat", "Change Birthday into: ");
                changeData(index, editData, studentBalance, ".\\src\\Database\\student_balance.dat", "Change Balance into: ");

                centerText(windowSize / 2, " ", "Done Editing!");
                



            }else{ //? not exists
                header();
                centerText(windowSize / 2, " ", "STUDENT NOT FOUND");
            }

            system("pause");
            adminMenu("BackToMenu");

        }

        int getVectorIndex(string text, vector<string> vectorArray){
            for(int i = 0; i < vectorArray.size(); i++){
                if(text == vectorArray[i]){
                    return i;
                }
            }
            return -1;
        }

        void changeData(int index, string editData, vector<string> vectorArray, string filename, string messagePrmpt){
            int windowSize = getScreenSize();//-> constant number depending on the length of your Console

            centerText(windowSize / 2, " ", messagePrmpt);
            inputHere();
            getline(cin, editData);

            if(editData == ""){
                editData = vectorArray[index];
            }

            vectorArray.erase(vectorArray.begin() + (index));
            vectorArray.push_back(editData);

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
// END OF ADMIN STATE