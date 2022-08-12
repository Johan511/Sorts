#include <cstdlib>
#include <time.h>
#include <vector>

#define PIVOT_FIRST 0
#define PIVOT_AVERAGE_MEDIAN 1
#define PIVOT_MEDIAN 2
#define PIVOT_RANDOM 3
#define PIVOT_LAST 4

template <typename T_element>
class quickSort
{
    // returns position of element of rank r
    static int findRank_r(T_element *array, int begin, int end, int rank);

private:
    int pivot_schema;
    T_element *array;
    int length;
    bool (*compare_function)(T_element, T_element);
    void getPivotPosition(int begin, int end);

    void __quickSort(T_element *array, int begin, int end, bool (*compare_function)(T_element, T_element));
    void __quickSort(int begin, int end);

public:
    quickSort(int pivot_schema);

    ~quickSort();
    void operator()(T_element *array, int length, bool (*compare_function)(T_element, T_element));

protected:
};

template <typename T_element>
quickSort<T_element>::quickSort(int pivot_schema)
{
    this->pivot_schema = pivot_schema;
}

template <typename T_element>
void quickSort<T_element>::operator()(T_element *array, int length, bool (*compare_function)(T_element, T_element))
{
    this->array = array;
    this->length = length;
    this->compare_function = compare_function;
    __quickSort(0, length);
}

template <typename T_element>
void quickSort<T_element>::__quickSort(T_element *array, int begin, int end, bool (*compare_function)(T_element, T_element))
{
    if (begin < end)
    {
        int pivot = getPivotPosition(begin, end);
        __quickSort(begin, pivot);
        __quickSort(pivot + 1, end);
    }
}

template <typename T_element>
void quickSort<T_element>::getPivotPosition(int begin, int end)
{
    if (this->pivot_schema == PIVOT_FIRST)
    {
        return begin
    }
    else if (this->pivot_schema == PIVOT_AVERAGE_MEDIAN)
    {
    }
    else if (this->pivot_schema == PIVOT_MEDIAN)
    {
    }
    else if (this->pivot_schema == PIVOT_RANDOM)
    {
        srand(time(NULL));
        return rand() * (end - begin) / RAND_MAX;
    }
    else if (this->pivot_schema == PIVOT_LAST)
    {
        return end - 1;
    }
}

template <typename T_element>
int quickSort<T_element>::findRank_r(T_element *array, int begin, int end, int rank)
{
    vector<T_element> less_than;
    vector<T_element> equal_to;
    vector<T_element> greater_than;

    int pivot;
    if (this->pivot_schema != PIVOT_MEDIAN)
    {
        pivot = getPivotPosition(begin, end);
    }
    else
    {
        int temp_pivot_schema = this->pivot_schema;
        this->pivot_schema = PIVOT_AVERAGE_MEDIAN;
        pivot = getPivotPosition(begin, end);
        this->pivot_schema = temp_pivot_schema;
    }

    for (int i = begin; i < end; i++)
    {
    }
}
