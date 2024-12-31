#include<bits/stdc++.h>
using namespace std;

class Heap{
	public:
		int top();
		void pop();
		bool empty();
		void push(int a);
		int size();
	private:
		vector<int> HeapValue;
};

bool Heap::empty(){
	if(HeapValue.size() == 0){
		return true;
	}
	return false;

}
int Heap::top(){
	if(!HeapValue.size() == 0){
		return HeapValue[HeapValue.size()-1];
	}
	cout << "ERROR" << flush;
	exit(0);
}
void Heap::push(int a){
	HeapValue.push_back(a);
}
void Heap::pop(){
	if(HeapValue.size() == 0){
                cout << "ERROR" << flush;
		exit(0);
        }
	HeapValue.pop_back();
}
int Heap::size(){
	return HeapValue.size();
}
bool inH[50007];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> ARRAY;
	vector<int> OPS;
	Heap H;
	Heap H2;
	for(int i = 0; i < 2*N; ++i){
		int a; cin >> a;
		ARRAY.push_back(a);
	}
	for(int i = 2*N-1; i >= 0; --i){
		H.push(ARRAY[i]);
	}
	while(!H.empty()){
		if(inH[H.top()]){
			if(H2.top()==H.top()){
				int x = H.top();
				H2.pop();
				H.pop();
				inH[x]=false;
			}
			else{
				OPS.push_back(H2.size());
				int x = H2.top();
				int y = H.top();
				H.pop();
				inH[H2.top()] = false;
				H2.pop();
				H.push(x);
				H.push(y);
			}
		}
		else{
			inH[H.top()]=true;
			H2.push(H.top());
			H.pop();
		}
	}
	cout << OPS.size() << "\n";
	for(int i = 0; i < OPS.size(); ++i){
		cout << OPS[i] << "\n";
	}
}
