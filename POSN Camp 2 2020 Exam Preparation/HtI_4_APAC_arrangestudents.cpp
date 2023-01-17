//				9/8/2563
#include<bits/stdc++.h>
using namespace std;
int p,x,n,tc,temp;
bool cansort(bool is_girl,vector<int> b,vector<int> g){
	if(is_girl) p=b[0];
	else p=g[0];
	for(int i=1;i<n;++i){
		if(is_girl) x=g[i];
		else x=b[i];
		if(x<p) return 0;
		p=x;
		if(is_girl) x=b[i];
		else x=g[i];
		if(x<p) return 0;
		p=x;
	}
	return 1;
}
bool check(vector<int> b,vector<int> g){
	if(b[0]<=g[0]){
		//printf("cansort boy b[0]=%d g[0]=%d\n",b[0],g[0]);
		if(cansort(0,b,g)) return 1;
	}
	if(g[0]<=b[0]){
		//printf("cansort girl\n");
		if(cansort(1,b,g)) return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		vector<int> b,g; // maybe global va & clear()
		for(int i=0;i<n;++i){
			scanf("%d",&temp);
			b.push_back(temp);
		}
		for(int i=0;i<n;++i){
			scanf("%d",&temp);
			g.push_back(temp);
		}
		sort(b.begin(),b.end());
		sort(g.begin(),g.end());
		if(check(b,g)) printf("YES\n");
		else printf("NO\n");
	}
}
