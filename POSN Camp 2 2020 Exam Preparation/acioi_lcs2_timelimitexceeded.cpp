//				21/4/2563
#include<bits/stdc++.h>
using namespace std;
int lcs[1005][1005],n;
char str1[1005],str2[1005];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>str1[i];
	}
	for(int i=0;i<n;i++){
		cin>>str2[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(str1[i]==str2[j]&&(i==0||j==0)) lcs[i][j]=1;
			else if(i==0&&j>0) lcs[i][j]=lcs[i][j-1];
			else if(i>0&&j==0) lcs[i][j]=lcs[i-1][j];
			else if(i==0&&j==0) lcs[i][j]=0;
			else if(str1[i]==str2[j]) lcs[i][j]=1+lcs[i-1][j-1];
			else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	}
	printf("%d",lcs[n-1][n-1]);
}
