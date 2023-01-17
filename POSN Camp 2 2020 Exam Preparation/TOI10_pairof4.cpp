//				20/4/2563
#include<bits/stdc++.h>
using namespace std;
int n,ans,gap_start,gap_end,pos_b,pos_n,pos_o,pos_u;
string str;
bool no_pair;
char temp;
void del(int l,int r){
	//printf("%c %c l=%d r=%d\n",str[l],str[r],l,r);
	if(l==0&&r==INT_MAX){
		no_pair=1;
		return ;
	}
	if(r==str.length()-1) str.erase(str.begin()+l,str.end());
	else str.erase(str.begin()+l,str.begin()+r+1);
	ans++;
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>temp;
		str.push_back(temp);
	}
	//cout<<str;
	while(1){
		if(no_pair||str.length()<2) break;
		gap_start=0;
		gap_end=INT_MAX;
		pos_b=-1;
		pos_n=-1;
		pos_o=-1;
		pos_u=-1;
		for(int i=0;i<str.length();i++){
			if(str[i]=='B'){
				if(pos_b!=-1){
					if(i-pos_b<=2){
						del(pos_b,i);
						break ;
					}
					else if(i-pos_b<gap_end-gap_start){
						gap_start=pos_b;
						gap_end=i;
					}
				}
				pos_b=i;
			}
			else if(str[i]=='N'){
				if(pos_n!=-1){
					if(i-pos_n<=2){
						del(pos_n,i);
						break ;
					}
					else if(i-pos_n<gap_end-gap_start){
						gap_start=pos_n;
						gap_end=i;
					}
				}
				pos_n=i;
			}
			else if(str[i]=='O'){
				if(pos_o!=-1){
					if(i-pos_o<=2){
						del(pos_o,i);
						break ;
					}
					else if(i-pos_o<gap_end-gap_start){
						gap_start=pos_o;
						gap_end=i;
					}
				}
				pos_o=i;
			}
			else{
				if(pos_u!=-1){
					if(i-pos_u<=2){
						del(pos_u,i);
						break ;
					}
					else if(i-pos_u<gap_end-gap_start){
						gap_start=pos_u;
						gap_end=i;
					}
				}
				pos_u=i;
			}
			if(i+1==str.length()){
				del(gap_start,gap_end);
			}
		}
	}
	printf("%d",ans);
}
