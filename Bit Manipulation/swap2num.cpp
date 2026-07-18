void swap(int &a, int &b) {
    a = a^b;
    b = a^b;
    a = a^b;
}

// a = a^b
// b = a^b = (a^b)^b  b and b cancel out = a hence b = a
// a = a^b = (a^b)^(a) as b is now a , a and a cancel, hence a = b;