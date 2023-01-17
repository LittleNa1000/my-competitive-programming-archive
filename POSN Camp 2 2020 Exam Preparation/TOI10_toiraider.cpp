//				7/5/2563
#include<bits/stdc++.h>
using namespace std;
int ans;
short int n,m,middle;
int step,pos_i,pos_j;
int area[105][105];
bool b;
void f(){
	//printf("(%d,%d) Step=%d Area=%d\n",pos_i,pos_j,step,area[pos_i][pos_j]);
	//printf("%d mod %d = %d\n",step-1,area[pos_i+1][pos_j],(step-1)%area[pos_i+1][pos_j]);
	if(((pos_i==middle-1&&pos_j==0)||(pos_i==middle&&pos_j==0)||(pos_i==middle+1&&pos_j==0))&&step==1){
		b=1;
		return ;
	}
	if(step==1) return ;
	if(pos_j>0&&area[pos_i][pos_j-1]&&(step-1)%area[pos_i][pos_j-1]==0){//		West
		pos_j--;	step--;
		f();
		pos_j++;	step++;
	}
	if(pos_i%2==1){
		if(pos_i>0&&pos_j>0&&area[pos_i-1][pos_j-1]&&(step-1)%area[pos_i-1][pos_j-1]==0){//		NW
		pos_i--;	pos_j--;	step--;
		f();
		pos_i++;	pos_j++;	step++;
		}
		if(pos_i<n-1&&pos_j>0&&area[pos_i+1][pos_j-1]&&(step-1)%area[pos_i+1][pos_j-1]==0){//	SW
		pos_i++;	pos_j--;	step--;
		f();
		pos_i--;	pos_j++;	step++;
		}
	}
	if(pos_i>0&&area[pos_i-1][pos_j]&&(step-1)%area[pos_i-1][pos_j]==0){//		North
		pos_i--;	step--;
		f();
		pos_i++;	step++;
	}
	if(pos_i<n-1&&area[pos_i+1][pos_j]&&(step-1)%area[pos_i+1][pos_j]==0){//	South
		pos_i++;	step--;
		f();
		pos_i--;	step++;
	}
	if(pos_j<m-1&&area[pos_i][pos_j+1]&&(step-1)%area[pos_i][pos_j+1]==0){//	East
		pos_j++;	step--;
		f();
		pos_j--;	step++;
	}
	if(pos_i%2==0){
		if(pos_i>0&&pos_j<m-1&&area[pos_i-1][pos_j+1]&&(step-1)%area[pos_i-1][pos_j+1]==0){//	NE
			pos_i--;	pos_j++;	step--;
			f();
			pos_i++;	pos_j--;	step++;
		}
		if(pos_i<n-1&&pos_j<m-1&&area[pos_i+1][pos_j+1]&&(step-1)%area[pos_i+1][pos_j+1]==0){//	SE
		pos_i++;	pos_j++;	step--;
		f();
		pos_i--;	pos_j--;	step++;
		}
	}
}
main(){
	scanf("%hd %hd",&n,&m);
	for(short int i=0;i<n;i++){
		for(short int j=0;j<m;j++){
			scanf("%d",&area[i][j]);
		}
	}
	middle=(n-1)/2;
	for(ans=area[middle][m-1];;ans+=area[middle][m-1]){
		pos_i=middle;
		pos_j=m-1;
		step=ans;
		f();
		if(b){
			printf("%d",ans);
			break;
		}
	}
}
