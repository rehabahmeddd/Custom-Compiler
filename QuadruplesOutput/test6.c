int main() {
    int i = 0;
    int sum = 0;
    
    do {
        sum = sum + i;
        i = i + 1;
    } while (i < 5);
    
    i = 10;
    do {
        sum = sum - 1;
        i = i - 2;
    } while (i > 0);
    
    return sum;
}