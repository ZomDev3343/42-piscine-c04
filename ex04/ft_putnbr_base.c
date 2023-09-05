/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:45:16 by truello           #+#    #+#             */
/*   Updated: 2023/09/05 10:14:34 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + ft_strlen(++str));
}

int	check_base(char *base)
{
	int	base_len;
	int	i;
	int	j;

	i = -1;
	j = -1;
	base_len = ft_strlen(base);
	if (base_len > 1)
	{
		while (++i < base_len)
		{
			while (++j < base_len)
				if ((i != j && base[i] == base[j])
					|| base[i] == '-' || base[i] == '+')
					return (0);
			j = 0;
		}
		return (1);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_len;
	long int	nbb;

	nbb = (long int) nbr;
	if (check_base(base))
	{
		base_len = ft_strlen(base);
		if (nbb < 0)
		{
			write(1, "-", 1);
			nbb *= -1;
		}
		if (nbb >= 0 && nbb < base_len)
		{
			write(1, &base[nbb], 1);
		}
		else
		{
			ft_putnbr_base(nbb / base_len, base);
			ft_putnbr_base(nbb % base_len, base);
		}
	}
}
/*#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int nbr = atoi(argv[1]);
		char *base = argv[2];

		ft_putnbr_base(nbr, base);
		write(1, "\n", 1);
	}
	return (0);
}*/
