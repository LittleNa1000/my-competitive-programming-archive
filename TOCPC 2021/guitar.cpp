//not sure
//maybe only 2 dimensions
#include <bits/stdc++.h>
using namespace std;
struct S
{
  long long c;
  int l, idx, t;
};
bool operator<(const S &a, const S &b)
{
  return a.c > b.c;
}
int N, M, K, tem, l, idx, t;
int arr[305];
long long c;
long long dist[305][305][305], cost[305][305];
bool visited[305][305][305];
priority_queue<S> pq;
int main()
{
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 1; i <= N; ++i)
  {
    for (int j = 1; j <= N; ++j)
    {
      scanf("%lld", &cost[i][j]);
    }
  }
  for (int i = 1; i <= M; ++i)
  {
    scanf("%d", &tem);
    arr[i] = tem;
  }
  for (int i = 0; i <= N; ++i)
  {
    for (int j = 0; j <= M; ++j)
    {
      for (int k = 0; k <= K; ++k)
      {
        dist[i][j][k] = LONG_LONG_MAX;
      }
    }
  }
  dist[0][0][K] = 0;
  pq.push({0, 0, 0, K});
  while (!pq.empty())
  {
    c = pq.top().c;
    l = pq.top().l; //Current Guitar Line
    idx = pq.top().idx;
    t = pq.top().t;
    pq.pop();
    if (visited[l][idx][t])
      continue;
    visited[l][idx][t] = 1;
    // printf("%lld %d %d %d\n", c, l, idx, t);
    if (idx == M)
    {
      printf("%lld", c);
      // printf("\n%lld", c + cost[l][arr[idx]]);
      return 0;
    }
    if (!visited[arr[idx + 1]][idx + 1][t] && c + cost[l][arr[idx + 1]] < dist[arr[idx + 1]][idx + 1][t])
    {
      dist[arr[idx + 1]][idx + 1][t] = c + cost[l][arr[idx + 1]];
      pq.push({dist[arr[idx + 1]][idx + 1][t], arr[idx + 1], idx + 1, t});
    }
    if (t)
    {
      if (!visited[l][idx + 1][t - 1] && c < dist[l][idx + 1][t - 1])
      {
        dist[l][idx + 1][t - 1] = c;
        pq.push({dist[l][idx + 1][t - 1], l, idx + 1, t - 1});
      }
    }
  }
  printf("-1");
}