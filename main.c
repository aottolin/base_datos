#include "lib.h"

int	main(void)
{
	int modulo;
	bool	check;

	presentacion_programa();
	t_empresa *e;

	e = fc_malloc(sizeof(t_empresa));
	
	check = false;
	while (!check)
	{
		printf("1-Inicializar programa primera vez\n");
		printf("2-Agregar un empleado\n");
		printf("3-Cargar horarios\n");
		printf("4-Inicializar modulo de consulta\n");
		scanf("%d", &modulo);
		fflush(stdin);
		if (modulo == 1)
		{
			modules(e, 1);
			check = true;
		}	
		else if (modulo == 2)
		{
			modules(e, 2);
		}
		else if (modulo == 3)
		{
			printf("modulo 3");
		}
		else if (modulo == 4)
		{
			modules(e, 4);
		}
		else
			printf(RED"La respuesta debe ser 1, 2, 3 o 4\n"RST);
	}
	//init_calendario(e);
	return (0);
}
