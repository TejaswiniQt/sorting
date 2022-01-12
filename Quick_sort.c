/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int partition(int a[],int lb,int ub);
void quick_sort_recursion(int a[],int lb,int ub);
void quick_sort(int a[],int n);
void swap(int *x,int *y);

int main()
{
    int a[20];
    int n,i;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quick_sort(a,n);
    printf("The sorted array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}

int partition(int a[],int lb,int ub)
{
    int pivot,start,end;
    pivot=a[lb];
    start=lb;
    end=ub;
    while(start<end)
    {
    while(a[start]<=pivot)
    {
        start++;
    }
    while(a[end]>pivot)
    {
        end--;
    }
    if(start<end)
    {
        swap(&a[start],&a[end]);
    }
    }
    swap(&a[lb],&a[end]);
    return end;
}



void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void quick_sort(int a[],int n)
{
    quick_sort_recursion(a,0,n-1);
}

void quick_sort_recursion(int a[],int lb,int ub)
{
    int loc;
    if(lb<ub)
    {
        loc=partition(a,lb,ub);
        quick_sort_recursion(a,lb,loc-1);
        quick_sort_recursion(a,loc+1,ub);
        
    }
}
