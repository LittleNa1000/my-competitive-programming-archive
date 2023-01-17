#include <bits/stdc++.h>
using namespace std;
int n,m,Q;
vector<int> a,b;
long long qsum[1005][1005];
bool is_sq(long long x){
	double y=sqrt(x);
	//printf("%lld %f\n",x,y);
	if(y==floor(y)) return 1;
	return 0;
}

void init_land(int N, int M, int P, std::vector<int> A, std::vector<int> B){
	n=N;
	m=M;
	Q=P;
	a=A;
	b=B;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(is_sq((long long)a[i-1]*(long long)b[j-1])) qsum[i][j]=1;
			qsum[i][j]+=qsum[i][j-1]+qsum[i-1][j]-qsum[i-1][j-1];
			
		}
	}
	// for(int i=1;i<=n;++i){
	// 	for(int j=1;j<=m;++j){
	// 		printf("%lld ",qsum[i][j]);
			
	// 	}
	// 	printf("\n");
	// }
}

long long answer_query(int r1, int c1, int r2, int c2){
	++r1;
	++c1;
	++r2;
	++c2;
	return qsum[r2][c2]-qsum[r2][c1-1]-qsum[r1-1][c2]+qsum[r1-1][c1-1]; 
	//return 0;
	// if(is_sq(((long long)a[r1]*(long long)b[c1]))) return 1;
	// else return 0;

}
/*
8 8 10
500000 400000 100000 200000 800000 900000 300000 700000 
200000 100000 400000 300000 800000 600000 500000 200000
0 7 0 7
1 6 1 6
2 5 2 5
3 4 3 4
4 3 4 3
5 2 5 2
6 1 6 1
7 0 7 0
0 1 1 3
0 4 3 4
*/

