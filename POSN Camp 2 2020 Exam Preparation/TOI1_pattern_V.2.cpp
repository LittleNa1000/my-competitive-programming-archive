//				11/4/2563 Last Update: 19/4/2563
#include<bits/stdc++.h>
using namespace std;
int is_pattern;
int n,temp,temp1,temp2,line;
char arr[50005][75];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		if(line<temp) line=temp;
		arr[temp-1][temp1-1]=1;
		arr[temp-1][temp1-1+temp2]=2;
		//printf("%d %d\n",arr[temp-1][temp1-1],arr[temp-1][temp1-1+temp2]);
	}
	for(int i=0;i<line;i++){
		is_pattern=0;
		for(int j=0;j<70;j++){
			if(arr[i][j]==1) is_pattern++;
			else if(arr[i][j]==2) is_pattern--;
			if(is_pattern>0) printf("x");
			else printf("o");
		}
		printf("\n");
	}
}
