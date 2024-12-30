#include<bits/stdc++.h>
using namespace std;

const int MAXN= 1007;
int AM[MAXN];

int main(){
        ios_base::sync_with_stdio(0); cin.tie(0);
        int N, M; cin >> N >> M;
        long long am = 0;
        while(M--){
                int a, b; cin >> a >> b;
                AM[a]++;
                AM[b]++;
        }
        for(int i = 1; i <= N; ++i){
                am+=AM[i]*(N-1-AM[i]);
        }
        am/=2;
        cout << N*(N-1)*(N-2)/6 - am;
}
