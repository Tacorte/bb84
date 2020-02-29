#include <iostream>
#include <chrono>
#include <random>

using namespace std;


int main()
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	std::mt19937 generator(seed);
	int A[1000] = { 0 };
	int B[1000] = { 0 };
	int BOB[1000] = { 0 };
	int result[1000] = { 0 }; 
	int sigma, n;
	cout << "enter gamma, n" << endl;
	cin >> sigma >> n;

	cout << "Random bits:" << endl;
	for (int i = 1; i <= (4 + sigma) * n; i++) {
		A[i] = generator() % 2;
		cout << A[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= (4 + sigma) * n; i++) {
		B[i] = generator() % 2;
		cout << B[i] << " ";
	}
	cout << endl;
	cout << "crypt send:" << endl;

	for (int i = 1; i <= (4 + sigma) * n; i++) {
		if (B[i] == 0) {
			if (A[i] == 0) cout << "|0>";
			else cout << "|1>";
		}
		else if (A[i] == 0) cout << "|+>";
		else cout << "|->";
	}
	cout << endl<<"Bobs random generate:"<< endl;
	for (int i = 1; i <= (4 + sigma) * n; i++) {
		BOB[i] = generator() % 2;
		cout << BOB[i] << " ";
	}
	cout << "\nCheck result:\n";
	for (int i = 1; i <= (4 + sigma) * n; i++) {
		if (BOB[i] == B[i]) {
			result[i] = 1;
			cout << "1 ";
		}
		else {
			cout << "0 ";
			result[i] = 0;
		}
	}
	cout << "\nResult secret key:\n";
	for (int i = 1; i <= (4 + sigma) * n; i++) {
		if (result[i] == 1)
			cout << A[i] << " ";
	}

}
