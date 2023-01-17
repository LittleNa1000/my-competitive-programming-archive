//				12/4/2563
#include<bits/stdc++.h>
using namespace std;
//typedef pair<int,int> pr;
vector<int> v,v2;
priority_queue<int> q;
int arr[500005];
int n,temp,temp1,ans,x,lb,p,mx;
//pr p;
void call(int target){
	lb=upper_bound(v2.begin(),v2.end(),target)-v2.begin();
	//printf("%d %d\n",ans,lb-1);
	for(int i=ans+1;i<lb;i++){
		q.push(v[i]);
	}
	if(lb-1>ans) ans=lb-1;
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&temp,&temp1);
		v.push_back(temp+temp1);
		v2.push_back(temp);
	}
	for(int i=0;i<n;i++){
		ans=i;
		call(v[i]);
		while(!q.empty()){
			p=q.top();
			q.pop();
			if(p>mx){
				mx=p;
				call(p);
			}
		}
		printf("%d ",ans+1);
	}
}
