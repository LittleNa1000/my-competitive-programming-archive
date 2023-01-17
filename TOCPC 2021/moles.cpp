//มองเป็นกราฟ???
//maybe pq
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int n, start, a, b, ans;
int val[1000005];
vector<ii> v;
int main()
{
  scanf("%d %d", &n, &start);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d %d", &a, &b);
    v.push_back({b, a});
  }
  // Subtask 2 3
  // v.push_back({0, start});
  // sort(v.begin(), v.end());
  // for (int i = 0; i <= n; ++i)
  // {
  //   ans = max(ans, val[i]);
  //   for (int j = i + 1; j <= n; ++j)
  //   {
  //     //maybe only <
  //     if (abs(v[i].second - v[j].second) <= v[j].first - v[i].first)
  //     {
  //       val[j] = max(val[j], val[i] + 1);
  //     }
  //   }
  // }
  // printf("%d", ans);
  // Subtask 1
  // for (int i = 0; i < n; ++i)
  // {
  //   if (abs(start - s[i]) < t[i])
  //   {
  //     printf("%d", n - i);
  //     return 0;
  //   }
  // }
}