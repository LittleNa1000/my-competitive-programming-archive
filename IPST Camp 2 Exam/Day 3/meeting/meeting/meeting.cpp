#include<bits/stdc++.h>
#include "meeting.h"
using namespace std;
int mn,mx,idx,x,idx2,x2;
vector<int> qsum;
vector<int> best_meeting(int N, int Q,
			 vector<vector<int>>& roads,
			 vector<int>& lengths,
			 vector<int>& a,
			 vector<int>& b,
			 vector<int>& c){
	vector<int> ans;
	qsum.push_back(0);
	for(int i=0;i<N-1;++i){
		qsum.push_back(qsum[i]+lengths[i]);
	}
	for(int q=0;q<Q;++q){
		mn=min(a[q],min(b[q],c[q]));
		mx=max(a[q],max(b[q],c[q]));
		//printf("mn %d, mx %d, val %d\n",mn,mx,qsum[mn]+(qsum[mx]-qsum[mn])/2);
		idx=lower_bound(qsum.begin(),qsum.end(),qsum[mn]+(qsum[mx]-qsum[mn])/2)-qsum.begin();
		idx2=upper_bound(qsum.begin(),qsum.end(),qsum[mn]+(qsum[mx]-qsum[mn])/2)-qsum.begin()-1;
		x=max(qsum[mx]-qsum[idx],qsum[idx]-qsum[mn]);
		x2=max(qsum[mx]-qsum[idx2],qsum[idx2]-qsum[mn]);
		ans.push_back(min(x,x2));
	}
  	
  	return ans;
}
/*
10 2
0 1 1 
1 2 2 
3 2 3 
2 4 2 
7 6 5 
4 6 4 
4 5 6 
5 8 4 
5 9 3
0 3 6
0 3 1

6 4
0 1 10
1 2 10
2 3 10
3 4 10
4 5 10
0 2 5
2 3 5
3 4 5
1 4 5

6 4
0 1 1
1 2 2
2 3 3
3 4 2
4 5 5
0 2 5
2 3 5
3 4 5
1 4 5
*/
