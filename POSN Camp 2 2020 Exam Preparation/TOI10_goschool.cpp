//				25/4/2563
#include<bits/stdc++.h>
using namespace std;
long long int arr[55][55];
short int m,n,k,x,y;
main(){
	scanf("%hd %hd %hd",&m,&n,&k);
	arr[n-2][0]=1;
	arr[n-1][1]=1;
	for(short int i=0;i<k;i++){
		scanf("%hd %hd",&x,&y);
		arr[n-y][x-1]=-1;
	}
	for(short int i=n-1;i>=0;i--){
		for(short int j=0;j<m;j++){
			if(arr[i][j]!=-1){
				if(i<n-1&&arr[i+1][j]!=-1) arr[i][j]+=arr[i+1][j];
				if(j>0&&arr[i][j-1]!=-1) arr[i][j]+=arr[i][j-1];
			}
		}
	}
	/*for(short int i=0;i<n;i++){
		for(short int j=0;j<m;j++) printf("%lld ",arr[i][j]);
		printf("\n");
	}*/
	printf("%lld",arr[0][m-1]);
}
