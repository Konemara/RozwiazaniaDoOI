#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300007;
const int MAXM = 300007;
int MINDEPTH[MAXN];
int POINTER[MAXN];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	int mindepth = 1e9+7;
	int pointer = 0;
	
	for(int i = 0; i < N; ++i){
		MINDEPTH[i+1]=mindepth;
		POINTER[i+1]=pointer;
		int a; cin >> a;
		if(a < mindepth){
			mindepth = a;
			pointer = i+1;
		}
	}
	MINDEPTH[N+1]=mindepth;
        POINTER[N+1]=pointer;
	int LASTSTOP = N+1;
	while(M--){
		if(LASTSTOP == 0){
			break;
		}
		int disk; cin >> disk;
		int pos = LASTSTOP;
		while(MINDEPTH[pos] < disk){
			pos = POINTER[pos];
		}
		LASTSTOP = pos-1;
	}
	cout << LASTSTOP;
}
