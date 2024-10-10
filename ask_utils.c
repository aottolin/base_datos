#include "lib.h"

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
				printf("[%d]%s >> %d to %d HsTotal >>%d\n", e->empleados[i].id, e->empleados[i].nombre, e->empleados[i].calendario->fecha[day_p].hora_entrada, e->empleados[i].calendario->fecha[day_p].hora_salida, e->empleados[i].calendario->fecha[day_p].hs_extras_dia);
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

