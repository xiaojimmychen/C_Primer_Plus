#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



// practice 1
typedef struct MONTH_INFO
{
	char month[4];
	int month_days;
	int month_number;
} ST_MONTH_INFO;
#define N_MONTH  12
const ST_MONTH_INFO info[N_MONTH] = {
	{"Jan", 31, 1},
	{"Feb", 28, 2},
	{"Mar", 31, 3},
	{"Apr", 30, 4},
	{"May", 31, 5},
	{"Jun", 30, 6},
	{"Jul", 31, 7},
	{"Aug", 31, 8},
	{"Sep", 30, 9},
	{"Oct", 31, 10},
	{"Nov", 30, 11},
	{"Dec", 31, 12}
};
void p14_1(void)
{
	char month[4];
	int total_days = 0;
	_Bool find = 0;
	printf("Enter the abbreviation of month:");
	fgets(month, 4, stdin);

	for (int i = 0; i < N_MONTH; i++)
	{
		total_days += info[i].month_days;
		if (strcmp(month, info[i].month) == 0)
		{
			find = 1;
			break;
		}
	}

	if (find == 1)
		printf("There are %d days till %s\n", total_days, month);
	else
		printf("The month of addreviation is not found!\n");

	return;
}


// practice 2
void p14_2(void)
{
	char month[4];
	int days = 0;
	int total_days = 0;
	_Bool find = 0;
	int i = 0;

	while (find == 0)
	{
		total_days = 0;
		printf("Enter the abbreviation of month:");
		fgets(month, 4, stdin);

		for (i = 0; i < N_MONTH; i++)
		{
			total_days += info[i].month_days;
			if (strcmp(month, info[i].month) == 0)
			{
				find = 1;
				break;
			}
		}

		if (find == 1)
			printf("There are %d days till %s\n", total_days, month);
		else
			printf("The month of addreviation is not found! Enter again.\n");
	}

	find = 0;
	while (find == 0)
	{
		printf("Enter the days of month:");
		scanf("%d", &days);
		if (days < info[i].month_days)
		{
			total_days += days;
			find = 1;
			printf("There %d days till %s %d\n", total_days, month, days);
		}
		else
			printf("The day of month is not found! Enter again.\n");
	}

	return;
}


// practice 3
char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return ret_val;
}
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100
struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	// 下面一个变量用于practice 7,在practice 3时可以先删除
	int delete;
};
void p14_3(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;

	printf("Please enter the book title.\n");
	printf("Please [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
			&& library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
		{
			continue;
		}
		if (count < MAXBKS)
		{
			printf("Enter the next title.\n");
		}
	}

	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		printf("Array by original:\n");
		for (index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		}
		printf("\n");

		printf("Array by title:\n");
		for (int i = 0; i < count; i++)
		{
			for (int j = i; j < count; j++)
			{
				if (strcmp(library[i].title, library[j].title) > 0)
				{
					struct book tmp = library[i];
					library[i] = library[j];
					library[j] = tmp;
				}
			}
		}

		for (index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		}
		printf("\n");

		printf("Array by value:\n");
		for (int i = 0; i < count; i++)
		{
			for (int j = i; j < count; j++)
			{
				if (library[i].value > library[j].value)
				{
					struct book tmp = library[i];
					library[i] = library[j];
					library[j] = tmp;
				}
			}
		}

		for (index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		}
		printf("\n");
	}
	else
		printf("No books? Too bad.\n");

	return;
}


// practice 4
struct name_info {
	char first_name[32];
	char last_name[32];
	char mid_name[32];
};
struct member_info {
	char insuran_number[32];
	struct name_info name;
};
void p14_4a(struct member_info *member)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%s, %s", member[i].name.first_name, member[i].name.last_name);
		if (member[i].name.mid_name[0] != '\0')
		{
			printf(" %s.", member[i].name.mid_name);
		}
		printf(" -- %s\n", member[i].insuran_number);
	}
}
void p14_4b(struct member_info member)
{
	printf("%s, %s", member.name.first_name, member.name.last_name);
	if (member.name.mid_name[0] != '\0')
	{
		printf(" %s.", member.name.mid_name);
	}
	printf(" -- %s\n", member.insuran_number);
}
void p14_4(void)
{
	struct member_info member[5] = {
		{"302039823", {"Dribble", "FLossie", "M"}},
		{"302039824", {"Hello", "Kitty"}},
		{"302039285", {"Hello", "Jimmy", "J"}},
		{"302039286", {"Good", "Job"}},
		{"302039287", {"Jump", "High", "J"}}
	};

	// a
	//p14_4a(member);

	// b
	for (int i = 0; i < 5; i++)
	{
		p14_4b(member[i]);
	}

	return;
}


