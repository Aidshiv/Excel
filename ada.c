*********************selection************

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

************merg************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    srand(time(NULL));
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);
    return 0;
}

************topological************
#include <stdio.h>
int cost[10][10], n, colsum[10];
void cal_colsum()
{
    for (int j = 0; j < n; j++)
    {
        colsum[j] = 0;
        for (int i = 0; i < n; i++)
            colsum[j] += cost[i][j];
    }
}
void source_removal()
{
    int i, j, k, select[10] = {0};
    printf("Topological ordering is:");
    for (i = 0; i < n; i++)
    {
        cal_colsum();
        for (j = 0; j < n; j++)
        {
            if (select[j] == 0 && colsum[j] == 0)
                break;
        }
        printf("%d ", j);
        select[j] = 1;
        for (k = 0; k < n; k++)
            cost[j][k] = 0;
    }
}
void main()
{
    printf("Enter no. of Vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    source_removal();
}

*****************quick*****************
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
*********************prims**************
#include <stdio.h>
int cost[10][10], n;
void prim()
{
    int vt[10] = {0};
    int a = 0, b = 0, min, mincost = 0, ne = 0;
    vt[0] = 1;
    while (ne < n - 1)
    {
        min = 999;
        for (int i = 0; i < n; i++)
        {
            if (vt[i] == 1)
                for (int j = 0; j < n; j++)
                    if (cost[i][j] < min && vt[j] == 0)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
        }
        printf("Edge from vertex %d to vertex %d and the cost %d\n", a, b, min);
        vt[b] = 1;
        ne++;
        mincost += min;
        cost[a][b] = cost[b][a] = 999;
    }
    printf("minimum spanning tree cost is %d", mincost);
}
void main()
{
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    prim();
}
*************krushkal**************

#include <stdio.h>
int cost[10][10], n;
void kruskal()
{
    int par[n];
    int a = 0, b = 0, u = 0, v = 0, min, mincost = 0, ne = 0;
    for (int i = 0; i < n; i++)
        par[i] = -1;

    printf("the minimum spanning tree edges are...");
    while (ne < n - 1)
    {
        min = 999;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
        while (par[u] != -1)
            u = par[u];
        while (par[v] != -1)
            v = par[v];

        if (u != v)
        {
            printf("From vertex %d to vertex %d and the cost = %d\n", a, b, min);
            mincost += min;
            par[v] = u;
            ne++;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Cost of MST = %d", mincost);
}
void main()
{
    printf("Enter the no. of vertices:");
    scanf("%d", &n);
    printf("Enter the cost matrix\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    kruskal();
}
