/**************************************************
* �����ʼ���������Ҫ��¼�˺ź�����              *
* ����Ա1���˺ţ�account1                         *
*          ���룺111111                           *
* ����Ա2���˺ţ�account2                         *
*          ���룺222222                           *
* �������Ҫ�ȳ�ʼ��(ֻ��ʼ��һ��)                *
* ����Ա���˺����뱣����account1+.txt�ļ���       *
* ������Ϣ����owner.txt�ļ���                     *
*                                                 *
* ��ĿС�飺��ʮһ��                              *
* С���Ա������������ܣ�ŷ��骣�              *
*           Ф���������������֮����              *
***************************************************/


#include"parking_lot.h"
#include<stdbool.h>

void initialize_operation_system(void);
void operation_system(bool initialize_not);

//������
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
			//��ʼ�����򿪣������ļ����ù���Ա֪����Щ�û��Ѿ�����λ 
			initialize_not = true;
			initialize_location(a);
			//��ʼ��ͣ����ͼ
			break;
		case 2:
			print_all(parking);//�ù���Ա����������Ϣ 
			break;
		case 3:
			print_one_parking_info();
			break;
		case 4:
			printf("������Ҫɾ���ĳ�����Ϣ�����:");
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

//��ʼ������
void initialize_operation_system(void)
{

	printf("                          �q�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�r \n");
	printf("                   �q�T�T�T�T�T�T�g  Parkinglot System  �d�T�T�T�T�T�T�T�r\n");
	printf("                   �U                                    �U\n");
	printf("                   �U                                    �U\n");
	printf("                   �U     Ϊ����Ա�ṩ���ֲ������ܣ�     �U\n");
	printf("                   �U          1.�鿴������Ϣ��          �U\n");
	printf("                   �U          2.�鿴ͣ������Ϣ��        �U\n");
	printf("                   �U          3.��������Ϣ��          �U\n");
	printf("                   �U          4.����������Ϣ��          �U\n");
	printf("                   �U          5.ɾ��������Ϣ��          �U\n");
	printf("                   �U          6.�޸ĳ�����Ϣ��          �U\n");
	printf("                   �U                                    �U\n");
	printf("                   �U             �ɵ�11������           �U\n");
	printf("                   �U             ף��ʹ�����           �U\n");
	printf("                   �t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
	printf("                         *************************\n");
	printf("                         **   ��ʼ������ɹ�    **\n");
	return;
}


//�������
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
