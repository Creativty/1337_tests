/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:26:09 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 17:43:58 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

typedef struct {
	int			c;
	size_t	len;
} MemsetTest;

int	ft_memset_test(void)
{
	int	failures;
	failures = 0;
	MemsetTest inps[] = {
		{ 'a', 8 },
		{ '\\', 16 },
		{ ' ', 32 },
		{ '\0', 64 },
	};
	for (size_t i = 0; i < (sizeof(inps)/sizeof(inps[0])); i++)
	{
		int failed_ptr = 0;
		int failed_char = 0;

		MemsetTest inp = inps[i];
		char	*s = ft_calloc(inp.len, sizeof(char));
		if (!s)
		{
			log_warning("could not allocate a string for test %zu", i);
			continue;
		}

		void	*t = ft_memset((void *)s, inp.c, inp.len);
		if ((char *)t != s)
			failed_ptr = 1;

		for (int j = 0; j < (int)inp.len; j++)
		{
			if (s[j] != inp.c)
			{
				failed_char = j;
				log_info("mismatching characters: user %c expected %c", s[j], inp.c);
				break;
			}
		}
		if (failed_char || failed_ptr)
		{
			log_error(
				"test %zu: failed_char: %d or failed_ptr: %d",
				i, failed_char, failed_ptr
			);
			failures++;
		}
		free(s);
	}
	return (failures);
}
