#include <stdio.h>
#include <float.h>

/************************************************************************/
/* practice 1                                                                     */
/************************************************************************/
void p4_1(void)
{
	char first_name[40];
	char last_name[40];
	printf("What's your first name:");
	scanf_s("%s", first_name);
	
	printf("What's your last name:");
	scanf_s("%s", last_name);

	getchar();

	printf("%*s,%*s\n", first_name, last_name);

	return;
}


/************************************************************************/
/* practice 2                                                                     */
/************************************************************************/
void p4_2(void)
{
	char first_name[40];
	char last_name[40];
	int first_name_length = 0;
	int last_name_lenght = 0;
	printf("What's your first name:");
	scanf_s("%s", first_name);

	printf("What's your last name:");
	scanf_s("%s", last_name);
	
	getchar();

	first_name_length = strlen(first_name);
	last_name_lenght = strlen(last_name);

	printf("a.\"%s,%s\"\n", first_name, last_name);
	printf("b.\"%20s,%20s\"\n", first_name, last_name);
	printf("c.\"%-20s,%-20s\"\n", first_name, last_name);
	printf("d.%*s,%*s\n", first_name_length+3, first_name, last_name_lenght+3, last_name);

	return;
}


/************************************************************************/
/* practice 3                                                                     */
/************************************************************************/
void p4_3(void)
{
	double input = 0.0;
	printf("please input the float number:");
	scanf_s("%lf", &input);
	getchar();

	printf("%lf\n", input);
	printf("%e\n", input);

}


/************************************************************************/
/* practice 4                                                                     */
/************************************************************************/
#define CM_PER_INCH (2.54)
void p4_4(void)
{
	float height_inch = 0;
	float height_cm = 0;
	printf("What's your height:");
	scanf_s("%f", &height_inch);
	getchar();

	printf("Dabney, you are %f feet tall\n", height_inch);
	height_cm = height_inch * CM_PER_INCH;
	printf("Dabney, you are %f cm tall\n", height_cm);
}

/************************************************************************/
/* practice 5                                                                     */
/************************************************************************/
void p4_5(void)
{
	float network_speed = 0;
	float file_size = 0;
	float download_time = 0;

	printf("How much your network speed:");
	scanf_s("%f", &network_speed);
	getchar();

	printf("How much is your download file:");
	scanf_s("%f", &file_size);
	getchar();

	download_time = file_size / (network_speed / 8);

	printf("At %f megabits per secnod, a file of %f magebytes\n download in %f seconds.\n", network_speed, file_size, download_time);
}


/************************************************************************/
/* practice 6                                                                     */
/************************************************************************/
void p4_6(void)
{
	char first_name[40] = { 0 };
	char last_name[40] = { 0 };
	int first_name_length = 0;
	int last_name_length = 0;

	printf("What's your first name:");
	scanf_s("%s", first_name);
	getchar();

	printf("What's your last name:");
	scanf_s("%s", last_name);
	getchar();

	first_name_length = strlen(first_name);
	last_name_length = strlen(last_name);

	printf("%s %s\n", first_name, last_name);
	printf("%*d %*d\n", first_name_length, first_name_length, last_name_length, last_name_length);

	printf("%s %s\n", first_name, last_name);
	printf("%-*d %-*d\n", first_name_length, first_name_length, last_name_length, last_name_length);
}


/************************************************************************/
/* practice 7                                                                     */
/************************************************************************/
void p4_7(void)
{
	double d_value = 1.0 / 3.0;
	float f_value = 1.0 / 3.0;

	printf("the value of FLT_DIG:%d, the value of DBL_DIG:%d\n", FLT_DIG, DBL_DIG);
	printf("the value of double:%.6lf, the value of float:%.6lf\n", d_value, f_value);
	printf("the value of double:%.12lf, the value of float:%.12lf\n", d_value, f_value);
	printf("the value of double:%.18lf, the value of float:%.18lf\n", d_value, f_value);

}


/************************************************************************/
/* practice 8                                                                     */
/************************************************************************/
#define KM_PER_MILE (1.609)
#define PINT_PER_GALLON (3.785)
void p4_8(void)
{
	float driven_distance = 0.0;
	float gas_consumption = 0.0;
	float pint_per_hundred_km = 0.0;
	float mile_per_gallon = 0.0;
	printf("How much distance have you traveled in kilometer:");
	scanf_s("%f", &driven_distance);
	getchar();

	printf("How much gas have you used in pint:");
	scanf_s("%f", &gas_consumption);
	getchar();

	pint_per_hundred_km = gas_consumption / driven_distance * 100;
	mile_per_gallon = (driven_distance / KM_PER_MILE) / (gas_consumption / PINT_PER_GALLON);

	printf("Fuel consumptions:%f pint/100km or %f mile/gallon\n", pint_per_hundred_km, mile_per_gallon);
}

int main(int argc, char **argv)
{
	p4_8();

	getchar();
}