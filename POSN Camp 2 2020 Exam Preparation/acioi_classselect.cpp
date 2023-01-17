//			27/3/2563
#include<bits/stdc++.h>
using namespace std;
struct classroom{
	int s,f,c; //Start, Finish, Count
};
inline bool operator<(const classroom& lhs,const classroom& rhs){
	return lhs.c<rhs.c;
}
multiset<struct classroom> room;
multiset<struct classroom>::reverse_iterator it;
struct classroom ctemp;
vector<int> start,finish;
int ans,temp,n,result,shortest,idx;
bool have_room;
int get_shortest(){
	shortest=INT_MAX;
	result=0;
	for(int i=0;i<start.size();i++){
		if(finish[i]-start[i]<shortest) {
			shortest=finish[i]-start[i];
			result=i;
		}
	}
	printf("\nShortest: Index=%d  Start=%d  Finish=%d\n",result,start[result],finish[result]);
	return result;
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		start.push_back(temp);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		finish.push_back(temp);
	}
	for(int i=0;i<n;i++){
		have_room=0;
		idx=get_shortest();
		for(it=room.rbegin();it!=room.rend();it++){
			ctemp=*it;
			if(finish[idx]<=ctemp.s){// left
				ctemp.s=start[idx];
				printf("size=%d\n",ctemp.c);
				ctemp.c++;
				printf("A Room has been extended (Left) to %d - %d size=%d\n",ctemp.s,ctemp.f,ctemp.c);
				if(ctemp.c>ans) ans=ctemp.c;
				have_room=1;
				break;
			}
			else if(start[idx]>=ctemp.f){// right
				ctemp.f=finish[idx];
				printf("size=%d\n",ctemp.c);
				ctemp.c++;
				printf("A Room has been extended (Right) to %d - %d size=%d\n",ctemp.s,ctemp.f,ctemp.c);
				if(ctemp.c>ans) ans=ctemp.c;
				have_room=1;
				break;
			}
		}
		if(!have_room){
			printf("Create a new room #%d: s=%d f=%d\n",room.size(),start[idx],finish[idx]);
			ctemp.s=start[idx];
			ctemp.f=finish[idx];
			ctemp.c=1;
			room.insert(ctemp);
		}
		start.erase(start.begin()+idx);
		finish.erase(finish.begin()+idx);
	}
	printf("%d",ans);
}
