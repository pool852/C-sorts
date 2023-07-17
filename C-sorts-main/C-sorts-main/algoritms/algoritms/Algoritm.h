#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int summing(int* b, int k);
void min_number(int* a, int n, int* min, int* l);
int otbor_elem(char** a, int n, char param, char*** best);
int linear_search(char** dst, char* source, int size);
int binary_search(char** dst, char* source, int size);
int spisok_bez_povtoreniy(char** name, int n, char*** list);
int spisok_bez_povtoreniy_rate(char** name, int n, char*** list, int** rate);
int spisok_bez_povtoreniy_sum(char** name, int n, int* ch, char*** list, int** sum);
int string_split(char* str, char* razd, char*** res);
int string_split_smart(char* str, char* razd, char*** res);