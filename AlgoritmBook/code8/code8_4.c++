#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    Node *prev, *next;        // 自己参照ポインタ
    string name;       // ノードの名前

    // コンストラクタの定義
    Node(string name_ = "") : 
    prev(NULL), next(NULL), name(name_) { }
};

Node* nil;

void init(){
    nil = new Node();
    nil->prev = nil;
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
	p->next->prev = v;
    p->next = v;
    v->prev = p;
}

void erase(Node *v){
    if(v == nil){
        return;
    }
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

int main(){
    init();

    vector<string> names = {"yamamoto","watanabe","ito","takahashi","suzuki","sato"};

    Node *watanabe;
    for(int i = 0; i < (int)names.size(); ++i){
        Node* node = new Node(names[i]);

        insert(node);

        if(names[i] == "watanabe"){
            watanabe = node;
        }
    }
    cout << "before: ";
    printList();
    erase(watanabe);
    cout << "after: ";
    printList();
}