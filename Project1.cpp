/*
💗💗💗Authorized by Noore Mozassam💗💗💗
      💀💀💀Date :- 09/10/25💀💀💀
description :- Sign-up and login form
*/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class form
{
    string UserName, Password, Email;
    string SearchUserName, SearchPassword, SearchEmail;
    fstream file;

    public:
    void login();
    void signUP();
    void forgot();
}obj;

int main()
{
    int choice;

    do 
    {
        cout<<"Press 1 for login"<<endl;
        cout<<"Press 2 for signUP"<<endl;
        cout<<"Press 3 for forgot Password"<<endl;
        cout<<"Press 4 for exit"<<endl;

        cout<<"Enter the choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1 : 
            cin.ignore();
            obj.login();
            break;

            case 2 : 
            cin.ignore();
            obj.signUP();
            break;

            case 3 :
            cin.ignore();
            obj.forgot();
            break;

            case 4 : 
            return 0;
            break;

            default : cout<<"Invalid selection.....!"<<endl;
        }
    }
    while(choice!=5);
}

void form :: signUP()
{
    cout<<"Enter your UserName : ";
    getline(cin, UserName);

    cout<<"Enter your Email Address : ";
    getline(cin, Email);

    cout<<"Create a Password : ";
    getline(cin, Password);

    file.open("loginFormData.txt", ios :: out | ios ::app);
    file<<"UserName : "<<UserName<<" "<<"Email : "<<Email<<" "<<"Password : "<<Password<<endl;
    file.close();

    cout<<"------------SignUp successfully------------"<<endl<<endl<<endl;
}

void form :: login()
{
    cout<<"Enter your UserName : ";
    getline(cin, SearchUserName);

    cout<<"Enter your Password : ";
    getline(cin, SearchPassword);

    file.open("loginFormData.txt", ios :: in);
    if(!file)
    {
        cout<<"File not found! Please sign up first."<<endl;
        return;
    }

    bool found = false;
    string line;

    while(getline(file, line))
    {
        stringstream ss(line);
        string label1, label2, label3, u , e, p, colon;

        ss >> label1 >> colon >> u >> label2 >> colon >> e >> label3 >> colon >> p;

        if(u == SearchUserName && p == SearchPassword)
        {
            cout<<"\n-------------Account login successfully--------------"<<endl;
            cout<<"UserName : "<<u<<endl;
            cout<<"Email : "<<e<<endl<<endl<<endl;
            found = true;
            break;
        }
    }
    file.close();
}

void form :: forgot()
{
    cout<<"Enter the UserName : ";
    getline(cin, SearchUserName);

    cout<<"Enter the Email : ";
    getline(cin, SearchEmail);

    file.open("loginFormData.txt", ios :: in);
    if(!file)
    {
        cout<<"File not found......!";
    }

    bool found = false;
    string line;

    while(getline(file, line))
    {
        stringstream ss(line);
        string label1,label2, label3, u, e, p, colon;

        ss>> label1 >> colon >> u >> label2 >> colon >> e >> label3 >> colon >> p;

        if(u == SearchUserName && e == SearchEmail)
        {
            cout<<"\n -------------Password change Successfully----------"<<endl;
            cout<<"Your Password :: "<<p<<endl<<endl<<endl;
            found == true;
            break;
        }
    }
    file.close();
}