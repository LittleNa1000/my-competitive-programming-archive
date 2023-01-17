//				7/8/2563
#include<bits/stdc++.h>
using namespace std;
int inarr[500005];
int n,m,op,k;
long long int sum;
vector<int> v;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		inarr[i]=1;
		v.push_back(i); // maybe deque
		sum+=i;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&op);
		if(inarr[op]>0){
			k=v[0];
			v[0]=v[n-1];
			v[n-1]=k;
		}
		else{
			--inarr[v[n-1]];
			sum-=v[n-1];
			v[n-1]=op;
			++inarr[op];
			sum+=op;
		}
		printf("%lld\n",sum);
	}
}
