//				12/8/2563
#include<bits/stdc++.h>
using namespace std;
int n,q,temp,lb;
vector<pair<int,int> > v;
vector<int> p,idx;
main(){
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;++i){
		scanf("%d",&temp);
		if(!i) v.push_back({temp,i});
		else v.push_back({v[i-1].first+temp,i});
	}
	for(int i=n-1;i>0;--i){
		if(v[i].first<=0){
			v.erase(v.begin(),v.begin()+i);
			break;
		}
		if(v[i].first<=v[i-1].first){
			v.erase(v.begin()+i-1);
		}
	}
	//for(int i=0;i<v.size();++i) printf("%d\n",v[i]);
	for(int i=0;i<v.size();++i){
		p.push_back(v[i].first);
		idx.push_back(v[i].second);
	}
	for(int i=0;i<q;++i){
		scanf("%d",&temp);
		lb=upper_bound(p.begin(),p.end(),temp)-p.begin();
		if(lb!=p.size()) printf("%d\n",idx[lb]);
		else printf("%d\n",n);
	}
}
