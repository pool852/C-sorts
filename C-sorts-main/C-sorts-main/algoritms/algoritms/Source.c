#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Algoritm.h"

int menu(char** Name_punct, int Number) {
	int result = 0, kod, i = 0;
	system("cls");
	//system("color 3F");
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	do {
		system("cls");
		for (i = 0; i < Number; i++) {
			if (i == result) {
				// изменить цвет на инверсный
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

				printf("%s\n", Name_punct[i]);


				//вернуть цвет
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE);

			}
			else {
				printf("%s\n", Name_punct[i]);
			}
		}
		kod = _getch();
		if (kod == 0) {
			kod = _getch();
		}
		else if (kod == 72) // нажата стрелка вверх
		{
			result--;
			if (result < 0) { result = Number - 1; }
		}
		else if (kod == 80) // нажата стрелка вниз
		{
			result++;
			if (result == Number) { result = 0; }
		}
	} while (kod != 13);

	return result;
}

void alg1() {
	int N;
	int sum;
	int i;
	int* a;
	setlocale(LC_ALL, "rus");
	printf("Введите кол-во чисел: ");
	scanf_s("%d", &N);
	a = (int*)calloc(N, sizeof(int));
	printf("Введите числа: ");
	for (i = 0; i < N; i++) {
		scanf_s("%d", &a[i]);
	}
	sum = summing(a, N);
	printf("Сумма чисел равна %d", sum);
	_getch();
	return 0;
}

void alg2() {
	int* a;
	int n;
	int min, l;

	setlocale(LC_ALL, "rus");

	printf("Введите кол-во чисел: ");
	scanf_s("%d", &n);

	a = (int*)calloc(n, sizeof(int));

	printf("Введите список:\n");

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}

	min = a[0];
	l = 0;

	min_number(a, n, &min, &l);

	printf("Минимальное число: %d Его индекс %d", min, l);
	_getch();
	return 0;
}

void alg3()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	int len;
	int k, i;
	char** name;
	char** best;
	char tmp[255];

	rsize_t l;
	setlocale(LC_ALL, "rus");
	printf("Введите кол-во N:\n");
	scanf("%d", &n);

	name = (char**)calloc(4 * n, sizeof(char*));
	best = (char**)calloc(4 * n, sizeof(char*));

	printf("Введите список\n");
	for (i = 0; i < n; i++)
	{
		scanf("\n");
		fgets(tmp, 255, stdin);
		len = strlen(tmp) + 2;
		l = sizeof(rsize_t);
		name[i] = (char*)calloc(l * len, sizeof(char));
		strcpy(name[i], tmp);
	}
	k = 0;
	for (i = 0; i < n; i++)
	{
		if (name[i][0] == 'A')
		{
			len = strlen(name[i]) + 2;
			l = sizeof(rsize_t);
			best[k] = (char*)calloc(l * len, sizeof(char));
			strcpy(best[k], name[i]);
			k++;
		}
	}
	printf("Список хороших\n");
	for (i = 0; i < k; i++)
	{
		printf("%s", best[i]);
	}
	_getch();
	return(0);
}

void alg4() {
	int N, i, len;
	char** name;
	char* ctrl;
	char tmp[255];

	rsize_t l;

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf_s("Введите кол-во N: ");
	scanf_s("%d", &N);

	name = (char**)calloc(N, sizeof(char*));

	printf("Введи список:\n");

	for (i = 0; i < N; i++) {

		scanf_s("\n");
		fgets(tmp, 255, stdin);
		len = strlen(tmp) + 2;
		l = sizeof(rsize_t);
		name[i] = (char*)calloc(len, sizeof(char));

		strcpy_s(name[i], l * len, tmp);
	}

	printf("Введите искомое слово: ");
	scanf_s("\n");
	fgets(tmp, 255, stdin);

	len = strlen(tmp) + 2;
	//l = sizeof(rsize_t);
	ctrl = (char*)calloc(len, sizeof(char));

	strcpy_s(ctrl, len, tmp);

	printf("Линейный поиск %d\n", linear_search(name, ctrl, N));
	_getch();
	return 0;
}

