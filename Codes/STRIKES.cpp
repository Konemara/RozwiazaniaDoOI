#include<bits/stdc++.h>
using namespace std;

const int MAXN=500007;
int SYNOWIE[MAXN];
int DIST[MAXN];
int OJCIEC[MAXN];
bool ZAZNACZONY[MAXN];
vector<vector<int>> CONS(MAXN);

void DFS(int NODE, int prev, int dist){
	DIST[NODE]=dist;
	for(int J : CONS[NODE]){
		if(J != prev){
			DFS(J, NODE, dist+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<pair<int, int>> CONNS;
	for(int i = 0; i < N-1; ++i){
		int a, b; cin >> a >> b;
		CONS[a].push_back(b);
		CONS[b].push_back(a);
		CONNS.push_back({a, b});
	}
	DFS(1, 0, 0);
	for(int i = 0; i < N-1; ++i){
		int a = CONNS[i].first; int b = CONNS[i].second;
		if(DIST[a] > DIST[b]){
			SYNOWIE[b]++;
			OJCIEC[a]=b;
		}
		else{
			SYNOWIE[a]++;
			OJCIEC[b]=a;
		}
	}
	int M; cin >> M;
	int ans = 1;
	ZAZNACZONY[0]=true;
	while(M--){
		int c; cin >> c;
		if(c > 0){
				ans+=SYNOWIE[c]+!(ZAZNACZONY[OJCIEC[c]])-1;
				SYNOWIE[OJCIEC[c]]--;
				ZAZNACZONY[c]=true;
		}
		else{
			ans-=SYNOWIE[c*-1]+!(ZAZNACZONY[OJCIEC[c*-1]])-1;
			SYNOWIE[OJCIEC[c*-1]]++;
			ZAZNACZONY[c*-1]=false;
		}
		cout << ans << "\n";
	}
}
