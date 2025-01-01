#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;   // 十分大きな値に

int main(){
    // 入力を受け取る
    int N;
    cin >> N; // 風船の数
    vector<long long> h(N), s(N);

    // 各風船の高さと速度（毎秒上昇量）を入力
    for (int i = 0; i < N; i++) 
        cin >> h[i] >> s[i];

    // 二分探索の範囲を初期化。最小ペナルティは0、最大ペナルティは十分大きな値INFに設定
    long long left = 0 ,right = INF;

    // 二分探索を開始。最小の最大ペナルティを求める
    while(right - left > 1){
        // 現在の中間ペナルティ値を計算
        long long mid = (left + right) / 2; 
        
        bool ok = true; // このmidで条件を満たすかどうかを示すフラグ
        vector<long long> t(N,0);// 各風船が撃たれる時刻を格納する配列

        // 各風船について、撃った時の高度を計算
        for(int i = 0;i < N; ++i){
            // midのペナルティで撃つことができるかチェック
            if(mid < h[i]){
                ok = false; // この風船はmidでは撃てない（高度が足りない）
            }
            else{
                t[i] = (mid - h[i]) / s[i];// 撃つことができるなら、撃つための最適な時刻を計算
            }
        }
        // 時刻tを昇順に並べる
        sort(t.begin(),t.end());

        // 並べた時刻に対して、条件を満たすかチェック
        for(int i = 0;i < N; ++i){
            // 撃つ時刻がi番目の風船に対して、i番目以降で撃つべきだという条件
            if(t[i] < i){
                ok = false; // i番目の風船は、撃つべき時間に撃てない
            }
        }

        // 条件を満たす場合、midを下限にして範囲を絞る
        if(ok){
            right = mid; // 条件を満たすので、midは有効な答えの候補
        }
        else{
            left = mid; // 条件を満たさないので、midは無効な値とし、範囲を縮める
        }
    }
    // 二分探索が終了した時点で、最小の最大ペナルティはrightに格納されている
    cout << right << endl;
}