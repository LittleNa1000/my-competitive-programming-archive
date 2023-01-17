//				12/9/2563
//5 100
//60 48 20 90 49
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int s[100005];
int n,m,cnt;
main(){
	scanf("%d %d",&n,&m);
	m/=2;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		if(a[i]>m*(s[i]+1)) continue;
		if(a[i]+a[i-1]>m*(s[i]+s[i-1]+2)){
		//group left
			a[i]+=a[i-1];
			s[i]=s[i-1]+1;
			cnt++;
		}
		else{
			a[i+1]+=a[i];
			s[i+1]=s[i]+1;
			cnt++;
		}
	}
	for(int i=1;i<=n;++i){printf("%d %d %d\n",i,a[i],s[i]+1);}
	printf("%d",n-cnt);
}
