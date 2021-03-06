/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:13:14 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/06 21:13:28 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_get_str(char *flags, va_list args)
{
    char *end;
    int i;
    int y;
    char *value;
    char *va_arg;
    
    y = 0;
    i = 0;
    if (ft_strlen(flags) == 0)
    {
        va_arg = va_arg(args, char *);
        if (!(end = ft_calloc(sizeof(end), ft_strlen(va_arg) + 1)))
            return (NULL);
        ft_strcpy(end, va_arg);
        return (end);
    }
    return (NULL);
}