//				29/8/2563
#include<bits/stdc++.h>
using namespace std;
int t,x,y,z;
int not_one;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&x,&y,&z);
		if(x>=1&&y>=1) y=1;
		if(y>=1&&z>=1) z=1;
		if(z>=1&&x>=1) x=1;
		if(x>1) ++not_one;
		if(y>1) ++not_one;
		if(z>1) ++not_one;
		if(not_one==0) printf("YES\n");
		else printf("NO\n");
		not_one=0;
	}
}
