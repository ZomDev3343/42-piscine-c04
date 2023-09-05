/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:41:55 by truello           #+#    #+#             */
/*   Updated: 2023/08/31 15:58:43 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[0] != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
//int	main(void)
//{
//	printf("Longueur de la chaine 'Hello' : %d", ft_strlen("Hello"));
//	return (0);
//}
