#include<bits/stdc++.h>
using namespace std;

int main(){
	int maxdzielnik = 0;
	for(int i = 1; i <= 2000000000;){
		int dziel = 0;
		for(int j = 1; j * j <= i; ++j){
			if(i % j == 0){
			if(j*j==i){
				dziel++;
			}
			else{
				dziel+=2;	
			}
			}
		}
		if(dziel > maxdzielnik){
			cout << i << " " << flush;
			maxdzielnik = dziel;
		}
		if(i >= 61261200){
			i+=720;
		}
		else if(i >= 60){
			i+=30;
		}
		else{
			i++;
		}
	}
}
