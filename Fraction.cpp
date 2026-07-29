struct Fraction
{
    int a, b;
    Fraction(int a, int b) : a(a), b(b) {}
    Fraction() : a(0), b(1) {}
    Fraction(int a) : a(a), b(1) {}
    inline Fraction operator+(Fraction f) const
    {
        Fraction ans;
        ans.a = a * f.b + b * f.a;
        ans.b = f.b * b;
        int g = __gcd(ans.a, ans.b);
        ans.a /= g;
        ans.b /= g;
        return ans;
    }
    inline Fraction operator-(Fraction f) const
    {
        Fraction ans;
        ans.a = a * f.b - b * f.a;
        ans.b = f.b * b;
        int g = __gcd(ans.a, ans.b);
        ans.a /= g;
        ans.b /= g;
        return ans;
    }
    inline bool operator<(Fraction f) const
    {
        return a * f.b < f.a * b;
    }
    inline bool operator>(Fraction f) const
    {
        return a * f.b > f.a * b;
    }
};
