//O(100⋅N) 

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> x(N);
    for(int i=0;i<N;i++){
        cin >> x[i];
    }

    int y = INT_MAX;
    for(int i=0;i<=100;i++){
        int q = 0;
        for(int j=0;j<N;j++){
            q += (x[j]-i)*(x[j]-i);
        }
        y = min(y,q);
    }
    cout << y << endl;
}