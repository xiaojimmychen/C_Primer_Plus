#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>


// practice 1
void p7_1(void)
{
	char ch = 0;
	int n_space = 0;
	int n_break = 0;
	int n_other = 0;

	printf("Please enter text to be analyzed(# to terminate):");
	while ((ch = getchar()) != '#')
	{
		if (' ' == ch)
		{
			n_space++;
		}
		else if ('\n' == ch)
		{
			n_break++;
		}
		else
		{
			n_other++;
		}
	}


	printf("break = %d, space = %d, other = %d\n", n_break, n_space, n_other);
	return;
}


// practice 2
void p7_2(void)
{
	char ch = 0;
	int i = 0;
	
	printf("Please enter text to be analyzed:(# to terminate):");
	while ((ch = getchar()) != '#')
	{
		if ((i % 8 == 0) && (i != 0))
		{
			putchar('\n');
		}
		i++;
		printf("%c:%d ", ch, ch);
	}

	return;
}


// practice 3
void p7_3(void)
{
	int n_odd = 0;
	int n_even = 0;
	int sum_odd = 0;
	int sum_even = 0;
	int input = 0;

	printf("Please enter integer to be analyzed(0 to terminate):");
	while (scanf_s("%d", &input))
	{
		if (0 == input)
		{
			break;
		}
		else if (0 == (input % 2))
		{
			n_even++;
			sum_even += input;
		}
		else
		{
			n_odd++;
			sum_odd += input;
		}
	}

	printf("the average value of %d even is: %d; the average value of %d odd is: %d\n", n_even, (sum_even/n_even), n_odd, (sum_odd/n_odd));

	return;

}


// practice 4
void p7_4(void)
{
	char ch = 0;

	printf("Please enter text to be analyzed:(# to terminate):");
	while ((ch = getchar()) != '#')
	{
		if ('.' == ch)
		{
			putchar('!');
		}
		else if ('!' == ch)
		{
			putchar('!');
			putchar('!');
		}
		else
		{
			putchar(ch);
		}
	}

	return;
}


// practice 5
void p7_5(void)
{
	char ch = 0;

	printf("Please enter text to be analyzed (# to terminate):");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case '.':
			putchar('!');
			break;

		case '!':
			putchar('!');
			putchar('!');
			break;

		default:
			putchar(ch);
			break;
		}
	}

	return;
}


// practice 6
void p7_6(void)
{
	char ch = 0;
	char ch_pre = 0;
	int n_appear = 0;

	printf("Please enter text to be analyzed (# to terminate): ");
	while ((ch = getchar()) != '#')
	{
		if ('i' == ch)
		{
			if ('e' == ch_pre)
			{
				n_appear++;
			}
		}
		ch_pre = ch;
	}

	printf("ei has appeared %d times.\n", n_appear);
	return;
}


// practice 7
#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25
void p7_7(void)
{
	double work_hours = 0;
	double total_income = 0;
	double tax = 0;
	double	net_income = 0;

	printf("How long have you worked:");
	scanf_s("%lf", &work_hours);
	if (work_hours > 40)
	{
		work_hours = (work_hours - 40) * 1.5 + 40;
	}

	total_income = work_hours * 1000;
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

	printf("total income = %lf, tax = %lf, net income = %lf\n", total_income, tax, net_income);

	return;

}


