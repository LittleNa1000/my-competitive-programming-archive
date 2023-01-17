//				9/5/2563
#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int maloch,nobita,x,y,temp;
int n,t;
bool testcase(){
	scanf("%d %d %d %d",&maloch,&nobita,&x,&y);
	x--;	y--;	maloch--;	nobita--;
	vector<int> v(arr,arr+n);
	temp=v[x];
	v[x]=v[y];
	v[y]=temp;
	for(int i=0;i<n*2;i++){
		maloch=arr[maloch]-1;
		if(maloch==nobita) return 0;
	}
	return 1;
}
main(){
	scanf("%d %d",&n,&t);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	while(t--){
		if(testcase()) printf("SURVIVE\n");
		else printf("DEAD\n");
	}
}
