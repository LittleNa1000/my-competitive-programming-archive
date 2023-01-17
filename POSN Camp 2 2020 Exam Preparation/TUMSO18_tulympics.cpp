//				12/5/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<double,short int> p;
priority_queue<p,vector<p>,greater<p> > pq[10];
int score[20005],point[20005],temp,target;
short int n,m,x,t; 
set<int>::reverse_iterator itr;
main(){
	scanf("%hd %hd %hd %hd",&n,&m,&x,&t);
	for(short int i=0;i<n;i++){
		scanf("%d",&point[i]);
	}
	for(short int i=0;i<n;i++){
		for(short int j=0;j<m;j++){
			scanf("%d",&temp);
			pq[j].push({temp+(((double)i)/20001),i});
		}
	}
	for(short int i=0;i<m;i++){
		for(short int j=0;j<n;j++){
			//printf("i=%hd j=%hd 1st=%lf 2nd=%d point[j]=%d\n",i,j,pq[i].top().first,pq[i].top().second,point[j]);
			score[pq[i].top().second]+=point[j];
			pq[i].pop();
		}
	}
	target=score[x-1];
	//for(short int i=0;i<n;i++) printf("i=%d %d\n",i,score[i]);
	//printf("\n");
	set<int> s(score,score+n);
	for(itr=s.rbegin();itr!=s.rend();itr++){
		//printf("i=%d %d\n",distance(s.rbegin(),itr),*itr);
		if(*itr==target){
			printf("%d",distance(s.rbegin(),itr)+1);
			if(t==2) printf(" %d",target);
		}
	}
}
