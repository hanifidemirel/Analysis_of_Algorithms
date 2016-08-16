/**********
Hanifi Demirel
150120039

***********/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

int find_max(int* arr,int number_of_lines){
    int max_value=arr[0];
    for(int i=0; i<number_of_lines; i++){
        if(arr[i]>max_value)
            max_value=arr[i];
    }
    return max_value;
}

int part(int* arr, int first, int last){
    int pivot=arr[last];
    int boundary=first;
    for(int i=first ; i<=last-1; i++){
        if(arr[i]<=pivot){
            swap(arr[i], arr[boundary]);
            boundary++;
        }
    }
    swap(arr[boundary], arr[last]);
    return boundary;
}

void quicksort(int* arr, int first, int last){

    if(first < last){
        int boundary = part(arr, first, last);
        quicksort(arr,  first, boundary-1);
        quicksort(arr, boundary+1, last  );
    }

}

void countingsort(int* arr, int number_of_lines){
    int n=number_of_lines;
    int* temp=new int[n];
    int max_value=find_max(arr, n);
    int* counts=new int[max_value+1]();///Initialization to zero

    for(int i=0; i<n; i++){
        int x= arr[i];
        counts[x]=counts[x]+1;

    }
    for(int i=1; i<max_value+1; i++){
        counts[i]=counts[i]+counts[i-1];
    }
    for(int i=n-1; i>=0; i--){
        int x= arr[i];
        counts[x]=counts[x]-1;
        temp[counts[x]]=x;
    }
    for(int i=0; i<n; i++){
        arr[i]=temp[i];
    }

}




void countingsort2(int* arr, int n, int exp) ///For radix sort
{
	int output[n];
	int i, count[10] = {0};

	for (i = 0; i < n; i++)
		count[ (arr[i]/exp)%10 ]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
		count[ (arr[i]/exp)%10 ]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}


void radixsort(int* arr, int n)
{
	int m = find_max(arr, n);


	for (int exp = 1; m/exp > 0; exp *= 10)
		countingsort2(arr, n, exp);
}








int main(int argc, char* argv[])
{

    int* arr;
    int size=0;
    if(argv[2][strlen(argv[2]) - 10]=='0'){ /// Checks according to 10. digit from last
        size=100000;
        arr=new int[size];
    }
    else{
        size=1000;
        arr=new int[size];

    }


    clock_t t=clock();


    ifstream source;
    source.open(argv[2]);
    if(!source.is_open()){
      cout<<"Could not open file.";
      return 0;
    }


    int number_of_lines=0;
    int i=0;
    while(!source.eof()){
        source>>arr[i];
        i++;
        number_of_lines++;
        }
    number_of_lines--;




    if(strcmp(argv[1],"q")==0){
        quicksort(arr,0,number_of_lines-1);
    }
    if(strcmp(argv[1],"c")==0){
        countingsort(arr,number_of_lines);
    }
    if(strcmp(argv[1],"r")==0){
        radixsort(arr, number_of_lines);
    }

    t=clock()-t;
    float elapsed_time=((float)t)/CLOCKS_PER_SEC;
    cout<<"Running time is "<<elapsed_time<<endl;

   source.close();
    return 0;
    }


