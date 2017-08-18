#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


// practice 1
void p8_1(void)
{
	char ch = 0;
	int n_char = 0;
	while ((ch = getchar()) != EOF)
	{
		n_char++;
	}

	printf("There are %d characters in the file!\n", n_char);

	return;
}


// practice 2
void p8_2(void)
{
	char ch = 0;
	int n_char = 0;
	while ((ch = getchar()) != EOF)
	{
		n_char++;
		if (ch < ' ')
		{
			if ('\t' == ch)
			{
				putchar('\\');
				putchar('t');
				printf(":%d ", ch);
			}
			else if ('\n' == ch)
			{
				putchar('\\');
				putchar('t');
				printf(":%d ", ch);
			}
			else
			{
				putchar('^');
				putchar(ch+64);
				printf(":%d ", ch);
			}
		}
		else
		{
			putchar(ch);
			printf(":%d ", ch);
		}
		if (n_char % 10 == 0)
		{
			printf("\n");
		}

	}
}


// practice 3
void p8_3(void)
{
	char ch = 0;
	int n_upper = 0;
	int n_lower = 0;

	while ((ch = getchar()) != EOF)
	{
		if (islower(ch))
		{
			n_lower++;
		}
		else if (isupper(ch))
		{
			n_upper++;
		}
	}

	printf("There are %d upper character and %d lower charecter.\n", n_upper, n_lower);

	return;	
}


// practice 4
void p8_4(void)
{
	char ch = 0;
	char ch_pre = 0;
	int n_word = 0;
	int total_chr = 0;
	int word_chr = 0;
	double word_chr_avg = 0;

	while (ch = getchar()) // 清除文件开头处的空格、标点和换行符等
	{
		if (isalpha(ch))
		{
			break;
		}
	}

	while (ch != EOF)
	{
		if ((' ' == ch || '\n' == ch) && !isspace(ch_pre)) // 排除连续空格情况
		{
			n_word++;
			printf("ch_pre = %c\n", ch_pre);
			total_chr += word_chr;
			printf("word_chr = %d, total_chr = %d\n", word_chr, total_chr);
			word_chr = 0;
		}
		else if (isspace(ch))  // 清除连续的空格
		{
			ch_pre = ch;
			ch = getchar();
			continue;
		}
		if (!ispunct(ch) && !isspace(ch))
		{
			word_chr++;
		}
		ch_pre = ch;
		ch = getchar();
	}

	if (!isspace(ch_pre))
	{
		n_word++;
		printf("ch_pre = %c\n", ch_pre);
		total_chr += word_chr;
	}

	word_chr_avg = (double)total_chr / n_word;

	printf("Total words: %d, Total characters: %d, Characters per word: %.2lf", n_word, total_chr, word_chr_avg);
}


// practice 5
void p8_5(void)
{
	char ch = 0;
	int upper = 100;
	int lower = 0;
	int guest = 50;

	printf("I guest the number is 50. Is it right(Y/N)?");
	scanf_s("%c", &ch);
	getchar();
	
	while ('Y' != ch)
	{
		printf("Ok, the number you chosen is bigger or smaller than I guest?(B/S)");
		scanf_s("%c", &ch);
		getchar();
		if ('B' == ch)
		{
			lower = guest;
			guest = (lower + upper) / 2;
		}
		else
		{
			upper = guest;
			guest = (lower + upper) / 2;
		}

		printf("I guest the number is %d, Is it right(Y/N)?", guest);
		scanf_s("%c", &ch);
		getchar();
	}

	printf("HAHA, I win!");

	return;
}


// practice 6
char get_first(void)
{
	int ch = 0;
	
	while (!isalpha(ch = getchar()))
	{
		continue;
	}

	return ch;
}
void p8_6(void)
{
	char ch = get_first();

	putchar(ch);
}


