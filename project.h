#ifndef PROJECT_H
# define PROJECT_H

# include "libft/libft.h"
# include "get_next_line.h"
#include <stdio.h>

#define WARNING     "\x1b[31m"
#define OK   "\x1b[32m"
#define INSTRUCTIONS  "\x1b[33m"
/*
printf(INSTRUCTIONS     "TAKE BEFORE BED WITH DRINK"     ANSI_COLOR_RESET "\n");
*/
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct		s_drug
{
	char			*name;
	char			*ins;
	char			**drugi;
	char			**diseasei;
	char			**se;
	struct s_drug	*next;
}					t_drug;

typedef struct		s_ptnt
{
	char			*name;
	char			**pres;
	char			**cur_med;
	char			**disease;
}					t_ptnt;

#endif
