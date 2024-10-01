#include "lib.h"

void	init_calendario(t_empresa *e)
{
	int fecha_compacta;
	int	dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	x;
	int	dia;
	int mes;
	char	fecha_comp[5];

	x = 0;
	dia = 1;
	mes = 0;

	e->empleados->calendario = malloc(sizeof(e->empleados->calendario) * 20);
	while (mes < 12)
	{
		while (dia <= dias_por_mes[mes])
		{
			sprintf(fecha_comp, "%02d%02d", dia, mes + 1);
			fecha_compacta = atoi(fecha_comp);
			e->empleados->calendario->fecha[x].dia = fecha_compacta;	
			//printf("%d\n", e->empleados->calendario->fecha[x].dia);
			dia++;
			x++;
		}
		mes++;
		dia = 1;
	}
}

void	init_primeros_empleados(t_empresa *e)
{
	int	i;
	int resultado;
	int	scan_id_empleado;
	bool	correct;
	t_empleado *empleado;
	
	e->empleados = fc_malloc(sizeof(t_empleado) * e->cantidad_empleados);
	i = -1;
	correct = false;
	while (!correct)
	{
		printf("Cantidad de empleados\n");
		resultado = scanf("%d", &e->cantidad_empleados);
		if (resultado == 1 && check_errors_nbr(e->cantidad_empleados) == 0)
			correct = true;
		else
			printf(RED"Escribe un numero del 1 al 100\n"RST);
		fflush(stdin);
	}
	correct = false;
	resultado = 0;
	while (++i < e->cantidad_empleados)
	{
		empleado = e->empleados + i;
		while (!correct)
		{
			printf("numero empleado\n");
			resultado = scanf("%d", &scan_id_empleado);
			if (resultado == 1 && check_errors_nbr(scan_id_empleado) == 0)
			{
				empleado->id = scan_id_empleado;
				correct = true;
			}
			else
				printf(RED"Escribe un numero del 1 al 100\n"RST);
			fflush(stdin);
		}
		printf("nombre empleado\n");
		fgets(empleado->nombre, sizeof(empleado->nombre), stdin);
		empleado->empresa = e;
		e->contador = 1;
		correct = false;
	}
}

/*void	agregar_empleados(t_empresa *e)
{


}
*/

void	init_empleados(t_empresa *e)
{
	if (e->contador == 0)
	{	
		init_primeros_empleados(e);
	}
	/*else
		agregar_empleado(e);
*/
}
