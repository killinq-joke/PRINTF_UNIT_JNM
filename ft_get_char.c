/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:17:06 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/06 22:26:06 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_get_char(char *flags, va_list args)
{
    char *end;
    int va_arg;
    
    if (ft_strlen(flags) == 0)
    {
        va_arg = va_arg(args, int);
        if (!(end = ft_calloc(sizeof(end), 2)))
            return (NULL);
        end[0] = va_arg;
		end[1] = '\0';
        return (end);
    }
    return (NULL);
}