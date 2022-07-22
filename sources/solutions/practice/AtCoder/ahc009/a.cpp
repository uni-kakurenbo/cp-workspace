#include<iostream>
#include<random>

using namespace std;


random_device rd;
default_random_engine eng(rd());
uniform_int_distribution<int> distr1(0, 2);
uniform_int_distribution<int> distr2(0, 1);
uniform_int_distribution<int> distr3(0, 3);
uniform_int_distribution<int> distr4(0, 2);

constexpr char dir[4] = { 'D', 'R', 'U', 'L' };
constexpr char dir_i[4] = { 1, 0, -1,  0 };
constexpr char dir_j[4] = { 0, 1, 0,  -1 };

int Si, Sj, Ti, Tj;
float p;

int i, j;

char put(int d) {
	i += dir_i[d], j += dir_j[d];
	return dir[d];
}


#define STR 85


int main() {
	cin >> Si >> Sj >> Ti >> Tj >> p;

	i = Si, j = Sj;

	for (int i = 0; i < STR; i++) {
		if (distr1(eng) == 0) {
			if (distr2(eng) == 0) cout << put(distr2(eng) + 2) << put(distr2(eng));
			else  cout << put(distr2(eng)) << put(distr2(eng) + 2);
		}
		else {
			cout << put(0) << put(1);;
		}
	}
	int tmp = 200 - STR * 2;
	if (Ti == 19) {
		for (int i = 0; i < tmp/2; i++) {
			if (distr3(eng) == 0) {
				if (distr2(eng) == 0) cout << put(distr2(eng) + 2);
				else  cout << put(distr2(eng));
			} else {
				cout << put(0);
			}
		}
		for (int i = 0; i < tmp/4+3; i++) cout << put(3);
		for (int i = 0; i < tmp/4-3; i++) cout << put(1);
	} else if(Tj == 19) {
		for (int i = 0; i <tmp/2; i++) {
			if (distr3(eng) == 0) {
				if (distr2(eng) == 0) cout << put(distr2(eng) + 2);
				else  cout << put(distr2(eng));
			}
			else {
				cout << put(1);
			}
		}
		for (int i = 0; i < tmp / 4+3; i++) cout << put(2);
		for (int i = 0; i < tmp / 4-3; i++) cout << put(0);

	} else {
		for (int i = 0; i < 200 - STR * 2; i++) {
			if (distr4(eng) > 0) {
				if (distr4(eng) == 0) {
					if (i > Ti) cout << put(0);
					else if (i < Ti) cout << put(2);
					else cout << put(distr3(eng));
				}
				else {
					if (j > Tj) cout << put(3);
					else if (j < Tj) cout << put(1);
					else cout << put(distr3(eng));
				}
			}
			else cout << put(distr3(eng));
		}
	}
	cout << endl;
	return 0;
}
