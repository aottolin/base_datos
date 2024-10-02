#include "lib.h"

void write_file(t_empresa *e, int x)
{
	FILE *file = fopen(archivo, "wb");
	if (!file)
	{
		printf(RED"Error opening file to WRITE"RST);
		return ;
	}
	if (x == 1)
	{	
		fwrite(e, sizeof(t_empresa), 1, file);
		fwrite(e->empleados, sizeof(t_empleado), e->cantidad_empleados, file);
	}
	printf(G"File saved successfully.\n"RST);
	fclose(file);
}

t_empresa* read_file(t_empresa *e)
{
	FILE *file = fopen(archivo, "rb");
	if (!file)
	{
		printf(RED"Error opening file to READ\n"RST);
		return NULL;
	}
	fread(e, sizeof(t_empresa), 1, file);
	e->empleados = fc_malloc(sizeof(t_empleado) * e->cantidad_empleados); // ver como funciona bien
	fread(e->empleados, sizeof(t_empleado), e->cantidad_empleados, file);
	fclose(file);
	printf(G"File read successfully.\n"RST);
	return (e);
}
