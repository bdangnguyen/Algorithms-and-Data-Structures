#include <iostream>
#include <chrono>
#include <vector>

// An implementation of bubble sort in C++ using vectors.
// Time Complexity: O(n^2) worst case, O(n) best case
// Space Comlpexity: O(1)
//
// In the worst case, the first for loop takes n iterations, with the second
// loop taking n-1, n-2, ..., 1 iterations. This only occurs when the list is
// reversed. Using the Arithmetic series gives O(n^2).
// In the best case, we simply loop over the entire vector once and verify
// that we have not swapped anything.
// We sort in place, giving O(1) space complexity.
void bubbleSort(std::vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        bool sortFlag = false;

        // Run through the vector. The largest value "bubbles" up the vector.
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;

                sortFlag = true;
            }
        }
        
        // If we run through and the vector is sorted no more work is needed.
        if (sortFlag == false) {
            return;
        }
    }
}

int main() {
    typedef std::chrono::duration<float> float_time;
    float_time elapsed;

    int n;
    bool choice = 0;

    std::cout << "Enter the size of the array you wish to bubble sort: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Enter a valid integer";
        return 1;
    }

    std::vector<int> arr;

    std::cout << "Type either 1 or 0 for the sort\n";
    std::cout << "0. An " << n << " length array with random elements\n";
    std::cout << "1. An " << n << " length array counting from " << n << "\n";
    std::cin >> choice;

    if (choice == 0) {
        for (int i = 0; i < n; i++) {
            int randNum = rand();
            arr.push_back(randNum);
        }
    } else {
        for (int i = 0; i < n; i++) {
            arr.push_back(n - i);
        }
    }

    std::cout << "\nPrinting the first 100 elements...\n";

    int count = 0;
    while (count < 100 && count < n) {
        std::cout << arr[count] << " ";
        count++;
    }

    auto start = std::chrono::system_clock::now();
    bubbleSort(arr);
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