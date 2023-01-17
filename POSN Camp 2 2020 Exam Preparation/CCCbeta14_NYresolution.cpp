//				13/8/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > pipii;
priority_queue<pipii,vector<pipii>,greater<pipii> > pq;
int gf[1005];
int n,x,y,z,cost,fans,month;
int arr[55][1005]; // gf, month
main(){
	scanf("%d %d %d %d",&n,&x,&y,&z);
	for(int i=0;i<=50;++i){
		for(int j=0;j<=n;++j) arr[i][j]=INT_MAX;
	}
	arr[0][0]=0;
	for(int i=0;i<n;++i){
		scanf("%d",&gf[i]);
	}
	pq.push({0,{0,0}});
	while(!pq.empty()){
		cost=pq.top().first;   fans=pq.top().second.first;    month=pq.top().second.second;
		//printf("{%d,{%d,%d}}: ",cost,fans,month);
		pq.pop();
		if(month==n) break;
		if(fans<=gf[month]){
			if(                                    cost+((gf[month]-fans)*x)+gf[month]*y<arr[gf[month]][month+1]){
				//printf("Move on -> {%d,{%d,%d}}\n",cost+((gf[month]-fans)*x)+gf[month]*y,gf[month],month+1);
				pq.push({                          cost+((gf[month]-fans)*x)+gf[month]*y,{gf[month],month+1}});
				arr[gf[month]][month+1]=cost+((gf[month]-fans)*x)+gf[month]*y;
			}
		}
		else{ // maybe mix between DP and for()
			//printf("Split -> ");
			/*if(                         cost+(fans*y)<arr[fans][month+1]){
				pq.push({               cost+(fans*y),{fans,month+1}});
				arr[fans][month+1]=cost+(fans*y);
				printf(" {%d,{%d,%d}} ",cost+(fans*y),fans,month+1);
			}
			if(                         cost+((fans-1)*y)+z<arr[fans-1][month+1]){
				pq.push({               cost+((fans-1)*y)+z,{fans-1,month+1}});
				arr[fans-1][month+1]=cost+((fans-1)*y)+z;
				printf(" {%d,{%d,%d}} ",cost+((fans-1)*y)+z,fans-1,month+1);
			}*/
			for(int i=0;i<=(fans-gf[month]);++i){
				if(cost+((fans-i)*y)+(i*z)<arr[fans-i][month+1]){
					pq.push({cost+((fans-i)*y)+(i*z),{fans-i,month+1}});
					arr[fans-i][month+1]=cost+((fans-i)*y)+(i*z);
					//printf(" {%d,{%d,%d}} ",cost+((fans-i)*y)+(i*z),fans-i,month+1);
				}
			}
			//printf("\n");
		}
	}
	printf("%d",cost);
}

