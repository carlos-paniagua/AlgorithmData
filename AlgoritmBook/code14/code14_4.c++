#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 最大値を表す値
const long long INF = 1LL << 60;

// 辺を表す型，ここでは重みを表す型をlonglongが型とする
struct Edge
{
    int to;      // 隣接頂点番号
    long long w; // 重み

    // コンストラクタ：メンバ初期化リスト
    Edge(int to, long long w) : to(to), w(w) {}
};

// 重み付きグラフを表す型
using Graph = vector<vector<Edge>>;

// 緩和を実施する関数
template <class T>
bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    else
        return false;
}

int main()
{
    // 頂点数，辺数，始点
    int N, M, s;
    cin >> N >> M >> s;

    // グラフ
    Graph G(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }
    cout << "" << endl;

    // ダイクストラ法
    vector<long long> dist(N, INF);
    dist[0] = 0;

    //(d[v],v)のペアを要素としたヒープを作る
    //標準ライブラリの**優先度付きキュー（最大ヒープ）**を提供するテンプレートクラス。
    priority_queue<
        pair<long long, int>, //ヒープの要素の型
        vector<pair<long long, int>>,//内部で使うコンテナ型（デフォルトは vector）
        greater<pair<long long, int>>//優先度の比較基準として「小さい値を優先する」ことを指定
    >
    que;
    que.push(make_pair(dist[s], s));//キューの初期化

    //ダイクストラ法の反復を開始
    while (!que.empty())
    {
        // v:使用済みでない頂点のうちd[v]が最長の頂点
        // d:vに対するキー値
        int v = que.top().second;
        long long d = que.top().first;
        que.pop();

        //d>dist[v]は(d,v)がゴミであることを意味する
        if (d > dist[v])
            continue;

        //頂点vを始点とした各辺を緩和
        for (auto e : G[v])
        {
            if (chmin(dist[e.to], dist[v] + e.w))
            {
                // 更新があるならヒープに新たに挿入
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    // 結果出力
    for (int v = 0; v < N; v++)
    {
        if (dist[v] < INF)
            cout << dist[v] << endl;
        else
            cout << "INF" << endl;
    }
}