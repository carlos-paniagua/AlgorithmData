#include <iostream>
#include <vector>
using namespace std;

//配列aの区間[left,right)をソートする
//[left,right)は，left,left+1,...,right-1
void MergeSort(vector<int> &a, int left, int right)
{
    if (right - left == 1)
        return;
    int mid = left + (right-left) / 2;

    MergeSort(a, left, mid);    //左半分[left,mid)をソート
    MergeSort(a, mid, right);   //右半分[mid,right)をソート

    //一旦「左」と「右」のソート結果をコピーしておく（右側は左右反転）
    vector<int> buf;
    for (int i = left; i < mid; i++)
        buf.push_back(a[i]);
    for (int i = right - 1; i >= mid; i--)
        buf.push_back(a[i]);

    //合併する
    int index_left = 0;
    int index_right = (int)buf.size() - 1; //右側の添字
    for (int i = left; i < right; i++)
    {
        //左側採用
        if (buf[index_left] <= buf[index_right])
        {
            a[i] = buf[index_left++];
        }
        //右側採用
        else
        {
            a[i] = buf[index_right--];
        }
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

    MergeSort(a, 0, N);

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