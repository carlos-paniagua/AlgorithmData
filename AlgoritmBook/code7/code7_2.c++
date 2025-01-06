#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 開始時刻と終了時刻をペアとして表現
using Interval = pair<int, int>;

bool cmp(const Interval &a, const Interval &b){
    // 区間を終了時刻の昇順にソート
    return a.second < b.second;
}

int main(){
    int N;
    cin >> N; // 区間の数を入力
    vector<Interval> inter(N); // N個の区間のリスト

    // 終了時刻で区間をソート
    for (int i = 0; i < N; i++) {
        cin >> inter[i].first >> inter[i].second;
    }
    sort(inter.begin(),inter.end(),cmp);

    int res = 0; // 選ばれる区間の数
    int current_end_time = 0; // 現在選んだ区間の終了時刻


    for(int i = 0; i < N; ++i){
        // 開始時刻が現在選んだ区間の終了時刻よりも前の場合
        if(inter[i].first < current_end_time){
            continue;
        }
        ++res;
        current_end_time = inter[i].second; // 現在選んだ区間の終了時刻を更新
    }
    cout << res << endl;
}