#include <iostream>

using namespace std;

void show_array(int* A, int n){
    cout << "[ " << A[0];
    for(int i = 1; i < n; i++)
        cout << ", " << A[i];
    cout << " ]\n";
}

int main(){
    int n = 8, min, temp;
    int A[n] = {4,3,2,10,12,1,5,6};

    for(int i = 0; i < n - 1; i++){
        min = i;

        for(int j = i+1; j < n; j++)
            if(A[j] < A[min])
                min = j;

        if(min != i){
            temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        }
    }

    show_array(A, n);

    return 0;
}
