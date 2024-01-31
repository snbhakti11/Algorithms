#include<stdio.h>
#include<time.h>
#define max 100
void swap(int *a,int *b)
{
    int x=*a;
    *a=*b;
    *b=x;
}
int partition(int arr[],int l,int h)
{
    int pivot = arr[h];
    int i= (l-1);
    for(int j =l;j<=h-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[h]);
    return(i+1);
}
void quicksort(int arr[],int l,int h)
{
    if(l<h)
    {
        int pi = partition(arr,l,h);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,h);
    }
}

int main()
{
    clock_t s,e;
    double cpu_time_used;
    FILE *file = fopen("Sample.txt","r");
    int arr[max];
    int n=0;
    if(file==NULL)
    {
        printf("error in opening file");
        return 1;
    }
    while(n<100 && fscanf(file,"%d",&arr[n])!=EOF )
    {
        n++;
    }
    fclose(file);
    printf("Unsorted array\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    s = clock();

    quicksort(arr,0,n-1); //code

    e = clock();

    printf("\nsorted array\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    cpu_time_used = (((double)(e-s))/CLOCKS_PER_SEC)*1000000;
    printf("\n Time = %f microseconds\n",cpu_time_used);
    return 0;
}
