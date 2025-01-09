#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;

// 深さ優先探索
void dfs(const Graph &G, int v)
{
    seen[v] = true;                          // vを訪問済みにする
    cout << "Visited vertex: " << v << endl; // 訪問順を出力

    // vから行ける各頂点next_vについて
    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;   // next_vが探索済みならば探索しない
        dfs(G, next_v); // 再帰的に探索
    }
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
        // 有向グラフ
        G[a].push_back(b);
        // 無向グラフ
        //  G[b].push_back(a);
    }

    // 探索
    seen.assign(N, false);
    for (int v = 0; v < N; v++)
    {
        if (seen[v])
            continue;
        cout << "Starting DFS from vertex: " << v << endl;
        dfs(G, v);
    }
}