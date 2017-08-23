#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>




// practice 1
void get_input(char *input, int num)
{
	printf("Please enter %d character:", num);
	for (size_t i = 0; i < num; i++)
	{
		input[i] = getchar();
	}

	return;
}
void p11_1(void)
{
	char input[256];
	int number = 0;
	printf("Enter the number of character:");
	scanf_s("%d", &number);
	getchar();

	get_input(input, number);
	printf("You input:");
	for (size_t i = 0; i < number; i++)
	{
		printf("%c", input[i]);
	}
	printf("\n");
}


// practice 2
void get_input_rewrite(char *input, int num)
{
	printf("Please enter:");
	char ch = 0;
	for (size_t i = 0; i < num; i++)
	{
		ch = getchar();
		if (isblank(ch))
		{
			return;
		}
		else
		{
			input[i] = ch;
		}
	}

	return;
}
void p11_2(void)
{
	char input[256];
	int number = 0;
	printf("Enter the number of character:");
	scanf_s("%d", &number);
	getchar();

	get_input_rewrite(input, number);
	printf("You input:");
	for (size_t i = 0; i < number; i++)
	{
		printf("%c", input[i]);
	}
	printf("\n");
}


// practice 3
void get_input2(char *input)
{
	char ch = 0;
	int i = 0;
	printf("Enter the word:");
	do
	{
		ch = getchar();
		if (!isblank(ch))
		{
			break;
		}
	} while (1);

	input[i++] = ch;
	do
	{
		ch = getchar();
		if (isblank(ch))
		{
			break;
		}
		input[i++] = ch;
	} while (1);

	input[i] = '\0';

	return;
}
void p11_3(void)
{
	char input[256];
	
	get_input2(input);

	printf("The word you entered is %s\n", input);

	return;
}


// practice 4
void get_input3(char *input, int num)
{
	char ch = 0;
	int i = 0;
	printf("Enter the word, limited in %d character:", num-1);
	do
	{
		ch = getchar();
		if (!isblank(ch))
		{
			break;
		}
	} while (1);

	input[i++] = ch;
	do
	{
		ch = getchar();
		if (isblank(ch))
		{
			break;
		}
		input[i++] = ch;
		if (i >= num - 1)
		{
			break;
		}
	} while (1);

	input[i] = '\0';

	return;
}
void p11_4(void)
{
	char input[10];

	get_input3(input, 10);

	printf("The word you entered is %s\n", input);

	return;
}


// practice 5
int strchr1(char *string, char *chr)
{
	int string_length = strlen(string);
	int chr_length = strlen(chr);
	int m = 0;
	int n = 0;

	for (size_t i = 0; i < string_length; i++)
	{
		n = i;
		m = 0;
		while (string[n] == chr[m])
		{
			n++;
			m++;
			if (m >= chr_length)
			{
				return i;
			}
		}
	}
	return -1;
}
void p11_5(void)
{
	char string[256];
	char chr[256];
	int loc = 0;

	printf("Enter the string:");
	gets_s(string, 256);

	printf("Enter the string you want to find:");
	gets_s(chr, 256);

	loc = strchr1(string, chr);

	if (-1 == loc)
	{
		printf("%s doesn't appear in %s\n", chr, string);
	}
	else
	{
		printf("For %s, it is staring from %d character in %s\n", chr, loc, string);
	}

	return;
}


// practice 6
int is_within(char ch, char *string)
{
	int string_length = strlen(string);
	for (size_t i = 0; i < string_length; i++)
	{
		if (ch == string[i])
		{
			return 1;
		}
	}
	
	return 0;
}
void p11_6(void)
{
	char ch = 0;
	char string[256];
	_Bool within = 0;

	while ('q' != ch)
	{
		printf("Enter the string:");
		gets_s(string, 256);

		printf("Enter the character:");
		ch = getchar();
		getchar();

		within = is_within(ch, string);
		if (within == 0)
		{
			printf("character %c is not within %s\n", ch, string);
		}
		else
		{
			printf("character %c is within %s\n", ch, string);
		}
	}
	
	return;
}


// practice 7
char *mystrncpy(char *s1, char *s2, int n)
{
	int s1_length = strlen(s1);
	int s2_length = strlen(s2);
	int copy_length = (s2_length >= n ? n : s2_length);

	for (size_t i = 0; i < copy_length; i++)
	{
		s1[s1_length + i] = s2[i];
	}

	if (s2_length < n)
	{
		s1[s1_length + s2_length] = '\0';
	}

	return s1;
}
void p11_7(void)
{
	char string1[256];
	char string2[256];
	int string1_length = 0;
	int string2_length = 0;

	while (1) // 一直循环输入吧，也可以添加一个退出条件
	{
		printf("Enter the first string:");
		gets_s(string1, 256);

		printf("Enter the second string:");
		gets_s(string2, 256);

		string1_length = strlen(string1);
		string2_length = strlen(string2);

		printf("The first original string: ");
		puts(string1);
		mystrncpy(string1, string2, (256 - string1_length));
		printf("After mystrncpy, ths first string: ");
		puts(string1);
	}
	
	return;
}


