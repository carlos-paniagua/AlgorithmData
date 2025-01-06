#include <iostream>
#include <vector>
using namespace std;

//Union-Find
struct UnionFind {
    vector<int> par, siz;

    //初期化
    UnionFind(int n) : par(n,-1), siz(n,1) {}

    //根を求める
    int root(int x){
        if(par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    //xとyが同じグループに属するかどうか（根が一致するかどうか）
    bool issame(int x, int y){
        return root(x) == root(y);
    }

    //xを含むグループと，yを含むグループと併合する
    bool unite(int x, int y){
        //x,yをそれぞれ根まで移動する
        x = root(x); y = root(y);

        //すでに同じグループのときは何もしない
        if(x == y)  
            return false;

        //union by size (y側のサイズが小さくなるようにする)
        if(siz[x] < siz[y])
            swap(x, y);

        //yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    
    //xを含むグループのサイズ
    int size(int x){
        return siz[root(x)];
    }  
};

int main(){
    //頂点，変数
    int N,M;
    cin >> N >> M;

    //Union-findを要素数Nで初期化
    UnionFind uf(N);

    //各辺に対する処理
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        uf.unite(a,b);
    }

    //集計
    int res = 0;
    for(int x = 0; x < N; x++){
        if(uf.root(x) == x)
            ++res;
    }

    cout << res << endl;
}