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

void compare_drug_interaction(t_drug *druglist, t_ptnt *patient)
{
  size_t i;
  size_t j;
  size_t counter;

  i = 0;
  counter = 0;
  while (druglist->drugi[i])
  {
    j = 0;
    while (patient->pres[j])
    {
      if (ft_strcmp(druglist->drugi[i], patient->pres[j]) == 0)
      {
        drug_conflict(drugi[i]);
        counter++;
      }
      j++;
    }
    i++;
  }
  i = 0;
  while (druglist->drugi[i])
  {
    j = 0;
    while (patient->pres[j])
    {
      if (ft_strcmp(druglist->drugi[i], patient->curr_med[j]) == 0)
      {
        drug_conflict(drugi[i]);
        counter++;
      }
      j++;
    }
    i++;
  }
  if (counter == 0)
    drug_clear();
}
