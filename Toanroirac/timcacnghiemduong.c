#include <stdio.h>
#define ll long long

ll dem = 0;

void out(ll a[], ll k) {
    for (ll i = 1; i <= k; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
}

void in(ll i, ll a[], ll n, ll k) {
    for (ll j = 0; j <= n; j++) {
        a[i] = j;
        if (i == k) {
            if (j == n) {
                out(a, k);
                dem++;
            }
        } else {
            in(i + 1, a, n - j, k);
        }
    }
}

int main() {
    ll a[100], n, k;
    scanf("%lld %lld", &n, &k);
    in(1, a, n, k);
    printf("Tong so nghiem: %lld\n", dem);
    return 0;
}
