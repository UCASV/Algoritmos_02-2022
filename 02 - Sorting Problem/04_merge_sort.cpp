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

int main(){
    int n = 8;
    int A[n] = {5,2,4,7,1,3,2,6};

    merge_sort(A, 0, n-1);

    show_array(A, n);

    return 0;
}
