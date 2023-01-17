//				7/7/2563
#include<bits/stdc++.h>
using namespace std;
int n,mindist,idxB,idxN,idxO,idxU,minidx,ans;
char temp,previous;
bool update;
string str;
main(){
	scanf("%d\n",&n);
	for(int i=0;i<n;++i){
		scanf("%c ",&temp);
		str.push_back(temp);
		if(i+1<n) scanf(" "); //maybe scanf("%c ",);
	}
	cout<<str<<'\n';
	while(str.length()>2){
		idxB=-1;   idxN=-1;   idxO=-1;   idxU=-1;
		mindist=INT_MAX;
		for(int i=0;i<str.length();++i){
			if(str[i]=='B'){
				if(idxB!=-1&&i-idxB<mindist){
					mindist=i-idxB;
					minidx=idxB;
				}
				idxB=i;
			}
			else if(str[i]=='N'){
				if(idxN!=-1&&i-idxN<mindist){
					mindist=i-idxN;
					minidx=idxN;
				}
				idxN=i;
			}
			else if(str[i]=='O'){
				if(idxO!=-1&&i-idxO<mindist){
					mindist=i-idxO;
					minidx=idxO;
				}
				idxO=i;
			}
			else{
				if(idxU!=-1&&i-idxU<mindist){
					mindist=i-idxU;
					minidx=idxU;
				}
				idxU=i;
			}
		}
		if(mindist==INT_MAX) break;
		//cout<<str<<'\n';
		str.erase(str.begin()+minidx,str.begin()+minidx+mindist+1);
		//printf("(%d,%d) ",minidx,minidx+mindist);	 cout<<str<<'\n';
		++ans;
		do{
			update=0; previous=0;
			for(int i=0;i<str.length();++i){
				if(previous==str[i]){
					update=1;
					str.erase(str.begin()+i-1,str.begin()+i+1);
					//cout<<str<<'\n';
					++ans;
					break;
				}
				previous=str[i];
			}
		}while(update);
	}
	printf("%d",ans);
}
