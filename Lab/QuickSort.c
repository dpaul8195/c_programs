#include<stdio.h>

int partition(int *arr, int s, int e) {
    int x = arr[e]; // Pivot element
    int i = s - 1;
    
    for (int j = s; j < e; j++) {
        if (arr[j] < x) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i+1] and arr[e] (pivot position)
    int temp = arr[i + 1];
    arr[i + 1] = arr[e];
    arr[e] = temp;

    return i + 1; // Return pivot index
}

void QuickSort(int *arr, int s, int e) {
    if (s < e) {
        int p = partition(arr, s, e); // Partition index

        QuickSort(arr, s, p - 1); // Left subarray
        QuickSort(arr, p + 1, e); // Right subarray
    }
}

void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Add a newline for better output
}

void main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;
    QuickSort(arr, 0, n - 1); // Pass correct array bounds
    print(arr, n);
}
