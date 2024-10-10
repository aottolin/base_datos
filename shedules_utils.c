#include "lib.h"

void	contract(t_empleado *e)
{
	bool	ok;
	bool	check;
	bool	ok2;
	int		m_hs;
	int		c_hs;
	int		result;

	ok = false;
	ok2 = false;
	check = false;
	while (!check)
	{
		while (!ok)
		{
			printf("Month to edit[Jan1-Dec12]:\n");
			if ((result = scanf("%d", &m_hs) == 1) && check_func(e->empresa, m_hs, 6) == 0)
			{
				result = 0;
				while (!ok2)
				{
					printf("Contract hs x month?\n");
					if ((result = scanf("%d", &c_hs) == 1) && check_func(e->empresa, c_hs, 2) == 0)
					{
						e->calendario->contract[m_hs - 1].hs = c_hs;
						ok = true;
						ok2 = true;
					}
					else if (result != 1)
					{
						printf(RED"Error input: Write[5]-[40]\n"RST);
						clear_input_buffer();
					}
				}
			}
			else if (result != 1)
			{
				printf(RED"Error input: Write[1]-[12]\n"RST);
				clear_input_buffer();
			}
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
		if ((result = scanf("%d", &in) == 1) && check_func(e->empresa,in, 5) == 0)
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
		if ((result = scanf("%d", &out) == 1) && check_func(e->empresa, out, 5) == 0)
		{
			e->calendario->fecha[day_posic].hora_salida = out;
			check2 = true;
		}
		else
			printf(RED"Wrong time [OUT] input\n"RST);
		clear_input_buffer();
	}
	e->calendario->fecha[day_posic].hs_hechas = out - in;
}

void	week_extras(t_empresa *e)
{
	int	i;
	int	week;
	int	day_posic;
	int	hs_week;
	int	month;
	t_empleado *em;
	

	week = 0;
	i = -1;
	while (++i < e->cantidad_empleados)
	{
		em = e->empleados + i;
		while (week < 52)
		{
			em->calendario->semanas[week].hs_semana = 0;
			week++;
		}
	}
	i = -1;
	week = 0;
	while (++i < e->cantidad_empleados)
	{
		em = e->empleados + i;
		while (week < 52)
		{
			hs_week = 0;
			day_posic = em->calendario->semanas[week].fecha_inicio - 1;
			while (day_posic < em->calendario->semanas[week].fecha_fin)
			{
				hs_week += em->calendario->fecha[day_posic].hs_hechas;
				printf("day%d week%d hs hechas:%d \n", day_posic, week, em->calendario->fecha[day_posic].hs_hechas);
				day_posic++;
			}
			em->calendario->semanas[week].hs_semana = hs_week;
			week++;
		}
	}
	i = -1;
	month = 0;
	while (++i < e->cantidad_empleados)
	{
		em = e->empleados + i;
		while (month < 12)
		{
			em->calendario->contract[month].hs = 20;
			month++;
		}
	}
	i = -1;
	week = 0;
	month = 0;
	while (++i < e->cantidad_empleados)
	{
		em = e->empleados + i;
		while (week < 52)
		{
			 em->calendario->semanas[week].hs_extras = em->calendario->semanas[week].hs_semana - em->calendario->contract[month].hs; 
			// printf("week%d hs extras:%d \n", week, em->calendario->semanas[week].hs_extras);
			week++;
		}
	}
}