void alg5() {
	int N, i, len, l;
	char** name;
	char* ctrl;
	char tmp[255];



	setlocale(LC_ALL, "Rus");

	printf("Введите кол-во N: ");
	scanf("%d", &N);

	name = (char**)calloc(4 * N, sizeof(char*));

	printf("Введи список\n");

	for (i = 0; i < N; i++) {

		scanf("\n");
		fgets(tmp, 255, stdin);
		len = strlen(tmp) + 2;
		l = sizeof(rsize_t);
		name[i] = (char*)calloc(l * len, sizeof(char));

		strcpy(name[i], tmp);
	}

	printf("Введите искомое слово\n");
	scanf_s("\n");
	fgets(tmp, 255, stdin);
	len = strlen(tmp) + 2;
	ctrl = (char*)calloc(len, sizeof(char));

	strcpy(ctrl, tmp);
	printf("Бинарный поиск %d\n", binary_search(name, ctrl, N));

	_getch();
	return 0;
}

void alg6() {
	char tmp[255];
	char** name;
	char** list;
	int N;

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	printf("Введите количество элементов: \n");
	scanf("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));

	for (int i = 0; i < N; i++) {
		scanf("%s", &tmp);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy(name, N, &list);

	printf("Список без повторений\n");
	for (int i = 0; i < k; i++) {
		printf("[%d] = %s\n", i, list[i]);
	}
	_getch();
	return 0;
}

void alg7() {
	char tmp[255];
	char** name;
	char** list;
	int* Rate;
	int N;

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	printf("Введите количество элементов: ");
	scanf("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));
	Rate = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%s", &tmp);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy_rate(name, N, &list, &Rate);

	printf("Список без повторений и подсчет рейтинга\n");
	for (int i = 0; i < k; i++) {
		printf("[%d] = %s Его рейтинг %d\n", i, list[i], Rate[i]);
	}
	_getch();
	return 0;
}

void alg8() {
	char tmp[255];
	char** name;
	char** list;
	int* Sum;
	int* CH;
	int N;

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Введите количество элементов: ");
	scanf("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));
	CH = (int*)calloc(N, sizeof(int));
	Sum = (int*)calloc(N, sizeof(int));

	printf("Введите название элемента и его характеристику\n");
	for (int i = 0; i < N; i++) {
		scanf("%s %d", &tmp, &CH[i]);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy_sum(name, N, CH, &list, &Sum);

	printf("Список без повторений и подсчет рейтинга\n");
	for (int i = 0; i < k; i++) {
		printf("[%d] = %s\n Характеристика %d\n", i, list[i], Sum[i]);
	}
	_getch();
	return 0;
}

void alg9() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char data[100];
	char** result;

	printf("Введите строку: ");
	fgets(data, 100, stdin);

	int len = strlen(data) + 2;

	result = (char**)calloc(len, sizeof(char*));

	int k = string_split(data, " ", &result);

	for (int i = 0; i < k; i++) {
		printf("[%d] %s\n", i, result[i]);
	}
	_getch();
	return 0;
}

void alg10() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char data[100];
	char** result;
	char razd[] = ",/.'[]*-+&! ";

	printf("Введите строку: ");
	fgets(data, 100, stdin);

	int len = strlen(data) + 2;

	result = (char**)calloc(len, sizeof(char*));

	int k = string_split_smart(data, razd, &result);

	for (int i = 0; i < k; i++) {
		printf("[%d] %s\n", i, result[i]);
	}
	_getch();
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");

	char** Np;
	int n = 11, m;

	Np = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++) {
		Np[i] = (char*)calloc(10 * n, sizeof(char));
	}
	strcpy(Np[0], "Выход");
	strcpy(Np[1], "Сумма n-чисел");
	strcpy(Np[2], "Поиск минимального элемента массива с определением его места в массиве");
	strcpy(Np[3], "Отбор элемента массива по заданному признаку с формированием нового массива");
	strcpy(Np[4], "Линейный поиск");
	strcpy(Np[5], "Бинарный поиск");
	strcpy(Np[6], "Список без повторений");
	strcpy(Np[7], "Список без повторений + рейтинг");
	strcpy(Np[8], "Список без повторений + характеристика");
	strcpy(Np[9], "Деление строки на слова при помощи одного разделителя");
		strcpy(Np[10], "Деление строки на слова в случае разных разделителей");
	do {
		m = menu(Np, n);

		switch (m) {
		case 0:
			system("exit");
			break;
		case 1:
			system("cls");
			alg1();
			break;
		case 2:
			system("cls");
			alg2();
			break;
		case 3:
			system("cls");
			alg3();
			break;
		case 4:
			system("cls");
			alg4();
			break;
		case 5:
			system("cls");
			alg5();
			break;
		case 6:
			system("cls");
			alg6();
			break;
		case 7:
			system("cls");
			alg7();
			break;
		case 8:
			system("cls");
			alg8();
			break;
		case 9:
			system("cls");
			alg9();
			break;
		case 10:
			system("cls");
			alg10();
			break;
		}
	} while (m != 0);
}
#define _CRT_SECURE_NO_WARNINGS
#include "Algoritm.h"

//Алгоритм 1
int summing(int* b, int k)
{
	int sum;
	int i;
	sum = 0;
	for (i = 0; i < k; i++) {
		sum += b[i];
	}
	return sum;
}

//Алгоритм 2
void min_number(int* a, int n, int* min, int* l) {
	(*min) = a[0];
	(*l) = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < (*min)) {
			(*min) = a[i];
			(*l) = i;
		}
	}
}

