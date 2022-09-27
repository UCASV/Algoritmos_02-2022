#include <climits>
#include <math.h>

void swap(int* A, int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void insertion_sort(int* A, int n){
    int key, i;
    for(int j = 1; j < n; j++){
        key = A[j];

        i = j - 1;

        while( i > -1 && A[i] > key ){
            A[i+1] = A[i];
            i--;
        }

        A[i+1] = key;
    }
}

void selection_sort(int* A, int n){
    int min;
    for( int i = 0; i < n-1; i++ ){
        min = i;

        for( int j = i+1; j < n; j++ ){
            if( A[j] < A[min] ){
                min = j;
            }
        }

        if( min != i )
            swap(A, min, i);
    }
}

void bubble_sort(int* A, int n){
    for(int i = 0; i < n-1; i++)
        for(int j = n-1; j > i; j--)
            if( A[j] < A[j-1] )
                swap(A, j, j-1);
}

void merge(int* A, int p, int q, int r){
    int i, j;
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1+1], R[n2+1];
    for(i = 0; i < n1; i++)
        L[i] = A[ p+i ];
    for(j = 0; j < n2; j++)
        R[j] = A[ q+1+j ];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = j = 0;
    for(int k = p; k <= r; k++)
        if( L[i] < R[j] ){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
}

void merge_sort(int* A, int p, int r){
    if( p < r ){
        int q = floor( (p+r)/2 );
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
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

int partition(int* A, int p, int r){
    int x = A[r];
    int i = p - 1;
    for(int j = p; j < r; j++)
        if( A[j] <= x){
            i++;
            swap(A, i, j);
        }
    i++;
    swap(A, i, r);
    return i;
}

void quicksort(int* A, int p, int r){
    if( p < r ){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}
