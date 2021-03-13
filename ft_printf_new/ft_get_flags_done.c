/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags_done.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:01:53 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/13 10:54:24 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      ft_flags_numbers(char *flags) // GIVE FLAGS AMOUNT
{
    int i;
    int numbers;

    i = 0;
    numbers = 0;
    if (ft_strlen(flags) == 0)
        return (numbers);
    if (flags[0] == '.' && ft_isalnum(flags[1]) == 1)
        return (2);
    while (flags[i] != '.' && flags[i + 1] != '\0')
        i++;
    if (i > 0) 
    {
        numbers++;
        i++;
    }
    if (flags[i])
    {
        i++;
        numbers++;
    }
    return (numbers);
}

static char     *ft_is_one_value(char *flags, char *end)
{
    int i;
    int side;
    char *str;
    char *ptr;
    

    i = ft_get_first_value(flags);
    side = i;
    if (i < 0)
    { 
        i = -i;
        str = ft_calloc(sizeof(str), i + ft_strlen(end) + 1);
    }
    else
        str = ft_calloc(sizeof(str), i + ft_strlen(end) + 1);
    ptr = str;
    if (i > 0 && i > (int)ft_strlen(end) && -side < 0)
    {  
        ft_memset(str, ' ', i - (int)ft_strlen(end));
        str = ft_strcat(str, end);
        free (end);
        return (str);
    }
    else if (i > (int)ft_strlen(end) && -side > 0)
    {
        
        if (i < 0)
            i = -i;
        ft_strcpy(str, end);
        ft_memset(str + (int)ft_strlen(end), ' ', i - ft_strlen(end)); 
        free (end);
        return (str);
    }
    free (ptr);
    return (end);
}

static char     *ft_is_two_values(char *flags, char *end)
{
    int value;
    char *ptr;
    char *new_flags;

    value = ft_get_second_value(flags);
    end[value] = '\0';
    value = ft_get_first_value(flags);
    ptr = ft_itoa(value);
    new_flags = ft_calloc(sizeof(new_flags), ft_strlen(ptr) + 1);
    ft_strcpy(new_flags, ptr);
    end = ft_is_one_value(new_flags, end);
    free (ptr);
    free (new_flags);
    return (end);
}

char     *ft_index(char *end, char *flags)
{
    if (ft_flags_numbers(flags) == 0)
        return (end);
    if (ft_flags_numbers(flags) == 1)
        end = ft_is_one_value(flags, end);
    if (ft_flags_numbers(flags) == 2)
        end = ft_is_two_values(flags, end);
    return (end);
}