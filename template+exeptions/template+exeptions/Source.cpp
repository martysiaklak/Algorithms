#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>

void func(vector<T>& array, int size) 
{
	for (int i = 0; i < size; i+=3)  //in order not to repeat 
	{
		array.insert(array.begin() + i + 1, array[i]);
		size++; // increase size by 1 to account for repeated element
	}
}

template <typename T>
void print(vector<T> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		if (i == array.size() - 1)
		{
			cout << array[i] << ". ";
		}
		else
		{
			cout << array[i] << ", ";
		}
	}
	cout << endl;
}

int main()
{
	try {
		vector<int> int_array = {1,2,3,4,0,9,8,7,6,5};
		if (int_array.size()==0)
		{
			throw invalid_argument("No elements in integer array");   
		}

		vector<string> string_array = { "hello", "hi","banana", "apple","tree", "summer", "wifi" };
		if (string_array.size() == 0)
		{
			throw invalid_argument("No elements in string array");     
		}

		func(int_array, int_array.size());
		print(int_array);
		func(string_array, string_array.size());
		print(string_array);
	}
	catch (invalid_argument& e)
	{
		cerr << "Error:" << e.what() << endl;
	}
	return 0;
}
