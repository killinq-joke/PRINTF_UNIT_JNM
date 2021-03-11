/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_first_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 06:42:47 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/11 06:43:00 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int      ft_get_first_value(char *flags) // GET FLAGS FIRST VALUE
{
    int i;
    char *first_value;

    i = 0;
    if (ft_strlen(flags) == 0)
        return (i);
    first_value = ft_calloc(sizeof(first_value), 10);
    if (flags[0] == '.')
        first_value[0] = '0';
    else
    {
        while (flags[i] != '.' && flags[i] != '\0')
        {
            first_value[i] = flags[i];
            i++;
        }
    }
    i = ft_atoi(first_value);
    free (first_value); //------
    return (i);
}