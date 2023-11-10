/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:19:57 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 16:58:57 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

int ft_isdigit_test(void)
{
	int failures;

	failures = 0;
	for (int i = 0; i < 256; i++)
	{
		int exp = isdigit(i);
		int out = ft_isdigit(i);
		if (exp != out)
		{
			failures++;
			log_error("test %d: user: \"%d\", expected: \"%d\"", i, out, exp);
		}
	}
	return (failures);
}
