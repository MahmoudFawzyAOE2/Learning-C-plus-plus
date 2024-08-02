#include <stdio.h>

void update(int *a,int *b) {
    
    int x = *a;
    x-=*b;
    *a = *a+*b;
    if (x<0) {*b=-x;} else {*b=x;} 
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}