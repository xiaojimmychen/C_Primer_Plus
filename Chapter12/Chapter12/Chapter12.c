#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <memory.h>
#include <string.h>



// practice 1
int critic(void)
{
	int units;
	printf("No luck, my friend, Try again.\n");
	scanf_s("%d", &units);
	return units;
}
void p12_1(void)
{
	int units;

	printf("How many pounds to firkin of butter?\n");
	scanf_s("%d", &units);
	while (units != 56)
	{
		units = critic();
	}
	printf("You must have looked it up!\n");

	return;
}


// practice 2
static int mode = 0;
static int distance = 0;
static double fuel_consume = 0;
void set_mode(int set)
{
	if (0 == set || 1 == set)
	{
		mode = set;
	}
	else
	{
		printf("Invalid mode specified. Mode %s used.\n", (mode ? "1(US)" : "0(metric)"));
	}

	return;
}
void get_info(void)
{
	if (0 == mode)
	{
		printf("Enter distance traveled in kilometers: ");
		scanf_s("%d", &distance);

		printf("Enter fuel comsumed in liters: ");
		scanf_s("%lf", &fuel_consume);
	}
	else if (1 == mode)
	{
		printf("Enter distance traveled in miles: ");
		scanf_s("%d", &distance);

		printf("Enter fuel comsumed in gallons: ");
		scanf_s("%lf", &fuel_consume);
	}

	return;
}
void show_info(void)
{
	if (0 == mode)
	{
		printf("Fuel comsumption is %lf liters per 100 km\n", (fuel_consume / (distance / 100)));
	}
	else if (1 == mode)
	{
		printf("Fuel comsuption is %lf miles per gallon.\n", distance / fuel_consume);
	}

	return;
}
void p12_2(void)
{
	int mode;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf_s("%d", &mode);
	while (mode >= 0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		scanf_s("%d", &mode);
	}

	printf("Done.\n");
	return;
}


// practice 3
void get_info3(int mode, int *distance, double *fuel_comsuption)
{
	if (0 == mode)
	{
		printf("Enter distance traveled in kilometers: ");
		scanf_s("%d", distance);

		printf("Enter fuel comsumed in liters: ");
		scanf_s("%lf", fuel_comsuption);
	}
	else if (1 == mode)
	{
		printf("Enter distance traveled in miles: ");
		scanf_s("%d", distance);

		printf("Enter fuel comsumed in gallons: ");
		scanf_s("%lf", fuel_comsuption);
	}

	return;
}
void show_info3(int mode, int distance, double fuel_consume)
{
	if (0 == mode)
	{
		printf("Fuel comsumption is %lf liters per 100 km\n", (fuel_consume / (distance / 100)));
	}
	else if (1 == mode)
	{
		printf("Fuel comsuption is %lf miles per gallon.\n", distance / fuel_consume);
	}

	return;
}
void p12_3(void)
{
	int mode = 0;
	int mode_pre = 0;
	int distance = 0;
	double fuel_consumption;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf_s("%d", &mode);

	while (mode >= 0)
	{
		if ((0 != mode) && (1 != mode))
		{
			printf("Invalid mode specified. Mode %s used.\n", (mode_pre ? "1(US)" : "0(metric)"));
			mode = mode_pre;
		}
		get_info3(mode, &distance, &fuel_consumption);
		show_info3(mode, distance, fuel_consumption);
		mode_pre = mode;
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		scanf_s("%d", &mode);
	}
	printf("Done.\n");
	return;
}


// practice 4
void test_fun(void)
{
	static int call_time = 0;
	call_time++;
	printf("test_fun have been called %d times!\n", call_time);
}
void p12_4(void)
{
	for (size_t i = 0; i < 20; i++)
	{
		test_fun();
	}

	return;
}


