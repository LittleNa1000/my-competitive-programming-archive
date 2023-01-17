//				26/3/2563
#include<bits/stdc++.h>
using namespace std;
int lcs[1005][1005];
string str1,str2,temp;
main(){
	cin>>str1>>str2;
	for(int i=0;i<str1.length();i++){
		for(int j=0;j<str2.length();j++){
			if(str1[i]==str2[j]&&(i==0||j==0)) lcs[i][j]=1;
			else if(i==0&&j>0) lcs[i][j]=lcs[i][j-1];
			else if(i>0&&j==0) lcs[i][j]=lcs[i-1][j];
			else if(i==0&&j==0) lcs[i][j]=0;
			else if(str1[i]==str2[j]) lcs[i][j]=1+lcs[i-1][j-1];
			else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	}
	printf("%d",lcs[str1.length()-1][str2.length()-1]);
}
