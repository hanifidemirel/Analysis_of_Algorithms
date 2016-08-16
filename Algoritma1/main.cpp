/**********
Hanifi DEMÝREL
150120039

***********/


#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArraySort.h"
#include <ctime>

using namespace std;



int main(int argc, char* argv[])
{


    if(argc < 3)
    {
        printf("Enter valid values.");

        return 0;
    }



    /*Taking the third argument as N */
    long N=atol(argv[2]);

    int *arr=new int[N];
    ifstream source;
    source.open("data.txt");
    /*Taking data from text file to arr array*/
    if(source.is_open()){
        for(int i=0; i<N; i++){
            source>>arr[i];
        }
        source.close();
    }
    else{
        cout<<"Could not open file"<<endl;
        return 0;
    }








    ArraySort array_sort;
    clock_t t=clock();
    /*Choosing the sorting algorithm*/
    if(strcmp(argv[1],"m")==0){
        array_sort.MergeSort(arr,0,N-1);

    }
    if(strcmp(argv[1],"b")==0){
        array_sort.BubbleSort(arr,N-1);
    }

    t=clock()-t;

    float elapsed_time=((float)t)/CLOCKS_PER_SEC;
    cout<<"It took "<<elapsed_time<<"second."<<endl;


    /*Creating and writing to sorted.txt file*/
    ofstream sorted;
    sorted.open("sorted.txt");
    if(sorted.is_open()){
        for(int i=0; i<N; i++){
            sorted<<arr[i]<<endl;
        }
    }
    else{
        cout<<"Could not open file"<<endl;
    }





    delete[] arr;
    return 0;
}
