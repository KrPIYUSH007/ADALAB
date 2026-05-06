#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);

void quickSort(int arr[],int low,int high){
    if (low<high){
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i =low-1;
    int j;
    for (j =low;j<high;j++){
        if (arr[j] <pivot){
            i++;
            swap(&arr[i],&arr[j]);
    }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

int main(){
    int n,i;
    clock_t start,end;
    double cpu_time_used;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d integer elements:\n", n);
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    start=clock();
    quickSort(arr, 0, n - 1);
    end=clock();
    cpu_time_used =((double)(end - start))/CLOCKS_PER_SEC;
    printf("\nSorted elements are:\n");
    for (i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\nTime taken for Quick Sort = %f seconds\n",cpu_time_used);
    return 0;
}

