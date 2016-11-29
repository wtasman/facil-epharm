#ifndef PROJECT_H
# define PROJECT_H

# include "libft/libft.h"
# include "get_next_line.h"

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
