/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:01:40 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/26 11:23:13 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	unsigned char	params;
	char			**paths;

	params = 0;
	if (argc > 1)
		params = ft_parseparams(argc, argv);
	paths = ft_parseargs(argc, argv);
	ft_ls(paths, params);
	return (0);
}
