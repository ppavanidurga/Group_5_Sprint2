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
	int userNo=ZERO;
	while(!infile.eof())
	{
	    User usr;
	    infile >>usr.UserName;
	    infile >>usr.Password;
	    int isadminflag = ZERO;
	    infile>>isadminflag;
	    usr.IsAdmin= isadminflag > ZERO ? true:false;
	    users[userNo]=usr;
	    userNo++;
	}
	infile.close();
	UsersCount=userNo;


}

bool Users::Login(string username,string password)
{
	bool isLogin=false;
	int userNo=ZERO;
	for(userNo=ZERO;userNo<UsersCount;userNo++)
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
        info("\nChoose username :");
        cin>>username;
        info("\nChoose password :");
        cin>>password;
        info("\nEnter Address :");
        cin>>address;

	double phoneNumber;
	phone_num:
	info("\nEnter Phone number No : ");
	while ( !(cin >> phoneNumber) )
	{
    		fflush(stdin);
    		error("\nInvalid Phone number\n");
    		info("\nEnter Phone number again : ");
	}
	if (phoneNumber < MINPH || phoneNumber > MAXPH)
	{
   		error("\nPlease enter valid phone number!\n");
   		goto phone_num;
	}
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
	notice("\n****Sign Up successful****\n");
}

void Users::LoginWithRetrys()
{
	int retry = ONE;
        LoginSuccess=false;
        while(retry <= THREE){
        string username,password;
        notice("\nPlease enter your login details\n");
        info("\nEnter Username: ");
        cin>>username;
        info("\nEnter password : ");
        cin>>password;
        if(Login(username,password))
        {
                LoginSuccess=true;
                break;
        }
        warning("\nWARNING!!! Invalid password, Please re-enter the password\n");
        retry++;
        if(retry==FOUR)
        {
                error("\nOOPS!! Maximum retry limit reached, Wait for 30 sec to retry\n");
                sleep(SEC);
                retry=ONE;
        }
        }
        if(LoginSuccess)
        {
                if(IsAdmin)
         notice("Admin login successful with Username\n");
                else
          notice("Login successful with Username\n");

        }

}

