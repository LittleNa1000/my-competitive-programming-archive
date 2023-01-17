//			23/3/2563
#include<bits/stdc++.h>
using namespace std;
set< pair<int,int> > s; 
//set< pair<int,int> >::iterator it;
pair<int,int> p;
main(){
	int n,m,temp1,temp2;
	char temp;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n+m;i++){
		cin>>temp;
		if(temp=='T'){
			scanf("%d %d",&temp1,&temp2);
			s.insert(make_pair(temp1,temp2));
		}
		else if(temp=='P'){
			p=*s.begin();
			printf("%d\n",p.second);
			if(s.size()>0) s.erase(s.begin());
		}
	}
}
