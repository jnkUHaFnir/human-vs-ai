typedef int (*ArbitraryFunc)(int, int, int);

int thunk(ArbitraryFunc func, int arg1, int arg2, int arg3) {
    return func(arg1, arg2, arg3);
}

int main() {
    ArbitraryFunc myFunc = (ArbitraryFunc)0x12345678; // address of arbitrary function
    int result = thunk(myFunc, 1, 2, 3); // call arbitrary function with 3 arguments
    return result;
}
