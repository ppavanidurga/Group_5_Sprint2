#include<iostream>
#include "Users.h"
#include "Logger.h"
#include<fstream>
#include<unistd.h>

using namespace std;


Users::Users()
{
	ifstream infile;
	infile.open("login.txt");
	int userNo=0;
	//cout<<"constructor called"<<endl;
	while(!infile.eof())
	{
	    User usr;
	    infile >>usr.UserName;
	    infile >>usr.Password;
	    int isadminflag=0;
	    infile>>isadminflag;
	    usr.IsAdmin= isadminflag>0 ? true:false;
	    users[userNo]=usr;
	    userNo++;
	    // cout<<usr.UserName<<endl;
	    // cout<<usr.Password<<endl;
	}
	infile.close();
	UsersCount=userNo;


}

bool Users::Login(string username,string password)
{
	bool isLogin=false;
	int userNo=0;
	for(userNo=0;userNo<UsersCount;userNo++)
	{
		if(users[userNo].UserName==username && users[userNo].Password == password)
		{
		 isLogin=true;
		 UserName=users[userNo].UserName;
		 IsAdmin= users[userNo].IsAdmin;
		 break;
		}

	}
	if(userNo==UsersCount)
		return false;
	return true;
}
void Users::SignUp()
{
	string username,password,address;
	string phonenumber;
        cout<<"<---------------Choose username-------------->"<<endl;
        cin>>username;
        cout<<"<----------------Choose password--------------->"<<endl;
        cin>>password;
	cout<<"<-----------------------Enter address-------------->"<<endl;
	cin>>address;
	cout<<"<--------------Enter phonenumber-------------->"<<endl;
	cin>>phonenumber;
	ofstream outfile;
        outfile.open("login.txt",ios::app);
	outfile<<"\n";
	outfile<<username;
	outfile<<"\t";
	outfile<<password;
	outfile<<"\t";
	outfile<<"0";
        outfile.close();
	User usr;
        usr.UserName=username;
        usr.Password=password;
	usr.IsAdmin=false;
	users[UsersCount]=usr;
        UsersCount++;
	notice("****Sign Up successful****");
}

void Users::LoginWithRetrys()
{
	int retry=ones;
        LoginSuccess=false;
        while(retry<=thrice){
        string username,password;
        cout<<"\n<---------------Please enter your login details----------------->"<<endl;
        cout<<"<-----Enter Username------>"<<endl;
        cin>>username;
        cout<<"<-----------Enter password----->"<<endl;
        cin>>password;
        if(Login(username,password))
        {
                LoginSuccess=true;
                break;
        }
        warning("<-----------WARNING!!! Invalid password----->\n<-------------Please re-enter the password------->");
        retry++;
        if(retry==four)
        {
                error("<----------OOPS!! Maximum retry limit reached--------Wait for 30 sec to retry----->");
                sleep(sec);
                retry=ones;
        }
        }
        if(LoginSuccess)
        {
                if(IsAdmin)
         notice("<---------Admin login successful with Username-------->");
                else
          notice("<----------Login successful with Username-------->\n");

        }

}

