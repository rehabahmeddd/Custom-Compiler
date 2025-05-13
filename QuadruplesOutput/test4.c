int main() {
    int x = 10;
    int y = 20;
    int result = 0;
    
    if (x > y) {
        result = x;
    } else {
        result = y;
    }
    
    if (x == 10) {
        result = result + 5;
    }
    
    if (y < 10) {
        result = result + 1;
    } else if (y < 15) {
        result = result + 2;
    } else {
        result = result + 3;
    }
    
    return result;
}