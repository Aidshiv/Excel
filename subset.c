#include<stdio.h>
int x[10], w[10], count, d;
void sum_of_subsets(int s, int k, int rem)
{ 
 x[k] = 1;
 if( s + w[k] == d)
 { 
 //if subset found
 printf("subset = %d\n", ++count);
 for(int i=0 ; i <= k ; i++)
 if ( x[i] == 1)
 printf("%d ",w[i]);
 printf("\n");
 }
 else if ( s + w[k] + w[k+1] <= d )//left tree evaluation
 sum_of_subsets(s+w[k], k+1, rem-w[k]);
 if( ( s+rem-w[k] >= d) && ( s + w[k+1]) <= d)//right tree evaluation
 { 
 x[k] = 0;
 sum_of_subsets(s,k+1,rem-w[k]);
 }
}
int main() 
{
 int sum = 0,n;
 printf("enter no of elements:");
 scanf("%d",&n);
 printf("enter the elements in increasing order:");
 for( int i = 0; i < n ; i++)
 { 
 scanf("%d",&w[i]);
 
sum=sum+w[i];
 }
 printf("eneter the sum:");
 scanf("%d",&d);
 
 if ( ( sum < d ) || ( w[0] > d ) )
 printf("No subset possible\n");
 else
 sum_of_subsets(0,0,sum);
}



Sample Input and Output:
enter no of elements:5
enter the elements in increasing order:1 2 3 4 5
eneter the sum:10
subset = 1
1 2 3 4
subset = 2
1 4 5
subset = 3
2 3 5