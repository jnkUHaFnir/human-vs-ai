struct X { int x; };

X Fun() {
    return X();  
}

int main() {
    X x = Fun(); 
}
void Fun(X x) {}

int main() {
    Fun(X());
}
