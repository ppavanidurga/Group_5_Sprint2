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
	cout<<"Enter Menu Item Number"<<endl;
	cin>>index;
	index--;
	if(index>=ItemsCount)
	
	{
		error("Invalid Menu Item Number");
		return;
	}
	CartItem cartItem;
	cartItem.Name=items[index].Name;
	cartItem.Price=items[index].Price;
	cout<<"Enter Quantity of Your Item :"<<cartItem.Name<<endl;
	cin>>cartItem.Qty;
	cartItems[cartItemsCount]=cartItem;
	cartItemsCount++; 
	notice("Item Ordered Successfully");

}
void Menu::DeleteItemToCart()
{
        int index;
        cout<<"Enter Your Cart Item Number"<<endl;
        cin>>index;
        index--;
        if(index>=cartItemsCount)
        {
                error("Invalid Cart Item Number");
                return;
        }
        for(int cartitemindex=index;cartitemindex<cartItemsCount-1;cartitemindex++)
		cartItems[cartitemindex]=cartItems[cartitemindex+1];
        cartItemsCount--;
        notice("Item removed Successfully");

}

void Menu::UserTransistion()
{
	int outoption=0;
        while(true)
        {
        cout<<"Menu Items"<<endl;
        int menuitemindex=0;
        while(menuitemindex<ItemsCount)
        {
                cout<<menuitemindex+1<<". "<<items[menuitemindex].Name<<"\t"<<items[menuitemindex].Price<<endl;
                menuitemindex++;
        }

	cout<<"Your ordered Items"<<endl;
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
		cout<<" Total bill :"<<sum<<endl;
	}

        int option;
	cout<<"\n1. Search Item\n2. Order Item\n3. Delete Item from Cart\n4. Pay Bill\n5. Cancel\n"<<"100.Customer Support\n"<<endl;
        while(cout << "Enter your choice: " && !(cin>>option)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		error("Enter Valid Option\n");
		//cout << "Enter Valid Input" << endl;
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
		case 100:
			Customer customer;
			customer.customerSupport();
			break;
                default:
			error("Enter Valid Option\n");
                        //cout<<"Enter Valid Option"<<endl;
                        break;
        }
	
	if(outoption==3 || outoption==4)
		break;
        
	}

	if(outoption==3)
	{
		while(true){
		cout<<"Please select payment option"<<endl;
		cout<<"\n1. GPay 2. PhonePe 3. Cash On Delivery 4. Others (Credit /Debit card)\n"<<endl;
		int pmethod;
		cin>>pmethod;
		if(pmethod>0 && pmethod<=4)
		{
			notice("Transaction successful");
			break;
		}
		else
			error("Invalid Option try again");
		
		}


	}

	notice("Thank You for choosing us");


}


void Menu::AddMenu()
{
	MenuItem menuItem;
	cout<<"Add Menu Item"<<endl;
	cout<<"Enter new Item Name"<<endl;
	cin>>menuItem.Name;
	cout<<"Enter Price"<<endl;
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
	cout<<"New Item Added to Menu Successfully"<<endl;
	
}

void Menu::DeleteMenu()
{
	int index;
	cout<<"Enter Menu Item Number to Delete"<<endl;
	cin>>index;
	index--;
	if(index>=ItemsCount)
	{
		cout<<"Invalid Menu Item Number"<<endl;
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
        cout<<"Enter Menu Item Number to Update"<<endl;
        cin>>index;
        index--;
        if(index>=ItemsCount)
        {
                cout<<"Invalid Menu Item Number"<<endl;
                return;
        }
        int menuitemindex=0;
        
	MenuItem item;
	cout<<"Enter Menu Item Name"<<endl;
	cin>>item.Name;
	cout<<"Enter Price"<<endl;
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
	cout<<"Menu Items"<<endl;
	int menuitemindex=0;
	while(menuitemindex<ItemsCount)
	{
		cout<<menuitemindex+1<<". "<<items[menuitemindex].Name<<"\t"<<items[menuitemindex].Price<<endl;
		menuitemindex++;
	}
	
	int option;
	cout<<"\n1. Add Item to menu\n2. Update Menu Item\n3. Delete Menu Item\n4. Exit\n"<<endl;
	cin>>option;
	switch(option)
	{
		case 1:
			AddMenu();
			break;
		case 2:
			UpdateMenu();
			break;
		case 3:
			DeleteMenu();
			break;
		case 4:
			cout<<"Thank you"<<endl;
			break;
		default:
			cout<<"Enter Valid Option"<<endl;
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
	    cout<<"Enter your favorite dish: ";
    //cin.getline(searchitem,100);
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
    cout<<"VOILA!" << endl << searchitem << " is present at line  number "<<ans+1<<endl;
    cout << "Enter " << ans+1 << " to add " << searchitem << " to your cart in order menu" << endl;
    }
    else {
    cout<<"The Menu Item "<<searchitem<<" is not found"<<endl;
    }
    return 0;

}

