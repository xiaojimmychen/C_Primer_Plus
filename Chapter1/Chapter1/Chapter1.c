#include <stdio.h>

/************************************************************************/
/* practice 1                                                                     */
/************************************************************************/
void p1_1(void)
{
	printf("Jimmy Chen\n");
	printf("Jimmy\n");
	printf("Chen\n");
	printf("Jimmy");
	printf(" Chen\n");

	return;
}

/************************************************************************/
/* practice 2                                                                     */
/************************************************************************/
void p1_2(void)
{
	printf("Name:Jimmy Chen\n");
	printf("Addr:HuiZhou, Guangdong province\n");

	return;
}

/************************************************************************/
/* practice 3                                                                     */
/************************************************************************/
void p1_3(void)
{
	int years_old = 0;
	int live_days = 0;
	printf("How old are you:");
	scanf_s("%d", &years_old);
	getchar(); // 删除输入缓冲区中的回车键
	live_days = years_old * 356;
	
	printf("The days you live for are:%d\n", live_days);

	return;
}

/************************************************************************/
/* practice 4                                                                     */
/************************************************************************/
void jolly(void)
{
	printf("For he's a jolly good fellow!\n");

	return;
}

void deny(void)
{
	printf("Which nobody can deny!\n");
}

void p1_4(void)
{
	jolly();
	jolly();
	jolly();
	deny();

	return;
}

/************************************************************************/
/* practice 5                                                                     */
/************************************************************************/
void br(void)
{
	printf("Brazil, Russia");

	return;
}

void ic(void)
{
	printf("India, China");

	return;
}

void p1_5(void)
{
	br();
	printf(", ");
	ic();
	printf("\n");
	ic();
	printf(",\n");
	br();
	printf("\n");
}

/************************************************************************/
/* practice 6                                                                     */
/************************************************************************/
void p1_6(void)
{
	int toes = 10;
	int double_toes = toes * 2;
	int square_toes = toes * toes;

	printf("the value of toes is : %d\n", toes);
	printf("the value of double toes is : %d\n", double_toes);
	printf("the value of square toes is : %d\n", square_toes);

	return;
}

/************************************************************************/
/* practice 7                                                                     */
/************************************************************************/
void smile(void)
{
	printf("Smile!");

	return;
}

void p1_7(void)
{
	smile(); smile(); smile(); printf("\n");
	smile(); smile(); printf("\n");
	smile(); printf("\n");

	return;
}

/************************************************************************/
/* practice 8                                                                     */
/************************************************************************/
void two(void)
{
	printf("two\n");
	
	return;
}

void p1_8(void)
{
	printf("starting now:\n");
	printf("one\n");
	two();
	printf("three\n");
	printf("done!\n");

	return;
}

/************************************************************************/
/* main for test                                                                     */
/************************************************************************/
int main(int argc, char **argv)
{
	p1_8();

	getchar();

	return 0;
}