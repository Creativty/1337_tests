/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:01:08 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 17:12:45 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

typedef struct {
	char const *str;
	int c;
	size_t n;
} ManchrTest;

int	ft_memchr_test(void)
{
	int failures = 0;
	ManchrTest inps[] = {
		{ NULL, 'a', 0 },
		{ "", 'a', 1 },
		{ "H", 'a', 2 },
		{ "H", 'H', 2 },
		{ "Hello, world", 'H', 12 },
		{ "Hello, world", 'o', 12 },
		{ "Hello, world", 'd', 12 },
	};

	for (size_t i = 0; i < (sizeof(inps)/sizeof(inps[0])); i++)
	{
		char const *exp =	memchr(inps[i].str, inps[i].c, inps[i].n);
		char const *out = ft_memchr(inps[i].str, inps[i].c, inps[i].n);
		if (exp != out)
		{
			log_error("test %zu: user: \"%s\", expected: \"%s\"", i, out, exp);
			failures++;
		}
	}

	return (failures);
}
