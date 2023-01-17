//				5/5/2563 Last Edited: V.3 23/5/2563
#include<bits/stdc++.h>
using namespace std;
int n,k,sz,x,y,z,k2;
set<int> s;
set<int>::reverse_iterator itr;
set<int>::iterator it;
main(){
	scanf("%d %d",&n,&k);
	k2=k;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		//printf("%d %d %d\n",x,y,z);
		if(y>z&&y>x) s.insert(y);
		if(i+1==n&&x>y) s.insert(x);
		z=y;
		y=x;
	}
	if(s.empty()) printf("-1");
	else{
		sz=s.size();
		if(sz<k){
			for(it=s.begin();it!=s.end();it++){
				printf("%d\n",*it);
			}
		}
		else{
			for(itr=s.rbegin();k2--;itr++){
				printf("%d\n",*itr);
			}
		}
	}
}

