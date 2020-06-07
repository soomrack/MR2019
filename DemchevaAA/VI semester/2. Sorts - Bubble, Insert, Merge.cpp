#include <iostream>

using namespace std;

void InsertionSort(int *Array, const int Size)
{
  //Массив из одного элемента считается отсортированным
	if (Size == 1) 
		return;

  //Если в массиве больше 1 элемента
	for (int KeyCounter = 1; KeyCounter < Size; KeyCounter++)//Поочередно находим место для каждого элемента входного массива
	{
	    int i = KeyCounter;
	    while ((i > 0) && (Array[i] < Array[i-1]))//Меняем местами элементы, если они стоят в неправильной последовательности
	    {
	    	swap(Array[i], Array[i-1]);
	    	i--;
	    }	
	}
 
 //Вывод для проверки	
	for (int counter = 0; counter < Size; counter++)
	{
		printf("%d ", Array[counter]);
	}
	return;
}



void BubbleSort(int* Array, const int Size)
{
	//Массив из одного элемента считается отсортированным
	if (Size == 1)
		return;

	//Если в массиве больше 1 элемента
	int SwapCounter = 1;

	while (SwapCounter == 1)
	{
		SwapCounter = 0;
		for (int Counter = 0; Counter < Size; Counter++)
		{
			if (Array[Counter + 1] < Array[Counter])
			{
				swap(Array[Counter + 1], Array[Counter]);
				SwapCounter = 1;
			}
				
		}
	}
	
	//Вывод для проверки	
	for (int counter = 0; counter < Size; counter++)
	{
		printf("%d ", Array[counter]);
	}

	return;
}



void MergeSort(int* Array, const int Size)
{
	int Step = 2; //Размер подмассива (число эл-в в нем) после слияния
	int Result[8] = {0}; //Буфер для хранения отсортированных частей

	int Limit = 0;//Ограничение для перезаписи элементов из одного массива в другой (если число эл-в нечетное)
	if ((Size % 2) == 1)
		Limit = Size - 1;
	else
		Limit = Size;


	for (int Counter = 0; Counter < Size; Counter++) //Копируем в Result исходный массив
	{
		Result[Counter] = Array[Counter];
	}


	while (Step <= Size)
	{
		int ResultCounter = 0;
		int i = 0;//Счетчик отсортированных частей массива
		while (i < (Size / Step))
		{
			int LeftBorder = Step * i;  //Определяем границы сортировки
			int RightBorder = LeftBorder + Step;
			int Middle = LeftBorder + (Step / 2);

			int LeftCounter = LeftBorder; //Счетчики для каждой из двух сравниваемых подчастей массива
			int RightCounter = Middle;


			while ((LeftCounter < Middle) && (RightCounter < RightBorder))//Сливаем две части массива
			{
				if (Array[LeftCounter] < Array[RightCounter])
				{
					Result[ResultCounter] = Array[LeftCounter];
					ResultCounter++;
					Result[ResultCounter] = Array[RightCounter];
				}
				else
				{
					Result[ResultCounter] = Array[RightCounter];
					ResultCounter++;
					Result[ResultCounter] = Array[LeftCounter];
				}
				ResultCounter++;
				LeftCounter++;
				RightCounter++;
			}
			i++;
		}

		for (int Counter = 0; Counter < Limit; Counter++)//Переносим результат сортировки обратно в Array
		{
			Array[Counter] = Result[Counter];
			Result[Counter] = 0;
		}
		Step = Step * 2;//Увеличиваем шаг в два раза
	}

	if ((Size % 2) == 1)//Если массив содержит нечетное число элементов
	{
		int Counter2 = 0;
		while (Array[Counter2] < Array[Size - 1])//Переносим в Result уже отсортированную часть массива
		{
			Result[Counter2] = Array[Counter2];
			Counter2++;
		}
		Result[Counter2] = Array[Size - 1];//Записываем в нужное место в Result оставшийся элемент
		Counter2++;
		for (; Counter2 < Size; Counter2++)////Переносим в Result оставшуюся отсортированную часть
		{
			Result[Counter2] = Array[Counter2 - 1];
		}

		for (int Counter = 0; Counter < Size; Counter++)//Сохраняем результат обратно в Array
	    {
	    	Array[Counter] = Result[Counter];
	    	Result[Counter] = 0;
	    }
	}
	
	for (int counter = 0; counter < Size; counter++)//Вывод для проверки
	{
		printf("%d ", Array[counter]);
	}

	return;
}





int main()
{
	//int array[7] = {3,2,-1,10,15,-2,0};
	//InsertionSort(array, 5);
	//BubbleSort(array, 5);
	int array[8] = { 13, 3, 8, 1, 15, 2, 3, 7};
	MergeSort(array, 8);


	return 0;
}
