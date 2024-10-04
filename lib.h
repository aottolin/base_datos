#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define RST		"\033[0m"	 //reset to default color
#define RED		"\033[31m" //Bold red
#define G		"\033[32m" //Bold Green
#define Y		"\033[33m" // Bold Yellow
#define B		"\033[34m" // Bold Blue
#define M		"\033[35m" // Bold Magenta
#define C		"\033[36m" // Bold Cyan
#define W		"\033[37m" // Bold White

#define	archivo "empleados.dat"
typedef struct s_empresa t_empresa;

typedef struct	s_fecha
{
	int	dia;
	int	hora_entrada;
	int	hora_salida;
	int	hs_extras_dia;
	int	hs_extras_semana;
	int	hs_extras_mes;
}				t_fecha;

typedef struct	s_calendario
{
	t_fecha	fecha[365];

}				t_calendario;

typedef struct	s_empleado
{
	int				id;
	char			nombre[10];
	t_calendario	*calendario;
	t_empresa		*empresa;
}				t_empleado;

struct	s_empresa
{
	int			cantidad_empleados;
	t_empleado	*empleados;
};
						   

t_empresa* read_file(t_empresa *e);
void	init_new_employeed(t_empresa *e);
void	init_calendario(t_empresa *e);
void	modules(t_empresa *e, int x);
void	init_empleados(t_empresa *e);
int		check_errors_nbr(int nbr);
void	*fc_malloc(size_t bytes);
void	imprimir_con_efecto(const char *texto, int color);
void	presentacion_programa(void);
void write_file(t_empresa *e, int x);
int	check_str(char *str);
int	contrasena(void);
