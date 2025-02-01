#include<bits/stdc++.h>
using namespace std;

map<vector<int>, vector<int>> ZBIORY;
map<pair<int, int>, bool> POL;
const int MAXN = 500007;
int MIASTO[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	if(N == 1){
		cout << "1\n1";
	}
	else{
		for(int i = 1; i <= N; ++i){
			int a; cin >> a;
			vector<int> vec;
			while(a--){
				int b; cin >> b;
				vec.push_back(b);
			}
			vec.push_back(i);
			sort(vec.begin(), vec.end());
			ZBIORY[vec].push_back(i);
		}
		if(ZBIORY.size() == 1){
			cout << 2 << "\n";
			for(int i = 0; i < N-1; ++i){
				cout << 1 << " ";
			}
			cout << 2 << "\n";
			cout << "1 2";
			return 0;
		}
		else{
			cout << ZBIORY.size() << "\n";
		}
		int am = 1;
		for(auto it = ZBIORY.begin(); it != ZBIORY.end(); ++it){
			vector<int> v = it->second;
			for(int i : v){
				MIASTO[i]=am;
			}
			am++;
		}
		for(int i = 1; i <= N; ++i){
			cout << MIASTO[i] << " ";
		}
		cout << "\n";
		am = 1;
		for(auto it = ZBIORY.begin(); it != ZBIORY.end(); ++it){
			vector<int> v = it->first;
			for(int i : v){
				if(MIASTO[i] != am){
					int A = MIASTO[i], B = am;
					if(A > B){
						swap(A, B);
					}
					if(!POL[{A, B}]){
						POL[{A, B}] = true;
						cout << A << " " << B << "\n";
					}
				}
			}	
			am++;
		}
	}
}
