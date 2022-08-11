#include <iostream>

using namespace std;

void show_array(int* A, int n){
    cout << "[ " << A[0];
    for(int i = 1; i < n; i++)
        cout << ", " << A[i];
    cout << " ]\n";
}

int main(){
    int len = 8, key, i;
    int A[len] = {4,3,2,10,12,1,5,6};

    for(int j = 1; j < len; j++){
        key = A[j];

        //algún comentario
        i = j - 1;

        while( i > -1 && A[i] > key ){
            A[i+1] = A[i];
            i = i - 1;
        }

        A[i+1] = key;
    }

    show_array(A, len);

    return 0;
}
