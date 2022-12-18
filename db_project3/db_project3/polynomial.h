#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <fstream>
#include <cstring>
using namespace std;

class Polynomial {
private: 
	int n, max;
	int arr[1000];
	int brr[1000];
public:
	void LoadPolynomial(string& filename) {
		ifstream fin(filename);
		fin >> n;
			for (int i = 0; i < n; i++) {
				fin >> arr[i] >> brr[i];
			}
	}
	void PrintPolynomial() {
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
						if (brr[i] < brr[j]) {
							int temp = brr[i];
							brr[i] = brr[j];
							brr[j] = temp;
							int temp2 = arr[i];
							arr[i] = arr[j];
							arr[j] = temp2;
						}
				}
			}
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " " << brr[i] << endl;
			}
	}
};
#endif
