#include <iostream>

// Insert an element into array SORTED in ascending order.
// Keeps the array sorted
void insertSorted(int array[], int x, unsigned size)
{
    int i = size;

    // Shifts all elements, greater than X to ensure free position
    while (i > 0 && array[i - 1] > x)
    {
        array[i] = array[i - 1];
        --i;
    }

    // At the end place the element at that position
    array[i] = x;
}

// Insertion sort
void insertionSort(int array[], unsigned size)
{
    for (unsigned i = 1; i < size; ++i)
    {
        insertSorted(array, array[i], i);
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
    insertionSort(arr, size);
    printArr(arr, size);

    return 0;
}
