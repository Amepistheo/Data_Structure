#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

class Polynomial {
private:
	int n;
	int arr[1000];
	int brr[1000];
	int c[1000];  //계수
	int d[1000];  //지수
	int h, j, t=0, tmp=0;

public:
	void LoadPolynomial(string& filename) {
		ifstream fin(filename);
		fin >> n;
		if (n > 0) {
			for (int i = 0; i < n; i++) {
					fin >> arr[i] >> brr[i];
			}
		}
	}
	void add(Polynomial a, Polynomial b) {
		int h = a.n;
		int j = b.n;
		if (a.n >= b.n) {
			for (int i = 0; i < a.n; i++) {
				for (int j = 0; j < b.n; j++) {
					if (a.brr[i] != b.brr[j]) {
						tmp++;
					}
					else if (a.brr[i] == b.brr[j]) {
						c[i] = a.arr[i] + b.arr[j];
						d[i] = a.brr[i];
						tmp = 0;
					}
				}
				if (tmp == b.n) {
					c[i] = a.arr[i];
					d[i] = a.brr[i];
				}
				tmp = 0;
			}
			for (int j = 0; j < b.n; j++) {
				for (int i = 0; i < a.n; i++) {
					if (b.brr[j] != a.brr[i]) {
						c[a.n + t] = b.arr[j];
						d[a.n + t] = b.brr[j];
						t++;
					}
				}
			}
		}
		else if (a.n < b.n) {
			for (int i = 0; i < b.n; i++) {
				for (int j = 0; j < a.n; j++) {
					if (b.brr[i] != a.brr[j]) {
						tmp++;
					}
					else if (b.brr[i] == a.brr[j]) {
						c[i] = b.arr[i] + a.arr[j];
						d[i] = b.brr[i];
						tmp = 0;
					}
				}
				if (tmp == a.n) {
					c[i] = b.arr[i];
					d[i] = b.brr[i];
				}
				tmp = 0;
			}
			for (int j = 0; j < a.n; j++) {
				for (int i = 0; i < b.n; i++) {
					if (a.brr[j] != b.brr[i]) {
						c[b.n + t] = a.arr[j];
						d[b.n + t] = a.brr[j];
						t++;
					}
				}
			}
		}
	}
	void PrintPolynomial() {
			for (int i = 0; i < h+j-1; i++) {
				for (int j = i + 1; j < h+j; j++) {
					if (d[i] >= 0) {
						if (d[i] < d[j]) {
							int temp = d[i];
							d[i] = d[j];
							d[j] = temp;
							int temp2 = c[i];
							c[i] = c[j];
							c[j] = temp2;
						}
					}
					else {
						if (d[i] > d[j]) {
							int temp = d[i];
							d[i] = d[j];
							d[j] = temp;
							int temp2 = c[i];
							c[i] = c[j];
							c[j] = temp2;
						}
					}
				}
			}
			for (int i = 0; i < h + j; i++) {
				if (c[i] != 0)
					cout << c[i] << " " << d[i] << endl;
				else
					continue;
			}
	}
};
#endif
