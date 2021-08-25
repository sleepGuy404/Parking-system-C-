#include"parking_lot.h"

int number_occupied = 0;
//�Ѿ�ռ�õĳ�λ������ȫ�ֱ���

void last_chance(int a);
//��½ʱ���һ�ξ���

//initialize
//��ʼ��������Ϣ 
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
		//���ļ��ж�ȡ��Ϣ
		fscanf(p1, "%s", parking[i].person_name); 
		fscanf(p1, "%s", parking[i].license_plate);
		fscanf(p1, "%s", parking[i].phone_number);
		fscanf(p1, "%f", &parking[i].price);
		fscanf(p1, "%d", &parking[i].condition);
		fscanf(p1, "%d-%d", &parking[i].m, &parking[i].n);
		number_occupied++;
		//�����ȡ����������
	}
	printf("\n\n�ѳɹ���ȡ��Ϣ\n");
	printf("\n������%dλ������Ϣ.\n\n",number_occupied);
	
	return;
}


//print_all
//�ú�������ӡ���еĳ�����Ϣ
void print_all(truck_space parking[]) {
	int i;
	
	printf("��ʾ���г�����Ϣ��\n");
	printf("��������        �绰����            ���ƺ�           ��λλ��\n");
	
	for (i = 0; i < MAX_PARKING_NUMBER; i++)
		if (parking[i].person_name[0] != '\0')
			printf("%-8s        %-11s\t    %-8s\t     %d-%d\n", parking[i].person_name,
				parking[i].phone_number, parking[i].license_plate,
				parking[i].m, parking[i].n);

	printf("\n��ȫ������.\n");
	printf("\n����%dλ������Ϣ\n\n", number_occupied);
	return;
}


//read_line
//�ú��������ļ��������ж�ȡ�ַ�
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
//ͨ������绰������������������Ϣ
//�����ɹ�����i��ʧ���򷵻�-1
int search(truck_space parking[])
{
	char phone_number_temp[PHONE_NUMBER];
	int i;
	
	printf("\n���������ĵ绰����:");
	read_line(phone_number_temp, 11);
	
	for (i = 0; i < number_occupied; i++)
		if (strcmp(phone_number_temp, parking[i].phone_number) == 0)
		{
			printf("�õ绰Ϊ��%d���û��ĵ绰.\n", i + 1);
			return i;
		}
	printf("�ܱ�Ǹû���ҵ�������Ϣ��\n");
	
	return -1;
}


//print_one_parking_info
//��ӡһ����������Ϣ
void print_one_parking_info() {
	int a;
	
	a = search(parking);
	if (a == -1) {
		return;
	}
	
	printf("��ʾ������Ϣ��\n");
	printf("��������        �绰����           ���ƺ�           ��λλ��\n");
	printf("%s\t\t%s\t    %s\t     %d-%d\n\n", parking[a].person_name,
		parking[a].phone_number, parking[a].license_plate,
		parking[a].m, parking[a].n);
	printf("����ʾ.\n\n\n");
}


//delete_one
//ɾ��һ����λ��Ϣ
void delete_one(truck_space parking[], int number)
{
	int i;
	
	for (i = 0; i < strlen(parking[number - 1].license_plate); i++)
		parking[number - 1].license_plate[i] = '\0';//���ƺ������
	for (i = 0; i < strlen(parking[number - 1].phone_number); i++)
		parking[number - 1].phone_number[i] = '\0';//�绰�������
	for (i = 0; i < strlen(parking[number - 1].person_name); i++)
		parking[number - 1].person_name[i] = '\0';//�������		
	parking[number - 1].condition = 1;//��λ״̬��Ϊ����
	parking[number - 1].price = 0;//�۸����
	a[parking[number - 1].m][parking[number - 1].n] = '*';
	a[(parking[number - 1].m) + 1][parking[number - 1].n] = '*';
	
	number_occupied--;
	//������Ϣ������1

	return;
}


//initialize_location
//ͣ�����ĳ���ƽ��ͼ��ʼ��
void initialize_location(char a[N][N]) {
	//��λƽ��ͼ��ʾ
	int i, j, m, len, row;//���������к��� 

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = ' ';//ȫ���ո� 

	for (j = 0; j < N; j++) {//���һ�б߿� 
		a[N-1][j] = '*';
	}

	len = 1;//���� ����λ���е�*����һ�����ӵ�һ�п�ʼ�� 
	i = 1;
	j = 0;
	m = N - 1;

	for (; i < N - 1; i++) {
		a[i][j] = '*';//���߿� ������Ϊ0�� 
		for (row = 4; row < N - 2 && len < N - 1; row += 6) {//��������Ϊ4,10��16,22....���г�λ �� 
			a[len][row] = '*';
			a[len + 1][row] = '*';
		}

		len += 4;
		a[i][m] = '*';//��λ֮������� 
	}
	i = N - 2;
	j = 1;

	for (i=0; j < 10; j++) {
		a[i][j] = '*';
	}
	j = 16;
	for (i=0; j < N; j++)
		a[i][j] = '*';//������� 

	int q = 0;
	for (; q < MAX_PARKING_NUMBER; q++) {
		a[4 * parking[q].n - 3][6 * parking[q].m - 2] = 'S';
		a[4 * parking[q].n - 2][6 * parking[q].m - 2] = 'S';
	}
	
	return;
}


