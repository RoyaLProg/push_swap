/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifcations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:21:33 by ccambium          #+#    #+#             */
/*   Updated: 2022/01/10 11:40:46 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_all_int(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!argv)
				return (1);
			if (!ft_isnum(argv[i][j]))
				return (1);
		}
		i++;
	}
	return (0);
}

static int	min_max(char **argv, int argc)
{
	long long int	x;
	int				i;

	i = 0;
	while (i < argc)
	{
		x = ft_itoa(argv[i]);
		if (x > 2147483647 || x < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	verification(char **argv, int argc)
{
	if (is_all_int(argv, argc))
		return (0);
	if (min_max(argv, argc))
		return (0);
	return (1);
}
