#include<iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <cstdlib>
#include <limits.h>


using namespace std;

int * loadArray(int size){
    if(size > 0){
        int * array = new int[size];
        for(int i = 0; i<size; i++)
            cin >> array[i];
        return array;

    }
    // TODO !!!
    return NULL;
}

void showArray(int array[], int size){
    for(int i=0;i<size;i++)
        cout << array[i]<<",";
    cout << endl;
}

void insertSort(int array[], int size){
    int temp, j;
    for(int i = size-2; i >= 0; i--){
        temp = array[i];

        for (j = i; j < size-1 && temp > array[j+1]; j++){
            array[j] = array[j+1];
        }
        array[j]=temp;
        showArray(array,size);
    }
}

void bubbleSort(int array[], int size){
    for(int i = size-1; i > 0; i--){
        for (int j = size-1; j > 0; j--){
            if(array[j]<array[j-1]){
                swap(array[j],array[j-1]);
            }
        }
        showArray(array,size);
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
        showArray(array, size);

    }
}



bool isCommand(const string command,const char *mnemonic){
	return command==mnemonic;
}

int main(){
	string line;
	string command;
	int size=0;
	cout << "START" << endl;
	while(true){
		getline(cin,line);
		std::stringstream stream(line);
		stream >> command;
		if(line=="" || command[0]=='#')
		{
			// ignore empty line and comment
			continue;
		}

		// copy line on output with exclamation mark
		cout << "!" << line << endl;;

		// change to uppercase
		command[0]=toupper(command[0]);
		command[1]=toupper(command[1]);

		// read next argument, one int size
		stream >> size;

		// one-argument command
		if(isCommand(command,"HA")){
			cout << "END OF EXECUTION" << endl;
			break;
		}

		if(isCommand(command,"IS")) //*
		{
			int *arr=loadArray(size);
			showArray(arr,size);
			insertSort(arr,size);
			continue;
		}

		if(isCommand(command,"BS")) //*
		{
			int *arr=loadArray(size);
			showArray(arr,size);
			bubbleSort(arr,size);
			continue;
		}

		if(isCommand(command,"MI")) //*
		{
			int *arr=loadArray(size);
			showArray(arr,size);
			mergeSortIter(arr,size);
			continue;
		}

		cout << "wrong argument in test: " << command << endl;
	}
	return 0;
}