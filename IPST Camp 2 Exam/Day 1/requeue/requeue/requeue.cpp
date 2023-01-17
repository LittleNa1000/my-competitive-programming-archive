#include<bits/stdc++.h>
using namespace std;
int n,cnt,idx;
vector<int> v;
queue<int> low,high;
bool not_sorted(){
	for(int i=0;i<n-1;++i){
		if(v[i]<v[i+1]) return 1;
	}
	return 0;
}
int requeue(vector<int> Q, int k){
	v=Q;
	n=v.size();
	if(k==2){
		while(not_sorted()){
			++cnt;
			while(!low.empty()) low.pop();
			while(!high.empty()) high.pop();
			for(int i=0;i<n;i+=2){
				if(i+1==n){
					high.push(v[i]);
					break;
				}
				high.push(max(v[i],v[i+1]));
				low .push(min(v[i],v[i+1]));
			}
			idx=0;
			while(!(low.empty()&&high.empty())){
				if(low.empty()){
					v[idx]=high.front();
					high.pop();
					++idx;
				}
				else if(high.empty()){
					v[idx]=low.front();
					low.pop();
					++idx;
				}
				else if(low.front()>high.front()){
					v[idx]=low.front();
					low.pop();
					++idx;
				}
				else{
					v[idx]=high.front();
					high.pop();
					++idx;
				}
			}
		}
		return cnt;
	}
	return 0;
}
