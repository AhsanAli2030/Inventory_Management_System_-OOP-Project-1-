#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct inventory_item
{
	string item_name;
	int item_id;
	int qty;
	float price_per_item;

	inventory_item* nextptr;
};

inventory_item* fptr = NULL;

void AddingItem();
void Sellingitem();
void Removinginventoryitem();
void DISPLAYINGDATABASE();
void BUYINGITEM();

int main()
{
	int option, option1, option2, option3, option4;
	while (1)
	{
	MAINMENU:  // goto statement
		//  system("CLS");
		cout << "\n\n<<<__************** MAIN MENU **************__>>>\n";
		cout << "\n1.Add Inventory Item\n2.Sell Inventory Item\n3. Remove Inventory Item\n4.CHECK STOCKS\n5.Buy Inventory Item.\nChoose One Of The Options : ";
	TRYTRYAGAIN:
		cin >> option;
		switch (option)
		{
		case 1:
		addingagain:              // goto statement
			cout << "\n\n<<<__************** ADDING INVENTORY ITEM **************__>>>\n";

			AddingItem();             // Function
			cout << "\nPress 1 For Adding Additional Inventory item & 2 For mainMenu : ";
		INVALID:             // goto statement
			cin >> option1;
			switch (option1)
			{
			case 1: goto addingagain;
				break;
			case 2: goto MAINMENU;
				break;
			default:cout << "\nINVALID INPUT\nPlease Try Again : ";
				goto INVALID;
			}
			break;
		case 2:
		REselling:
			cout << "\n\n<<<__************** SELLING INVENTORY ITEM **************__>>>\n";
			Sellingitem();  // Function
			cout << "\nPress 1 For Re_Selling Inventory item & 2 For mainMenu : ";
		INVALID1:             // goto statement
			cin >> option2;
			switch (option2)
			{
			case 1: goto REselling;
				break;
			case 2: goto MAINMENU;
				break;
			default:cout << "\nINVALID INPUT\nPlease Try Again : ";
				goto INVALID1;
				break;
			}
			break;
		case 3:
		Removing_initem:
			cout << "\n\n<<<__************** Removing INVENTORY ITEM **************__>>>\n";
			Removinginventoryitem();  // Function
			cout << "\nPress 1 For Again Removing Inventory item & 2 For mainMenu : ";
		INVALID3:             // goto statement
			cin >> option3;
			switch (option3)
			{
			case 1: goto Removing_initem;
				break;
			case 2: goto MAINMENU;
				break;
			default:cout << "\nINVALID INPUT\nPlease Try Again : ";
				goto INVALID3;
			}
			break;
		case 4:
			cout << "\n\n<<<__************** DISPLAYING ALL INVENTORY **************__>>>\n";
			DISPLAYINGDATABASE();   // Function
			cout << "\nPress 1 For Exiting Inventory Management System & 2 For mainMenu : ";
		INVALID4:             // goto statement
			cin >> option4;
			switch (option4)
			{
			case 1:exit(0);
				break;
			case 2: goto MAINMENU;
				break;
			default:cout << "\nINVALID INPUT\nPlease Try Again : ";
				goto INVALID4;
			}
			break;
		case 5:
		REBUY:
			cout << "\n\n<<<__************** BUYING INVENTORY ITEM **************__>>>\n";
			BUYINGITEM();
			cout << "\nPress 1 For Re_BUY Inventory item & 2 For mainMenu : ";
		INVALID5:             // goto statement
			cin >> option2;
			switch (option2)
			{
			case 1: goto REBUY;
				break;
			case 2: goto MAINMENU;
				break;
			default:cout << "\nINVALID INPUT\nPlease Try Again : ";
				goto INVALID5;
				break;
			}
			break;
		default: cout << "\nINVALID INPUT.\nPLEASE TRY AGAIN : ";
			goto TRYTRYAGAIN;

		}
	}
}

