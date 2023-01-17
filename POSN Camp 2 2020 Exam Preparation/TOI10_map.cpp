//				13/4/2563
#include<bits/stdc++.h>
using namespace std;
int area[405][405];
char temp1;
vector< pair<pair<int,int>,bool> > v;
unsigned short int pos_i[40005],pos_j[40005];
int printed=1,n,m,k_i,k_j,temp,temp2,x;
queue<int> q;
void prepare(int x,int i,int idx){
	pos_i[i]=pos_i[x];
	pos_j[i]=pos_j[x];
	printed++;
	q.push(i);
}
void insert_right(int x,int i,int idx){
	prepare(x,i,idx);
	if(v[idx].second) pos_i[i]++;
	else pos_j[i]++;
	area[pos_i[i]][pos_j[i]]=i;
}
void insert_left(int x,int i,int idx){
	prepare(x,i,idx);
	if(v[idx].second) pos_i[i]--;
	else pos_j[i]--;
	if(k_i+k_j>pos_i[i]+pos_j[i]){
		k_i=pos_i[i];
		k_j=pos_j[i];
	}
	area[pos_i[i]][pos_j[i]]=i;
}
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<(m*n)-1;i++){
		//cin>>temp>>temp1>>temp2;
		scanf("%d %c %d",&temp,&temp1,&temp2);
		if(temp1=='U') v.push_back(make_pair(make_pair(temp,temp2),1));
		else v.push_back(make_pair(make_pair(temp,temp2),0));
		//edge[temp][temp2]=temp1;
	}
	q.push(0);
	pos_i[0]=n;
	pos_j[0]=m;
	area[pos_i[0]][pos_j[0]]=0;
	k_i=n;
	k_j=m;
	while(printed<m*n){
		x=q.front();
		q.pop();
		for(int i=0;i<v.size();i++){
			//if(edge[x][i]) insert_right(x,i);
			if(v[i].first.first==x){
				insert_right(x,v[i].first.second,i);
				v.erase(v.begin()+i);
			}
			//if(edge[i][x]) insert_left(x,i);
			if(v[i].first.second==x){
				insert_left(x,v[i].first.first,i);
				v.erase(v.begin()+i);
			}
		}
	}
	/*for(int i=0;i<2*n;i++){
		for(int j=0;j<2*m;j++){
			printf("%d ",area[i][j]);
		}
		printf("\n");
	}*/
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",area[i+k_i][j+k_j]);
		}
		printf("\n");
	}
}

