/**************************************************
* 进入初始化界面后需要登录账号和密码              *
* 管理员1：账号：account1                         *
*          密码：111111                           *
* 管理员2：账号：account2                         *
*          密码：222222                           *
* 进入后需要先初始化(只初始化一次)                *
* 管理员的账号密码保存在account1+.txt文件中       *
* 车主信息存在owner.txt文件中                     *
*                                                 *
* 项目小组：第十一组                              *
* 小组成员：陈霆润，李玮杰，欧坤楠，              *
*           肖泊寒，杨振国，赵之航。              *
***************************************************/


#include"parking_lot.h"
#include<stdbool.h>

void initialize_operation_system(void);
void operation_system(bool initialize_not);

//主程序
int main(){
	int i;
	int n;
	int valid_count = 0;
	bool initialize_not = false;

	initialize_operation_system();
	manager_log_in();
   
	for (;;) {
		operation_system(initialize_not);
		scanf("%d", &i);
		while (getchar() != '\n')
			;
	
		switch (i) {
		case 1:
			initialize(parking);
			//初始化（打开）本地文件，让管理员知道哪些用户已经购买车位 
			initialize_not = true;
			initialize_location(a);
			//初始化停车场图
			break;
		case 2:
			print_all(parking);//让管理员看到车主信息 
			break;
		case 3:
			print_one_parking_info();
			break;
		case 4:
			printf("输入你要删除的车主信息的序号:");
			scanf("%d", &n);
			delete_one(parking, n);
			break;
		case 5:
			condition();
			break;
		case 6:
			Rental_fee();
			break;
		case 7:
			insert(parking);
			break;
		case 8:
			print_the_map();
			break;
		case 0:
			quit();
			break;
		default:
			printf("Invalid instruction.\n");
			valid_count++;
			break;
		}

		if (valid_count > 2) {
			printf("\nWARNING:You have typed wrong %d times", valid_count);
			if (valid_count >= 6) {
				printf("\nMalicious mistyped.\nExit Automatically.\n\n");
				quit();
			}
		}
	}
} 

//初始化界面
void initialize_operation_system(void)
{

	printf("                          ╭═════════════════════╮ \n");
	printf("                   ╭══════╣  Parkinglot System  ╠═══════╮\n");
	printf("                   ║                                    ║\n");
	printf("                   ║                                    ║\n");
	printf("                   ║     为管理员提供多种操作功能：     ║\n");
	printf("                   ║          1.查看所有信息；          ║\n");
	printf("                   ║          2.查看停车场信息；        ║\n");
	printf("                   ║          3.增添车主信息；          ║\n");
	printf("                   ║          4.搜索车主信息；          ║\n");
	printf("                   ║          5.删除车主信息；          ║\n");
	printf("                   ║          6.修改车主信息。          ║\n");
	printf("                   ║                                    ║\n");
	printf("                   ║             由第11组制作           ║\n");
	printf("                   ║             祝您使用愉快           ║\n");
	printf("                   ╰════════════════════════════════════╯\n");
	printf("                         *************************\n");
	printf("                         **   初始化界面成功    **\n");
	return;
}


//命令界面
void operation_system(bool initialize_not)
{
	printf("\n\n");
	printf("                   ************************************************************************\n");

	if (initialize_not == false) {
		printf("                   ** Code 1: for initialize;                                            **\n");
	}

	printf("                   ** Code 2: print all the owner's information;                         **\n");
	printf("                   ** Code 3: search the owner's information and print out;              **\n");
	printf("                   ** Code 4: delete one of the owner's information;                     **\n");
	printf("                   ** Code 5: change the condition of the picture of the parking lot;    **\n");
	printf("                   ** Code 6: for  temporary rental owner;                               **\n");
	printf("                   ** Code 7: change the the owner's information;                        **\n");
	printf("                   ** Code 8: print the current map of parking lot;                      **\n");
	printf("                   ** Code 0: quit;                                                      **\n");
	printf("                   ** Other codes: invalid instruction.                                  **\n");
	printf("                   ************************************************************************\n\n");
	printf("Please enter the code:");

	return;
}