// practice 8
// 基本算法和strchr1是一样的，就返回值不同
char *string_in(char *string1, char *string2)
{
	int string_length = strlen(string1);
	int chr_length = strlen(string2);
	int m = 0;
	int n = 0;

	for (size_t i = 0; i < string_length; i++)
	{
		n = i;
		m = 0;
		while (string1[n] == string2[m])
		{
			n++;
			m++;
			if (m >= chr_length)
			{
				return &string1[i];
			}
		}
	}
	return NULL;
}
void p11_8(void)
{
	char string1[256];
	char string2[256];

	while (1) // 一直循环输入吧，也可以添加一个退出条件
	{
		printf("Enter the first string:");
		gets_s(string1, 256);

		printf("Enter the second string:");
		gets_s(string2, 256);

		char *in = string_in(string1, string2);
		if (NULL == in)
		{
			printf("%s is not at %s\n", string2, string1);
		}
		else
		{
			printf("%s is at %s, address:%p\n", string2, string1, in);
		}
	}

	return;
}


// practice 9
void revert_string(char *string)
{
	int string_length = strlen(string);
	for (size_t i = 0; i < string_length / 2; i++)
	{
		char ch = string[i];
		string[i] = string[string_length - i - 1];
		string[string_length - i - 1] = ch;
	}

	return;
}
void p11_9(void)
{
	char string[256];

	while (1)
	{
		printf("Enter the string:");
		gets_s(string, 256);

		printf("The string you entered is %s\n", string);
		revert_string(string);
		printf("After reverting string, The string is %s\n", string);
	}

	return;
}


// practice 10
void remove_space(char *string)
{
	int string_length = strlen(string);
	int m = 0;

	for (size_t i = 0; i < string_length; i++)
	{
		if (isspace(string[i]))
		{
			continue;
		}
		string[m++] = string[i];
	}
	string[m] = '\0';

	return;
}
void p11_10(void)
{
	char string[256];

	printf("Enter the string:");
	gets_s(string, 256);

	while ('\0' != string[0])
	{
		printf("The original string you entered is ");
		puts(string);

		remove_space(string);
		printf("After remove space, the string is ");
		puts(string);

		printf("Enter the next string:");
		gets_s(string, 256);
	}

	printf("Done and exit!");

	return;
}


// practice 11
void print_string(char *string[10], int string_amount)
{
	for (size_t i = 0; i < string_amount; i++)
	{
		printf("%d: ", i);
		puts(string[i]);
	}

	return;
}
void print_original_string(char string[][256], int string_amount)
{ 
	static char *string_ori[10];  // 本质数组，存储十个指向char的指针
	static _Bool sort = 0;		//记录是否已经处理过，没必要每次都处理吧

	if (sort != 1)
	{
		for (size_t i = 0; i < string_amount; i++)
		{
			string_ori[i] = string[i];
		}

		sort = 1;
	}

	printf("Now print the original string:\n"); 
	print_string(string_ori, string_amount);
}
void print_string_by_ascii(char string[][256], int string_amount)
{
	static char *string_ascii[10]; // 本质数组，存储十个指向char的指针
	static _Bool sort = 0;	//记录是否已经处理过，没必要每次都处理吧

	if (sort != 1)
	{
		for (size_t i = 0; i < string_amount; i++)
		{
			string_ascii[i] = string[i];
		}

		for (size_t i = 0; i < string_amount; i++)
		{
			for (size_t j = i + 1; j < string_amount; j++)
			{
				int result = strcmp(string_ascii[i], string_ascii[j]);
				if (result > 0)
				{
					char *tmp = string_ascii[j];
					string_ascii[j] = string_ascii[i];
					string_ascii[i] = tmp;
				}
			}
		}

		sort = 1;
	}

	printf("Now print the string sorted by ascii:\n");
	print_string(string_ascii, string_amount);
}
void print_string_by_length(char string[][256], int string_amount)
{
	static char *string_length[10];
	static _Bool sort = 0;
	 
	if (sort != 1)
	{
		for (size_t i = 0; i < string_amount; i++)
		{
			string_length[i] = string[i];
		}

		for (size_t i = 0; i < string_amount; i++)
		{
			for (size_t j = i + 1; j < string_amount; j++)
			{
				if (strlen(string_length[i]) < strlen(string_length[j]))
				{
					char *tmp = string_length[i];
					string_length[i] = string_length[j];
					string_length[j] = tmp;
				}
			}
		}

		sort = 1;
	}

	printf("Now print the string sorted by string length:\n");
	print_string(string_length, string_amount);
}
int check_first_word_length(char *string)
{
	int result = 0;
	int string_lenght = strlen(string);

	for (size_t i = 0; i < string_lenght; i++)
	{
		if (isspace(string[i]))
		{
			return i;
		}
	}
	return string_lenght;
}
void print_string_by_first_word_length(char string[][256], int string_amount)
{
	static char *string_first_word_length[10];
	static _Bool sort = 0;

	if (sort != 1)
	{
		for (size_t i = 0; i < string_amount; i++)
		{
			string_first_word_length[i] = string[i];
		}

		for (size_t i = 0; i < string_amount; i++)
		{
			for (size_t j = i + 1; j < string_amount; j++)
			{
				if (check_first_word_length(string_first_word_length[i]) < check_first_word_length(string_first_word_length[j]))
				{
					char *tmp = string_first_word_length[i];
					string_first_word_length[i] = string_first_word_length[j];
					string_first_word_length[j] = tmp;
				}
			}
		}

		sort = 1;
	}

	printf("Now print the string sorted by first word length:\n");
	print_string(string_first_word_length, string_amount);
}
void p11_11(void)
{
	char string[10][256];
	char choice = 0;
	int string_amount = 0;

	printf("You can enter up to ten strings:\n");
	for (size_t i = 0; i < 10; i++)
	{
		gets_s(string[i], 256);
		if (string[i][0] == '\0')
		{
			break;
		}
		string_amount++;
	}

	do
	{
		printf("Menu:\n");
		printf("%-50s%-50s\n%-50s%-50s\n%-50s\n", "a) print original string", "b) print string sorted by ascii", "c) print string sorted by string length",
			"d) print string sorted by first word length", "q) quit");
		printf("Now enter your choice: ");

		choice = getchar();
		getchar();

		switch (choice)
		{
		case 'a':
			print_original_string(string, string_amount);
			break;

		case 'b':
			print_string_by_ascii(string, string_amount);
			break;

		case 'c':
			print_string_by_length(string, string_amount);
			break;
			
		case 'd':
			print_string_by_first_word_length(string, string_amount);
			break;

		case 'q':
			printf("Done and quit!\n");
			return;

		default:
			printf("Unkonw command, enter again!\n");
			break;
		}
	} while (1);

}


