/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-25 18:23:54
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

using namespace std;

const int maxN = 10005;

struct Ant {
	int pos;
	int id;
	int toward;
	bool operator < (const Ant & a) const {
		return pos < a.pos;
	}
} A[maxN], B[maxN];

int T, l, n, t;
int order[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int kase = 0;
	char to[5];
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &l, &t, &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d %s", &B[i].pos, to);
			if(to[0] == 'L')
				B[i].toward = -1;
			else
				B[i].toward = 1;
			B[i].id = i;
			A[i] = B[i];
			A[i].pos = B[i].pos + (B[i].toward * t);
		}
		sort(B + 1, B + 1 + n);
		for(int i = 1; i <= n; i++)
			order[B[i].id] = i;
		sort(A + 1, A + 1 + n);
		for(int i = 1; i < n; i++)
			if(A[i].pos == A[i + 1].pos)
				A[i].toward = A[i + 1].toward = 0;
		printf("Case #%d:\n", ++kase );
		for(int i = 1; i <= n; i++) {
			int currId = order[i];
			if(A[currId].pos < 0 || A[currId].pos > l)
				printf("Fell off\n");
			else {
				switch(A[currId].toward) {
				case -1:
					printf("%d L\n", A[currId].pos);
					break;
				case 0:
					printf("%d Turning\n", A[currId].pos);
					break;
				case 1:
					printf("%d R\n", A[currId].pos);
					break;
				}
			}
		}
		putchar('\n');
	}
	return 0;
}