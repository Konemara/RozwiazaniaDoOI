#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	int POSTERS = 0;
	vector<int> HEAPOFPOSTERS;
	for(int i = 0; i < N; ++i){
		int h, w; cin >> w >> h;
		while(HEAPOFPOSTERS.size() > 0 && HEAPOFPOSTERS[HEAPOFPOSTERS.size()-1] > h){
			HEAPOFPOSTERS.pop_back();
		}
		if(HEAPOFPOSTERS.size()==0){
			HEAPOFPOSTERS.push_back(h);
			POSTERS++;
		}
		else if(HEAPOFPOSTERS[HEAPOFPOSTERS.size()-1] < h){
			HEAPOFPOSTERS.push_back(h);
			POSTERS++;
		}
	}
	cout << POSTERS;
}
