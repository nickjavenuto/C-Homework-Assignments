//nick venuto
//January 16th, 2019
//Chapter 7 to 9 Assignment
#include<string>
#include <iomanip>
#include<iostream>
using namespace std; 


int main()
{
	//Step 1. The following arrays created:a. an array of double with 5 elements, dArrb. an array of long, lArr, with 7 elements and initialized at the time of creation with the values 100000, 134567, 123456, 9, -234567, -1, 123489c. a 2 dimensional array of integer, with 3 rows and 5 columns, iArr. d. an array of char with your name initialized in it. Big enough for 30 typable characters, sName
	double dArr[5]; 
	long lArr[7] = { 100000, 134567, 123456, 9, -234567, -1, 123489 };
	int iArr[3][5]; 
	char sName[31] = "nick venuto";
	//Step 2. define 3 variables, , cnt1 and cnt2 (short data types) as general purpose countersand a long double total
	short cnt1, cnt2; 
	long double total = 0; 
	//Step 3. define 1 long variable called highest
	long highest; 
	//Step 4. a for loop to put a random number into each of the elements of the array of double, dArr. Use rand() and seed a random starting point with srand.
	srand((unsigned int)time(NULL));
	for (cnt1 = 0; cnt1 < 5; cnt1++)
		dArr[cnt1] = rand();
	cout << "The elements in dArr are as follows: " << endl;
	for (cnt1 = 0; cnt1 < 5; cnt1++)
		cout << dArr[cnt1] << " ";
	cout << endl;
	//Step 5. another for loop to add up the array of double, dArr, into the variable total
	for (cnt1 = 0; cnt1 < 5; cnt1++)
		total += dArr[cnt1];
	//Step 6. one cout to print the total and another cout to print the average of the double array, dArr. 
	cout << endl << "The total of dArr is " << total << endl << "The average of dArr is " << total / 5 << endl<<endl;
	//Step 7. a for loop similar to the following for the long array, lArr:for ( cnt1 = 1,highest = lArr[0];cnt1 < 7 ;cnt1++ ) {logic to compare each array element, starting with lArr[1], with highest replace highest if the value in lArr[cnt] is higher than the value in the variable highest 
	for (cnt1 = 1, highest = lArr[0]; cnt1 < 7; cnt1++)
	{
		if (lArr[cnt1] > highest)
			highest = lArr[cnt1];
	}
	//Step 8. a cout to print highest as derived in the above code
	cout << "The elements in dArr are as follows: " << endl;

	for (cnt1 = 0; cnt1 < 7; cnt1++)
		cout << lArr[cnt1] << " ";
	cout << endl; 
	cout << "The highest number in lArr is "<< highest << endl; 
	//Step 9. a for loop to put a random number, each with a value no lower than 1 and no higher than 53, into each element of iArr, the array of integer, seed the random generator with srand( (unsigned) time(NULL)). Only have to run srand once....Use the modulo operator similar to the way you did with dice rolls in Project 2.
	for (cnt1 = 0; cnt1 < 3; cnt1++)
		for (cnt2 = 0; cnt2 < 5; cnt2++)
			iArr[cnt1][cnt2] = rand() % 53 + 1;
	//Step 10. a separate loop to print iArr with 3 rows on your screen. Each row has 5 numbers. Use setw() to control the width of each column. See Chapter 3 for an example of a program using setw().Print row by row.
	cout << endl; 
	for (cnt1 = 0; cnt1 < 3; cnt1++)
	{
		for (cnt2 = 0; cnt2 < 5; cnt2++)
			cout << setw(8) << iArr[cnt1][cnt2];
		cout << endl;
	}
	//Step 11. a loop to print the 2 dimensional array, iArr, so that all 3 numbers in column 0 are printed and then on the next line all 3 numbers in column 1, etc.thru column 4. Print column by column.
	cout << endl; 
	for (cnt2 = 0; cnt2 < 5; cnt2++)
	{
		for (cnt1 = 0; cnt1 < 3; cnt1++)
			cout << setw(8) << iArr[cnt1][cnt2];
		cout << endl;
	}
	//Step 12. Use cin.getline(......) to type another name into the variable sName.
	cout << endl; 
	cout << "Enter a new name for sName: ";
	cin.getline(sName, 31);
	cout << "sName is now " << sName << endl; 
	//Step 13. Print the ASCII value of each character in the char array, 1 per line. Use a while loop and look for the '\0' as a signal to end. 
	cnt1 = 0; 
	cout << "\nThe ASCII values of sName are as follows: " << endl; 
	while (sName[cnt1] != '\0')
	{
		cout << int(sName[cnt1]) << endl; 
		cnt1++; 
	}
	cout << endl; 
	//Step 14. make the array of char, sName, have the name "Albert Einstein" in it. You must use strcpy or strcpy_s function.
	strcpy_s(sName, "Albert Einstein"); 
	cout << "You've changed the value of sName, the new value in sName is now " << sName << endl; 
	//Step 15. print the ASCII value of the 12th character of the string sName
	cout << "The 12th character of sName is " << int(sName[11]) << endl;
	//Step 16. Define a pointer to a double, pdArray.
	double* pdArray; 
	//Step 17. Assign the pointer, pdArray, to contain the address of the double array, dArr:
	pdArray = dArr; 
	//Step 18. Use the array name, dArr, to print out the array elements with subscript notation, [ ]. All on 1 line a space between each.
	cout << "\nThe elements of dArr using subscript notation are: " << endl;
	for (cnt1 = 0; cnt1 < 5; cnt1++)
	{
		cout << dArr[cnt1] << " "; 
	}
	cout << endl; 
	//Step 19. Use the pointer to print out the array elements with pointer notation while not changing the pointer itself. Use a for loop. *( pdArray + Cnt1) would be an example. All on 1 line a space between each.
	cout << "\n The elements of dArr using pointer notation are as follows: " << endl; 
	for (cnt1 = 0; cnt1 < 5; cnt1++)
	{
		cout << *(pdArray + cnt1) << " "; 
	}
	cout << "\npdArray is still: "  << *pdArray << endl;
	//Step 20. Use the pointer to print out the array elements with pointer notation but change the pointer to point to the actual array element rather than the method in 18. All on 1 line. * pdArray would do this if the loop has the following post loop operation : pdArray++
	cout << "\nUsing pointer notation to print pdArray as well as change pdArray: " << endl; 
	for (cnt1 = 0; cnt1 < 5; cnt1++, pdArray++)
		cout << *pdArray << " "; 
	cout << endl; 
	cout << "\npdArray is now at location: " << pdArray << endl; 
	cout << "\npdArray is now: " << *pdArray << endl; 
	//Step 21. Use the array name for the double array and pointer notation to print the entire array, all on one line.
	cout << "\nPrint the elements of dArr using pointer notation" << endl; 
	for (cnt1 = 0; cnt1 < 5; cnt1++)
	{
		cout << *(dArr + cnt1) << " "; 
	}
	//Step 22. Using a different pointer, piArray, dynamically allocate enough memory for 100 int's and assign the address to the pointer.
	int* piArray = new int[100];
	//Step 23. In a for loop assign every item in the array to be a random number from 1 to 49( hint: rand() % 6 + 1 gives random numbers from 1 to 6 )
	for (cnt1 = 0; cnt1 < 100; cnt1++)
		*(piArray+cnt1) = rand()%49 + 1; 
	cout << endl; 
	//Step 24. Using cout print the first 10 items in the array, all on 1 line.
	cout << "\nThe first 10 items of piArray are as follow: " << endl; 
	for (cnt1 = 0; cnt1 < 10; cnt1++)
		cout << *(piArray + cnt1) << " "; 
	
	//Step 25. Be sure to free up the dynamically allocated memo
	delete[]piArray; 

	cout << endl; 
}

/*

*/