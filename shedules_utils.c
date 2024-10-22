#include "lib.h"

void	init_dates_utils(t_empleado *e)
{
	bool	check;
	int		in_d;
	int		result;
	t_empresa *empresas;

	empresas = e->empresa;
	check = false;
	while (!check)
	{
		printf("INIT DATE_\n");
		if ((result = scanf("%d", &in_d) == 1) && check_date(in_d) == 0)
		{
			e->init_date = in_d;	
			check = true;
		}
		else if (in_d == 0)
		{
			check = true;
			principal(empresas, 0);
		}
		else if (in_d == -1)
		{
			check = true;
			principal(empresas, -1);
		}
		else
		{
			printf(RED"Error input\n"RST);
			clear_input_buffer();
		}
	}
}

void	init_dates(t_empresa *read_info)
{
	int			i;
	t_empleado	*edit_e;
	bool		check;
	int			id_e;
	bool		ok;
	int			result;

	i = 0;
	printf("ADD INIT DATE TO_\n");
	while (i < read_info->cantidad_empleados)
	{
		edit_e = read_info->empleados + i;
		printf(" [%d]%s", edit_e->id, edit_e->nombre);
		i++;
	}
	printf("\n");
	i = 0;
	ok = false;
	check = false;
	while (!check)
	{
		if ((result = scanf("%d", &id_e) == 1) && id_e != -1 && id_e != 0 && check_func(read_info, id_e, 1) == 0 && check_func(read_info, id_e, 4) == 0)
		{
			while (i < read_info->cantidad_empleados && ok == false)
			{
				edit_e = read_info->empleados + i;
				if (edit_e->id != id_e)
					i++;
				else
				{
					init_dates_utils(edit_e);
					check = true;
					ok = true;
				}
			}				
		}
		else if (id_e == 0)
		{
			check = true;
			principal(read_info, 0);
		}
		else if (id_e == -1)
		{
			check = true;
			principal(read_info, -1);
		}
		else
		{
			printf(RED"Error input\n"RST);
			clear_input_buffer();
		}
	}
}

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

void	contract_hs(t_empresa *read_info)
{
	t_empleado	*edit_e;
	bool	check;
	int		id_e;
	int			i;
	int	result;
	bool	ok;

	i = 0;
	check = false;
	ok = false;
	printf("ADD CONTRACT HOURS TO_");
	while (i < read_info->cantidad_empleados)
	{
		edit_e = read_info->empleados + i;
		printf(" [%d]%s", edit_e->id, edit_e->nombre);
		i++;
	}
	printf("\n");
	i = 0;

	while (!check)
	{
		if ((result = scanf("%d", &id_e) == 1) && check_func(read_info, id_e, 1) == 0 && check_func(read_info, id_e, 4) == 0)
		{
			while (i < read_info->cantidad_empleados && ok == false)
			{
				edit_e = read_info->empleados + i;
				if (edit_e->id != id_e)
					i++;
				else
					contract(edit_e);
			}					
		}
	}
}

void	in_out(t_empleado *e, int day_posic)
{
	bool	check2;
	float	in;
	float	out;
	int	result;

	check2 = false;

	while (!check2)
	{
		printf("	IN time:\n");
		if ((result = scanf("%f", &in) == 1) && check_func(e->empresa,in, 5) == 0)
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
		if ((result = scanf("%f", &out) == 1) && check_func(e->empresa, out, 5) == 0)
		{
			e->calendario->fecha[day_posic].hora_salida = out;
			check2 = true;
		}
		else
			printf(RED"Wrong time [OUT] input\n"RST);
		clear_input_buffer();
	}

	if (out >= 7 && out <= 24)
		e->calendario->fecha[day_posic].hs_hechas = out - in;
	else
	{
		if (out == 01)
			e->calendario->fecha[day_posic].hs_hechas = 25 - in;
		if (out == 01.5)
			e->calendario->fecha[day_posic].hs_hechas = 25.5 - in;
		if (out == 02)
			e->calendario->fecha[day_posic].hs_hechas = 26 - in;
		if (out == 02.5)
			e->calendario->fecha[day_posic].hs_hechas = 26.5 - in;
		if (out == 03)
			e->calendario->fecha[day_posic].hs_hechas = 27 - in;
		if (out == 03.5)
			e->calendario->fecha[day_posic].hs_hechas = 27.5 - in;
		if (out == 04)
			e->calendario->fecha[day_posic].hs_hechas = 28 - in;
		if (out == 04.5)
			e->calendario->fecha[day_posic].hs_hechas = 28.5 - in;
		if (out == 05)
			e->calendario->fecha[day_posic].hs_hechas = 29 - in;
		if (out == 05.5)
			e->calendario->fecha[day_posic].hs_hechas = 29.5 - in;
		if (out == 06)
			e->calendario->fecha[day_posic].hs_hechas = 30 - in;
		if (out == 06.5)
			e->calendario->fecha[day_posic].hs_hechas = 30.5 - in;
	}
}

