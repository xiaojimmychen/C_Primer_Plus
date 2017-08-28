#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>



// practice 1
int p13_1(void)
{
	int ch;
	FILE *fp;
	unsigned long count = 0;
	char file_name[256];

	printf("Enter the file name: ");
	scanf_s("%s", file_name, 256);

	if ((fp = fopen(file_name, "r")) == NULL) // fopen函数在VS2017中报告会报错，解决办法是在 项目 =》属性 =》c/c++  =》预处理器=》点击预处理器定义，编辑，加入_CRT_SECURE_NO_WARNINGS
	{									      // scanf_s之类的安全增强函数应该也适用(具体还没有试过)，早知道就百度查一下了，之前使用的都是scanf_s
		printf("Can't not open %s\n", file_name);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", file_name, count);

	return 0;
}


// practice 2
void p13_2(void)
{
	FILE *fp1;
	FILE *fp2;
	char *file1 = "data1.dat";
	char *file2 = "data2.dat";
	int ch = 0;

	if ((fp1 = fopen(file1, "rb")) == NULL)
	{
		printf("Can't open %s\n", file1);
	}
	if ((fp2 = fopen(file2, "wb")) == NULL)
	{
		printf("Can't open %s\n", file2);
	}

	while ((ch = fgetc(fp1)) != EOF)
	{
		fputc(ch, fp2);;
	}

	fclose(fp1);
	fclose(fp2);

	return;	
}


//practice 3
void p13_3(void)
{
	char file_name[256];
	char *tmp_file = "tmp.txt";  // 现在只能想到把读出来的数据保存到一个缓存文件里，然后再从缓存文件度回，暂时没想到同时读取修改同一个文件的方法
	int ch = 0;
	FILE *fp_r;
	FILE *fp_w;

	printf("Enter the file name: ");
	gets_s(file_name, 256);

	if ((fp_r = fopen(file_name, "r+")) == NULL)
	{
		printf("Can't open %s as read mode!\n", file_name);
	}

	if ((fp_w = fopen(tmp_file, "w")) == NULL)
	{
		printf("Can't open %s as write mode!\n", tmp_file);
	}

	while ((ch = fgetc(fp_r)) != EOF)
	{
		ch = toupper(ch);
		fputc(ch, fp_w);

	}

	fclose(fp_r);
	fclose(fp_w);

	if ((fp_r = fopen(tmp_file, "r")) == NULL)
	{
		printf("Can't open %s as read!\n", tmp_file);
	}
	if ((fp_w = fopen(file_name, "w")) == NULL)
	{
		printf("Can't open %s as write!\n", file_name);
	}
	while ((ch = fgetc(fp_r)) != EOF)
	{
		fputc(ch, fp_w);
	}

	fclose(fp_r);
	fclose(fp_w);
	remove(tmp_file);

	printf("Done.\n");

	return;
}


// practice 4
int p13_4(int argc, char **argv)
{
	FILE *fp;
	char buf[256] = { 0 };
	for (int i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			printf("Can't open file %s as read!\n", argv[i]);
		}

		printf("%s:\n", argv[i]);
		while (fgets(buf, 256, fp) != NULL)
		{
			fputs(buf, stdout);
		}

		printf("\n");
	}

	printf("Done!\n");

	return 0;
}


// practice 5
#define BUFFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFFSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFFSIZE, source)) > 0)
	{
		fwrite(temp, sizeof(char), bytes, dest);
	}
}
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
void p13_5(int argc, char **argv)
{
	FILE *fa, *fs;
	int files = 0;
	int ch;

	if (argc <3)
	{
		printf("Usage: %s dest_file source1_file ...\n", argv[0]);
		return;
	}

	if ((fa = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFFSIZE) != 0)
	{
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	for (int i = 2; i < argc; i++)
	{
		if (strcmp(argv[1], argv[i]) == 0)
		{
			fputs("Can't append file to itself\n", stderr);
		}
		else if ((fs = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Can't open %s\n", argv[i]);
		}
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFFSIZE) != 0)
			{
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
			{
				fprintf(stderr, "Error in reading file %s.\n", argv[i]);
			}
			if (ferror(fa) != 0)
			{
				fprintf(stderr, "Error in writing file %s.n", argv[1]);
			}
			fclose(fs);
			files++;
			printf("File %s appended.\n", argv[i]);
		}
	}

	printf("Done appending. %d files appended.\n", files);
	rewind(fa);
	printf("%s contents:\n", argv[1]);
	while ((ch = getc(fa)) != EOF)
	{
		putchar(ch);
	}
	puts("Done displaying!\n");
	fclose(fa);

	return;
}


