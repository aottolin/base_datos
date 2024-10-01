#include "lib.h"

void	imprimir_con_efecto(const char *texto, int color)
{

	if (color == 1)
	{	
		while (*texto)
		{
			printf(RED"%c"RST, *texto);
			fflush(stdout);
			usleep(25000);
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

void	presentacion_programa(void)
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
}
