#include <stdio.h>
template <typename T_element>
class Sorts
{

private:
public:
	void bubbleSort(T_element *array, int length, bool (*less_than)(T_element, T_element));
	void insertionSort(T_element *array, int length, bool (*less_than)(T_element, T_element));
	void bubbleSort(int length, T_element...);
	void insertionSort(int length, T_element...);
	void print();

protected:
};


template <typename T_element>
class Utility
{
	friend class Sorts<T_element>;
	void swap(T_element &element1, T_element &element2);
};
