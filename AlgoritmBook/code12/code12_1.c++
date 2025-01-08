#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int> &a)
{
    int N = (int)a.size();
    for (int i = 1; i < N; i++)
    {
        int v = a[i]; //挿入したい値
        //vを挿入する適切な場所jを探す
        int j = i;
        for (; j > 0; j--)
        {
            //vより大きいものは1つ後ろに移す
            if (a[j - 1] > v)
            {
                a[j] = a[j - 1];
            }
            else
                break;  //v以下になったら止める
        }
        a[j] = v;   //最後にj番目にvを持ってくる
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
    InsertionSort(a);

    // ベクタの要素を出力
    for (int i = 0; i < N; i++)
    {
        if (i > 0) cout << " "; // スペースで区切る
        cout << a[i];
    }
    cout << endl;

    return 0;
}