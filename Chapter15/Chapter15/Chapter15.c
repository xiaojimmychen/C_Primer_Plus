#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>


// practice 1
void p15_1(void)
{
	char *pbin = "01001001";
	int num = 0;
	int p_length = strlen(pbin);

	for (int i = 0; i < p_length; i++)
	{
		num = num * 2 + (pbin[i] - '0');
	}

	printf("the number is %d.\n", num);
}


// practice 2
int binargstr2int(char *pbin)
{
	int num = 0;
	int p_length = strlen(pbin);

	for (int i = 0; i < p_length; i++)
	{
		num = num * 2 + (pbin[i] - '0');
	}

	return num;
}
int p15_2(int argc, char **argv)
{
	unsigned int number1 = 0;
	unsigned int number2 = 0;

	if (argc != 3)
	{
		printf("Usage: binary_string binarg_string\n");
		return 0;
	}

	number1 = binargstr2int(argv[1]);
	number2 = binargstr2int(argv[2]);

	int nega_number1 = ~number1;
	int nega_number2 = ~number2;

	// printf没有二进制输出，使用十六进制输出，将就看吧
	printf("The negative of %s and %s are %x and %x\n", argv[1], argv[2], nega_number1, nega_number2);

	int and = number1 & number2;
	printf("%s & %s = %x\n", argv[1], argv[2], and);

	int or = number1 | number2;
	printf("%s | %s = %x\n", argv[1], argv[2], or);

	int xor = number1 ^ number2;
	printf("%s ^ %s = %x\n", argv[1], argv[2], xor);

	return 0;
}


// practice 3
int check_open_bit(int num)
{
	int open = 0;
	while (num != 0)
	{
		if ((num & 0x01) == 1)
		{
			open++;
		}
		num = num >> 1;
	}

	return open;
}
void p15_3(void)
{
	int num = check_open_bit(0x55);
	printf("0x55 has %d open bits.\n", num);
}


// practice 4
int check_bit(int number, int bit)
{
	return (number & (0x01 << (bit - 1)));
}
void p15_4(void)
{
	int num = check_bit(0x55, 1);
	int num2 = check_bit(0x55, 2);

	printf("0x55 bit 1 is %d, bit 2 is %d.\n", num, num2);
}


// practice 5
unsigned int rotate_l(unsigned int number, unsigned int ro)
{
	unsigned int tmp = 0;
	unsigned int int_bit = sizeof(unsigned int) * 8;
	for (size_t i = 0; i < ro; i++)
	{
		if ((number & (0x01 << int_bit)) == 1)
		{
			number = (number << 1) + 0x01;
		}
		else
		{
			number = number << 1;
		}
	}

	return number;
}
void p15_5(void)
{
	unsigned int number = rotate_l(0x80000001, 1);

	printf("Number:%d", (unsigned int)number);
}


// practice 6
struct characteristic {
	unsigned char ch_id;
	unsigned char ch_size : 7;
	unsigned char ch_align : 2;
	unsigned char ch_bold : 1;
	unsigned char ch_italic : 1;
	// 看运行示例，貌似还有个加下划线的设置
	unsigned char ch_underline : 1;
};
void p15_6(void)
{
	// 下面这个想测试看看这个结构体多大，大家可以先分析下，再执行这个代码
	int characteristic_size = sizeof(struct characteristic);
	printf("struct characteristic size = %d\n", characteristic_size);
	char align[10] = "left";
	char choice = 0;

	struct characteristic chr = { 1, 12, 0, 0, 0, 0 };
	while (1)
	{
		printf("ID SIZE ALIGNMENT%4s%4s%4s\n", "B", "I", "U");
		if (chr.ch_align == 0)
		{
			strcpy(align, "left");
		}
		else if (chr.ch_align == 1)
		{
			strcpy(align, "center");
		}
		else if (chr.ch_align == 2)
		{
			strcpy(align, "right");
		}
		printf("%2d%5d%8s%7s%4s%4s\n", chr.ch_id, chr.ch_size, align, (chr.ch_bold ? "on" : "off"), (chr.ch_italic ? "on" : "off"), 
			(chr.ch_underline ? "on" : "off"));

		printf("%-20s%-20s%-20s\n", "f)change font", "s)change size", "a)change alignment");
		printf("%-20s%-20s%-20s\n", "b)toggle bold", "i)toggle italic", "u)toggle underline");
		printf("%-20s\n", "q)quit");

		scanf("%c", &choice);
		while (getchar() != '\n');
		if (choice == 'q')
		{
			break;
		}

		switch (choice)
		{
		case 'f':
			printf("Enter font id(0-255): ");
			int font_id = 0;
			scanf("%d", &font_id);
			chr.ch_id = font_id;
			while (getchar() != '\n');
			break;

		case 's':
			printf("Enter font size(0-127): ");
			int font_size = 0;
			// 位域地址不能用scanf直接读取，晕
			//scanf("%d", &chr.ch_size);
			scanf("%d", &font_size);
			while (getchar() != '\n');
			chr.ch_size = font_size;
			break;

		case 'a':
			printf("Select alignment:");
			printf("%-10s%-10s%-10s\n", "l)left", "c)center", "r)right");
			char choice = 0;
			scanf("%c", &choice);
			while (getchar() != '\n');
			switch (choice)
			{
			case 'l':
				chr.ch_align = 0;
				break;

			case 'c':
				chr.ch_align = 1;
				break;

			case 'r':
				chr.ch_align = 2;
				break;

			default:
				printf("Input error! Nothing have been changed!\n");
				break;
			}
			break;

		case 'b':
			chr.ch_bold = ~chr.ch_bold;
			break;

		case 'i':
			chr.ch_italic = ~chr.ch_italic;
			break;

		case 'u':
			chr.ch_underline = ~chr.ch_underline;
			break;			

		default:
			printf("Error choice. Nothing have been changed!\n");
			break;
		}
	}

	printf("Done.\n");
	return;
}


