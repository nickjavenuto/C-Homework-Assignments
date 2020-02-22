//nick venuto
//2/2/20 ©
//Write a function that accepts a pointer to a C-string as its argument.  The function should count the number of vowels appearing in the string and return that number.  Write another function that accepts a pointer to a c-string as its argument. THis function should count the number of consonants appearing in the string and return that number.
//demonstrate these two functions in a main function that performs the following steps: 1)Ask user to enter a string 2)The program displays the menu in the book 3) The program performs the operation selected by the user and repeats until the user selects E to exit to the program.

#include<iostream>
#include<cctype>
using namespace std; 

//Function Prototypes
int findVowels(char word[]);
int findCons(char word[]);

int main()
{
	char userInput[81];
	char menuSelection; 

	
	//Ask the user to enter a string
	cout << "Please enter a string less than 81 characters:\n";
	cin.getline(userInput, 81);
	cout << endl; 

	do
	{
		//Display the menu
		cout << "Your menu of choices:" << endl;
		cout << "A) Count the number of vowels in the string\nB) Count the number of consonants in the string\nC) Count both the vowels and consonants in the string\nD) Enter another string\nE) Exit the program\n" << endl; 
		cout << "Enter your selection: ";
		cin.get(menuSelection);
		cin.ignore();
		
		switch (toupper(menuSelection))
		{
		case 'A': 
		{
			int numVowels = findVowels(userInput);
			cout << "The number of vowels in your string is " << numVowels << endl;
			cout << endl; 
			break;
		}
		case 'B':
		{	
			int numCons = findCons(userInput);
			cout << "The number of consonants in your string is " << numCons << endl;
			cout << endl; 
			break;
		}
		case 'C':
		{
			int numVowels = findVowels(userInput);
			cout << "The number of vowels in your string is " << numVowels << endl;
			int numCons = findCons(userInput);
			cout << "The number of consonants in your string is " << numCons << endl;
			cout << endl; 
			break;
		}
		case 'D':
		{
			cout << "Please enter another string less than 81 characters: " << endl; 
			cin.getline(userInput, 81);
			cout << endl; 
			break;
		}
		default: 
			if (toupper(menuSelection) != 'E')
			{
				cout << "That is not a valid selection." << endl;
				cout << endl;
				break;
			}
		}


	} while (toupper(menuSelection) != 'E');

	return 0; 
}

int findVowels(char word[])
{
	int count = 0; //Vowel Count
	int length = strlen(word);
	
	for (int index = 0; index < length; index++)
	{
		char test = toupper(word[index]);
		if (test == 'A' || test == 'E' || test == 'I' || test == 'O' || test == 'U')
			count++; 			
	}
	return count;
}


int findCons(char word[])
{
	int count = 0; //Consonant Count
	int length = strlen(word);

	for (int index = 0; index < length; index++)
	{
		char test = toupper(word[index]);
		if (!(test == 'A' || test == 'E' || test == 'I' || test == 'O' || test == 'U' || test == ' '))
				count++;
		
	}
	return count;

}


