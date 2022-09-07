#include <iostream>

using namespace std;

void show_array(int* A, int n){
    cout << "[ " << A[0];
    for(int i = 1; i < n; i++)
        cout << ", " << A[i];
    cout << " ]\n";
}

int main(){
    int n = 8, temp;
    int A[n] = {4,3,2,10,12,1,5,6};

    for(int i = 0; i < n-1; i++)
        for(int j = n-1; j > i; j--)
            if(A[j] < A[j-1]){
                temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
            }

    show_array(A, n);

    return 0;
}
