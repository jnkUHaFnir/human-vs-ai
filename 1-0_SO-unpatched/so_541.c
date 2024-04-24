    #include <stdio.h>
    #include <stdlib.h>
    
    struct x{
        int a;
        int b;
    };
    
    int count(const char *s){
        if(s == NULL ||  *s != '(')
            return 0;//bad
        int n, a, b, count = 0;
        for(;;){
            if(2!=sscanf(++s, "(%d,%d)%n", &a, &b, &n)){
                return 0;
            } else {
                s += n;
                ++count;
                if(*s == ',')
                    continue;
                else if(*s == ')')
                    return count;
                else
                    return 0;
            }
        }
    }
    void set(struct x *a, const char *s){
        int n, c = 0;
        while(2==sscanf(++s, "(%d,%d)%n", &a[c].a, &a[c].b, &n)){
            s += n;
            ++c;
        }
    }
    
    int main(void) {
        char *input = "((1828,299),(2729,2553),(2797,2929),(2200,1383),(2894,876))";
        int i, n = count(input);
        if(n == 0){
            printf("invalid format!\n");
            exit(EXIT_FAILURE);
        }
        struct x arr[n];
        set(arr, input);
        for(i = 0; i < n; ++i){
            printf("(%4d, %4d)\n", arr[i].a, arr[i].b);
        }
    
        return 0;;
    }