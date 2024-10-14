#include "lib.h"

void	consult_worker(t_empresa *e)
{
	t_empresa *datos_cargados = read_file(e);
	t_empleado *read_employee;
	int	i;

	i = 0;
	
	if (datos_cargados != NULL)
	{	
		while (i < datos_cargados->cantidad_empleados)
		{
			read_employee = datos_cargados->empleados + i;
			printf(" [%d]%s", read_employee->id, read_employee->nombre);
			i++;
		}
		printf("\n");
	}
}

void	consult_in_out(t_empresa *e)
{
	t_empresa *datos_cargados = read_file(e);
	t_empleado *read_employee;
	int	i;
	int	result;
	int	askby;
	int	inout_e;
	bool	check;
	bool	ok;

	i = 0;
	check = false;
	ok = false;
	
	if (datos_cargados != NULL)
	{
		while (!check)
		{
			printf("ASK BY DATE OR WORKER_\n[1]DATE\n[2]WORKER\n");
			if ((result = scanf("%d", &askby) == 1) && askby == 1)
			{
				in_out_date(datos_cargados);
				return ;
			}
			else if (result == 1 && askby == 2)
			{
				printf("WRITE WORKER NUMBER>>");
				while (i < datos_cargados->cantidad_empleados)
				{
					read_employee = datos_cargados->empleados + i;
					printf(" [%d]%s", read_employee->id, read_employee->nombre);
					i++;
				}
				printf("\n");
				result = 0;
				while(!ok)
				{
					if ((result = scanf("%d", &inout_e) == 1) && check_func(datos_cargados, inout_e, 4) == 0)
					{
						//in_out_date_emp(datos_cargados, in_out_e);
						return;
					}
					else if ((result != 1) || check_func(datos_cargados, inout_e, 4 == 0))
					{
						printf(RED">_Wrong input or non-existent worker\n"RST);
						printf("WRITE WORKER NUMBER>>\n");
						clear_input_buffer();
					}
				}
			}
			else if (askby == 0)
			{
				check = true;
				module_3(datos_cargados, -1);
			}
			else if (askby == -1)
			{
				check = true;
				principal(datos_cargados, -1);
			}
			else if ((result != 1) || (askby != 1 && askby != 2))
			{
				printf(RED">_Wrong input, Write>>[1or2]\n"RST);
				clear_input_buffer();
			}
		}
	}
}

void	consult_extra(t_empresa *e)
{
	bool	check;
	int		result;
	int		m;

	check = false;
	while (!check)
	{
		printf("EXTRAS BY_\n[1]WEEK\n[2]MONTH\n");
		if ((result = scanf("%d", &m) == 1) && m == 1)
		{
			ask_by_week(e);
			check = true;
		}
		else if (result == 1 && m == 2)
		{
			ask_by_month(e);
			check = true;
		}
		else if (m == 0)
		{
			check = true;
			module_3(e, 0);
		}
		else if (m == -1)
		{
			check = true;
			principal(e, -1);
		}
		else if (result == 1)
		{
			printf(RED">_Wrong input, Write [1-2]\n"RST);
			clear_input_buffer();
		}
		else if (result != 1)
		{
			printf(RED">_Wrong input, Write [1-2]\n"RST);
			clear_input_buffer();
		}
	}
}

