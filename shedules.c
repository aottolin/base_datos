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

void	shedules(t_empresa *e, int id)
{
	t_empleado *edit_employee;
	int	i;
	int	date;
	int day_p;
	bool	check;
	int	result;

	i = 0;
	date = 1702;
	check = false;
	while (i < e->cantidad_empleados && check == false)
	{
		edit_employee = e->empleados + i;
		if (edit_employee->id != id)
			i++;
		else
		{
			while (!check)
			{
				printf("Write date:\n");
				result = scanf("%d", &date);
				if (result == 1 && check_date(date) == 0)
				{
					day_p = date_id(date);
					printf("day_p:%d\n", day_p);
					edit_employee->calendario->fecha[day_p].hora_salida = 10;
					check = true;
				}
				else
				{
					if (result != 1)
						printf(RED"Wrong date input[DDMM]\n"RST);				}
				clear_input_buffer();
			}
		}
	}
}

void	edit_shedules(t_empresa *e)
{
	t_empresa	*read_info;
	t_empleado	*edit_e;
	int			i;
	
	read_info = read_file(e);
	i = 0;
	if (read_info != NULL)
	{
		printf("Add new shedule to:");
		while (i < read_info->cantidad_empleados)
		{
			edit_e = read_info->empleados + i;
			printf(" [%d] %s", edit_e->id, edit_e->nombre);
			i++;
		}
		printf("\n");
		int	id_e;
		scanf("%d", &id_e);
		if (check_errors_nbr(id_e) == 0 && check_idem_2(read_info, id_e) == 0)
			shedules(read_info, id_e);
		}
	else
		printf(RED"Error reading file in edit_shedules"RST);
}
