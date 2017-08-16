#include <stdio.h>

/************************************************************************/
/* practice 1                                                                     */
/************************************************************************/
#define SECONDS_PER_MINUTE (60)
void p5_1(void)
{
	float hours = 0;
	int minutes = 0;
	int seconds = 0;
	printf("please input the number of minutes(<= 0 to quit):");
	scanf_s("%d", &minutes);

	while (minutes > 0)
	{
		getchar();
		hours = (float)minutes / SECONDS_PER_MINUTE;
		seconds = minutes * SECONDS_PER_MINUTE;
		printf("%d minute = %f hours or %d seconds\n", minutes, hours, seconds);

		printf("please input the number of minutes(<= 0 to quit):");
		scanf_s("%d", &minutes);
	}

	return ;
}


/************************************************************************/
/* practice 2                                                                     */
/************************************************************************/
void p5_2(void)
{
	int input_num = 0;
	printf("please enter an integer:");
	scanf_s("%d", &input_num);
	getchar();

	printf("the ten integers after %d are:", input_num);
	for (int i = 0; i <= 10; i++)
	{
		printf("%d ", (input_num + i));
	}
	printf("\n");

	return;
}
/************************************************************************/
/* practice 3                                                                     */
/************************************************************************/
const int DAY_PER_WEEK = 7;
void p5_3(void)
{
	int days = 0;
	int weeks = 0;
	int remain_day = 0;
	
	printf("please input the number of day:");
	scanf_s("%d", &days);
	getchar();

	weeks = days / DAY_PER_WEEK;
	remain_day = days % DAY_PER_WEEK;
	printf("%d days are %d weeks, %d days\n", days, weeks, remain_day);

	return ;
}


/************************************************************************/
/* practice 4                                                                     */
/************************************************************************/
const float CM_PER_INCH = 2.54f;
const float CM_PER_FEET = 30.38f;
void p5_4(void)
{
	float height_cm = 0;
	int height_feet = 0;
	float height_inch = 0.0;

	printf("Enter a height in centimeters: ");
	scanf_s("%f", &height_cm);

	while (height_cm > 0) {
		getchar();
		height_feet = (int)(height_cm / CM_PER_FEET);
		height_inch = (height_cm - CM_PER_FEET * height_feet) / CM_PER_INCH;
		printf("%.1f cm = %d feet, %.1f inches\n", height_cm, height_feet, height_inch);

		printf("Enter a height in centimeters(<=0 to quit): ");
		scanf_s("%f", &height_cm);
	}

	return ;
}


/************************************************************************/
/* practice 5                                                                     */
/************************************************************************/
void p5_5(void)
{
	int count, sum;
	count = 0;
	sum = 0;

	printf("please enter work days:");
	scanf_s("%d", &count);
	getchar();

	do 
	{
		sum += count;
	} while (count-- > 0);

	printf("sum = %d\n", sum);

	return;
}


/************************************************************************/
/* practice 6                                                                     */
/************************************************************************/
#define SQUARE(X) ((X) * (X))
void p5_6(void)
{
	int count, sum;
	count = 0;
	sum = 0;

	printf("please enter work days:");
	scanf_s("%d", &count);
	getchar();

	do 
	{
		sum += SQUARE(count);
	} while (count-- >0);

	printf("sum = %d\n", sum);

	return;
}


/************************************************************************/
/* practice 7                                                                     */
/************************************************************************/
void cube(double input)
{
	double cube_num = input * input * input;
	printf("the cube of %lf is %lf\n", input, cube_num);

	return;
}

void p5_7(void)
{
	double input = 0.0;
	printf("please enter a double number:");
	scanf_s("%lf", &input);
	getchar();

	cube(input);

	return;	
}


/************************************************************************/
/* practice 8                                                                     */
/************************************************************************/
void p5_8(void)
{
	int first_operand = 0;
	int second_operand = 0;

	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand:");
	scanf_s("%d", &second_operand);
	getchar();

	printf("Now enter the first operand:");
	scanf_s("%d", &first_operand);

	while (first_operand > 0)
	{
		getchar();
		printf("%d %% %d is %d\n", first_operand, second_operand, (first_operand % second_operand));

		printf("Enter next number for first operand (<=0 to quit):");
		scanf_s("%d", &first_operand);
	}

	printf("Done\n");

	return;
}


/************************************************************************/
/* practice 9                                                                     */
/************************************************************************/
void Temperatures(const double temperature)
{
	const double Fahrenheit_val = 32.0;
	const double Kelvin_val = 273.16;
	const double Fahrenheit_temp = 5.0 / 9.0 * (temperature - Fahrenheit_val);
	const double Kelvin_temp = temperature + Kelvin_val;

	printf("Celsius: %.2lf  Fahrenheit:%.2lf  Kelvin:%.2lf\n", temperature, Fahrenheit_temp, Kelvin_temp);
	return;
}
void p5_9(void)
{
	double temperature = 0.0;

	printf("please enter the temperature (q to quit):");
	while (scanf_s("%lf", &temperature) == 1)
	{
		getchar();
		Temperatures(temperature);
		printf("please enter the temperature (q to quit):");
	}

	return;
}


int main(int argc, char **argv)
{
	p5_9();

	getchar();

	return 1;
}