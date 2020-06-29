#ifndef COURSE_WORK_TRANSLATE_H
#define COURSE_WORK_TRANSLATE_H
// подключение заголовочных фалов
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 4

struct vocabulary_ { // структура слов
    char word_rus[30]; // русское слово
    char word_eng[30]; // англ. слово
};

struct vocabulary_ mass_of_letter[SIZE]; // массив структуры

// объявление прототипов функции
void translate_words(FILE* un_translate, FILE* translated);
int serch( FILE* translated , char * word_ , char c);
int is_upper_in_un_translated(char*is_up);


#endif //COURSE_WORK_TRANSLATE_H
