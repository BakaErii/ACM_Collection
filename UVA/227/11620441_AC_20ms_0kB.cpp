/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-18 17:28:54
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	char line[5][10];
	string command;
	int i, j, x, y, isBreak, num;
	num = 0;
	while (cin.getline(line[0], sizeof(line[0])) && line[0][0] != 'Z') {
		cin.getline(line[1], sizeof(line[1]));
		cin.getline(line[2], sizeof(line[2]));
		cin.getline(line[3], sizeof(line[3]));
		cin.getline(line[4], sizeof(line[4]));
		//处理空位
		for (j = 0; j < 5; j++) {
			for (i = 0; i < 5; i++)
			{
				if (line[j][i] == ' ' || line[j][i] == '\0') {
					x = i;
					y = j;
				}
			}
		}
		// cout << x << y << endl;
		//处理指令
		isBreak = 0;
		while (getline(cin, command)) {
			for (i = 0; i < (int)command.length(); i++)
			{
				switch (command[i]) {
				case 'A':
					if (y == 0)
						isBreak = 1;
					else {
						line[y][x] = line[y - 1][x];
						line[y - 1][x] = ' ';
						y--;
					}
					break;
				case 'B':
					if (y == 4)
						isBreak = 1;
					else {
						line[y][x] = line[y + 1][x];
						line[y + 1][x] = ' ';
						y++;
					}
					break;
				case 'R':
					if (x == 4)
						isBreak = 1;
					else {
						line[y][x] = line[y][x + 1];
						line[y][x + 1] = ' ';
						x++;
					}
					break;
				case 'L':
					if (x == 0)
						isBreak = 1;
					else {
						line[y][x] = line[y][x - 1];
						line[y][x - 1] = ' ';
						x--;
					}
					break;
				case '0': break;
				default: isBreak = 1; break;
				}
				// for (j = 0; j < 5; j++)
				// 	printf("[%c %c %c %c %c]\n", line[j][0], line[j][1], line[j][2], line[j][3], line[j][4]);
				// cout << endl;
			}
			if (command[(int)command.length() - 1] == '0')
				break;
		}
		if (isBreak == 1) {
			if (num != 0)
				cout << endl;
			cout << "Puzzle #" << ++num << ":" << endl;
			cout << "This puzzle has no final configuration." << endl;
		} else {
			if (num != 0)
				cout << endl;
			cout << "Puzzle #" << ++num << ":" << endl;
			for (i = 0; i < 5; i++)
				printf("%c %c %c %c %c\n", line[i][0], line[i][1], line[i][2], line[i][3], line[i][4]);
		}
	}
	return 0;
}