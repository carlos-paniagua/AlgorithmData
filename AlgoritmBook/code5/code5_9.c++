#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
const long long INF=1LL<<60;

int main(){
    int N;
    cin >> N;

    vector<vector<long long>> c(N+1,vector<long long>(N+1));

    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            cin >> c[i][j];
        }
    }

    vector<long long> dp(N+1,INF);

    dp[0] = 0;

    for(int i =0;i<=N;i++){
        for(int j=0;j<i;j++){
            chmin(dp[i],dp[j]+c[j][i]);
        }   
    }
    cout << dp[N] << endl;
}