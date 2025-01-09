#include <iostream>
#include <vector>
using namespace std;

// i番目の頂点を根とする部分木について，ヒープ条件を満たすようにする
// aのうち0番目からN-1番目までの部分a[0:N]について飲み考える
void Heapify(vector<int> &a, int i, int N)
{
    int child1 = i * 2 + 1;//左の子ども
    if (child1 >= N) //子どもがないときは終了
        return;
    
    //子ども同士を比較
    if (child1 + 1 < N && a[child1 + 1] > a[child1])
        child1++;

    if (a[child1] <= a[i])  //逆転がなかったら終了
        return;

    swap(a[i], a[child1]);

    Heapify(a, child1, N);
}

//配列aをソートする
void HeapSort(vector<int> &a)
{
    int N = (int)a.size();

    // ステップ1:a全体をヒープにするフェーズ
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        Heapify(a, i, N);
    }

    // ステップ2:ヒープから1個1個最大値をpopするフェーズ
    for (int i = N - 1; i > 0; i--)
    {
        swap(a[0], a[i]);//ヒープの最大値を左詰めに
        Heapify(a, 0, i);//ヒープサイズはiに
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    HeapSort(a);

    // ベクタの要素を出力
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            cout << " "; // スペースで区切る
        cout << a[i];
    }
    cout << endl;

    return 0;
}