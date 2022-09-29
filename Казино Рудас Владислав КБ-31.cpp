#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ResultWin(int a, int b, int c, int balance) {
	printf(" -[%d][%d][%d]- ---WIN---", a, b, c);
    printf(" Balance: %d\n", balance);
}

int main() {

    time_t t;
    srand((unsigned)time(&t));

    int a;
    int b;
    int c;
    int price = 100;
    int balance = 5000;
    
    while (balance >= price) {
        a = rand() % 8;
        b = rand() % 8;
        c = rand() % 8;
        balance -= price;
        if (a == 7 && b == 7 && c == 7) {
            balance += 5000;
            printf(" -[%d][%d][%d]- ---Jackpot---", a, b, c);
            printf(" Balance: %d\n", balance);
        }
        else if (a == b && b == c) {
            balance += 1000;
            ResultWin(a,b,c,balance);
        }
        else if (a == 5 || a == 7) {
            balance += 150;
            ResultWin(a,b,c,balance);
        }
        else if (a == 5 && b == 5 || a == 7 && b == 7) {
            balance += 500;
            ResultWin(a,b,c,balance);
        }
        else if (a == 6 && b == 6 && c == 6) {
            printf(" -[%d][%d][%d]- ---LOSE---", a, b, c);
            printf(" Balance: %d\n", balance);
            break;
        }
        else {
            printf(" -[%d][%d][%d]- ---LOSE---", a, b, c);
            printf(" Balance: %d\n", balance);
        }
    }
    return 0;
}
