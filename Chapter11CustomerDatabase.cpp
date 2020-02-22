//nick venuto
//February 4th, 2020 ©
//Write a program that uses a structure to store the following data about a customer account:Name; Address; City, State, Zip; Telephone Number; Account Balance; Date of Last Payment
//The program should use an array of at least 2 structures.  It should let the user enter the data into the array, change the contents of any element, and display all the data stored in the array. The program should have a menu-driven user interface.  INput validation: When the data for a new account is entered, be sure the user enters data for all fields.  No negative account balances should be entered.


//***NICK ADD A MENU DRIVEN USER INTERFACE I.E. 1 TO CREATE ANOTHER CUSTOMER, 2 TO PRINT
#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

struct account
{
	char name[31];
	char address[81];
	char city[31];
	char state[15];
	char zip[6];
	char phone[13];
	char lastPayment[11];
	double balance;


};

//Function Prototype
void getData(account c[], int count);
void printData(account c[], int userInput);
void searchData(account c[], char search[], int count);

int main()
{
	int numCustomers; //number of profiles needed
	//int userView;	//profile number user would like to view
	int menuSelection;
	char searchTerm[31]; //variable for search term

	account customers[10] = {}; //structure of customers account info

	cout << "\tWelcome to the Customer Database\n";
	do
	{
		cout << "\nThe following is your list of selections: \n";
		cout << "1. Enter Customers into the Database (Up to 10)\n2. View All Customers in Database\n3. Search Database for Specific Customer\n4. Quit Program" << endl;
		cout << "\nEnter your selection: ";
		cin >> menuSelection;
		if (menuSelection == 1)
		{
			//Get number of profiles needed from user
			cout << "Enter the number of profiles needed: (10 or Less)" << endl;
			cin >> numCustomers;
			cin.ignore();

			//Collect the data for the given number of accounts
			getData(customers, numCustomers);
			break;
		}
		else if (menuSelection == 2 || menuSelection == 3)
		{
			cout << "\nThere are no customers currently in the database\n" << endl;
		}

	} while (menuSelection != 4);
	
	if (menuSelection == 4)
		return 0; 
	cout << "\nYour Database Now Has Customers" << endl;

	do
	{
		menuSelection = 0;//reinitialize menuSelection to zero
		cout << "\nThe following is your list of selections: \n";
		cout << "1. View All Customers in Database\n2. Search Database for Specific Customer\n3. Quit Program" << endl;
		cout << "\nEnter your selection: ";
		cin >> menuSelection;
		
		cin.ignore();
		if (menuSelection == 1)
		{
			printData(customers, numCustomers);
		}
		else if (menuSelection == 2)
		{
			cout << "Enter the customer's first name: " << endl;
			cin.get(searchTerm, 31);
			searchData(customers, searchTerm, numCustomers);
		}
		
	} while (menuSelection != 3);


	/*Ask the user which customer they'd like to view

	cout << "\nThere are " << numCustomers << " customer profile(s) built" << endl;
	cout << "Enter the customer's number you'd like to view(i.e. 1, 2, etc...) or 0 to quit: " << endl;
	cin >> userView;
	if (userView > numCustomers)
		cout << "\nCustomer " << userView << " does not exist\n" << endl;
	while (userView != 0)
	{
		printData(customers, userView);
		cout << "\nThere are " << numCustomers << " customer profile(s) built" << endl;
		cout << "Enter the customer's number you'd like to view(i.e. 1, 2, etc...) or 0 to quit: " << endl;
		cin >> userView;
		while (userView > numCustomers)
		{
			cout << "\nCustomer " << userView << " does not exist\n" << endl;
			cout << "Enter the customer's number you'd like to view(i.e. 1, 2, etc...) or 0 to quit: " << endl;
			cin >> userView;
		}
	}*/

	return 0;
}

