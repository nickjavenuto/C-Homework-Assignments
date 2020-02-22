//nick venuto
//Feb. 21st, 2020 ©
//This program asks the user for a file name.  The file is then displayed with the line number preceding each line.  If the file contents don't fit on a single screen, the program should display 24 lines of output at a time, then pause.  Each time the program pauses it should wait for the user to strike a key before the next 24 lines are displayed.
#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

int main()
{
	fstream file; //Create a fstream object variable to hold a file
	string userInput; //Create a variable to hold the user's input
	int lineNumber=1; //Create a variable to hold the line number
	string input; //To hold a file input

	//Ask the user for the name of the file to be displayed
	cout << "Enter the name of the file you wish to be displayed: \n"; 
	cin >> userInput; 

	//Open the file
	file.open(userInput, ios::in); 
	
	//Display the file numbering each line, 24 lines at a time, with a pause in-between
	if (file)
	{
		//Read an item from the file
		getline(file, input);
		cin.ignore(); 

		//WHile the last read was successfully opened, continue
		while (file)
		{
			for (int count = 0; count < 24; count++)
			{
				cout << lineNumber << ": " << input << endl; 
				lineNumber++; 
				getline(file, input); 
				if (count <= 24 && !file)
				{
					cout << "END OF FILE" << endl; 
					break;
				}
					 
			}
			cin.get(); 
		}
	}
	else
		cout << "ERROR: Couldn't find file.  Program aborted." << endl;

	return 0; 
}