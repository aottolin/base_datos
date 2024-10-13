#include "lib.h"

void	separe_weeks(t_empleado *e)
{
	int	days_month_year[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int	day_week;
	int	day_current;
	int	week;
	int	month;
	int	day_month;
	int	result;

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
				e->calendario->semanas[week].fecha_inicio = day_current;
				e->calendario->semanas[week].month = month;
				//printf("Week:%d fecha inicio->%d\n", week, e->empleados->calendario->semanas[week].fecha_inicio);
			}
			if (day_week == 0 && result == 0)
			{
				result = 1;
				e->calendario->semanas[week].fecha_inicio = day_current;
				e->calendario->semanas[week].month = month;
				//printf("Week:%d fecha inicio->%d\n", week, e->empleados->calendario->semanas[week].fecha_inicio);
			}
			if (day_week == 6 || day_month == days_month_year[month])
			{
				e->calendario->semanas[week].fecha_fin = day_current;
				e->calendario->semanas[week].month = month;
				//printf("Week:%d fecha fin->%d\n", week, e->empleados->calendario->semanas[week].fecha_fin);
				week++;
				if (day_week == 6)
					day_week = -1;
			}	
				if (day_week == 6 && day_month == days_month_year[month] && month == 11 && day_month == 31)
			{
				e->calendario->semanas[week].fecha_fin = day_current;
				e->calendario->semanas[week].month = month;
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
		e->calendario->semanas[week].date_start = get_date_inverted(e->calendario->semanas[week].fecha_inicio);
		e->calendario->semanas[week].date_fin = get_date_inverted(e->calendario->semanas[week].fecha_fin);
		week++;
	}

}

int	get_date_inverted(int posic)
{
	static char date[5];
	int	date_atoi;	
	int	month;
	int day_month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	month = 0;
	while (posic > day_month[month])
	{
		posic -= day_month[month];
			month++;
	}
	snprintf(date, sizeof(date), "%02d%02d", posic, month + 1);
	date_atoi = atoi(date);
	return (date_atoi);
}

int	get_date(int day, int month)
{
	int date;
	int	x;
	int day_month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	x = 0;
	date = 0;
	while (x < month - 1)
		date += day_month[x++];
	date += day - 1;
	return (date);
}

int	date_id(int date)
{
	int	day;
	int	month;
	int day_month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	date_posicion;

	day = date / 100;
	month = date % 100;
	if (month < 1 || month > 12 || day < 1 || day > day_month[month - 1])
	{
		printf(RED"Wrong date input\n"RST);
		return -1;
	}
	date_posicion = get_date(day, month);
	return (date_posicion);
}

void	init_calendario(t_empleado *e)
{
	int fecha_compacta;
	int	dias_por_mes[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	x;
	int	dia;
	int mes;
	char	fecha_comp[5];
	
	e->calendario = fc_malloc(sizeof(t_calendario));
	x = 0;
	dia = 1;
	mes = 0;
	while (mes < 12)
	{
		while (dia <= dias_por_mes[mes])
		{
			sprintf(fecha_comp, "%02d%02d", dia, mes + 1);
			fecha_compacta = atoi(fecha_comp);
			e->calendario->fecha[x].dia = fecha_compacta;	
			//	printf("%d\n", e->empleados->calendario->fecha[x].dia);
			dia++;
			x++;
		}
		mes++;
		dia = 1;
	}
	separe_weeks(e);
}