//Алгоритм 3
int otbor_elem(char** a, int n, char param, char*** best)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i][0] == param)
		{
			int len = strlen(a[i]) + 2;
			(*best)[k] = (char*)calloc(len, sizeof(char));
			strcpy((*best)[k], a[i]);
			k++;
		}
	}
	return k;
}

//Алгоритм 4
int linear_search(char** dst, char* source, int size) {
	int index = -1;
	int i = 0;

	while (index == -1 && i < size) {

		if (strcmp(dst[i], source) == 0) {
			index = i;
		}

		i++;
	}

	return index;
}

//Алгоритм 5
int binary_search(char** dst, char* source, int size)
{
	int start = 0;
	int finish = size - 1;
	int index = -1;
	int i = 0;

	while (start <= finish)
	{
		int middle = (start + finish) / 2;

		int str_cmp_data = strcmp(source, dst[middle]);

		if (str_cmp_data == 0)
		{
			index = middle;
			break;
		}
		if (str_cmp_data < 0)
		{
			finish = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
	}

	return index;
}

//Алгоритм 6
int spisok_bez_povtoreniy(char** name, int n, char*** list) {
	int k = 0;

	for (int i = 0; i < n; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (strcmp(name[i], (*list)[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			(*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
			strcpy((*list)[k], name[i]);
			k++;
		}
	}
	return k;
}

//Алгоритм 7
int spisok_bez_povtoreniy_rate(char** name, int n, char*** list, int** rate) {
	int k = 0;

	for (int i = 0; i < n; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (strcmp(name[i], (*list)[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			(*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
			strcpy((*list)[k], name[i]);
			(*rate)[k] = 1;
			k++;
		}
		else {
			(*rate)[l] += 1;
		}
	}
	return k;
}

//Алгоритм 8
int spisok_bez_povtoreniy_sum(char** name, int n, int* ch, char*** list, int** sum) {
	int k = 0;

	for (int i = 0; i < n; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (strcmp(name[i], (*list)[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			(*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
			strcpy((*list)[k], name[i]);
			(*sum)[k] = ch[i];
			k++;
		}
		else {
			(*sum)[l] += ch[i];
		}
	}
	return k;
}

//Алгоритм 9
int string_split(char* str, char* razd, char*** res) {

	strcat(str, " ");
	int k = 0;
	while (strlen(str) > 0) {
		int l = strcspn(str, razd);
		if (l > 0) {
			(*res)[k] = (char*)calloc(l + 2, sizeof(char));
			strncpy((*res)[k], str, l);
			k++;
		}
		int len = strlen(str);
		for (int i = 0; i < len - l + 1; i++) {
			str[i] = str[l + i + 1];
		}
	}
	return k;
}

//Алгоритм 10
int string_split_smart(char* str, char* razd, char*** res) {
	char* tmp;
	int len = strlen(str);

	str[len - 1] = ' ';
	str[len] = '\0';

	tmp = (char*)calloc(len + 2, sizeof(char));

	int k = 0;

	strcpy(tmp, "");

	for (int i = 0; i < len; i++) {
		char symb[2] = { str[i], '\0' };
		int l = strcspn(symb, razd);

		if (l > 0) {
			strcat(tmp, symb);
		}
		else {
			if (symb[0] == ' ')
			{
				int tmp_len = strlen(tmp);
				if (tmp_len != 0)
				{
					(*res)[k] = (char*)calloc(tmp_len + 2, sizeof(char));
					strcpy((*res)[k], tmp);
					strcpy(tmp, "");
					k++;
				}
			}
			else {
				int tmp_len = strlen(tmp);
				if (tmp_len != 0) {
					(*res)[k] = (char*)calloc(tmp_len + 2, sizeof(char));
					strcpy((*res)[k], tmp);
					strcpy(tmp, "");
					k++;
				}
				(*res)[k] = (char*)calloc(2, sizeof(char));
				strcpy((*res)[k], symb);
				k++;
			}
		}
	}
	return k;
}