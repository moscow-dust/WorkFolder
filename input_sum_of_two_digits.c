#include <stdio.h>
#include <stdlib.h>
#include "lab12.h"

int main(int ac,char **av)
{
	int *buf, sum =0;
	FILE * f;
	int i;
	if (ac != 2)
	{
		printf("Usage: ./a.out filename");
		return 1;
	}
	f = fopen(av[1], "r");
    if(f == NULL)
	{
		printf("There is not such file");
		return 1;
	}
	while(!feof(f))
	{
		int i, sum, flag = 0;
		int tmp1;
		t_number number1;
		int lenght_of_array_of_structures;
		int tmp;
		int counter = 1;

		if(fscanf(f, "%d", &(number1.number))==1)
		{
		tmp = number1.number;
		tmp = tmp/10;
		while(tmp!=0)
		{
			tmp = tmp/10;
			counter++;
		}
		lenght_of_array_of_structures=counter/2;
		if(counter%2!=0)
		{
			lenght_of_array_of_structures += 1;
		}
		number1.dig_arr = (t_digits *)calloc(lenght_of_array_of_structures, sizeof(t_digits));
		tmp1 = number1.number;
		i = lenght_of_array_of_structures - 1;
		if(counter%2!=0)
		{
			number1.dig_arr[i].first = tmp1%10;
			number1.dig_arr[i].second = 3;
			flag = 1;
			i--;
			tmp1 = tmp1/10;
		}
		while(i >= 0)
		{
			number1.dig_arr[i].second  = tmp1 % 10;
			tmp1 = tmp1/10;
			number1.dig_arr[i].first = tmp1 %10;
			tmp1 = tmp1 / 10;
			i--;
		}
		for (i = 0; i < (lenght_of_array_of_structures-1); i++)
		{
			sum = 0;
			sum = number1.dig_arr[i].first+number1.dig_arr[i].second;
			if(sum<10)
			{
				printf("%d%d%d", number1.dig_arr[i].first,  number1.dig_arr[i].second, sum);
			}
			else
			{
				printf("%d%d", number1.dig_arr[i].first,  number1.dig_arr[i].second);
			}
		}
		sum = number1.dig_arr[i].first+number1.dig_arr[i].second;
		if(flag == 1 && (sum!=number1.dig_arr[i].first))
		{
			printf("%d", number1.dig_arr[i].first);
		}
		else
			if(sum<10)
			{
				printf("%d%d%d", number1.dig_arr[i].first,  number1.dig_arr[i].second, sum);
			}
			else
			{
				printf("%d%d", number1.dig_arr[i].first,  number1.dig_arr[i].second);
			}
		
		printf("\n");
		}
	}
	return 0;
}