void	in_out_split(t_empleado *e, int day_posic)
{
	bool	check2;
	bool	check3;
	float	in;
	float	in2;
	float	out;
	float	out2;
	float hs_hechas1;
	float hs_hechas2;
	int	result;
	int	result2;

	check2 = false;
	check3 = false;
	hs_hechas1 = 0;
	hs_hechas2 = 0;
	while (!check2)
	{
		printf("	IN[1] time:\n");
		if ((result = scanf("%f", &in) == 1) && check_func(e->empresa,in, 5) == 0)
		{
			e->calendario->fecha[day_posic].hora_entrada = in;
			check2 = true;
		}
		else
			printf(RED"Wrong time [IN] input\n"RST);
		clear_input_buffer();
	}
	while (!check3)
	{
		result = 0;
		printf("	OUT[1] time:\n");
		if ((result = scanf("%f", &out) == 1) && check_func(e->empresa, out, 5) == 0)
		{
			e->calendario->fecha[day_posic].hora_salida = out;
			check3 = true;
		}
		else
			printf(RED"Wrong time [OUT] input\n"RST);
		clear_input_buffer();
	}
	check2 = false;
	check3 = false;
	while (!check2)
	{
		printf("	IN[2] time:\n");
		if ((result2 = scanf("%f", &in2) == 1) && check_func(e->empresa, in2, 5) == 0)
		{
			e->calendario->fecha[day_posic].hora_entrada2 = in2;
			check2 = true;
		}
		else
			printf(RED"Wrong time [IN2] input\n"RST);
		clear_input_buffer();
	}
	while (!check3)
	{
		result2 = 0;
		printf("	OUT[2] time:\n");
		if ((result = scanf("%f", &out2) == 1) && check_func(e->empresa, out2, 5) == 0)
		{
			e->calendario->fecha[day_posic].hora_salida2 = out2;
			check3 = true;
		}
		else
			printf(RED"Wrong time [OUT2] input\n"RST);
		clear_input_buffer();
	}
	hs_hechas1 = out - in;	

	if (out2 >= 7 && out2 <= 24)
		hs_hechas2 = out2 - in2;
	else
	{
		if (out2 == 01)	
			hs_hechas2 = 25 - in2;
		if (out2 == 01.5)	
			hs_hechas2 = 25.5 - in2;
		if (out2 == 02)
			hs_hechas2 = 26 - in2;
		if (out2 == 02.5)	
			hs_hechas2 = 26.5 - in2;
		if (out2 == 03)
			hs_hechas2 = 27 - in2;
		if (out2 == 03.5)	
			hs_hechas2 = 27.5 - in2;
		if (out2 == 04)
			hs_hechas2 = 28 - in2;
		if (out2 == 04.5)	
			hs_hechas2 = 28.5 - in2;
		if (out2 == 05)
			hs_hechas2 = 29 - in2;
		if (out2 == 05.5)	
			hs_hechas2 = 29.5 - in2;
		if (out2 == 06)
			hs_hechas2 = 30 - in2;
		if (out2 == 06.5)
			hs_hechas2 = 30.5 - in2;
	}
	e->calendario->fecha[day_posic].hs_hechas = hs_hechas1 + hs_hechas2;
}
