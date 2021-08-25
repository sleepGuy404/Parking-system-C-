#include"parking_lot.h"

int number_occupied = 0;
//已经占用的车位数量，全局变量

void last_chance(int a);
//登陆时最后一次警告

//initialize
//初始化车主信息 
void initialize(truck_space parking[])
{
	int i;
	FILE* p1;

	number_occupied = 0;
	p1 = fopen("owner.txt", "r+");
	
	if (p1 == NULL){
		printf("open failed");
		printf("\n\n");
		printf("\t\t\tMade by Eleventh Group.\n");
		printf("\t\t\tAll Rights Reserved.\n\n");
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; i <= 9; i++){
		//从文件中读取信息
		fscanf(p1, "%s", parking[i].person_name); 
		fscanf(p1, "%s", parking[i].license_plate);
		fscanf(p1, "%s", parking[i].phone_number);
		fscanf(p1, "%f", &parking[i].price);
		fscanf(p1, "%d", &parking[i].condition);
		fscanf(p1, "%d-%d", &parking[i].m, &parking[i].n);
		number_occupied++;
		//计算读取车主的数量
	}
	printf("\n\n已成功读取信息\n");
	printf("\n共读到%d位车主信息.\n\n",number_occupied);
	
	return;
}


//print_all
//该函数将打印所有的车主信息
void print_all(truck_space parking[]) {
	int i;
	
	printf("显示所有车主信息：\n");
	printf("车主名字        电话号码            车牌号           车位位置\n");
	
	for (i = 0; i < MAX_PARKING_NUMBER; i++)
		if (parking[i].person_name[0] != '\0')
			printf("%-8s        %-11s\t    %-8s\t     %d-%d\n", parking[i].person_name,
				parking[i].phone_number, parking[i].license_plate,
				parking[i].m, parking[i].n);

	printf("\n已全部加载.\n");
	printf("\n共有%d位车主信息\n\n", number_occupied);
	return;
}


//read_line
//该函数将从文件或输入中读取字符
int read_line(char str[], int n) {
	int i = 0;
	int ch;

	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	
	return i;
}


//search
//通过输入电话号码来搜索车主的信息
//搜索成功返回i，失败则返回-1
int search(truck_space parking[])
{
	char phone_number_temp[PHONE_NUMBER];
	int i;
	
	printf("\n请输入您的电话号码:");
	read_line(phone_number_temp, 11);
	
	for (i = 0; i < number_occupied; i++)
		if (strcmp(phone_number_temp, parking[i].phone_number) == 0)
		{
			printf("该电话为第%d个用户的电话.\n", i + 1);
			return i;
		}
	printf("很抱歉没有找到您的信息。\n");
	
	return -1;
}


//print_one_parking_info
//打印一个车主的信息
void print_one_parking_info() {
	int a;
	
	a = search(parking);
	if (a == -1) {
		return;
	}
	
	printf("显示车主信息：\n");
	printf("车主名字        电话号码           车牌号           车位位置\n");
	printf("%s\t\t%s\t    %s\t     %d-%d\n\n", parking[a].person_name,
		parking[a].phone_number, parking[a].license_plate,
		parking[a].m, parking[a].n);
	printf("已显示.\n\n\n");
}


//delete_one
//删除一个车位信息
void delete_one(truck_space parking[], int number)
{
	int i;
	
	for (i = 0; i < strlen(parking[number - 1].license_plate); i++)
		parking[number - 1].license_plate[i] = '\0';//车牌号码清空
	for (i = 0; i < strlen(parking[number - 1].phone_number); i++)
		parking[number - 1].phone_number[i] = '\0';//电话号码清空
	for (i = 0; i < strlen(parking[number - 1].person_name); i++)
		parking[number - 1].person_name[i] = '\0';//人名清空		
	parking[number - 1].condition = 1;//车位状态改为空闲
	parking[number - 1].price = 0;//价格清空
	a[parking[number - 1].m][parking[number - 1].n] = '*';
	a[(parking[number - 1].m) + 1][parking[number - 1].n] = '*';
	
	number_occupied--;
	//车主信息数量减1

	return;
}


