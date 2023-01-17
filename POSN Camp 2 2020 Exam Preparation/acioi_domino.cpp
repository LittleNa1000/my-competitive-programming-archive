//				2/4/2563 WIP
#include<bits/stdc++.h>
using namespace std;
int j,n,temp,temp1;
vector< pair<int,int> > v;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&temp,&temp1);
		v.push_back(make_pair(temp,temp1));
	}
	for(int i=0;i<n;i++){
		for(j=0;j<v.size()-1;j++){
			if(v[j].first+v[j].second<v[j+1].first){
				break;
			}
			else if(v[j].first+v[j].second>v[j+1].first){
				for(int k=j+2;k<v.size();k++){
					if(v[j].first+v[j].second<v[k].first){
						j=k-1;
						break;
					}
				}
			}
		}
		printf("%d ",i+j);
		v.erase(v.begin());
	}
}
