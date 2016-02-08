	;#include <stdio.h>
	;#include <math.h>
	;#include <stdlib.h>
	;
	;void calculate_e()
	;{
	;	int a;
	;	float b, c, e, z;
	;	a = 1;
	;	b = 1;
	;	c = 1;
	;	float y = 1.0;
	;	float e_6 = 2.718281;
	;	float prec = 0.00001;
	;	
	;	while (a <= 9)
	;	{
	;		printf("\n\nIteration number %d\n", a);
	;		c = c*a;
	;		z = b/c;
	;		a++;
	;		y=z+y;
	;		printf("Sum of fractions so far:	%f\n", y);
	;		printf("Actual value of e:		%f\n", e_6);
	;		e = e_6-y;
	;		printf("Difference:			%f\n", e);
	;		printf("Precision value:		%f\n", prec);
	;	}
	;}
	;
	;void average_nums()
	;	;{
	;	
	;}
	;
	;void matrix_mul()
	;{
	;	float matrix_1[4] = {0.4, 0.3, 0.2, 0.1};
	;	float matrix_2[4] = {0.6, 0.7, 0.8, 0.9};
	;	float temp_matrix[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	;	float end_matrix[4] = {0.0, 0.0, 0.0, 0.0};
	;	
	;	printf("Matrix One:\n%lf %lf\n%lf %lf\n\n", matrix_1[0], matrix_1[1], matrix_1[2], matrix_1[3]);
	;	
	;	printf("Matrix Two:\n%lf %lf\n%lf %lf\n\n", matrix_2[0], matrix_2[1], matrix_2[2], matrix_2[3]);
	;	
	;	int a_counter=0, b_counter=0, c_counter=0, d_counter=0, counter=0;
	;	
	;	while (counter < 4)
	;	{
	;		temp_matrix[c_counter] = matrix_1[a_counter] * matrix_2[b_counter];
	;		b_counter++;
	;		c_counter++;
	;		temp_matrix[c_counter] = matrix_1[a_counter] * matrix_2[b_counter];
	;		a_counter++;
	;		b_counter++;
	;		c_counter++;
	;		if (b_counter==2)
	;		{
	;			b_counter = 0;
	;		}
	;		counter++;
	;	}
	;	
	;	counter = 0;
	;	c_counter = 0;
	;	d_counter = 0;
	;	
	;	while (counter < 4)
	;	{
	;		end_matrix[d_counter] = temp_matrix[c_counter] + temp_matrix[c_counter+2];
	;		c_counter++;
	;		d_counter++;
	;		counter++;
	;		if (counter == 2)
	;		{
	;			c_counter = 4;
	;		}
	;	}
	;	
	;	printf("End Matrix:\n%lf %lf\n%lf %lf\n\n", end_matrix[0], end_matrix[1], end_matrix[2], end_matrix[3]);
	;}
	;
	;void freq_table()
	;{
	;	int freq_tab[27] = {0};
	;	char cm_str[7] = {"APP LE"};
	;	int counter = 6;
	;	printf("String:			%s\n", cm_str);
	;	int ft_counter = 0, thing = 0;
	;	float numletts = counter;
	;	float frq_val_max = 1/numletts;
	;	printf("Single letter frequency: %lf\n", frq_val_max);
	;	int start = 65;
	;	while (start > 64)
	;	{
	;		if (cm_str[ft_counter] == start)
	;		{
	;			printf("Letter: %c", cm_str[ft_counter]);
	;			freq_tab[thing] = freq_tab[thing] + frq_val_max;
	;		}
	;		ft_counter++;
	;		thing++;
	;		start++;
	;		if (start == 91)
	;			break;
	;	}
	;}
	;
	;int main()
	;{
	;	int sel;
	;	do {
	;	printf("Welcome to Isaac Stallcup's Program 5.\n");
	;	printf("Please select the function you wish to perform (1-4).\n");
	;	printf("1 Approximate e\t\t\t2 Average numbers\n3 Float matrx multiplication\t4 Frequency Table\n");
	;	scanf("%d", &sel);
	;	} while (sel > 5 && sel < 0);
	;	
	;	if (sel == 1)
	;	{
	;		calculate_e();
	;	}
	;	
	;	if (sel == 2)
	;	{
	;		average_nums();
	;	}
	;	
	;	if (sel == 3)
	;	{
	;		matrix_mul();
	;	}
	;	
	;	if (sel == 4)
	;	{
	;		freq_table();
	;	}
	;	
	;	return 0;
	;	
	;}
	;
	;
	;
	;
	;
	;
	;
	;
	;
	;