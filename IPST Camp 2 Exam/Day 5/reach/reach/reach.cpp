#include "reach.h"
#include<bits/stdc++.h>
using namespace std;
vector<int> V[1005];
void initialize(int N) {
	return;
}

void add_arc(int u, int v) {
	V[u].push_back(v);
	return;
}

bool is_reachable(int u, int v, int t) {
	if(u==0||(u<=t&&t<=v)) return false;
	if(t<u) return true;
	for(int i=0;i<u;++i){
		for(int j=0;j<V[i].size();++j){
			if(v+1<=V[i][j]&&V[i][j]<=t){
				return true;
			}
		}
	}
	return false;
}
/*
6 6
2 4 5 1
2 3 3 5
1 1 4
1 3 5
2 2 3 4
2 2 4 5
*/