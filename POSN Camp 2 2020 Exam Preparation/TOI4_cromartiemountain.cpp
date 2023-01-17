//				3/5/2563
#include<bits/stdc++.h>
using namespace std;
short int n,maxh=SHRT_MIN,maxl=SHRT_MIN,start,height,x;
char mountain[15][100];
main(){
	scanf("%hd",&n);
	for(short int i=0;i<n;i++){
		scanf("%hd %hd",&start,&height);
		maxh=max(maxh,height);
		start--;
		if(maxl<start+height*2){
			maxl=start+height*2;
		}
		for(short int j=0;j<height;j++){
			if(mountain[14-j][start+j]=='\\') mountain[14-j][start+j]='v';
			else mountain[14-j][start+j]='/'; 
		}
		for(short int j=height-1;j>=0;j--){
			if(mountain[14-j][start+height+(height-j)-1]=='/') mountain[14-j][start+height+(height-j)-1]='v';
			else mountain[14-j][start+height+(height-j)-1]='\\'; 
		}
	}
	for(short int i=14-maxh+1;i<15;i++){
		x=0;
		for(short int j=0;j<maxl;j++){
			if(mountain[i][j]=='\\') x--;
			if(!x){
				if(mountain[i][j]) printf("%c",mountain[i][j]);
				else printf(".");
			}
			else{
				if(mountain[i][j]=='v') printf("%c",mountain[i][j]);
				else printf("X");
			}
			if(mountain[i][j]=='/') x++;
		}
		printf("\n");
	}
}
