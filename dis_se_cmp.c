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

static size_t	disease_cmp(char **di, char **ptnt)
{
	size_t	id;
	size_t	ip;
	size_t	count;

	ip = 0;
	count = 0;
	while (ptnt[ip])
	{
		id = 0;
		while (di[id])
		{
			if (!ft_strcmp(di[id], ptnt[ip]))
			{
				side_conflict(di[id]);
				count++;
			}
			id++;
		}
		ip++;
	}
}

static size_t	se_cmp(char **se, char **ptnt)
{
	size_t	is;
	size_t	ip;
	size_t	count;

	ip = 0;
	count = 0;
	while (ptnt[ip])
	{
		is = 0;
		while (se[is])
		{
			if (!ft_strcmp(se[is], ptnt[ip]))
			{
				side_conflict(se[is]);
				count++;
			}
			is++;
		}
		ip++;
	}
	return (count);
}

void			dis_se_cmp(t_drug *presc, t_ptnt *patient)
{
	t_drug	*tpresc;

	tpres = presc;
	while (tpresc)
	{
		drug_name(tpresc->name);
		compare_drug_interaction(presc, patient);
		if(!(disease_cmp(tpresc->diseasei, patient->disease))
			&& !(se_cmp(tpresc->se, patient->disease)))
			side_clear();
		tpresc = tpresc->next;
	}
}
