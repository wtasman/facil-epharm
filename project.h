#ifndef PROJECT_H
# define PROJECT_H

# include "libft/libft.h"
# include "get_next_line.h"

// Pending prototype ideas //

typedef struct		s_drug
{
	char			*name;
	char			*ins;
	char			**drugi;	//drug interaction
	char			**diseasei;	//disease interation
	char			**se;		//side effects
	struct s_drug	*next;
}					t_drug;

typedef struct		s_ptnt		//patient
{
	char			*name;
	char			**pres;		//prescription
	char			**cur_med;	//current medication
	char			**disease;	//disease and complication
	struct s_ptnt	*next;
}					t_ptnt;

// please input your opinion //

#endif
