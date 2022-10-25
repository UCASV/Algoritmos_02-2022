#include <iostream>

using namespace std;

int fibonacci(int n){
    if(n == 0 || n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "El programa debe ejecutarse con el siguiente formato: fibonacci <posición requerida>\n";
        exit(EXIT_FAILURE);
    }
    int n = atoi(argv[1]);
    if(n <= 0){
        cout << "La posición requerida debe ser mayor a 0.\n";
        exit(EXIT_FAILURE);
    }

    cout << "El n-ésimo término de la sucesión de Fibonacci es: " << fibonacci(n) << "\n";

    return 0;
}