//			22/3/2563
#include<bits/stdc++.h>
using namespace std;
int m,temp;
long long n,maxworktime;
vector< pair<int,int> > v;
bool find_max_worktime(){
	int mx=0;
	for(int i=0;i<v.size();i++){
		if(mx<v[i].first*v[i].second) mx=v[i].first*v[i].second;
	}
	if(mx<=maxworktime){
		maxworktime=mx;
		return 0;
	}
	return 1;
}
main(){
	scanf("%d %lld",&m,&n);
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		v.push_back(make_pair(temp,0));
	}
	sort(v.begin(),v.end());
	v[0].second=n;
	maxworktime=v[0].first*v[0].second;
	for(long long i=0;i<n;i++){
		v[0].second--;
		if(i<v.size()) v[i].second++;
		else v[1].second++;
		if(find_max_worktime()) break; //0 if lesser 1 if larger compared to previous "maxworktime"
	}
	printf("%lld",maxworktime);
}
