#include <iostream>
#include <vector>
using namespace std;

const int N = 8;                      // 配列の要素数
const vector<int> a = {3, 5, 8, 10, 14, 17, 21, 39}; // 配列

bool P(int x){
    int target = 15;                  // 探索するターゲット値
    return a[x] >= target;            // 配列のx番目がターゲット以上かを判定
}

int binary_search(){
    int left = -1;            // 探索範囲の下限
    int right = N;   // 探索範囲の上限

    while(right - left > 1){
        int mid = left + (right - left) / 2;
        if(P(mid)){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    return right;
}

int main(){
    int index = binary_search();
    if (index < N && a[index] >= 15) { // インデックスが有効か確認
        cout << "条件を満たす最小インデックス: " << index << endl;
        cout << "条件を満たす値: " << a[index] << endl;
    } else {
        cout << "条件を満たす値が存在しません" << endl;
    }
    return 0;
}