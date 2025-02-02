#include <iostream>
#include <vector>
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
    vector<bool> used(N, false);
    vector<long long> dist(N, INF);
    dist[s] = 0;
    for (int iter = 0; iter < N; iter++)
    {
        // 「使用済み」でない頂点のうち,dist値が最小の頂点を探す
        long long min_dist = INF;
        int min_v = -1;
        for (int v = 0; v < N; v++)
        {
            if (!used[v] && dist[v] < min_dist)
            {
                min_dist = dist[v];
                min_v = v;
            }
        }

        // もしそのような頂点が見つからなければ終了する
        if (min_v == -1)
            break;

        //min_vを始点とした確変を緩和する
        for (auto e : G[min_v])
        {
            chmin(dist[e.to], dist[min_v] + e.w);
        }
        //usedを「使用済み」とする
        used[min_v] = true;
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