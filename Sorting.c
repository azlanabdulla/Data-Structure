#include <stdio.h>

int step;

void InsertionSort(int arr[], int n) {
    step = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            step++;
        }
        arr[j + 1] = key;
        step++;
    }
}

void SelectionSort(int arr[], int n) {
    step = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            step++;
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void Merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        step++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void MergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}

int Partition(int arr[], int low, int high) {
    int p = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        step++;
        if (arr[j] < p) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int p1 = Partition(arr, low, high);
        QuickSort(arr, low, p1 - 1);
        QuickSort(arr, p1 + 1, high);
    }
}

void CountSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int id = (arr[i] / exp) % 10;
        count[id]++;
        step++;
    }
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int id = (arr[i] / exp) % 10;
        output[count[id] - 1] = arr[i];
        count[id]--;
        step++;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        step++;
    }
}

void RadixSort(int arr[], int n) {
    step = 0;
    int m = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > m)
            m = arr[i];

    for (int exp = 1; m / exp > 0; exp *= 10)
        CountSort(arr, n, exp);
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void displayArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]");
}

int main() {
    int n, arr[50];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int arr1[50], arr2[50], arr3[50], arr4[50], arr5[50];
    copyArray(arr, arr1, n);
    copyArray(arr, arr2, n);
    copyArray(arr, arr3, n);
    copyArray(arr, arr4, n);
    copyArray(arr, arr5, n);

    printf("\nOriginal Array: ");
    displayArray(arr, n);

    // Insertion Sort
    InsertionSort(arr1, n);
    printf("\n\nInsertion Sort: ");
    displayArray(arr1, n);
    printf("\tSteps: %d", step);

    // Selection Sort
    SelectionSort(arr2, n);
    printf("\nSelection Sort: ");
    displayArray(arr2, n);
    printf("\tSteps: %d", step);

    // Merge Sort
    step = 0;
    MergeSort(arr3, 0, n - 1);
    printf("\nMerge Sort: ");
    displayArray(arr3, n);
    printf("\tSteps: %d", step);

    // Quick Sort
    step = 0;
    QuickSort(arr4, 0, n - 1);
    printf("\nQuick Sort: ");
    displayArray(arr4, n);
    printf("\tSteps: %d", step);

    // Radix Sort
    RadixSort(arr5, n);
    printf("\nRadix Sort: ");
    displayArray(arr5, n);
    printf("\tSteps: %d", step);

    printf("\n");
    return 0;
}