/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:45:25 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 17:48:40 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

int	ft_strlen_test(void)
{
	int	failures;
	failures = 0;
	char const *inps[] = {
		"",
		"H",
		"Hello, world",
		"Maybe a super long string like this who knows maybe it would work, i'm",
	};
	for (size_t i = 0; i < (sizeof(inps)/sizeof(inps[0])); i++)
	{
		char const *inp = inps[i];
		int	exp = strlen(inp);
		int	out = ft_strlen(inp);
		if (out != exp)
		{
			log_error(
				"test %zu: user: %d, expected: %d",
				i, out, exp
			);
			failures++;
		}
	}
	return (failures);
}
