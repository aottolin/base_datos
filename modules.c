#include "lib.h"

void	modules(t_empresa *e, int x)
{
	if (x == 1)
	{
		int	value;

		value = 0;
		printf("	(1) First time init or (2) Add new worker");
		while (value == 0)
		{
			scanf("%d", &value);
			fflush(stdin);
		
			if (value == 1)
			{
				printf(G"Init first workers\n"RST);
				init_empleados(e);
				write_file(e, 1);
			}
			else if (value == 2)
			{
				printf(G"	Add new worker\n"RST);
				init_new_employeed(e);
				write_file(e, 1);
			}
			else
				printf(RED"Write 1 or 2\n");
		}
	}
	if (x == 3)
	{
		t_empresa *datos_cargados = read_file(e);

		//printf("el prog llega aqui\n");
		if (datos_cargados != NULL)
		{
			int i = -1;

			printf("Cantidad empleados: %d\n", e->cantidad_empleados);
			while (++i < e->cantidad_empleados)
			{
				printf("Nombre: %s\n", datos_cargados->empleados[i].nombre);
				printf("Numero: %d\n", datos_cargados->empleados[i].id);
			}
		}
	}
}
