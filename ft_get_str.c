/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:13:14 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/09 10:42:27 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char     *ft_get_flags_values(char *flags, char *end)
{
    char *spaces;
    char *ptr;
    int isneg;
    int totlen;
    int isalone;
    int len;
    int i;

    i = 0;
    isalone = 0;
    totlen = 0;
    isneg = 0;
    spaces = ft_calloc(sizeof(spaces), 10);
    if ((flags[0] == '.' || flags[0] == '-') && ft_isalnum(flags[1]) == 0)
        return (end);
    spaces = ft_calloc(sizeof(spaces), 10);
    while (flags[i] != '.' && flags[i] != '\0')
    {
        spaces[i] = flags[i];
        i++;
    }
    if (ft_strlen(flags) == ft_strlen(spaces))
        isalone++;
    i++;
    if (flags[i])
        totlen = ft_atoi(flags + i);
    len = ft_atoi(spaces);
    free (spaces);
    if (len < 0)
    {
        len = -len;
        isneg++;
    }
    if (len >= totlen&& isalone == 0)
    {
        spaces = ft_calloc(sizeof(spaces), len);
        if (((int)ft_strlen(end) < totlen) && isneg == 0)
            ft_memset(spaces, ' ', len - ft_strlen(end));
        else if (isneg == 1 && len > totlen)
            return (end);
        else
            ft_memset(spaces, ' ', len - totlen);
        end[totlen] = '\0';
        ptr = end;
        end = ft_strcat(spaces, end);
        free (ptr);
    }
    else if (isalone > 0)
    {
        spaces = ft_calloc(sizeof(spaces), len);
        ft_memset(spaces, ' ', len - ft_strlen(end));
        end[len - totlen] = '\0';
        ptr = end;
        if (len < (int)ft_strlen(end))
        {
            end = ft_strcat(spaces, end);
            free (ptr);
        }
        else
            end = ft_strcat(end, spaces);
    }
    else
    {
        end[totlen] = '\0';
    }
    return (end);
}

static char     *ft_index(char *end, char *flags)
{
    end = ft_get_flags_values(flags, end);
    return (end);
}

char            *ft_get_str(char *flags, va_list args)
{
    char *end;
    char *ptr;
    char *va_arg;

    va_arg = va_arg(args, char *);
    if (va_arg == NULL)
    {
        end = ft_calloc(sizeof(end), 7);
        ptr = end;
        end = ft_strjoin(end, "(null)");
        free (ptr);
    }
    else
    {
        if (!(end = ft_calloc(sizeof(end), ft_strlen(va_arg) + 1)))
            return (NULL);
        ft_strcpy(end, va_arg);
    }
    if (ft_strlen(flags) != 0)
        end = ft_index(end, flags);
    return (end);
    return (NULL);
}