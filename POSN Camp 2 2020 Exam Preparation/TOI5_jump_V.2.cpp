//				16/4/2563
#include<bits/stdc++.h>
using namespace std;
queue<unsigned short int> q;
short int n,k;
unsigned short int ans,x;
main(){
	scanf("%hd %hd",&n,&k);
	for(short int i=0;i<n;i++){
		scanf("%hu",&x);
		if(i==0) q.push(x);
		else{
			if(x<=q.front()+k) q.push(x);
			else if(x==q.front()+k){
				q.pop();
				if(ans<q.size()) ans=q.size();
			}
			else{
				q.pop();
				if(ans<q.size()) ans=q.size();
				q.push(x);
			}
		}
		if(i+1==n){
			q.pop();
			if(ans<q.size()) ans=q.size();
		}
	}
	
	printf("%hu",ans);
}
