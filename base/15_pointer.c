int main() {
    int x = 1, y = 2, z[10];  // define some variables
    int *ip;  // a pointer which is pointing to int
    ip = &x;  // ip points to x
    y = *ip;  // y is now 1
    *ip = 0;  // x is now 0
    ip = &z[0];  // ip is now points to z[0]
    return 0;
}