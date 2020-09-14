/* Final Project -- Main */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;
	
	//vector for ITEM ID
	vector<int> v_itemID;

	//vector for ITEM NAME
	vector<string> v_itemName;

	//vector for number of items ordered;
	vector<int> v_itemsOrdered;

	//vector for number of items current;
	vector<int> v_itemsCurrent;

	//vector for number of item sold;	
	vector<int> v_itemsSold;

	//vector for manufacturers price;
	vector<double> v_mfgPrice;

	//vector for Store price of item;
	vector<double> v_storePrice;
	
	
//constructor to load data
void readFile(ifstream& inData, int item_ID, string item_Name, int p_Ordered, 
              double manuf_Price, double selling_Price, int& rows);
	
//constructor add item;
void addItem(int itemID, string itemName, int itemsOrdered, int itemsCurrent, double mfgPrice, double storePrice);

//constructor seaches for an item
int itemSearch(vector<int> v_itemID, int item_num);

//constructor for sorting list
void itemSort(string itemName, int item_Num, int p_Order, double man_Price,
     double sell_Price, int rows);

//consturctor remove item;

//Constructor  to output report;
void printReport();

ifstream inData;

int itemID;
string itemName;
int itemsOrdered;
int itemsSold;
double itemsCurrent;
double mfgPrice;
double storePrice;
int item; //index of item returned by search
int size;

int main()
{
int rows;

//opens the opens data stream and inputs file -- placed in the same directory as program
inData.open("sampleInput.txt");
    
//If the input file does not exist print out message and end program
	if (!inData)
	{
		cout << endl;
		cout << endl;
		cout << "ERROR!!!!!!!!" << endl;
		cout << "Input file cannot be opened or does not exist." << endl;
		cout << "Data file 'data_input.txt' must be in the same directory as program." << endl;
		cout << "Program will now end!!" << endl;
		cout << endl;
		cout << endl;
		return 1;
	}

//Load vector function.
//CANT get this to work...where do you get rows?
readFile(inData, itemID, itemName, itemsOrdered, mfgPrice, storePrice, rows); 

int choice = 0; //choise of selection of what to do

	while(!(choice < 0))
	{
		//Main screen asking for selection of what the user wants to do
		cout << endl;
		cout << endl;		
		cout << "Welcome to Friendly's Hardware Store" << endl;
		cout << endl;
		cout << endl;
		cout << "What do you want to do? " << endl;
		cout << "1) Add an Item" << endl;
		cout << "2) Remove an Item" << endl;
		cout << "3) Print out Report" << endl;
		cout << "4) Search for an Item" << endl;
		cout << "Enter Selection (-1) to exit: " << endl;
		cin >> choice;
	
		//Choice 1 -- user enters info and item info is added to end of each of the vectors
		switch (choice)
		{
		case 1:
			cout << "Enter Item ID: ";
			cin >> itemID;
			cout << endl;
	
			cout << "Enter Item Name: ";
			cin >> itemName;
			cout << endl;
	
			cout << "Enter The Number Of Items Ordered: ";
			cin >> itemsOrdered;
			cout << endl;

			cout << "Enter The Number Of Items Sold: ";
			cin >> itemsSold;
			cout << endl;

			cout << "Enter The Manufacturer Price: ";
			cin >> mfgPrice;
			cout << endl;

			cout << "Enter The Store Price: ";
			cin >> storePrice;
			cout << endl;
        
			//additem simply adds item to end of vectors
			addItem(itemID, itemName, itemsOrdered, itemsSold, mfgPrice, storePrice);
			break;
		
		//Choice 2 -- Prompts user as to which item he would like to remove
		case 2:
			cout << "Enter the Item ID of the item you wish to remove: ";
			cin >> itemID;
		
			//function to remove item PLACE here
			break;		
		
		case 3:
			printReport();
			break;

		case 4:
		//Searches for Item returns info if found
			itemSearch(v_itemID, itemID);
			break;

		default:
			cout << "Thank you for using this program" << endl;
		}
	}
inData.close();	    
return 0;
}

