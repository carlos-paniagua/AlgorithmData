#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

//ニ部グラフ判定
vector<bool> color;
bool dfs(const Graph &G, int v, int cur = 0)
{
    color[v] = cur;

    // vから行ける各頂点next_vについて
    for (auto next_v : G[v])
    {
        //隣接頂点がすでに色確定していた場合
        if (color[next_v] != -1)
        {
            //同じイラガ隣接した場合は二部グラフではない
            if (color[next_v] == cur)
                return false;
            //色が確定した場合には探索しない
            continue;
        }
        // 隣接頂点の色を変えて，再帰的に探索
        // falseが帰ってきたらfalseを返す
        if (!dfs(G, next_v, 1 - cur))
            return false;
    }
    return true;
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
        G[b].push_back(a);
    }

    // 探索
    color.assign(N, false);
    bool is_bipartite = true;
    for (int v = 0; v < N; v++)
    {
        if (color[v] != -1)
            continue;
        if (!dfs(G, v))
            is_bipartite = false;
    }

    if (is_bipartite)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}