//				28/3/2563
#include<bits/stdc++.h>
using namespace std;
int n,q,temp,x;
vector<int> v;
void binary_search(int x){
	int left=0,right=n-1,middle;
	while(left<=right){
		middle=left+(right-left)/2;
		if(v[middle]==x){
			printf("Y");
			return ;
		}
		else if(v[middle]>x){//left
			right=middle-1;
		}
		else{//Right
			left=middle+1;
		}
	}
	printf("N");
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	scanf("%d",&q);
	while(q--){
		scanf("%d",&x);
		binary_search(x);
	}
}
