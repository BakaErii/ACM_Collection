#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 111111
struct Tree
{
    int left, right, data;
    Tree() {left = right = data = 0;}
} T[22 * maxn];
int n, m, l, r, k, a[maxn], pos[maxn], id[maxn], root[maxn], cnt;
int cmp(int x, int y)
{
    return a[x] < a[y];
}
void insert(int &i, int l, int r, int x)
{
    T[++cnt] = T[i];
    i = cnt;
    T[i].data++;
    if (l == r) return ;
    int mid = (l + r) >> 1;
    if (x <= mid) insert(T[i].left, l, mid, x);
    else insert(T[i].right, mid + 1, r, x);
}
int query(int i, int j, int l, int r, int k)
{
    if (l == r) return l;
    int temp = T[T[j].left].data - T[T[i].left].data, mid = (l + r) >> 1;
    if (k <= temp) query(T[i].left, T[j].left, l, mid, k);
    else query(T[i].right, T[j].right, mid + 1, r, k - temp);
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            pos[i] = i;
        }
        sort(pos + 1, pos + n + 1, cmp);
        for (int i = 1; i <= n; i++)
            id[pos[i]] = i;
        cnt = root[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            root[i] = root[i - 1];
            insert(root[i], 1, n, id[i]);
        }
        while (m--)
        {
            scanf("%d%d%d", &l, &r, &k);
            int ans = query(root[l - 1], root[r], 1, n, k);
            printf("%d\n", a[pos[ans]]);
        }
    }
    return 0;
}