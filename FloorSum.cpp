long long floorSum(int n, int m, int a, int b)
{
    if (n == 0)
        return 0;
    if (m == 0)
        return 0;
    long long ans = (n * (n - 1) / 2) * (a / m) + n * (b / m);
    a %= m;
    b %= m;
    long long newb = (a * n + b) % m, newn = (a * n + b) / m;
    return ans + floorSum(newn, a, m, newb);
}
