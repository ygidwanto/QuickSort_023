#include <iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_cout = 0; // number of comparasion
int mov_cout = 0; // number of data movements
int n;

void input() {
	while (true)
	{
		cout << "Memasukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}
}