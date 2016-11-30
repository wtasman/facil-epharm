/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_se_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:56:14 by yherrera          #+#    #+#             */
/*   Updated: 2016/11/29 16:56:19 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

void	drug_name(char *drug)
{
	printf(DRUG_NAME "Prescribed Drug: %s\n" ANSI_COLOR_RESET, drug);
}

void	drug_conflict(char *conflict)
{
	printf(WARNING "WARNING: conflict with %s\n" ANSI_COLOR_RESET, conflict);
}

void	side_conflict(char *conflict)
{
	printf(WARNING "WARNING: patent already has %s\n" ANSI_COLOR_RESET, conflict);
}

void	instructions(char *instructions)
{
	printf(INSTRUCTIONS "%s\n" ANSI_COLOR_RESET, instructions);
}

void	all_clear()
{
	printf(OK "OK\n" ANSI_COLOR_RESET);
}

static void	disease_cmp(char **di, char **ptnt)
{
	size_t	id;
	size_t	ip;

	ip = 0;
	while (ptnt[ip])
	{
		id = 0;
		while (di[id])
		{
			if (!ft_strcmp(di[id], ptnt[ip]))
				side_conflict(di[id]);
			id++;
		}
		ip++;
	}
}

static void	se_cmp(char **se, char **ptnt)
{
	size_t	is;
	size_t	ip;

	ip = 0;
	while (ptnt[ip])
	{
		is = 0;
		while (se[is])
		{
			if (!ft_strcmp(se[is], ptnt[ip]))
				side_conflict(se[is]);
			is++;
		}
		ip++;
	}
}

void		dis_se_cmp(t_drug *pres, t_ptnt patient)
{
	t_drug	*tpres;

	tpres = pres;
	while (tpres)
	{
		disease_cmp(pres->diseasei, patient->disease);
		se_cmp(pres->se, patient->disease);
		tpres = tpres->next;
	}
}
