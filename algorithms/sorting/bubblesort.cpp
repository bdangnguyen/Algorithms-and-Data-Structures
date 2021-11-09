#include <iostream>
#include <chrono>
#include <stdlib.h>

// In the worst case, Bubble Sort takes O(n^2).
// n iterations of the first loop, and n-1, n-2, ..., 1 iterations of the
// second loop. This only occurs when the entire list has to be reversed.
// In the best case, this bubble sort takes O(n).
// This only occurs if the array has been sorted already.
void bubbleSort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        bool sortFlag = false;

        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                sortFlag = true;
            }
        }
        
        // If we run through and the array is sorted no more work is needed.
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

    // Dynamic allocation to avoid complaints at compile time.
    int* arr = new int[n];

    std::cout << "Type either 1 or 0 for the sort\n";
    std::cout << "0. An " << n << " length array with random elements\n";
    std::cout << "1. An " << n << " length array counting from " << n << "\n";
    std::cin >> choice;

    if (choice == 0) {
        for (int i = 0; i < n; i++) {
            int randNum = rand();
            arr[i] = randNum;
        }
    } else {
        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
    }

    std::cout << "\nPrinting the first 100 elements...\n";

    int count = 0;
    while (count < 100 && count < n) {
        std::cout << arr[count] << " ";
        count++;
    }

    auto start = std::chrono::system_clock::now();
    bubbleSort(arr, n);
    auto end = std::chrono::system_clock::now();
    elapsed = end - start;

    std::cout << "\nPrinting the sorted first 100 elements...\n";

    count = 0;
    while (count < 100 && count < n) {
        std::cout << arr[count] << " ";
        count++;
    }

    std::cout << "\nTime it took to sort: " << elapsed.count() << "s";

    delete[] arr;
    return 0;
}