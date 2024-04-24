int main() {
    struct x arr[5];
    for(int i = 0; i < 5; i++) {
        scanf("(%d,%d)", &arr[i].a, &arr[i].b);
    }
    for(int i = 0; i < 5; i++) {
        printf("(%d,%d) ", arr[i].a, arr[i].b);
    }
    return 0;
}
(1828,299) (2729,2553) (2797,2929) (2200,1383) (2894,876) 
