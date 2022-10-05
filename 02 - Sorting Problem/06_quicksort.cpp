#include <iostream>

using namespace std;

void show_array(int* A, int n){
    cout << "[ " << A[0];
    for(int i = 1; i < n; i++)
        cout << ", " << A[i];
    cout << " ]\n";
}

void swap(int* A, int a, int b){
    if( a != b ){
        int temp = A[a];
        A[a] = A[b];
        A[b] = temp;
    }
}

int partition(int* A, int p, int r){
    int pivot = A[r];
    int tracker = p - 1;
    for(int j = p; j < r; j++)
        if( A[j] <= pivot ){
            tracker++;
            swap(A, j, tracker);
        }
    tracker++;
    swap(A, r, tracker);
    return tracker;
}

void quicksort(int* A, int p, int r){
    if( p < r ){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int main(){
    int n = 8;
    int A[n] = {2,8,7,1,3,5,6,4};

    quicksort(A, 0, n-1);

    show_array(A, n);

    return 0;
}
