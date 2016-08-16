/**********
Hanifi DEMÝREL
150120039

***********/

#include "ArraySort.h"

ArraySort::ArraySort()
{
    //ctor
}

ArraySort::~ArraySort()
{
    //dtor
}




void ArraySort::BubbleSort(int arr[],int N){

    for(int i=0; i<N; i++){
        for(int j=N-1; j>i; j--){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }

}






void ArraySort::Merge(int arr[],int p, int q, int r){



     int i, j, k;
    int n1 = q - p + 1;
    int n2 =  r - q;

    /* temporary arrays */
    int* L=new int[n1];
    int* R=new int[n2];

    /* Copy data to temporary arrays */
    for(i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[q + 1+ j];


    /* Merging*/
    i = 0;
    j = 0;
    k = p;



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
    delete[] R;
    delete[] L;
}

void ArraySort::MergeSort(int arr[],int p, int r){
    if (p < r)
    {
        int q = (r+p)/2;
        MergeSort(arr, p, q);
        MergeSort(arr, q+1, r);
        Merge(arr, p, q, r);
    }
}