//initialize_location
//停车场的场景平面图初始化
void initialize_location(char a[N][N]) {
	//车位平面图显示
	int i, j, m, len, row;//后两个是行和列 

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = ' ';//全部空格 

	for (j = 0; j < N; j++) {//最后一行边框） 
		a[N-1][j] = '*';
	}

	len = 1;//行数 （车位两行的*代表一个，从第一行开始） 
	i = 1;
	j = 0;
	m = N - 1;

	for (; i < N - 1; i++) {
		a[i][j] = '*';//左侧边框 （列数为0） 
		for (row = 4; row < N - 2 && len < N - 1; row += 6) {//（在列数为4,10，16,22....处有车位 ） 
			a[len][row] = '*';
			a[len + 1][row] = '*';
		}

		len += 4;
		a[i][m] = '*';//车位之间空两行 
	}
	i = N - 2;
	j = 1;

	for (i=0; j < 10; j++) {
		a[i][j] = '*';
	}
	j = 16;
	for (i=0; j < N; j++)
		a[i][j] = '*';//车库大门 

	int q = 0;
	for (; q < MAX_PARKING_NUMBER; q++) {
		a[4 * parking[q].n - 3][6 * parking[q].m - 2] = 'S';
		a[4 * parking[q].n - 2][6 * parking[q].m - 2] = 'S';
	}
	
	return;
}


//manager_log_in 
void manager_log_in(void) {
	char a[10], b[10]; //用来存输入的账户和密码 
	FILE* fp;
	int i = 0;
	int n = 0;

	fp = fopen("account1+.txt", "r+");

	for (i = 0; i < MANAGER; i++) {

		fscanf(fp, "%s", manager[i].manager_name);
		fscanf(fp, "%s", manager[i].key);

		if (fp == NULL) {
			printf("Fail to open it.\n");
			return;
		}
	}
	printf("                         **   登陆系统已就绪    **\n");
	printf("                         *************************\n");
	for (i = 0; i < OWNER && n < 5; i++) {
		for (int j = 0; j < 10; j++) {
			a[j] = '\0';
			b[j] = '\0';
		}
		printf("                           请输入管理员的账户：\n");
		printf("                           ");
		read_line(a, 10);
		printf("                           请输入你的密码：\n");
		printf("                           ");
		read_line(b, 10);

		for (i = 0; i < MANAGER; i++)
			if ((strcmp(manager[i].manager_name, a) == 0) && (strcmp(manager[i].key, b) == 0)) {
				printf("欢迎登陆！\n\n\n");
				return;
			}

		n++;
		printf("Incorrect key!\nPlease try again.\n");
		printf("Wrong key for %d times.\n\n\n", n);
		last_chance(n);

	}
	printf("You have put in wrong keys for 5 times.\n");
	printf("\nPlease contact the suprior to upgrade the new keys.\n");
	printf("\n\n");
	printf("\t\t\tMade by Eleventh Group.\n");
	printf("\t\t\tAll Rights Reserved.\n\n");
	exit(EXIT_FAILURE);
}


//condition
void condition(void) {
	//该函数显示车位是否被售卖或者空闲 或者出租状态
	int i, j;
	char ch='Y', con;

	initialize_location(a);

	printf("\n\n\n");

	printf("condition{ SOLD='S',Available='*',RENT='R'}\n\n");
	//S为已售，*为空闲，R为已租

	do {
		printf("Please choose the condition you want to change(S for selling,R for rent):");
		scanf(" %c", &con);
		con = toupper(con);
		getchar();
		//读取换行符，勿改

		printf("To manager:the location the len is 1,2,3,4,5,6,7 \n \t\trow is 1,2,3,4\n \n");
		printf("Please enter the location your parking condition is changed( , ):  ");

		scanf("%d %d", &i, &j);
		if ((i > 0 && i < 8) && (j > 0 && j < 5))
			;
		else {
			printf("Sorry, no such space.\n");
			continue;
		}
		i = 4 * i - 3;
		j = 6 * j - 2;

		switch (con) {
		case 'R':
			if ((a[i][j] == 'R' && a[++i][j] == 'R')||
				(a[i][j] == 'S'&& a[++i][j] == 'S')) {
				printf("\nSorry, this place has been occupied.\n\n");
				break;
			}
			else
			{
				a[i][j] = 'R';
				a[++i][j] = 'R';
				break;
			}
		case 'S':
			if ((a[i][j] == 'R' && a[++i][j] == 'R') ||
				(a[i][j] == 'S' && a[++i][j] == 'S')) {
				printf("\nSorry, this place has been occupied.\n\n");
				break;
			}
			else
			{
				a[i][j] = 'S';
				a[++i][j] = 'S';
				break;
			}
		}

		printf("Continue?  (\"Y\"for continue,\"N\"for quit)  ");
		scanf(" %c", &ch);
		ch = toupper(ch);

		

	} while (ch != 'N');
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}

	printf("\n\nThis is the new parking conditon.\n");


}

