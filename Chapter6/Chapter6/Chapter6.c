#include <stdio.h>
#include <math.h>

// practice 1
void p6_1(void)
{
	char ch[26];
	ch[0] = 'a';
	for (int i = 1; i < 26; i++)
	{
		ch[i] = 'a' + i;
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%c ", ch[i]);
	}

	printf("\n");

	return;
}


// practice 2
void p6_2(void)
{
	char ch = '$';

	for (int i = 0; i < 5; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
	return;
}


// practice 3
void p6_3(void)
{
	char ch = 'F';

	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			printf("%c", (ch - j));
		}
		printf("\n");
	}

	return;
}


// practice 4
void p6_4(void)
{
	char ch = 'A';

	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			printf("%c", (ch++));
		}
		printf("\n");
	}

	return;
}


// practice 5
void p6_5(void)
{
	char ch = 0;
	printf("Please input an uppercase letter:");
	scanf_s("%c", &ch);
	getchar();

	int length = ch - 'A' + 1;
	for (size_t i = 0; i < length; i++)
	{
		char temp = 'A' - 1;
		for (size_t j = 0; j < (4 - i); j++)
		{
			printf(" ");
		}
		for (size_t j = 0; j <= i; j++)
		{
			printf("%c", ++temp);
		}
		for (size_t j = 0; j < i; j++)
		{
			printf("%c", --temp);
		}

		printf("\n");
	}
	return;
}


// practice 6
#define SQUARE(X) ((X) * (X))
#define CUBE(X) ((X) * (X) * (X))
void p6_6(void)
{
	int upper = 0;
	int lower = 0;

	printf("Please input the upper:");
	scanf_s("%d", &upper);
	getchar();

	printf("Please input the lower:");
	scanf_s("%d", &lower);
	getchar();

	printf("%10s%10s%10s\n", "number", "square", "cube");

	for (size_t i = 0; i < (upper-lower+1); i++)
	{
		int number = lower + i;
		int square = SQUARE(number);
		int cube = CUBE(number);

		printf("%10d%10d%10d\n", number, square, cube );
	}
	return;
}


// practice 7
void p6_7(void)
{
	char string[20] = { 0 };
	char rev_string[20] = { 0 };
	memset(string, 0, 20);
	memset(rev_string, 0, 20);
	int length = 0;
	printf("Please enter the word:");
	scanf_s("%s", string, 19);
	getchar();

	printf("The word you inputed was:");
	printf("%s\n", string);

	length = strlen(string);
	string[length] = '\0';
	for (size_t i = 0; i < length; i++)
	{
		rev_string[i] = string[length - i - 1];
	}
	rev_string[length] = '\0';
	printf("The revert string was:%s\n", rev_string);
	return;
}


// practice 8
void p6_8(void)
{
	double divsor1 = 0;
	double divsor2 = 0;
	printf("Please input two float number:");
	while (scanf_s("%lf %lf", &divsor1, &divsor2) == 2)
	{
		getchar();
		double sub = divsor1 - divsor2;
		double pro = divsor1 * divsor2;
		double result = sub / pro;
		printf("two number input were: %lf %lf; result = %lf\n", divsor1, divsor2, result);
		printf("Please input two float number:");
	}

	return;
}


// practice 9
double cla(double div1, double div2)
{
	double sub = div1 - div2;
	double pro = div1 * div2;
	double result = sub / pro;

	return result;
}

void p6_9(void)
{
	double divsor1 = 0;
	double divsor2 = 0;
	printf("Please input two float number:");
	while (scanf_s("%lf %lf", &divsor1, &divsor2) == 2)
	{
		getchar();
		double result = cla(divsor1, divsor2);
		printf("two number input were: %lf %lf; result = %lf\n", divsor1, divsor2, result);
		printf("Please input two float number:");
	}

	return;
}


