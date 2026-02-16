#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool est_pair(int n) {
    if (n == 0) {
        return true; // 0 est pair
    }
    return est_impair(n-1); // Appel de est_impair
}

bool est_impair(int n) {
    if (n == 0) {
        return false; // 0 n'est pas impair
    }
    return est_pair(n-1); // Appel de est_pair
}

int main() {
    assert(est_pair(4));
    assert(est_impair(3));
    return 0;
}

