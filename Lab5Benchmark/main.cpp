#include<iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <cstdlib>
#include <limits.h>

using namespace std;

int * randArray(int size){
    int *arr = new int[size];
    for (int i = 0; i<size; i++){
        arr[i] = rand();
    }
    return arr;
}


bool copy_array(int size, int *a1, int *a2, int *a3){

    for (int i = 0; i<size; i++){
        a2[i]=a1[i];
        a3[i]=a1[i];
    }
    return true;
}

/* void showArray(int array[], int size){
    for(int i=0;i<size;i++)
        cout << array[i]<<",";
    cout << endl;
}  */

void insertSort(int array[], int size){
    int temp, j;
    for(int i = size-2; i >= 0; i--){
        temp = array[i];

        for (j = i; j < size-1 && temp > array[j+1]; j++){
            array[j] = array[j+1];
        }
        array[j]=temp;
        //showArray(array,size);
    }
}

void bubbleSort(int array[], int size){
    for(int i = size-1; i > 0; i--){
        for (int j = size-1; j > 0; j--){
            if(array[j]<array[j-1]){
                swap(array[j], array[j-1]);
            }
        }
       // showArray(array,size);
    }
}


void merge(int array[], int start, int center, int end) {
    int *left = new int[center - start + 1];
    int *right = new int[end - center + 1];
    int r = 0, l = 0;

    for (int i = 0; i < center - start; i++) {
        left[i] = array[start + i];
    }
    left[center-start] = INT_MAX;
    for (int i = 0; i < end - center; i++) {
        right[i] = array[center + i];
    }
    right[end-center] = INT_MAX;
    for (int i = start; i < end; i++) {
        if (left[l] < right[r]) {
            array[i] = left[l];
            l++;
        } else{
            array[i] = right[r];
            r++;}
    }
    delete[] left;
    delete[] right;
}

void mergeSortIter(int array[], int size){
    int center, end;
    for (int i=1; i < size; i*=2){
        for (int j = 0; j<size; j+=2*i){
            center = j+i;
            end = j+2*i;
            if (end>size){
                end = size;
                if (center > size){
                    center = size;
                }
            }

            merge(array,j, center, end);
        }
       // showArray(array, size);

    }
}



void test(int size){
    int * insertArray;
    int * bubbleArray = new int[size];
    int * mergeArray = new int[size];
    clock_t start, end;

    cout << "n = " << size << endl;

    insertArray = randArray(size);
    copy_array(size,insertArray, bubbleArray,mergeArray);

    start = clock();
    insertSort(insertArray, size);
    end = clock();

    cout << "Insert: " << "\t" << (long int)(end-start)<< endl;

    start = clock();
    bubbleSort(bubbleArray, size);
    end = clock();

    cout << "Bubble: " << "\t" << (long int)(end-start)<< endl;

    start = clock();
    mergeSortIter(mergeArray, size);
    end = clock();

    cout << "Merge20: " << "\t\t" << (long int)(end-start)<< endl;
}

int main(){
    cout.precision( 15 );
    cout.setf( ios::fixed );

    srand( time( NULL ) );

    test(100);

    test(10000);

    test(100000);

    return 0;
}
