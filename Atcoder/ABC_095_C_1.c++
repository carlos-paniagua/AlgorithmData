#include <iostream>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin >>A>>B>>C>>X>>Y;

    //ABピザを使わない場合
    //Aピザ1枚 + Bピザ1枚の合計価格(A+B) が、ABピザ2枚の価格(2⋅C) よりも安い場合は、 ABピザを使わないほうが得になります。
    if((A+B)<=(2*C)){
        cout << A*X+B*Y << endl;
    }
    //ABピザを使う場合
    else{
        if(X <= Y){
            cout << min(2*C*Y,2*C*X+B*(Y-X)) << endl;
        }
        else{
            cout << min(2*C*X,2*C*Y+A*(X-Y)) << endl;
        }
    }
}

    // int total = 0;
    // for(int i = 0;i <= X; i++){
    //     for(int j = 0;j <= Y; j++){
    //         total += 2*1600;
    //         total = min(total,)
    //     }
    // }

