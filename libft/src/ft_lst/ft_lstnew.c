/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:19:36 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/17 22:19:39 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a new element. The variable ’content’ 
*	is initialized with the value of the parameter ’content’. The variable 
*	’next’ is initialized to NULL.
*	PARAMETERS
*	#1. The content to create the new element with.
*	RETURN VALUES
*	The new element.
*/

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = 0;
	new->content = content;
	return (new);
}
