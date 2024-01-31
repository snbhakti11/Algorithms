#include<stdio.h>
#include <time.h>
int main()
{
     clock_t start, end;
     double cpu_time_used;
     int n=0;
     FILE *file = fopen("sample.txt", "r");
    if (file == NULL) 
    {
        printf("Error in opening file");
        return 1;
    }
    int arr[100];
    while(n<100 && fscanf(file,"%d",&arr[n])!=EOF)
    {
        n++;
    }
    fclose(file);
     start = clock();
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int x;
                x=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=x;
            }
        }
     }
     end = clock();
     printf("SORTED ARRAY : \n");
     for(int i=0;i<n;i++)
     {
         printf("%d ",arr[i]);
     }
     cpu_time_used = (((double) (end - start)) /CLOCKS_PER_SEC)*1000000;
     printf("\nTime  :  %f microseconds\n",cpu_time_used);
     return 0;
}
