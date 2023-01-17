//maybe calulate paren string as BFSing
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
struct I
{
  int a, b, c;
};
vector<int> vec, edge[100005];
string str;
int score[100005][2], u, x, y, a, b, n, U, V;
ii val[100005];
int par[100005];
int cnt[100005][2];
long long ans;
bool visited[100005][2];
void bfs(int idx, int src)
{
  //can remove y and change to queue<ii> q;
  queue<I> q;
  q.push({src, 0, 0});
  if (idx)
  {
    vec.push_back(src);
    par[src] = -1;
  }
  while (!q.empty())
  {
    u = q.front().a;
    x = q.front().b;
    y = q.front().c;
    q.pop();
    if (visited[u][idx])
      continue;
    visited[u][idx] = 1;
    if (!idx)
    {
      if (str[u] == '(' && x >= 0)
      {
        x += 1;
      }
      if (str[u] == ')')
      {
        x -= 1;
      }
      score[u][idx] = x;
    }
    for (int i = 0; i < edge[u].size(); ++i)
    {
      if (!visited[edge[u][i]][idx])
      {
        q.push({edge[u][i], x, y});
        if (idx)
        {
          par[edge[u][i]] = u;
          vec.push_back(edge[u][i]);
        }
      }
    }
  }
}
int main()
{
  scanf("%d %d %d", &n, &U, &V);
  --U;
  --V;
  for (int i = 0; i < n - 1; ++i)
  {
    scanf("%d %d", &a, &b);
    --a;
    --b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  cin >> str;
  // bfs from U then V
  bfs(0, U);
  bfs(1, V);
  for (int i = 0; i < vec.size(); ++i)
  {
    u = vec[i];
    if (par[u] != -1)
    {
      x = val[par[u]].first;
      y = val[par[u]].second;
    }
    else
    {
      x = 0;
      y = 0;
    }
    if (str[u] == '(')
    {
      x -= 1;
    }
    if (str[u] == ')' && x >= 0)
    {
      x += 1;
    }
    val[u] = {x, y};
    score[u][1] = x;
    // if (y == 0)
    // {
    //   score[u][1] = x;
    // }
    // else
    // {
    //   score[u][1] = -1;
    // }
  }
  for (int i = 0; i < n; ++i)
  {
    // printf("score%d val(%d %d) par%d\n", score[i][1], val[i].first, val[i].second, par[i] + 1);
    for (int j = 0; j < 2; ++j)
    {
      if (score[i][j] >= 0)
      {
        cnt[score[i][j]][j]++;
      }
    }
  }
  for (int i = 0; i < 100005; ++i)
  {
    ans += (cnt[i][0] * cnt[i][1]);
  }
  printf("%lld", ans);
}