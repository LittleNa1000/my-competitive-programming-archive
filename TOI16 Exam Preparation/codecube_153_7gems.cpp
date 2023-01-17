//                  20/11/2563
#include<bits/stdc++.h>
using namespace std;
struct t{
    int i,j,t,g,d;
};
queue<t> q;
bool visited[205][205][8][8]; //or bitset
int x[]={0,1,0,-1};
int y[]={-1,0,1,0};
int n,m,sj,si,pi,pj,tick,gem,d;
bool fs;
string str[205];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		cin>>str[i];
		if(!fs){
			for(int j=0;j<m;++j){
				if(str[i][j]=='S'){
					si=i;
					sj=j;
					fs=1;
					break;
				}
			}
		}
	}
	q.push({si,sj,1,0,0}); //tick, gem, d
	while(!q.empty()){
		pi=q.front().i;
		pj=q.front().j;
		tick=q.front().t;
		gem=q.front().g;
		d=q.front().d;
		q.pop();
        if(visited[pi][pj][tick][gem]) continue;
        visited[pi][pj][tick][gem]=1;
        //printf("(%d,%d) %d %d %d\n",pi,pj,tick,gem,d);
        if(str[pi][pj]=='G') ++gem;
		if(gem==7){
			printf("%d",d);
            return 0;
		}
        tick=(tick%6)+1;
        for(int k=0;k<4;++k){
            int i=pi+y[k];
            int j=pj+x[k];
            if(i>=0&&i<n&&j>=0&&j<m&&str[i][j]!='#'&&!visited[i][j][tick][gem]){
                if(str[i][j]>='1'&&str[i][j]<='6'){
                    if((tick==str[i][j]-'0'||gem>=str[i][j]-'0')) q.push({i,j,tick,gem,d+1});
                }
                else q.push({i,j,tick,gem,d+1});
            }
        }
	}
	printf("-1");
}