// practice 5
void p12_5(void)
{
	int array[100];
	srand((unsigned int) time(0));
	for (size_t i = 0; i < 100; i++)
	{
		array[i] = (rand() % 10 + 1);
	}

	printf("Before sorted:\n");
	for (size_t i = 0; i < 100; i++)
	{
		printf("%d ", array[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}

	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = i; j < 100; j++)
		{
			if (array[i] < array[j])
			{
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}

	printf("After sorted:\n");
	for (size_t i = 0; i < 100; i++)
	{
		printf("%d ", array[i]);
		if ((i+1)%10 == 0)
		{
			printf("\n");
		}
	}

	return;
}


// practice 6
void p12_6(void)
{
	int num[10] = { 0 }; // 初始化为0
	
	for (size_t i = 0; i < 1000; i++)
	{
		if ((i % 100 == 0))
		{
			srand((unsigned int)time(0)); // 很奇怪的是加了这句话，出现的次数都是10的倍数，暂时不清楚什么原因
		}
		int tmp = rand() % 10 + 1;
		num[tmp - 1]++;
	}

	for (size_t i = 0; i < 10; i++)
	{
		printf("%d appears %d times.\n", i+1, num[i]);
	}

	return;
}


// practice 7
static int rollem(int sides)
{
	int roll;
	roll = rand() % sides + 1;

	return roll;
}
int roll_n_dice(int dice, int sides)
{
	int total = 0;
	int d = 0;
	if (sides < 2)
	{
		printf("Need at least 2 sides.\n");
		return -2;
	}
	if (dice < 1)
	{
		printf("Need at least 1 dice.\n");
		return -1;
	}
	for ( d = 0; d < dice; d++)
	{
		total += rollem(sides);
	}

	return total;
}
void p12_7(void)
{
	int sets = 0;
	int sides = 0;
	int dice = 0;
	int total = 0;

	while (1)
	{
		printf("Enter the number of sets; enter q to stop: ");
		if (1 != scanf_s("%d", &sets))
		{
			break;
		}

		printf("How many sides and how many dice? ");
		scanf_s("%d %d", &sides, &dice);

		printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
		for (int i = 0; i < sets; i++)
		{
			if ((i + 1) % 15 == 0)
			{
				printf("\n");
			}
			printf("%d ", roll_n_dice(dice, sides));
		}
		printf("\n");
	}

	printf("Done.\n");

	return;

}


// practice 8
int *make_array(int elem, int val)
{
	int *pa = (int *)malloc(elem);
	for (int i = 0; i < elem; i++)
	{
		pa[i] = val;
	}

	return pa;
}
void show_array(const int ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((i+1)%8 == 0)
		{
			printf("\n");
		}
		printf("%d ", ar[i]);
	}

	printf("\n");

	return;
}
void p12_8(void)
{
	int *pa;
	int size;
	int value;

	printf("Enter the number of elements: ");
	while (scanf_s("%d", &size) == 1 && size > 0)
	{
		printf("Enter the initialization value: ");
		scanf_s("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			printf("Free memory!\n");
			free(pa);
		}
		printf("Enter the number of elements (<1 to quit): ");
	}

	printf("Done.\n");
	return ;
}


// practice 9
void p12_9(void)
{
	int n_word;
	char **word;
	char word_tmp[256];
	
	printf("How many words do you wish to enter? ");
	scanf_s("%d", &n_word);

	word = (char **)malloc(sizeof(char *) * n_word);

	printf("Enter %d words now:\n", n_word);
	for (int i = 0; i < n_word; i++)
	{
		scanf_s("%s", word_tmp, 256);
		int word_length = strlen(word_tmp);
		word[i] = (char *)malloc(word_length+1);
		strcpy_s(word[i], word_length + 1, word_tmp);
	}

	printf("Here are your words:\n");
	for (int i = 0; i < n_word; i++)
	{
		printf("%s\n", word[i]);
	}

	// 别忘记释放内存
	for (int i = 0; i < n_word; i++)
	{
		free(word[i]);
	}
	free(word);
}







int main(int argc, char **argv)
{
	p12_9();

	while (getchar());

	return 0;
}
