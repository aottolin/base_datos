#include "lib.h"

int	get_date(int day, int month)
{
	int date;
	int	x;
	int day_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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
	int day_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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

void	init_calendario(t_empresa *e)
{
	int fecha_compacta;
	int	dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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
	
		i = 0;
		while (i < read_data->cantidad_empleados)
		{
			z = -1;
			while (++z < 365)
			{
				read_data->empleados[i].calendario->fecha[z].dia = read_data->empleados->calendario->fecha[z].dia;
				//printf("%d\n", e->empleados[i].calendario->fecha[z].dia);
			}
			i++;
		}
	}
	else
		printf(RED"Problem reading read_data in init_calender\n"RST);
}
