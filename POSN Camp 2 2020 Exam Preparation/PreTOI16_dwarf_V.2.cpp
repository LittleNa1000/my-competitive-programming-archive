//				8/5/2563
#include<bits/stdc++.h>
using namespace std;
int l,r,n,k,t,arr[200005],ans;
bool visited[200005];
stack<int> st;
bool f(){
	scanf("%d %d",&l,&r);
	l--;	r--;
	if(r-l+1<k) return 0;
	for(int i=l;i<=r;i++){
		//printf("%d:%d ",i,arr[i]);
		if(arr[i]<=k&&!visited[arr[i]]){
			ans++;
			visited[arr[i]]=1;
			st.push(arr[i]);
		}
		if(ans==k) return 1;
	}
	return 0;
}
int main(){
	scanf("%d %d %d",&n,&k,&t);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	while(t--){
		if(f()) printf("YES\n");
		else printf("NO\n");
		ans=0;
		while(!st.empty()){
			visited[st.top()]=0;
			st.pop();
		}
	}
}
