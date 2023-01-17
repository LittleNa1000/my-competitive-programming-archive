//				13/5/2563 		or set destroyed tiles to -1
#include<bits/stdc++.h>
using namespace std;
struct data{
	int p_i,p_j,value;
};
vector<struct data> v;
int n,t,x,y,h,k,ans,a;
bool pass;
main(){
	scanf("%d %d",&n,&t);
	while(n--){
		scanf("%d %d %d %d",&x,&h,&y,&k);
		x--;	
		for(int i=0;i<h;i++){
			for(int j=x;j<y+x;j++){
				//printf("\n(%d,%d) ",i,j);
					pass=0;
					for(a=0;a<v.size();a++){
						if(v[a].p_i==i&&v[a].p_j==j&&v[a].value<=t){
							//printf("Founded in v, a=%d ",a);
							if(v[a].value==t) ans--;
							v[a].value+=k;
							if(v[a].value==t) ans++;
							pass=1;
							break;
						}
					}
					if(!pass){
						//printf("Added {%d,%d,%d} to vector ",i,j,k);
						if(k<=t) v.push_back({i,j,k});
						if(k==t) ans++;
					}
			}
		}
		
	}
	printf("%d",ans);
}
