//				24/4/2563 Last Edited: 25/4/2563
#include<bits/stdc++.h>
using namespace std;
short int n,m,i,j;
int ans;
char str[2100][2100];
void cd(){
	printf("\n%hd %hd",i,j);
	str[i][j]='0';
	if(i>0&&j>0&&str[i-1][j-1]=='1'){
		i--;
		j--;
		cd();	
		i++;
		j++;
	}
	if(i>0&&str[i-1][j]=='1'){
		i--;
	 	cd();	
	 	i++;
	} 
	if(i>0&&j<m-1&&str[i-1][j+1]=='1'){
		i--;
		j++;
		cd();
		i++;
		j--;
	}
	if(j>0&&str[i][j-1]=='1'){
		j--;
		cd();
		j++;
	}  
	if(j<m-1&&str[i][j+1]=='1'){
		j++;
		cd();
		j--;
	} 
	if(i<n-1&&j>0&&str[i+1][j-1]=='1'){
		i++;
		j--;
		cd();
		i--;
		j++;
	}
	if(i<n-1&&str[i+1][j]=='1'){
		i++;
		cd();
		i--;
	}  
	if(i<n-1&&j<m-1	&&str[i+1][j+1]=='1'){
		i++;
		j++;
		cd();
		i--;
		j--;
	}
}
main(){
	scanf("%hd %hd",&n,&m);
	for(short int a=0;a<n;a++){
		cin>>str[a];
	}
	for(short int a=0;a<n;a++){
		for(short int b=0;b<m;b++){
			printf("\n%hd %hd",a,b);
			if(str[a][b]=='1'){
				ans++;
				i=a;
				j=b;
				cd();
			}
		}
	}
	printf("*\n\n\n\n\n%d*",ans);
}
