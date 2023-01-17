//				16/6/2563//FOR LOOP : K ON LFT & RIGHT TO CHECK DESTROYED
#include<bits/stdc++.h>
using namespace std;
int n,k,temp,ans,value,pos,left_m,right_m;
int gap[500005];
int master[500005];
vector< pair<int,int> > v;
int find_mas(int p){
	if(master[p]==p) return p;
	return find_mas(master[p]);
}
bool can_delete(){
	left_m=find_mas(pos-1);
	right_m=find_mas(pos+1);
	if(gap[left_m]+gap[right_m]+1>=k) return 0;
	gap[pos]=gap[left_m]+gap[pos+1]+1;
	if(gap[left_m]>0) master[left_m]=pos;
	if(gap[right_m]>0) master[right_m]=pos;
	return 1;
}
main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		ans+=temp;
		master[i]=i;
		v.push_back({temp,i});
	}
	if(k!=1){
		sort(v.begin(),v.end());
		for(int i=n-1;i>=0;--i){
			value=v[i].first;	pos=v[i].second;
			//printf("p%d v%d\n",pos,value);
			if(pos!=0&&pos!=n-1&&can_delete()){
				ans-=value;
				//printf("Delete %d\n",pos);
				//for(int j=0;j<n;j++) printf("master[%d]=%d  gap[%d]=%d\n",j,master[j],j,gap[j]);
				//printf("\n");
			}
			
		}
	}
	printf("%d",ans);
}
