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

// Bubble sort
void bubbleSort(int array[], unsigned size)
{
    bool changed = false; // If an element was moved in the last pass
    unsigned sorted = 0;  // The number of already sorted elements
    do
    {
        changed = false; // At the beginning there are no moved elements
        // Then we check all pairs of adjoining elements
        for (unsigned i = size - 1; i > sorted; --i)
        {
            if (array[i] < array[i - 1])
            {                          // and if there is a pair with not proper order
                swap(array, i, i - 1); // swap the elements
                changed = true;        // and mark the move
            }
        }
        ++sorted; // update the size of already sorted part
    } while (changed);
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
    bubbleSort(arr, size);
    printArr(arr, size);

    return 0;
}
