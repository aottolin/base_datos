#include "lib.h"

void	init_calendario(t_empleados *empleados)
{
	int fecha_compacta;
	int	dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	x;
	int	dia;
	int mes;
	char	fecha_comp[5];

	x = 0;
	dia = 1;
	mes = 0;

	empleados->calendario = malloc(sizeof(empleados->calendario) * 20);
	while (mes < 12)
	{
		while (dia <= dias_por_mes[mes])
		{
			sprintf(fecha_comp, "%02d%02d", dia, mes + 1);
			fecha_compacta = atoi(fecha_comp);
			empleados->calendario->fecha[x].dia = fecha_compacta;	
			//printf("%d\n", empleados->calendario->fecha[x].dia);
			dia++;
			x++;
		}
		mes++;
		dia = 1;
	}
}

void	leer_datos(t_empleados *empleados)
{
	FILE *file = fopen(archivo, "rb");
	if (file == NULL)
	{
		printf("no se puede abrir para leer el archivo");
		return ;
	}
	int num_leido = fread(empleados, sizeof(t_empleados), 20, file);
	if (num_leido == 0) 
        printf("No se pudieron leer empleados del archivo o el archivo está vacío.\n");
	fclose(file);
}

void	guardar_datos(t_empleados *empleado)
{
	FILE *file = fopen(archivo, "wb");
	if (file == NULL)
	{
		printf("no se puede abrir para guardar los datos en el archivo");
		return ;
	}

	size_t num_w = fwrite(empleado, sizeof(t_empleados), 1, file);
	if (num_w != 1)
		printf("no se puede esxrriitb");
	fclose(file);
}

void	init_empleados(t_empleados *empleados)
{
	int	x;
	int i = 0;

	printf("Ingrese numero del empleado:\n");
	scanf("%d", &x);
	empleados[0].id = x;
	fflush(stdin);

	empleados[x].nombre = (char *)malloc(50 * sizeof(char));
	printf("Ingrese nombre del empleado:\n");
	scanf("%s", empleados[0].nombre);
	printf("%s\n", empleados[0].nombre);
	printf("%d\n", empleados[0].id);
	guardar_datos(empleados);
	return ;
}
