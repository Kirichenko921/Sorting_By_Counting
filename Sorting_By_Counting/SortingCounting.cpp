#include <string>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include <ctime>
#include <chrono> // для получения времени
using namespace std;

void write_arr(const string& filename, const int* arr, const int n)
{
	fstream fs;
	fs.open(filename, fstream::out);
	if (fs.is_open())// проверяем что файл успешно открыт
	{
		fs << n << '\n';//записываем размер массива
		for (int i = 0; i < n; i++)
			fs << arr[i] << ' ';//записываем значения через пробел
		fs << '\n';

		fs.close();//закрываем файл
	}
}

void read_arr(const string& filename, int* arr, int n)
{
	fstream fs;

	fs.open(filename, fstream::in);
	if (fs.is_open())// проверяем что файл успешно открыт
	{
		fs >> n; // читаем размер массива
		arr = new int[n];
		for (int i = 0; i < n; ++i)
			fs >> arr[i];// читаем из файла разделительные символы - пробел и перенос строки

		fs.close();//закрываем файл
	}
}
void swap(int* a, int* b) // функция для смены местами двух значений
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* arr, int low, int high)
{
	int pivot = arr[high]; // опорный элемент
	int i = (low - 1); // индекс наименьшего элемента
	for (int j = low; j <= high - 1; j++)
	{
		// если текущий элемент меньше или равен опорнуму
		if (arr[j] <= pivot)
		{
			i++; // увеличиваем индекс минимального элемента
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
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

	for(int i=0;i<n;++i)
	{
		count[arr[i]]++; // подсчитываем частоту повторения элементов
		
	}
	for (int i = 0; i <= max; ++i)
	{
		cout << count[i] << " ";
	}
	cout << endl;
	
	for (int i = 0, j = 0; i <= max;i++)
	{
		while (count[i]--)
			output[j++] = i;
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
		int arr[] = { 3,5,1,2,1,0,5,4 };
		int n = sizeof(arr) / sizeof(arr[0]); //
		countSort(arr, n); //âûçûâàåì ñîðòèðîâêó

		for (int i = 0; i < n; ++i)//
		{
			cout << arr[i] << " ";
		}

		cout << endl;
		return 0;
	return 0;
}