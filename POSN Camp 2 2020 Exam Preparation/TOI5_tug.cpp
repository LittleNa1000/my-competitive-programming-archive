//				3/4/2563
#include<bits/stdc++.h>
using namespace std;
unsigned short int n;
int temp; //temp and ans is the same
int a_team[2002],b_team[2002];
set<int> s;
main(){
	scanf("%u",&n);
	for(short int i=0;i<n;i++){
		scanf("%d",&temp);
		s.insert(temp);
	}
	//printf("size=%d\n",s.size());
	for(short int i=0;i<n;i++){
		a_team[i]=*s.begin();
		s.erase(s.begin());
	}
	s.clear();
	for(short int i=0;i<n;i++){
		scanf("%d",&temp);
		s.insert(temp);
	}
	for(short int i=0;i<n;i++){
		b_team[i]=*s.begin();
		s.erase(s.begin());
	}
	s.clear();
	temp=0;
	for(short int i=0;i<n;i++){
	    //printf("i=%d %d %d\n",i,a_Team[i],*s.begin());
		temp+=abs(a_team[i]-b_team[i]);
	}
	printf("%ld",temp);
}
