#include "lib.h"

void	modules(t_empresa *e, int modulee)
{
	if (modulee == 1)
	{
		bool	check;
		int	value;

		value = 0;
		check = false;
		printf("(1) First time init or (2) Add new worker\n");
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
			else
				printf(RED"Write 1 or 2\n"RST);
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
			bool	check;
			int		result;
			int		m;

			check = false;
			while (!check)
			{
				printf("What do you want to ask [1]Extra_hs [2]In_out [3]Workers\n");
				if ((result = scanf("%d", &m) == 1) && m == 1)
				{
					//consult_extras(read_file); 
					check = true;
				}
				else if (result == 1 && m == 2)
				{
					consult_in_out(datos_cargados);
					printf(G"Entering..[2]In_Out\n"RST);
					check = true;

				}
				else if (result == 1 && m == 3)
				{
					consult_worker(datos_cargados); 
					check = true;

				}
				else if (result != 1)
				{
					printf(RED"Wrong input, Write [1-3]\n"RST);
					clear_input_buffer();
				}
			}
		}
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
			printf("Add contract hours to:");
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

/*
			while (++i < e->cantidad_empleados && x < 277)
			{
				printf("Nombre: %s\n", datos_cargados->empleados[i].nombre);
				printf("Numero: %d\n", datos_cargados->empleados[i].id);
				printf("fecha: %d ", datos_cargados->empleados[i].calendario->fecha[x].dia );
				printf("hora_entrada:%d ", datos_cargados->empleados[i].calendario->fecha[x].hora_entrada);
				printf("hora_salida:%d\n", datos_cargados->empleados[i].calendario->fecha[x].hora_salida);
				x++;
			}
		}
			//printf("Primera fecha del ano:%d\n", datos_cargados->empleados[i].calendario->fecha[0].dia);
			//printf("ultima fecha del ano:%d\n", datos_cargados->empleados[i].calendario->fecha[364].dia);
	}
}
*/
