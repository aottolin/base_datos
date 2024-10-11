#include "lib.h"

void	week_extras(t_empresa *e)
{
	int	i;
	int	week;
	int	day_posic;
	int	hs_week;
	int	month;
	t_empleado *em;
	
	i = -1;
	month = 0;
	while (++i < e->cantidad_empleados)
	{
		em = e->empleados + i;
		while (month < 12)
		{
			em->calendario->contract[month].hs = 20;
			month++;
		}
		month = 0;
	}
	i = -1;
	week = 0;
	while (++i < e->cantidad_empleados)
	{
		week = 0;
		em = e->empleados + i;
		while (week < 62)
		{
			hs_week = 0;
			day_posic = em->calendario->semanas[week].fecha_inicio - 1;
			//printf("Empleado %d, Semana %d: fecha_inicio=%d, fecha_fin=%d\n", i, week, em->calendario->semanas[week].fecha_inicio, em->calendario->semanas[week].fecha_fin);
			while (day_posic < em->calendario->semanas[week].fecha_fin)
			{
				hs_week += em->calendario->fecha[day_posic].hs_hechas;
			//	printf("day%d week%d hs hechas:%d \n", day_posic + 1, week, em->calendario->fecha[day_posic].hs_hechas);
				day_posic++;
			}
			em->calendario->semanas[week].hs_semana = hs_week;
			week++;
		}
	}
	i = -1;
	week = 0;
	month = 0;
	while (++i < e->cantidad_empleados)
	{
		em = e->empleados + i;
		while (week < 62)
		{
			 em->calendario->semanas[week].hs_extras = em->calendario->semanas[week].hs_semana - em->calendario->contract[month].hs; 
			week++;
		}
		week = 0;
	}
	int	extrasmonth;
	
	i = -1;
	while (++i < e->cantidad_empleados)
	{
		em = e->empleados + i;
		month = 0;
		while (month < 12)
		{
			extrasmonth = 0;
			while (week < 62)
			{
				if (month == em->calendario->semanas[week].month)
					extrasmonth += em->calendario->semanas[week].hs_extras; 
				week++;
			}
			em->calendario->contract[month].ex_month = extrasmonth;
			printf("%d %d\n", month + 1, em->calendario->contract[month].ex_month);
			week = 0;
			month++;
		}
	}
}
