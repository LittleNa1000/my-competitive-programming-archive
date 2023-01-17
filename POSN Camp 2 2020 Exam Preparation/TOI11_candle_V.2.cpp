//				25/4/2563 V.2
#include<bits/stdc++.h>
using namespace std;
short int n,m,i,j;
int ans;
char str[2005][2005];
queue< pair<short int,short int> > q;
pair<short int,short int> p;
void cd(){
	//printf("\n%hd %hd",i,j);
	while(!q.empty()){
		p=q.front();
		q.pop();
		i=p.first;
		j=p.second;
		str[i][j]='0';
		if(i>0&&j>0&&str[i-1][j-1]=='1'){
			q.push(make_pair(i-1,j-1));
			str[i-1][j-1]='0';
		}
		if(i>0&&str[i-1][j]=='1'){
			q.push(make_pair(i-1,j));
			str[i-1][j]='0';
		} 
		if(i>0&&j<m-1&&str[i-1][j+1]=='1'){
			q.push(make_pair(i-1,j+1));
			str[i-1][j+1]='0';
		}
		if(j>0&&str[i][j-1]=='1'){
			q.push(make_pair(i,j-1));
			str[i][j-1]='0';
		}  
		if(j<m-1&&str[i][j+1]=='1'){
			q.push(make_pair(i,j+1));
			str[i][j+1]='0';
		} 
		if(i<n-1&&j>0&&str[i+1][j-1]=='1'){
			q.push(make_pair(i+1,j-1));
			str[i+1][j-1]='0';
		}
		if(i<n-1&&str[i+1][j]=='1'){
			q.push(make_pair(i+1,j));
			str[i+1][j]='0';
		}  
		if(i<n-1&&j<m-1	&&str[i+1][j+1]=='1'){
			q.push(make_pair(i+1,j+1));
			str[i+1][j+1]='0';
		}
	}
}
main(){
	scanf("%hd %hd",&n,&m);
	for(short int a=0;a<n;a++){
		cin>>str[a];
	}
	for(short int a=0;a<n;a++){
		for(short int b=0;b<m;b++){
			//printf("\n%hd %hd",a,b);
			if(str[a][b]=='1'){
				ans++;
				q.push(make_pair(a,b));
				cd();
			}
		}
	}
	printf("%d",ans);
}