// practice 6
#define LEN 40
void p13_6(void)
{
	FILE *in, *out;
	int ch;
	char out_file[LEN];
	char in_file[LEN];
	int count = 0;

	printf("Enter the file name:");
	gets_s(in_file, LEN);

	if ((in = fopen(in_file, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file\"%s\"", in_file);
		exit(EXIT_FAILURE);
	}

	strncpy(out_file, in_file, LEN-5);
	out_file[LEN - 5] = '\0';
	strcat(out_file, ".red");

	if ((out = fopen(out_file, "w")) == NULL)
	{
		fprintf(stderr, "Can't creat output file.\n");
		exit(3);
	}

	while ((ch = getc(in)) != EOF)
	{
		if (count++ % 3 == 0)
			putc(ch, out);
	}

	if (fclose(in) != 0 || fclose(out) != 0)
	{
		fprintf(stderr, "Error in closing files\n");
	}

	return;

}


// practice 7
void p13_7(void)
{
	FILE *file1, *file2;
	char file_name1[128];
	char file_name2[128];
	char buf1[256] = { 0 };
	char buf2[256] = { 0 };

	printf("Enter the first file name:");
	gets_s(file_name1, 128);

	printf("Enter the second file name:");
	gets_s(file_name2, 128);

	if ((file1 = fopen(file_name1, "r")) == NULL)
	{
		printf("Can't open %s\n", file_name1);
	}
	if ((file2 = fopen(file_name2, "r")) == NULL)
	{
		printf("Can't open %s\n", file_name2);
	}

	while ((feof(file1) == 0) || (feof(file2) == 0))
	{
		if (fgets(buf1, 256, file1) != NULL)
		{
			int length = strlen(buf1);
			// 要实现B情况，添加如下代码
			/*
			if (buf1[length - 1] == '\n')
			{
				buf1[length - 1] = '\0';
			}
			*/
			fputs(buf1, stdout);
		}
		if (fgets(buf2, 256, file2) != NULL)
		{
			fputs(buf2, stdout);
		}
	}

	return;
}


// practice 8
void p13_8(int argc, char **argv)
{
	char find_ch = 0;
	char ch = 0;
	char input[256] = { 0 };
	int repeat_time = 0;
	FILE *fp;

	if (argc < 2)
	{
		printf("Usage: %s <character> [file_name1 ....]", argv[0]);
		return;
	}

	find_ch = argv[1][0];
	if (argc == 2)
	{
		printf("Enter the string you wanted to analysize: ");
		gets_s(input, 256);
		int input_length = strlen(input);
		for (int i = 0; i < input_length; i++)
		{
			if (find_ch == input[i])
			{
				repeat_time++;
			}
		}

		printf("In string \"%s\", %c have appeared %d times!\n", input, find_ch, repeat_time);
	}
	else
	{
		for (int i = 2; i < argc; i++)
		{
			repeat_time = 0;
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				printf("Can't open %s\n", argv[i]);
				continue;
			}

			while ((ch = fgetc(fp)) != EOF)
			{
				if (ch == find_ch)
				{
					repeat_time++;
				}
			}
			printf("In file %s, %c have appeared %d time!\n", argv[i], find_ch, repeat_time);
		}
	}

	return;
}


// practice 9
// 暂时的想到的解决办法是将单词读出来获取前面的标号，但是这样好像不够优雅
#define MAX 41
void p13_9(void)
{
	FILE *fp;
	char words[MAX];
	int n_word = 0;

	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout, "Can't open\"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}

	rewind(fp);
	while (fgets(words, MAX, fp) != NULL)
	{
		n_word++;
	}

	puts("Enter words to add to the file; press the #");
	puts("key at the begining of a line to terminate.");

	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
	{
		fprintf(fp, "%d:%s\n", ++n_word, words);
	}
	puts("File contents:");
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1)
	{
		puts(words);
	}
	puts("Done");
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error closing file\n");
	}

	return;
}


// practice 10
void p13_10(void)
{
	char file_name[256];
	char content[256];
	int file_seek = 0;
	FILE *fp;

	printf("Enter the file name:");
	fscanf(stdin, "%s", file_name);
//	scanf("%s", file_name);

	if ((fp = fopen(file_name, "r")) == NULL)
	{
		printf("Can't open %s file.\n", file_name);
	}

	while (1)
	{
		printf("Enter the location of file to print ( <0 to terminate) :");
		if (fscanf(stdin, "%d", &file_seek) != 1 || file_seek < 0)
		{
			break;
		}
		fseek(fp, file_seek, SEEK_SET);
		fgets(content, 256, fp);
//		fscanf(fp, "%s", content);
//		奇怪，下面这两个打印方法都没有办法打印 (好吧，我知道了，我这是输出啊，应该用的是stdout，汗....)
//		fprintf(stdin, "%s", content);
//		fputs(content, stdin);
		printf("%s", content);
	}

	puts("Done");
	fclose(fp);

	return;
}


// practice 11
void p13_11(int argc, char **argv)
{
	char content[256];
	FILE *fp;

	if (argc != 3)
	{
		printf("Usage: %s <string> <file_name>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("Can't open file %s.\n", argv[2]);
	}
	while ((fgets(content, 256, fp)) != NULL)
	{
		if (strstr(content, argv[1]) != NULL)
		{
			fputs(content, stdout);
		}
	}
}


// practice 12，13，14
// 剩下的就不写了，那个数组600个数字，全部输完都成斗鸡眼了





int main(int argc, char **argv)
{
//	p13_10();
	p13_11(argc, argv);

	while (getchar());

	return 0;
}