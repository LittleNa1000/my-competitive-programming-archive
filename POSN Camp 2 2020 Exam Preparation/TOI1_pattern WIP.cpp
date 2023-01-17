//				30/3/2563 WIP
#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> > x[50005];
bool have_pattern[50005],b;
int temp,temp1,temp2,n;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		have_pattern[temp]=1;
		x[temp].push_back(make_pair(temp1,temp2));
	}
	for(int i=1;i<=n;i++){
		if(have_pattern[i]){
			for(int j=1;j<=70;j++){
				b=1;
				for(int k=0;k<x[i].size();k++){
					if(j==x[i][k].first){
						for(int m=0;m<x[i][k].second;m++) printf("x");
						j+=x[i][k].second;
						b=0;
					}
				}
				if(b) printf("o");
			}
		}
		printf("\n");
	}
}
