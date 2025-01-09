#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

// 入力：グラフGと，探索の始点s
// 出力：sから各頂点への最短路長を表す配列
vector<int> BFS(const Graph &G, int s)
{
    int N = (int)G.size();//頂点数

    vector<int> dist(N, -1);//全頂点を「未訪問」に初期化
    queue<int> que;

    //初期条件（頂点0を初期頂点とする）
    dist[0] = 0;
    que.push(0);//0を橙色頂点にする

    while (!que.empty())
    {
        int v = que.front();//キューから戦闘頂点を取り出す
        que.pop();

        //vから他ドレス頂点をすべて調べる
        for (int x : G[v])
        {
            //すでに発券済みの頂点は探索しない
            if (dist[x] != -1)
                continue;
            //新たな白色頂点xについて距離情報を更新してキューに挿入
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main()
{
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        
        G[a].push_back(b);// 有向グラフ
        G[b].push_back(a);// 無向グラフ
    }

    //頂点0を始点としたBFS
    vector<int> dist = BFS(G, 0);

    //結果出力（各頂点の頂点0からの距離を見る）
    for (int v = 0; v < N; v++)
    {
        cout << v << ": " << dist[v] << endl;
    }
}