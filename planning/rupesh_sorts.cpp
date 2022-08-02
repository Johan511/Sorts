#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <forward_list>
using namespace std;
using namespace std::chrono;

#define MAXSIZE 100000
#define NFUNS 20
#define MAXVALUE (MAXSIZE * 100)

class AllSortsOfThings
{
public:
    typedef enum
    {
        BubbleSlow,
        Bubble,
        BubbleFast,
        Insertion,
        InsertionBinary,
        Selection,
        Shell,
        Quick,
        Merge,
        Heaps,
        Bucket,
        Radix,
        MaxSort
    } FunType;
    vector<string> funnames;

    AllSortsOfThings(int N)
    {
        cout << "Number of elements = " << N << endl;

        arr = new int[N];
        this->N = N;
        srand(time(NULL));

        funnames.resize(MaxSort + 1);
        int ii = 0;
        funs[ii] = &AllSortsOfThings::bubbleSlow;
        funnames[ii++] = "BubbleSlow";
        funs[ii] = &AllSortsOfThings::bubble;
        funnames[ii++] = "Bubble";
        funs[ii] = &AllSortsOfThings::bubbleFast;
        funnames[ii++] = "BubbleFast";
        funs[ii] = &AllSortsOfThings::insertion;
        funnames[ii++] = "Insertion";
        funs[ii] = &AllSortsOfThings::insertionBinary;
        funnames[ii++] = "InsertionBinary";
        funs[ii] = &AllSortsOfThings::selection;
        funnames[ii++] = "Selection";
        funs[ii] = &AllSortsOfThings::shell;
        funnames[ii++] = "Shell";
        funs[ii] = &AllSortsOfThings::quick;
        funnames[ii++] = "Quick";
        funs[ii] = &AllSortsOfThings::merge;
        funnames[ii++] = "Merge";
        funs[ii] = &AllSortsOfThings::heap;
        funnames[ii++] = "Heap";
        funs[ii] = &AllSortsOfThings::bucket;
        funnames[ii++] = "Bucket";
        funs[ii] = &AllSortsOfThings::radix;
        funnames[ii++] = "Radix";
        funs[ii] = &AllSortsOfThings::maxSort;
        funnames[ii++] = "MaxSort";
    }
    ~AllSortsOfThings()
    {
        delete arr;
    }
    void init();
    void print();
    void test(FunType fun, bool debug = false);
    void testStandard(bool debug = false);

    void bubbleSlow();
    void bubble();
    void bubbleFast();
    void insertion();
    void insertionBinary();
    void selection();
    void shell();
    void quick();
    void merge();
    void heap();
    void bucket();
    void radix();
    void maxSort();

    bool isSorted();

private:
    int *arr;
    int N;
    void (AllSortsOfThings::*funs[NFUNS])();

    void swap(int ii, int jj);
    void shiftRight(int, int);
    int bsearch(int, int, int);
    void quick(int, int);
    int partition(int, int);
    void merge(int, int);
    void arrayMerge(int, int, int);
    int maximum();
    void countSort(int);
    bool distinct(int, int);

