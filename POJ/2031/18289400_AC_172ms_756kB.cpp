#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 111

struct yuan {
    double x, y, z, r;
}p[maxn];

struct node {
    int u, v;
    double w;
    bool operator < (const node &a) const {
        return w < a.w;
    }
} edge[maxn*maxn];

int n, m;

double dis (yuan a, yuan b) {
    double xx = a.x-b.x, yy = a.y-b.y, zz = a.z-b.z;
    double d = sqrt (xx*xx + yy*yy + zz*zz);
    if (d <= a.r+b.r)
        return 0;
    return d - a.r - b.r;
}

#define find Find
int fa[maxn];
int find (int x) {
    return fa[x] == x ? fa[x] : fa[x] = find (fa[x]);
}

int main () {
    //freopen ("in", "r", stdin);
    while (cin >> n && n) {
        m = 0;
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i <= n; i++) {
            cin >> p[i].x >> p[i].y >> p[i].z >> p[i].r;
            for (int j = 1; j < i; j++) {
                edge[m].u = i, edge[m].v = j, edge[m++].w = dis (p[i], p[j]);
            }
        }
        sort (edge, edge+m);
        double ans = 0.0;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            int p1 = find (edge[i].u), p2 = find (edge[i].v);
            if (p1 != p2) {
                fa[p1] = p2;
                ans += edge[i].w;
                cnt++;
            }
            if (cnt == n-1)
                break;
        }
        printf ("%.3f\n", ans);
    }
    return 0;
}