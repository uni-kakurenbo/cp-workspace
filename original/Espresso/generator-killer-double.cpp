/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ GCC */

#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) Debug::debug(Debug::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { Debug::DEBUG(nullptr, "\033[3;35m#" + to_string(__LINE__) + "\033[m  "); Debug::DEBUG(__VA_ARGS__); Debug::DEBUG(nullptr, "\033[m\n"); } while(0);
#else
    #define debug(...) { ; }
    #define DEBUG(...) { ; }
#endif

#include <bits/stdc++.h>
using namespace std;

random_device rd;
default_random_engine engine(rd());

#define float double

int solver(int x, int y, long long k, vector<int> &a) {
    k *= y;
    int ans = 0;
    for(int v : a) {
        k -= 1LL * x * v;
        if(k < 0) break;
        ++ans;
    }
    // debug(k, ans);
    return ans;
}

int wrong_solver(int x, int y, long long kk, vector<int> &a) {
    float k = kk;
    int ans = 0;
    float p = (float)x/(float)y;
    for(int v : a) {
        k -= p * (float)v;
        if(k < 0) break;
        ++ans;
    }
    // debug(k, ans);
    return ans;
}



signed main() {
    string dirName_in = "./testcases/in";
    string dirName_out = "./testcases/out";

    string fileName; cin >> fileName;
    ofstream ofs_in(dirName_in + "/" + fileName), ofs_out(dirName_out + "/" + fileName);

    uniform_int_distribution<int>
        distr_N(1, 400000), distr_A(1, 1000000000), distr_Y(1, 1000);
    int N; cin >> N;

    retry:

    int Y = distr_Y(engine);
    uniform_int_distribution<int> distr_X(0, Y);
    int X = distr_X(engine);

    long double p = ( (long double)X / (long double)Y );

    vector<int> A(N);
    long long sum_A = 0;
    for(int i=0; i<N; i++) {
        A[i] = distr_A(engine);
        sum_A += A[i];
    }

    long long K = sum_A * p;

    auto B = A;
    sort(B.begin(), B.end());

    uniform_int_distribution<long long> distr_K(1, K/2);

    for(int c=0; c<500; c++) {
        long long k = distr_K(engine), p_ans = 0;
        long long d = 100000000;
        for(int i=0; i<K; i++) {
            // debug(k);
            long long ans = solver(X,Y,k,B);
            if(d == 0) {
                break;
            }
            if(ans != wrong_solver(X,Y,k,B)) {
                debug(N, X, Y, K, sum_A, p);
                debug(K * Y, sum_A * X);
                debug(ans);

                ofs_in << N << " " << X << " " << Y  << " " << k << "\n";

                for(int i=0; i<N; i++) ofs_in << A[i] << " ";
                ofs_in << "\n";

                ofs_out << ans << "\n";

                // debug(k);
                return 0;
            };
            if(p_ans != ans) {
                // debug(d);
                d /= 10;
                d *= -1;
            }
            p_ans = ans;
            k += d;
        }
        // debug(k);
    }
    goto retry;

    return 0;
}
