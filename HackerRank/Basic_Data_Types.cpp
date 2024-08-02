#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i;
    long l;
    char ch;
    float f;
    double d;

    scanf("%d %ld %c %f %lf", &i, &l, &ch, &f,&d);
    cout << i <<endl;
    cout << l <<endl;
    cout << ch <<endl;
    printf("%.3f\n", f);
    printf("%*f", 9,d);
    return 0;
}