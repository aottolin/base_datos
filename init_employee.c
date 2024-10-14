#include "lib.h"

void	init_new_employeed(t_empresa *e)
{
	t_empresa *read_data;
	t_empleado *new_employeed;

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
		printf("\n\n");
		t_empleado *temp = realloc(read_data->empleados, sizeof(t_empleado) * (i + 1));
		read_data->empleados = temp;
		new_employeed = &read_data->empleados[i];
		new_employeed->id = read_data->cantidad_empleados + 1;
		printf("	Employeed[%d] NAME:\n", new_employeed->id);
		fgets(new_employeed->nombre, sizeof(new_employeed->nombre), stdin);
		new_employeed->nombre[strcspn(new_employeed->nombre, "\n")] = '\0';
		new_employeed->empresa = e;
		read_data->cantidad_empleados++;
		init_calendario(new_employeed);
	}
	else
		printf("Program cannot read the data(init_new_employeed_fc\n");
}

void	init_empleados(t_empresa *e)
{
	int	i;
	int resultado;
	bool	correct;
	int nbr;
	t_empleado *empleado;

	i = -1;
	correct = false;
	resultado = 0;
	while (!correct)
	{
		printf("	Number of employees:\n");
		if ((resultado = scanf("%d", &e->cantidad_empleados)) == 1 && check_func(e, e->cantidad_empleados, 1) == 0)
			correct = true;	
		else if (resultado != 1)
			printf(RED"Write a number from 1 to 20\n"RST);
		clear_input_buffer();
	}
	resultado = 0;
	e->empleados = fc_malloc(sizeof(t_empleado) * e->cantidad_empleados);
	nbr = 0;
	while (++i < e->cantidad_empleados)
	{
		empleado = e->empleados + i;
		empleado->id = ++nbr;
		char str[10];

		printf("	Employeed[%d] NAME:\n", nbr);
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
		init_calendario(empleado);
	}
}
