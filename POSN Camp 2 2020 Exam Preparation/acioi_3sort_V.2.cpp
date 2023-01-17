//				21/5/2563
#include<bits/stdc++.h>
using namespace std;
int n,arr[100005],p1,p2,num[5][5],ans;
/*void printtable(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			printf("%d ",num[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}*/
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(arr[i]==1){
			p1++;	p2++;
		}
		else if(arr[i]==2){
			p2++;
		}
	}
	//printf("one:[%d,%d] two:[%d,%d] three:[%d,%d]\nCreate Table:\n",0,p1-1,p1,p2-1,p2,n-1);
	for(int i=0;i<=p1-1;i++){
		if(arr[i]==2) num[1][2]++;
		else if(arr[i]==3) num[1][3]++;
	}
	for(int i=p1;i<=p2-1;i++){
		if(arr[i]==1) num[2][1]++;
		else if(arr[i]==3) num[2][3]++;
	}
	for(int i=p2;i<=n-1;i++){
		if(arr[i]==1) num[3][1]++;
		else if(arr[i]==2) num[3][2]++;
	}
	//printtable();
	while(num[1][2]&&num[2][1]){
		num[1][2]--;	num[2][1]--;
		ans++;
	}
	while(num[1][3]&&num[3][1]){
		num[1][3]--;	num[3][1]--;
		ans++;
	}
	while(num[3][2]&&num[2][3]){
		num[3][2]--;	num[2][3]--;
		ans++;
	}
	while(num[3][1]&&num[1][2]&&num[2][3]){
		num[3][1]--;	num[1][2]--;	num[2][3]--;
		ans+=2;
	}
	while(num[2][1]&&num[1][3]&&num[3][2]){
		num[2][1]--;	num[1][3]--;	num[3][2]--;
		ans+=2;
	}
	//printtable();
	printf("%d",ans);
}
