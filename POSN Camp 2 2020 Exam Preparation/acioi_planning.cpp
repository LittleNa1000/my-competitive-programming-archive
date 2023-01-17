//				10/4/2563
#include<bits/stdc++.h>
using namespace std;
bool completed[1005],s;
vector<int> v[1005];
int n,temp,temp1,finish_task;
void f(int i){
	finish_task++;
	printf("%d ",i);
	completed[i]=1;
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		for(int j=0;j<temp;j++){
			scanf("%d",&temp1);
			v[i].push_back(temp1);
		}
		if(temp==0){
			f(i);
		}
	}
	while(finish_task<n){
		for(int i=0;i<n;i++){
			if(v[i].size()<=finish_task&&!completed[i]){
				s=1;
				for(int j=0;j<v[i].size();j++){
					if(!completed[v[i][j]]){
						s=0;
						break;
					}
				}
				if(s) f(i);
			}
		}
	}
}
