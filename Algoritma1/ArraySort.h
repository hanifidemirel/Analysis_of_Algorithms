/**********
Hanifi DEMÝREL
150120039

***********/
#ifndef ARRAYSORT_H
#define ARRAYSORT_H


class ArraySort
{
    public:
        void Merge(int arr[],int p, int q, int r);
        void MergeSort(int arr[],int p, int r);
        void BubbleSort(int arr[],int N);
        ArraySort();
        virtual ~ArraySort();

    protected:
    private:
};

#endif
