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
				get_bool(e);
				if (e->first_time == true)
				{
					printf(RED"[ERROR] >_The program is already INIT _ You can't do FIRST INIT again\n"RST);
					principal(e, 0);
				}
				else
				{
					init_empleados(e);
					write_file(e, 2);
				}
				check = true;
			}
			else if (value == 2)
			{
				get_bool(e);
				if (e->first_time == false)
				{
					printf(RED"[ERROR] >_First time INIT first _ You can't add new WORKERS if the system has 0 workers\n"RST);
					principal(e, 0);
				}
				else
				{
					init_new_employeed(e);
					write_file(e, 2);
				}
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
		principal(e, 0);
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
		bool	check;
		int	result;
		int	s;

		read_info = read_file(e);
		check = false;
		if (read_info != NULL)
		{
			while (!check)
			{
				printf("[1]CONTRACT HS - [2]INIT DATE\n");
				if ((result = scanf("%d", &s)) == 1 && s == 1 && check_func(read_info, s, 1) == 0)
					contract_hs(read_info);
				else if (result == 1 && s == 2 && check_func(read_info, s, 1) == 0)
					init_dates(read_info);
				else if (s == 0)
				{
					check = true;
					principal(read_info, 0);
					return ;
				}
				else if (s == -1)
				{
					check = true;
					principal(read_info, -1);
					return ;
				}
				else if (result != 1)
				{
					printf(RED"Error input: Write[1]-[2]\n"RST);
					clear_input_buffer();
				}
				else
				{
					printf(RED"Error input: Write[1]-[2]\n"RST);
					clear_input_buffer();
				}
			}
			write_file(e, 2);
		}
		else
			printf(RED"Error reading file in module 4\n"RST);
	}
	if (modulee == 5)
	{
		int	id_e;
		int	i;
		int	result;
		bool	check;
		t_empresa *datos_cargados = read_file(e);
		t_empleado *em;

		check = false;
		i = 0;
		if (datos_cargados != NULL)
		{
			printf("DELETE WORKER NUMBER>>");
			while (i < datos_cargados->cantidad_empleados)
			{
				em = datos_cargados->empleados + i;
				printf(" [%d]%s", em->id, em->nombre);
				i++;
			}
			printf("\n");
			while (!check)
			{
				if ((result = scanf("%d", &id_e) == 1) && check_func(datos_cargados, id_e, 1) == 0 && check_func(datos_cargados, id_e, 4) == 0)
				{
					int	x;
					bool work_finded = false;
					t_empleado *worker;
					
					x = 0;
					while (!work_finded)
					{
						worker = datos_cargados->empleados + x;
						if (worker->id == id_e)
						{
							while (x < datos_cargados->cantidad_empleados)
							{
								datos_cargados->empleados[x] = datos_cargados->empleados[x + 1];
								datos_cargados->empleados[x].id = datos_cargados->empleados[x - 1].id + 1;
								x++;
								work_finded = true;
							}
							datos_cargados->cantidad_empleados--;
							check = true;
						}	
						else
							x++;
					}
					write_file(e, 2);
				}
				else if (result != 1)
				{
					printf(RED"Error input.. Write a correct worker [NUMBER]\n"RST);
					clear_input_buffer();
				}
			}
		}
		else
			printf(RED"Error reading file in module 5\n"RST);
	}
}
