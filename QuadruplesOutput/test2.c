int main() {
    int a = 5;
    int b = 10;
    int c = 15;
    int d;
    
    d = a + b * c;
    d = (a + b) * c;
    d = a * b + c * a;
    d = (a + b) * (c - a);
    
    return d;
}