#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template <class T>
void merge(vector<T> &arr, int left, int mid, int right)
{
    int leftBoundary = mid - left + 1;
    int rightBoundary = right - mid;

    vector<int> leftArr(leftBoundary);
    vector<int> rightArr(rightBoundary);

    for (int i = 0; i < leftBoundary; ++i)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < rightBoundary; ++j)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    int leftIndex = 0, rightIndex = 0, k = left;

    while (leftIndex < leftBoundary && rightIndex < rightBoundary)
    {
        if (leftArr[leftIndex] <= rightArr[rightIndex])
        {
            arr[k] = leftArr[leftIndex];
            ++leftIndex;
        }
        else
        {
            arr[k] = rightArr[rightIndex];
            ++rightIndex;
        }
        ++k;
    }

    while (leftIndex < leftBoundary)
    {
        arr[k] = leftArr[leftIndex];
        ++leftIndex;
        ++k;
    }

    while (rightIndex < rightBoundary)
    {
        arr[k] = rightArr[rightIndex];
        ++rightIndex;
        ++k;
    }
}

template <class T>
void mergeSort(vector<T> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    //vector<char> arr = {'g', 'e', 'e', 'k', 's', 'f', 'o', 'r', 'g', 'e', 'e', 'k', 's'};
    int arrSize = arr.size();

    cout << "Original array: ";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}
