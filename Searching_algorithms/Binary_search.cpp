#include <iostream>
using std::cout;

// Binary search for a given element in a SORTED array
// Returns its index if the element exists or -1 otherwise
int binarySearch(int array[], int x, unsigned size)
{
    // left and right borders of the searching range
    unsigned left = 0, right = size;

    // while the range is not empty
    while (left < right)
    {
        // find the middle of the range
        unsigned middle = (left + right) / 2;

        if (array[middle] == x) // If the element is found
            return middle;      // return its index

        if (array[middle] < x) // If current element is less than X
            left = middle + 1; // cut the left half
        else
            right = middle; // else cut the right half
    }
    return -1; // If we reach that point the element is not into the array
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 8, 9};
    cout << "Function returns the possition of the wanted element in the arr: " << binarySearch(arr, 3, 5);
    return 0;
}
