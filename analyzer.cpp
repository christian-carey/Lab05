/* Christian Carey
 * Lab 05
 * Reconstruction of Lab04 in C++, pushed to Git
 */
#include <iostream>
#include "StringData.h"


// Linear Search
int linearSearch(std::vector<std::string> container, const std::string& element)
{
    for (int index = 0; index < container.size(); index++)
    {
        if (element == container[index])
            return index;
    }
    return -1;
}

// Binary Search
int binarySearch(std::vector<std::string> container, const std::string& element)
{
    // Check base case
    int max = container.size() - 1;
    int min = 0;

    while (true)
    {
        if (max >= min)
        {
            int mid = ((max - min) / 2) + min;

            if (container[mid] == element)  // If element is found, return it
                return mid;

            else if (container[mid] < element)  // If element is bigger than mid, shift min bound to right above mid
            {
                min = mid + 1;
                continue;
            }

            else  // Otherwise the element must be smaller than mid, so shift max bound to right below mid
            {
                max = mid - 1;
                continue;
            }
        }
        else  // If max and min are equal, then the binary search is exhausted and the element is not present.
            return -1;
    }
}

// Main
int main()
{
    // Access the data:
    std::vector<std::string> data = getStringData();
    
    // Time keeping variables:
    long long timeBegin;
    long long timeEnd;
    long long runtime;
    
    int index;

    // Search for "not_here" using both algorithms
    timeBegin = systemTimeNanoseconds();
    index = linearSearch(data, "not_here");
    timeEnd = systemTimeNanoseconds();
    runtime = (timeEnd - timeBegin);
    std::cout << "Linear search for \"not_here\" found at index " << index << " in " << runtime << " nanoseconds." << std::endl;

    timeBegin = systemTimeNanoseconds();
    index = binarySearch(data, "not_here");
    timeEnd = systemTimeNanoseconds();
    runtime = timeEnd - timeBegin;
    std::cout << "Binary search for \"not_here\" found at index " << index << " in " << runtime << " nanoseconds.\n" << std::endl;

    // Search for "mzzzz" using both algorithms.
    timeBegin = systemTimeNanoseconds();
    index = linearSearch(data, "mzzzz");
    timeEnd = systemTimeNanoseconds();
    runtime = timeEnd - timeBegin;
    std::cout << "Linear search for \"mzzzz\" found at index " << index << " in " << runtime << " nanoseconds." << std::endl;

    timeBegin = systemTimeNanoseconds();
    index = binarySearch(data, "mzzzz");
    timeEnd = systemTimeNanoseconds();
    runtime = timeEnd - timeBegin;
    std::cout << "Binary search for \"mzzzz\" found at index " << index << " in " << runtime << " nanoseconds.\n" << std::endl;

    // Search for "aaaaa" using both algorithms.
    timeBegin = systemTimeNanoseconds();
    index = linearSearch(data, "aaaaa");
    timeEnd = systemTimeNanoseconds();
    runtime = timeEnd - timeBegin;
    std::cout << "Linear search for \"aaaaa\" found at index " << index << " in " << runtime << " nanoseconds." << std::endl;

    timeBegin = systemTimeNanoseconds();
    index = binarySearch(data, "aaaaa");
    timeEnd = systemTimeNanoseconds();
    runtime = timeEnd - timeBegin;
    std::cout << "Binary search for \"aaaaa\" found at index " << index << " in " << runtime << " nanoseconds." << std::endl;

    return 0;
}

