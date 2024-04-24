    int evaluate_add_expression( char const *in_string, int *out_value ) {
        int lhs, rhs;
    
        if ( sscanf( in_string, " %d + %d ", &lhs, &rhs ) != 2 ) return 1;
    
        *out_value = lhs + rhs;
    
        return 0;
    }