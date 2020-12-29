#pragma once
unsigned long long gcd(unsigned long long u, unsigned long long v) {
    if (v == 0) {
        return u;
    }
    else {
        return gcd(v, u % v);
    }
}