int additem = 0;
int c = 0;
string addItemName[50];
void AddingItem()
{
	inventory_item* add;
	add = new inventory_item;

addAnotherName:
	cout << "\nEnter Name Of Inventory Item : ";
	cin >> add->item_name;
	addItemName[c] = add->item_name;
	inventory_item* searchUniqueName = fptr; int flag = 0;
	while (searchUniqueName != NULL)
	{
		if (addItemName[c] == searchUniqueName->item_name)
			flag = 1;
		searchUniqueName = searchUniqueName->nextptr;
	}

	if (flag == 1)
	{
		cout << "\nName is Not Unique.\nPlease TRY AGAIN !! ";
		goto addAnotherName;
	}
	cout << "\nEnter Id of " << add->item_name << " Item : ";
	cin >> add->item_id;
	cout << "\nEnter Quantity of " << add->item_name << " Item : ";
	cin >> add->qty;
	cout << "\nEnter Price per Item of " << add->item_name << " : ";
	cin >> add->price_per_item;

	c++;
	if (fptr == NULL)
	{

		add->nextptr = NULL;
		fptr = add;

	}
	else
	{
		inventory_item* currentptr = fptr;
		while (currentptr->nextptr != NULL)
		{
			currentptr = currentptr->nextptr;
		}

		currentptr->nextptr = add;
		add->nextptr = NULL;
	}


	additem++;
}

int remaningquantity[20], qtydemanded[20];
int i = 0;
void Sellingitem()
{

	inventory_item* displaychart = fptr;
	cout << endl << setw(15) << left << "ITEM ID" << setw(15) << left << "ITEM NAME";
	while (displaychart != NULL)
	{

		cout << endl << setw(15) << left << displaychart->item_id << setw(15) << left << displaychart->item_name;


		displaychart = displaychart->nextptr;

	}
	cout << "\n\n";
	int k = 0;
	int flag = 0;
	string sale;
	cout << "\nEnter Name of Item to Sell : ";
	cin >> sale;

	inventory_item* saleitem = fptr;
	while (saleitem != NULL)
	{
		if (saleitem->item_name == sale)
		{
			flag = 1;

			break;
		}
		k++;

		saleitem = saleitem->nextptr;
	}
	//saleitem = fptr;
	if (flag == 1)
	{
		cout << "\nItem " << sale << " is Present in system.";
		cout << "\nQuantity of Item " << sale << " is " << saleitem->qty;
		cout << "\nEnter Quantity of Stock You Want : ";
		cin >> qtydemanded[i];
		if (saleitem->qty >= qtydemanded[i])
		{
			cout << endl << qtydemanded[i] << " Number of items are Present in System.";
			cout << "\nPrice for Quantity Demanded = " << (saleitem->price_per_item * qtydemanded[i]);
			remaningquantity[i] = (saleitem->qty - qtydemanded[i]);
			cout << "\nQuantity of Stock Remaning = " << remaningquantity[i];
			saleitem->qty = remaningquantity[i];
			if (remaningquantity[i] == 0)
			{
				cout << "\nQuantity == 0";
				inventory_item* firstptr = fptr;
				inventory_item* secondptr = fptr;
				for (i = 0; i < k; i++)
				{
					secondptr = firstptr;
					firstptr = firstptr->nextptr;
				}
				secondptr->nextptr = firstptr->nextptr;
				delete firstptr;

			}

		}
		else
		{
			cout << endl << qtydemanded[i] << " Number of items are not Present in System.";
		}
		saleitem = saleitem->nextptr;

	}
	else
	{
		cout << "\nItem " << sale << " do not Exist in System.";
	}
}

