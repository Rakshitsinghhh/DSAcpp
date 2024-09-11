#include<iostream>
using namespace std;

int binarySearch(int a[], int key, int start, int end) {
    // Base case: if start exceeds end, the element is not found
    if (start > end) {
        return -1;
    }

    // Calculate mid-point
    int mid = (start + end) / 2;

    // Check if the key is at the mid-point
    if (key == a[mid]) {
        return mid;  // Key found, return the index
    }

    // If key is smaller than mid, search in the left half
    if (key < a[mid]) {
        return binarySearch(a, key, start, mid - 1);
    }

    // If key is greater than mid, search in the right half
    return binarySearch(a, key, mid + 1, end);
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};  // Sorted array
    int size = 5;
    int key = 4;

    // Call binarySearch with start and end index
    int ans = binarySearch(a, key, 0, size - 1);

    // Output the result
    if (ans != -1) {
        cout << "Element found at index " << ans << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
