#include <iostream>

using namespace std;

void show_array(int* A, int n){
    cout << "[ " << A[0];
    for(int i = 1; i < n; i++)
        cout << ", " << A[i];
    cout << " ]\n";
}

int main(){
    int n = 8, key, i;
    int A[n] = {4,3,2,10,12,1,5,6};

    for(int j = 1; j < n; j++){
        key = A[j];

        //algún comentario
        i = j - 1;

        while( i > -1 && A[i] > key ){
            A[i+1] = A[i];
            i--;
        }

        A[i+1] = key;
    }

    show_array(A, n);

    return 0;
}
