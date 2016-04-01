/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:54:47 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/30 12:10:33 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static unsigned char	ft_checkparam(char *arg, unsigned char params)
{
	int		i;

	i = 1;
	while (arg[i] != '\0')
	{
		if (arg[i] != 'R' && arg[i] != 'r' && arg[i] != 'a' && arg[i] != 'l'
				&& arg[i] != 't')
			ft_error(USAGE, 1, NULL);
		if (arg[i] == 'R' && !CHECK_BIT(params, PARAM_R_MAX_POS))
			params += 1 << PARAM_R_MAX_POS;
		else if (arg[i] == 'r' && !CHECK_BIT(params, PARAM_R_MIN_POS))
			params += 1 << PARAM_R_MIN_POS;
		else if (arg[i] == 'a' && !CHECK_BIT(params, PARAM_A_POS))
			params += 1 << PARAM_A_POS;
		else if (arg[i] == 'l' && !CHECK_BIT(params, PARAM_L_POS))
			params += 1 << PARAM_L_POS;
		else if (arg[i] == 't' && !CHECK_BIT(params, PARAM_T_POS))
			params += 1 << PARAM_T_POS;
		i++;
	}
	return (params);
}

unsigned char			ft_parseparams(int argc, char **argv)
{
	int				i;
	unsigned char	params;

	i = 0;
	params = 0;
	while (++i < argc && ft_strcmp(argv[i], "--") != 0)
		if (ft_strncmp(argv[i], "-", 1) == 0)
		{
			params = ft_checkparam(argv[i], params);
			argv[i] = NULL;
		}
	return (params);
}
