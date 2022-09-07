template<typename T>
T power(T a, int b) {
    T res = 1;
    for (; b; b >>= 1, a *= a)
        if (b & 1) res *= a;
    return res;
}

template<const int mod = 998244353>
struct mint {
    typedef long long ll;

    int x;

    // assume -mod <= x < 2 * mod
    int norm(int x) {
        if (x < 0) x += mod;
        if (x >= mod) x -= mod;
        return x;
    }

    mint(int x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}

    int val() const {
        return x;
    }
    mint operator - () const {
        return mint(norm(mod - x));
    }
    mint inv() const {
        assert(x != 0);
        return power(*this, mod - 2);
    }

    bool operator < (const mint& rhs) const {
        return x < rhs.x;
    }
    bool operator == (const mint& rhs) const {
        return x == rhs.x;
    }
    bool operator != (const mint& rhs) const {
        return x != rhs.x;
    }

    mint& operator *= (const mint& rhs) {
        x = 1ll * x * rhs.x % mod;
        return *this;
    }
    mint& operator += (const mint& rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    mint& operator -= (const mint& rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    mint& operator /= (const mint& rhs) {
        return *this *= rhs.inv();
    }

    friend mint operator * (const mint& lhs, const mint& rhs) {
        mint res = lhs;
        res *= rhs;
        return res;
    }
    friend mint operator + (const mint& lhs, const mint& rhs) {
        mint res = lhs;
        res += rhs;
        return res;
    }
    friend mint operator - (const mint& lhs, const mint& rhs) {
        mint res = lhs;
        res -= rhs;
        return res;
    }
    friend mint operator / (const mint& lhs, const mint& rhs) {
        mint res = lhs;
        res /= rhs;
        return res;
    }

    friend std::istream& operator >> (std::istream& is, mint& a) {
        ll v;
        is >> v;
        a = mint(v);
        return is;
    }
    friend std::ostream& operator << (std::ostream& os, const mint& a) {
        return os << a.val();
    }
};