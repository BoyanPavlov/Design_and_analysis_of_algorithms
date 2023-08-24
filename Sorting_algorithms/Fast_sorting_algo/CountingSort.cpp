#include <iostream>
#include <vector>

template <class T>
void countingSort(std::vector<T> &arr)
{
    if (arr.empty())
        return;

    T minVal = arr[0];
    T maxVal = arr[0];

    // Find the minimum and maximum values in the array
    for (T num : arr)
    {
        if (num < minVal)
            minVal = num;
        if (num > maxVal)
            maxVal = num;
    }

    int range = maxVal - minVal + 1;
    std::vector<T> countingArray(range, 0);

    // Count the occurrences of each element
    for (T num : arr)
    {
        countingArray[num - minVal]++;
    }

    // Modify countingArray to accumulate counts
    for (int i = 1; i < range; ++i)
    {
        countingArray[i] += countingArray[i - 1];
    }

    std::vector<T> sortedArr(arr.size());

    // Build the sorted array
    for (int i = arr.size() - 1; i >= 0; --i)
    {

        // Actual position Of A Number In Counting Array = arr[i] - minVal;
        // Index which is zero based in the sorted arr = (countingArray[arr[i] - minVal] - 1)

        sortedArr[countingArray[arr[i] - minVal] - 1] = arr[i];
        countingArray[arr[i] - minVal]--;
    }

    // Copy the sorted array back to the original array
    arr = sortedArr;
}

int main()
{
     std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    //std::vector<char> arr = {'g', 'e', 'e', 'k', 's', 'f', 'o', 'r', 'g', 'e', 'e', 'k', 's'};
    // std::vector<int> arr = {3,5,2,4};

    countingSort(arr);

    std::cout << "Sorted array: ";
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
