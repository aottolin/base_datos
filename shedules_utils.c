#include "lib.h"

void	contract(t_empleado *e)
{
	bool	ok;
	bool	check;
	int		m_hs;
	int		c_hs;
	int		result;

	ok = false;
	check = false;
	while (!check)
	{
		while (!ok)
		{
			printf("Month to edit[Jan1-Dec12]:\n");
			result = scanf("%d", &m_hs);
			if (result == 1 && check_contract(m_hs, 1) == 0)
			{
				result = 0;
				printf("Contract hs x month?\n");
				result = scanf("%d", &c_hs);
				if (result == 1 && check_contract(c_hs, 2) == 0)
				{
					e->calendario->contract[m_hs - 1].hs = c_hs;
					ok = true;
				}
				else
					printf(RED"Error input write [5]-[40]\n"RST);
			}
			else
				printf(RED"Error input write [1]-[12]\n"RST);
		}
		check = true;
	}
}

void	in_out(t_empleado *e, int day_posic)
{
	bool	check2;
	int	in;
	int	out;
	int	result;

	check2 = false;
	
	while (!check2)
	{
		printf("	IN time:\n");
		result = scanf("%d", &in);
		if (result == 1 && check_time(in) == 0)
		{
			e->calendario->fecha[day_posic].hora_entrada = in;
			check2 = true;
		}
		else
			printf(RED"Wrong time [IN] input\n"RST);
		clear_input_buffer();
	}
	check2 = false;
	while (!check2)
	{
		result = 0;
		printf("	OUT time:\n");
		result = scanf("%d", &out);
		if (result == 1 && check_time(out) == 0)
		{
			e->calendario->fecha[day_posic].hora_salida = out;
			check2 = true;
		}
		else
			printf(RED"Wrong time [OUT] input\n"RST);
		clear_input_buffer();
	}
}

int	get_date(int day, int month)
{
	int date;
	int	x;
	int day_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	x = 0;
	date = 0;
	while (x < month - 1)
		date += day_month[x++];
	date += day - 1;
	return (date);
}

int	date_id(int date)
{
	int	day;
	int	month;
	int day_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	date_posicion;

	day = date / 100;
	month = date % 100;
	if (month < 1 || month > 12 || day < 1 || day > day_month[month - 1])
	{
		printf(RED"Wrong date input\n"RST);
		return -1;
	}
	date_posicion = get_date(day, month);
	return (date_posicion);
}

