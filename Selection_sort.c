//selection sort of random numbers in the file sample with time complexity

#include<stdio.h>
#include<time.h>
int main()
{

    clock_t start,end;
    double time_used;
    int N;
    int arr[101];
    printf("Enter size\n");

    scanf("%d",&N);
    int n=0;

    FILE *file = fopen("sample.txt","r");
    if(fscanf(file,"%d",&arr[n])==EOF)
    {
        printf("Error in opening the file\n");
        return 0;
    }
    while(n<N && fscanf(file,"%d",&arr[n])!=EOF)
    {
        n++;
    }
    fclose(file);
    
    start = clock();
    int minindex;
    for(int i=0;i<n;i++)
    {
        minindex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[minindex]>arr[j])
            {
                minindex=j;
            }
        }
        int temp=arr[minindex];
        arr[minindex]=arr[i];
        arr[i]=temp;
    }
    end = clock();
    for(int i=0;i<N;i++)
    {
        printf(" %d ",arr[i]);
    }
    time_used=((double)(end-start)/CLOCKS_PER_SEC)*1000000;
    printf("\ntime used=%f microseconds \n",time_used);
    return 0;
}