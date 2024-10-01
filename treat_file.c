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
		fwrite(e->empleados, sizeof(t_empleado), 1, file);
	}
	printf("Archivo guardado exitosamente.\n");
	fclose(file);
}

t_empresa* read_file(void)
{
	t_empresa *e_read;

	FILE *file = fopen(archivo, "rb");
	if (!file)
	{
		printf(RED"Error opening file to READ\n"RST);
		return NULL;
	}
	e_read = fc_malloc(sizeof(t_empresa));
	fread(e_read, sizeof(t_empresa), 1, file);
	e_read->empleados = fc_malloc(sizeof(t_empleado));
	fread(e_read->empleados, sizeof(t_empleado), 1, file);
	fclose(file);
	return (e_read);
}
