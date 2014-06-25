#include <stdio.h>

int main() {

while (1) {

char str[50];
fgets(str, 7 , stdin);
printf("Result: %s\n", str);
sleep(1);
}
return 0;
}