void getData(account c[], int count)
{
	for (int cnt = 0; cnt < count; cnt++)
	{
		cout << "\tCustomer #" << cnt + 1 << "'s Info" << endl;
		//Get the string info
		cout << "Enter the customer's name: " << endl;
		cin.getline(c[cnt].name, 31);
		while (!isalpha(c[cnt].name[0]))
		{
			cout << "That is not a valid entry\nEnter the customer's name: " << endl;
			cin.getline(c[cnt].name, 31);
		}
		cout << "Enter the customer's address: " << endl;
		cin.getline(c[cnt].address, 81);
		while (isspace(c[cnt].address[0]))
		{
			cout << "That is not a valid entry\nEnter the customer's address: " << endl;
			cin.getline(c[cnt].address, 81);
		}
		cout << "Enter the customer's city: " << endl;
		cin.getline(c[cnt].city, 31);
		while (isspace(c[cnt].city[0]))
		{
			cout << "That is not a valid entry\nEnter the customer's city: " << endl;
			cin.getline(c[cnt].city, 31);
		}
		cout << "Enter the customer's state: " << endl;
		cin.getline(c[cnt].state, 15);
		while (isspace(c[cnt].state[0]))
		{
			cout << "That is not a valid entry\nEnter the customer's state: " << endl;
			cin.getline(c[cnt].state, 15);
		}
		cout << "Enter the customer's zip code: " << endl;
		cin.getline(c[cnt].zip, 6);
		while (!isdigit(c[cnt].zip[0]))
		{
			cout << "That is not a valid entry\nEnter the customer's zip:  " << endl;
			cin.getline(c[cnt].zip, 6);
		}
		cout << "Enter the customer's phone number (xxx-xxx-xxxx): " << endl;
		cin.getline(c[cnt].phone, 13);
		while (!isdigit(c[cnt].phone[0]))
		{
			cout << "That is not a valid entry\nEnter the customer's phone (xxx-xxx-xxxx): " << endl;
			cin.getline(c[cnt].phone, 13);
		}
		cout << "Enter the customer's balance: " << endl;
		cin >> c[cnt].balance;
		while (c[cnt].balance < 0)
		{
			cout << "That customers balance cannot be negative\nEnter the customer's balance: ";
			cin >> c[cnt].balance;
		}
		cout << "Enter the customer's last payment date: (MM/DD/YYYY)" << endl;
		cin.ignore();
		cin.getline(c[cnt].lastPayment, 11);
		while (!isdigit(c[cnt].lastPayment[0]))
		{
			cout << "That is not a valid entry\nEnter the customer's last payment date (MM/DD/YYYY): " << endl;
			cin.getline(c[cnt].lastPayment, 11);
		}
	}

}

void printData(account c[], int count)
{
	for (int cnt = 0; cnt < count; cnt++)
	{
		cout << "\n\tCustomer #" << cnt + 1 << endl;
		cout << "Customer's Name: " << c[cnt].name << endl;
		cout << "Customer's Address: " << c[cnt].address << endl;
		cout << "Customer's City, State, Zip: " << c[cnt].city << ", " << c[cnt].state << " " << c[cnt].zip << endl;
		cout << "Customer's Phone: " << c[cnt].phone << endl;
		cout << "Customer's balance: " << c[cnt].balance << endl;
		cout << "Customer's Last Payment Date: " << c[cnt].lastPayment << endl;
	}

}
void searchData(account c[], char search[], int count)
{
	cin.ignore();
	int found=0; 
	for (int cnt = 0; cnt < count; cnt++)
	{
		if (strcmp(search, c[cnt].name)==0)
		{
			cout << "\n\tCustomer #" << cnt + 1 << endl;
			cout << "Customer's Name: " << c[cnt].name << endl;
			cout << "Customer's Address: " << c[cnt].address << endl;
			cout << "Customer's City, State, Zip: " << c[cnt].city << ", " << c[cnt].state << " " << c[cnt].zip << endl;
			cout << "Customer's Phone: " << c[cnt].phone << endl;
			cout << "Customer's balance: " << c[cnt].balance << endl;
			cout << "Customer's Last Payment Date: " << c[cnt].lastPayment << endl;
			found++;
		}
	}
	if (found == 0)
		cout << "\nNo Customer Found\n";
}