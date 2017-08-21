#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


// practice 1
double min_rewrite(double x, double y)
{
	return (x < y ? x : y);
}
void p9_1(void)
{
	double number1 = 0.0;
	double number2 = 0.0;

	printf("Enter the first number:");
	scanf_s("%lf", &number1);
	getchar();


	printf("Enter the second number:");
	scanf_s("%lf", &number2);
	getchar();

	printf("The min number of %lf and %lf is %lf", number1, number2, min_rewrite(number1, number2));

	return;
}



// practice 2
void chline(char *ch, int i, int j)
{
	int m = 0;
	int n = 0;
	int tmp = 0;
	while ((*(ch + tmp)) != '\0')
	{

		if (m == i - 1)
		{
			break;
		}
		if ('\n' == (*(ch + tmp)))
		{
			m++;
		}
		tmp++;
	}

	for (n = 0; n < j; n++)
	{
		if (n == j - 1)
		{
			putchar(ch[tmp]);
		}
		tmp++;
	}
}
void p9_2(void)
{
	int i = 0;
	int j = 0;
	char ch = 0;
	char *words = "hello world!\nThis is the bulteaful world!\nLearn to program in c language!\nc language is a nice language!";

	printf("Please enter the row:");
	scanf_s("%d", &i);
	getchar();

	printf("Please enter the column:");
	scanf_s("%d", &j);
	getchar();

	printf("The character of %d row %d column is ", i, j);
	chline(words, i, j);

	printf("\n");

	return;
}


// practice 3
void print_n_char(char ch, int repeat_time, int repeat_row)
{
	for (int i = 0; i < repeat_row; i++)
	{
		for (int j = 0; j < repeat_time; j++)
		{
			putchar(ch);
		}
		putchar('\n');
	}

	return;
}
void p9_3()
{
	int i = 0;
	int j = 0;
	char ch = 0;

	printf("Enter the character you want to print:");
	ch = getchar();
	getchar();

	printf("Enter the number of times to print:");
	scanf_s("%d", &i);
	getchar();

	printf("Enter the number of lines to print:");
	scanf_s("%d", &j);
	getchar();

	print_n_char(ch, i, j);

	return;
	
}


// practice 4
double harmonic_avg(double number1, double number2)
{
	double reciprocal1 = 1 / number1;
	double reciprocal2 = 1 / number2;
	double sum = reciprocal1 + reciprocal2;
	double sum_avg = sum / 2;
	return (1 / sum_avg);
}
void p9_4(void)
{
	double number1 = 0.0;
	double number2 = 0.0;
	double result = 0.0;

	printf("Ener the first double number:");
	scanf_s("%lf", &number1);
	getchar();

	printf("Enter the second double number:");
	scanf_s("%lf", &number2);
	getchar();

	result = harmonic_avg(number1, number2);

	printf("The harmonic average of %lf and %lf is %lf\n", number1, number2, result);

	return;
}


// practice 5
void larger_of(double *x, double *y)
{
	if (*x > *y)
	{
		*y = *x;
	}
	else
	{
		*x = *y;
	}
}
void p9_5(void)
{
	double number1 = 0.0;
	double number2 = 0.0;

	printf("Enter the first double number:");
	scanf_s("%lf", &number1);
	getchar();

	printf("Enter the second double number:");
	scanf_s("%lf", &number2);
	getchar();

	printf("Before larger_of, the two numbers are %lf and %lf\n", number1, number2);
	larger_of(&number1, &number2);
	printf("After larger_of, the two number are %lf and %lf\n", number1, number2);

	return;
}


// practice 6
void rank_three_double(double *number1, double *number2, double *number3)
{
	double tmp = 0.0;
	if (*number1 > *number2)
	{
		tmp = *number1;
		*number1 = *number2;
		*number2 = tmp;
	}
	if (*number1 > *number3)
	{
		tmp = *number1;
		*number1 = *number3;
		*number3 = tmp;
	}
	if (*number2 > *number3)
	{
		tmp = *number2;
		*number2 = *number3;
		*number3 = tmp;
	}
	return;
}
void p9_6(void)
{
	double number1 = 0.0;
	double number2 = 0.0;
	double number3 = 0.0;

	printf("Enter the first double number:");
	scanf_s("%lf", &number1);
	getchar();

	printf("Enter the second double number:");
	scanf_s("%lf", &number2);
	getchar();

	printf("Enter the third double number:");
	scanf_s("%lf", &number3);
	getchar();

	printf("Before rank, the three double number are: %lf, %lf and %lf\n", number1, number2, number3);
	rank_three_double(&number1, &number2, &number3);
	printf("After rank, the three double number are: %lf, %lf and %lf\n", number1, number2, number3);

	return;
}


