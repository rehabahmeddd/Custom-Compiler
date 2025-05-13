int main() {
    int sum = 0;
    int i;
    
    for (i = 0; i < 5; i = i + 1) {
        sum = sum + i;
    }
    
    for (i = 10; i > 0; i = i - 2) {
        sum = sum - 1;
    }
    
    return sum;
}