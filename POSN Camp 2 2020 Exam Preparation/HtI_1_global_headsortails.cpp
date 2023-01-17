//				11/8/2563
#include<bits/stdc++.h>
using namespace std;
int n,h,t,maxt,maxh;
string str;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		cin>>str;
		if(str=="Heads"){
			maxt=max(maxt,t);
			t=0;
			++h;
		}
		else{
			maxh=max(maxh,h);
			h=0;
			++t;
		}
	}
	maxt=max(maxt,t);
	maxh=max(maxh,h);
	printf("%d %d",maxh,maxt);
}
