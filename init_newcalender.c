#include "lib.h"

void	separe_newweeks(t_empresa *e)
{
	int	days_month_year[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int	day_week;
	int	day_current;
	int	week;
	int	month;
	int	day_month;
	int	result;
	int i = e->cantidad_empleados - 1;

	result = 0;
	day_current = 1;
	day_week = 0;
	week = 0;
	month = 0;
	day_month = 1;
	while (month < 12)
	{
		while (day_month <= days_month_year[month])
		{
			result = 0;
			if (day_month == 1 && result == 0)
			{
				result = 1;
				e->empleados[i].calendario->semanas[week].fecha_inicio = day_current;
				e->empleados[i].calendario->semanas[week].month = month;
				//printf("Week:%d fecha inicio->%d\n", week, e->empleados->calendario->semanas[week].fecha_inicio);
			}
			if (day_week == 0 && result == 0)
			{
				result = 1;
				e->empleados[i].calendario->semanas[week].fecha_inicio = day_current;
				e->empleados[i].calendario->semanas[week].month = month;
				//printf("Week:%d fecha inicio->%d\n", week, e->empleados->calendario->semanas[week].fecha_inicio);
			}
			if (day_week == 6 || day_month == days_month_year[month])
			{
				e->empleados[i].calendario->semanas[week].fecha_fin = day_current;
				e->empleados[i].calendario->semanas[week].month = month;
				//printf("Week:%d fecha fin->%d\n", week, e->empleados->calendario->semanas[week].fecha_fin);
				week++;
				if (day_week == 6)
					day_week = -1;
			}	
				if (day_week == 6 && day_month == days_month_year[month] && month == 11 && day_month == 31)
			{
				e->empleados[i].calendario->semanas[week].fecha_fin = day_current;
				e->empleados[i].calendario->semanas[week].month = month;
				//printf("Week:%d fecha fin->%d\n", week, e->empleados->calendario->semanas[week].fecha_fin);
				day_week = -1;
				week++;
			}
			day_month++;
			day_week++;
			day_current++;
		}
		day_month = 1;
		month++;
	}
	week = 0;
	while (week < 62)
	{
		e->empleados[i].calendario->semanas[week].date_start = get_date_inverted(e->empleados->calendario->semanas[week].fecha_inicio);
		e->empleados[i].calendario->semanas[week].date_fin = get_date_inverted(e->empleados->calendario->semanas[week].fecha_fin);
		week++;
	}

}

void	init_newcalendario(t_empresa *e)
{
	int fecha_compacta;
	int	dias_por_mes[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	x;
	int	dia;
	int mes;
	char	fecha_comp[5];
	t_empresa *read_data;

	read_data = read_file(e);
	if (read_data != NULL)
	{
		x = 0;
		dia = 1;
		mes = 0;
		while (mes < 12)
		{
			while (dia <= dias_por_mes[mes])
			{
				sprintf(fecha_comp, "%02d%02d", dia, mes + 1);
				fecha_compacta = atoi(fecha_comp);
				read_data->empleados->calendario->fecha[x].dia = fecha_compacta;	
			//	printf("%d\n", e->empleados->calendario->fecha[x].dia);
				dia++;
				x++;
			}
			mes++;
			dia = 1;
		}
		int i;
		int z;
	
		i = e->cantidad_empleados - 1;
		z = -1;
		while (++z < 366)
		{
			read_data->empleados[i].calendario->fecha[z].dia = read_data->empleados->calendario->fecha[z].dia;
		}
		separe_newweeks(read_data);
	}
	else
		printf(RED"Problem reading read_data in init_calender\n"RST);
}
