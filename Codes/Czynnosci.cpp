#include<bits/stdc++.h>
using namespace std;

struct CZYNNOSC{
        int num; double a, b;
};

bool SRT(CZYNNOSC A, CZYNNOSC B){
        return (B.a*A.b) < (A.a*B.b);
}
int main(){
        int N; cin >> N;
        vector<CZYNNOSC> VEC(N);
        for(int i = 0; i < N; ++i){
                VEC[i].num = i+1;
                cin >> VEC[i].a >> VEC[i].b;
        }
        sort(VEC.begin(), VEC.end(), SRT);
        for(int i = 0; i < N; ++i){
                cout << VEC[i].num << "\n";
        }
}
