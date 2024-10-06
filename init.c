#include "lib.h"

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

void	init_new_employeed(t_empresa *e)
{
	t_empresa *read_data;
	t_empleado *new_employeed;
	bool	check;

	check = false;
	read_data = read_file(e);
	if (read_data != NULL)
	{
		int	i;
		int	a;

		i = read_data->cantidad_empleados;
		a = 0;
		printf("	Workers all ready created:\n");
		while (a < read_data->cantidad_empleados)
		{
			printf("[%d]%s ", read_data->empleados[a].id, read_data->empleados[a].nombre);
			a++;
		}
		printf("\n");
		new_employeed = read_data->empleados + i;
		while (!check)
		{
			int resultado;
			int	scan_id_employeed;
			printf("	\nWrite Employeed NUMBER:\n");
			resultado = scanf("%d", &scan_id_employeed);
			if (resultado == 1 && check_errors_nbr(scan_id_employeed) == 0 && check_idem(read_data, scan_id_employeed) == 0)
			{
				new_employeed->id = scan_id_employeed;
				check = true;
			}
			else
			{
				if (resultado != 1)
					printf(RED"Write a number from 1 to 20\n"RST);
			}
			fflush(stdin);
		}
		printf("	Employeed NAME:\n");
		fgets(new_employeed->nombre, sizeof(new_employeed->nombre), stdin);
		new_employeed->nombre[strcspn(new_employeed->nombre, "\n")] = '\0';
		new_employeed->empresa = e;
		read_data->cantidad_empleados = i + 1;
	}
	else
		printf("Program cannot read the data(init_new_employeed_fc\n");
}

void	init_empleados(t_empresa *e)
{
	int	i;
	int resultado;
	int	scan_id_empleado;
	bool	correct;
	int	contador;
	t_empleado *empleado;
	
	i = -1;
	contador = 1;
	correct = false;
	while (!correct)
	{
		printf("	Number of employees:\n");
		resultado = scanf("%d", &e->cantidad_empleados);
		if (resultado == 1 && check_errors_nbr(e->cantidad_empleados) == 0)
			correct = true;
		else
			printf(RED"Write a number from 1 to 20\n"RST);
	}
	correct = false;
	resultado = 0;
	e->empleados = fc_malloc(sizeof(t_empleado) * e->cantidad_empleados);
	while (++i < e->cantidad_empleados)
	{
		empleado = e->empleados + i;
		while (!correct)
		{
			printf("	Employeed[%d] NUMBER:\n", contador);
			resultado = scanf("%d", &scan_id_empleado);
			if (resultado == 1 && check_errors_nbr(scan_id_empleado) == 0 && check_idem(e, scan_id_empleado) == 0)
			{
				empleado->id = scan_id_empleado;
				correct = true;
			}
			else
			{
				if (resultado != 1)
					printf(RED"Write a number from 1 to 20\n"RST);
			}
		clear_input_buffer();
		}
		correct = false;
		while (!correct)
		{
			char str[10];

			printf("	Employeed[%d] NAME:\n", contador);
			fgets(str, sizeof(str), stdin);
			str[strcspn(str, "\n")] = '\0';
			if (check_str(str) == 0)
			{
				memcpy(empleado->nombre, str, sizeof(str));
				correct = true;
			}
			else
				printf(RED"Write valid input (char)\n"RST);
			empleado->empresa = e;
		}
		correct = false;
		contador++;
	}
}
