#ifndef PARKING_LOT
#define PARKING_LOT

#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LICENSE_PLATE 8     //���ƺų���
#define MAX_PERSON_NAME 30      //������󳤶�
#define MAX_PARKING_NUMBER 28  //��λ����
#define PHONE_NUMBER 12         //�绰���볤��   
#define MANAGER 2               //����Ա 
#define N 30                   //��λƽ��ͼ 
#define OWNER 10              //���� 

typedef struct {                             //���Ͷ��峵λ��Ϣ 
	char license_plate[MAX_LICENSE_PLATE];   //���ƺ�
	char person_name[MAX_PERSON_NAME];      //����
	int condition;                          //����״̬
	float price;                            //��λ�۸�
	char phone_number[PHONE_NUMBER];        //�绰����
	int m;
	int n;           //��λλ��
} truck_space;
//��λ��Ϣ

truck_space parking[MAX_PARKING_NUMBER];
//��λ����

typedef struct {
	char manager_name[10];	//����Ա�˺�
	char key[10];			//����Ա����
}manager_Info;

manager_Info manager[MANAGER];
//����Ա�˻�����������
 
char a[N][N];
//����ƽ��ͼ 

void Rental_fee();
//�Ʒ�

void initialize(truck_space parking[]);
//��ʼ����λ�����ļ��ж�ȡ����

void insert(truck_space parking[]);
//����λ��Ϣ���뵽������,numberΪѡ���ĳ�λ��λ��

void print_all(truck_space parking[]);
//�����еĳ�λ��Ϣ��ӡ����,

int search(truck_space parking[]);
//������λ��Ϣ������0Ϊ�ɹ�������1Ϊʧ��

void delete_one(truck_space parking[], int number);
//ɾ�����е�һ����λ��Ϣ��numberΪѡ���ĳ�λ��λ��

void manager_log_in(void);
//����Ա��½

int read_line(char str[], int n);
//��д

void initialize_location(char a[N][N]);
//��ʼ����ͼ����

void condition(void);
//�ı��ͼ���� 

void print_one_parking_info(void);
//��ʾ����������Ϣ

void print_the_map(void);
//��ӡ��ǰ��ͣ����ͼ 
 
void quit(void);
//�˳�����

#endif // !PARKING_LOT
