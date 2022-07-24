#include <iostream>
#include <stdio.h>
#include "./0_headers/sorts/sorts.h"

// Idea derived from slides of Dr. Rupesh Nasre
//  http://www.cse.iitm.ac.in/~rupesh/teaching/programming/may22/code/sort.cpp

template <typename T_element>
void Utility<T_element>::swap(T_element &element1, T_element &element2)
{
	T_element temp = element1;
	element1 = element2;
	element2 = temp;
}

template <typename T_element>
void Sorts<T_element>::bubbleSort(T_element *array, int length, bool (*less_than)(T_element, T_element))
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (less_than(*(array + j), *(array + i)))
			{
			}
			else
			{
				Utility<T_element> s;
				s.swap(*(array + j), *(array + i));
			}
		}
	}
};

bool less_than(int a, int b);

int main()
{
	Sorts<int> s;
	int array[5] = {5, 4, 3, 2, 1};
	s.bubbleSort(array, 5, &less_than);
	for (int i = 0; i < 5; i++)
	{
		std::cout << *(array + i) << std::endl;
	}
	std::cout << " ho " << std::endl;
}

bool less_than(int a, int b)
{
	if (a < b)
	{
		return true;
	}
	return false;
}
