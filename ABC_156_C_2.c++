//O(100⋅N) 

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> x(N);
    double sum = 0;
    for(int i=0;i<N;i++){
        cin >> x[i];
        sum += x[i];
    }

    double mean = sum/N;
    int p1 = floor(mean);
    int p2 = ceil(mean);

    int y1 = 0,y2 = 0;
    for(int j=0;j<N;j++){
        y1 += (x[j]-p1)*(x[j]-p1);
        y2 += (x[j]-p2)*(x[j]-p2);
    }
    cout << min(y1,y2) << endl;
}