#include <iostream>

#include "cashRegister.h"

#include "dispenserType.h"

using namespace std;

void showSelection();
void sellProduct(dispenserType& product, cashRegister& pCounter);

int main()
{
	cashRegister counter;						//Step 1
	dispenserType candy(100,50); 				//Step 2
	dispenserType chips(100,65);				//Step 2
	dispenserType gum(75,45);					//Step 2
	dispenserType cookies(100,85);				//Step 2

	int choice;  								//Step 3

	showSelection();							//Step 4
	cin>>choice;								//Step 5

	while(choice != 9)							//Step 6
	{
		switch(choice)							//Step 6a
		{
		case 1: sellProduct(candy, counter);
				break;
	    case 2: sellProduct(chips, counter);
				break;
		case 3: sellProduct(gum, counter);
				break;
		case 4: sellProduct(cookies, counter);
				break;
		default: cout<<"Bad Selection"<<endl;
		}//end switch

		showSelection();						//Step 6b
		cin>>choice;							//Step 6c
	}//end while

	return 0;
}//end main


void showSelection()
{
	cout<<"*** Welcome to Shelly's Candy Shop ***"<<endl;
	cout<<"To select an item, enter "<<endl;
	cout<<"1 for Candy"<<endl;
	cout<<"2 for Chips"<<endl;
	cout<<"3 for Gum"<<endl;
	cout<<"4 for Cookies"<<endl;
	cout<<"9 to exit"<<endl;
}//end showSelection


void sellProduct(dispenserType& product, cashRegister& pCounter)
{
	int amountEntered;  //variable to hold the amount entered
	int amountLeft; //variable to hold the extra amount needed
	bool done = false;
	if(product.count() > 0)  							//Step a
	{
		amountEntered = 0;
		amountLeft = product.productCost();
        cout << "Please enter " << product.productCost()
              << " to receive your item" << endl;
		while(!done)
		{
         cin >> amountEntered; 
		 amountLeft -= amountEntered;

         

			if(amountLeft <= 0)				//Step a.iv
			{
				pCounter.acceptAmount(amountEntered);				//Step a.iv.1
				product.makeSale();							//Step a.iv.2
				cout<<"Collect your item at the bottom"
					<<" and enjoy."<<endl; 					//Step a.iv.3
				done = true;
			}
			else
				cout <<"Please enter " << amountLeft << " more cents. " << endl;
		

		}

		cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
			<<endl<<endl;
	}
	else
		cout<<"Sorry this item is sold out."<<endl;		//Step b
}//end sellProduct


