//				14/4/2563
#include<bits/stdc++.h>
using namespace std;
int arr[1005][1005];
int n,m,q,i_a,j_a,i_b,j_b,temp;
main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&temp);
			if(i==0&&j==0) arr[i][j]=temp;
			else if(i==0) arr[i][j]=arr[i][j-1]+temp;
			else if(j==0) arr[i][j]=arr[i-1][j]+temp;
			else arr[i][j]=arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1]+temp;
		}
	}
	while(q--){
		scanf("%d %d %d %d",&i_a,&j_a,&i_b,&j_b);
		//printf("*");
		if(i_a==1&&j_a==1) printf("%d\n",arr[i_b-1][j_b-1]);
		else if(j_a==1) printf("%d\n",arr[i_b-1][j_b-1]-arr[i_a-2][j_b-1]);
		else if(i_a==1) printf("%d\n",arr[i_b-1][j_b-1]-arr[i_b-1][j_a-2]);  
		else printf("%d\n",arr[i_b-1][j_b-1]-arr[i_b-1][j_a-2]-arr[i_a-2][j_b-1]+arr[i_a-2][j_a-2]);
	}
}
