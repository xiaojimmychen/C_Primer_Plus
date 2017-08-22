#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


// practice 1
#define MONTHS 12
#define YEARS 5
void p10_1(void)
{
	const float rain[YEARS][MONTHS] =
	{
		{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
		{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
		{9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
		{7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
		{7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
	};

	int year, month;
	float subtot, total;

	printf(" YEAR    RAINFALL(inches)\n");
	for (year = 0, total = 0; year < YEARS; year++)
	{
		for (month = 0, subtot = 0; month < MONTHS; month++)
			subtot += *(*(rain + year) + month);
		printf("%5d %15.1f\n", 2010+year, subtot);
		total += subtot;
	}

	printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
	printf("MONTHLY AVERAGE:\n\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct");
	printf(" Nov Dec\n");

	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtot = 0; year < YEARS; year++)
			subtot += *(*(rain + year) + month);
		printf("%4.1f", subtot / YEARS);
	}

	printf("\n");

	return ;
}


// practice 2
void copy_arr(double target[], double source[], int num)
{
	for (size_t i = 0; i < num; i++)
	{
		target[i] = source[i];
	}

	return;
}
void copy_ptr(double *target, double *source, int num)
{
	for (size_t i = 0; i < num; i++)
	{
		*(target + i) = *(source + i);
	}
	return;
}
void copy_ptrs(double *target, double *source_begin, double *source_end)
{
	for (double *i = source_begin; i < source_end; i++)
	{
		*target++ = *i;
	}
	return;
}
void p10_2(void)
{
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5];
	double target2[5];
	double target3[5];

	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source+5);

	printf("target1:");
	for (size_t i = 0; i < 5; i++)
	{
		printf(" %.2lf", target1[i]);
	}
	printf("\n");

	printf("target2:");
	for (size_t i = 0; i < 5; i++)
	{
		printf(" %.2lf", target2[i]);
	}
	printf("\n");

	printf("target3:");
	for (size_t i = 0; i < 5; i++)
	{
		printf(" %.2lf", target3[i]);
	}
	printf("\n");
}


// practice 3
int max_element(int arr[], int num)
{
	int tmp = arr[0];
	for (size_t i = 0; i < num; i++)
	{
		if (tmp < arr[i])
		{
			tmp = arr[i];
		}
	}

	return tmp;
}
void p10_3(void)
{
	int arr[10] = { 10, 23, 55, 2, 12, 5, 23, 333, 5, 100 };
	int result = max_element(arr, 10);

	printf("The max element of array is %d.\n", result);

	return;
}


// practice 4
int max_element_subscript(double arr[], int num)
{
	double tmp = arr[0];
	int subscript = 0;
	for (size_t i = 0; i < num; i++)
	{
		if (tmp < arr[i])
		{
			tmp = arr[i];
			subscript = i;
		}
	}

	return subscript;
}
void p10_4(void)
{
	double arr[10] = { 1.23, 202.22, 39.03, 292.11, 3939.22, 30.2, 333.33, 938.2, 391.1, 2.2 };
	int result = 0;
	
	result = max_element_subscript(arr, 10);

	printf("The max element subscript of arr is %d\n", result);

	return;
}


// practice 5
double diff_max_min(double arr[], int num)
{
	double max = arr[0];
	double min = arr[0];

	for (size_t i = 0; i < num; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}

		if (min > arr[i])
		{
			min = arr[i];
		}
	}

	return (max - min);
}
void p10_5(void)
{
	double arr[10] = { 1.23, 202.22, 39.03, 292.11, 3939.22, 30.2, 333.33, 938.2, 391.1, 2.2 };
	double result = 0.0;

	printf("The different of max and min is %.2lf\n", diff_max_min(arr, 10));

	return;
}


// practice 6
void revert_arr(double arr[], int num)
{
	for (size_t i = 0; i < num / 2; i++)
	{
		double tmp = arr[i];
		arr[i] = arr[num - 1 - i];
		arr[num - 1 - i] = tmp;
	}
}
void p10_6(void)
{
	double arr[10] = { 1.23, 202.22, 39.03, 292.11, 3939.22, 30.2, 333.33, 938.2, 391.1, 2.2 };

	printf("Before revert, the array is:");
	for (size_t i = 0; i < 10; i++)
	{
		printf(" %.2lf", arr[i]);
	}
	printf("\n");

	revert_arr(arr, 10);

	printf(" After revert, the array is:");
	for (size_t i = 0; i < 10; i++)
	{
		printf(" %.2lf", arr[i]);
	}
	printf("\n");

	return;
}


