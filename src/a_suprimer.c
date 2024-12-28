#include "push_swap.h"

//pour tester le bon deroulement de push a
void print_stack(t_stack *stack)
{
    t_node *tmp;

    if (!stack || !stack->top) // Vérifie si la pile est valide et non vide
    {
        ft_printf("\033[31mLa pile est vide ou invalide.\033[0m\n");
        return;
    }
    tmp = stack->top;
    while (tmp)
    {
        ft_printf("%d\t", tmp->value);
        tmp = tmp->next;
    }
    ft_printf("\n");
}
