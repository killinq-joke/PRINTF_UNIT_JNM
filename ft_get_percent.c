/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:37:28 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/08 19:11:08 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_get_percent(char *flags)
{
    char *end;
    
    (void)flags;
    if (!(end = ft_calloc(sizeof(end), 2)))
        return (NULL);
    end[0] = '%';
    end[1] = '\0';
    return (end);
}