#include <iostream>

void swap(int arr[], int pos, int prevPos)
{
    if (&arr[pos] != &arr[prevPos])
    {
        arr[pos] = arr[pos] ^ arr[prevPos];
        arr[prevPos] = arr[pos] ^ arr[prevPos];
        arr[pos] = arr[pos] ^ arr[prevPos];
    }
}

// Find the index of the minimal element in a range
unsigned minFrom(int array[], unsigned from, unsigned to)
{
    unsigned min = from;
    for (unsigned i = from + 1; i < to; ++i)
    {
        if (array[i] < array[min])
            min = i;
    }
    return min;
}

// Selection sort
void selectionSort(int array[], unsigned size)
{
    for (unsigned i = 0; i < size - 1; ++i)
    {
        int m = minFrom(array, i, size);
        swap(array, m, i);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    const int size = 6;
    int arr[size] = {1, 7, 4, 6, 3, 9};
    selectionSort(arr, size);
    printArr(arr, size);

    return 0;
}