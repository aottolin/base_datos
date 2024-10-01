#include "lib.h"

void	modules(t_empresa *e, int x)
{
	if (x == 1)
	{
		init_empleados(e);
		write_file(e, 1);
	}
	if (x == 4)
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
