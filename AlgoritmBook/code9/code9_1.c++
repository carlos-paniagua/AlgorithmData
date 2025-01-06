#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;

int st[MAX];
int top = 0;

void init(){
    top = 0;
}

bool isEmpty(){
    return (top == 0);
}

bool isFull(){
    return (top == MAX);
}

void push(int x){
    if(isFull()){
        cout << "error: stack is full." << endl;
        return ;
    }
    st[top] = x; //xを格納して
    ++top;       //topを進める
}

int pop(){
    if(isEmpty()){
        cout << "error: stack is empty." << endl;
        return -1;
    }
    --top;          //topをデクリメントする
    return st[top]; //topの位置にある要素を返す
}

int main(){
    init();

    push(3);
    push(5);
    push(7);

    cout << pop() << endl;
    cout << pop() << endl;
    
    push(9);
}