#ifndef PARKING_LOT
#define PARKING_LOT

#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LICENSE_PLATE 8     //车牌号长度
#define MAX_PERSON_NAME 30      //人名最大长度
#define MAX_PARKING_NUMBER 28  //车位数量
#define PHONE_NUMBER 12         //电话号码长度   
#define MANAGER 2               //管理员 
#define N 30                   //车位平面图 
#define OWNER 10              //车主 

typedef struct {                             //类型定义车位信息 
	char license_plate[MAX_LICENSE_PLATE];   //车牌号
	char person_name[MAX_PERSON_NAME];      //人名
	int condition;                          //车辆状态
	float price;                            //车位价格
	char phone_number[PHONE_NUMBER];        //电话号码
	int m;
	int n;           //车位位置
} truck_space;
//车位信息

truck_space parking[MAX_PARKING_NUMBER];
//车位数量

typedef struct {
	char manager_name[10];	//管理员账号
	char key[10];			//管理员密码
}manager_Info;

manager_Info manager[MANAGER];
//管理员账户和密码数组
 
char a[N][N];
//车辆平面图 

void Rental_fee();
//计费

void initialize(truck_space parking[]);
//初始化车位，从文件中读取数据

void insert(truck_space parking[]);
//将车位信息输入到数组中,number为选定的车位的位置

void print_all(truck_space parking[]);
//将所有的车位信息打印出来,

int search(truck_space parking[]);
//搜索车位信息，返回0为成功，返回1为失败

void delete_one(truck_space parking[], int number);
//删除其中的一个车位信息，number为选定的车位的位置

void manager_log_in(void);
//管理员登陆

int read_line(char str[], int n);
//读写

void initialize_location(char a[N][N]);
//初始化地图界面

void condition(void);
//改变地图界面 

void print_one_parking_info(void);
//显示单个车主信息

void print_the_map(void);
//打印当前的停车场图 
 
void quit(void);
//退出程序

#endif // !PARKING_LOT
