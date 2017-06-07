#include<iostream>
#include <string>
#include <sstream>

using namespace std;


struct Heap{
    int *arr;
    int size;
    int pos;
};

void heapify(Heap& h,int idx)
{
    int idxOfBigger=2*idx+1;
    if(idxOfBigger<h.size)
    {
        if(idxOfBigger+1<h.size && h.arr[idxOfBigger]<h.arr[idxOfBigger+1])
            idxOfBigger++;
        if(h.arr[idx]<h.arr[idxOfBigger])
        {
            swap(h.arr[idx],h.arr[idxOfBigger]);
            heapify(h,idxOfBigger);
        }
    }
}

void init(Heap& h, int size){
    h.arr = new int[size];
    h.size = size;
    h.pos = 0;
}

void heapAdjustment(Heap &h){
    for(int i=(h.size-1)/2;i>=0;i--)
        heapify(h, i);
}

void loadAndMakeHeap(Heap &h, int howMany){
    for(h.pos= 0; h.pos<howMany;h.pos++){
        cin >> h.arr[h.pos];
    }
    heapAdjustment(h);
}

void siftup(Heap &h, int child) {
    int parent = ((child -1) / 2);
    while (h.arr[child] > h.arr[parent]) {
        swap(h.arr[child], h.arr[parent]);
        siftup(h, parent);
    }
}


void add(Heap &h, int value){
    h.pos++;
    h.size = h.pos;
    h.arr[h.size-1] = value;
   siftup(h,(h.size-1));
}


void makeSorted(Heap& h){
    heapAdjustment(h);
    for(int i=h.size-1;i>0;i--){
        swap(h.arr[i],h.arr[0]);
        h.size = i;
        heapify(h,0);
    }
}

void show(Heap& h){
    for(int i=0;i<h.pos;i++)
    {
        cout << h.arr[i] << ",";
    }
    cout << endl;
}


void showBool(bool val){
    if(val)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

bool isCommand(const string command,const char *mnemonic){
    return command==mnemonic;
}

int main(){
    string line;
    string command;
    Heap *heap;
    int currentH=0;
    int value;
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

        // zero-argument command
        if(isCommand(command,"HA")){
            cout << "END OF EXECUTION" << endl;
            break;
        }

        if(isCommand(command,"SH")) //*
        {
            show(heap[currentH]);
            continue;
        }

        if(isCommand(command,"MS")) //*
        {
            makeSorted(heap[currentH]);
            continue;
        }

        // read next argument, one int value
        stream >> value;

        if(isCommand(command,"IN")) //*
        {
            init(heap[currentH],value);
            continue;
        }

        if(isCommand(command,"LD"))
        {
            loadAndMakeHeap(heap[currentH],value);
            continue;
        }

        if(isCommand(command,"AD"))
        {
            add(heap[currentH],value);
            continue;
        }

        if(isCommand(command,"CH"))
        {
            currentH=value;
            continue;
        }

        if(isCommand(command,"GO"))
        {
            heap=new Heap[value];
            continue;
        }

        cout << "wrong argument in test: " << command << endl;
    }
    return 0;
}