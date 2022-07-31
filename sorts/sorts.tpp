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
				u.swap(*(array + j), *(array + i));
			}
		}
	}
};

template <typename T_element>
void Sorts<T_element>::mergeSort(T_element *array, int length, bool (*less_than)(T_element, T_element))
{
	__mergeSort(array, 0, length, less_than);
}

template <typename T_element>
void Sorts<T_element>::__mergeSort(T_element *array, int begin, int end, bool (*less_than)(T_element, T_element))
{
	if (end - begin + 1 > 1)
	{
		int middle = (begin + end) / 2;
		__mergeSort(array, begin, middle, less_than);
		__mergeSort(array, middle + 1, end, less_than);
		__merge(array + begin, middle - begin + 1, array + middle + 1, end - middle, less_than);
	}
}

template <typename T_element>
void Sorts<T_element>::__merge(T_element *array1, int len1, T_element *array2, int len2, bool (*less_than)(T_element, T_element))
{
	T_element *temp_array;
	temp_array = new T_element[len1 + len2];
	int pointer1 = 0;
	int pointer2 = 0;
	while (pointer1 < len1 && pointer2 < len2)
	{
		if (less_than(array1[pointer1], array2[pointer2]))
		{
			temp_array[pointer1 + pointer2] = array1[pointer1];
			pointer1++;
		}
		else
		{
			temp_array[pointer2 + pointer1] = array2[pointer2];
			pointer2++;
		}
	}
	if (pointer1 < len1)
	{
		while (pointer1 < len1)
		{
			temp_array[pointer1 + pointer2] = array1[pointer1];
			pointer1++;
		}
	}
	if (pointer2 < len2)
	{
		while (pointer2 < len2)
		{
			temp_array[pointer2 + pointer1] = array2[pointer2];
			pointer2++;
		}
	}

	for (int i = 0; i < len1; i++)
	{
		array1[i] = temp_array[i];
	}
	for (int i = 0; i < len2; i++)
	{
		array2[i] = temp_array[i + len1];
	}
	free(temp_array);
}

template <typename T_element>
void Sorts<T_element>::quickSort_0(T_element *array, int length, bool (*less_than)(T_element, T_element))
{
	__quickSort_0(array, 0, len - 1, less_than);
}

template <typename T_element>
void Sorts<T_element>::__quickSort_0(T_element *array, int start, int end, bool (*less_than)(T_element, T_element))
{
	if (start < end)
	{
		int pivot_position = __partition_0(array, start, end, less_than);

		__quickSort_0(array, 0, pivot_position, less_than);
		__quickSort_0(array, pivot_position + 1, end, less_than);
	}
}

template <typename T_element>
int Sorts<T_element>::__partition_0(T_element *array, int start, int end, bool (*less_than)(T_element, T_element))
{
	int pivot_index = __getPivotIndex_0(array, start, end, less_than);
	u.swap(&pivot_index, &array[0]);
}

template <typename T_element>
int Sorts<T_element>::__getPivotIndex_0(T_element *array, int start, int end, bool (*less_than)(T_element, T_element))
{
	return 0;
}

// can't template count sort (same for radix sort)
// count sort works on the princple that we already have compared integers (1<2<3<4<...)
// but we haven't done it for all possible templates
// template <typename T_element>
// void Sorts<T_element>::countSort(T_element *array, int length, bool (*less_than)(T_element, T_element))
// {
// 	struct __min_max<T_element> min_max = min_max(array, length, less_than);
// 	T_element *frequency_array = new T_element[__min_max.max - __min_max.min + 1];
// 	// we assume - operator is overloaded
// 	for (int i = 0; i < length; i++)
// 	{
// 		frequency_array[min]
// 	}

// }

template <typename T_element>
struct __min_max<T_element> Sorts<T_element>::min_max(T_element *array, int length, bool (*less_than)(T_element, T_element))
{
	T_element max = array[0];
	T_element min = array[0];
	for (int i = 0; i < length; i++)
	{
		if (less_than(max, array[i]))
		{
			max = array[i];
		}
		else
		{
			min = array[i];
		}
	}
	struct __min_max<T_element> return_min_max;
	return_min_max.min = min;
	return_min_max.max = max;
	return return_min_max;
}