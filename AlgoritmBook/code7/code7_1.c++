#include <iostream>
#include <vector>
using namespace std;

const vector<int> value = {500,100,50,10,5,1};

int main(){
    int X;
    int N = 6;
    vector<int> a(6);
    cin >> X; 
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int result = 0;
    for (int i = 0; i < N; ++i) {
        int add = X / value[i];

        if (add > a[i]){
            add = a[i];
        }

        X -= value[i] * add;
        result += add;
    }
    cout << result << endl;
}