    static int compare(const void *, const void *);
};
bool AllSortsOfThings::distinct(int ee, int nn)
{
    for (int ii = 0; ii < nn; ++ii)
        if (arr[ii] == ee)
            return false;
    return true;
}
void AllSortsOfThings::init()
{
    for (int ii = 0; ii < N; ++ii)
    {
        int ee = rand() % MAXVALUE;
        if (distinct(ee, ii - 1))
            arr[ii] = ee;
        else
            --ii;
    }
}
void AllSortsOfThings::print()
{
    for (int ii = 0; ii < N; ++ii)
        cout << arr[ii] << " ";
    cout << endl;
}
bool AllSortsOfThings::isSorted()
{
    for (int ii = 0; ii < N - 1; ++ii)
        if (arr[ii] > arr[ii + 1])
            return false;
    return true;
}
void AllSortsOfThings::swap(int ii, int jj)
{
    int tmp = arr[ii];
    arr[ii] = arr[jj];
    arr[jj] = tmp;
}
void AllSortsOfThings::bubbleSlow()
{
    for (int ii = 0; ii < N; ++ii) // can be changed to run upto N - 1.
        for (int jj = 0; jj < N - 1; ++jj)
            if (arr[jj] > arr[jj + 1])
                swap(jj, jj + 1);
}
void AllSortsOfThings::bubble()
{
    for (int ii = 0; ii < N; ++ii) // can be changed to run upto N - 1.
        for (int jj = 0; jj < N - ii - 1; ++jj)
            if (arr[jj] > arr[jj + 1])
                swap(jj, jj + 1); // no use of ii.
}
void AllSortsOfThings::bubbleFast()
{
    for (int ii = 0; ii < N - 1; ++ii)
    {
        bool swapped = false;
        for (int jj = 0; jj < N - ii - 1; ++jj)
            if (arr[jj] > arr[jj + 1])
            {
                swap(jj, jj + 1);
                swapped = true;
            }
        if (swapped == false)
            break;
    }
}
void AllSortsOfThings::insertion()
{
    for (int ii = 1; ii < N; ++ii)
    {
        int key = arr[ii];
        int jj = ii - 1;

        while (jj >= 0 && key < arr[jj])
        {
            arr[jj + 1] = arr[jj];
            --jj;
        }
        arr[jj + 1] = key;
    }
}
void AllSortsOfThings::shell()
{
    for (int gap = N / 2; gap; gap /= 2)
    {
        for (int ii = gap; ii < N; ++ii)
        {
            int key = arr[ii];
            int jj = ii;

            while (jj - gap >= 0 && key < arr[jj - gap])
            {
                arr[jj] = arr[jj - gap];
                jj -= gap;
            }
            arr[jj] = key;
        }
    }
}
int AllSortsOfThings::bsearch(int key, int start, int end)
{
    if (key <= arr[start])
        return start;
    if (key >= arr[end])
        return end;

    int mid = (start + end) / 2;
    if (arr[mid] < key)
        return bsearch(key, mid + 1, end - 1);
    else
        return bsearch(key, start + 1, mid); // not mid - 1.
}
void AllSortsOfThings::shiftRight(int start, int end)
{
    for (int ii = end; ii >= start; --ii)
        arr[ii + 1] = arr[ii];
}
void AllSortsOfThings::insertionBinary()
{
    for (int ii = 1; ii < N; ++ii)
    {
        int key = arr[ii];
        int jj = bsearch(key, 0, ii - 1);
        shiftRight(jj, ii - 1);
        arr[jj] = key;
    }
}
void AllSortsOfThings::selection()
{
    for (int ii = 0; ii < N - 1; ++ii)
    {
        int iimin = ii;
        for (int jj = ii + 1; jj < N; ++jj)
        {
            if (arr[jj] < arr[iimin])
                iimin = jj;
        }
        /*int temp = arr[iimin];
        arr[iimin] = arr[ii];
        arr[ii] = temp;*/
        swap(iimin, ii);
    }
}

