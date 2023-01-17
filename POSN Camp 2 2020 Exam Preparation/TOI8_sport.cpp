//			27/3/2563
#include<bits/stdc++.h>
using namespace std;
int k,w,l,comb,w2,l2;
string str;
bool printable;
main(){
	scanf("%d %d %d",&k,&w,&l);
	comb=(2*k)-1-w-l;
	for(int i=0;i<pow(2,comb);i++){
		w2=w;
		l2=l;
		printable=1;
		/*for(int j=0;j<comb;j++){
			if(i&(1<<j)) printf("W ");
			else printf("L ");
		}
		printf("	->	");*/
		for(int j=0;j<comb;j++){
			if(w2>=k||l2>=k){
				for(int a=j;a<comb;a++){
					if(!(i&(1<<a))){
						printable=0;
						break;
					}
				}
				break;
			}
			if(i & (1<<j)){
				w2++;
				str.push_back('W');
				//printf("W ");
			}
			else{
				l2++;
				str.push_back('L');
				//printf("L ");
			}
			str.push_back(' ');
		}
		if(printable) cout<<str<<'\n';
		//printf("\n");
		str.clear();
	}
}
