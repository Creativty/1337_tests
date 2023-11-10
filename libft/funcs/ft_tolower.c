/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:23:20 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 17:24:35 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

int	ft_tolower_test(void)
{
	int	failures;
	failures = 0;
	for (int i = 0; i < 255; i++)
	{
		int exp = tolower(i);
		int out = ft_tolower(i);
		if (exp != out)
		{
			log_error("test %d: user: \"%d\", expected: \"%d\"", i, out, exp);
			failures++;
		}
	}
	return (failures);
}
