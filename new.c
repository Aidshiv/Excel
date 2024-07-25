#include<stdio.h>

void floyd(int n,int cam[20][20]);
void printmat(int dist[20][20],int n);
void readmat();

void main()
{
  readmat();
}

void readmat()
{
  int cam[20][20],n,j,i;
   
  printf("enter the number of vertices\n");
   scanf("%d",&n);
  
  printf("enter the cost adjacency matrix\n");
   for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      scanf("%d",&cam[i][j]);

  printf("entered cost adjacency matrix is\n");
  
 for(i=0;i<n;i++)
 {
   printf("\n");
    for(j=0;j<n;j++)
      printf("%d\t",cam[i][j]);
 }

floyd(n,cam);






}

void floyd(int n,int cam[20][20])
{
  int i,k,j,dist[20][20];
  
   for(i=0;i<n;i++)
    for(j=0;j<n;j++)
       dist[i][j]=cam[i][j];

  for(k=0;k<n;k++)
     for(i=0;i<n;i++)
      for(j=0;j<n;j++)
         if(dist[i][j]>dist[i][k]+dist[k][j])
              dist[i][j]=dist[i][k]+dist[k][j];
  printmat(dist,n);

}

void printmat(int dist[20][20],int n)
{ 
   int i,j;
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        if(i==j)
          dist[i][j]=0;

   printf("matrix containing shortest distance between two vertices is\n");
 
    for(i=0;i<n;i++)
   {
    printf("\n");
      for(j=0;j<n;j++)
         printf("%d\t",dist[i][j]);
    }

}




3b)

#include<stdio.h> 
int w[10],p[10],n;
int max(int a,int b)
{
return a>b?a:b;
}

int knap(int i,int m)
{
if(i==n) return w[i]>m?0:p[i]; if(w[i]>m) return knap(i+1,m);
return max(knap(i+1,m),knap(i+1,m-w[i])+p[i]);
}

int main()
{
int m,i,max_profit;
printf("\nEnter the no. of objects:"); 
scanf("%d",&n);
printf("\nEnter the knapsack capacity:"); 
scanf("%d",&m);
printf("\nEnter profit followed by weight:\n"); 
for(i=1; i<=n; i++)
	scanf("%d %d",&p[i],&w[i]); 
max_profit=knap(1,m);

printf("\nMax profit=%d",max_profit); return 0;
}