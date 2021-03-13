/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:42:06 by trofidal          #+#    #+#             */
/*   Updated: 2021/02/22 20:42:06 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int      ft_find_char(char c,char *str)
{
  int i;

  i = 0;
  while(str[i])
  {
    if(str[i] == c)
      return  (1);
    i++;
  }
  return (0);
}