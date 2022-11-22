#include <bits/stdc++.h>
#include <string>
#include<iostream>
#include <ctype.h>
#include "Menu.h"
#include "server_client.h"
#include<fstream>
#include<unistd.h>
#include "Logger.h"

using namespace std;


Menu::Menu()
{
	ifstream infile;
	infile.open("menu.txt");
	int itemindex=0;
	while(!infile.eof())
	{
	    MenuItem menuItem;
	    infile >>menuItem.Name;
	    infile >>menuItem.Price;
	    items[itemindex]=menuItem;
	    itemindex++;
	}
	infile.close();
	ItemsCount=itemindex;


}
void Menu::AddItemToCart()
{
	int index;
	info("Enter Menu Item Number\n");
	cin>>index;
	index--;
	if(index>=ItemsCount)
	
	{
		error("Invalid Menu Item Number\n");
		return;
	}
	CartItem cartItem;
	cartItem.Name=items[index].Name;
	cartItem.Price=items[index].Price;
	info("Enter Quantity of Your Item :");
	cout<<cartItem.Name<<endl;
	cin>>cartItem.Qty;
	cartItems[cartItemsCount]=cartItem;
	cartItemsCount++; 
	notice("Item Ordered Successfully\n");

}
void Menu::DeleteItemToCart()
{
        int index;
        info("Enter Your Cart Item Number : ");
        cin>>index;
        index--;
        if(index>=cartItemsCount)
        {
                error("Invalid Cart Item Number\n");
                return;
        }
        for(int cartitemindex=index;cartitemindex<cartItemsCount-1;cartitemindex++)
		cartItems[cartitemindex]=cartItems[cartitemindex+1];
        cartItemsCount--;
        notice("Item removed Successfully\n");

}

void Menu::UserTransistion()
{
	int outoption=0;
        while(true)
        {
        notice("\nMenu Items\n");
        int menuitemindex=0;
        while(menuitemindex<ItemsCount)
        {
                cout<<menuitemindex+1<<". "<<items[menuitemindex].Name<<"\t"<<items[menuitemindex].Price<<endl;
                menuitemindex++;
        }

	notice("Your ordered Items\n");
	int cartitemindex=0;
	int sum=0;
	while(cartitemindex<cartItemsCount)
	{
		int total = cartItems[cartitemindex].Qty*cartItems[cartitemindex].Price;
		cout<<cartitemindex+1<<". "<<cartItems[cartitemindex].Name<<"\t"<<cartItems[cartitemindex].Qty<<"* "<<cartItems[cartitemindex].Price<<"\t"<< total  <<endl;
                cartitemindex++;
		sum+=total;
	}
	if(sum>0)
	{
		info("Total bill : ");
		cout<<sum<<endl;
	}
        Menu:
        int option;
	info("\n1. Search Item\n2. Order Item\n3. Delete Item from Cart\n4. Pay Bill\n5. Cancel\n");
        while(cout << "Enter your choice: " && !(cin>>option)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error("Enter Valid Option\n");
		
	}
	switch(option)
        {
		case 1:
			SearchInMenu();
			break;
                case 2:
                        AddItemToCart();
                        break;
                case 3:
                        DeleteItemToCart();
                        break;
                case 4:
                        //DeleteMenu();
			outoption=3;
                        break;
		case 5:
			outoption=4;
			break;
                default:
			error("Enter Valid Option\n");
                        
                        break;
        }
	
	if(outoption==3 || outoption==4)
		break;
        
	}

	if(outoption==3)
	{
		while(true){
		info("Please select payment option\n");
		info("\n1. GPay 2. PhonePe 3. Cash On Delivery 4. Others (Credit /Debit card) 5. Customer Support\n");
		int pmethod;
		//cin>>pmethod;
		while(cout << "Enter your choice: " && !(cin>>pmethod)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("Enter Valid Option\n");
		}
		if(pmethod == 5) {
			Customer customer;
			customer.customerSupport();
			cout<<"Thanks Visit again"<<endl;
			exit(1);
		}

		if(pmethod>0 && pmethod<=4)
		{
			notice("Transaction successful");
			break;
		}
		else
			error("Invalid Option try again");
		
		}


	}

	//notice("Thank You for choosing us");


}


void Menu::AddMenu()
{
	MenuItem menuItem;
	info("Add Menu Item\n");
	info("Enter new Item Name\n");
	cin>>menuItem.Name;
	info("\nEnter Price");
	cin>>menuItem.Price;
	items[ItemsCount]=menuItem;
	ItemsCount++;
	ofstream outfile;
        outfile.open("menu.txt",ios::app);
        outfile<<"\n";
        outfile<<menuItem.Name;
        outfile<<"\t";
        outfile<<menuItem.Price;
        outfile<<"\t";
        outfile<<"0";
        outfile.close();
	notice("\nNew Item Added to Menu Successfully");
	
}

