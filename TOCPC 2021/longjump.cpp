#include <bits/stdc++.h>
using namespace std;
int N, M, W, sx, sy, ex, ey;
int main()
{
  scanf("%d %d %d", &N, &M, &W);
  scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
  if (W == 0)
  {
    int cnt = 0;
    if (sy == 1 || sy == M)
    {
      cnt++;
    }
    if (sx == 1 || sx == N)
    {
      cnt++;
    }

    if (sx == ex && sy == ey)
    {
      printf("0");
      return 0;
    }
    else if ((sy == 1 || sy == M) && sx == ex)
    {
      printf("1");
      return 0;
    }
    else if ((sx == 1 || sx == N) && sy == ey)
    {
      printf("1");
      return 0;
    }
    if (cnt == 2)
    {
      printf("2");
      return 0;
    }
  }
  printf("-1");
}