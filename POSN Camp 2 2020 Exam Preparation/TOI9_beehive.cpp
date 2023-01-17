//				7/5/2563 Recursive or queue
#include<bits/stdc++.h>
using namespace std;
int mx=INT_MIN,mxcount,p_i,p_j,h;
int n,m,arr[1005][1005];
void f(){
	if(p_i==n-1){
		if(h>mx){
			mx=h;
			mxcount=1;
		}
		else if(h==mx){
			mxcount++;
		}
		return ;
	}
	p_i++;	h+=arr[p_i][p_j];
	f();
	h-=arr[p_i][p_j]; 	p_i--;
	if(p_i%2==0&&p_j>0){
		p_i++;	p_j--;	h+=arr[p_i][p_j];
		f();
		h-=arr[p_i][p_j];	p_i--;	p_j++;
	}
	if(p_i%2==1&&p_j<m-1){
		p_i++;	p_j++;	h+=arr[p_i][p_j];
		f();
		h-=arr[p_i][p_j];	p_i--;	p_j--;
	}
}
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		p_i=0;
		p_j=i;
		h=arr[0][i];
		f();
	}
	printf("%d %d",mx,mxcount);
}
