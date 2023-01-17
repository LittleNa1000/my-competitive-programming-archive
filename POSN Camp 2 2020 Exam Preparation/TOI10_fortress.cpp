//				25/3/2563
#include<bits/stdc++.h>
using namespace std;
void testcase(){
	long int x,y,ans;
	scanf("%ld %ld",&x,&y);
	ans=y-(x/2-y)+1;
	if(2*y>x||ans<=0) printf("0\n");
	else printf("%ld\n",ans);
}
main(){
	int t=20;
	while(t--){
		testcase();
	}
}
