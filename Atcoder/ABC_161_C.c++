#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int K;
    cin >> K;
    vector<int> digits;


    int count = 0;
    for(int i = 0; i < 1000000; i++){
        int tempK = i;
        digits.push_back(0);
        while (tempK  > 0) {
             digits.insert(digits.begin() + 1, K % 10);  // num の一番右の桁を取り出して配列に追加
            tempK  /= 10;  // num を1桁減らす
        }
        digits.push_back(0);

        for (int num : digits) {
            cout << num << " ";
        }
        cout << endl;

        cout << digits.size() << endl;

        for(int i = 1; i < digits.size()-1; i++){
            if (abs(digits[i] - digits [i+1]) == 1 && abs(digits[i - 1] - digits[i]) == 1){
                count++;
            }
            else{
                break;
            }
            
        }
        digits.clear();
    }
}