//fee
void Rental_fee(void) {

	int time, money;
	char ch;
	
	printf("\n请选择租用套餐 月/日/小时(M/D/H):");
	ch = getchar();
	ch = toupper(ch);

	if (ch == 'M') {//按月计费 
		printf("请输入停放月数（不满1月按1月计）：");
		scanf("%d", &time);
		money = time * 300;
		printf("\n您的停车费用为：%d元", money);
	}
	else if (ch == 'D') {//按日计费 
		printf("请输入停放天数（不满1天按1天计）：");
		scanf("%d", &time);
		money = time * 15;
		printf("\n您的停车费用为：%d元", money);
	}
	else if (ch == 'H' ) {//小时计费 
		printf("请输入停放时间（不满1小时按1小时计）：");
		scanf("%d", &time);
		if (time <= 4)
			printf("\n您的停车费用为：%d元", 5);
		else if (4 < time && time <= 12) {
			money = 5 + (time - 4) * 1;
			printf("\n您的停车费用为：%d元", money);
		}
		else if (12 < time && time <= 24) {
			money = 15;
			printf("\n您的停车费用为：%d元", money);
		}
	}
	printf("\n");
}


//change
//租用后显示图形界面变化 
void insert(truck_space parking[])
{
	char ch;
	char plate[MAX_LICENSE_PLATE], name[MAX_PERSON_NAME], number[PHONE_NUMBER];//车牌，人名，电话号
	char cd;//状态 
	int x, y;//定位位置 
	int s;
	int v, w;
	for (;;)
	{
		printf("\n请选择车位(x，y)(x=1~4,y=1~7):");
		scanf("%1d %1d", &x, &y);//输入位置坐标
		
		
		if ((1 > x && x > 4) || (1 > y || y > 7)) {
			printf("不存在该车位，请重新输入。\n");
			continue;
		}

		v = 4 * x - 3;
		w = 6 * y - 2;
		if (a[v][w] == 'S') {
			printf("当前车位状态为：已售。请重新选择\n");
			continue;
		}
		if (a[v][w] == 'R') {
			printf("当前车位状态为：已租。请重新选择\n");
			continue;
		}
		if (a[v][w] == '*')
		{
			printf("当前车位状态为：空闲。");
			printf("\n请变更车位状态：(S for Sold, R for Rent)");
			scanf(" %c", &cd);
			cd = toupper(cd);
			
			//由空闲变为占用  
				a[v][w] = cd;
				a[v + 1][w] = cd;
				number_occupied++;
				s = number_occupied;
				if (cd == 'S')
				{
					s--;
					parking[s].m = x;
					parking[s].n = y;
					parking[s].condition = 0;
				}
				else if (cd == 'R')
				{
					s--;
					parking[s].m = x;
					parking[s].n = y;
					parking[s].condition = 2;
				}
				//若有新车主入驻，则显示以下信息 


				//将新信息插入到结构中
				printf("\n请输入车牌号："); 
				read_line(plate, MAX_LICENSE_PLATE);
				strcpy(parking[s].license_plate, plate);

				printf("请输入车主姓名：");
				read_line(name, MAX_PERSON_NAME);
				strcpy(parking[s].person_name, name);

				printf("请输入车主电话号：");
				read_line(number, PHONE_NUMBER);
				strcpy(parking[s].phone_number, number);
				printf("已成功录入用户信息\n");
		}

		//是否跳出该循环
		for (;;) {
			printf("\nContinue?  (\"Y\"for continue,\"N\"for quit)  ");
			scanf(" %c", &ch);
			ch = toupper(ch);
			if (ch == 'Y')
				break;
			else if (ch == 'N')
				return;
			else
			{
				printf("Invalid instruction.\n\n");
			}
		}
		
		
	}
}


//print_the_map 
void print_the_map(void)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
}

void quit(void)
{
	printf("\n\n");
	printf("\t\t\tMade by Eleventh Group.\n");
	printf("\t\t\tAll Rights Reserved.\n\n");
	exit(EXIT_SUCCESS);
}

void last_chance(int a)
{
	if (a == 4) {
		printf("WARNING: You only have the last chance to enter your ");
		printf("account number and password.\n");
	}		
}