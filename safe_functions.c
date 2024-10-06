#include "lib.h"

void	*fc_malloc(size_t bytes)
{
	void	*ret;
	ret = malloc(bytes);
	if (!ret)
		printf("malloc error");
	return (ret);
}

int	check_idem_2(t_empresa *e, int value)
{
	int	i;

	i = -1;
	while (i < e->cantidad_empleados)
		if (e->empleados[i].id != value)
			i++;
		else
			return (0);
	printf(RED"Employee number[%d] non exist\n"RST, value);
	return -1;
}

int	check_time(int value)
{
	if (value >= 0 && value <= 24)
		return (0);
	return (-1);
}

int	check_date(int date)
{
	int	day;
	int	month;
	int day_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	day = date / 100;
	month = date % 100;
	if (month < 1 || month > 12 || day < 1 || day > day_month[month - 1])
	{
		printf(RED"Wrong date input[DDMM]\n"RST);
		return -1;
	}
	return (0);
} 

int	check_idem(t_empresa *e, int value)
{
	int	i;

	i = -1;

	while (++i < e->cantidad_empleados) 
		if (e->empleados[i].id == value)
		{
			printf(RED"Employee number[%d] already exist\n"RST, value);
			return (-1);
		}
	return 0;
}

int	check_str(char *str)
{
	int	x;
	int	size;

	x = 0;
	size = strlen(str);

	while (str[x] >= 'a' && str[x] <= 'z')
		x++;
	if (size == x)
		return 0;
	else
		return -1;
}

int check_errors_nbr(int nbr)
{
	if (nbr >= 1 && nbr <= 20)
		return 0;
	printf(RED"Write a number from 1 to 20\n"RST);
	return -1;
}

void clear_input_buffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)			{ }
}
