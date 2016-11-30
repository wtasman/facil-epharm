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

void compare_drug_interaction(t_drug *presc, t_drug *currmed)
{
  t_drug *pcurr;
  t_drug *cmcurr;
  size_t i;
  size_t j;

  i = 0;
  pcurr = presc;
  cmcurr = currmed;
  while (pcurr)
  {
    while (cmcurr)
    {
      i = 0;
      j = 0;
      while (pres != NULL && currmed != NULL)
      {
        if (ft_strcmp(presc->pres[i], currmed->drugi[j]) == 0)
          drug_conflict(drugi[j]);
          i++;
          j++;
      }
      cmcurr = cmcurr->next;
    }
    pcurr = pcurr->next;
  }
}
