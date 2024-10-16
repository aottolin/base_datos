#include "lib.h"

void	shedules(t_empresa *e, int id)
{
	t_empleado *edit_employee;
	int	i;
	int	date;
	int day_p;
	bool	check;
	int	result;
	int	result2;
	int	result3;
	bool ok;
	int	c;
	int b;

	i = 0;
	date = 1702;
	check = false;
	ok = false;
	while (i < e->cantidad_empleados && check == false)
	{
		edit_employee = e->empleados + i;
		if (edit_employee->id != id)
			i++;
		else
		{
			while (!check)
			{
				while (!ok)
				{
					printf("	[1-Continued] or [2-Split]\n");
					if ((result3 = scanf("%d", &b) == 1) && (b == 1 || b == 2))
					{
						printf("	Date[DDMM]:\n");
						if ((result = scanf("%d", &date) == 1) && check_date(date) == 0)
						{
							result2 = 0;
							day_p = date_id(date);
							edit_employee->calendario->fecha[day_p].split = false;
							if (b == 1)
								in_out(edit_employee, day_p);
							if (b == 2)
							{
								in_out_split(edit_employee, day_p);
								edit_employee->calendario->fecha[day_p].split = true;
							}
							printf("Do you want to add another date in [%d]%s?	[1]yes-[2]no\n", edit_employee->id, edit_employee->nombre);	
							if ((result2 = scanf("%d", &c) == 1) && c == 1)
								check = false;
							else if (result2 == 1 && c == 2)
							{
								check = true;
								ok = true;
							}
							else if (result3 == 1)
							{
								printf(RED"Wrong input[1] or [2]\n"RST);
								return ;
							}
							else if (result3 != 1)
							{
								printf(RED"Wrong input[1] or [2]\n"RST);
								return ;
							}
						}
						else if (result != 1)
						{
							printf(RED"Wrong date input[DDMM]\n"RST);		
							clear_input_buffer();
						}
					}
					else if (result3 != 1)
					{
						printf(RED"Wrong input[1 - 2]\n"RST);		
							clear_input_buffer();
					}
				}
			}
		}
	}
}	

void	edit_shedules(t_empresa *e)
{
	t_empresa	*read_info;
	t_empleado	*edit_e;
	int			i;
	bool	check;
	int		id_e;
	int		result;

	check = false;
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
		while (!check)
		{
			if ((result = scanf("%d", &id_e) == 1) && check_func(read_info, id_e, 1) == 0 && check_func(read_info, id_e, 4) == 0)
			{
				shedules(read_info, id_e);
				check = true;
			}
			else if (result != 1)
				printf(RED"Error input.. Write a correct worker [NUMBER]\n"RST);
			clear_input_buffer();
		}
	}
	else
		printf(RED"Error reading file in edit_shedules"RST);
	week_extras(e);
}
