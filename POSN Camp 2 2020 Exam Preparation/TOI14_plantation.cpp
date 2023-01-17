//				14/8/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long int,long long int> pii;
long long int ans;
long long int n,temp,temp1,t,radius,sd;
vector<pii> point[12];
int idx;
long long int dist(pii a,pii b){
	//if(a==b) return INT_MAX;
	//printf("(%d,%d)-(%d,%d)*%d*\n",a.first,a.second,b.first,b.second,((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));
	return ((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second));
}
bool sby(const pii &a,const pii &b){
	return a.second<b.second;
}
long long int cpop(long long int l,long long int r){
	if(l>=r) return LONG_LONG_MAX;
	if(l==r-1){
		if(point[idx][l].second>point[idx][r].second){
			swap(point[idx][l],point[idx][r]);
		}
		return dist(point[idx][l],point[idx][r]);
	}
	long long int m=(l+r)/2;
	long long int d=min(cpop(l,m),cpop(m+1,r));
	long long int xmid=point[idx][m].first;
	sort(point[idx].begin()+l,point[idx].begin()+r+1,sby);
	for(long long int i=l;i<=r;++i){
		if(abs(xmid-point[idx][i].first)<d){
			for(long long int j=i+1;j<=r&&point[idx][j].second-point[idx][i].second<d;++j){
				//printf("(%d,%d) %d\n",i,j,dist(point[i],point[j]));
				d=min(d,dist(point[idx][i],point[idx][j]));
			}
		}
	}
	return d;
}
main(){
	scanf("%lld",&t);
	for(idx=0;idx<t;++idx){
		
		scanf("%lld %lld %lld",&n,&radius,&sd);
		for(long long int i=0;i<n;++i){
			scanf("%lld %lld",&temp,&temp1);
			point[idx].push_back({temp,temp1});
		}
		sort(point[idx].begin(),point[idx].end());
		ans=cpop(0,n-1);
		//printf("%d %f\n",ans,sqrt((float)ans));
		if(sqrt((float)ans)-2*radius<sd){
			printf("N\n");
		}
		else printf("Y\n");
	}
}
