#include "lib.h"

void	*fc_malloc(size_t bytes)
{
	void	*ret;
	ret = malloc(bytes);
	if (!ret)
		printf("malloc error");
	return (ret);
}

int	check_func(t_empresa *e, float value, int m)
{
	if (m == 1) // check nbr;
	{
		if (value >= 1 && value <= 20)
			return 0;
		printf(RED"Write a number from 1 to 20\n"RST);
	}
	else if (m == 2)
	{
		if (value >= 5 && value <= 40)
			return (0);
		printf(RED"Error input write [5]-[40]\n"RST);
	}
	else if (m == 3) // check idem
	{
		int	i;

		i = -1;
		while (++i < e->cantidad_empleados)
		if (e->empleados[i].id == value)
		{
			printf(RED"Employee number[%.0f] already exist\n"RST, value);
			return (-1);
		}
		return 0;
	}
	else if (m == 4) // check idem 2
	{
		int	i;

		i = -1;
		while (i < e->cantidad_empleados)
			if (e->empleados[i].id != value)
				i++;
			else
				return (0);
		printf(RED"Employee number[%.0f] non exist\n"RST, value);
	}
	else if (m == 5) // check time
	{
		if (value >= 0 && value <= 24)
			return (0);
	}
	else if (m == 6) // check contract
	{
		if (value >= 1 && value <= 12)
			return (0);
		printf(RED"Error input write [1]-[12]\n"RST);
	}
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

void clear_input_buffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)			{ }
}
