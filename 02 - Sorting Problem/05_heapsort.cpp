#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

void show_array(int* A, int n){
    cout << "[ " << A[0];
    for(int i = 1; i < n; i++)
        cout << ", " << A[i];
    cout << " ]\n";
}

void swap(int* A, int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int parent(int i){
    return floor( (i-1)/2 );
}

int left(int i){
    return 2*i + 1;
}

int right(int i){
    return 2*i + 2;
}

void max_heapify(int* A, int i, int heap_size){
    int largest, temp;
    int l = left(i);
    int r = right(i);
    if( l < heap_size && A[l] > A[i] )
        largest = l;
    else
        largest = i;
    if( r < heap_size && A[r] > A[largest] )
        largest = r;
    if( largest != i ){
        swap(A, i, largest);
        max_heapify(A, largest, heap_size);
    }
}

void build_max_heap(int* A, int heap_size){
    for(int i = floor(heap_size/2)-1; i >= 0; i--)
        max_heapify(A, i, heap_size);
}

void heapsort(int* A, int n){
    int heap_size = n;
    build_max_heap(A, heap_size);
    for(int i = n-1; i > 0; i--){
        swap(A, 0, i);
        heap_size--;
        max_heapify(A, 0, heap_size);
    }
}

int main(){
    int n = 9;
    int A[n] = {5,13,2,25,7,17,20,8,4};

    heapsort(A, n);

    show_array(A, n);

    return 0;
}
