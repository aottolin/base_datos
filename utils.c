#include "lib.h"

void	contrasena(void)
{
	int a;
	int b;

	a = 1704;
	b = 0;
	printf(RED"Alex, i need the password to continue..\n"RST);
	while (a != b)
	{
		struct	termios	oldt, newt;

		tcgetattr(STDIN_FILENO, &oldt);
		newt = oldt;
		newt.c_lflag &= ~(ECHO);
		tcsetattr(STDIN_FILENO, TCSANOW, &newt);
		scanf("%d", &b);
		if (b == a)
		{
			char *print = "ENTER THE SIMULATION\n";
			imprimir_con_efecto(print, 3);
		}
		else
			printf(RED"Wrong Password, try again or leave the program now\n"RST);
		fflush(stdin);
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	}
}

void	imprimir_con_efecto(const char *texto, int color)
{

	if (color == 1)
	{	
		while (*texto)
		{
			printf(RED"%c"RST, *texto);
			fflush(stdout);
			usleep(10000);
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
	}
	else if (color == 3)
	{
		while (*texto)
		{
			printf(G"%c"RST, *texto);
			fflush(stdout);
			usleep(20000);
			texto++;
		}
	}
	printf("\n");
}

void	presentacion_programa(void)
{
	const char	*texto = "	Good morning Alex, everything it's ready to start!";
	const char	*texto2 = "		Do you want to init the simulation now?";
	const char	*texto3 = "				PRESS:ENTER";
	imprimir_con_efecto(texto, 1);
	usleep(350000);
	imprimir_con_efecto(texto2, 1);
	usleep(350000);
	imprimir_con_efecto(texto3, 2);
	getchar();
}
