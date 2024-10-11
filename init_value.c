#include "lib.h"

void	init_value(t_empresa *e)
{
	int	x = -1;
	while (++x < 366)
	{	
		e->empleados->calendario->fecha[x].hora_entrada = 0;
		e->empleados->calendario->fecha[x].hora_salida = 0;
		e->empleados->calendario->fecha[x].hs_hechas = 0;
	}
}
