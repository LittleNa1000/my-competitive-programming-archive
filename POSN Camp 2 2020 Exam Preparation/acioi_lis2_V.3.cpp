//				14/4/2563 LAST EDITED: 18/6/2563
#include<bits/stdc++.h>
using namespace std;
vector<int> v,seq;
vector<pair<int,int> > h[300005];
int n,ans,ub,temp;
bool b;
void first_seq(int depth,int idx,int k){//maybe start from depth=0 (look at the example & explaination)
	if(depth<0){
		for(int i=seq.size()-1;i>=0;--i){
			printf("%d ",seq[i]);
		}
		b=1;
		return ;
	}
	for(int i=0;i<h[depth].size();i++){
		if(h[depth][i].first<idx&&h[depth][i].second<k){// maybe <=k
			seq.push_back(h[depth][i].second);
			first_seq(depth-1,h[depth][i].first,h[depth][i].second);
			seq.pop_back();
			if(b) return ;
		}
	}
}
void print_vec(vector<pair<int,int> > x){
    for(int i=0;i<x.size();i++) printf("{%d,%d} ",x[i].first,x[i].second);// idx,value
    printf("\n");
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(i==0){
			v.push_back(temp);
			ans++;
			ub=0;
		}
		else{
			ub=lower_bound(v.begin(),v.end(),temp)-v.begin();
			if(ub==v.size()){
				v.push_back(temp);
				ans++;
			}
			else{
				v[ub]=temp;
			}
		}
		h[ub].push_back({i,temp});
	}
	/*for(int i=0;i<ans;i++){
		printf("h[%d]= ",i);
		print_vec(h[i]);
	}*/
	printf("%d\n",ans);
	first_seq(ans-1,n,INT_MAX);
}
/*
11
3 4 -1 5 8 2 3 12 7 9 10
*/
