//				2/6/2563
#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,e,pstr;
char str[100005];
char ans[100005];
bool visited[100005];
main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d %d\n",&a,&b,&c,&d,&e);
		scanf("%s",&str);
		pstr=e-1;
		while(d--){
			while(str[pstr]=='4'){
				pstr--;
			}
			ans[pstr]='4';
			//printf("put 4 on %d\n",pstr);
			visited[pstr]=1;
			pstr--;
		}
		pstr=e-1;
		while(c--){
			while(str[pstr]=='3'||visited[pstr]){
				pstr--;
			}
			ans[pstr]='3';
			//printf("put 3 on %d\n",pstr);
			visited[pstr]=1;
			pstr--;
		}
		pstr=0;
		while(a--){
			while(str[pstr]=='1'||visited[pstr]){
				pstr++;
			}
			ans[pstr]='1';
			//printf("put 1 on %d\n",pstr);
			visited[pstr]=1;
			pstr++;
		}
		pstr=0;
		while(b--){
			while(str[pstr]=='2'||visited[pstr]){
				pstr++;
			}
			ans[pstr]='2';
			//printf("put 2 on %d\n",pstr);
			visited[pstr]=1;
			pstr++;
		}
		printf("%s\n",ans);
		for(int i=0;i<e;i++){
			visited[i]=0;
			ans[i]=0;
		}
	}
}