void Menu::DeleteMenu()
{
	int index;
	info("Enter Menu Item Number to Delete : ");
	cin>>index;
	index--;
	if(index>=ItemsCount)
	{
		error("Invalid Menu Item Number");
		return;
	}
	int menuitemindex=0;
	for(menuitemindex=index;menuitemindex<ItemsCount-1;menuitemindex++)
	{
	   items[menuitemindex]=items[menuitemindex+1];
	}
	ofstream outfile;
        outfile.open("menu.txt");
        menuitemindex=0;
	ItemsCount--;
        while(menuitemindex<ItemsCount)
        {
            outfile<<"\n";
            outfile <<items[menuitemindex].Name;
	    outfile<<"\t";
            outfile <<items[menuitemindex].Price;
	    menuitemindex++;
            
        }
        outfile.close();
        ItemsCount=menuitemindex;

}

void Menu::UpdateMenu()
{
        int index;
        info("Enter Menu Item Number to Update : ");
        cin>>index;
        index--;
        if(index>=ItemsCount)
        {
                error("Invalid Menu Item Number");
                return;
        }
        int menuitemindex=0;
        
	MenuItem item;
	info("Enter Menu Item Name: ");
	cin>>item.Name;
	info("\nEnter Price: ");
	cin>>item.Price;
	items[index]=item;

        ofstream outfile;
        outfile.open("menu.txt");
        menuitemindex=0;
        while(menuitemindex<ItemsCount)
        {
            outfile<<"\n";
            outfile<<items[menuitemindex].Name;
            outfile<<"\t";
            outfile<<items[menuitemindex].Price;
            menuitemindex++;

        }
        outfile.close();
        ItemsCount=menuitemindex;
}


void Menu::AdminTransistion()
{
	while(true)
	{
	info("Menu Items");
	int menuitemindex=0;
	while(menuitemindex<ItemsCount)
	{
		cout<<menuitemindex+1<<". "<<items[menuitemindex].Name<<"\t"<<items[menuitemindex].Price<<endl;
		menuitemindex++;
	}
	
	int option;
	info("\n1. Search Item in menu\n2. Add Item to menu\n3. Update Menu Item\n4. Delete Menu Item\n5. Exit\n");
	//cin>>option;
	 while(cout << "Enter your choice: " && !(cin>>option)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("Enter Valid Option\n");

        }

	switch(option)
	{
		case 1:
			SearchInMenu();
			break;
		case 2:
			AddMenu();
			break;
		case 3:
			UpdateMenu();
			break;
		case 4:
			DeleteMenu();
			break;
		case 5:
			notice("Thank you");
			break;
		default:
			error("Enter Valid Option");
			break;
	}
	if(option==4)
		break;
	}

}
int Menu::SearchInMenu()
{
	int ans=-1;
     string searchitem;
	    info("Enter your favorite dish: ");
    cin >> searchitem;
    /*To make string in lower case*/
    transform(searchitem.begin(), searchitem.end(), searchitem.begin(), ::tolower);

    /*To remove any white spaces*/	
    searchitem.erase(remove(searchitem.begin(),searchitem.end(),' '), searchitem.end());
    
    /*To capitalize first letter*/
    searchitem[0] = toupper(searchitem[0]);
    for(int i=0;i<ItemsCount;i++)
    {
        if(items[i].Name==searchitem)
        {
            ans=i;
            break;
        }
    }
    if(ans!=-1){
    info("VOILA!\n");
    cout<< searchitem ;
    info(" is present at line  number ");
    cout<<ans+1<<endl;
    cout << "Enter " << ans+1 << " to add " << searchitem << " to your cart in order menu" << endl;
    }
    else {
    cout<<"The Menu Item "<<searchitem<<" is not found"<<endl;
    }
    return 0;

}
void Menu::FeedbackForManagement(){

        while(true)
        {
		cout<<endl;
        info("\nGIVE A FEEDBACK");

        int fchoice;
        notice("\n1. POOR\n2. AVERAGE\n3. GOOD\n4. EXCELLENT\n5. Exit\n");
        cin>>fchoice;
        switch(fchoice)
        {
                case 1:
                         info("THANK YOU FOR THE FEEDBACK, WE WILL TRY TO IMPROVE OUR SERVICE\n");

                        break;
                case 2:
                        info("THANK YOU FOR THE FEEDBACK, WE WILL TRY TO IMPROVE OUR SERVICE\n");

                        break;
                case 3:
                       info("THANK YOU.... VISIT AGAIN \n");
                        break;
                case 4:
                        info("THANK YOU SO MUCH.. HOPE YOU ARE ENJOYING..... VISIT AGAIN \n");
                        break;
                case 5:
                        info("THANK YOU\n");
                        break;
                default:
                        error("Enter Valid Option\n");
                        break;
        }
        if(fchoice>0 && fchoice<=5)
                break;
        }

        notice("THANK YOU FOR CHOOSING US\n");

}

