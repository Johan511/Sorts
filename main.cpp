#include <iostream>
#include <stdio.h>
#include "./0_headers/sorts/sorts.h"
#include <cstdlib>
#include <sys/time.h>
#include <chrono>
#include <string>
#include <vector>
#include <sys/resource.h>
// Idea derived from slides of Dr. Rupesh Nasre
//  http://www.cse.iitm.ac.in/~rupesh/teaching/programming/may22/code/sort.cpp
using namespace std;
void random_populate(int *array, int length);
bool less_than(int a, int b);
int *array_million = new int[1000000];
int *array_ten_million = new int[10000000];
int *array_hundered_million = new int[100000000];
int *array_thousand_million = new int[1000000000];

int main()
{

	chrono::time_point<std::chrono::high_resolution_clock> chrono_start, chrono_end;

	chrono_start = chrono::high_resolution_clock::now();

	random_populate(array_million, 1000000);
	random_populate(array_ten_million, 1000000);
	random_populate(array_hundered_million, 100000000);
	random_populate(array_thousand_million, 1000000000);

	chrono_end = chrono::high_resolution_clock::now();

	// chrono::duration<double> elapsed_seconds = chrono_end - chrono_start;

	cout << "created all arrays in " << (chrono::duration<double>(chrono_end - chrono_start)).count() << " seconds" << endl;
	Sorts<int> s;

	chrono_start = chrono::high_resolution_clock::now();
	s.quickSort_0(array_million, 1000, less_than);
	chrono_end = chrono::high_resolution_clock::now();
	cout << "quickSort_0 million elements in " << (chrono::duration<double>(chrono_end - chrono_start)).count() << " seconds" << endl;

	// chrono_start = chrono::high_resolution_clock::now();
	// s.quickSort_0(array_ten_million, 10000000, less_than);
	// chrono_end = chrono::high_resolution_clock::now();
	// cout << "quick sorted 10 million elements in " << (chrono::duration<double>(chrono_end - chrono_start)).count() << " seconds" << endl;

	// chrono_start = chrono::high_resolution_clock::now();
	// s.quickSort_0(array_hundered_million, 100000000, less_than);
	// chrono_end = chrono::high_resolution_clock::now();
	// cout << "quick sorted 100 million elements in " << (chrono::duration<double>(chrono_end - chrono_start)).count() << " seconds" << endl;

	// chrono_start = chrono::high_resolution_clock::now();
	// s.quickSort_0(array_thousand_million, 1000000000, less_than);
	// chrono_end = chrono::high_resolution_clock::now();
	// cout << "quick sorted 1000 million elements in " << (chrono::duration<double>(chrono_end - chrono_start)).count() << " seconds" << endl;

	delete array_million;
	delete array_ten_million;
	delete array_hundered_million;
	delete array_thousand_million;
}
bool less_than(int a, int b)
{
	if (a < b)
	{
		return true;
	}
	return false;
}

void random_populate(int *array, int length)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		array[i] = rand();
		// cout << array[i] << endl;
	}
}