//manager_log_in 
void manager_log_in(void) {
	char a[10], b[10]; //������������˻������� 
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
	printf("                         **   ��½ϵͳ�Ѿ���    **\n");
	printf("                         *************************\n");
	for (i = 0; i < OWNER && n < 5; i++) {
		for (int j = 0; j < 10; j++) {
			a[j] = '\0';
			b[j] = '\0';
		}
		printf("                           ���������Ա���˻���\n");
		printf("                           ");
		read_line(a, 10);
		printf("                           ������������룺\n");
		printf("                           ");
		read_line(b, 10);

		for (i = 0; i < MANAGER; i++)
			if ((strcmp(manager[i].manager_name, a) == 0) && (strcmp(manager[i].key, b) == 0)) {
				printf("��ӭ��½��\n\n\n");
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
	//�ú�����ʾ��λ�Ƿ��������߿��� ���߳���״̬
	int i, j;
	char ch='Y', con;

	initialize_location(a);

	printf("\n\n\n");

	printf("condition{ SOLD='S',Available='*',RENT='R'}\n\n");
	//SΪ���ۣ�*Ϊ���У�RΪ����

	do {
		printf("Please choose the condition you want to change(S for selling,R for rent):");
		scanf(" %c", &con);
		con = toupper(con);
		getchar();
		//��ȡ���з������

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
	
	printf("\n��ѡ�������ײ� ��/��/Сʱ(M/D/H):");
	ch = getchar();
	ch = toupper(ch);

	if (ch == 'M') {//���¼Ʒ� 
		printf("������ͣ������������1�°�1�¼ƣ���");
		scanf("%d", &time);
		money = time * 300;
		printf("\n����ͣ������Ϊ��%dԪ", money);
	}
	else if (ch == 'D') {//���ռƷ� 
		printf("������ͣ������������1�찴1��ƣ���");
		scanf("%d", &time);
		money = time * 15;
		printf("\n����ͣ������Ϊ��%dԪ", money);
	}
	else if (ch == 'H' ) {//Сʱ�Ʒ� 
		printf("������ͣ��ʱ�䣨����1Сʱ��1Сʱ�ƣ���");
		scanf("%d", &time);
		if (time <= 4)
			printf("\n����ͣ������Ϊ��%dԪ", 5);
		else if (4 < time && time <= 12) {
			money = 5 + (time - 4) * 1;
			printf("\n����ͣ������Ϊ��%dԪ", money);
		}
		else if (12 < time && time <= 24) {
			money = 15;
			printf("\n����ͣ������Ϊ��%dԪ", money);
		}
	}
	printf("\n");
}


//change
//���ú���ʾͼ�ν���仯 
void insert(truck_space parking[])
{
	char ch;
	char plate[MAX_LICENSE_PLATE], name[MAX_PERSON_NAME], number[PHONE_NUMBER];//���ƣ��������绰��
	char cd;//״̬ 
	int x, y;//��λλ�� 
	int s;
	int v, w;
	for (;;)
	{
		printf("\n��ѡ��λ(x��y)(x=1~4,y=1~7):");
		scanf("%1d %1d", &x, &y);//����λ������
		
		
		if ((1 > x && x > 4) || (1 > y || y > 7)) {
			printf("�����ڸó�λ�����������롣\n");
			continue;
		}

		v = 4 * x - 3;
		w = 6 * y - 2;
		if (a[v][w] == 'S') {
			printf("��ǰ��λ״̬Ϊ�����ۡ�������ѡ��\n");
			continue;
		}
		if (a[v][w] == 'R') {
			printf("��ǰ��λ״̬Ϊ�����⡣������ѡ��\n");
			continue;
		}
		if (a[v][w] == '*')
		{
			printf("��ǰ��λ״̬Ϊ�����С�");
			printf("\n������λ״̬��(S for Sold, R for Rent)");
			scanf(" %c", &cd);
			cd = toupper(cd);
			
			//�ɿ��б�Ϊռ��  
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
				//�����³�����פ������ʾ������Ϣ 


				//������Ϣ���뵽�ṹ��
				printf("\n�����복�ƺţ�"); 
				read_line(plate, MAX_LICENSE_PLATE);
				strcpy(parking[s].license_plate, plate);

				printf("�����복��������");
				read_line(name, MAX_PERSON_NAME);
				strcpy(parking[s].person_name, name);

				printf("�����복���绰�ţ�");
				read_line(number, PHONE_NUMBER);
				strcpy(parking[s].phone_number, number);
				printf("�ѳɹ�¼���û���Ϣ\n");
		}

		//�Ƿ�������ѭ��
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