// practice 5
struct name {
	char first_name[32];
	char last_name[32];
};
struct student {
	struct name student_name;
	double grade[3];
	double average;
};
#define CSIZE 4
void p14_5(void)
{
	struct student students[CSIZE];

	// d
	for (int i = 0; i < CSIZE; i++)
	{
		printf("Enter the student's first name: ");
		s_gets(students[i].student_name.first_name, 32);

		printf("Enter the student's last name: ");
		s_gets(students[i].student_name.last_name, 32);

		printf("Enter three grades of this student: ");
		for (int j = 0; j < 3; j++)
		{
			scanf("%lf", &students[i].grade[j]);
		}
		getchar(); // 换行符还在缓冲区里
	}

	// e
	for (int i = 0; i < CSIZE; i++)
	{
		double total_grade = 0.0;
		for (int j = 0; j < 3; j++)
		{
			total_grade += students[i].grade[j];
		}
		students[i].average = total_grade / 3;
	}

	// f
	for (int i = 0; i < CSIZE; i++)
	{
		printf("Student: %s, %s, grade: %.2lf, %.2lf, %.2lf, average: %.2lf\n", students[i].student_name.first_name, students[i].student_name.last_name,
			students[i].grade[0], students[i].grade[1], students[i].grade[2], students[i].average);
	}

	// g
	double total_grades = 0.0;
	for (int i = 0; i < CSIZE; i++)
	{
		total_grades += students[i].average;
	}
	printf("All students' average grade is %.2lf\n", total_grades / CSIZE);

	return;
}


// practice 6
struct softball_player {
	char first_name[128];
	char last_name[128];
	int play_times;
	int hit_times;
	int run_bar_times;
	int rbi;
	double hit_rate;
};
void p14_6(void)
{
	struct softball_player players[19] = { {'\0', '\0', 0, 0, 0, 0, 0.0} };
	FILE *fp;
	char file_name[128];
	struct softball_player player;
	int player_number;

	printf("Enter the file name: ");
	s_gets(file_name, 128);

	if ((fp = fopen(file_name, "r")) == NULL)
	{
		printf("Can't open the %s.\n", file_name);
	}

	while (feof(fp) == 0)
	{
		fscanf(fp, "%d", &player_number);
		fscanf(fp, "%s", &player.first_name);
		fscanf(fp, "%s", &player.last_name);
		fscanf(fp, "%d", &player.play_times);
		fscanf(fp, "%d", &player.hit_times);
		fscanf(fp, "%d", &player.run_bar_times);
		fscanf(fp, "%d", &player.rbi);
		if (players[player_number].first_name[0] == '\0')
		{
			players[player_number] = player;
		}
		else
		{
			players[player_number].play_times += player.play_times;
			players[player_number].hit_times += player.hit_times;
			players[player_number].run_bar_times += player.run_bar_times;
			players[player_number].rbi += player.rbi;
		}
	}

	for (int i = 0; i < 19; i++)
	{
		if (players[i].first_name[0] != '\0')
		{
			players[i].hit_rate = (double)players[i].hit_times / players[i].play_times;
		}
	}

	for (int i = 0; i < 19; i++)
	{
		if (players[i].first_name[0] != '\0')
		{
			printf("Player:%s %s, play times: %d, hit times: %d, run barrier times: %d, rbi: %d, hit_rate: %.2lf\n",
					players[i].first_name, players[i].last_name, players[i].play_times, players[i].hit_times, players[i].run_bar_times, players[i].rbi, 
					players[i].hit_rate);
		}
	}
}


