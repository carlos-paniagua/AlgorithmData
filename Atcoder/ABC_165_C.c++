#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// グローバル変数の定義
int N, M, Q;
vector<int> a, b, c, d;

// 再帰的に数列 A を作成し、得点の最大値を求める関数
int solve(vector<int> A) {
    // 最終的な得点を保持する変数
    int res = 0;

    // 数列が長さ N に達したとき、得点を計算する
    if (A.size() == N) {
        // 得点の計算
        for (int i = 0; i < Q; i++) {
            if (A[b[i]] - A[a[i]] == c[i]) {
                res += d[i];
            }
        }
        return res;
    }

    // これから追加する A の要素の開始点（単調増加の条件を考慮）
    int start = (A.empty() ? 1 : A.back());  // Aが空のときは1から、そうでないときは最後の要素から

    // 単調増加の条件を満たすように、startからMまでの数を追加していく
    for (int i = start; i <= M; i++) {
        A.push_back(i);               // 新しい要素を追加
        res = max(res, solve(A));     // 再帰的に解を求め、最大値を記録
        A.pop_back();                 // 戻ってきたら要素を削除
    }
    return res;
}

int main() {
    // 入力の受け取り
    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    
    for (int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;  // 0-indexed に変換
        b[i]--;  // 0-indexed に変換
    }

    // 再帰関数を呼び出して得点の最大値を求める
    int result = solve({});
    cout << result << endl;

    return 0;
}
