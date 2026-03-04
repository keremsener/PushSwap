/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:47:20 by ksener            #+#    #+#             */
/*   Updated: 2026/03/04 11:43:08 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void    test_print(t_list *a_head, t_list *b_head)
{
    int wlcount = 8;

    printf("\n\na b\n___\n");
    while (wlcount--)
    {
        if (a_head != NULL)
        {
            printf("%d", *(int *)a_head->content);
            a_head = a_head->next;
        }
        else
            printf(" ");
        if (b_head != NULL)
        {
            printf(" %d", *(int *)b_head->content);
            b_head = b_head->next;
        }
        else
            printf(" ");
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    t_list  *a_head;
    t_list  *b_head;
    int     i;
    int     j;
    char    **split_args;
    int     *val;

    if (argc < 2)
        return (0);
    i = 1;
    a_head = NULL;
    b_head = NULL;
    while (i < argc)
    {
        split_args = ft_split(argv[i], ' ');
        j = 0;
        while (split_args[j])
        {
            val = (int *)malloc(sizeof(int));
            if (!val)
                return (1);
            *val = ft_atoi(split_args[j]);
            ft_lstadd_back(&a_head, ft_lstnew(val));
            free(split_args[j]);
            j++;
        }
        free(split_args);
        i++;
    }
    insertion_sort(&a_head, &b_head);
    test_print(a_head, b_head);
    return (0);
}