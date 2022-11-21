#include<iostream>
#include<stdio.h>
#include "server_client.h"
#include<unistd.h>
#include "Users.h"
#include "Menu.h"
#include "location.h"
#include "Logger.h"
int main()
{
   
	Users users;
	int loginOption=1;
        //cout<< "\t\t\t***********************************************\n";
	//cout<< "\t\t\t|           Welcome to                        |\n";
	//cout<< "\t\t\t|    Online Food Ordering System              |\n";
	//cout<< "\t\t\t***********************************************\n";
	notice("\t\t\tWELCOME TO ONLINE FOOD ORDERING SYSTEM");
	cout<<"\n1. Login" << endl << "2. Sign Up "<<endl;
	notice("Select option: \n");
	cin>>loginOption;
	switch(loginOption)
	{
		case 1:
			users.LoginWithRetrys();
			break;
		case 2:
			users.SignUp();
			users.LoginWithRetrys();
			break;
		default:
			error("Invalid Option");
			break;


	}
	if(users.LoginSuccess)
	{
		Location l;
		l.Location_transition();
		if(users.IsAdmin)
		{
			
			Menu m;
			m.AdminTransistion();
		
		}
		else
		{
			
		    Menu m;
		    m.UserTransistion();
		}
	}
	
	return 0;
	

}
