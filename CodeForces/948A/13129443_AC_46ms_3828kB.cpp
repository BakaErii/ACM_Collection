/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-21 16:21:26
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

int r, c;
char arr[501][501];

bool is_Protect(int x, int y) {
	if (x + 1 < r && arr[x + 1][y] == 'W')
		return false;
	if (x + 1 < r && arr[x + 1][y] == '.')
		arr[x + 1][y] = 'D';
	if (y + 1 < c && arr[x][y + 1] == 'W')
		return false;
	if (y + 1 < c && arr[x][y + 1] == '.')
		arr[x][y + 1] = 'D';
	if (x - 1 >= 0 && arr[x - 1][y] == 'W')
		return false;
	if (x - 1 >= 0 && arr[x - 1][y] == '.')
		arr[x - 1][y] = 'D';
	if (y - 1 >= 0 && arr[x][y - 1] == 'W')
		return false;
	if (y - 1 >= 0 && arr[x][y - 1] == '.')
		arr[x][y - 1] = 'D';
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	scanf("%d %d", &r, &c);
	getchar();
	for (i = 0; i < r; i++)
		gets(arr[i]);
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			if(arr[i][j]=='S')
				if(is_Protect(i,j)==false){
					printf("No\n");
					return 0;
				}
	printf("Yes\n");
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++)
			putchar(arr[i][j]);
		putchar('\n');
	}
	return 0;
}