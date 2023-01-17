//				30/8/2563
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int lus[1005][1005];
main(){
	cin>>s1>>s2;
	for(int i=1;i<=s1.length();++i){
		for(int j=1;j<=s2.length();++j){
			if(s1[i-1]==s2[j-1]) lus[i][j]=1+lus[i-1][j-1];
			else lus[i][j]=max(lus[i-1][j],lus[i][j-1]);
		}
	}
	for(int i=1;i<=s1.length();++i){
		for(int j=1;j<=s2.length();++j){
			printf("%d ",lus[i][j]);
		}
		printf("\n");
	}
	if(lus[s1.length()][s2.length()]==0) printf("-1");
	else printf("%d",lus[s1.length()][s2.length()]);
}
