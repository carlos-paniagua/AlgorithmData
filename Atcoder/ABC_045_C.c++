#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    cin >> S;
    int N = S.size();

    long long res = 0;
    for (int bit = 0;bit < (1 << (N-1));bit++)
    {
        long long tmp = 0;
        for(int i=0;i<N-1;i++){
            tmp = tmp * 10 + S[i] - '0';
            if(bit & (1 << i))
            {
                res += tmp;
                tmp = 0;
            }
        }
        tmp = tmp * 10 + S.back() -'0';
        res = res + tmp;
    }
    cout << res << endl;
}