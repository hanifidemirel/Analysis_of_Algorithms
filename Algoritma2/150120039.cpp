/**********
Hanifi DEMÝREL
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

/*The function which finds index of max value according to online maximum algorithm */
int online_max(int* score,int k, int last){
        int bestscore=0;
        for(int i=0; i< k; i++){
            if (score[i] > bestscore){
            bestscore = score[i];
            }
        }
        for(int i=k; i<=last; i++){
            if (score[i] > bestscore){
                return i;
            }
        }
    return last;
}


int main(int argc, char* argv[])
{
    try
    {

        /* Checks the arguments of main function */
        if(argc < 3)
            throw "Enter valid values.";

    int N=atoi(argv[1]);
    int k=atoi(argv[2]);
    int best_applicant_for_currentline;


    ifstream source;
    source.open("data.txt");
    if(!source.is_open()){
        throw "Could not open file.";
    }

    ofstream sorted;
    sorted.open("best_applicant.txt");




    clock_t t=clock();
    for(int i=0; i<N; i++){
        int* score=new int[10];

        for(int j=0; j<10; j++){
            string temp;
            source>>temp;

            if(j!=9){
                temp.resize(temp.size()-1); //Deleting coma
            }
            score[j]=atoi(temp.c_str());
        }
        t=clock()-t;
        float elapsed_time=((float)t)/CLOCKS_PER_SEC;

        best_applicant_for_currentline=online_max(score,k,9);

        sorted<<"The index of best applicant for "<<i+1<<".line is " <<best_applicant_for_currentline+1<< ". The score is "<<score[best_applicant_for_currentline] <<", and the running time is "<<elapsed_time<<endl;


        }



    source.close();
    sorted.close();
    return 0;
    }

    catch (const char* e)
    {
        cout<<e<<endl;
        return 0;
    }
}
