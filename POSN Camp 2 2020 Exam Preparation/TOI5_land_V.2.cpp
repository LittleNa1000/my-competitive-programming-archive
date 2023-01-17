//				30/4/2563
#include<bits/stdc++.h>
using namespace std;
int cost[5][5];
short int n,m,i,j;
double ans,temp[5][5],tcost;
vector<short int> v;
bool visited[10];
/*void print_vec(vector<short int> v){
	for(short int x=0;x<v.size();x++) printf("%hd ",v[x]);
	printf("\n");
}*/
void t(){
	for(short int i=0;i<n;i++){
		for(short int j=0;j<m;j++) temp[i][j]=cost[i][j];
	}
}
void land(){
	t();
	for(short int x=0;x<v.size();x++){
		i=v[x]/m;
		j=v[x]%m;
		//printf("(%hd,%hd) ",i,j);
		tcost+=temp[i][j];
		if(i>0&&j>0)   temp[i-1][j-1]+=temp[i][j]/10;
    	if(i>0) 	   temp[i-1][j]+=temp[i][j]/10;
    	if(i>0&&j+1<m) temp[i-1][j+1]+=temp[i][j]/10;
    	if(j>0) 	   temp[i][j-1]+=temp[i][j]/10;
    	if(j+1<m) 	   temp[i][j+1]+=temp[i][j]/10;
    	if(i+1<n&&j>0) temp[i+1][j-1]+=temp[i][j]/10;
    	if(i+1<n) 	   temp[i+1][j]+=temp[i][j]/10;
    	if(i+1<n&&j+1<m) temp[i+1][j+1]+=temp[i][j]/10;
	}
	if(tcost<ans||ans==0) ans=tcost;
}
void f(){
	if(v.size()==n*m){
		//print_vec(v);
		tcost=0;
		land();
		return ;
	}
	for(short int i=0;i<n*m;i++){
		if(!visited[i]){
			visited[i]=1;
			v.push_back(i);
			f();
			v.pop_back();
			visited[i]=0;
		}
	}
}
main(){
	scanf("%hd %hd",&n,&m);
	for(short int i=0;i<n;i++){
		for(short int j=0;j<m;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	f();
	printf("%.2lf",ans);
}		
