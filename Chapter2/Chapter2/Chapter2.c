#include <stdio.h>

/************************************************************************/
/* practice 2                                                                     */
/************************************************************************/
void p2_(void)
{
	int ch = 0;
	printf("please input the value of ascii:");
	scanf_s("%d", &ch);

	getchar(); // 删除输入缓冲区中的回车键

	printf("the value of ascii : %d\n", ch);
	printf("the character : %c\n", (char)ch);

	return;
}


/************************************************************************/
/* practice 3                                                                     */
/************************************************************************/
void p2_3(void)
{
	printf("\a");
	printf("Startled by the sudden sound, sally shouted,\n\"By the Great Pumpkin, what was that!\"");

	return;
}


/************************************************************************/
/* practice 4                                                                     */
/************************************************************************/
void p2_4(void)
{
	float input = 0.0;
	printf("Enter a floating-point value:");
	scanf_s("%f", &input);

	getchar();

	printf("fixed-point notation:%f\n", input);
	printf("exponential notation:%e\n", input);
	printf("p notation:%a\n", input);

	return;
}

void p2_4_version2(void)
{
	double input = 0.0;
	printf("Enter a floating-point value:");
	scanf_s("%lf", &input);

	getchar();

	printf("fixed-point notation:%lf\n", input);
	printf("exponential notation:%le\n", input);
	printf("p notation:%la\n", input);

	return;
}


/************************************************************************/
/* practice 5                                                                     */
/************************************************************************/
#define SECONDS_PER_YEAR (3.156e7)

void p2_5(void)
{
	int year = 0;
	printf("How old are you:");
	scanf_s("%d", &year);
	getchar();

	double live_seconds = year * SECONDS_PER_YEAR;

	printf("You have live %lf days\n", live_seconds);
	printf("You have live %le days\n", live_seconds);

	return;
}


/************************************************************************/
/* practice 6                                                                     */
/************************************************************************/
#define QUALITY_OF_WATER_MOLECULE (3.0e-23)
#define NUM_OF_WATER_MOLECULE_PER_QUART (950/QUALITY_OF_WATER_MOLECULE)

void p2_6(void)
{
	double num_of_quart = 0;
	printf("How much quart of water:");
	scanf_s("%lf", &num_of_quart);
	getchar();

	double num_of_water_molecule = num_of_quart * NUM_OF_WATER_MOLECULE_PER_QUART;
	printf("there are %lf quart water and %le water molecule", num_of_quart, NUM_OF_WATER_MOLECULE_PER_QUART);

	return;
}


/************************************************************************/
/*  practice 7                                                                     */
/************************************************************************/
#define CM_PER_INCH (2.54)

void p2_7(void)
{
	float height_in_inch = 0;
	float height_in_cm = 0;
	printf("What's your height in inch:");
	scanf_s("%f", &height_in_inch);
	getchar();

	height_in_cm = height_in_inch * CM_PER_INCH;
	printf("Your height is %f in cm\n", height_in_cm);

	return;
}


/************************************************************************/
/* practice 8                                                                     */
/************************************************************************/
#define CUPS_PER_PINT (2)
#define OUNCES_PER_CUP (8)
#define BIG_SPOONS_PER_OUNCE (2)
#define TEA_SPIINS_PER_BIG_SPOON (3)

void p2_8(void)
{
	float cups = 0;
	float pints = 0;
	float ounces = 0;
	float big_spoons = 0;
	float tea_spoons = 0;

	printf("How many cups of tea do you want:");
	scanf_s("%f", &cups);
	getchar();
	pints = cups / CUPS_PER_PINT;
	ounces = cups * OUNCES_PER_CUP;
	big_spoons = ounces * BIG_SPOONS_PER_OUNCE;
	tea_spoons = big_spoons * TEA_SPIINS_PER_BIG_SPOON;

	printf("pints:%f, cups:%f, ounces:%f, big_spoons:%f, tea_spoons:%f\n", pints, cups, ounces, big_spoons, tea_spoons);

	return;

}

/************************************************************************/
/* main to test                                                                     */
/************************************************************************/
int main(int argc, char **argv)
{
	p2_8();

	getchar();

	return 0;
}