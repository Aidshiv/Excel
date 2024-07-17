#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int arr[], int n) {
   int i, j, min,temp;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
    }
    if(min!=i)
    {
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }          
    }
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; 
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    selectionSort(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);
    return 0;
}	