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
	int itemindex=ZERO;
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
	info("\nEnter Menu Item Number: ");
	//cin>>index;
	while(!(cin>>index)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("\nEnter Valid Option\n");
		info("\nEnter Menu Item Number: ");
                }

	index--;
	if(index>=ItemsCount)
	
	{
		error("Invalid Menu Item Number\n");
		return;
	}
	CartItem cartItem;
	cartItem.Name=items[index].Name;
	cartItem.Price=items[index].Price;
	info("\nEnter Quantity of Your Item: ");
	//cout<<cartItem.Name<<endl;
	while(!(cin>>cartItem.Qty)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("\nEnter Valid Option\n");
		info("\nEnter Quantity of Your Item: ");
                }

	//cin>>cartItem.Qty;
	cartItems[cartItemsCount]=cartItem;
	cartItemsCount++; 
	notice("\nItem Ordered Successfully\n");

}
void Menu::DeleteItemToCart()
{
        int index;
        info("\nEnter Your Cart Item Number: ");
        //cin>>index;
	while(!(cin>>index)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("\nEnter Valid Option\n");
        	info("\nEnter Your Cart Item Number: ");
                }

        index--;
        if(index>=cartItemsCount)
        {
                error("\nInvalid Cart Item Number\n");
                return;
        }
        for(int cartitemindex=index;cartitemindex<cartItemsCount-ONE;cartitemindex++)
		cartItems[cartitemindex]=cartItems[cartitemindex+ONE];
        cartItemsCount--;
        notice("\nItem removed from cart\n");

}

void Menu::UserTransistion()
{
	int outoption=ZERO;
        while(true)
        {
        notice("\nMENU ITEMS\n");
        int menuitemindex=ZERO;
        while(menuitemindex<ItemsCount)
        {
                cout<<menuitemindex+ONE<<". "<<items[menuitemindex].Name<<"\t"<<items[menuitemindex].Price<<endl;
                menuitemindex++;
        }

	notice("\nYour ordered Items\n");
	int cartitemindex=ZERO;
	int sum=ZERO;
	while(cartitemindex<cartItemsCount)
	{
		int total = cartItems[cartitemindex].Qty*cartItems[cartitemindex].Price;
		cout<<cartitemindex+ONE<<". "<<cartItems[cartitemindex].Name<<"\t"<<cartItems[cartitemindex].Qty<<"* "<<cartItems[cartitemindex].Price<<"\t"<< total  <<endl;
                cartitemindex++;
		sum+=total;
	}
	if(sum>ZERO)
	{
		info("\nTotal bill : ");
		cout<<sum<<endl;
	}
        Menu:
        int option;
	info("\n1. Search Item\n2. Order Item\n3. Delete Item from Cart\n4. Pay Bill\n5. Cancel\n");
        while(cout << "\nEnter your choice: " && !(cin>>option)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error("\nEnter Valid Option\n");
		
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
			outoption=THREE;
                        break;
		case 5:
			outoption=FOUR;
			break;
                default:
			error("\nEnter Valid Option\n");
                        
                        break;
        }
	
	if(outoption==THREE || outoption==FOUR)
		break;
        
	}

	if(outoption==THREE)
	{
		while(true){
		info("\nPlease select payment option:");
		info("\n1. GPay 2. PhonePe 3. Cash On Delivery 4. Others (Credit /Debit card) 5. Customer Support\n");
		int pmethod;
		//cin>>pmethod;
		while(cout << "\nEnter your choice: " && !(cin>>pmethod)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("\nEnter Valid Option\n");
		}
		if(pmethod == FIVE) {
			Customer customer;
			customer.customerSupport();
			notice("Thank You Visit again\n");
			exit(1);
		}

		if(pmethod>ZERO && pmethod<=FOUR)
		{
			notice("\nTransaction successful\n");
			break;
		}
		else
			error("\nInvalid Option try again\n");
		
		}


	}

}


void Menu::AddMenu()
{
	MenuItem menuItem;
	info("\nAdd Menu Item\n");
	info("Enter new Item Name: ");
	cin>>menuItem.Name;
	info("\nEnter Price: ");
	//cin>>menuItem.Price;
	while(!(cin>>menuItem.Price)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("\nEnter Valid Option\n");
		info("\nEnter Price: ");
                }

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
	notice("\nNew Item Added to Menu Successfully\n");
	
}

