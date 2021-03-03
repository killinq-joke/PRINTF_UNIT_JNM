/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:19:02 by trofidal          #+#    #+#             */
/*   Updated: 2021/03/03 08:19:16 by trofidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# define BUFF_SIZE 32


typedef struct		s_print
{
	char			*type; 		/* %s %d */
	char			*flags; 	/* - + # 0 ' ' */
	void			*content; 	/* les strings, le contenu */
	struct s_print	*next; 		/* pointeur sur le prochain objet a print */
}					t_print;

/*
**VOID FUNCTIONS
*/

/*
**CHAR FUNCTIONS
*/ 

/*
**SIZE_T FUNCTIONS
*/

/*
**INT FUNCTIONS
*/
int     ft_printf(const char *str, ...);
/*
**T_LIST
*/

#endif
