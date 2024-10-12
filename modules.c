#include "lib.h"

void	module_3(t_empresa *datos_cargados, int value)
{	
	bool	check;
	int		result;
	int		m;
	
	if (value == -1)
		return ;
	check = false;
	while (!check)
	{
		printf("\n[1]WORKERS_DATA\n[2]IN_OUT_HOURS\n[3]EXTRA_HS\n");
		if ((result = scanf("%d", &m) == 1) && m == 3)
			consult_extra(datos_cargados); 
		else if (result == 1 && m == 2)
			consult_in_out(datos_cargados);
		else if (result == 1 && m == 1)
			consult_worker(datos_cargados); 
		else if (m == 0)
		{
			check = true;
			principal(datos_cargados, 0);
		}
		else if (m == -1)
		{
			check = true;
			principal(datos_cargados, -1);
		}
		else if (result == 1)
		{
			printf(RED">_Wrong input, Write [1-3]\n"RST);
			clear_input_buffer();
		}
		else if (result != 1)
		{
			printf(RED">_Wrong input, Write [1-3]\n"RST);
			clear_input_buffer();
		}
	}
}

void	modules(t_empresa *e, int modulee)
{
	if (modulee == 1)
	{
		bool	check;
		int	value;

		value = 0;
		check = false;
		printf(G">_SELECT:\n"RST);
		printf("[1]FIRST TIME INIT\n[2]ADD NEW WORKER\n");
		while (!check)
		{
			scanf("%d", &value);
			clear_input_buffer();
		
			if (value == 1)
			{
				init_empleados(e);
				write_file(e, 1);
				init_calendario(e);
				write_file(e, 2);
				check = true;
			}
			else if (value == 2)
			{
				init_new_employeed(e);
				write_file(e, 1);
				init_calendario(e);
				write_file(e, 2);
				check = true;
			}
			else if (value == 0)
			{
				check = true;
				principal(e, 0);
			}
			else if (value == -1)
			{
				check = true;
				principal(e, -1);
			}
			else
				printf(RED">_Write 1 or 2\n"RST);
		}
	}

	if (modulee == 2)
	{
		edit_shedules(e);
		write_file(e, 2);
	}

	if (modulee == 3)
	{
		t_empresa *datos_cargados = read_file(e);

		if (datos_cargados != NULL)
		{
			module_3(datos_cargados, 0);
		}
		else
			printf(RED"Error reading file in module 3\n"RST);
	}
	if (modulee == 4)
	{
		t_empresa	*read_info;
		t_empleado	*edit_e;
		bool	check;
		int		id_e;
		int			i;
		int	result;
		bool	ok;
		
		ok = false;
		read_info = read_file(e);
		check = false;
		i = 0;
		if (read_info != NULL)
		{
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
						edit_e = e->empleados + i;
						if (edit_e->id != id_e)
							i++;
						else
							contract(edit_e);
					}					
				}
			}
			write_file(e, 2);
		}
	}
}
