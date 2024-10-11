#include "lib.h"

void	ask_by_week(t_empresa *e)
{
	int	week;
	int	date_from;
	int	date_to;
	int	conv_from;
	int	conv_to;
	int	i;
	int	week_start;
	int	week_finish;
	t_empleado *em;

	i = -1;
	week = 0;
	printf("From[DDMM]\n");
	scanf("%d", &date_from);
	printf("To[DDMM]\n");
	scanf("%d", &date_to);
	
	conv_from = date_id(date_from) + 1;
	printf("conv from%d\n", conv_from);
	conv_to = date_id(date_to) + 1;
	printf("conv to%d\n", conv_to);
	
	while (week < 62)
	{
		//printf("week%d\n", week);
		week_start = e->empleados->calendario->semanas[week].fecha_inicio;
		//printf("week_s%d\n", e->empleados->calendario->semanas[week].fecha_inicio);
		week_finish = e->empleados->calendario->semanas[week].fecha_fin;
		//printf("week_f%d\n", e->empleados->calendario->semanas[week].fecha_fin);
	
		if ((week_start >= conv_from && week_start <= conv_to) || (week_finish >= conv_from && week_finish <= conv_to) || (conv_from >= week_start && conv_to <= week_finish))
		{
			while (++i < e->cantidad_empleados)
			{
				em = e->empleados + i;
				printf("Week[%d] from[%d]to[%d] Worker:%s Hs_extras %d\n", week + 1, em->calendario->semanas[week].fecha_inicio, em->calendario->semanas[week].fecha_fin, em->nombre, em->calendario->semanas[week].hs_extras);
			}
			printf("\n");
		}
		week++;
	}
}

void	in_out_date(t_empresa *e)
{
	bool	check;
	int	date;
	int	day_p;
	int	i;
	int	result;

	i = 0;
	check = false;
	while (!check)
	{
		printf("	DATE[DDMM]:\n");
		if ((result = scanf("%d", &date) == 1) && check_date(date) == 0)
		{
			day_p = date_id(date);
			while (i < e->cantidad_empleados)
			{
				printf("[%d]%s >> %d to %d HsTotal >>%d\n", e->empleados[i].id, e->empleados[i].nombre, e->empleados[i].calendario->fecha[day_p].hora_entrada, e->empleados[i].calendario->fecha[day_p].hora_salida, e->empleados[i].calendario->fecha[day_p].hs_hechas);
			i++;
			}
			check = true;
		}
		else if (result != 1)
		{
			printf(RED">_Wrong date input[DDMM]\n"RST);		
			clear_input_buffer();
		}
	}
}
/*
void	in_out_date_emp(t_empresa *e, int in_out_e)
{



}
*/