void Removinginventoryitem()
{
	string remove;
	cout << "\nEnter Name Of Item For Removing : ";
	cin >> remove;
	inventory_item* removefptr = fptr;
	int count = 1, flag = 0;
	while (removefptr != NULL)
	{
		if (removefptr->item_name == remove)
		{
			flag = 1;
			break;
		}
		count++;
		removefptr = removefptr->nextptr;
	}
	if (flag == 1)
	{
		cout << "Item Name " << remove << " is at Entry " << count << ".";
	}
	else
	{
		cout << "Item Name " << remove << " is not present in List. ";
	}

	if (count == 1)                               // Deleting First Node
	{
		inventory_item* removeFirstNode;
		removeFirstNode = new inventory_item;
		removeFirstNode = fptr;
		fptr = fptr->nextptr;
		delete removeFirstNode;
		cout << "\nFirst Node Is Successfuly Deleted.";
	}
	else if (additem == count)                         // Deleting Last Node
	{
		inventory_item* removeLastNocde = fptr;
		inventory_item* removePreviousOfLastNocde = fptr;
		while (removeLastNocde->nextptr != NULL)
		{
			removePreviousOfLastNocde = removeLastNocde;
			removeLastNocde = removeLastNocde->nextptr;

		}
		removePreviousOfLastNocde->nextptr = NULL;
		delete removeLastNocde;





		cout << "\nLast Node Is Successfuly Deleted.";
	}
	else                                   // Deleting Node in between
	{

		inventory_item* removeInBetw = fptr;
		inventory_item* removeInBetwPrevious = fptr;
		for (int i = 1; i < count; i++)
		{
			removeInBetwPrevious = removeInBetw;
			removeInBetw = removeInBetw->nextptr;
		}
		removeInBetwPrevious->nextptr = removeInBetw->nextptr;
		delete removeInBetw;

		cout << "\n Node at Entry " << count << " is Successfuly Deleted.";
	}



}

void DISPLAYINGDATABASE()
{
	int j = 0;
	inventory_item* displayingptr = fptr;
	cout << "\n\n" << setw(25) << left << "ITEM NAME" << setw(25) << left << "ITEM ID" << setw(25) << left << "QUANTITY" << setw(25) << left << "Price Per Item" << setw(25) << left << "Quantity Demanded" << setw(25) << left << "Total price" << setw(25) << left << "Quantity Left";
	cout << "\n";
	while (displayingptr != NULL)
	{

		cout << "\n" << setw(25) << left << displayingptr->item_name << setw(25) << left << displayingptr->item_id << setw(25) << left << displayingptr->qty << setw(25) << left << displayingptr->price_per_item << setw(25) << left << qtydemanded[j] << setw(25) << left << (displayingptr->price_per_item * qtydemanded[i]) << setw(25) << left << remaningquantity[j];

		j++;
		displayingptr = displayingptr->nextptr;
	}
}

int qtydemandedBUY[20], remaningquantityBUY[20];
int m = 0;

void BUYINGITEM()
{
	inventory_item* displaychart1 = fptr;
	cout << endl << setw(15) << left << "ITEM ID" << setw(15) << left << "ITEM NAME";
	while (displaychart1 != NULL)
	{

		cout << endl << setw(15) << left << displaychart1->item_id << setw(15) << left << displaychart1->item_name;


		displaychart1 = displaychart1->nextptr;

	}
	cout << "\n\n";



	int k = 0;
	int flag = 0;
	string BUY;
	cout << "\nEnter Name of Item to BUY : ";
	cin >> BUY;

	inventory_item* BUYitem = fptr;
	while (BUYitem != NULL)
	{
		if (BUYitem->item_name == BUY)
		{
			flag = 1;

			break;
		}
		k++;

		BUYitem = BUYitem->nextptr;
	}
	//saleitem = fptr;
	if (flag == 1)
	{
		cout << "\nItem " << BUY << " is Present in system.";
		cout << "\nQuantity of Item " << BUY << " is " << BUYitem->qty;
		cout << "\nEnter Quantity of Stock You Want : ";
		cin >> qtydemandedBUY[m];
		if (BUYitem->qty >= qtydemandedBUY[m])
		{
			cout << endl << qtydemandedBUY[m] << " Number of items are Present in System.";
			cout << "\nPrice for Quantity Demanded = " << (BUYitem->price_per_item * qtydemandedBUY[m]);
			remaningquantityBUY[m] = (BUYitem->qty + qtydemandedBUY[m]);
			cout << "\nQuantity of Stock Remaning = " << remaningquantityBUY[m];
			BUYitem->qty = remaningquantityBUY[m];


		}
		else
		{
			cout << endl << qtydemandedBUY[i] << " Number of items are not Present in System.";
		}
		BUYitem = BUYitem->nextptr;

	}
	else
	{
		cout << "\nItem " << BUY << " do not Exist in System.";
	}


}


































