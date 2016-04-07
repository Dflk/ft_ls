/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:19:23 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/07 22:32:22 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_strsj(char *path, char *name)
{
	char	*str;

	if (!path)
		return (NULL);
	str = NULL;
	if (path[ft_strlen(path) - 1] != '/')
	{
		path = ft_strjoin(path, "/");
		str = path; 
	}
	if (name)
	{
		path = ft_strjoin(path, name);
		if (str)
			free(str);
	}
	return (path);
}

void	ft_putspaces(size_t i, size_t spaces)
{
	while (i++ < spaces)
		ft_putchar(' ');
}
