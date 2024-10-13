#include "lib.h"

int	contrasena(void)
{
	int a;
	int b;
	int	counter;
	int	counter2;
	struct	termios	oldt, newt;

	a = 1704;
	b = 0;
	counter = 0;
	counter2 = 2;
	
	printf(RED"Alex Collet, i need the password to continue..\n"RST);
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	
	while (counter++ < 3)
	{
		scanf("%d", &b);
		if (b == a)
		{
			char *print = ">_Password OK.. Enter the simulation\n";
			imprimir_con_efecto(print, 3);
			tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
			return (0);
		}
		else
			printf(RED"Wrong Password.. try again: %d attempts left \n"RST, counter2--);
		fflush(stdin);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	printf("3 FAILED attempts, The program will TURN OFF\n"); 
		return -1;
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
	const char	*texto = "	Good morning Alex Collet, everything it's ready to start!";
	const char	*texto2 = "		Do you want to init the simulation now?";
	const char	*texto3 = "				PRESS:ENTER";
	imprimir_con_efecto(texto, 1);
	usleep(350000);
	imprimir_con_efecto(texto2, 1);
	usleep(350000);
	imprimir_con_efecto(texto3, 2);
	getchar();
}


