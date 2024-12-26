#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> vx(N),vy(N),vh(N);
    for(int i=0;i<N;i++){
        cin >> vx[i] >> vy[i] >> vh[i];
    }

    int px, py, ph;
    for (int i = 0; i < N; ++i) {
        if (vh[i] != 0) {
            px = vx[i];
            py = vy[i];
            ph = vh[i];
            break;
        }
    }

    for(int x=0;x<=100;x++){
        for(int y=0;y<=100;y++){
            int tmp  = ph + abs(px-x) + abs(py-y);

            bool valid = true;
            for(int i=0;i<N;i++){
                int h = max(tmp - abs(vx[i]-x) - abs(vy[i]-y),0);

                if(vh[i] != h){
                    valid = false;
                    break;
                }
            }

            if(valid){
                cout << x << " " << y << " " << tmp << endl;
                return 0;
            }
        }
    }
    return 0;
}