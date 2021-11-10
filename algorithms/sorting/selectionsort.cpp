#include <iostream>
#include <chrono>
#include <vector>

// An implementation of Selection Sort in C++ using vectors.
// Time Complexity: O(n^2) worst case, O(n^2) best case
// Space Complexity: O(1)
//
// In the worst case, the first for loop takes n iterations, with the second
// loop taking n-1, n-2, ..., 1 iterations. This only occurs when the list is
// reversed. Using the Arithmetic series gives O(n^2).
// No matter what our vector looks like, we'll always do the same amount of
// comparisons. This gives O(n^2) for the best case, and gives us Theta(n^2).
// We sort in place, giving O(1) space complexity.
void selectionSort(std::vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        // Assume that the minimum is the first element of the unsorted array.
        int min = i;

        // Run through the unsorted array, if we find a new min, take it.
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // If we found a new min, add it to the end of the sorted array.
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    return;
}

int main(int argc, char* argv[]) {
    typedef std::chrono::duration<float> float_time;
    float_time elapsed;

    int n;
    bool choice = 0;

    std::cout << "Enter the size of the array you wish to selection sort: ";
    std::cin >> n;

    std::vector<int> arr;

    if (n <= 0) {
        std::cout << "Enter a valid integer";
        return 1;
    }

    std::cout << "Type either 1 or 0 for the sort\n";
    std::cout << "0. An " << n << " length array with random elements\n";
    std::cout << "1. An " << n << " length array counting from " << n << "\n";
    std::cin >> choice;

    if (choice == 0) {
        for (int i = 0; i < n; i++) {
            arr.push_back(rand());
        }
    } else {
        for (int i = 0; i < n; i++) {
            arr.push_back(n-i);
        }
    }

    std::cout << "\nPrinting the first 100 elements...\n";

    int count = 0;
    while (count < 100 && count < n) {
        std::cout << arr[count] << " ";
        count++;
    }

    auto start = std::chrono::system_clock::now();
    selectionSort(arr);
    auto end = std::chrono::system_clock::now();
    elapsed = end - start;

    std::cout << "\nPrinting the sorted first 100 elements...\n";

    count = 0;
    while (count < 100 && count < n) {
        std::cout << arr[count] << " ";
        count++;
    }

    std::cout << "\nTime it took to sort: " << elapsed.count() << "s";

    return 0;
}