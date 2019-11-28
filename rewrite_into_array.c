#include <stdio.h>
#include <stdlib.h>

int main(int ac,char **av)
{
	int *buf,res, sum =0;
	FILE * f;
	char c;
	int count_numb = 0;

	buf = (int *)malloc(sizeof(int) * 2);
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
	fseek(f,0,SEEK_END);
	long pos=ftell(f);
	if(pos<=0)
	{
		printf("There is not symbols in file");
		return 1;
	}
	fseek(f,0,SEEK_SET);
	while (!feof(f))
	{
		int r_flag = -1;
		r_flag = fscanf(f, "%d", &res);
		if (r_flag == 0)
		{
			fscanf(f, "%c", &c);
			continue ;
		}
		else if (r_flag == 1)
		{
			if (count_numb == 0)
			{
				buf[0] = res;
				count_numb++;
			}
			else
			{
				if (count_numb > 1)
				{
					buf[0] = buf[1];
					buf[1] = res;
				}
				else
				{
					buf[1] = res;
					count_numb++;
				}
			}
		}
	}
	if(count_numb==0 || count_numb ==1)
	{
		printf("There are not numbers or only one number");
		return 1;
	}

	printf("%d\n%d ", buf[0],buf[1]);
	res = buf[0]/10;
	sum = buf[0]%10;
	while(res!=0)
	{
		sum = res%10+sum;
		res = res/10;
	}
	printf("sum of digits: %d\n", sum);
return 0;

}

	
