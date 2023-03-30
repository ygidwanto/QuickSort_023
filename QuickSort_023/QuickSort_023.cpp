#include <iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_count = 0; // number of comparasion
int mov_count = 0; // number of data movements
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

	cout << "\n===================" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n===================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
 // swaps the element at index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)
		return;                                               // Langkah 1

	//Partition the list into two part:
	//one containing elements less that or equal to pivot
	//Pither conntaining elements greather than pivot 

	pivot = arr[low];                                         // Langkah 2

	i = low + 1;                                              // Langkah 3
	j = high;                                                 // Langkah 4


	while (i <= j)
	{
		//search for an element greater than pivot
		while ((arr[j] <= pivot) && (i <= high))             // Langkah 5
		{
			i++;                                             // Langkah 6
			cmp_count++;
		}
		cmp_count++;
		//search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low))               // Langkah 7
		{
			j--;                                             // Langkah 8
			cmp_count++;
		}
		cmp_count++;

		                                                     // Langkah 9
		if (i < j) // if the greater element is ont the left of the element
		{
			//Swap the element at index i whit the element in at index j
			swap(i, j);
			mov_count++;
		}
	}
	//j now containt the index of the last element in the sorted list
	if (low < j);											// Langkah 11
	{
		//move the pivot to its correct position in the list 
		swap(low, j);
		mov_count++;
	}


	//sort the list list on the left of pivot using quck sort
	q_short(low, j - 1);                                    // Langkah 12
	//Short the list on the right of pivot using quick sort
	q_short(j + 1, high);                                   // Langkah 13

}


void display() {
	cout << "\n=======================" << endl;
	cout << "Sorted Array" << endl;
	cout << "===================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparations: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}


int main()
{

	input();
	//Sort the array using quick sort
	q_short(0, n - 1);
	display();
	system("pause");

	return 0;
}