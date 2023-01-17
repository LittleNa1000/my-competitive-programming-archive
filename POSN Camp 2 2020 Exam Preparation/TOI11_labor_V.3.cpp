//				5/5/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<long int,int> pr;
int n,temp;
long int k;
priority_queue<pr,vector<pr>,greater<pr> > pq;
main(){
	scanf("%d %ld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		pq.push(make_pair(temp,temp));
	}
	while(--k){
		pq.push(make_pair(pq.top().first+pq.top().second,pq.top().second));
		pq.pop();
	}
	printf("%ld",pq.top().first);
}
