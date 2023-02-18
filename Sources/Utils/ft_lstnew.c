/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:27:25 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/18 20:16:07 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

char	*ft_strdup_without_nl(const char *s)
{
	int		size;
	int		i;
	char	*str;

	if (!s)
		return (0);
	size = ft_strlen (s);
	str = malloc (sizeof(char) * (size + 1));
	i = 0;
	if (!str)
		return (0);
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_map	*ft_lstnew(void *extract)
{
	t_map	*new_element;

	new_element = malloc(sizeof(t_map));
	if (!new_element)
		return (NULL);
	new_element->line = ft_strdup_without_nl(extract);
	if (!new_element->line)
	{
		free (new_element);
		return (NULL);
	}
	new_element->prev = NULL;
	new_element->next = NULL;
	return (new_element);
}