// practice 7
void p15_7(void)
{
	/* practice 6中通过sizeof测出来的大小是3字节，所以其实使用int行就足够的了
	   这里按要求使用unsigned long
	   bit:0	表示下划线开关位
	   bit:1	表示斜体开关位
	   bit:2	表示加粗开关位
	   bit:3-4	表示对齐
	   bit:8-15	表示字体大小
	   bit:16-23 表示字体ID
	*/
	unsigned long ch = 0;

	char align[10] = "left";
	char choice = 0;
	
	while (1)
	{
		printf("ID SIZE ALIGNMENT%4s%4s%4s\n", "B", "I", "U");
		if ((ch >> 3 & 0x3) == 0)
		{
			strcpy(align, "left");
		}
		else if (((ch >> 3) & 0x3) == 1)
		{
			strcpy(align, "center");
		}
		else if (((ch >> 3) & 0x3) == 2)
		{
			strcpy(align, "right");
		}
		printf("%2d%5d%8s%7s%4s%4s\n", ((ch >> 16) & 0xff), ((ch >> 8) & 0xff), align, (((ch >> 2) & 0x01) ? "on" : "off"), 
			(((ch >> 1) & 0x01) ? "on" : "off"), ((ch & 0x01) ? "on" : "off"));

		printf("%-20s%-20s%-20s\n", "f)change font", "s)change size", "a)change alignment");
		printf("%-20s%-20s%-20s\n", "b)toggle bold", "i)toggle italic", "u)toggle underline");
		printf("%-20s\n", "q)quit");

		scanf("%c", &choice);
		while (getchar() != '\n');
		if (choice == 'q')
		{
			break;
		}

		switch (choice)
		{
		case 'f':
			printf("Enter font id(0-255): ");
			unsigned char font_id = 0;
			scanf("%d", &font_id);
			ch &= ~(0xff << 16);
			ch |= (font_id << 16);
			while (getchar() != '\n');
			break;

		case 's':
			printf("Enter font size(0-127): ");
			unsigned char font_size = 0;
			scanf("%d", &font_size);
			while (getchar() != '\n');
			ch &= ~(0xff << 8);
			ch |= (font_size << 8);
			break;

		case 'a':
			printf("Select alignment:");
			printf("%-10s%-10s%-10s\n", "l)left", "c)center", "r)right");
			char choice = 0;
			scanf("%c", &choice);
			while (getchar() != '\n');
			// 先将对齐字段清零
			ch &= ~(0x03 << 3);
			switch (choice)
			{
			case 'l':
				ch |= (0x00 << 3);
				break;

			case 'c':
				ch |= (0x01 << 3);
				break;

			case 'r':
				ch |= (0x02 << 3);
				break;

			default:
				printf("Input error! Nothing have been changed!\n");
				break;
			}
			break;

		case 'b':
			if (ch & (0x01 << 2))
			{
				ch &= ~(0x01 << 2);
			}
			else
			{
				ch |= (0x01 << 2);
			}
			break;

		case 'i':
			if (ch & (0x01 << 1))
			{
				ch &= ~(0x01 << 1);
			}
			else
			{
				ch |= (0x01 << 1);
			}
			break;

		case 'u':
			if (ch & 0x01)
			{
				ch &= ~(0x01);
			}
			else
			{
				ch |= 0x01;
			}
			break;

		default:
			printf("Error choice. Nothing have been changed!\n");
			break;
		}
	}

	printf("Done.\n");
	return;

}




int main(int argc, char **argv)
{
	p15_7();
//	p15_2(argc, argv);

	while (getchar());

	return 0;
}