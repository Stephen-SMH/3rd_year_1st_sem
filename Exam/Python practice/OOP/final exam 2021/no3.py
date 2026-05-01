def count_operands_in_expr(expr):
    # Base case: if expr is not a tuple, it is an operand
    if not isinstance(expr, tuple):
        return 1
    
    # Recursive case: expr is a tuple representing an infix expression
    left_expr, operator, right_expr = expr
    
    # Recursively count operands in the left and right sub-expressions
    left_count = count_operands_in_expr(left_expr)
    right_count = count_operands_in_expr(right_expr)
    
    # Return the total count of operands in both sub-expressions
    return left_count + right_count

# Test cases
print(count_operands_in_expr((3, '**', 4)))  # Output: 2
print(count_operands_in_expr(((((2, '+', 4), '/', 3), '*', 2), '+', (3, '**', 4))))  # Output: 6
