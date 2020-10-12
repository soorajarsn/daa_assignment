#include<stdio.h>
#include<stdlib.h>
typedef struct heap{
    int elements[1000000];
    int heapSize;
}heap;
int left(int index){
    return 2*index+1;
}
int right(int index){
    return 2*index+2;
}
void minHeapify(int* h,int index,int heapSize){
    int l = left(index);
    int r = right(index);
    int min = index;
    if(l < heapSize && h[l] < h[min])
        min = l;
    if(r < heapSize && h[r] < h[min])
        min = r;;
    if(min != index){
        int temp = h[min];
        h[min] = h[index];
        h[index] = temp;
        minHeapify(h,min,heapSize);
    }
}//theta(logn);
void buildMinHeap(int* h,int heapSize){
    for(int i = heapSize/2; i >= 0; i--)
        minHeapify(h,i,heapSize);
}//theta(n)
int extractMin(int* h,int* heapSize){
    if(*heapSize < 1){
        printf("\nError: Heap Underflow");
        exit(0);
    }
    int min = h[0];
    h[0] = h[*heapSize-1];
    *heapSize = *heapSize - 1;
    minHeapify(h,0,*heapSize);
    return min;
}
int main(){
    int h[1000000];
    int k, heapSize;
    printf("\nEnter Number of Elements : ");
    scanf("%d",&heapSize);
    printf("\nEnter the Numbers : ");
    for(int i = 0; i < heapSize; i++)
        scanf("%d",&h[i]);
    printf("\nEnter the value rank of element to be found : ");
    scanf("%d",&k);
    buildMinHeap(h,heapSize);
    int e = -1;
    for(int i = 0; i < k; i++)
        e = extractMin(h,&heapSize);
    printf("\n The kth smallest elements is %d\n",e);
    return 0;
}