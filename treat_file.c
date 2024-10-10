#include "lib.h"

void write_file(t_empresa *e, int x)
{
	FILE *file = fopen(archivo, "wb");
	if (!file)
	{
		printf(RED">_Error opening file to WRITE"RST);
		return ;
	}
	if (x == 1)
	{	
		fwrite(e, sizeof(t_empresa), 1, file);
		fwrite(e->empleados, sizeof(t_empleado), e->cantidad_empleados, file);
	}
	if (x == 2)
	{	
		fwrite(e, sizeof(t_empresa), 1, file);
		fwrite(e->empleados, sizeof(t_empleado), e->cantidad_empleados, file);
		int i;

		i = 0;
		while (i < e->cantidad_empleados)
		{
			fwrite(e->empleados[i].calendario, sizeof(t_calendario), 1, file);
			fwrite(e->empleados[i].calendario->fecha, sizeof(t_fecha), 365, file);
			fwrite(e->empleados[i].calendario->contract, sizeof(t_contract), 12, file);
			fwrite(e->empleados[i].calendario->semanas, sizeof(t_semana), 52, file);
			i++;
		}
	}
	printf(G">_File saved successfully.\n"RST);
	fclose(file);
}

t_empresa* read_file(t_empresa *e)
{
	FILE *file = fopen(archivo, "rb");
	if (!file)
	{
		printf(RED">_Error opening file to READ\n"RST);
		return NULL;
	}
	fread(e, sizeof(t_empresa), 1, file);
	e->empleados = fc_malloc(sizeof(t_empleado) * e->cantidad_empleados); // ver como funciona bien
	fread(e->empleados, sizeof(t_empleado), e->cantidad_empleados, file);
	int	i;

	i = 0;
	while (i < e->cantidad_empleados)
	{	
		e->empleados[i].calendario = fc_malloc(sizeof(t_calendario));
		if (e->empleados[i].calendario == NULL)
		{
			printf(RED">_Error allocating memory for calendario of empleado %d\n"RST, i);
			int j;

			j = 0;
			while (j < i)
			{
				free(e->empleados[j].calendario);
				j++;
			}
			free(e->empleados);
			fclose(file);
			return NULL;
		}
		fread(e->empleados[i].calendario, sizeof(t_calendario), 1, file);
		fread(e->empleados[i].calendario->fecha, sizeof(t_fecha), 365, file);
		fread(e->empleados[i].calendario->contract, sizeof(t_contract), 12, file);
		fread(e->empleados[i].calendario->semanas, sizeof(t_semana), 52, file);
		i++;
	}
	fclose(file);
	printf(G">_File read successfully.\n"RST);
	return (e);
}
