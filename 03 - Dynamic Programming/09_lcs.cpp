#include <iostream>

using namespace std;

bool common(string A, string B){
    bool ans = true;
    int from_position = 0;

    for(int i = 0; i < A.length(); i++){
        int pos = B.find(A[i], from_position);
        if( pos == std::string::npos ){
            ans = false;
            break;
        }
        from_position = pos;
    }

    return ans;
}

int combinations(string cad, string A, string B, int cont){
    if( cont == A.length() )
        if( common(cad, B) ) return cad.length();
        else return 0;
    
    char car = A[cont];
    int res1 = combinations(cad+car, A, B, cont+1);
    int res2 = combinations(cad, A, B, cont+1);

    return max(res1, res2);
}

int LCS(string A, string B){ 
    int res1 = combinations("",A,B,0);
    
    int res2 = combinations("",B,A,0);

    return max(res1, res2);
}

int main(void){
    string S1 = "longest", S2 = "stone";

    cout << "La longitud de la Longest Common Subsequence es: " << LCS(S1, S2) << ".\n";

    return 0;
}