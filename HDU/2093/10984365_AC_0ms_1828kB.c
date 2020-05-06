/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-08 13:28:08
 * 大项目 #滑稽
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int n, m, num, s, ac, i, j, len, temp;
	char tmp[11], swap[11];
	char stu_name[233][11];
	int stu_score[233][2];
	scanf("%d %d", &n, &m);
	getchar();
	//初始化变量
	num = 0;
	//对stu[num]进行操作
	while (scanf("%s", tmp) != EOF) {
		//调试
		//if (tmp[0] == '~')
		//{
		//	break;
		//}
		//初始化变量
		s = 0;
		ac = 0;
		strcpy(stu_name[num], tmp);
		//读取分数 累加得分于s 通过数为ac
		for (i = 0; i < n; i++)
		{
			//对数据进行处理转换为整数
			scanf("%s", tmp);
			//先判断是否AC
			if (tmp[0] == '-' || tmp[0] == '0')
			{
				//没有AC 不管了
				continue;
			} else {
				//AC了 先atoi转换分数 然后判断是否有错误提交再计算
				ac++;
				temp = atoi(tmp);
				len = strlen(tmp);
				for (j = 0; j < len; j++)
				{
					if (tmp[j] == '(')
					{
						strcpy(swap, &tmp[j + 1]);
						temp = temp + atoi(swap) * m;
						break;
					}
				}
				s = s + temp;
			}
		}
		//处理当前学生的得分赋值给stu_score
		stu_score[num][0] = ac;
		stu_score[num][1] = s;
		//换到下一个学生
		num++;
	}
	//定义排序变量
	int swap_ac, swap_score;
	//进行排序(AC数) 将大的放到前面
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1; j++)
		{
			if (stu_score[j][0] < stu_score[j + 1][0])
			{
				//j+1复制到swap中
				strcpy(swap, stu_name[j + 1]);
				swap_ac = stu_score[j + 1][0];
				swap_score = stu_score[j + 1][1];
				//j->j+1
				strcpy(stu_name[j + 1], stu_name[j]);
				stu_score[j + 1][0] = stu_score[j][0];
				stu_score[j + 1][1] = stu_score[j][1];
				//把swap中的变量赋值给j
				strcpy(stu_name[j], swap);
				stu_score[j][0] = swap_ac;
				stu_score[j][1] = swap_score;
			}
		}
	}
	//进行排序(时间分) 将小的放到前面
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1; j++)
		{
			if (stu_score[j][1] > stu_score[j + 1][1] && stu_score[j][0] == stu_score[j + 1][0])
			{
				//j+1复制到swap中
				strcpy(swap, stu_name[j + 1]);
				swap_ac = stu_score[j + 1][0];
				swap_score = stu_score[j + 1][1];
				//j->j+1
				strcpy(stu_name[j + 1], stu_name[j]);
				stu_score[j + 1][0] = stu_score[j][0];
				stu_score[j + 1][1] = stu_score[j][1];
				//把swap中的变量赋值给j
				strcpy(stu_name[j], swap);
				stu_score[j][0] = swap_ac;
				stu_score[j][1] = swap_score;
			}
		}
	}
	//输出
	for (i = 0; i < num; i++)
	{
		printf("%-10s %2d %4d\n", stu_name[i], stu_score[i][0], stu_score[i][1]);
	}
	//getchar();
	//getchar();
	return 0;
}