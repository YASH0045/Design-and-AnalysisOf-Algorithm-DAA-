#include <iostream>
#include <climits>
using namespace std;

// Structure to store the results
struct Pair {
    int min;
    int max;
};

// Function to find the minimum and maximum value using Divide and Conquer
Pair findMinMax(int arr[], int low, int high) {
    Pair minmax, left, right;
    int mid;

    // If there is only one element
    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            minmax.max = arr[high];
            minmax.min = arr[low];
        } else {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        return minmax;
    }

    // If there are more than two elements
    mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Compare the minimum values of the two halves
    if (left.min < right.min) {
        minmax.min = left.min;
    } else {
        minmax.min = right.min;
    }

    // Compare the maximum values of the two halves
    if (left.max > right.max) {
        minmax.max = left.max;
    } else {
        minmax.max = right.max;
    }

    return minmax;
}

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function and get the result
    Pair minmax = findMinMax(arr, 0, n - 1);

    // Print the results
    cout << "Minimum element is " << minmax.min << endl;
    cout << "Maximum element is " << minmax.max << endl;

    return 0;
}
