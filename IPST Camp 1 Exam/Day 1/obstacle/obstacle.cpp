#include "obstacle.h"
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp_4;
int NN,MM;
void initialize(int N, int M, int Q,
		std::vector<std::vector<int>>& rowlen,
		std::vector<std::vector<int>>& collen)
{
  vector<vector<int>> dp_1(N, vector<int>(M));
  vector<vector<int>> dp_2(N, vector<int>(M));
  NN=N;
  MM=M;
  //static vector<vector<int>> dp_4(N, vector<int>(M));
  dp_4.resize(N);
  for(int i=0;i<N;++i){
	  dp_4[i].resize(M);
	  for(int j=0;j<M;++j){
		  if(!i&&!j) continue;
		  if(!i) dp_1[i][j]=dp_1[i][j-1]+rowlen[i][j-1];
		  else if(!j) dp_1[i][j]=dp_1[i-1][j]+collen[i-1][j];
		  else dp_1[i][j]=min(dp_1[i-1][j]+collen[i-1][j],dp_1[i][j-1]+rowlen[i][j-1]);
	  }
  }
  for(int i=N-1;i>=0;--i){
	  for(int j=M-1;j>=0;--j){
		  if(i==N-1&&j==M-1) continue;
		  if(i==N-1) dp_2[i][j]=dp_2[i][j+1]+rowlen[i][j];
		  else if(j==M-1) dp_2[i][j]=dp_2[i+1][j]+collen[i][j];
		  else dp_2[i][j]=min(dp_2[i][j+1]+rowlen[i][j],dp_2[i+1][j]+collen[i][j]);
	  }
  }
  for(int j=1;j<M;++j){
	  for(int i=N-1;i>=1;--i){
		  //could be better
		  if(i==N-1) dp_4[i][j]=dp_1[i][j-1]+dp_2[i][j]+rowlen[i][j-1];
		  else {
			dp_4[i][j]=min(dp_4[i+1][j],dp_1[i][j-1]+dp_2[i][j]+rowlen[i][j-1]);
			//dp_4[i][j]=min(INT_MAX,dp_1[i][j-1]+dp_2[i][j]+rowlen[i][j-1]);
		}
	  }
  }
  //dp_4=dp_4; //could do better?
//     for(int i=0;i<N;++i){
// 	  for(int j=0;j<M;++j){
// 		  printf("%d ",dp_1[i][j]);
// 	  }
// 	  printf("\n");
//   }
//     for(int i=0;i<N;++i){
// 	  for(int j=0;j<M;++j){
// 		  printf("%d ",dp_2[i][j]);
// 	  }
// 	  printf("\n");
//   }
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<M;++j){
	// 		printf("%d ",dp_4[i][j]);
	// 	}
	// 	printf("\n");
	// }
// 	3 5 2
// 1 1 7 8
// 1 1 3 6
// 9 4 1 1
// 4 3 1 2 4
// 6 2 2 3 8
// 0 4
// 1 2
}

int ask(int r, int c)
{
	if(c==0) return -1;
	if(r==NN-1&&c==MM-1) return -1;
	if(r==NN-1) return -1;
	return dp_4[r+1][c];
  
}

