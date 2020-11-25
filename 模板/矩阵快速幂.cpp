struct Matrix {
    ll a[5][5];
    Matrix() { memset(a, 0, sizeof a); } // 
    Matrix operator*(const Matrix &b) const {
        Matrix res;
        for (int i = 1; i <= 4; ++i)  //长度为4的矩阵相乘
            for (int j = 1; j <= 4; ++j)
                for (int k = 1; k <= 4; ++k)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
        return res;
    }
} ans, base;
void qpow(int b) { //快速幂
    while (b) {
        if (b & 1) ans = ans * base;
        base = base * base;
        b >>= 1;
    }
}