// practice 7
// 不好模拟文件末尾，所以用#代替文件末尾
int judge_alpha(char ch)
{
	if (isalpha(ch))
	{
		return ch - 'a' + 1;
	}
	else
	{
		return -1;
	}
}
void p9_7(void)
{
	char ch = 0;
	int result = 0;

	printf("Enter the character:(# to quit):");
	while ((ch = getchar()) != '#')
	{
		if ('\n' == ch)
		{
			continue;
		}
		int jud = judge_alpha(ch);
		if (-1 == jud)
		{
			printf("%c is not a alpha.\n", ch);
		}
		else
		{
			printf("%c:%d\n", ch, jud);
		}
		printf("Enter the next character:(# to quit):");
	}

	return;
}


// practice 8
double pow_rewrite(double base, double index)
{
	if (index > 0)
	{
		return pow(base, index);
	}
	if (0 == index)
	{
		if (0 == base)
		{
			printf("The base number is 0 is not defined!\n");
		}

		return 1;
	}
	if (index < 0)
	{
		double tmp = pow(base, -index);
		return (1 / tmp);
	}
}
void p9_8(void)
{
	double base = 0.0;
	double index = 0.0;
	double result = 0.0;

	printf("Enter the base number:");
	scanf_s("%lf", &base);
	getchar();

	printf("Enter the index number:");
	scanf_s("%lf", &index);
	getchar();

	result = pow_rewrite(base, index);
	printf("base number: %lf, index number: %lf, the result: %lf\n", base, index, result);

	return;
}


// practice 9
double pow_recursive(double base, double index)
{
	if (index > 0)
	{
		index--;
		return (base * pow_recursive(base, index));
	}
	if (0 == index)
	{
		if (base == 0)
		{
			printf("The base number is 0 is not defined!\n");
		}
		return 1;
	}
	if (index < 0)
	{
		index++;
		double tmp = 1 / base;
		return (tmp * pow_recursive(base, index));
	}
}
void p9_9(void)
{
	double base = 0.0;
	double index = 0.0;
	double result = 0.0;

	printf("Enter the base number:");
	scanf_s("%lf", &base);
	getchar();

	printf("Enter the index number:");
	scanf_s("%lf", &index);
	getchar();

	result = pow_recursive(base, index);
	printf("base number: %lf, index number: %lf, the result: %lf\n", base, index, result);

	return; 
}


// practice 10
void to_base_n(unsigned long n, int base)
{
	int r = 0;

	r = n % base;
	if (n >= base)
	{
		to_base_n(n / base, base);
	}
	putchar(('0' + r));

	return;
}
void p9_10(void)
{
	unsigned long number = 0;
	int base = 0;

	printf("Enter the value that needs to be converted:");
	scanf_s("%ld", &number);
	getchar();

	printf("Enter the value of the base number:");
	scanf_s("%d", &base);
	getchar();

	printf("The result is: ");
	to_base_n(number, base);
	putchar('\n');

	return;
}


// practice 11
void Fibonacci(unsigned int n)
{
	int fib1 = 1;
	int fib2 = 1;

	printf("%d, %d", fib1, fib2);

	for (size_t i = 0; (i = (fib1 + fib2)) < n;)
	{
		printf(", %d", i);
		fib1 = fib2;
		fib2 = i;
	}

	putchar('\n');
	return;
}
void p9_11(void)
{
	unsigned long num = 0;

	printf("Enter the larger number of fabonicci:");
	scanf_s("%ld", &num);
	getchar();

	Fibonacci(num);

	return;
}



int main(int argc, char **argv)
{
	p9_11();

	while (getchar())
	{

	}

	return;
}