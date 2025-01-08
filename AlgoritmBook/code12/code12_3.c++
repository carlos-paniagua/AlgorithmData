#include <iostream>
#include <vector>
using namespace std;

//配列aの区間[left,right)をソートする
//[left,right)は，left,left+1,...,right-1番目を表す
void QuickSort(vector<int> &a, int left, int right)
{
    if (right - left <= 1)
        return;

    int pivot_index = (left + right) / 2; //適当にここでは中点
    // int pivot_index = left + rand() % (right - left); // leftからright-1の間のランダムなインデックス
    int pivot = a[pivot_index];
    swap(a[pivot_index], a[right - 1]); //pivotと右端をswap

    int i = left;   //iは左詰めされたpivot未満要素の右端を表す
    for (int j = left; j < right - 1; j++)
    {
        if (a[j] < pivot) //pivot未満のものがあったら左端に詰めていく
        {
            swap(a[i++], a[j]);
        }
    }
    swap(a[i], a[right - 1]); //pivotを適切な場所に挿入

    QuickSort(a, left, 1);  //左半分(pivot未満)
    QuickSort(a, i + 1, right);//右半分(pivot以上)
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

    QuickSort(a, 0, N);

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