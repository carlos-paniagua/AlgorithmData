#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N; 
    vector<long long> A(N),B(N);

    // AとBの入力を受け取る
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    
    long long sum = 0;
    // 後ろから前に向かって処理
    for (int i = N-1; i >= 0; i--) {
        A[i] += sum; // 今までの累積の影響を加える
        long long amari = A[i] % B[i]; // 現在のA[i]のB[i]での余りを計算
        long long D = 0;
        if(amari != 0){
            D = B[i] - amari; // 余りがある場合、次に押すべきボタンの回数を計算
        }
        sum += D; // 必要な回数だけボタンを押す
    }
    cout << sum << endl;
}