#include <iostream>
using std::cout;

// Sequential searching for a given element
// Returns its index if the element exists or -1 otherwise
int search(int array[], int x, unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        if (array[i] == x)
            return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 8, 9};
    cout << "Function returns the possition of the wanted element in the arr: " << search(arr, 4, 5);
    return 0;
}
