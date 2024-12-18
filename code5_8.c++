#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
const int INF=1<<29;

int main(){
    int M,N;
    cin >> M >> N;
    string S,T;
    cin >> S;
    cin >> T;
    //dp という2次元のベクターを宣言
    //(M + 1, vector<int>(N + 1, INF)): M + 1 は、dp の行数 N + 1 は、各行に含まれる列の数 INF は、各要素の初期値
    vector<vector<int>> dp(M+1,vector<int>(N+1,INF));

    dp[0][0] = 0;

    for(int i =0;i<=M;i++){
        for(int j=0;j<=N;j++){
            if(i > 0 && j>0){
                if(S[i-1]==T[j-1]){
                    //そのまま
                    chmin(dp[i][j],dp[i-1][j-1]);
                }
                // 変更
                else{
                    chmin(dp[i][j],dp[i-1][j-1]+1);
                }
            }
            // 削除
            if(i>0){
                chmin(dp[i][j],dp[i-1][j]+1);
            }
            //挿入
            if(j>0){
                chmin(dp[i][j],dp[i][j-1]+1);
            }
        }
    }
    cout << dp[S.size()][T.size()] << endl;
}