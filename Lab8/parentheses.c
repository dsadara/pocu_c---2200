#include "parentheses.h"

size_t get_matching_parentheses(parenthesis_t* parentheses, size_t max_size, const char* str)
{
    const char* s = str;
    parentheses_and_index_t* my_stack;
    size_t stack_element_count = 0;
    size_t parenthesis_array_index = 0;
    size_t parentheses_pair_num = 0;
    size_t i;
    int find_result;

    my_stack = malloc(sizeof(parentheses_and_index_t) * max_size);

    while(*s != '\0') {
        printf("s:%c\n", *s);
        if (*s == '{' || *s == '(' || *s == '[' || *s == '<') {
            if (stack_element_count >= max_size) {
                s++;
                continue;
            }
            my_stack[stack_element_count].parentheses = *s;
            my_stack[stack_element_count++].stack_element_count = s - str;
            printf("stack_element_count: %d\n", s - str);
        }
        

        if (*s == '}') {
            find_result = find_stack_element(my_stack, stack_element_count, '{');
            printf("find_result: %d\n", find_result);
            if (find_result != -1) {
                parentheses[parenthesis_array_index].opening_index = my_stack[find_result].stack_element_count;
                for (i = find_result; i < stack_element_count; i++) {
                    my_stack[i] = my_stack[i + 1];
                }
                stack_element_count--;
                parentheses[parenthesis_array_index++].closing_index = s - str;
                parentheses_pair_num++;
            }
        }
        if (*s == ')') {
            find_result = find_stack_element(my_stack, stack_element_count, '(');
            printf("find_result: %d\n", find_result);
            if (find_result != -1) {
                parentheses[parenthesis_array_index].opening_index = my_stack[find_result].stack_element_count;
                for (i = find_result; i < stack_element_count; i++) {
                    my_stack[i] = my_stack[i + 1];
                }
                stack_element_count--;
                parentheses[parenthesis_array_index++].closing_index = s - str;
                parentheses_pair_num++;
            }
        }
        if (*s == ']') {
            find_result = find_stack_element(my_stack, stack_element_count, '[');
            printf("find_result: %d\n", find_result);
            if (find_result != -1) {
                parentheses[parenthesis_array_index].opening_index = my_stack[find_result].stack_element_count;
                for (i = find_result; i < stack_element_count; i++) {
                    my_stack[i] = my_stack[i + 1];
                }
                stack_element_count--;
                parentheses[parenthesis_array_index++].closing_index = s - str;
                parentheses_pair_num++;
            }
        }
        if (*s == '>') {
            find_result = find_stack_element(my_stack, stack_element_count, '<');
            printf("find_result: %d\n", find_result);
            if (find_result != -1) {
                parentheses[parenthesis_array_index].opening_index = my_stack[find_result].stack_element_count;
                for (i = find_result; i < stack_element_count; i++) {
                    my_stack[i] = my_stack[i + 1];
                }
                stack_element_count--;
                parentheses[parenthesis_array_index++].closing_index = s - str;
                parentheses_pair_num++;
            }
        }
        s++;
    }

    free(my_stack);

    qsort(parentheses, parentheses_pair_num, sizeof(parenthesis_t), comp);

    return parentheses_pair_num;
}


int find_stack_element(parentheses_and_index_t* my_stack, size_t stack_element_count, char element)
{
    char popped_element;
    int is_element_founded = 0;

    printf("stack_element_count:%d\n", stack_element_count);
    if (stack_element_count == 0) {
            return -1;
    }

    do {
        popped_element = my_stack[--stack_element_count].parentheses;    /* (*my_Stack_ptr)[--stack_element_count] */
        if (popped_element == element) {
            is_element_founded = 1;
            break;
        }
    } while (stack_element_count != 0);
    
    if (!is_element_founded) {
        return -1;
    }

    return stack_element_count;
}

int comp(const void *a, const void *b)  
{
    size_t num1 = ((parenthesis_t*)a)->opening_index;    
    size_t num2 = ((parenthesis_t*)b)->opening_index;   

    if (num1 < num2)    
        return -1;     
    
    if (num1 > num2)    
        return 1;       
    
    return 0;   
}
