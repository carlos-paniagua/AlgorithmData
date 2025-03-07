#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    Node* next;        // 自己参照ポインタ
    string name;       // ノードの名前

    // コンストラクタの定義
    Node(string name_ = "") : next(NULL), name(name_) {}
};

Node* nil;

void init(){
    nil = new Node();
    nil->next = nil;
}

void printList(){
    Node* cur = nil->next;
    for (; cur != nil; cur = cur->next) {
        cout << cur->name << "->";
    }
    cout << endl;
}

void insert(Node* v, Node* p = nil){
	v->next = p->next;
	p->next = v;
}

int main(){
    init();

    vector<string> names = {"yamamoto","watanabe","ito","takahashi","suzuki","sato"};
    for(int i = 0; i < (int)names.size(); ++i){
        Node* node = new Node(names[i]);

        insert(node);

        cout << "step" << i << " : ";
        printList();
    }
}