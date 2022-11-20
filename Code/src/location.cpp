#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "location.h"
#include "server_client.h"
#include "Logger.h"
using namespace std;

/*Function to display available locations*/

void Location::display_location() {
    ifstream INFile("location.txt");
    string line;  
    
    while(! INFile.eof())
    {
        getline(INFile, line);
        cout << line << endl;
    }
    INFile.close();
}

/*function to verify entered location*/

bool Location::get_location(string user_location){
    ifstream INFile("location.txt");
    string to_find;
    bool exists = false;
    transform(user_location.begin(), user_location.end(), user_location.begin(), ::tolower);
    while (getline(INFile,to_find)) {
	    transform(to_find.begin(), to_find.end(), to_find.begin(), ::tolower);

	 if(to_find == "- "+user_location)
		{
        	    exists = true;
           	    break;
        	}
    	}
   
   	 if (exists) {
      		cout << "Displaying available Restaurants in " << user_location << endl; 
   	 }
    	else{
		error("Please enter Valid Location");
        	//cout << "Please enter valid Location" << endl;
    	}
 	return exists;
}

/*function to display the available Restaurants*/

void Location::restaurant_list(string appended_user_location) {
    ifstream INFile_hotel_list(appended_user_location);
    string hotel_list;
  
    if (!INFile_hotel_list){
        return display_location();
    }

    while(! INFile_hotel_list.eof())
    {
        getline(INFile_hotel_list, hotel_list);
        cout << hotel_list << endl;
    }

    INFile_hotel_list.close();
    
}

bool Location::get_restaurants(string appended_user_location) {
    
    ifstream INFile_hotel_list(appended_user_location);

    if (!INFile_hotel_list){
   	 return false;
    }
    else if(INFile_hotel_list){
        int restaurant_no;
        while(cout<< "Select your Hotel number: " && !(cin >> restaurant_no)){
		cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("Enter Valid Option\n");
	}

	int read_lines = 0;
	//int line_number= stoi(restaurant_no);
	string line;
	if (restaurant_no!=100)
	{
        
        //line_number = stoi(restaurant_no);
       // read_lines = 0;
       	//string line;
	
     
         /*else if(restaurant_no == 100)
	 {
		 Customer customer;
          	customer.customerSupport();
	 }*/

         while (getline(INFile_hotel_list, line)){
         	 read_lines++;

            	if(read_lines == restaurant_no)
            	{
                	cout << line << endl;
                	break;
            	}
        }
	} 
	  else if(restaurant_no == 100)
         {
                 Customer customer;
                customer.customerSupport();
         }
    
       
	 INFile_hotel_list.close();
         
	 if (read_lines < restaurant_no) {
            error("Invalid Entry");
            return false;
         }
    
    return true;
}
}

int Location::Location_transition()
{
	while(true) 
	{
	   cout << "\n---We are availble in the following Locations--- "<<endl;
	   display_location();
	   string user_location;
    
    	   cout << "Enter Your Location: ";
           cin >> user_location;
    
           transform(user_location.begin(), user_location.end(), user_location.begin(), ::tolower);
   
   	if (get_location(user_location)){
    		string appended_user_location;
    		appended_user_location=user_location.append("_hotels.txt");
    
    		restaurant_list(appended_user_location);	
    		while(!get_restaurants(appended_user_location));
    		break;
   		}
	}     
    return 0;
}

