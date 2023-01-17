//				23/8/2563 2d matrix
#include<bits/stdc++.h>
using namespace std;
char s[3];
int E,u,v,source=-1,sub;
string str; //maybe vector
bool edge[30][30];
int sz[30];
bool f(int node,int d){
	//printf("node=%c, d=%d\n",node+'A',d);
	if(d==E){
		return 1;
	}
	for(int i=0;i<26;++i){
		if(edge[node][i]&&edge[i][node]){
			edge[node][i]=0;
			edge[i][node]=0;
			str.push_back(i+'A');
			str.push_back(' ');
			if(f(i,d+1)) return 1;
			str.erase(str.end()-2,str.end());
			edge[node][i]=1;
			edge[i][node]=1;
		}
	}
	//printf("return\n");
	return 0;
}
main(){
	scanf("%d",&E);
	for(int i=0;i<E;++i){
		scanf("%s",&s);
		u=s[0]-'A';
		v=s[1]-'A';
		edge[u][v]=1;
		edge[v][u]=1;
		++sz[u];
		++sz[v];
	}
	for(int i=0;i<26;++i){
		if(sz[i]%2==1){
			source=i;
			break;
		}
		else if(sz[i]>0) sub=i;
	}
	if(source==-1) source=sub;
	/*printf("Source=%c\n",source+'A');
	for(int i=0;i<26;++i){
		for(int j=0;j<26;++j) printf("%d ",edge[i][j]);
		printf(" = %d\n",sz[i]);
	}*/
	str.push_back(source+'A');
	str.push_back(' ');
	if(f(source,0)) cout<<str;
}
