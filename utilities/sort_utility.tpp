#include "../0_headers/utilities/sort_utility.h"
#include <iostream>
using namespace std;
template <typename T_element>
void Utility<T_element>::swap(T_element &element1, T_element &element2)
{
    T_element temp = element1;
    element1 = element2;
    element2 = temp;
};

template <typename T_element>
void Utility<T_element>::print_array(T_element *array, int length)
{
    if (length > 20)
    {
        cout << "WARNING : Array longer than 20 elements, not printing array";
        return;
    }
    for (int i = 0; i < length; i++)
    {
        cout << *(array + i) << " ";
    }
    cout << endl;
};
