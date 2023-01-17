//			27/3/2563
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq; //front = Max
double ans;
int n,m,temp;
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		pq.push(temp);
	}
	for(int i=0;i<m;i++){
		ans+=pq.top()*((i/n)+1);
		pq.pop();
	}
	printf("%.3f",ans/m);
}
