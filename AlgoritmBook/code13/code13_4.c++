#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;

//深さ優先探索
void dfs(const Graph &G, int v)
{
    seen[v] = true; // vを訪問済みにする

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
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        // 有向グラフ
        G[a].push_back(b);
    }

    // 探索
    seen.assign(N, false);
    dfs(G, s);

    if (seen[t])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}