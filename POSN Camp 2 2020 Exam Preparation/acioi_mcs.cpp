//				18/4/2563
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int temp,t,n;
int mcs(int left,int right){
	if(left==right) return v[left];
	int mid=(left+right)/2;
	int ls=INT_MIN,rs=INT_MIN;
	t=0;
	for(int i=mid;i>=left;i--){
		t+=v[i];
		ls=max(ls,t);
	}
	t=0;
	for(int i=mid+1;i<=right;i++){
		t+=v[i];
		rs=max(rs,t);
	}
	return max(max(mcs(left,mid),mcs(mid+1,right)),ls+rs);
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		v.push_back(temp);
	}
	printf("%d",mcs(0,n-1));
}
