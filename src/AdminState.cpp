#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// #include "./StudentState.cpp"

void centerText();
void displayConsoleName();
void inputHere();
int getScreenSize();
void header();
void studentMenu();
void menu();

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
                centerText(windowSize / 2, " ", "6.ADD CASH TO ALL STUDENTS");
                centerText(windowSize / 2, " ", "7.VIEW ARCHIVE LIST");
                centerText(windowSize / 2, " ", "8.EXIT");
                centerText(windowSize / 2, " ", "9.LOGOUT");
                cout << endl;
                centerText(windowSize / 2, " ", "Select Option");
                inputHere();
                cin >> optMenu;

                if(optMenu == 1){
                    registerAccount();
                    break;
                }else if(optMenu == 2){
                    balanceInquiry("ADMIN", "");
                    break;
                }else if(optMenu == 3){
                    viewAllAccounts("");
                    break;
                }else if(optMenu == 4){
                    modifyAccount();
                    break;
                }else if(optMenu == 5){
                    archiveAccount();
                    break;
                }else if(optMenu == 6){
                    addCash();
                    break;
                }else if(optMenu == 7){
                    viewAllAccounts("ArchiveList");
                }else if(optMenu == 8){
                    system("cls");
                    system("exit");
                    break;
                }else if(optMenu == 9){
                    loadData();
                    menu();
                    break;
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

            fstream studentNumFile, studentNameFile, studentAddressFile, studentPhoneNumberFile, studentCourseFile, studentSectionFile, dateEnrolledFile, birthdayFile, amountFile, passwordFile;
            studentNumFile.open(".\\src\\Database\\student_number.dat", ios::in | ios::out | ios::app);
            studentNameFile.open(".\\src\\Database\\student_name.dat", ios::in | ios::out | ios::app);
            studentAddressFile.open(".\\src\\Database\\student_address.dat", ios::in | ios::out | ios::app);
            studentPhoneNumberFile.open(".\\src\\Database\\student_phone_number.dat", ios::in | ios::out | ios::app);
            studentCourseFile.open(".\\src\\Database\\student_course.dat", ios::in | ios::out | ios::app);
            studentSectionFile.open(".\\src\\Database\\student_section.dat", ios::in | ios::out | ios::app);
            dateEnrolledFile.open(".\\src\\Database\\student_date_enrolled.dat", ios::in | ios::out | ios::app);
            birthdayFile.open(".\\src\\Database\\student_birthday.dat", ios::in | ios::out | ios::app);
            amountFile.open(".\\src\\Database\\student_balance.dat", ios::in | ios::out | ios::app);
            passwordFile.open(".\\src\\Database\\password.dat", ios::in | ios::out | ios::app);

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
                passwordFile << stdId << endl;

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

        void balanceInquiry(string type, string studentNum){
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

            if(type == "ADMIN"){
                header();
                centerText(windowSize / 2, " ", "Enter Student Number: ");
                inputHere();
                getline(cin, stdInput);
            }else if(type == "STUDENT"){
                stdInput = studentNum;
            }

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

            
            if(type == "ADMIN"){
                adminMenu("BackToMenu");
            }
        }

        void viewAllAccounts(string type){
            cin.ignore();
            cin.sync();
            int windowSize = getScreenSize();//-> constant number depending on the length of your Console

            header();
            centerText(windowSize / 2, " ", "Student Accounts");
            fstream studentNumFile, studentNameFile, studentAddressFile, studentPhoneNumberFile, studentCourseFile, studentSectionFile, dateEnrolledFile, birthdayFile, amountFile;

            if(type == "ArchiveList"){
                studentNumFile.open(".\\src\\Database\\archive\\archive_student_number.dat", ios::in | ios::out | ios::app);
                studentNameFile.open(".\\src\\Database\\archive\\archive_student_name.dat", ios::in | ios::out | ios::app);
                studentAddressFile.open(".\\src\\Database\\archive\\archive_student_address.dat", ios::in | ios::out | ios::app);
                studentPhoneNumberFile.open(".\\src\\Database\\archive\\archive_student_phone_number.dat", ios::in | ios::out | ios::app);
                studentCourseFile.open(".\\src\\Database\\archive\\archive_student_course.dat", ios::in | ios::out | ios::app);
                studentSectionFile.open(".\\src\\Database\\archive\\archive_student_section.dat", ios::in | ios::out | ios::app);
                dateEnrolledFile.open(".\\src\\Database\\archive\\archive_student_date_enrolled.dat", ios::in | ios::out | ios::app);
                birthdayFile.open(".\\src\\Database\\archive\\archive_student_birthday.dat", ios::in | ios::out | ios::app);
                amountFile.open(".\\src\\Database\\archive\\archive_student_balance.dat", ios::in | ios::out | ios::app);
            }else{
                studentNumFile.open(".\\src\\Database\\student_number.dat", ios::in | ios::out | ios::app);
                studentNameFile.open(".\\src\\Database\\student_name.dat", ios::in | ios::out | ios::app);
                studentAddressFile.open(".\\src\\Database\\student_address.dat", ios::in | ios::out | ios::app);
                studentPhoneNumberFile.open(".\\src\\Database\\student_phone_number.dat", ios::in | ios::out | ios::app);
                studentCourseFile.open(".\\src\\Database\\student_course.dat", ios::in | ios::out | ios::app);
                studentSectionFile.open(".\\src\\Database\\student_section.dat", ios::in | ios::out | ios::app);
                dateEnrolledFile.open(".\\src\\Database\\student_date_enrolled.dat", ios::in | ios::out | ios::app);
                birthdayFile.open(".\\src\\Database\\student_birthday.dat", ios::in | ios::out | ios::app);
                amountFile.open(".\\src\\Database\\student_balance.dat", ios::in | ios::out | ios::app);
            }

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
            fstream studentNumFile, studentNameFile, studentAddressFile, studentPhoneNumberFile, studentCourseFile, studentSectionFile, dateEnrolledFile, birthdayFile, amountFile, passwordFile;
            studentNumFile.open(".\\src\\Database\\student_number.dat", ios::in | ios::out | ios::app);
            studentNameFile.open(".\\src\\Database\\student_name.dat", ios::in | ios::out | ios::app);
            studentAddressFile.open(".\\src\\Database\\student_address.dat", ios::in | ios::out | ios::app);
            studentPhoneNumberFile.open(".\\src\\Database\\student_phone_number.dat", ios::in | ios::out | ios::app);
            studentCourseFile.open(".\\src\\Database\\student_course.dat", ios::in | ios::out | ios::app);
            studentSectionFile.open(".\\src\\Database\\student_section.dat", ios::in | ios::out | ios::app);
            dateEnrolledFile.open(".\\src\\Database\\student_date_enrolled.dat", ios::in | ios::out | ios::app);
            birthdayFile.open(".\\src\\Database\\student_birthday.dat", ios::in | ios::out | ios::app);
            amountFile.open(".\\src\\Database\\student_balance.dat", ios::in | ios::out | ios::app);
            passwordFile.open(".\\src\\Database\\password.dat", ios::in | ios::out | ios::app);

            vector<string> studentNumber, studentName, studentAddress, studentPhoneNumber, studentCourse, studentSection, studentEnrolledDate, studentBirthday, studentBalance, studentPassword;

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
            while(getline(passwordFile, input)){
                studentPassword.push_back(input);
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
            passwordFile.close();

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
                centerText(windowSize / 2, " ", "Password: " + studentPassword[index]);
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
                changeData(index, editData, studentPassword, ".\\src\\Database\\password.dat", "Change Password into: ");
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

        void archiveAccount(){
            

            int windowSize = getScreenSize();//-> constant number depending on the length of your Console   
            
            fstream studentNumFile, studentNameFile, studentAddressFile, studentPhoneNumberFile, studentCourseFile, studentSectionFile, dateEnrolledFile, birthdayFile, amountFile, passwordFile;
            studentNumFile.open(".\\src\\Database\\student_number.dat", ios::in | ios::out | ios::app);
            studentNameFile.open(".\\src\\Database\\student_name.dat", ios::in | ios::out | ios::app);
            studentAddressFile.open(".\\src\\Database\\student_address.dat", ios::in | ios::out | ios::app);
            studentPhoneNumberFile.open(".\\src\\Database\\student_phone_number.dat", ios::in | ios::out | ios::app);
            studentCourseFile.open(".\\src\\Database\\student_course.dat", ios::in | ios::out | ios::app);
            studentSectionFile.open(".\\src\\Database\\student_section.dat", ios::in | ios::out | ios::app);
            dateEnrolledFile.open(".\\src\\Database\\student_date_enrolled.dat", ios::in | ios::out | ios::app);
            birthdayFile.open(".\\src\\Database\\student_birthday.dat", ios::in | ios::out | ios::app);
            amountFile.open(".\\src\\Database\\student_balance.dat", ios::in | ios::out | ios::app);
            passwordFile.open(".\\src\\Database\\password.dat", ios::in | ios::out | ios::app);

            vector<string> studentNumber, studentName, studentAddress, studentPhoneNumber, studentCourse, studentSection, studentEnrolledDate, studentBirthday, studentBalance, studentPassword;

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
            while(getline(passwordFile, input)){
                studentPassword.push_back(input);
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
            passwordFile.close();

            cin.ignore();
            cin.sync();

            string stdId;
            header();
            centerText(windowSize / 2, " ", "Enter Student Number");
            inputHere();
            getline(cin, stdId);

            //check if user exists
            int index = getVectorIndex(stdId, studentNumber);
            if(index != -1){//! if user exists
                header();
                centerText(windowSize / 2, " ", "Here's The User's Data");
                cout << endl;
                centerText(windowSize / 2, " ", "Student Number: " + studentNumber[index]);
                centerText(windowSize / 2, " ", "Password: " + studentPassword[index]);
                centerText(windowSize / 2, " ", "Student Name: " + studentName[index]);
                centerText(windowSize / 2, " ", "Email Address: " + studentAddress[index]);
                centerText(windowSize / 2, " ", "Phone Number: " + studentPhoneNumber[index]);
                centerText(windowSize / 2, " ", "Course: " + studentCourse[index]);
                centerText(windowSize / 2, " ", "Section: " + studentSection[index]);
                centerText(windowSize / 2, " ", "Enrolled Date: " + studentEnrolledDate[index]);
                centerText(windowSize / 2, " ", "Birthday: " + studentBirthday[index]);
                centerText(windowSize / 2, " ", "Balance: " + studentBalance[index]);
                centerText(windowSize / 2, " ", "Are you sure you want to send this account to archive?(Y|N)");
                string archiveQ;
                inputHere();
                getline(cin, archiveQ);
                if(archiveQ == "Y" || archiveQ == "y"){
                    //? Sending to archive list
                    fstream archive_studentNumFile, archive_studentNameFile, archive_studentAddressFile, archive_studentPhoneNumberFile, archive_studentCourseFile, archive_studentSectionFile, archive_dateEnrolledFile, archive_birthdayFile, archive_amountFile, archive_passwordFile;

                    archive_studentNumFile.open(".\\src\\Database\\archive\\archive_student_number.dat", ios::in | ios::out | ios::app);
                    archive_studentNameFile.open(".\\src\\Database\\archive\\archive_student_name.dat", ios::in | ios::out | ios::app);
                    archive_studentAddressFile.open(".\\src\\Database\\archive\\archive_student_address.dat", ios::in | ios::out | ios::app);
                    archive_studentPhoneNumberFile.open(".\\src\\Database\\archive\\archive_student_phone_number.dat", ios::in | ios::out | ios::app);
                    archive_studentCourseFile.open(".\\src\\Database\\archive\\archive_student_course.dat", ios::in | ios::out | ios::app);
                    archive_studentSectionFile.open(".\\src\\Database\\archive\\archive_student_section.dat", ios::in | ios::out | ios::app);
                    archive_dateEnrolledFile.open(".\\src\\Database\\archive\\archive_student_date_enrolled.dat", ios::in | ios::out | ios::app);
                    archive_birthdayFile.open(".\\src\\Database\\archive\\archive_student_birthday.dat", ios::in | ios::out | ios::app);
                    archive_amountFile.open(".\\src\\Database\\archive\\archive_student_balance.dat", ios::in | ios::out | ios::app);
                    archive_passwordFile.open(".\\src\\Database\\archive\\archive_password.dat", ios::in | ios::out | ios::app);

                    archive_studentNumFile << studentNumber[index] << endl;
                    archive_studentNameFile << studentName[index] << endl;
                    archive_studentAddressFile << studentAddress[index] << endl;
                    archive_studentPhoneNumberFile << studentPhoneNumber[index] << endl;
                    archive_studentCourseFile << studentCourse[index] << endl;
                    archive_studentSectionFile << studentSection[index] << endl;
                    archive_dateEnrolledFile <<studentEnrolledDate[index] << endl;
                    archive_birthdayFile << studentBirthday[index] << endl;
                    archive_amountFile << studentBalance[index] << endl;
                    archive_passwordFile << studentPassword[index] << endl;

                    archive_studentNumFile.close();
                    archive_studentNameFile.close();
                    archive_studentAddressFile.close();
                    archive_studentPhoneNumberFile.close();
                    archive_studentCourseFile.close();
                    archive_studentSectionFile.close();
                    archive_dateEnrolledFile.close();
                    archive_birthdayFile.close();
                    archive_amountFile.close();
                    archive_passwordFile.close();

                    //! delete the archived info from student's Database
                    removeData(index, ".\\src\\Database\\student_number.dat", studentNumber);
                    removeData(index, ".\\src\\Database\\student_name.dat", studentName);
                    removeData(index, ".\\src\\Database\\student_address.dat", studentAddress);
                    removeData(index, ".\\src\\Database\\student_phone_number.dat", studentPhoneNumber);
                    removeData(index, ".\\src\\Database\\student_course.dat", studentCourse);
                    removeData(index, ".\\src\\Database\\student_section.dat", studentSection);
                    removeData(index, ".\\src\\Database\\student_date_enrolled.dat", studentEnrolledDate);
                    removeData(index, ".\\src\\Database\\student_birthday.dat", studentBirthday);
                    removeData(index, ".\\src\\Database\\student_balance.dat", studentBalance);
                    removeData(index, ".\\src\\Database\\password.dat", studentPassword);
                    
                    loadData();
                    cout << endl;
                    centerText(windowSize / 2, " ", "Sent To Archive List!");
                }else{
                    loadData();
                    cout << endl;
                    centerText(windowSize / 2, " ", "Failed Sending to Archive List!");
                }

                system("pause");
            }else{
                string msg = stdId + " is an invalid user";
                loadData();
                header();
                centerText(windowSize / 2, " ", msg);
                system("pause");
            }
            
            

            adminMenu("backToMenu");

        }

        void addCash(){
            cin.ignore();
            cin.sync();

            int windowSize = getScreenSize();//-> constant number depending on the length of your Console

            fstream balanceFile;
            balanceFile.open(".\\src\\Database\\student_balance.dat", ios::in | ios::out | ios::app);

            vector<string> studentBalance;
            string input;
            while(getline(balanceFile, input)){
                studentBalance.push_back(input);
            }

            balanceFile.close();
            int cashAmount;
            header();
            centerText(windowSize / 2, " ", "Enter Amount in Cash");
            inputHere();
            cin >> cashAmount;

            int cashTemp = 0;
            for(int i = 1; i < studentBalance.size(); i++){
                // cashTemp[i - 1] = stoi(studentBalance[i]) + cashAmount;
                cashTemp = stoi(studentBalance[i]) + cashAmount;
                studentBalance[i] = to_string(cashTemp);
            }

            //! insert edited to new file
            if( remove(".\\src\\Database\\student_balance.dat") != 0){
                    perror("There's an error in deleting the file.");
            }else{
                fstream newFile(".\\src\\Database\\student_balance.dat", ios::in | ios::out | ios::app);
                for(string i : studentBalance){
                    newFile << i << endl;
                }
                newFile.close();
            }
            
            

            loadData();
            cout << endl;
            centerText(windowSize / 2, " ", "SUCCESS!");
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

        void removeData(int index, string filename, vector<string> vectorArray){
            vectorArray.erase(vectorArray.begin() + (index));//? removes specific element
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