void Menu::DeleteMenu()
{
	int index;
	info("\nEnter Menu Item Number to Delete: ");
	//cin>>index;
	while(!(cin>>index)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("\nEnter Valid Option\n");
		info("\nEnter Menu Item Number to Delete: ");
                }

	index--;
	if(index>=ItemsCount)
	{
		error("\nInvalid Menu Item Number\n");
		return;
	}
	int menuitemindex=ZERO;
	for(menuitemindex=index;menuitemindex<ItemsCount-ONE;menuitemindex++)
	{
	   items[menuitemindex]=items[menuitemindex+ONE];
	}
	ofstream outfile;
        outfile.open("menu.txt");
        menuitemindex=ZERO;
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
        info("\nEnter Menu Item Number to Update : ");
        while(!(cin>>index)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("\nEnter Valid Option\n");
        	info("\nEnter Menu Item Number to Update : ");
                }

	//cin>>index;
        index--;
        if(index>=ItemsCount)
        {
                error("\nInvalid Menu Item Number\n");
                return;
        }
        int menuitemindex=ZERO;
        
	MenuItem item;
	info("\nEnter Menu Item Name: ");
	cin>>item.Name;
	info("\nEnter Price: ");
	//cin>>item.Price;
	while(!(cin>>item.Price)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("\nEnter Valid Option\n");
		info("\nEnter Price: ");
                }

	items[index]=item;

        ofstream outfile;
        outfile.open("menu.txt");
        menuitemindex=ZERO;
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
	notice("\nMENU ITEMS\n");
	int menuitemindex=ZERO;
	while(menuitemindex<ItemsCount)
	{
		cout<<menuitemindex+ONE<<". "<<items[menuitemindex].Name<<"\t"<<items[menuitemindex].Price<<endl;
		menuitemindex++;
	}
	
	int option;
	info("\n1. Search Item in menu\n2. Add Item to menu\n3. Update Menu Item\n4. Delete Menu Item\n5. Exit\n");
	//cin>>option;
	 while(cout << "\nEnter your choice: " && !(cin>>option)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("\nEnter Valid Option\n");

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
			notice("\nThank you. Have a good day!\n");
			break;
		default:
			error("\nEnter Valid Option\n");
			break;
	}
	if(option==FIVE)
		break;
	}

}
int Menu::SearchInMenu()
{
	int ans=-ONE;
     string searchitem;
	    info("\nEnter your favorite dish: ");
    cin >> searchitem;
    /*To make string in lower case*/
    transform(searchitem.begin(), searchitem.end(), searchitem.begin(), ::tolower);

    /*To capitalize first letter*/
    searchitem[ZERO] = toupper(searchitem[ZERO]);
    for(int i=ZERO;i<ItemsCount;i++)
    {
        if(items[i].Name==searchitem)
        {
            ans=i;
            break;
        }
    }
    if(ans!=-ONE){
    info("VOILA!\n");
    cout<< searchitem ;
    info(" is present at line  number ");
    cout<<ans+ONE<<endl;
    info("Enter "); cout << ans+ONE; info(" to add "); cout << searchitem; info(" to your cart in order menu\n");
    }
    else {
    info("The Menu Item "); cout<<searchitem; info(" is not found\n");
    }
    return 0;

}
void Menu::FeedbackForManagement(){

        while(true)
        {
		cout<<endl;
        info("\nPLEASE PROVIDE YOUR FEEDBACK");

        int fchoice;
        notice("\n1. POOR\n2. AVERAGE\n3. GOOD\n4. EXCELLENT\n5. Exit\n");
        while(cout << "\nEnter your choice: " && !(cin>>fchoice)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                error("\nEnter Valid Option\n");
        }
	//cin>>fchoice;
        switch(fchoice)
        {
                case 1:
                         info("THANK YOU FOR THE FEEDBACK, WE WILL TRY TO IMPROVE OUR SERVICE\n");

                        break;
                case 2:
                        info("THANK YOU FOR THE FEEDBACK, WE WILL TRY TO IMPROVE OUR SERVICE\n");

                        break;
                case 3:
                       info("THANK YOU. WE ARE GLAD YOU ENJOYED OUR SERVICE!\n");
                        break;
                case 4:
                        info("THANK YOU. WE ARE GLAD YOU ENJOYED OUR SERVICE!\n");
                        break;
                case 5:
                        info("THANK YOU.\n");
                        break;
                default:
                        error("Enter Valid Option\n");
                        break;
        }
        if(fchoice>ZERO && fchoice<=FIVE)
                break;
        }

        notice("GOODBYE! SEE YOU AGAIN SOON!\n");

}

