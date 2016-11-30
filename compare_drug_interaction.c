/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_drug_interaction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:54:56 by jjia              #+#    #+#             */
/*   Updated: 2016/11/29 15:54:58 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

void drug_compare()
int compare_drug_interaction(t_drug *druglist, t_ptnt ptntlist)
{
  t_drug *dcurr;
  size_t i;
  size_t j;
  size_t dlen;
  size_t plen;

  i = 0;
  j = 0;
  dcurr = druglist;
  while (dcurr)
  {
    (while druglist != NULL && ptntlist != NULL)
    {
      if (ft_strcmp(ptntlist->pres[i], druglist->drugi[j]) == 0)
        drug_conflict(drugi[j]);
      j++;
    }
    i++;
    dcurr = dcurr->next;
  }
}
