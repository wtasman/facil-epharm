#ifndef PROJECT_H
# define PROJECT_H
# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# define WARNING     "\x1b[31m"
# define OK   "\x1b[32m"
# define INSTRUCTIONS  "\x1b[33m"
# define DRUG_NAME "\x1b[35m"
# define ANSI_COLOR_RESET   "\x1b[0m"


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

char				*rmv_title(char *str);
t_ptnt				*mk_ptnt(int fd);
t_drug				*ft_drugparse(t_ptnt *patientfile);
int					ft_strcmp(const char *s1, const char *s2);
void				drug_name(char *drug);
void				drug_conflict(char *conflict);
void				side_conflict(char *conflict);
void				instructions(char *instructions);
void				drug_clear(void);
void				side_clear(void);
void				dis_se_cmp(t_drug *pres, t_ptnt patient);

#endif
