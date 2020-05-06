/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-26 22:12:45
 *
 */

#include <bits/stdc++.h>

using namespace std;

int arr[4][4];

void left(void);
void up(void);
void right(void);
void down(void);
void print(void);

int main(void) {
	int i, command;
	//读入数据
	for (i = 0; i < 4; i++)
		scanf("%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
	scanf("%d", &command);
	switch (command) {
	case 0: left(); break;
	case 1: up(); break;
	case 2: right(); break;
	case 3: down(); break;
	}
	print();
	return 0;
}

void print(void) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return;
}

void left(void) {
	//全局左移
	int i, j, k;
	for (i = 0; i < 4; i++) {
		k = 0;
		for (j = 0; j < 4; j++)
			if (arr[i][j] != 0) {
				swap(arr[i][j], arr[i][k++]);
			}
	}
	//计算
	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			if (arr[i][j] == arr[i][j + 1]) {
				arr[i][j] *= 2;
				arr[i][j + 1] = 0;
				j++;
			}
	//继续左移
	for (i = 0; i < 4; i++) {
		k = 0;
		for (j = 0; j < 4; j++)
			if (arr[i][j] != 0) {
				swap(arr[i][j], arr[i][k++]);
			}
	}
	return;
}

void up(void) {
	//上移
	int i, j, k;
	for (j = 0; j < 4; j++) {
		k = 0;
		for (i = 0; i < 4; i++)
			if (arr[i][j] != 0) {
				swap(arr[i][j], arr[k++][j]);
			}
	}
	//计算
	for (j = 0; j < 4; j++)
		for (i = 0; i < 3; i++)
			if (arr[i][j] == arr[i + 1][j]) {
				arr[i][j] *= 2;
				arr[i + 1][j] = 0;
				i++;
			}
	//继续上移
	for (j = 0; j < 4; j++) {
		k = 0;
		for (i = 0; i < 4; i++)
			if (arr[i][j] != 0) {
				swap(arr[i][j], arr[k++][j]);
			}
	}
	return ;
}

void right(void) {
	//全局右移
	int i, j, k;
	for (i = 0; i < 4; i++) {
		k = 3;
		for (j = 3; j >= 0; j--)
			if (arr[i][j] != 0) {
				swap(arr[i][j], arr[i][k--]);
			}
	}
	//计算
	for (i = 0; i < 4; i++)
		for (j = 3; j > 0; j--)
			if (arr[i][j] == arr[i][j - 1]) {
				arr[i][j] *= 2;
				arr[i][j - 1] = 0;
				j--;
			}
	//继续右移
	for (i = 0; i < 4; i++) {
		k = 3;
		for (j = 3; j >= 0; j--)
			if (arr[i][j] != 0) {
				swap(arr[i][j], arr[i][k--]);
			}
	}
	return;
}

void down(void) {
	//下移
	int i, j, k;
	for (j = 0; j < 4; j++) {
		k = 3;
		for (i = 3; i >= 0; i--)
			if (arr[i][j] != 0) {
				swap(arr[i][j], arr[k--][j]);
			}
	}
	//计算
	for (j = 0; j < 4; j++)
		for (i = 3; i > 0; i--)
			if (arr[i][j] == arr[i - 1][j]) {
				arr[i][j] *= 2;
				arr[i - 1][j] = 0;
				i--;
			}
	//继续下移
	for (j = 0; j < 4; j++) {
		k = 3;
		for (i = 3; i >= 0; i--)
			if (arr[i][j] != 0) {
				swap(arr[i][j], arr[k--][j]);
			}
	}
	return ;
}