// practice 10
void p6_10(void)
{
	int lower = 0;
	int upper = 0;
	int sum = 0;

	printf("Enter lower and upper integer limits:");
	scanf_s("%d %d", &lower, &upper);
	while (upper > lower)
	{
		getchar();
		sum = 0;
		for (size_t i = lower; i <= upper; i++)
		{
			sum += SQUARE(i);
		}
		printf("The sums of the squares from %d to %d is %d\n", SQUARE(lower), SQUARE(upper), sum);
		printf("Enter next set of limits:");
		scanf_s("%d %d", &lower, &upper);
	}
	printf("Done\n");
	return;
}


// practice 11
void p6_11(void)
{
	int iarray[9];
	printf("please input 8 integer to array:");
	for (size_t i = 0; i < 8; i++)
	{
		scanf_s("%d", &iarray[i]);
	}
	getchar();
	printf("The array you inputed was:");
	for (size_t i = 0; i < 8; i++)
	{
		printf("%d ", iarray[i]);
	}
	printf("\n");
	return;
}


// practice 12
void p6_12(void)
{
	signed long long item = 0;
	double result1 = 0.0;
	double result2 = 0.0;
	
	printf("Please input the item you want to check:");
	scanf_s("%lld", &item);
	getchar();

	while (item > 0)
	{
		result1 = 0.0; 
		result2 = 0.0;
		for (size_t i = 1; i <= item; i++)
		{
			result1 += 1.0 / i;
			if (i % 2 == 1)
			{
				result2 += 1.0 / i;
			}
			else
			{
				result2 -= 1.0 / i;
			}
		}
		printf("the %d item result of the first sequence was %lf\n", item, result1);
		printf("the %d item result of the second sequence was %lf\n", item, result2);

		printf("Please anthor input the item you want to check:");
		scanf_s("%d", &item);
		getchar();
	}

	printf("Done\n");
	
}


// practice 13
void p6_13(void)
{
	int iarray[8];
	for (size_t i = 0; i < 8; i++)
	{
		iarray[i] = pow(2, (i + 1));
	}

	int i = 0;
	do
	{
		printf("array[%d] = %d\n", i, iarray[i]);
		i++;
	} while (i < 8);

	return;
}


// practice 14
void p6_14(void)
{
	double darray1[8];
	double darray2[8];

	printf("Please enter 8 double into darray1:");
	for (size_t i = 0; i < 8; i++)
	{
		scanf_s("%lf", &darray1[i]);
	}
	getchar();

	darray2[0] = darray1[0];
	for (size_t i = 1; i < 8; i++)
	{
		darray2[i] = darray1[i] + darray2[i - 1];
	}

	for (size_t i = 0; i < 8; i++)
	{
		printf("darray1[%d] = %lf ", i, darray1[i]);
	}
	printf("\n");

	for (size_t i = 0; i < 8; i++)
	{
		printf("darray2[%d] = %lf ", i, darray2[i]);
	}
	printf("\n");

	return;
}


// practice 15
void p6_15(void)
{
	int i = -1;
	char input[256];

	printf("Please input the string:");

	do
	{
		i++;
		scanf_s("%c", &input[i]);
	} while (input[i] != '\n');

	for (size_t j = i; j > 0; j--)
	{
		printf("%c", input[j - 1]);
	}
	printf("\n");

	return;
}


// practice 16
void p6_16(void)
{
	double Dap = 100.0;
	double Dei = 100.0;
	int i = 0;
	
	do
	{
		i++;
		Dap = Dap + 10;
		Dei = Dei * 1.05;
	} while (Dei < Dap);

	printf("After %d year, Deirdre's account:%lf, Daphne's account:%lf\n", i, Dei, Dap);

	return;
}


// practice 17
void p6_17(void)
{
	double Chuckie = 100.0;
	int i = 0;
	do
	{
		i++;
		Chuckie = Chuckie * 1.08;
		Chuckie -= 10;
	} while (Chuckie > 0);

	printf("After %d year, Chuckie has taken all of the money!\n", i);

	return;
}


// parctice 18
void p6_18(void)
{
	int Rab = 5;
	int i = 0;
	do
	{
		i++;
		Rab -= i;
		Rab *= 2;
		printf("%d week, Rabnud has %d friends.\n", i, Rab);
	} while (Rab < 150);

	return;
}


int main(int argc, char **argv)
{
	p6_18();

	getchar();

	return 0;
}