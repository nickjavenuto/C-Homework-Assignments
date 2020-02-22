//nick venuto
//1.19.2020 ©
//A function that dynamically allocates an array of integers, accepting an integer argument indicating the number of elements to allocate. Returns a pointer to the array.

#include<iostream>
using namespace std; 

//Function Prototypes 
int *dynAlloIntArr(int num);


int main()
{
	int size;  
	cout << "How many elements would you like your array to contain?" << endl; 
	cin >> size; 
	int *newArray = dynAlloIntArr(size);
	cout << "Your dynamically allocated array is = {"; 
	for (int cnt1 = 0; cnt1 < size; cnt1++)
	{
		cout << " " << *(newArray + cnt1);
		if (cnt1 < size-1)
			cout << ",";
		else
			cout << " ";
	}
		cout << "}" << endl; 
		delete[] newArray;
		newArray = nullptr; 
}
int *dynAlloIntArr(int num)
{
	int *newArr = nullptr; 
	newArr = new int[num];
	for (int cnt1 = 0; cnt1 < num; cnt1++)
		*(newArr + cnt1) = cnt1 + 1;
	return newArr; 

}