//				26/5/2563
#include<bits/stdc++.h>
using namespace std;
int n,m,pipe[305][305],a,b,dist;
vector<int> v;
void f(int i,int j,int pi,int pj){
	if(pi>=0&&pi<n&&pj>=0&&pj<m){
		if(pipe[pi][pj]!=31) pipe[pi][pj]=0;
		else if(pj==j) pipe[pi][pj]=22;
		else pipe[pi][pj]=21;
	}
	if(i<0||i==n||j<0||j==m){
		v.push_back(dist);
		dist=0;
		return ;
	}
	dist++;
	if(pipe[i][j]==11){
		if(pi==i) return f(i-1,j,i,j);
		else return f(i,j-1,i,j);
	}
	else if(pipe[i][j]==12){
		if(pi==i) return f(i-1,j,i,j);
		else return f(i,j+1,i,j);
	}
	else if(pipe[i][j]==13){
		if(pi==i) return f(i+1,j,i,j);
		else return f(i,j-1,i,j);
	}
	else if(pipe[i][j]==14){
		if(pi==i) return f(i+1,j,i,j);
		else return f(i,j+1,i,j);
	}
	else if(pipe[i][j]==21){
		if(pi<i) return f(i+1,j,i,j);
		else return f(i-1,j,i,j);
	}
	else if(pipe[i][j]==22){
		if(pj<j) return f(i,j+1,i,j);
		else return f(i,j-1,i,j);
	}
	else if(pipe[i][j]==31){
		if(pi<i) return f(i+1,j,i,j);
		else if(pi>i) return f(i-1,j,i,j);
		else if(pj<j) return f(i,j+1,i,j);
		else return f(i,j-1,i,j);
	}
}
main(){
	scanf("%d %d",&n,&m);
	for(a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf("%d",&pipe[a][b]);
		}
	}
	for(a=0,b=0;b<m;b++){
		if(pipe[a][b]==11||pipe[a][b]==12||pipe[a][b]==21||pipe[a][b]==31){
			f(a,b,a-1,b);
		}
	}
	for(a=n-1,b=0;b<m;b++){
		if(pipe[a][b]==13||pipe[a][b]==14||pipe[a][b]==21||pipe[a][b]==31){
			f(a,b,a+1,b);
		}
	}
	for(b=0,a=0;a<n;a++){
		if(pipe[a][b]==11||pipe[a][b]==13||pipe[a][b]==22||pipe[a][b]==31){
			f(a,b,a,b-1);
		}
	}
	for(b=m-1,a=0;a<n;a++){
		if(pipe[a][b]==12||pipe[a][b]==14||pipe[a][b]==22||pipe[a][b]==31){
			f(a,b,a,b+1);
		}
	}
	printf("%d\n",v.size());
	for(a=0;a<v.size();a++) printf("%d ",v[a]);
}
