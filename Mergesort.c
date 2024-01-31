#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int LOW[size1], HIGH[size2];
    for (i = 0; i < size1; i++)
    {
        LOW[i] = a[low + i];
    }
    for (j = 0; j < size2; j++)
    {
        HIGH[j] = a[mid + 1+ j];
    }
    i = 0;
    j = 0;
    k = low;
    while (i < size1 && j < size2)
    {
        if (LOW[i] <= HIGH[j])
        {
            a[k] = LOW[i];
            i++;
            k++;
        }
        else
        {      
            a[k] = HIGH[j];
            j++;
            k++;
        }
}
while (i < size1)
{
    a[k] = LOW[i];
    i++;
    k++;
}
while (j < size2)
{
    a[k] = HIGH[j];
    j++;
    k++;
}
}
void Mergesort(int a[], int low, int high)
{
    if (low < high)
    {
    int mid = low+(high-low)/2;
    Mergesort(a, low, mid);
    Mergesort(a, mid+1, high);
    merge(a, low, mid, high);
    }
}
void print_array(int a[], int size)
{
    int i;
    for(i=0; i < size; i++)
    {
    printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int a[100];
    int n;
    //print("Given array is     ");
    printf("THIS PROGRAM IS TO CALCULATE THE TIME OF THE MERGE SORT\n");
    printf("Enter the no.of elements :\n");
    scanf("%d",&n);
    printf("\n");
    FILE *f=fopen("Sample.txt","r");
    if(f!=NULL)
    {
    for(int i=0;i<n;i++)
    {
        int num;
        if((fscanf(f,"%d",&num))!=EOF)
        {
            a[i]=num;
        }
        else
        {
            printf("FILE CONTENTS OVER");
        }
    }
    }
    else
    {
        printf("File Not Created \n");
    }
    clock_t start,end;
    double time;
    start=clock();
    Mergesort(a, 0, n-1);
    printf("Sorted array is  ");
    print_array(a, n);
    end=clock();
    time=((double)(end-start))/CLOCKS_PER_SEC*1000000;
    printf("Time taken is %lf micro seconds\n",time);
    printf("\n");
    printf("\n"); 
    return 0;
}
