#include <iostream>

using namespace std;


struct CreateAccount{
    string studentNumber; //! same with password 
    string birthDay; //! -> MM/DD/YY
    string dateEnrolled; //! -> MM/DD/YY
    int defBalance; //! -> 1k default balance
    string password = studentNumber;

    // CreateAccount(){
    //     studentNumber = "";
    //     birthDay = "";
    //     dateEnrolled = "";
    //     defbalance = 0;      
    //     password = "";
    // }

    CreateAccount(string stdNum, string bDay, string dEnrolled, int balance){
        studentNumber = stdNum;
        birthDay = bDay;
        dateEnrolled = dEnrolled;
        defBalance = balance;
        password = stdNum; // same with student number -> by default 
    }
};