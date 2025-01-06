#include <iostream>
#include <vector>
using namespace std;

//重み付きの辺を表す構造体 Edge
//隣接頂点番号，重み
struct Edge{
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main(){
    int N,M;
    cin >> N >> M;

    Graph G(N);
    for(int i=0;i<M;++i){
        int a,b;
        long long w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b,w));
        // G[b].push_back(a);
    }
}