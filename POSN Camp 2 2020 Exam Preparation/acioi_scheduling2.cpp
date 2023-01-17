//				3/5/2563
#include<bits/stdc++.h>
using namespace std;
short int ts,lim,n,temp1,process;
int temp;
bool p_empty;
unsigned long int t;
queue<short int> y,q;
queue<int> x;
short int test;
double ans,wt;
void testcase(){
	scanf("%hd %hd",&n,&ts);
	for(short int i=0;i<n;i++){
		scanf("%d %hd",&temp,&temp1);
		if(!i) t=temp;
		x.push(temp);
		y.push(temp1);
	}
	while(1){
		if(x.empty()&&q.empty()) break;
		//printf("T=%d ",t);
		if(t==x.front()){//		New Element to queue
			//printf("add \"new\" %hd to q ",y.front());
			q.push(y.front());
			x.pop();
			y.pop();
		}
		if(!p_empty){
			//printf("(%hd,%hd) -> ",process,lim);
			process--;
			lim--;
			//printf("(%hd,%hd) ",process,lim);
			if(process<=0){
				//printf("Process Finished ");
				p_empty=1;
			}
			else if(lim<=0){
				//printf("TS Exceeded, add %hd to q ",process);
				q.push(process);
				p_empty=1;
			}	
		}
		if(p_empty&&!q.empty()){//			Process something
			//printf("Add %hd to process ",q.front());
			process=q.front();
			q.pop();
			p_empty=0;
			lim=ts;
		}
		wt+=q.size();
		//printf("Waiting Time=%f\n",wt);
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

