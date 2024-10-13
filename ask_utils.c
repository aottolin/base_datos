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
	conv_to = date_id(date_to) + 1;
	while (week < 62)
	{
		week_start = e->empleados->calendario->semanas[week].fecha_inicio;
		week_finish = e->empleados->calendario->semanas[week].fecha_fin;
		if ((week_start >= conv_from && week_start <= conv_to) || (week_finish >= conv_from && week_finish <= conv_to) || (conv_from >= week_start && conv_to <= week_finish))
		{
			while (++i < e->cantidad_empleados)
			{
				em = e->empleados + i;
				printf("Week[%d] from[%02d]to[%02d] Worker:%s Hs_extras %.2f\n", week + 1, em->calendario->semanas[week].date_start, em->calendario->semanas[week].date_fin, em->nombre, em->calendario->semanas[week].hs_extras);
			}
			printf("\n");
		}
		week++;
	}
}

void	ask_by_month(t_empresa *e)
{

	int	month[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int	i;
	int	month_from;
	int month_to;
	int week;
	int	month_start;
	int	month_fin;
	t_empleado *em;
	

	i = -1;
	week = 0;
	printf("From[MM]\n");
	scanf("%d", &month_from);
	printf("To[MM]\n");
	scanf("%d", &month_to);
	month_from = month[month_from - 1];
	month_to = month[month_to - 1];

	while (week < 62)
	{
		month_start = e->empleados->calendario->semanas[week].month;
		month_fin = e->empleados->calendario->semanas[week].month;
		if ((month_start >= month_from && month_start <= month_to) || (month_fin >= month_from && month_fin <= month_to) || (month_from >= month_start && month_to <= month_fin))
		{
			while (++i < e->cantidad_empleados)
			{
				em = e->empleados + i;
				printf("Week[%d] from[%02d]to[%02d] Month[%d] Worker:%s Hs_extras %.2f\n", week + 1, em->calendario->semanas[week].date_start, em->calendario->semanas[week].date_fin, em->calendario->semanas[week].month + 1, em->nombre, em->calendario->semanas[week].hs_extras);
			}
			printf("\n");
		}
		week++;
		i = -1;
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
				printf("[%d]%s >> %.2f to %.2f HsTotal >>%.2f\n", e->empleados[i].id, e->empleados[i].nombre, e->empleados[i].calendario->fecha[day_p].hora_entrada, e->empleados[i].calendario->fecha[day_p].hora_salida, e->empleados[i].calendario->fecha[day_p].hs_hechas);
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

