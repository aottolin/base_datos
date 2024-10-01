#include "lib.h"

void	imprimir_con_efecto(const char *texto, int color)
{

	if (color == 1)
	{	
		while (*texto)
		{
			printf(RED"%c"RST, *texto);
			fflush(stdout);
			usleep(45000);
			texto++;
		}
		printf("\n");
	}
	else if (color == 2)
	{
		while (*texto)
		{
			printf(W"%c"RST, *texto);
			fflush(stdout);
			usleep(20000);
			texto++;
		}
		printf("\n");
	}
}

int	main(void)
{
	const char	*texto = "	Buenos dias Alexis, todo esta listo para empezar!";
	const char	*texto2 = "		Quieres iniciar el programa ahora?";
	const char	*texto3 = "				PRESS:ENTER";
	imprimir_con_efecto(texto, 1);
	usleep(350000);
	imprimir_con_efecto(texto2, 1);
	usleep(350000);
	imprimir_con_efecto(texto3, 2);
	getchar();
	//char	module_program;
	//bool	ok;
	t_empresa *e;

	e = fc_malloc(sizeof(t_empresa));
	//ok = false;
	init_empleados(e);
	init_calendario(e);
	/*while (!ok)
	{
		printf("EDICION: '1' || CONSULTA: '2'\n");
		scanf("%c", &module_program);
		fflush(stdin);
		if (module_program == '1')
		{
			ok = true;
			init_empleados(e);
		}
		else if (module_program == '2')
		{
			int x;
			leer_datos(e);
			printf("numero de empleado\n");
			scanf("%d", &x);
			printf("%d", e[x].id);
			ok = true;
		}
		else
			printf(RED"Wrong parameter (1 = edicion, 2 = consulta)\n"RST);
	*/
	return (0);
}
