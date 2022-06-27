#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include<bits/stdc++.h>
using namespace std;
void create();
void login();
void home();
void searchname();
void message();
void logout();
void seemsg();
void all();
void see();
void purpose();
int main()
{

    system("cls");
    int choice;
    cout << "*****************************WELCOME TO THE TWITTER CLONE********************************************" << endl;
    cout << "1.Create Account" << endl;
    cout << "2.Login" << endl;
    cout << "*****************************************************************************************************" << endl;
    cout<<"YOUR CHOICE : ";
    cin >> choice;
    
    switch (choice)
    {
    case 1:
        create();
        break;
    case 2:
        login();
        break;
        cin.get();
    }
}
void create()
{
    string name;
    string email;
    string password;
    string msg = "Post:";
    system("cls");
    cout << "*****************************************************" << endl;
    cout << "                        SIGN UP                        " << endl;
    cout << "*****************************************************" << endl;
    cout << "Enter your Name" << endl;
    cin >> name;
    cout<<"------------------------------------------"<<endl;
    cout << "ENter your email address" << endl;
    cin >> email;
    cout<<"------------------------------------------"<<endl;
    cout << "Enter your password" << endl;
    cin >> password;
    ofstream one("first.txt",ios::app);
    one << name << " " << email << " " << password << " " << msg << endl;
    one.close();
    system("cls");
    cout<<"ACCOUNT CREATED .........Please login"<<endl;
    system("pause");
    main();
}
void login()
{
    ifstream one("first.txt");
    string name;
    string email;
    string password;
    string msg;
    string femail;
    string fpassword;
    system("cls");
    cout << "*****************************************************" << endl;
    cout << "                        LOGIN                        " << endl;
    cout << "*****************************************************" << endl;
    cout << "Email Address" << endl;
    cin >> femail;
    while (one >> name >> email >> password >> msg)
    {
        if (femail == email)
        {
            system("cls");
            cout << "*****************************************************" << endl;
            cout << "                        LOGIN                        " << endl;
            cout << "*****************************************************" << endl;
            cout << "Password" << endl;
            cin >> fpassword;
            system("cls");
            if (fpassword == password)
            {
                home();
                break;
            }
            if (fpassword != password)
            {
                cout << "Incorrect password" << endl;
                break;
            }
        }
        if (femail != email)
        {
            
            system("cls");
            cout << "Email id doesnot exist" << endl;
            cout << "Please create accoutnt" << endl;
            
        }
    }
    system("pause");
    main();
}
void home()
{
    cout << "*****************************************************" << endl;
    cout << "                        Welcome                       " << endl;
    cout << "*****************************************************" << endl;
    cout << "1.Search Users" << endl;
    cout << "2.View Users Registered In This App " << endl;
    cout << "3.Post your thoughts " << endl;
    cout << "4.See All the post of Person you are searching from beginning" << endl;
    cout << "5.See Latest post of the person you are searching " << endl;
    cout << "6.View all POSTS " <<endl;
    cout << "7.Logout"<<endl;
    cout << "*****************************************************" << endl;
    int choose;
    cout<<"YOUR CHOICE: ";
    cin >> choose;
    switch (choose)
    {
    case 1:
        searchname();
        break;
    case 2:
        see();
        break;
    case 3:
        message();
        break;
    case 4:
        all();
        break;
    case 5:
        seemsg();
        break;
    case 6:
        purpose();
        break;    
    case 7:
        logout();
        break;    
    }  
}

