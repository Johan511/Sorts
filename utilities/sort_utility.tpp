#include "../0_headers/utilities/sort_utility.h"

template <typename T_element>
void Utility<T_element>::swap(T_element &element1, T_element &element2)
{
    T_element temp = element1;
    element1 = element2;
    element2 = temp;
}