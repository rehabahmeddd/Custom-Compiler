int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int compute(int x, int y) {
    int result = add(x, y);
    result = multiply(result, 2);
    return result;
}

int main() {
    int a = 5;
    int b = 10;
    int result;
    
    result = add(a, b);
    result = multiply(result, 3);
    result = compute(a, b);
    
    return result;
}