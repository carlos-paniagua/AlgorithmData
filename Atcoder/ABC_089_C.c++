#include <iostream>
using namespace std;

int P[10] = {0,0,0,0,0,0,1,1,1,2};
int Q[10] = {1,1,1,2,2,3,2,2,3,3};
int R[10] = {2,3,4,3,4,4,3,4,4,4};

// P[0], Q[0], R[0] → M, A, R から1人ずつ選ぶ
// P[1], Q[1], R[1] → M, A, C から1人ずつ選ぶ
// P[2], Q[2], R[2] → M, A, H から1人ずつ選ぶ
// P[3], Q[3], R[3] → M, R, C から1人ずつ選ぶ
// P[4], Q[4], R[4] → M, R, H から1人ずつ選ぶ
// P[5], Q[5], R[5] → M, C, H から1人ずつ選ぶ
// P[6], Q[6], R[6] → A, R, C から1人ずつ選ぶ
// P[7], Q[7], R[7] → A, R, H から1人ずつ選ぶ
// P[8], Q[8], R[8] → A, C, H から1人ずつ選ぶ
// P[9], Q[9], R[9] → R, C, H から1人ずつ選ぶ

int main(){
    int N;
    cin >> N;

    string s;
    long long m = 0, a = 0, r = 0, c = 0, h = 0;
    for(int i=0;i<N;i++){
        cin >> s;
        if(s[0] == 'M')m++;
        if(s[0] == 'A')a++;
        if(s[0] == 'R')r++;
        if(s[0] == 'C')c++;
        if(s[0] == 'H')h++;
    }

    long long D[5];
    D[0] = m;
    D[1] = a;
    D[2] = r;
    D[3] = c;
    D[4] = h;

    long long res = 0;
    for(int i=0;i<10;i++){
        res += D[P[i]] * D[Q[i]] * D[R[i]];
    }
    cout << res << endl;
}