void searchname()
{
    system("cls");
    ifstream one("first.txt");
    string name;
    string email;
    string password;
    string msg;
    string fname;
    system("cls");
     cout << "*****************************************************" << endl;
    cout << "                        SEARCH                         " << endl;
    cout << "*****************************************************" << endl;
    cout << "Enter the name of person " << endl;
    cin >> fname;
    while (one >> name >> email >> password >> msg)
    {
        if (fname == name)
        {
            system("cls");
            cout << "*****************************************************" << endl;
            cout << "                        USER FOUND                    " << endl;
            cout << "*****************************************************" << endl;
            cout << "Name" << endl;
            cout << "-----------" << endl;
            cout << name << endl;
            one.close();

        }
        if (fname != name)
        {
            system("cls");
            cout << "sorry no user is found" << endl;
        }
    }
    system("pause");
    system("cls");
    home();
}
void message()
{
    system("cls");
    ifstream one("first.txt");
    string name;
    string email;
    string password;
    string msg;
    string newmsg;
    string fname;
    string fpassword;
    system("cls");
     cout << "*****************************************************" << endl;
    cout << "                        POSTS                         " << endl;
    cout << "*****************************************************" << endl;
    cout<<"For security purpose enter your name and password"<<endl;
    cout << "Enter your Name" << endl;
    cin >> fname;
    cout<<"Enter your password :";
    cin>>fpassword;
    while (one >> name >> email >> password >> msg)
    {
        if (fname == name && fpassword==password)
        {
            system("cls");
            cout << "*****************************************************" << endl;
            cout << "                    POST YOUR THOUGHTS               " << endl;
            cout << "*****************************************************" << endl;
            cout << "NAME" << endl;
            cout << "-----" << endl;
            cout << name << endl;
            cout << "-----" << endl;
            cout << "Write your post WITHOUT SPACE(YOU CAN USE _ instead of space): "<<endl;
            cin>>newmsg;
            msg.replace(5,1,newmsg); 
            ofstream two("second.txt",ios::app);
            two << name << " " << email << " " << password << " " << msg <<endl;
            two.close();
            
 
        }

    }
    system("pause");
    system("cls");
    home();
}
void seemsg()
{
    system("cls");

    ifstream two("second.txt");
    string name, email, password;
    string msg;

    string fname;
    system("cls");
     cout << "*****************************************************" << endl;
    cout << "                        VIEW POSTS                   " << endl;
    cout << "*****************************************************" << endl;
    cout << "See  the post of (Friend Name).......  " << endl;
    cin >> fname;
    while (two >> name >> email >> password >> msg)
    {
        if (fname == name)
        {
            system("cls");
            cout << name << " " << msg << endl;
            
            
            
           
        }

    }
    system("pause");
    system("cls");
    home();
 
}
void all()
{
    system("cls");

    ifstream two("second.txt");
    string name, email, password;
    string msg;

    string fname;
    system("cls");
    cout << "*****************************************************" << endl;
    cout << "                        VIEW ALL POST                " << endl;
    cout << "*****************************************************" << endl;
    cout << "See all the post of (Friend Name)....... " << endl;
    cin >> fname;
    while (two >> name >> email >> password >> msg)
    {
        if (fname == name)
        {
            system("cls");
            cout << name << " " << msg << endl;
            
            system("pause");
            
           
        }

    }
    
    system("cls");
    home();
}
void logout()
{
    system("cls");
    cout<<"LOGGING OUT .........Please do visit again"<<endl;
    system("pause");
    main();
}
void see()
{
    system("cls");
    system("cls");
    ifstream two("first.txt");
    string name, email, password;
    string msg;

    
    system("cls");
    cout << "*****************************************************" << endl;
    cout << "            VIEW ALL USERS IN THIS DATABASE           " << endl;
    cout << "*****************************************************" << endl;
    cout<<"Name of Users on this are..... "<<endl;

    while (two >> name >> email >> password >> msg)
    {
        
        cout<<name<<endl;
        
    }
    system("pause");
    system("cls");
    home();
  
}
void purpose()
{
    system("cls");
    system("cls");
    ifstream two("second.txt");
    string name, email, password;
    string msg;

    
    system("cls");
    cout << "*****************************************************" << endl;
    cout << "            VIEW ALL POST OF YOUR FRIENDS           " << endl;
    cout << "*****************************************************" << endl;
    cout<<"Posts are..... "<<endl;
    cout<<"Name"<<" "<<"Post"<<endl;
    cout<<"-------------------"<<endl;
    while (two >> name >> email >> password >> msg)
    {
        cout<<name<<" "<<msg<<endl;
    }
    system("pause");
    system("cls");
    home();
}