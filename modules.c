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
				printf(RED"Write 1 or 2\n");
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
			int i = -1;

			printf("Cantidad empleados: %d\n", e->cantidad_empleados);
			while (++i < e->cantidad_empleados)
			{
				printf("Nombre: %s\n", datos_cargados->empleados[i].nombre);
				printf("Numero: %d\n", datos_cargados->empleados[i].id);
				printf("Primera fecha del ano:%d\n", datos_cargados->empleados[i].calendario->fecha[0].dia);
				printf("ultima fecha del ano:%d\n", datos_cargados->empleados[i].calendario->fecha[364].dia);
			}
			printf("hora_entrada:%d\n", datos_cargados->empleados[0].calendario->fecha[0].hora_entrada);
			printf("hora_salida:%d\n", datos_cargados->empleados[0].calendario->fecha[0].hora_salida);
			printf("hora_entrada:%d\n", datos_cargados->empleados[1].calendario->fecha[0].hora_entrada);
			printf("hora_salida:%d\n", datos_cargados->empleados[1].calendario->fecha[0].hora_salida);
			printf("hora_entrada:%d\n", datos_cargados->empleados[0].calendario->fecha[1].hora_entrada);
			printf("hora_salida:%d\n", datos_cargados->empleados[0].calendario->fecha[1].hora_salida);
			printf("hora_entrada:%d\n", datos_cargados->empleados[1].calendario->fecha[1].hora_entrada);
		//	printf("hora_entrada:%d\n", datos_cargados->empleados[1].calendario->contract[9].hs);
		}
	}
}
