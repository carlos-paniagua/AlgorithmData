#include <iostream>
using namespace std;

void func(long long N,long long current_num,int used_num, long long &counter){
    if (current_num > N){
        return;
    }

    if(used_num == 0b111){
        counter++;
    }

    func(N,current_num * 10 + 7,used_num|0b001,counter);
    func(N,current_num * 10 + 5,used_num|0b010,counter);
    func(N,current_num * 10 + 3,used_num|0b100,counter);
}   

int main(){
    long long N;
    cin >> N;
    long long counter = 0;

    func(N,0,0,counter);
    cout << counter << endl;
}