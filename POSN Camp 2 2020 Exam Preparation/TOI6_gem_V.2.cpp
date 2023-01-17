//					6/5/2563
#include<bits/stdc++.h>
using namespace std;
char t=5;
bool b;
int temp,temp1,n,m;
int arr[200005];
void testcase(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d %d",&temp,&temp1);
		arr[temp]++;
		arr[temp1]++;
	}
	for(int i=0;i<m/2;i++){
		scanf("%d %d",&temp,&temp1);
		if(arr[temp]>=m-1&&arr[temp]>=m-1){
			b=1;
		}
	}
	if(b) printf("N");
	else printf("Y");
}
main(){
	while(t--){
		b=0;
		for(int i=0;i<200005;i++){
			arr[i]=0;
		}
		testcase();
	}
}
