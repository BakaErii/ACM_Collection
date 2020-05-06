/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-01 07:27:51
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

int h1, h2, m1, m2;
int minutes;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d:%d", &h1, &m1);
	scanf("%d:%d", &h2, &m2);
	minutes = h1 * 60 + m1 + h2 * 60 + m2;
	minutes /= 2;
	printf("%02d:%02d\n", minutes / 60, minutes % 60 );
	return 0;
}