*********************selection************

#include <stdio.h>
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
        {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int arr[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    selectionSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

************merg************
#include <stdio.h>
void merge(int arr[], int l, int m, int r)
{
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
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int arr[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

************topological************
#include <stdio.h>
#include <stdlib.h>
#define V 6
void topologicalSortUtil(int graph[V][V], int v, int visited[], int stack[], int *top)
{
    visited[v] = 1;
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
            topologicalSortUtil(graph, i, visited, stack, top);
    }
    stack[(*top)++] = v;
}
void topologicalSort(int graph[V][V])
{
    int visited[V];
    int stack[V];
    int top = 0;
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, stack, &top);
    }
    for (int i = V - 1; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}
int main()
{
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}};
    topologicalSort(graph);
    return 0;
}

*****************quick*****************
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
struct timeval t;
void swap(int *x, int *y);
int partition(int a[], int m, int n);
void quicksort(int a[], int x, int y);
int main()
{
    double start, end;
    int a[100000], i, n;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    srand(time(NULL));
    printf("Array elements are randomly generated\n");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 55;
    }
    gettimeofday(&t, NULL);
    start = t.tv_sec + (t.tv_usec / 1000000.0);
    quicksort(a, 0, n - 1);
    gettimeofday(&t, NULL);
    end = t.tv_sec + (t.tv_usec / 1000000.0);
    printf("The sorted array is - \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    printf("Time taken to sort %d elements is = %lf\n", n, end - start);
    return 0;
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int a[], int m, int n)
{
    int pivot = a[m];
    int i = m;
    int j = n;
    do
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
            swap(&a[i], &a[j]);
    } while (i < j);
    swap(&a[j], &a[m]);
    return j;
}
void quicksort(int a[], int x, int y)
{
    int p;
    if (x < y)
    {
        p = partition(a, x, y);
        quicksort(a, x, p - 1);
        quicksort(a, p + 1, y);
    }
}

*********************prims**************
#include <stdio.h>
#include <limits.h>
#define V_MAX 100
int minKey(int key[], int mstSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
void printMST(int parent[], int n, int graph[V_MAX][V_MAX], int V)
{
    printf("Edge Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d %d \n", parent[i], i, graph[i][parent[i]]);
}
void primMST(int graph[][V_MAX], int V)
{
    int parent[V_MAX];
    int key[V_MAX];
    int mstSet[V_MAX];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, V, graph, V);
}
int main()
{
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    int graph[V_MAX][V_MAX];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }
    printf("Enter the source vertex, destination vertex, and weight for each edge:\n");
    for (int i = 0; i < E; i++)
    {
        int source, dest, weight;
        scanf("%d %d %d", &source, &dest, &weight);
        graph[source][dest] = weight;
        graph[dest][source] = weight;
    }
    primMST(graph, V);
    return 0;
}

*************krushkal**************

#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGES 1000
typedef struct Edge
{
    int src, dest, weight;
} Edge;
typedef struct Graph
{
    int V, E;
    Edge edges[MAX_EDGES];
} Graph;
typedef struct Subset
{
    int parent, rank;
} Subset;
Graph *createGraph(int V, int E)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}
int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int compare(const void *a, const void *b)
{
    Edge *a_edge = (Edge *)a;
    Edge *b_edge = (Edge *)b;
    return a_edge->weight - b_edge->weight;
}
void kruskalMST(Graph *graph)
{
    Edge mst[graph->V];
    int e = 0, i = 0;
    qsort(graph->edges, graph->E, sizeof(Edge), compare);
    Subset *subsets = (Subset *)malloc(graph->V * sizeof(Subset));
    for (int v = 0; v < graph->V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < graph->V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y)
        {
            mst[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i)
    {
        printf("(%d, %d) -> %d\n", mst[i].src, mst[i].dest, mst[i].weight);
    }
}
int main()
{
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    Graph *graph = createGraph(V, E);
    printf("Enter edges and their weights:\n");
    for (int i = 0; i < E; ++i)
    {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }
    kruskalMST(graph);
    return 0;
}
