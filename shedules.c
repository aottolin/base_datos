#include "lib.h"

void	in_out(t_empleado *e, int day_posic)
{
	bool	check2;
	int	in;
	int	out;
	int	result;

	check2 = false;
	
	while (!check2)
	{
		printf("	IN time:\n");
		result = scanf("%d", &in);
		if (result == 1 && check_time(in) == 0)
		{
			e->calendario->fecha[day_posic].hora_entrada = in;
			check2 = true;
		}
		else
			printf(RED"Wrong time IN input\n"RST);
		clear_input_buffer();
	}
	check2 = false;
	while (!check2)
	{
		result = 0;
		printf("	OUT time:\n");
		result = scanf("%d", &out);
		if (result == 1 && check_time(out) == 0)
		{
			e->calendario->fecha[day_posic].hora_salida = out;
			check2 = true;
		}
		else
			printf(RED"Wrong time OUT input\n"RST);
		clear_input_buffer();
	}
}

void	shedules(t_empresa *e, int id)
{
	t_empleado *edit_employee;
	int	i;
	int	date;
	int day_p;
	bool	check;
	int	result;
	char	c;

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
				printf("	Date[DDMM]:\n");
				result = scanf("%d", &date);
				if (result == 1 && check_date(date) == 0)
				{
					day_p = date_id(date);
					//printf("day_p:%d\n", day_p);
					in_out(edit_employee, day_p);
					printf("Do you want yo add another date? [y-n]\n");					//edit_employee->calendario->fecha[day_p].hora_salida = 10;
					scanf("%c", &c);
					if (c == 'y')
						check = false;
					else if (c == 'n')
						check = true;
					else
						printf(RED"Wrong input[y or n]\n"RST);
				}
				else
				{
					if (result != 1)
						printf(RED"Wrong date input[DDMM]\n"RST);		
				}
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
			printf(" [%d]%s", edit_e->id, edit_e->nombre);
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
