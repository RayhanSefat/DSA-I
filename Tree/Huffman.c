#include<stdio.h>
#include<conio.h>

int heap[101];
int heapSize=0;

int parent(int i){
    return i/2;
}

int leftChild(int i){
    return 2*i;
}

int rightChild(int i){
    return 2*i+1;
}

void swap(int i, int j){
    int temp = heap[i];
    heap[i]=heap[j];
    heap[j]=temp;
}

void display(){
    for(int i=1; i<=heapSize; i++) printf("%d ", heap[i]);
    printf("\n");
}

void heapify(int i){
    int l=leftChild(i);
    int r=rightChild(i);
    int largest=i;

    if(l<heapSize && heap[l]>heap[i]){
        largest = l;
    }
    if(r<heapSize && heap[r]>heap[largest]){
        largest = r;
    }

    if(largest!=i){
        swap(i, largest);
        heapify(largest);
    }
}

void buildMaxHeap(){
    heapSize++;
    for(int i=heapSize/2; i; i--) heapify(i);
    heapSize--;
}

void heapUpdateKey(int i, int key){
    heap[i]=key;
    while(i>1 && heap[parent(i)]<heap[i]){
        swap(i, parent(i));
        i=parent(i);
    }
}

void heapInsert(key){
    heapSize++;
    heap[heapSize]=-1000;
    heapUpdateKey(heapSize, key);
}


int main(){


    return 0;
}
