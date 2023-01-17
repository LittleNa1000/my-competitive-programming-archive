//				4/5/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
short int test,n;
int temp,temp1,temp2,process,process_p;
bool p_empty;
long int t;
double wt,ans;
queue<int> x;
queue<pr> y;
priority_queue<pr,vector<pr>,greater<pr> > pq;
pr a;
void decrease_prior(){
	priority_queue<pr,vector<pr>,greater<pr> > pq2;
	for(short int i=0;i<pq.size();i++){
		a=pq.top();
		pq2.push(make_pair(a.first-1,a.second));
	}
	pq=pq2;
	process_p--;
}
void testcase(){
	scanf("%hd",&n);
	for(short int i=0;i<n;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		x.push(temp);
		y.push(make_pair(temp1,temp2));
	}
	t=x.front();
	while(!pq.empty()||!x.empty()){
		//printf("%ld: ",t);
		if(t==x.front()){
			pq.push(y.front());
			y.pop();
			x.pop();
			//printf("New Task (#%d) to q. ",n-x.size());
		}
		if(!p_empty){
			//printf("Process: %d->%d ",process,process-1);
			process--;
			a=pq.top();
			if(process<=0){
				//printf("Task finished. ");
				p_empty=1;
			}
			else if(a.first<process_p){
				//printf(" move (%d,%d) from process to q. ",process_p,process);
				p_empty=1;
				pq.push(make_pair(process_p,process));
			}
		}
		if(p_empty&&!pq.empty()){
			a=pq.top();
			pq.pop();
			//printf("add (%d,%d) to process. ",a.first,a.second);
			process=a.second; 
			process_p=a.first;
			p_empty=0;
		}
		decrease_prior();
		//printf("Wait Time=%.0lf\n",wt);
		wt+=pq.size();
		t++;
	}
	ans=wt/n;
	printf("%.7lf\n",ans);
}
main(){
	scanf("%hd",&test);
	while(test--){
		p_empty=1;
		wt=0;
		testcase();
	}
}

