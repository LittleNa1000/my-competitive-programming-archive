//				19/4/2563
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,m,temp,i,j;
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	while(m--){
		scanf("%d",&temp);
		i=0;
		j=n-1;
		while(1){
			if(i==j){
				printf("NO\n");
				break;
			}
			if(v[i]+v[j]==temp){
				printf("YES\n");
				break;
			}
			else if(v[i]+v[j]<temp){
				i++;
			}
			else{
				j--;
			}
		}
	}
}