// practice 12
void p11_12(void)
{
	char string[256];
	int string_length = 0;
	int n_word = 0;
	int n_upper = 0;
	int n_lower = 0;
	int n_punch = 0;
	int n_num = 0;
	
	printf("Enter the string:");
	gets_s(string, 256);
	string_length = strlen(string);

	for (size_t i = 0; i <= string_length; i++)
	{
		if (isspace(string[i]) || '\0' == string[i])
		{
			n_word++;
		}
		else if (isupper(string[i]))
		{
			n_upper++;
		}
		else if (islower(string[i]))
		{
			n_lower++;
		}
		else if (ispunct(string[i]))
		{
			n_punch++;
		}
		else if (isdigit(string[i]))
		{
			n_num++;
		}
	}

	printf("String %s contains %d word, %d upper character, %d lower character, %d punchation, %d digital!\n", string, n_word,
			n_upper, n_lower, n_punch, n_num);

	return;
}


// practice 13
void p11_13(int argc, char **argv)
{
	for (size_t i = argc - 1; i > 0; i--)
	{
		printf("%s ", argv[i]);
	}

	return;
}


// practice 14
void p11_14(int argc, char **argv)
{
	double base = 0.0;
	int index = 0;
	double result = 0.0;

	base = atof(argv[1]);
	index = atoi(argv[2]);

	result = pow(base, index);

	printf("base:%lf, index:%d, result:%lf", base, index, result);
}


// practice 15
int atoi_rewrite(char *string)
{
	int string_length = strlen(string);
	int result = 0;

	for (size_t i = 0; i < string_length; i++)
	{
		if (!isdigit(string[i]))
		{
			return 0;
		}
		result = result * 10 + (string[i] - '0');
	}

	return result;
}
void p11_15(void)
{
	char string[256];
	int result = 0;

	printf("Enter a integer number:");
	gets_s(string, 256);
	result = atoi_rewrite(string);

	printf("string %s to integer %d\n", string, result);
}


// practice 16
void p11_16(int argc, char **argv)
{
	char string[256];
	int string_length = 0;
	
	printf("Enter the string:");
	gets_s(string, 256);
	string_length = strlen(string);
	
	if (strcmp("-p", argv[1]) == 0 || argc == 1)
	{
		printf("Original string: ");
		puts(string);
	}
	else if (strcmp("-u", argv[1]) == 0)
	{
		printf("Upper string:");
		for (size_t i = 0; i < string_length; i++)
		{
			putc(toupper(string[i]), stdout);
		}
		printf("\n");
	}
	else if (strcmp("-l", argv[1]) == 0)
	{
		printf("Lower string: ");
		for (size_t i = 0; i < string_length; i++)
		{
			putc(tolower(string[i]), stdout);
		}
		printf("\n");
	}

	return;
}





int main(int argc, char **argv)
{
//	p11_16(); 
	p11_16(argc, argv);

	while (getchar());

	return;
}