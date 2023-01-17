//				19/5/2563
#include<bits/stdc++.h>
using namespace std;
long long int value,mul,mx=INT_MIN;
typedef pair<long long int,int> p;
int n,ans[100005],sl;
char str[100005][100],temp[100];
priority_queue<p,vector<p>,greater<p> > pq;
main(){
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
		pq.push({value,i});
	}
	for(int i=0;i<n;i++){
		//printf("Top: value=%lld idx=%d\n",pq.top().first,pq.top().second);
		ans[pq.top().second]=i;
		pq.pop();
	}
	for(int i=0;i<n;i++) printf("%d\n",ans[i]+1);
}
