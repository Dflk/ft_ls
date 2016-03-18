/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:19:23 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/18 14:29:41 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_strsj(char *path, char *name, unsigned int size_name)
{
	char	*str;

	if (!path || !name)
		return (NULL);
	str = path;
	if ((path = (char*)ft_memalloc(sizeof(char) *
					(ft_strlen(path) + size_name + 2))))
	{
		path = ft_strcpy(path, str);
		path = strcat(path, "/");
		path = ft_strncat(path, name, size_name);
		path[ft_strlen(path) + size_name] = '\0';
	}
	return (path);
}
