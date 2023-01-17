//				29/3/2563	1(DEL)	2ABC	3DEF
#include<bits/stdc++.h>// 	4GHI	5JKL	6MNO	 
using namespace std;//		7PQRS	8TUV	9WXYZ
string ans;
char letter;
int n,num,press,posx,posy,h,v;
void print_a_letter(int s,int m){
	if(s==1){
		posx=0; posy=0;
		while(press--){
			if(!ans.empty())
			ans.erase(--ans.end());	
		}
	}
	else if(s==2){
		letter='A'; posx=1; posy=0;
	}
	else if(s==3) {
		letter='D'; posx=2; posy=0;
	}
	else if(s==4) {
		letter='G'; posx=0; posy=1;
	}
	else if(s==5) {
		letter='J'; posx=1; posy=1;
	}
	else if(s==6) {
		letter='M'; posx=2; posy=1;
	}
	else if(s==7) {
		letter='P'; posx=0; posy=2;
	}
	else if(s==8) {
		letter='T'; posx=1; posy=2;
	}
	else if(s==9) {
		letter='W'; posx=2; posy=2;
	}
	if(s==7||s==9){
		letter+=(m-1)%4;
		ans.push_back(letter);
	}
	else if(s!=1){
		letter+=(m-1)%3;
		ans.push_back(letter);
	}
}
main(){
	scanf("%d",&n);
	scanf("%d %d",&num,&press);
	print_a_letter(num,press);
	n--;
	while(n--){
		scanf("%d %d %d",&h,&v,&press);
		posx+=h;
		posy+=v;
		print_a_letter((posy*3)+posx+1,press);
	}
	if(!ans.empty()) cout<<ans;
	else printf("null");
}
