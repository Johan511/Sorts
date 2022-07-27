#include <iostream>
#include <stdio.h>
#include "./0_headers/sorts/sorts.h"

// Idea derived from slides of Dr. Rupesh Nasre
//  http://www.cse.iitm.ac.in/~rupesh/teaching/programming/may22/code/sort.cpp

bool less_than(int a, int b);

int main()
{
	Sorts<int> s;
	int array[5] = {5, 4, 3, 2, 1};
	s.bubbleSort(array, 5, &less_than);
	for (int i = 0; i < 5; i++)
	{
		printf("%d", array[i]);
	}
}

bool less_than(int a, int b)
{
	if (a < b)
	{
		return true;
	}
	return false;
}
