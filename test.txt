int main() {
    int a = 5;
    int b = 10;
    bool result;

    result = a < b;
    result = a > b;
    result = a <= b;
    result = a >= b;
    result = a == b;
    result = a != b;
    
    result = a < b && a != 0;
    result = a > b || b > 0;
    result = !(a == b);
    
    return 0;
}