#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <ncurses.h>

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

typedef struct	s_contract
{
	int	id;
	int	hs;
	int ex_month;
}				t_contract;

typedef struct	s_fecha
{
	int	dia;
	float	hora_entrada;
	float	hora_entrada2;
	float	hora_salida;
	float	hora_salida2;
	bool	split;
	float	hs_hechas;
}				t_fecha;

typedef struct	s_semana
{
	int	fecha_inicio;
	int	fecha_fin;
	int	date_start;
	int	date_fin;
	int	month;
	float	hs_semana;
	float	hs_extras;
}				t_semana;

typedef struct	s_calendario
{
	t_fecha	fecha[366];
	t_semana semanas[62];
	t_contract contract[12];
	t_empresa	*empresa;
}				t_calendario;

typedef struct	s_empleado
{
	int				id;
	char			nombre[10];
	int				init_date;
	t_calendario	*calendario;
	t_empresa		*empresa;
}				t_empleado;

struct	s_empresa
{
	int			cantidad_empleados;
	bool		first_time;
	t_empleado	*empleados;
};

/*treat_file*/
void		write_file(t_empresa *e, int x);
t_empresa* read_file(t_empresa *e);
/*init*/
void		init_empleados(t_empresa *e);
void		init_new_employeed(t_empresa *e);
void		init_calendario(t_empleado *e);
/*modules*/
void		modules(t_empresa *e, int modulee);
void	module_3(t_empresa *datos_cargados, int value);
/*safe_functions*/
void		*fc_malloc(size_t bytes);
int			check_str(char *str);
int			check_date(int date);
void		clear_input_buffer();
int			check_func(t_empresa *e, float value, int m);
/*utils*/
void		imprimir_con_efecto(const char *texto, int color);
void		presentacion_programa(void);
int			contrasena(void);
void	get_bool(t_empresa *e);
/*shedules*/
void	edit_shedules(t_empresa *e);
/*init_calender*/
int		date_id(int date);
int		get_date(int day, int month);
int		get_date_inverted(int posic);
/*shedules utils*/
void	contract(t_empleado *e);
void	in_out(t_empleado *e, int day_posic);
void	in_out_split(t_empleado *e, int day_posic);
void	week_extras(t_empresa *e);
void	contract_hs(t_empresa *read_info);
void	init_dates(t_empresa *read_info);
/*ask_consult*/
void	consult_worker(t_empresa *e);
void	consult_in_out(t_empresa *e);
void	consult_extra(t_empresa *e);
/*ask_utils*/
void	in_out_date(t_empresa *e);
void	in_out_date_emp(t_empresa *e, int in_out_e);
void	ask_by_week(t_empresa *e);
void	ask_by_month(t_empresa *e);

void	principal(t_empresa *e, int value);
void	init_newcalendario(t_empresa *e);
void	separe_new_weeks(t_empresa *e);
void	week_extras(t_empresa *e);
void	programa_logo(void);
