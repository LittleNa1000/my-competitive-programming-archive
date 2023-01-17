//				14/4/2563
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,ans,ub,temp;
void print_vec(vector<int> v){
    for(int i=0;i<v.size();i++) printf("%d ",v[i]);
    printf("\n");
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(i==0){
			v.push_back(temp);
			ans++;
		}
		else{
			ub=lower_bound(v.begin(),v.end(),temp)-v.begin();
			if(ub==v.size()){
				v.push_back(temp);
				ans++;
			}
			else{
				v[ub]=temp;
			}
		}
	}
	print_vec(v);
	printf("%d",ans);
}
