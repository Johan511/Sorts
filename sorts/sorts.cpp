#include "../0_headers/sorts/sorts.h"

template <typename T_element>
void Sorts<T_element>::print()
{
	printf("hi");
};

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
				Utility<int> u;
				u.swap(*(array + j), *(array + i));
			}
		}
	}
};
