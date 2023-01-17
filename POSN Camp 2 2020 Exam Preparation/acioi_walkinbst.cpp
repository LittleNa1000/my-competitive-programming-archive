//				17/4/2563
#include<bits/stdc++.h>
using namespace std;
short int h;
long int a,b,x;
void inorder(short int depth){
	if(depth==h){
		x++;
		if(x>=a&&x<=b) printf("T");
		else if(x>b) return ;
		return ;
	}
	x++;
	if(x>=a&&x<=b) printf("L");
	else if(x>b) return ;
	inorder(depth+1);
	x++;
	if(x>=a&&x<=b) printf("R");
	else if(x>b) return ;
	x++;
	if(x>=a&&x<=b) printf("T");
	else if(x>b) return ;
	x++;
	if(x>=a&&x<=b) printf("R");
	else if(x>b) return ;
	inorder(depth+1);
	x++;
	if(x>=a&&x<=b) printf("L");
	else if(x>b) return ;
}
main(){
	scanf("%hd %ld %ld",&h,&a,&b);
	if(a==-1){
		b=LONG_MAX;
	}
	inorder(0);
}
