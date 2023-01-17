//			19/3/2020
#include<bits/stdc++.h>
using namespace std;
int pipenum,m,n;
int pipe[400][400],ans[10000];
void endpipe(int i,int j,int pos){
	//printf("------Pipe #%d is at the end (i=%d j=%d facing=%d) with %d pipes------\n",pipenum,i,j,pos,ans[pipenum]);
	pipenum++;
	if(pipe[i][j]!=31){
		pipe[i][j]=0;
		return ;
	}
	if(pos==1||pos==3) pipe[i][j]=22;
	if(pos==2||pos==4) pipe[i][j]=21;
}
void found_a_pipe(int i,int j,int pos){//	0=null 1=North 2=East 3=South 4=West
	ans[pipenum]++;
	//printf("Pipe #%d (now has %d pipes) Position i=%d j=%d Facing: %d Pattern: %d\n",pipenum,ans[pipenum],i,j,pos,pipe[i][j]);
	if(pipe[i][j]==11){
		if(pos==2&&i==0) return endpipe(i,j,pos);
		if(pos==3&&j==0) return endpipe(i,j,pos);
		if(pos==3) return found_a_pipe(i,j-1,4);
		if(pos==2) return found_a_pipe(i-1,j,1);
	}
	if(pipe[i][j]==12){
		if(pos==4&&i==0) return endpipe(i,j,pos);
		if(pos==3&&j+1>=n) return endpipe(i,j,pos);
		if(pos==3) return found_a_pipe(i,j+1,2);
		if(pos==4) return found_a_pipe(i-1,j,1);
	}
	if(pipe[i][j]==13){
		if(pos==2&&i+1>=m) return endpipe(i,j,pos);
		if(pos==1&&j==0) return endpipe(i,j,pos);
		if(pos==2) return found_a_pipe(i+1,j,3);
		if(pos==1) return found_a_pipe(i,j-1,4);
	}
	if(pipe[i][j]==14){
		if(pos==4&&i+1>=m) return endpipe(i,j,pos);
		if(pos==1&&j+1>=n) return endpipe(i,j,pos);
		if(pos==1) return found_a_pipe(i,j+1,2);
		if(pos==4) return found_a_pipe(i+1,j,3);
	}
	if(pipe[i][j]==21||pipe[i][j]==31){
		if(pos==1&&i==0) return endpipe(i,j,pos);
		if(pos==3&&i+1>=m) return endpipe(i,j,pos);
		if(pos==1) return found_a_pipe(i-1,j,1);
		if(pos==3) return found_a_pipe(i+1,j,3);
	}
	if(pipe[i][j]==22||pipe[i][j]==31){
		if(pos==4&&j==0) return endpipe(i,j,pos);
		if(pos==2&&j+1>=m) return endpipe(i,j,pos);
		if(pos==2) return found_a_pipe(i,j+1,2);
		if(pos==4) return found_a_pipe(i,j-1,4);
	}
}
main(){
	int i,j;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&pipe[i][j]);
		}	
	}
	for(i=0;i<m;i++){ // All
	//printf("A");
		if(i==0||i+1==m){// First and last row
		//printf("B");
			for(j=0;j<n;j++){
			//printf("C");
				if(i==0&&j==0){//		0,0 
					if(pipe[i][j]==11) {ans[pipenum]++; endpipe(i,j,0);}//
					else if(pipe[i][j]==12) found_a_pipe(i,j,3);
					else if(pipe[i][j]==13) found_a_pipe(i,j,2);
					else if(pipe[i][j]==21) found_a_pipe(i,j,3);
					else if(pipe[i][j]==22) found_a_pipe(i,j,2);
					else if(pipe[i][j]==31) {found_a_pipe(i,j,2); found_a_pipe(i,j,3);}
					
				}
				else if(i==0){//		0,1 ... 0,n-2
					if(pipe[i][j]==11) found_a_pipe(i,j,3);
					else if(pipe[i][j]==12) found_a_pipe(i,j,3);
					else if(pipe[i][j]==21) found_a_pipe(i,j,3);
					else if(pipe[i][j]==31) found_a_pipe(i,j,3);
				}
				else if(i==0&&j+1==n){//		0,n-1
					if(pipe[i][j]==11) found_a_pipe(i,j,3);
					else if(pipe[i][j]==12) {ans[pipenum]++; endpipe(i,j,0);}//
					else if(pipe[i][j]==14) found_a_pipe(i,j,4);
					else if(pipe[i][j]==21) found_a_pipe(i,j,3);
					else if(pipe[i][j]==22) found_a_pipe(i,j,4);
					else if(pipe[i][j]==31) {found_a_pipe(i,j,3); found_a_pipe(i,j,4);}
					
				}
				else if(i+1==m&&j==0){//		m-1,0
					if(pipe[i][j]==11) found_a_pipe(i,j,2);
					else if(pipe[i][j]==13) {ans[pipenum]++; endpipe(i,j,0);}//
					else if(pipe[i][j]==14) found_a_pipe(i,j,1);
					else if(pipe[i][j]==21) found_a_pipe(i,j,1);
					else if(pipe[i][j]==22) found_a_pipe(i,j,2);
					else if(pipe[i][j]==31) {
					found_a_pipe(i,j,1); found_a_pipe(i,j,2);}
					
				}
				else if(i+1==m){//	m-1,1 ... m-1,n-2
					if(pipe[i][j]==13) found_a_pipe(i,j,1);
					else if(pipe[i][j]==14) found_a_pipe(i,j,1);
					else if(pipe[i][j]==21) found_a_pipe(i,j,1);
					else if(pipe[i][j]==31) found_a_pipe(i,j,1);
					
				}
				else if(i+1==m&&j+1==n){//	m-1,n-1
					if(pipe[i][j]==12) found_a_pipe(i,j,4);
					else if(pipe[i][j]==13) found_a_pipe(i,j,1);
					else if(pipe[i][j]==14) {ans[pipenum]++; endpipe(i,j,0);}//
					else if(pipe[i][j]==21) found_a_pipe(i,j,1);
					else if(pipe[i][j]==22) found_a_pipe(i,j,4);
					else if(pipe[i][j]==31) {
					found_a_pipe(i,j,1); found_a_pipe(i,j,4);}
					
				}
			}
		}
		else{ // 1,2,...,m-1 row
			j=0; //		x,0
				if(pipe[i][j]==11) found_a_pipe(i,j,2);
				else if(pipe[i][j]==13) found_a_pipe(i,j,2);
				else if(pipe[i][j]==22) found_a_pipe(i,j,2);
				else if(pipe[i][j]==31) found_a_pipe(i,j,2);
				
			
			j=n-1;//		x,n-1
				if(pipe[i][j]==12) found_a_pipe(i,j,4);
				else if(pipe[i][j]==14) found_a_pipe(i,j,4);
				else if(pipe[i][j]==22) found_a_pipe(i,j,4);
				else if(pipe[i][j]==31) found_a_pipe(i,j,4);
		}
	}
	printf("%d\n",pipenum);
	for(int k=0;k<pipenum;k++) printf("%d ",ans[k]);
}
