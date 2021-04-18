#include <iostream>
using namespace std;

int getMax(int *arr, int n) // фунция для нахождения максимального элемента
{
	int max = arr[0];
		for (int i = 1;i<n;++i)
		{
			if (arr[i] > max)
				max = arr[i];
		}
		return max;
}

void countSort(int* arr, int n)
{
	int* output = new int[n]; //выделяем память под временный массив
	int max = getMax(arr, n); // находим максимальный элемент массива
	int* count = new int[max + 1]; //выделяем память под массив частот

	// заполняем массив нолями
	for(int i= 0; i<max+1;++i)
	{
		count[i] = 0;
	}
	cout << "подсчитываем частоту повторения элементов" << endl;
	for(int i=0;i<n;++i)
	{
		count[arr[i]]++; // подсчитываем частоту повторения элементов
		
	}
	for (int i = 0; i < max+1; i++)
	{
		cout << count[i] << " ";
	}
	cout << endl;
	cout << "вычисляем накопленные частоты" << endl;
	for (int i = 1; i <= max; ++i)
	{
		count[i]+=count[i-1]; // вычисляем накопленные частоты
		cout << count[i] << " ";
	}
	cout << endl;
	cout << "устанавливаем элемент на корректное место во врременный массив" << endl;
	for (int i = n - 1; i >= 0; --i)
	{
		output[count[arr[i]] - 1] = arr[i]; //устанавливаем элемент на корректное место во врременный массив
		cout << output[i] << " ";
		count[arr[i]]--; // уменьшаем частоту, так как уже записали элемент
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}

	delete[]output;// удаляем ненужные массивы
	delete[]count;
}

int main()
{
	setlocale(LC_ALL, "");

	int arr[] = { 3,5,1,2,1,0,5,4 };
	int n = sizeof(arr) / sizeof(arr[0]); //вычисляем размер массива
	countSort(arr, n); //вызываем сортировку

	for (int i = 0; i < n; ++i)//вывод отсортированного массива на экран
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;
}