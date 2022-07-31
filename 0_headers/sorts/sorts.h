#pragma once
#include <stdio.h>
#include "../utilities/sort_utility.h"
template <typename T_element>
struct __min_max
{
	T_element min;
	T_element max;
};
template <typename T_element>
class Sorts
{

private:
	Utility<T_element> u;

	struct __min_max<T_element> min_max(T_element *array, int length, bool (*less_than)(T_element, T_element));

	void __mergeSort(T_element *array, int begin, int end, bool (*less_than)(T_element, T_element));
	void __merge(T_element *array1, int len1, T_element *array2, int len2, bool (*less_than)(T_element, T_element));

	void __quickSort_0(T_element *array, int start, int end, bool (*less_than)(T_element, T_element));
	int __partition_0(T_element *array, int start, int end, bool (*less_than)(T_element, T_element));
	int __getPivotIndex_0(T_element *array, int start, int end, bool (*less_than)(T_element, T_element));

public:
	void bubbleSort(T_element *array, int length, bool (*less_than)(T_element, T_element));

	void insertionSort(T_element *array, int length, bool (*less_than)(T_element, T_element));

	void mergeSort(T_element *array, int length, bool (*less_than)(T_element, T_element));

	void quickSort_0(T_element *array, int length, bool (*less_than)(T_element, T_element));

	// void countSort(T_element *array, int length, bool (*less_than)(T_element, T_element));

	void bubbleSort(int length, T_element...);
	void insertionSort(int length, T_element...);
	void mergeSort(int length, T_element...);
	void print();

protected:
};

class QuickSort
{
private:
public:
protected:
};

#include "../../sorts/sorts.tpp"