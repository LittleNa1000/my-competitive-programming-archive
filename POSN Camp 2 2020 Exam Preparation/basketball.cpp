//			22/3/2563
#include<stdio.h>
#include<algorithm>
//#include<iostream>
using namespace std;
int hi,hj,ans,n,row[3][1000000],a,b,*x,*y,p;
/*bool getHighest(){
	//int *x,*y;
	//int mx=0;
	/*hi=0;
	hj=0;
	for(int i=0;i<=1;i++){
		for(int j=0;j<n;j++){
			if(mx<row[i][j]){
				mx=row[i][j];
				hi=i;
				hj=j;
			}
		}
	}
	return mx;
	x=max_element(row[0],row[0]+n);
	y=max_element(row[1],row[1]+n);
	if(*x==0&&*y==0) return 0;
	hi=*y>*x;
	if(hi) hj=distance(row[1],y);
	else hj=distance(row[0],x);
	return 1;
}*/
int main(){
	scanf("%d",&n);
	//cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&row[0][i]);
		//cin>>row[0][i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",&row[1][i]);
		//cin>>row[1][i];
	}
	if(row[p][0]+row[!p][1]>row[!p][0]+row[p][1]){
		ans+=row[p][0];
		row[p][0]=0;
		row[!p][0]=0;
		row[p][1]=0;
		p=!p;
	}
	else{
		ans+=row[!p][0];
			row[p][0]=0;
			row[!p][0]=0;
			row[!p][1]=0;
	}
	//if(row[1][0]>row[0][0]) p=1;
	for(int i=1;i<n;i++){
		//a=row[p][i]+row[!p][i+1]+row[p][i+2];
		//if(i>0) a+=row[p][i+2];
		//b=row[!p][i]+row[p][i+1]+row[!p][i+2];
		if(row[p][i]+row[!p][i+1]+row[p][i+2]>=row[!p][i]+row[p][i+1]+row[!p][i+2]){
			ans+=row[p][i];
			row[p][i]=0;
			row[!p][i]=0;
			row[p][i+1]=0;
			p=!p;
		}
		else{
			ans+=row[!p][i];
			row[p][i]=0;
			row[!p][i]=0;
			row[!p][i+1]=0;
		}
		//p=!p;
	}
	//if(row[0][n-1]>row[1][n-1]) ans+=row[0][n-1];
	//else ans+=row[1][n-1];
	/*
		a=row[hi][hj];
		b=row[!hi][hj];
		if(hj>0){
			a+=row[!hi][hj-1];
			b+=row[hi][hj-1];
		} 
		if(hj<n-1) {
			a+=row[!hi][hj+1];
			b+=row[hi][hj+1];
		}
		if(a>=b){
			ans+=row[hi][hj];
			row[!hi][hj]=0;
			if(hj>0) row[hi][hj-1]=0;
			if(hj<n-1) row[hi][hj+1]=0;
		}
		row[hi][hj]=0;
	*/
	printf("%d",ans);
}
