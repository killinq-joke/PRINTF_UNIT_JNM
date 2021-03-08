/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:13:14 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/08 16:49:37 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_get_str(char *flags, va_list args)
{
    char *end;
    char *ptr;
    char *va_arg;
    
    if (ft_strlen(flags) == 0)
    {
        va_arg = va_arg(args, char *);
        if (va_arg == NULL)
        {
            end = ft_calloc(sizeof(end), 7);
            ptr = end;
            end = ft_strjoin(end, "(null)");
            free (ptr);
            return (end);
        }
        if (!(end = ft_calloc(sizeof(end), ft_strlen(va_arg) + 1)))
            return (NULL);
        ft_strcpy(end, va_arg);
        return (end);
    }
    return (NULL);
}