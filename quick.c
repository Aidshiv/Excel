#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    FILE *fp;
    fp = fopen("numbers.txt", "w");
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int num = rand() % 10000;
        fprintf(fp, "%d ", num);
    }
    fclose(fp);
    int arr[n];
    fp = fopen("numbers.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);
    return 0;
}