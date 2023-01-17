//				13/4/2563
#include<bits/stdc++.h>
using namespace std;
priority_queue<long double,vector<long double>,greater<long double> > pq;
int n;
long double temp;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%Lf",&temp);
		pq.push(temp);
	}
	for(int i=0;i<n;i++){
		printf("%.0Lf\n",pq.top());
		pq.pop();
	}
}