// practice 7
void p10_7(void)
{
	const double rain[YEARS][MONTHS] =
	{
		{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
		{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
		{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
		{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
		{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
	};

	double rain_cp[YEARS][MONTHS];

	for (size_t i = 0; i < YEARS; i++)
	{
		copy_arr(rain_cp[i], rain[i], MONTHS);
	}

	printf("After copy:\n");
	for (size_t i = 0; i < YEARS; i++)
	{
		for (size_t j = 0; j < MONTHS; j++)
		{
			printf("%.2f ", rain_cp[i][j]);
		}
		printf("\n");
	}
}


// practice 8
void p10_8(void)
{
	double arr[10] = { 1.23, 202.22, 39.03, 292.11, 3939.22, 30.2, 333.33, 938.2, 391.1, 2.2 };
	double target[3];

	copy_ptrs(target, arr+2, arr+5);

	for (size_t i = 0; i < 3; i++)
	{
		printf("%.2lf ", target[i]);
	}
}


// practice 9
void copy_arr_2d(double target[][5], double source[][5], int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			target[i][j] = source[i][j];
		}
	}
	return;
}
void print_arr_2d(double source[][5], int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			printf("%.2lf ", source[i][j]);
		}
	}
	printf("\n");
	return;
}
void p10_9(void)
{
	double source[3][5] =
	{
		{12.3, 32.1, 31.2, 677.6, 325.6},
		{23.1, 568.2, 23.5, 32.4, 88.67},
		{235.8, 64.5, 645.23, 2.3, 23.5}
	};
	double target[3][5];

	copy_arr_2d(target, source, 3);
	print_arr_2d(source, 3);
	print_arr_2d(target, 3);
}


// practice 10
void arr_add(int target[], int source1[], int source2[], int length)
{
	for (size_t i = 0; i < length; i++)
	{
		target[i] = source1[i] + source2[i];
	}

	return;
}
void p10_10(void)
{
	int source1[4] = { 2, 4, 5, 8 };
	int source2[4] = { 1, 0, 4, 6 };
	int target[4];

	arr_add(target, source1, source2, 4);

	for (size_t i = 0; i < 4; i++)
	{
		printf("%d ", source1[i]);
	}
	printf("\n");

	for (size_t i = 0; i < 4; i++)
	{
		printf("%d ", source2[i]);
	}
	printf("\n");

	for (size_t i = 0; i < 4; i++)
	{
		printf("%d ", target[i]);
	}
	printf("\n");

}


// practice 11
void arr_x2(int arr[][5], int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			arr[i][j] = arr[i][j] * 2;
		}
	}

	return;
}
void print_int_arr_2d(int arr[][5], int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return;
}
void p10_11(void)
{
	int source[3][5] =
	{
		{ 12, 32, 31, 677, 325 },
		{ 23, 568, 23, 32, 88 },
		{ 235, 64, 645, 2, 23 }
	};
	
	printf("Original array:\n");
	print_int_arr_2d(source, 3);
	arr_x2(source, 3);
	printf("After x2 array:\n");
	print_int_arr_2d(source, 3);

	return;
}


// practice 12
// 跳过吧，想到的是吧循环抽出来写在函数里，没什么好做的


// practice 13
void enter_arr(double arr[][5], int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			scanf_s("%lf", &arr[i][j]);
			getchar();
		}
	}
	return;
}
double cal_avg_1d(double arr[], int cols)
{
	double sum = 0.0;
	for (size_t i = 0; i < cols; i++)
	{
		sum += arr[i];
	}
	
	return (sum / cols);
}
double cal_avg_2d(double arr[][5], int rows)
{
	double sum = 0.0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			sum += arr[i][j];
		}
	}
	return (sum / (5 * rows));
}
double arr_max_element(double arr[][5], int rows)
{
	double max = 0.0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}
void print_double_2d(double arr[][5], int rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			printf("%lf ", arr[i][j]);
		}
		printf("\n");
	}
	return;
}
void p10_13(void)
{
	double arr[3][5];
	printf("Enter 15 double number:");
	enter_arr(arr, 3);
	for (size_t i = 0; i < 3; i++)
	{
		printf("average of row %d is %lf\n", i, cal_avg_1d(arr[i], 5));
	}
	printf("average of 15 double numbers is %lf\n", cal_avg_2d(arr, 3));
	printf("The max element of array is %lf\n", arr_max_element(arr, 3));

	return;
}


// practice 14
// vs2017不知道怎么设置变成数组，大概跟practice 13差不多





int main(int argc, char **argv)
{
	p10_13();

	while (getchar())
	{

	}

	return 0;
}