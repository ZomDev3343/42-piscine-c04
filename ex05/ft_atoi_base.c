/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:24:54 by truello           #+#    #+#             */
/*   Updated: 2023/09/05 10:26:10 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + ft_strlen(++str));
}

int	ft_is_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	check_base(char *base)
{
	int	base_len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	base_len = ft_strlen(base);
	if (base_len > 1)
	{
		while (i < base_len)
		{
			while (j < base_len)
			{
				if ((i != j && base[i] == base[j])
					|| base[i] == '-' || base[i] == '+'
						|| ft_is_space(base[i]))
					return (0);
				j++;
			}
			j = 0;
			i++;
		}
		return (1);
	}
	return (0);
}

int	is_char_in_base(char *base, char c, int *value, int base_len)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			*value += i;
			*value *= base_len;
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	i;
	int	r;
	int	minus_count;
	int	base_len;

	i = 0;
	r = 0;
	base_len = ft_strlen(base);
	minus_count = 0;
	if (check_base(base))
	{
		while (ft_is_space(nbr[i]) || nbr[i] == '-' || nbr[i] == '+')
		{
			if (nbr[i] == '-')
				minus_count++;
			i++;
		}
		while (is_char_in_base(base, nbr[i], &r, base_len))
			i++;
		r /= base_len;
		if (minus_count % 2 == 1)
			r *= -1;
	}
	return (r);
}
/*#include <stdlib.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%s in base '%s' : %d\n", argv[1], argv[2], \
				ft_atoi_base(argv[1], argv[2]));	
	}
	return (0);
}*/
