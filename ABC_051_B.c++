#include <iostream>
#include <vector>
using namespace std;

int main(){
    int K,S;
    cin >> K >> S;

    int count = 0;

    for(int x = 0;x<=min(K,S);x++){
        for(int y = 0;y<=min(K,S);y++){
            int z = S-x-y;
            if(0<=z && z<=K){
                count++;
            }
        }
    }

    cout << count << endl;
}