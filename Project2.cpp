/*
💗💗💗Authorized by Noore Mozassam💗💗💗
      💀💀💀Date :- 13/10/25💀💀💀
description :- Create a bank management system in which multiple user can 
                create account and manupulate the data such as deposite amount,
                 withdraw amount check previous amount check profile info and delete account. 
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Account
{
    long long accountNo;
    string adharNo;
    string phoneNo;

    float amount;
    float newAmount;
    
    

    string name;
    string fatherName;
    string email;


    fstream file1, file2;

    public:
    long long search;

    void createAccount();
    void depositAmount();
    void withdrawAmount();
    void checkInfo();
    void deleteAcount();
};

int main()
{
    Account obj;
    
    int choice;
    

    do 
    {
        cout<<"\n\n \t\t\t------------Noore's Bank-------------"<<endl<<endl;
        cout<<"           Press 1 for create Account."<<endl;
        cout<<"           Press 2 for login Account."<<endl;
        cout<<"           Press 3 for delete Account."<<endl;
        cout<<"           Press 0 for exit"<<endl;

        cout<<"           Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1 :
            cin.ignore();
            obj.createAccount();
            break;

            case 2 : 
            cin.ignore();
            cout<<"Enter your account no :: ";
	        cin>>obj.search;
            do
            {
                cout<<"\n\n \t\t\t-------------Noore's Bank--------------"<<endl;
                cout<<"          Press 1 for Deposit Amount."<<endl;
                cout<<"          Press 2 for Withdraw Amount."<<endl;
                cout<<"          Press 3 for Check Info."<<endl;
                cout<<"          Press 0 for for Back Menu."<<endl;

                cout<<"Enter yout choice : ";
                cin>>choice;

                switch(choice)
                {
                    case 1 :
                    cin.ignore();
                    obj.depositAmount();
                    break;

                    case 2 :
                    cin.ignore();
                    obj.withdrawAmount();
                    break;

                    case 3 :
                    cin.ignore();
                    obj.checkInfo();
                    break;

                    

                    case 0 :
                    system("Exit");
                    break;

                    default:
                    cout<<"Invalid choice.......!"<<endl;
                    break;
                }
                system("Pause");
                system("cls");
            }
            while(choice!=0);
            break;

        case 3 :
            cin.ignore();
            obj.deleteAcount();
            break;

        case 0 :
            exit(0);
            break;

        default :
            cout<<"\n Invalid choice.......!"<<endl;
            break;
        }
    }
    while(choice!=0);
}

void Account :: createAccount()
{
    srand(time(0));
    accountNo = rand()*rand() + rand();

    cout<<"\n\n \t\t\t-------------Noore's Bank--------------"<<endl;
    cout<<"\t   Enter your name : ";
    getline(cin, name);

    cout<<"\t   Enter your father name : ";
    getline(cin, fatherName);

    cout<<"\t   Enter your adharNo : ";
    cin>>adharNo;

    cout<<"\t   Enter your phone number : ";
    cin>>phoneNo;

    cout<<"\t   Enter your email : ";
    cin>>email;

    cout<<"\t   Enter your amount : ";
    cin>>amount;

    cout<<"-----------Note!!!------------"<<endl;
    cout<<"\n\n your Account Number is "<<accountNo<<endl;
    cout<<"Please save it."<<endl;

    file1.open("accountData.txt", ios :: out | ios :: app);
    file1<<accountNo<<"\t"<<name<<"\t"<<fatherName<<"\t"<<adharNo<<"\t"<<phoneNo<<"\t"<<email<<"\t"<<amount<<endl;
    file1.close();
}

void Account :: depositAmount()
{
    cout<<"\n\n \t\t\t-------------Noore's Bank--------------"<<endl;
    cout<<"\t   Enter the new Amount : ";
    cin>>newAmount;

    bool found = false;

    file1.open("accountData.txt", ios :: in);
    file2.open("accountData2.txt", ios :: out | ios :: app);

    while(file1>>accountNo>>name>>fatherName>>adharNo>>phoneNo>>email>>amount)
    {
        if(accountNo == search)
        {
            found = true;
            cout<<"\nCurrent amount : "<< amount<<endl;
            amount = amount + newAmount;
            cout<<"Updated amount : "<<amount<<endl;
        }
        file2<<accountNo<<"\t"<<name<<"\t"<<fatherName<<"\t"<<adharNo<<"\t"<<phoneNo<<"\t"<<email<<"\t"<<amount<<endl;
    }
    file1.close();
    file2.close();
    remove("accountData.txt");
    rename("accountData2.txt", "accountData.txt");

    if(!found)
    {
        cout<<"Account not found.......!"<<endl;
    }
}

void Account :: withdrawAmount()
{
    cout<<"\t   Enter the amount for withdrawable : ";
    cin>>newAmount;

    bool found = false;

    file1.open("accountData.txt", ios :: in);
    file2.open("accountData2.txt", ios :: out | ios :: app);

    while(file1>>accountNo>>name>>fatherName>>adharNo>>phoneNo>>email>>amount)
    {
        if(accountNo == search)
        {
            found = true;
            if(amount >= newAmount)
            {
                cout<<"\n\t    Current amount : "<< amount<<endl;
                amount = amount - newAmount;
                cout<<"\t      Updated amount : "<<amount<<endl;
            }
            else
            {
                cout<<"Not enough money for withdrawable........!";
            }
        }
        file2<<accountNo<<"\t"<<name<<"\t"<<fatherName<<"\t"<<adharNo<<"\t"<<phoneNo<<"\t"<<email<<"\t"<<amount<<endl;
    }
    file1.close();
    file2.close();
    remove("accountData.txt");
    rename("accountData2.txt", "accountData.txt");

    if(!found)
    {
        cout<<"Account not found.......!"<<endl;
    }
}

void Account :: checkInfo()
{
    bool found = false;

    file1.open("accountData.txt", ios :: in);

    while(file1>>accountNo>>name>>fatherName>>adharNo>>phoneNo>>email>>amount)
    {
        if(accountNo == search)
        {
            found = true;
            
            cout<<"\n\n--------------Account Info---------------"<<endl;
            cout<<"\t\tAccount Number    : "<<accountNo<<endl;
            cout<<"\t\tName              : "<<name<<endl;
            cout<<"\t\tFather Name       : "<<fatherName<<endl;
            cout<<"\t\tPhone Number      : "<<phoneNo<<endl;
            cout<<"\t\tAdhar Number      : "<<adharNo<<endl;
            cout<<"\t\tEmail id          :"<<email<<endl;
            cout<<"\t\tAccount Balance   :"<<amount<<endl;
        }
    }
    file1.close();
    if(!found)
    {
        cout<<"Account not found.......!"<<endl;
    }
}

void Account :: deleteAcount()
{
    cout<<"\t   Enter the account number for delete : ";
    cin>>search;

    bool found = false;

    file1.open("accountData.txt", ios :: in);
    file2.open("accountData2.txt", ios :: out | ios :: app);

    while(file1>>accountNo>>name>>fatherName>>adharNo>>phoneNo>>email>>amount)
    {
        if(accountNo != search)
        {
            file2<<accountNo<<"\t"<<name<<"\t"<<fatherName<<"\t"<<adharNo<<"\t"<<phoneNo<<"\t"<<email<<"\t"<<amount<<endl;
        }
        else
        {
            found = true;
        }
    }
    file1.close();
    file2.close();
    remove("accountData.txt");
    rename("accountData2.txt", "accountData.txt");


    if(found)
    {
        cout<<"Account deleted Successfully."<<endl;
    }
    else
    {
        cout<<"Account not found.......!"<<endl;
    }
}