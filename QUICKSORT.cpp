#include <iostream>
using namespace std;

int partition(int a[], int start, int end) {
    int pivot = a[start];
    int count = 0;

    // Count elements smaller than or equal to the pivot
    for (int i = start + 1; i <= end; i++) {
        if (a[i] <= pivot) {
            count++;
        }
    }

    // Place the pivot at its correct position
    int cpvt = start + count;
    swap(a[start], a[cpvt]);

    // Sort the elements on both sides of the pivot
    int i = start, j = end;
    while (i < cpvt && j > cpvt) {
        while (a[i] <= pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i < cpvt && j > cpvt) {
            swap(a[i++], a[j--]);
        }
    }
    return cpvt;
}

void quicksort(int a[], int start, int end) {
    if (start >= end) {
        return;
    }

    // Partition the array
    int p = partition(a, start, end);

    // Sort the left part
    quicksort(a, start, p - 1);

    // Sort the right part
    quicksort(a, p + 1, end);
}

int main() {
    int a[5] = {3, 4, 5, 2, 1};
    int start = 0;
    int end = 4;  // End should be 4 for a 5-element array

    quicksort(a, start, end);

    // Output the sorted array
    for (int i = 0; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