// practice 7
// 结构的定义和宏定义都在practice 3中，这里就不再另外定义
void p14_7(void)
{
	struct book library[MAXBKS] = { {'\0', '\0', 0.0, 0} };
	int count = 0;
	int index, filecount;
	FILE *pbooks;
	int size = sizeof(struct book);

	if ((pbooks = fopen("book.dat", "r+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
	}

	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
		{
			puts("Current contents of boot.dat:");
		}
		printf("%s by %s: $%.2f\n", library[count].title,
			library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("The book.dat file is null.", stderr);
	}

	printf("Please enter the book.dat title.\n");
	printf("Please [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
		{
			continue;
		}
		if (count < MAXBKS)
		{
			printf("Enter the next title.\n");
		}
	}

	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		for (index = 0; index < count; index++)
		{
			printf("%d: %s by %s: $%.2f\n", index + 1, library[index].title, library[index].author, library[index].value);
		}
	}
	else
		puts("No books? Too bad.\n");

	while (1)
	{
		int item;
		char ch;
		printf("Which book do you want to delete or modify(-1 to exit)?");
		scanf("%d", &item);
		while (getchar() != '\n')
		{
			continue;
		}
		if (item == -1)
		{
			break;
		}
		printf("[D]elete or [M]dify?");
		scanf("%c", &ch);
		while (getchar() != '\n')
		{
			continue;
		}
		if (ch == 'D')
		{
			library[item - 1].delete = 1;
		}
		else
		{
			printf("Please enter the book title.\n");
			s_gets(library[item - 1].title, MAXTITL);
			printf("Now enter the author.\n");
			s_gets(library[item - 1].author, MAXAUTL);
			printf("Now enter the value.\n");
			scanf("%f", &library[item - 1].value);
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}

	// 关闭再以只读打开文件后可以完全清空文件
	fclose(pbooks);
	if ((pbooks = fopen("book.dat", "w")) == NULL)
	{
		printf("Can't open boot.dat file\n");
	}
	for (int i = 0; i < count; i++)
	{
		if (library[i].delete != 1)
		{
			fwrite(&library[i], size, 1, pbooks);
		}
	}

	puts("Done.\n");
	fclose(pbooks);

	return;
}


// practice 8
#define TOTAL_SEAT 12
struct seat {
	int seat_number;
	int book;
	char first_name[128];
	char last_name[128];
};
void show_empty_seat(struct seat *airplane)
{
	int seats = 0;
	for (int i = 0; i < TOTAL_SEAT; i++)
	{
		if (airplane[i].book == 0)
		{
			seats++;
		}
	}

	printf("There are %d empty seats.\n", seats);

	return;
}
void list_empty_seat(struct seat *airplane)
{
	printf("List empty seat:");
	for (int i = 0; i < TOTAL_SEAT; i++)
	{
		if (airplane[i].book ==0)
		{
			printf(" %d", airplane[i].seat_number);
		}
	}
	printf("\n");
}
void show_alphabetical(struct seat *airplane)
{
	printf("Show alphabetical:\n");
	for (int i = 0; i < TOTAL_SEAT; i++)
	{
		if (airplane[i].book == 1)
		{
			printf("%d booked by %s %s.\n", airplane[i].seat_number, airplane[i].first_name, airplane[i].last_name);
		}
	}
}
void book_seat(struct seat *airplane)
{
	int seat_number = 0;
	
	while (1)
	{
		printf("Enter the seat number you want to book:");
		scanf("%d", &seat_number);
		seat_number -= 1;
		while (getchar() != '\n');
		if (airplane[seat_number].book == 1)
		{
			printf("Seat %d is not empty, please enter again.\n", seat_number+1);
		}
		else
		{
			break;
		}
	}

	printf("Enter the customer first name:");
	s_gets(airplane[seat_number].first_name, 128);

	printf("Enter the customer last name:");
	s_gets(airplane[seat_number].last_name, 128);

	airplane[seat_number].book = 1;

	return;
}
void delete_seat(struct seat *airplane)
{
	int seat_number;
	printf("Enter the seat assigment you want to delete:");

	scanf("%d", &seat_number);
	getchar();

	
	airplane[seat_number-1].book = 0;
}
void p14_8(void)
{
	struct seat airplane_seats[TOTAL_SEAT] = { {0, 0, '\0', '\0'} };
	char choice;

	for (int i = 0; i < TOTAL_SEAT; i++)
	{
		airplane_seats[i].seat_number = i + 1;
		airplane_seats[i].book = 0;
		airplane_seats[i].first_name[0] = '\0';
		airplane_seats[i].last_name[0] = '\0';
	}

	while (1)
	{
		printf("To choose a function, enter its letter lable:\n");
		printf("a) Show number of empty seats\n");
		printf("b) Show list of empty seats\n");
		printf("c) Show alphabetical list of seats\n");
		printf("d) Assign a customer to a seat assigment\n");
		printf("e) Delete a seat assignment\n");
		printf("f) Quit\n");

		scanf("%c", &choice);
		getchar();

		if (choice == 'f')
		{
			break;
		}

		switch (choice)
		{
		case 'a':
			show_empty_seat(airplane_seats);
			break;

		case 'b':
			list_empty_seat(airplane_seats);
			break;

		case 'c':
			show_alphabetical(airplane_seats);
			break;

		case 'd':
			book_seat(airplane_seats);
			break;

		case 'e':
			delete_seat(airplane_seats);
			break;

		default:
			break;
		}
	}
	
}


// practice 9
// 确认座位分配选项不知道用来做什么的，没理解，所以就不做了
#define TOTAL_FLIGHT 4
void p14_9(void)
{
	struct seat airplane_seats[TOTAL_FLIGHT][TOTAL_SEAT] = { { 0, 0, '\0', '\0' } };
	struct seat *flight_select = NULL;
	char choice;

	for (int i = 0; i < TOTAL_FLIGHT; i++)
	{
		for (int j = 0; j < TOTAL_SEAT; j++)
		{
			airplane_seats[i][j].seat_number = j + 1;
			airplane_seats[i][j].book = 0;
			airplane_seats[i][j].first_name[0] = '\0';
			airplane_seats[i][j].last_name[0] = '\0';
		}
	}

	while (1)
	{
		char flight[4];
		printf("Which flight you want to select: 102, 311, 444 or 519: ");
		scanf("%s", flight);
		getchar();

		if (strcmp("102", flight) == 0)
		{
			flight_select = airplane_seats[0];
		}
		else if (strcmp("311", flight) == 0)
		{
			flight_select = airplane_seats[1];
		}
		else if (strcmp("444", flight) == 0)
		{
			flight_select = airplane_seats[2];
		}
		else if (strcmp("519", flight) == 0)
		{
			flight_select = airplane_seats[3];
		}

		while (1)
		{
			printf("To choose a function, enter its letter lable:\n");
			printf("a) Show number of empty seats\n");
			printf("b) Show list of empty seats\n");
			printf("c) Show alphabetical list of seats\n");
			printf("d) Assign a customer to a seat assigment\n");
			printf("e) Delete a seat assignment\n");
			printf("f) Quit\n");

			scanf("%c", &choice);
			getchar();

			if (choice == 'f')
			{
				break;
			}

			switch (choice)
			{
			case 'a':
				show_empty_seat(flight_select);
				break;

			case 'b':
				list_empty_seat(flight_select);
				break;

			case 'c':
				show_alphabetical(flight_select);
				break;

			case 'd':
				book_seat(flight_select);
				break;

			case 'e':
				delete_seat(flight_select);
				break;

			default:
				break;
			}
		}
	}

}


// practice 10
void p14_10a(void)
{
	printf("p14_10a()\n");
}
void p14_10b(void)
{
	printf("p14_10b()\n");
}
void p14_10c(void)
{
	printf("p14_10c()\n");
}
void p14_10(void)
{
	char choice = 0;
	void(*fun[3])(void) = { p14_10a, p14_10b, p14_10c };
	printf("Enter you choice:\n");
	printf("a) p14_10a()\n");
	printf("b) p14_10b()\n");
	printf("c) p14_10c()\n");

	scanf("%c", &choice);
	getchar();

	switch (choice)
	{
	case 'a':
		fun[0]();
		break;

	case 'b':
		fun[1]();
		break;

	case 'c':
		fun[2]();
		break;

	default:
		break;
	}
}


// practice 11
double mul2(double x)
{
	return (x * 2.0);
}
double mul1(double x)
{
	return (x * x);
}
void transform(double *source, double *target, int num, double (*fun)(double))
{
	for (int i = 0; i < num; i++)
	{
		target[i] = fun(source[i]);
	}
}
void p14_11(void)
{
	double source[100];
	double target[100];

	for (int i = 0; i < 100; i++)
	{
		source[i] = i;
	}

	printf("Use sqr:\n");
	transform(source, target, 100, sqrt);
	for (int i = 0; i < 100; i++)
	{
		printf("%.2lf ", target[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}

	printf("Use sin:\n");
	transform(source, target, 100, sin);
	for (int i = 0; i < 100; i++)
	{
		printf("%.2lf ", target[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}

	printf("Use mul2:\n");
	transform(source, target, 100, mul2);
	for (int i = 0; i < 100; i++)
	{
		printf("%.2lf ", target[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}

	printf("Use sqr:\n");
	transform(source, target, 100, mul1);
	for (int i = 0; i < 100; i++)
	{
		printf("%.2lf ", target[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}
}







int main(int argc, char **argv)
{
	p14_11();

	while (getchar());

	return 0;
}