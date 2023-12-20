#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5+5;
vector<int>sgm[N << 2];
int a[N];
void build(int root, int l, int r)
{
    if (l == r)
    {
        sgm[root].push_back(a[l]);
        return;
    }
    int m = (l + r) >> 1;
    build((root << 1), l, m);
    build((root << 1) + 1, m + 1, r);
    merge(sgm[(root << 1)].begin(), sgm[(root << 1)].end(),sgm[(root << 1)+1].begin(),sgm[(root << 1)+1].end(),back_inserter(sgm[root]));
}
int get(int root, int l, int r, int x, int y, int val1, int val2)
{
    if (l > y || r < x || x > y)
        return 0;
    if (l >= x && r <= y)
    {
        int r_=upper_bound(begin(sgm[root]),end(sgm[root]),val2)-sgm[root].begin();
        int l_=lower_bound(begin(sgm[root]),end(sgm[root]),val1)-sgm[root].begin();
        return r_-l_;
    }
    int m = (l + r) >> 1;
    return get((root << 1), l, m, x, y, val1, val2) + get((root << 1) + 1, m + 1, r, x, y, val1, val2);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (m--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        cout << get(1, 1, n, x, y, l, r) << "\n";
    }
    return 0;
}