// practice 8
void p7_8(void)
{
	int chooice = 0;

	double work_hours = 0;
	double total_income = 0;
	double tax = 0;
	double net_income = 0;
	double hourly_wage = 0;

	while (1)
	{
		printf("Enter the number corresponding to the desired pay rate to action:\n");
		printf("%-20s%-20s\n%-20s%-20s\n%-20s\n", "1) $8.75/hr", "2) $9.33/hr", "3) $10.00/hr", "4) $11.20/hr", "5) quit");
		scanf_s("%d", &chooice);

		switch (chooice)
		{
		case 1:
			hourly_wage = 8.75;
			break;

		case 2:
			hourly_wage = 9.33;
			break;

		case 3:
			hourly_wage = 10.00;
			break;

		case 4:
			hourly_wage = 11.20;
			break;

		case 5:
			return;

		default:
			printf("Please enter the choice between 1 to 5\n");
			continue;
		}


		printf("How long have you worked:");
		scanf_s("%lf", &work_hours);
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


// practice 9
void p7_9(void)
{
	int input = 0;

	printf("please input the upper number:");
	scanf_s("%d", &input);

	int i = 0;
	int j = 0;

	for (i = 2; i <= input; i++)
	{
		for (j = 2; j < sqrt((double)i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d ", i);
		}
	}
}


// practice 10
void p7_10(void)
{
	int choice = 0;
	double income = 0;
	double threshold = 0;
	double tax = 0;
	
	while (1)
	{
		printf("Please choose the category:\n");
		printf("1) Single\n2) Head of household\n3) Married,Shared\n4) Married,dieorced\nEnter you choice:");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			threshold = 17850.0;
			break;

		case 2:
			threshold = 23900.0;
			break;

		case 3:
			threshold = 29750.0;
			break;

		case 4:
			threshold = 14875.0;
			break;

		default:
			printf("invalid choice!");
			continue;
		}

		printf("Please input your income:");
		scanf_s("%lf", &income);
		if (income < threshold)
		{
			tax = income * 0.15;
		}
		else
		{
			tax = threshold * 0.15 + (income - threshold) * 0.28;
		}

		printf("category:%d, income:%.2lf, tax:%.2lf\n", choice, income, tax);
	}

	return;
}


// practice 11
void p7_11(void)
{
	double n_artichoke = 0.0;
	double n_beet = 0.0;
	double n_carrot = 0.0;
	double freight = 0.0;
	double n_pound = 0.0;
	char choice = 0;
	double total_cost = 0.0;
	double discount = 0.0;
	double total_weight = 0.0;


	while ('q' != choice)
	{
		printf("Please choose the item you want to buy:\n");
		printf("%-20s%-20s\n%-20s%-20s\n", "a) Artichoke", "b) Beet", "c) Carrot", "q) Quit");
		printf("Now enter you choose:");
		choice = getchar();

		switch (choice)
		{
		case 'a':
			printf("How many pounds of Artichoke do you want to buy:");
			scanf_s("%lf", &n_pound);
			n_artichoke += n_pound;
			break;

		case 'b':
			printf("How many pounds of Beet do you want to buy:");
			scanf_s("%lf", &n_pound);
			n_beet += n_pound;
			break;

		case 'c':
			printf("How many pounds of Carrot do you want to buy:");
			scanf_s("%lf", &n_pound);
			n_carrot += n_pound;
			break;

		case 'q':
			continue;

		default:
			printf("Your choice is invalid! Please choose again.\n");
			break;
		}
		while (getchar() != '\n');
	}

	printf("%-20s%-20s%-20s%-20s\n", "Category", "Price", "Pounds", "Total price");
	printf("%-20s%-20s%-20.2lf%-20.2lf\n", "Artichoke", "$2.05/pound", n_artichoke, (n_artichoke * 2.05));
	printf("%-20s%-20s%-20.2lf%-20.2lf\n", "Beet", "$1.15/pound", n_beet, (n_beet * 1.15));
	printf("%-20s%-20s%-20.2lf%-20.2lf\n", "Carrot", "$1.09/pound", n_carrot, (n_carrot * 1.09));
		
	total_cost = n_artichoke * 2.05 + n_beet * 1.15 + n_carrot * 1.09;
	printf("Total_cost:%.2lf", total_cost);
	if (total_cost > 100)
	{
		discount = total_cost * 0.05;
		printf(" Discount:%,2lf", discount);
		total_cost -= discount;
	}

	total_weight = n_artichoke + n_beet + n_carrot;
	if (total_weight <= 5.0)
	{
		freight = 6.5;
	}
	else if (5.0 < total_weight <= 20)
	{
		freight = 14.0;
	}
	else
	{
		freight = 14 + (total_weight - 20) * 0.5;
	}
	printf(" Total_freight:%.2lf", freight);

	printf(" Final cost:%.2lf", (total_cost - discount + freight));

	return;
}



int main(int argc, char **argv)
{
	p7_11();

	while (getchar())  //防止控制台一闪而过
	{
		
	}

	return 0;
}