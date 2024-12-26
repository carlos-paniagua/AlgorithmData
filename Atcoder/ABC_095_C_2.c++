#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin >>A>>B>>C>>X>>Y;

    // 総費用 = A⋅(X−Z)+B⋅(Y−Z)+2⋅C⋅Z
    // 総費用 = A⋅X+B⋅Y+(−A−B+2⋅C)⋅Z
    int total = INT_MAX;
    for(int Z = 0; Z <= max(X,Y); Z++){
        int cost = A * max(0, X - Z) + B * max(0, Y - Z) + 2 * C * Z;
        total = min(total, cost);
    }
    cout << total << endl;
}

