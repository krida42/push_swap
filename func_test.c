/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:16:56 by kisikaya          #+#    #+#             */
/*   Updated: 2022/03/22 19:57:04 by kisikaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
void	func_test(t_stack **s_a, t_stack **s_b)
{
	// a = 54 23 43
	printf("len(s_a) 3 == %d\n", stack_len(s_a));
	printf("len(s_b) 0 == %d\n", stack_len(s_b));
	printf("is_sorted 0 == %d\n\n", is_sorted(s_a));

	printf("- - - \n(push_b)\n\n");
	push_b(&s_a, &s_b);
	prst("a", s_a);
	prst("b", s_b);
	printf("len(s_a) 2 == %d\n", stack_len(s_a));
	printf("len(s_b) 1 == %d\n", stack_len(s_b));

	printf("is_sorted 1 == %d\n\n", is_sorted(s_a));


	printf("- - - \n(push_a)\n\n");
	push_a(&s_a, &s_b);
	prst("a", s_a);
	prst("b", s_b);
	printf("len(s_a) 3 == %d\n", stack_len(s_a));
	printf("len(s_b) 0 == %d\n", stack_len(s_b));
	printf("is_sorted 0 == %d\n\n", is_sorted(s_a));
	int	i = -1;
	while(++i < 3)
	{
	printf("\n- - - - -\n");
	printf("(rotate_a)\n");

	rotate_a(&s_a, 1);
	prst("a", s_a);
	prst("b", s_b);

	}
	printf("len(s_a) 3 == %d\n", stack_len(s_a));
	printf("len(s_b) 0 == %d\n", stack_len(s_b));

	printf("get_el(s_a, 0) 54 == %d\n", get_el(s_a, 0)->val);
	printf("get_el(s_a, 1) 23 == %d\n", get_el(s_a, 1)->val);
	printf("get_el(s_a, 2) 43 == %d\n\n", get_el(s_a, 2)->val);


	//normaly generate error 
	// - - -
	//printf("get_el(s_a, 3) = %d\n", get_el(s_a, 3)->val);

	//printf("\nget_el(s_b, 0) = %d\n", get_el(s_b, 0)->val);
	//printf("get_el(s_b, 1) = %d\n", get_el(s_b, 1)->val);
	// - - 

	printf("get_index(s_a, get_el(s_a, 0)) 0 == %d\n", 
	get_index(s_a, get_el(s_a, 0)));
	printf("get_index(s_a, get_el(s_a, 1)) 1 == %d\n", 
	get_index(s_a, get_el(s_a, 1)));
	printf("get_index(s_a, get_el(s_a, 2)) 2 == %d\n", 
	get_index(s_a, get_el(s_a, 2)));
	//printf("get_index(s_b, get_el(s_a, 0)) = %d\n", 
	get_index(s_b, get_el(s_a, 0)));
	//printf("get_index(s_a, NULL) = %d\n", get_index(s_a, NULL));

	printf("s_a->val = %d\n", s_a->val);
	printf("s_a->next->val = %d\n", s_a->next->val);
	printf("get_first(s_a->next)->val = %d\n", get_first(s_a->next)->val);

	add_to(&s_a, 0, 10);
	prst("add_to(&s_a, 0, 10) :", s_a);

	add_to(&s_a, 1, 34);
	prst("add_to(&s_a, 1, 34) :", s_a);


	reverse_a(&s_a, 1);
	prst("a", s_a);
	reverse_a(&s_a, 1);
	prst("a", s_a);
	reverse_a(&s_a, 1);
	prst("a", s_a);
	rotate_a(&s_a, 1);
	prst("a", s_a);
	move_to_first(&s_a, get_el(s_a, 2));



	push_b(&s_a, &s_b);
	t_stack	*cui = find_max(s_a);
	printf("find_max(s_a) : %d\n", cui->val);

	//	printf("\n- - - - - - -\n");
//	prst("a", s_a);
//	prst("b", s_b);
//	printf("- - - - - - - -\n\n");

//	push_b(&s_a, &s_b);
//	push_b(&s_a, &s_b);
//	push_b(&s_a, &s_b);
//	push_b(&s_a, &s_b);
	//rotate_a(&s_a, 0);
	//reverse_a(&s_a, 1);
//	printf("abs : %d   %d\n",get_abs(7612376), get_abs(-872));
//	printf("are same sign, %d, %d, %d, %d\n", are_same_sign(-2, -3), 
	are_same_sign(1, 453), are_same_sign(-34 , 4), are_same_sign(543, -2));


//	printf("greater of  : %d\n", find_greater(s_a, get_el(s_a, 0))->val);
//	t_stack	*king = get_king_tags(s_a);
//	printf("the king is : %d\n", king->val);


	//printf("is sortted nof = %d\n", is_sorted_nof(s_a));
	
}

void	prst(char *s, t_stack *stack)
{
	printf("%s : ", s);
	if (!stack)
	{
		printf("VIDE\n");
		return ;
	}
	while (stack)
	{
		printf("%d  ", stack->val);
		stack = stack->next;
	}
	printf("\n");
}

*/
