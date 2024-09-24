#include <iostream>
using namespace std;

void merge(int a[], int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    int temp[high - low + 1]; 
    int index = 0; 

    // Merge the two halves
    while (left <= mid && right <= high) {
        if (a[left] <= a[right]) {
            temp[index++] = a[left++]; 
        } else {
            temp[index++] = a[right++]; 
        }
    }
    

    while (left <= mid) {
        temp[index++] = a[left++];
    }
    

    while (right <= high) {
        temp[index++] = a[right++];
    }


    for (int i = 0; i < index; i++) {
        a[low + i] = temp[i];
    }
}

void mergesort(int a[], int low, int high) {
    if (low < high) { 
        int mid = (low + high) / 2;
        mergesort(a, low, mid); 
        mergesort(a, mid + 1, high); 
        merge(a, low, mid, high); 
    }
}

int main() {
    int a[5] = {5, 2, 3, 1, 4};
    int size = 5;

    mergesort(a, 0, size - 1);

    // Output the sorted array
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
