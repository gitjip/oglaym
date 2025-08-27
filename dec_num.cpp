#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define rep(i, j, k) for (int i = j; i <= k; ++i)
#define rrep(i, j, k) for (int i = j; i >= k; --i)
#define clr(a, b) memset(a, b, sizeof(a))
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const int N = 105;
struct dec_num
{
    int a[N] = {};
    dec_num(int num = 0)
    {
        for (int i = 0; i < N && num; ++i)
        {
            a[i] = num % 10;
            num /= 10;
        }
    }
    dec_num(const string &s)
    {
        for (int i = 0; i < s.size(); ++i)
            a[i] = s[s.size() - i - 1] - '0';
    }
    operator string() const
    {
        string res;
        int i = N - 1;
        for (; i > 0 && a[i] == 0; --i)
            ;
        for (; i >= 0; --i)
            res += a[i] + '0';
        return res;
    }
    dec_num operator+(const dec_num &x) const
    {
        dec_num res(0);
        int car = 0;
        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
            sum = a[i] + x.a[i] + car;
            car = sum / 10;
            res.a[i] = sum % 10;
        }
        return res;
    }
    dec_num &operator+=(const dec_num &x)
    {
        return *this = *this + x;
    }
    dec_num operator-(const dec_num &x) const
    {
        dec_num res(0);
        int car = 0;
        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
            sum = a[i] - x.a[i] + car;
            car = (sum + 10) / 10 - 1;
            res.a[i] = (sum + 10) % 10;
        }
        return res;
    }
    dec_num &operator-=(const dec_num &x)
    {
        return *this = *this - x;
    }
    dec_num operator*(int x) const
    {
        dec_num res(*this);
        for (int i = 0; i < N; ++i)
            res.a[i] *= x;
        int car = 0;
        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
            sum = res.a[i] + car;
            car = sum / 10;
            res.a[i] = sum % 10;
        }
        return res;
    }
    dec_num operator*(const dec_num &x) const
    {
        dec_num res(0);
        for (int i = 0; i < N; ++i)
        {
            dec_num tmp = *this * x.a[i] << i;
            res = res + tmp;
        }
        return res;
    }
    dec_num &operator*=(const dec_num &x)
    {
        return *this = *this * x;
    }
    dec_num operator/(const dec_num &x) const
    {
        dec_num res(0);
        dec_num y(*this);
        for (int i = N - 1; i >= 0; --i)
        {
            dec_num z = x << i;
            while (y >= z)
            {
                y -= z;
                res += dec_num(1) << i;
            }
        }
        return res;
    }
    dec_num &operator/=(const dec_num &x)
    {
        return *this = *this / x;
    }
    bool operator==(const dec_num &x) const
    {
        for (int i = 0; i < N; ++i)
        {
            if (a[i] != x.a[i])
                return false;
        }
        return true;
    }
    bool operator!=(const dec_num &x) const
    {
        return !(*this == x);
    }
    bool operator<(const dec_num &x) const
    {
        for (int i = N - 1; i >= 0; --i)
        {
            if (a[i] != x.a[i])
                return a[i] < x.a[i];
        }
        return false;
    }
    bool operator<=(const dec_num &x) const
    {
        return *this < x || *this == x;
    }
    bool operator>(const dec_num &x) const
    {
        for (int i = N - 1; i >= 0; --i)
        {
            if (a[i] != x.a[i])
                return a[i] > x.a[i];
        }
        return false;
    }
    bool operator>=(const dec_num &x) const
    {
        return *this > x || *this == x;
    }
    dec_num operator<<(int x) const
    {
        dec_num res(*this);
        for (int i = N - 1; i >= x; --i)
            res.a[i] = res.a[i - x];
        for (int i = x - 1; i >= 0; --i)
            res.a[i] = 0;
        return res;
    }
    dec_num operator>>(int x) const
    {
        dec_num res(*this);
        for (int i = 0; i < N - x; ++i)
            res.a[i] = res.a[i + x];
        for (int i = N - x; i < N; ++i)
            res.a[i] = 0;
        return res;
    }
    dec_num suffix(int x) const
    {
        dec_num res(*this);
        for (int i = x; i < N; ++i)
            res.a[i] = 0;
        return res;
    }
};
istream &operator>>(istream &is, dec_num &num)
{
    string s;
    is >> s;
    num = s;
    return is;
}
ostream &operator<<(ostream &os, const dec_num &num)
{
    os << string(num);
    return os;
}