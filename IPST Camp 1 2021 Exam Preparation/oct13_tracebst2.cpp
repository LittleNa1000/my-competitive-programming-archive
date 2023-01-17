//				19/5/2563 Edited on 9/2/2564
#include<bits/stdc++.h>
using namespace std;
long long int value,mul,mx=INT_MIN,prv;
typedef pair<long long int,int> p;
int n,ans[100005],sl,cnt;
char str[100005][100],temp[100];
vector<p> v;
bool com(const p &a,const p &b){
    return a.first<b.first;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",&str[i]);
		sl=strlen(str[i])-1;
		if(mx<sl){
			mx=sl;
		}
	}
	mx=pow(2,mx);
	for(int i=0;i<n;i++){
		value=0;	mul=mx;		sl=strlen(str[i])-1;
		for(int j=0;j<sl;j++){
			if(str[i][j]=='R'){
				value+=mul;
			}
			else value-=mul;
			mul/=2;	
		}
        //printf("val%lld i%d\n",value,i);
		v.push_back({value,i});
	}
    sort(v.begin(),v.end(),com);
	for(int i=0;i<n;i++){
		//printf("Top: value=%lld idx=%d\n",pq.top().first,pq.top().second);
		if(prv!=v[i].first||!i){
            ++cnt;
        }
        ans[v[i].second]=cnt;
        prv=v[i].first;
	}
	for(int i=0;i<n;i++) printf("%d\n",ans[i]);
}
