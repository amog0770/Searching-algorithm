#include <stdio.h>
#include <stdlib.h>
void array_create(int arr[],int);
void array_display(int arr[],int);
void quicksort(int arr[],int ,int);
int linear_search(int arr[],int,int);
int binary_search(int arr[],int,int);

int main()
{ int ch;int n;int arr[200];int first,last;int value;int binarysearch;

    while(1)
    {   printf("\n==========================================\n");
        printf("1)enter array\n2)display array\n3)quick sort\n4)linear search\n5)binary search");
        printf("\n==========================================\n");
        printf("your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nenter the no of element in array:");
            scanf("%d",&n);
            array_create(arr,n);
            break;

        case 2:
            printf("\narray display:");
            array_display(arr,n);
            break;

        case 3:
            quicksort(arr,0,n-1);
            printf("\nsorted by quick sort");
            break;

        case 4:
            printf("enter the value to be search:");
            scanf("%d",&value);
            int linear=linear_search(arr,n,value);
            if(linear==1)
                printf("\nvalue found in array");
            else
                printf("\nnot found");
                break;

        case 5:
              printf("enter the value to be searched:");
              scanf("%d",&value);
              binarysearch=binary_search(arr,n,value);
              if(binarysearch==0)
                printf("\nnot found");
                break;

        }
    }
    return 0;
}
void array_create(int arr[],int n)
{
     for(int i=0;i<n;i++)
     {
         scanf("%d",&arr[i]);
     }
}

void array_display(int arr[],int n)
{
     for(int i=0;i<n;i++)
     {
         printf("%d ",arr[i]);
     }
}

void quicksort(int arr[],int first,int last)
{
    /*
fst pi           lst
    0  1  2  3  4
    5  8  9  6  3
    i           j
    */
    int i,j,pivot,temp;
    i=first,j=last,pivot=first;
    if(last>first)
    {
        while(j>i)
        {
            while(arr[i]<=arr[pivot] && i<last)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        quicksort(arr,first,j-1);
        quicksort(arr,j+1,last);
    }

}
int linear_search(int arr[],int n,int value)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==value)
            return 1;
    }
    return 0;
}

int binary_search(int arr[],int n,int value)
{
    int i,j,mid;
    i=0;j=n-1;
    while(j>=i){
    mid=(i+j)/2;
    if(value==arr[mid]){
    printf("value found at position:%d",mid+1);
    return 1;
    }
    else if(value>arr[mid])
        i=mid+1;
    else
        j=mid-1;
    }
    return 0;
}