int AllSortsOfThings::partition(int start, int end)
{
    int pivot = arr[end];
    int index = start - 1;
    int temp;

    for (int ii = start; ii < end; ++ii)
        if (arr[ii] < pivot)
        {
            ++index;
            swap(ii, index);
            /*temp = arr[ii];
            arr[ii] = arr[index];
            arr[index] = temp;*/
        }
    swap(end, index + 1);

    return index + 1;
}
void AllSortsOfThings::quick(int start, int end)
{
    if (start < end)
    {
        int iipivot = partition(start, end);
        // cout << "pivot = " << iipivot << ", a[pivot] = " << arr[iipivot] << endl;
        quick(start, iipivot - 1);
        quick(iipivot + 1, end);
    }
}
void AllSortsOfThings::quick()
{
    quick(0, N - 1);
}
void AllSortsOfThings::arrayMerge(int start, int mid, int end)
{
    int *tone = new int[MAXSIZE];
    int *ttwo = new int[MAXSIZE];
    int ii, jj, kk;

    for (ii = start; ii <= mid; ++ii)
        tone[ii - start] = arr[ii];
    for (jj = mid + 1; jj <= end; ++jj)
        ttwo[jj - mid - 1] = arr[jj];

    for (ii = 0, jj = 0, kk = start; ii < (mid - start + 1) && jj < (end - mid);)
    {
        if (tone[ii] < ttwo[jj])
            arr[kk++] = tone[ii++];
        else
            arr[kk++] = ttwo[jj++];
    }

    for (; ii < (mid - start + 1); ++ii, ++kk)
        arr[kk] = tone[ii];
    for (; jj < (end - mid); ++jj, ++kk)
        arr[kk] = ttwo[jj];

    delete[] tone;
    delete[] ttwo;
}
void AllSortsOfThings::merge(int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge(start, mid);
        merge(mid + 1, end);
        arrayMerge(start, mid, end);
        // cout << "start=" << start << ", mid=" << mid << ", end=" << end << endl;
        // print();
    }
}
void AllSortsOfThings::merge()
{
    merge(0, N - 1);
}
void AllSortsOfThings::heap()
{
    Heap hh(N, arr - 1); // array index starts from 1.
    hh.build(arr - 1, N, false);
    for (int ii = 0; ii < N; ++ii)
        hh.hide_back(hh.deleteMax());
}
void AllSortsOfThings::bucket()
{
    // forward_list<int> buckets[N];
    vector<int> buckets[N];

    for (int ii = 0; ii < N; ++ii)
    {
        long long x = arr[ii] * N;
        int iibucket = x / MAXVALUE;
        if (iibucket < 0)
            iibucket = N - 1;
        // buckets[iibucket].push_front(arr[ii]);
        buckets[iibucket].push_back(arr[ii]);
    }
    for (int ii = 0; ii < N; ++ii)
    {
        // buckets[ii].sort();
        sort(buckets[ii].begin(), buckets[ii].end());
    }
    int iiarr = 0;
    for (int ii = 0; ii < N; ++ii)
        for (auto e : buckets[ii])
            arr[iiarr++] = e;
}
void AllSortsOfThings::countSort(int exponent)
{
    int *output = new int[N];
    int count[10] = {0};
    int ii;

    for (ii = 0; ii < N; ++ii)
        ++count[(arr[ii] / exponent) % 10];
    for (ii = 1; ii < 10; ++ii)
        count[ii] += count[ii - 1];
    for (ii = N - 1; ii >= 0; --ii)
    {
        output[count[(arr[ii] / exponent) % 10] - 1] = arr[ii];
        --count[(arr[ii] / exponent) % 10];
    }
    for (ii = 0; ii < N; ++ii)
        arr[ii] = output[ii];

    delete[] output;
}
int AllSortsOfThings::maximum()
{
    int max = *arr;
    for (int ii = 1; ii < N; ++ii)
        if (arr[ii] > max)
            max = arr[ii];
    return max;
}
void AllSortsOfThings::radix()
{
    // taken from https://www.geeksforgeeks.org/radix-sort/
    int max = MAXVALUE; // or maximum();
    for (int exponent = 1; max / exponent; exponent *= 10)
        countSort(exponent);
}
void AllSortsOfThings::maxSort()
{
    cout << "You have exhausted the number of sort methods.\n";
}
void AllSortsOfThings::test(FunType fun, bool debug /* = false*/)
{
    init();
    if (debug)
        print();

    auto start = high_resolution_clock::now();
    (this->*funs[fun])();
    //(this->* ((AllSortsOfThings*)this)->AllSortsOfThings::funs[((int)fun)]) ();
    auto stop = high_resolution_clock::now();
    if (debug)
        print();
    cout << "The array is " << (isSorted() ? "" : "NOT ") << "sorted. ";

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by " << funnames[fun] << " = " << duration.count() << " ms" << endl;
}
int AllSortsOfThings::compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
void AllSortsOfThings::testStandard(bool debug /* = false*/)
{
    cout << "-------------------\n";
    init();
    if (debug)
        print();

    auto start = high_resolution_clock::now();
    qsort(arr, N, sizeof(int), compare);
    auto stop = high_resolution_clock::now();
    if (debug)
        print();
    cout << "The array is " << (isSorted() ? "" : "NOT ") << "sorted. ";

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by qsort = " << duration.count() << " ms" << endl;

    init();
    if (debug)
        print();

    start = high_resolution_clock::now();
    sort(arr, arr + N);
    stop = high_resolution_clock::now();
    if (debug)
        print();
    cout << "The array is " << (isSorted() ? "" : "NOT ") << "sorted. ";

    duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by std::sort = " << duration.count() << " ms" << endl;
}
int main()
{
    AllSortsOfThings asot(MAXSIZE);

    /*asot.test(AllSortsOfThings::BubbleSlow);
    asot.test(AllSortsOfThings::Bubble);*/
    asot.test(AllSortsOfThings::BubbleFast);
    asot.test(AllSortsOfThings::Insertion);
    // asot.test(AllSortsOfThings::InsertionBinary);
    asot.test(AllSortsOfThings::Shell);
    asot.test(AllSortsOfThings::Selection);
    asot.test(AllSortsOfThings::Quick);
    asot.test(AllSortsOfThings::Merge);
    asot.test(AllSortsOfThings::Heaps);
    // asot.test(AllSortsOfThings::Bucket);
    asot.test(AllSortsOfThings::Radix);
    // asot.print();

    asot.testStandard();
    return 0;
}