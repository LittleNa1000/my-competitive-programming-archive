//				24/6/2563
#include<bits/stdc++.h>
using namespace std;
int maxnum=INT_MIN,ans=INT_MIN,n,m,sum;
int num[105];
double x;
vector<int> qsum;
queue<int> q;
main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		maxnum=max(maxnum,num[i]);
		if(i==0) qsum.push_back(num[i]);
		else qsum.push_back(qsum[i-1]+num[i]);
	}
	if(m>=n) printf("%d",maxnum);
	else{
		for(int i=1;i<m;i++){
			x=qsum[n-1]*((double)i/(double)m);
			//printf("x=%lf\n",x);
			q.push(lower_bound(qsum.begin(),qsum.end(),x)-qsum.begin());  //maybe vector
		}
		for(int i=0;i<n;i++){
			sum+=num[i];
			if(!q.empty()&&i==q.front()){
				//printf("f=%d\n",q.front());
				q.pop();
				//printf("s=%d\n",sum);
				ans=max(ans,sum);
				sum=0;
			}
		}
		//printf("s=%d\n",sum);
		ans=max(ans,sum);
		printf("%d",ans);
	}
	
}
