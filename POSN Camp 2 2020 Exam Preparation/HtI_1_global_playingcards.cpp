//				11/8/2563
#include<bits/stdc++.h>
using namespace std;
int n,v1,v2;
char win,x1,x2;
int main(){
	cin>>win>>n;
	//printf("%c %d\n",win,n);
	for(int i=0;i<n;++i){
		cin>>x1>>v1>>x2>>v2;
		//printf("%c %d %c %d\n",x1,v1,x2,v2);
		if(x1==win&&x2!=win) printf("Player 1 wins\n");
		else if(x1!=win&&x2==win) printf("Player 2 wins\n");
		else{
			if(v1>v2) printf("Player 1 wins\n");
			else if(v2>v1) printf("Player 2 wins\n");
			else printf("Draw\n");
		}
	}
}
