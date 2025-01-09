#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

using Graph = vector<vector<int>>;

void bfs(const Graph &G, int s)
{
    int N = (int)G.size();

    vector<bool> seen(N, false);

    // 幅優先探索
    queue<int> todo;

    seen[s] = true;
    todo.push(s);

    cout << "BFS Order: ";
    while (!todo.empty())
    {
        int v = todo.front();
        todo.pop();
        cout << v << " "; // 現在の頂点を出力

        for (int x : G[v])
        {
            if (seen[x])
                continue;
            seen[x] = true; 
            todo.push(x);
        }
    }
    cout << endl;
}

void dfs(const Graph &G, int s)
{
    int N = (int)G.size();

    vector<bool> seen(N, false);

    // 深さ優先探索
    stack<int> todo;

    todo.push(s);

    cout << "DFS Order: ";
    while (!todo.empty())
    {
        int v = todo.top();
        todo.pop();

        if (seen[v])
            continue;     // 既に訪問済みの場合はスキップ
        seen[v] = true;   // 訪問済みにする
        cout << v << " "; // 現在の頂点を出力

        for (int x : G[v])
        {
            if (!seen[x])
            todo.push(x);
        }
    }
    cout << endl;
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

    // 開始点を指定
    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    // 幅優先探索
    bfs(G, start);

    // 深さ優先探索
    dfs(G, start);

    return 0;
}