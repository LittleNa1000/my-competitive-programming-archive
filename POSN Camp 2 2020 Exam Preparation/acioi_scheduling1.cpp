//				12/4/2563
#include<bits/stdc++.h>
using namespace std;
multiset< pair<int,int> > ms;
pair<int,int> p;
int temp,temp1,t,n,decimal,x; // x means time
double wait;
void testcase(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&temp,&temp1);
		ms.insert(make_pair(temp,temp1));
	}
	scanf("%d",&decimal);
	while(!ms.empty()){
		p=*ms.begin();
		if(x<=p.first){
			x=p.first+p.second;
		}
		else{
			wait+=(x-p.first);
			x+=p.second;
		}
		ms.erase(ms.begin());
	}
	printf("%.*lf\n",decimal,wait/n);
}
main(){
	scanf("%d",&t);
	while(t--){
		testcase();
		wait=0;
		x=0;
	}
}
