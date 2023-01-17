//				2/5/2563 	Last Edited: 10/5/2563
#include<bits/stdc++.h>
using namespace std;
vector<short int> v[30];
short int E,mn=SHRT_MAX,mx,del;
short int source,nxt,mx_s,bf,ori,n_remove;
char temp[2];
void check(){
	for(short int i=0;i<30;i++){
			if(!v[i].empty()){
				printf("%c has: ",i+'A');
				for(short int j=0;j<v[i].size();j++) printf("%c ",v[i][j]+'A');
				printf("\n");
			}
	}
}
main(){
	scanf("%hd",&E);
	for(short int i=0;i<E;i++){
		scanf("%s",&temp);
		v[temp[0]-'A'].push_back(temp[1]-'A');
		v[temp[1]-'A'].push_back(temp[0]-'A');
	}
	for(short int i=0;i<30;i++){
		if(v[i].size()%2){
			if(v[i].size()<mn){
				mn=v[i].size();
				source=i;
			}
		}
		else if(v[i].size()>mx){
			mx=v[i].size();
			mx_s=i;
		}
	}
	//check();
	if(!source) source=mx_s;
	bf=source; ori=source;
	printf("%c ",source+'A');
	while(E--){
		mn=SHRT_MAX;
		n_remove=1;
		nxt=0;	del=0;
		for(short int i=0;i<v[source].size();i++){
			if(v[source][i]==bf){
				v[source].erase(v[source].begin()+i);
				i--;
				n_remove=0;
			}
			else{
				if(v[v[source][i]].size()%2==0&&v[v[source][i]].size()<mn){
					if(v[source][i]!=ori||v[source].size()-n_remove==1){
						mn=v[v[source][i]].size();
						del=i;
						nxt=v[source][i];	
					}
				}
			}
		}
		if(!nxt){
			nxt=v[source][0];
		}
		//printf("%c to %c\n",source+'A',nxt+'A');
		v[source].erase(v[source].begin()+del);
		bf=source;
		source=nxt;
		printf("%c ",source+'A');
	}
}
/*
8
AB
AC
BF
BC
CF
DC
ED
EF
//
11
AB
CD
AC
BD
CE
DF
CF
ED
EF
EG
FG
14
AE
AC
EC
BC
BD
DG
CG
CF
CH
FG
GH
FH
FI
IH
//*********
14
AB
BC
AC
CD
DE
EF
FH
FG
GH
FI
DI
IK
KJ
JI
//********
27
DO
QA
KN
SH
IG
ME
DL
LQ
SK
GE
AJ
BN
RH
CI
MF
CG
GP
SP
BK
QJ
LP
EF
RS
PK
EP
PQ
LO
*/
