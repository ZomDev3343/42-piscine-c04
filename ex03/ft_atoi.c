/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:57:53 by truello           #+#    #+#             */
/*   Updated: 2023/09/05 10:17:13 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c)
{
	if (c == ' ' || (c <= '\r' && c >= '\t'))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		r;
	int		minus_count;

	i = 0;
	r = 0;
	minus_count = 0;
	while (ft_is_space(str[i]) || str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		r += (str[i] - '0');
		r *= 10;
		i++;
	}
	r /= 10;
	if (minus_count % 2 == 1)
		r *= -1;
	return (r);
}
/*#include <stdio.h>
int	main(void)
{
	char test[] = "----\n434";

	printf("Test avec 42 : %d\n", ft_atoi("42"));
	printf("Test avec -42 : %d\n", ft_atoi("-42"));
	printf("Test avec 2000000 : %d\n", ft_atoi("2000000"));
	printf("Test avec 0 : %d\n", ft_atoi("0"));
	printf("Test avec --+++-42 : %d\n", ft_atoi("--++-42"));
	printf("Test avec --42 : %d\n", ft_atoi("--42"));
	printf("Test avec -42aba43 : %d\n", ft_atoi("-42aba43"));
	printf("Test avec ----\n434 : %d\n", ft_atoi(test));	
	return (0);
}*/
