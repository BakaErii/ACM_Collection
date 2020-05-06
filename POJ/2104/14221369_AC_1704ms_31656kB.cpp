/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-06-08 17:56:35
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define leftSon left,mid
#define rightSon mid+1,right

using namespace std;

const int maxN = 100005;

struct Node
{
	int left;
	int right;
	int count;
	Node(void) {
		left = right = count = 0;
		return;
	}
} Tree[maxN * 25];

int n, m, cnt;
int arr[maxN];
int pos[maxN];
int root[maxN];
int index[maxN];

bool cmp(int a, int b) {
	return arr[a] < arr[b];
}

//插入操作
void insert(int & ptr, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	Tree[++cnt] = Tree[ptr];
	ptr = cnt;
	Tree[ptr].count++;
	if (left == right)
		return;
	if (curr <= mid)
		insert(Tree[ptr].left, leftSon, curr);
	else
		insert(Tree[ptr].right, rightSon, curr);
}

//查询操作
int querySection(int leftSection, int rightSection, int left, int right, int kth) {
	int mid = (left + right) >> 1;
	int tmp = Tree[Tree[rightSection].left].count - Tree[Tree[leftSection].left].count;
	if (left == right)
		return left;
	if (kth <= tmp)
		querySection(Tree[leftSection].left, Tree[rightSection].left, leftSon, kth);
	else
		querySection(Tree[leftSection].right, Tree[rightSection].right, rightSon, kth - tmp);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, leftSection, rightSection, kth, ans;
	while (~scanf("%d %d", &n, &m)) {
		for (i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			pos[i] = i;
		}
		sort(pos + 1, pos + n + 1, cmp);
		for (i = 1; i <= n; i++)
			index[pos[i]] = i;
		cnt = root[0] = 0;
		for (i = 1; i <= n; i++) {
			root[i] = root[i - 1];
			insert(root[i], 1, n, index[i]);
		}
		while (m--) {
			scanf("%d %d %d", &leftSection, &rightSection, &kth);
			ans = querySection(root[leftSection - 1], root[rightSection], 1, n, kth);
			printf("%d\n", arr[pos[ans]]);
		}
	}
	return 0;
}