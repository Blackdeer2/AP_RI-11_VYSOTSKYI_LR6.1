#include <iostream>
#include <time.h>
using namespace std;

void Create(int* mas, const int n, int A, int B, int i)
{
	mas[i] = A + rand() % (B - A + 1);
	if (i < n - 1)
		Create(mas, n, A, B, i + 1);
}
void Print(int* mas, const int n, int i) {
	cout << " " << mas[i];
	if (i < n - 1)
		Print(mas, n, i + 1);
	else cout << endl;
}
int Sum(int* mas, const int i, int s) {
	if (mas[i] > 0 && i % 5 != 0) {
		s += mas[i];
	}
	if (i < 0)
		return s;
	else
		return  Sum(mas, i - 1, s);
	
}
int Number(int* mas, const int n, int i, int num) {
	if (mas[i] > 0 && i % 5 != 0) {
		num += 1;
	}
	if (i < n) {
			return Number(mas, n, i + 1, num);
	}
	else {
		return num;
	}
}
void Zamina_0(int* mas, const int n, int i) {
	if (mas[i] > 0 && i % 5 != 0){
		mas[i] = 0;
	}
	if (i < n) 
		Zamina_0(mas, n, i + 1);
	else cout << endl;
	
}

int main()
{
	srand((unsigned)time(NULL));

	const int a = 20;
	int A[a];
	Create(A, a, -20, 50, 0);
	Print(A, a, 0);
	cout << "Suma = " << Sum(A, a,0)<< endl;
	cout << "Number = " << Number(A, a, 0, 0);
	Zamina_0(A, a, 0);
	cout << "Zamina_0 = ";
	Print(A, a, 0);
	return 0;
}