// practice 7
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
void p8_7(void)
{
	char chooice = 0;

	double work_hours = 0;
	double total_income = 0;
	double tax = 0;
	double net_income = 0;
	double hourly_wage = 0;

	while (1)
	{
		printf("Enter the number corresponding to the desired pay rate to action:\n");
		printf("%-20s%-20s\n%-20s%-20s\n%-20s\n", "a) $8.75/hr", "b) $9.33/hr", "c) $10.00/hr", "d) $11.20/hr", "q) quit");
		scanf_s("%c", &chooice);
		getchar();

		switch (chooice)
		{
		case 'a':
			hourly_wage = 8.75;
			break;

		case 'b':
			hourly_wage = 9.33;
			break;

		case 'c':
			hourly_wage = 10.00;
			break;

		case 'd':
			hourly_wage = 11.20;
			break;

		case 'q':
			return;

		default:
			printf("Please enter the choice between a to d and q\n");
			continue;
		}


		printf("How long have you worked:");
		scanf_s("%lf", &work_hours);
		getchar();
		if (work_hours > 40)
		{
			work_hours = (work_hours - 40) * 1.5 + 40;
		}

		total_income = work_hours * hourly_wage;
		if (total_income <= 300)
		{
			tax = total_income * RATE1;
			net_income = total_income - tax;
		}
		else if (300 < total_income <= 450)
		{
			tax = 300 * RATE1 + (total_income - 300) * RATE2;
			net_income = total_income - tax;
		}
		else
		{
			tax = 300 * RATE1 + 150 * RATE2 + (total_income - 450) * RATE3;
			net_income = total_income - tax;
		}

		printf("total income = %.2lf, tax = %.2lf, net income = %.2lf\n", total_income, tax, net_income);
	}


	return;
}


// practice 8
void p8_8(void)
{
	float number1 = 0.0;
	float number2 = 0.0;
	char choice = 0;

	do
	{
		printf("Enter the operation of your choice:\n");
		printf("%-20s%-20s\n%-20s%-20s\n%-20s\n", "a. add", "s. subtract", "m. multuply", "d. divide", "q. quit");
		if (scanf_s("%c", &choice) != 1&& (('a' != choice) || ('s' != choice) || ('m' != choice) || ('d' != choice) || ('q' != choice)))
		{
			printf("Please enter the correct operation, please enter again!\n");
			while (getchar() != '\n')
			{
				continue;
			}
			continue;
		}
		getchar();

		if ('q' == choice)
		{
			printf("Bye!\n");
			return;
		}

		printf("Enter first number:");
		while (scanf_s("%f", &number1) != 1)
		{
			char ch = 0;
			while ((ch = getchar()) != '\n')
			{
				putchar(ch);
			}
			printf(" is not an number.\n");
			printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
		}
		getchar();

		printf("Enter second number:");
		while (scanf_s("%f", &number2) != 1)
		{
			char ch = 0;
			while ((ch = getchar()) != '\n')
			{
				putchar(ch);
			}
			printf(" is not an number.\n");
			printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
		}
		getchar();

		switch (choice)
		{
		case 'a':
			printf("%f + %f = %f\n", number1, number2, (number1 + number2));
			break;

		case 's':
			printf("%f - %f = %f\n", number1, number2, (number1 - number2));
			break;

		case 'm':
			printf("%f * %f = %f\n", number1, number2, (number1 * number2));
			break;

		case 'd':
			if (0.0 == number2)
			{
				printf("Enter a number other than 0:");
				while (scanf_s("%f", &number2) != 1)
				{
					char ch = 0;
					while ((ch = getchar()) != '\n')
					{
						putchar(ch);
					}
					printf(" is not an number.\n");
					printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
				}
				getchar();
			}
			printf("%f / %f = %f\n", number1, number2, (number1 / number2));
			break;

		default:
			break;
		}
	} while (1);

	return;
}




int main(int argc, char **argv)
{
	p8_8();

	while (getchar());

	return 0;
}