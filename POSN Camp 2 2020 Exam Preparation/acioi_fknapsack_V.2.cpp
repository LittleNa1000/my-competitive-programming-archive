//				1/5/2563 LAST EDITED: 19/6/63
#include<bits/stdc++.h>
using namespace std;
typedef pair<long double,long double> d;
vector<d> v;
long double W,vl[100005],temp,ans,weight,value;
int n;
main(){
	scanf("%Lf %d",&W,&n);
	for(int i=0;i<n;i++){
		//scanf("%lf",&vl[i]);
		cin>>vl[i];
	}
	for(int i=0;i<n;i++){
		//scanf("%lf",&temp);//w[i]
		cin>>temp;
		v.push_back({(long double)vl[i]/(long double)temp,temp});
	}
	sort(v.begin(),v.end());
	for(int i=n-1;i>=0&&W>0;--i){
		weight=v[i].second;    value=v[i].first;  //first=Value/Weight	Second=Weight
		if(W>=weight){
			ans+=(weight*value);
			W-=weight;
		}
		else{
			ans+=(W*value);
			break;
		}
	}
	//printf("%.4Lf",ans);
	cout<<fixed<<setprecision(4)<<ans;
}
