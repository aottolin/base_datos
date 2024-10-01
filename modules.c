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
		t_empresa *datos_cargados = read_file();

		if (datos_cargados != NULL)
		{
			printf("Nombre: %s\n", e->empleados[0].nombre);
			printf("Nombre: %s\n", e->empleados[1].nombre);
			printf("Nombre: %d\n", e->empleados[0].id);
			printf("Nombre: %d\n", e->empleados[1].id);
		}
	}
}
