#include<bits/stdc++.h>
void towers(int n,char frompeg,char topeg,char auxpeg){
	if(n==1){
		printf("1 %c %c\n",frompeg,topeg);
		return;
	}
	//else{
		towers(n-1,frompeg,auxpeg,topeg);
		printf("%d %c %c\n",n,frompeg,topeg);
		towers(n-1,auxpeg,topeg,frompeg);
	//}
}
main(){
	int in;
	scanf("%d",&in);
	towers(in,'A','C','B');
}
