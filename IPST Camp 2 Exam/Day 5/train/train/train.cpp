#include "train.h"
#include <bits/stdc++.h>
using namespace std;
int n,m,x;
int seg[1000005];
//vector<int> s,t,c;
void init(int idx,int l,int r){
	if(l>r) return;
	if(l==r){
		if(l) seg[idx]=INT_MAX;
		return ;
	}
	int m=(l+r)/2;
	init((idx*2)+1,l,m);
	init((idx*2)+2,m+1,r);
	seg[idx]=max(seg[(idx*2)+1],seg[(idx*2)+2]);
	//printf("init idx=%d (%d,%d) val=%d\n",idx,l,r,seg[idx]);
}
int getval(int idx,int l,int r,int tg,int mn){
	if(l>r) return INT_MAX;
	mn=min(seg[idx],mn);
	if(l==r&&l==tg){
		return mn;
	}
	int m=(l+r)/2;
	if(tg>m){
		return getval((idx*2)+2,m+1,r,tg,mn);
	}
	else{
		return getval((idx*2)+1,l,m,tg,mn);
	}

}
void upd(int idx,int l,int r,int a,int b){
	if(l>r) return;
	if(a<=l&&r<=b){
		seg[idx]=min(seg[idx],x);
		return ;
	}
	if(b<l||r<a) return ;
	int m=(l+r)/2;
	upd((idx*2)+1,l,m,a,b);
	upd((idx*2)+2,m+1,r,a,b);
}
void display(int idx,int l,int r){
	if(l>r) return;
	printf("idx = %d (%d,%d) val = %d\n",idx,l,r,seg[idx]);
	if(l==r) return;
	int m=(l+r)/2;
	display((idx*2)+1,l,m);
	display((idx*2)+2,m+1,r);
}
int find_min_cost(int N, int M,
		  std::vector<int>& s,
		  std::vector<int>& t,
		  std::vector<int>& c)
{
	n=N;
	m=M;
	// S=s;
	// T=t;
	// C=c;
	//for(int i=0;i<n;++i){
		init(0,0,n-1);
	//}
	for(int i=0;i<m;++i){
		x=getval(0,0,n-1,s[i],INT_MAX);
		//printf("i = %d getval %d x = %d\n",i,s[i],x);
		if(x==INT_MAX) continue;
		x+=c[i];
		upd(0,0,n-1,s[i],t[i]);
		//display(0,0,n-1); printf("\n");
	}
	x=getval(0,0,n-1,n-1,INT_MAX);
	if(x==INT_MAX) return -1;
  	return x;
}
/*
7 7
0 2 10
1 3 50
2 6 200
2 4 30
4 6 200
3 6 10
0 6 1000
*/
