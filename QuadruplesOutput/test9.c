int main() {
    int choice = 2;
    int result = 0;
    
    switch (choice) {
        case 1:
            result = 10;
            // Fall-through to case 2
        case 2:
            result = result + 20;
            break;
        case 3:
            result = 30;
            break;
        default:
            result = -1;
            break;
    }
    
    return result;
}