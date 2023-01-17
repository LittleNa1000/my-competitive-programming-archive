#include<bits/stdc++.h>
char arr[100];
int input,y;
void swap(int idx){
	printf("*%d*",y);
	char temp;
	temp=arr[idx];
	arr[idx]=arr[idx-y];
	arr[idx-y]=temp;
}
void perm(int idx){
		if(idx==input){
			
			printf("%s\n",arr);
		}
		else{
			arr[idx]=idx+'0'+1;
			y--;
			perm(idx+1);
			//arr[idx]=arr[idx-1];
			
			swap(idx);
			y++;
			perm(idx+1);
		}
	}
main(){
	scanf("%d",&input);
	y=input;
	perm(0);
}
