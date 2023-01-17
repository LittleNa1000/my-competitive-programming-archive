// maybe knapsack TT
#include <bits/stdc++.h>
using namespace std;
struct E
{
  int x, y;
  long long c;
  set<int> s;
};
int n, X, Y, x, y, x2, y2, sx, sy;
set<int> s;
long long c, dist[505][505];
bool visited[505][505];
vector<E> edge;
bool operator<(const E &a, const E &b)
{
  if (a.c == b.c)
  {
    return a.x + a.y > b.x + b.y;
  }
  return a.c > b.c;
}
priority_queue<E> pq;
int main()
{
  scanf("%d %d %d", &n, &X, &Y);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d %d %lld", &x, &y, &c);
    sx += x;
    sy += y;
    edge.push_back({x, y, c});
  }
  if (sx < X && sy < Y)
  {
    printf("-1");
    return 0;
  }
  for (int i = 0; i <= 500; ++i)
  {
    for (int j = 0; j <= 500; ++j)
    {
      dist[i][j] = LONG_LONG_MAX;
    }
  }
  dist[0][0] = 0;
  pq.push({0, 0, 0, s});
  // printf("push 1st element\n");
  while (!pq.empty())
  {
    x = pq.top().x;
    y = pq.top().y;
    c = pq.top().c;
    s = pq.top().s;
    pq.pop();
    if (visited[x][y])
      continue;
    visited[x][y] = 1;
    // printf("%d %d %lld\n", x, y, c);
    if (x >= X && y >= Y)
    {
      printf("%lld", c);
      return 0;
    }
    for (int i = 0; i < edge.size(); ++i)
    {
      if (s.find(i) != s.end())
        continue;
      s.insert(i);
      x2 = min(x + edge[i].x, 500);
      y2 = min(y + edge[i].y, 500);
      if (x2 >= 0 && x2 <= 500 && y2 >= 0 && y2 <= 500 && !visited[x2][y2] && c + edge[i].c <= dist[x2][y2])
      {
        dist[x2][y2] = c + edge[i].c;
        pq.push({x2, y2, dist[x2][y2], s});
      }
      s.erase(i);
    }
  }
  printf("-1");
}