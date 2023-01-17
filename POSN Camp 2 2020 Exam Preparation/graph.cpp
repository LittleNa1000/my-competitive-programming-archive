#include<bits/stdc++.h>
using namespace std;

//#define CHECK 1
int graph[15000][15000],mst[15000][15000];
int vertice,edge,flag;
int visited[15000]; 

bool check_cycle(int v1,int v2){
	int idx=0;
	vector<int> checked;
	
	checked.push_back(v1);
	while(idx<checked.size()){
#ifdef CHECK
			//printf("Checking %d",checked[idx]+1);
#endif
		for(int i=0;i<vertice;i++){
		
			if(mst[checked[idx]][i]>0){
				//printf("Found %d",i+1);
				if(i==v2) return 1;
				bool has_duplicate=0;
				for(int j=0;j<checked.size();j++){
					if(i==checked[j]) {
						has_duplicate=1;
						break;
					}
					
				}
				if(!has_duplicate){
					//printf("Add %d to vector\n",i+1);
						checked.push_back(i);
				}
			}
		}
		//printf("\n");
		idx++;
	}
}
void find_max_weight(int &v1,int &v2){
	int max=0,u,v;
	for(int i=0;i<vertice;i++){
		for(int j=0;j<vertice;j++){
			if(graph[i][j]>max){
				max=graph[i][j];
				u=i;
				v=j;
			}
		}
	}
	v1=u;
	v2=v;
}
void display(){
	for(int i=0;i<vertice;i++){
		for(int j=0;j<vertice;j++){
			if(mst[i][j]>0) printf("%d %d %d\n",i,j,mst[i][j]);
		}
	}
}
main(){
	int x,y,z;
	scanf("%d %d",&vertice,&edge);
	for(int i=0;i<edge;i++){
		scanf("%d %d %d",&x,&y,&z);
		graph[x-1][y-1]=z;
		graph[y-1][x-1]=z;
	}
	/*vertice= 5;
	edge=6;
	graph[0][1]=5;
	graph[1][4]=15;
	graph[1][2]=12;
	graph[1][3]=8;
	graph[2][3]=9;
	graph[3][4]=20;*/
	int i = 0,a,b;
	while(i<vertice-1){
		find_max_weight(a,b);
		//printf("%d %d weight=%d\n",a+1,b+1,graph[a][b]);
		if(!check_cycle(a,b)){
			//printf("add %d %d %d to mst\n",a+1,b+1,graph[a][b]);
			flag+=graph[a][b]-1;
			mst[a][b]=graph[a][b];
			mst[b][a]=graph[a][b];
			graph[a][b]=0;
			graph[b][a]=0;
			visited[a]=1;
			visited[b]=1;
			i++;
		}
		else{
			graph[a][b]=0;
			graph[b][a]=0;
		}
		//i++;
	}
	printf("%d",flag);
	//display();
}