//Searches for Item via Item ID and returns index value if found -1 if not found
int itemSearch(vector<int> v_itemID, int itemID)
{
	for(unsigned int i = 0; i < v_itemID.size(); i++)
	{
		if(itemID == v_itemID.at(i))
		     return i;
	}
	return -1;
}

//Add item info to end of each vector
void addItem(int itemID, string itemName, int itemsOrdered, int itemsCurrent, double mfgPrice, double storePrice)
{
		v_itemID.push_back(itemID);
	    v_itemName.push_back(itemName);
		v_itemsOrdered.push_back(itemsOrdered);
	    v_itemsCurrent.push_back(itemsCurrent);
		v_itemsSold.push_back(itemsSold);
		v_mfgPrice.push_back(mfgPrice);
		v_storePrice.push_back(storePrice);
}	

void printReport()
{
	
	itemSort(v_itemName, v_itemID, v_itemsOrdered, v_mfgPrice, v_storePrice, v_itemID.size());
	cout << fixed << showpoint << setprecision(2);

	cout << setw(50) << "Friendly Hardware Store" << endl;
	cout << endl;
	cout << setw(6) << "itemID" << setw(12) << "itemName" << setw(12) << "pOrdered"
         << setw(12) << "pInStore" << setw(8) << "pSold" << setw(14) <<"manufPrice" 
         << setw(16) << "sellingPrice" << endl;
   
	double totalInventory = 0;
	for(unsigned int i = 0; i < v_itemID.size(); i++)
	{
		cout << setw(6) << v_itemID.at(i) << setw(12)<<  v_itemName.at(i)
             << setw(12) << v_itemsOrdered.at(i) << setw(12) << v_itemsCurrent.at(i)   
		     << setw(8) << v_itemsSold.at(i) << setw(14) << v_mfgPrice.at(i) 
		     << setw(16) << v_storePrice.at(i) << endl;

        totalInventory = totalInventory + (v_storePrice.at(i) * v_itemsCurrent.at(i));
		

	}
    cout << "TOTAL INVENTORY= $" << totalInventory << endl;
	cout << "Total number of items in the store: " << v_itemID.size() << endl;
}

void itemSort(vector<string> itemName, vector<int> item_Num, vector<int> p_Order, vector<double> man_Price,
     vector<double> sell_Price, int rows)
{
     
	 int firstOutOfOrder, location;
     int temp2, temp3; 
	 double temp4, temp5;
     string temp1;

     for(firstOutOfOrder = 1; firstOutOfOrder < rows; firstOutOfOrder++)
        if(itemName[firstOutOfOrder] < itemName[firstOutOfOrder])
        {
            temp1 = itemName[firstOutOfOrder];
            temp2 = item_Num[firstOutOfOrder];
            temp3 = p_Order[firstOutOfOrder];
            temp4 = man_Price[firstOutOfOrder];
            temp5 = sell_Price[firstOutOfOrder];
            location = firstOutOfOrder;
            
            do
            {
				itemName[location] = itemName[location - 1];
                item_Num[location] = item_Num[location - 1];
                p_Order[location] = p_Order[location - 1];
                man_Price[location] = man_Price[location - 1];
                sell_Price[location] = sell_Price[location - 1];
                location--;
            }
            while(location > 0 && itemName[location - 1] > temp1);
            
            itemName[location] = temp1;
            item_Num[location] = temp2;
            p_Order[location] = temp3;
            man_Price[location] = temp4;
            sell_Price[location] = temp5;
        }
}           

//Here is the vector loading function.
void readFile(ifstream& inData, vector<int> item_ID, vector<string> item_Name, vector<int> p_Ordered, 
              vector<double> manuf_Price, vector<double> selling_Price, int& rows)
     {
         int position = 0;
         
         while(inData)
         {
                  inData.get(item_Name);
                  item_ID.push_back(inData);
                  getline(inData, item_Name.push_back(inData);
                  inData >> p_Ordered[position] >> manuf_Price[position]
                         >> selling_Price[position];
                         
                         position++;
         }
         rows = item_ID.size();
     }

	

