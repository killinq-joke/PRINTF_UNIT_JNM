/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:13:14 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:50 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char            *ft_get_str(char *flags, va_list args)
{
    char *end;
    char *ptr;
    char *va_arg;
    int a;
    int b;

    b = 0;
    if (strchr(flags, '.') != NULL)
    {
        a = ft_get_second_value(flags);
        b++;
    }
    else
        a = ft_get_first_value(flags);
    va_arg = va_arg(args, char *);
    if (va_arg == NULL && (((a >= 6 || a == 0) || a < 0) || b == 0))
    {
        end = ft_calloc(sizeof(end), 7);
        ptr = end;
        end = ft_strjoin(end, "(null)");
        free (ptr);
    }
    else if (va_arg == NULL && a < 6)
    {
        end = strdup("");
    }
    else
    {
        if (!(end = ft_calloc(sizeof(end), ft_strlen(va_arg) + 1)))
            return (NULL);
        ft_strcpy(end, va_arg);
    }
    end = ft_index(end, flags);
    return (end);
}