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

int solver(int x, int y, long long k, vector<int> a) {
    k *= y;
    int ans = 0;
    sort(a.begin(), a.end());
    for(int v : a) {
        k -= 1LL * x * v;
        if(k < 0) break;
        ++ans;
    }
    debug(k, ans);
    return ans;
}

signed main() {
    string dirName_in = "./testcases/in";
    string dirName_out = "./testcases/out";

    string fileName; cin >> fileName;
    ofstream ofs_in(dirName_in + "/" + fileName), ofs_out(dirName_out + "/" + fileName);

    int N; cin >> N;
    int MAX_A, MAX_Y; cin >> MAX_A >> MAX_Y;

    uniform_int_distribution<int>
        distr_N(1, 400000), distr_A(1, MAX_A), distr_Y(1, MAX_Y);

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

    uniform_int_distribution<long long> distr_K(1, sum_A * p * 1.5);

    long long K = distr_K(engine);

    debug(N, X, Y, K, sum_A, p);
    debug(K * Y, sum_A * X);

    ofs_in << N << " " << X << " " << Y  << " " << K << "\n";
    for(int i=0; i<N; i++) ofs_in << A[i] << " ";
    ofs_in << "\n";

    int ans = solver(X,Y,K,A);
    ofs_out << ans << "\n";

    return 0;
}
