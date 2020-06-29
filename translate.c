#include "translate.h"

int is_upper_in_un_translated(char*is_up) // функция проверки на верхний регистр первой буквы слова.
{
    if (is_up >= 0 && is_up <= -33) // если буква лежит в диапозоне от 0 до -33 то она верхнего регистра
        return 1; // верхний
    else
        return 0; // нижний

}
int serch(FILE* translated , char * word_ , char c) // функция поиска слова в структуре принимает слово и символ и производит запись в файл
{
    int status = 1; // если статус 0 - то слово уже переведено , если 1 то записыввется русское слово
    int status_of_word = is_upper_in_un_translated(word_[0]); // проврека на верхний регистр
    printf("%d", status_of_word); //Вспомогательный вовод на экран статуса буквы
    int size_of_word_in = strlen(word_); // получение длины слова на входе
    int size_of_word_out; // Переменная длины слова на выход
    for (int i = 0 ; i < SIZE; ++i ) // цикл обхода структуры
    {
        word_[0] = toupper(word_[0]); // Изменение регистра первой буквы входного слова на верхний , т.к слова в словаре начинаются с Верхнего
        char *tmp = (char *) calloc(30, sizeof(char)); // создание временного буфера хранения слова || для поиска слова
        strcpy(tmp, mass_of_letter[i].word_rus); // проверка на наличие слова в Структуре
        if (strcmp(tmp, word_) == 0) // если 0 - то есть
        {
            if (status_of_word == 1) //Если изначальное слово в верхнеем Регисстре то записть в верхнем.
            {
                fprintf(translated, "%s", mass_of_letter[i].word_eng); // запись в файл
            }
            else // иначе будет происходить изменение регистра
            {
                size_of_word_out = strlen(mass_of_letter[i].word_eng); // Получение длина Английского слова
                if (size_of_word_in > size_of_word_out) // если русское слово больше английского , то слово записывается до конца длины английского слова
                {
                    fprintf(translated, "%c", tolower(mass_of_letter[i].word_eng[0])); // Запись буквы в нижнем регистре
                    for(int j = 1; j < size_of_word_out; j++) // цикл для записи остатка слова
                    {
                        fprintf(translated, "%c", mass_of_letter[i].word_eng[j]); // запись остатка слова , граница втроая буква и длина слова
                    }
                } else // Если русское слово < американского , то запись до русского слова
                {
                    fprintf(translated, "%c", tolower(mass_of_letter[i].word_eng[0])); // понижение регистра слова и запись первой буквы
                    for(int j = 1; j < size_of_word_in; j++) //Цикл для Записи остатка слова
                    {
                        fprintf(translated, "%c", mass_of_letter[i].word_eng[j]); // Запись остатка слова
                    }
                }

            }
            status = 0; // изменение статуса на 0
        }
    }
    if (status == 1) // если статутус 1 , то слово не было переведено на Англ.
    {
        if (status_of_word == 1) { //Если изначальное слово в верхнеем Регисстре то записть в верхнем.
            fprintf(translated, "%s", word_); //запись
        }
        else{
            fprintf(translated, "%c", tolower(word_[0])); // понижение регистра  и запись первой буквы
            for(int j = 1; j < size_of_word_in; ++j) //Цикл для Записи остатка слова
            {
                fprintf(translated, "%c", word_[j]);// Запись остатка слова
            }
        }
    }
    fprintf(translated, "%c", c); // Запись символа в файл.
}

void translate_words(FILE* un_translate, FILE* translated) // перевод слов
{
    int letter; // переменная символа
    char* word; // слово для перевода
    word = (char*)calloc(30, sizeof(char)); // выделеение памяти
    int i = 0; // перемнная для записи символов в слово
    while ((letter = fgetc(un_translate)) != EOF) { // Считываем до конца файла символы
        if (strchr(".?, -()[]\n\t", (char) letter)) { // Если встречаются спец.символы, то ищем записаное слово в структуре
            if (strcmp("", word) == 0) { // Если слово пустое, то выводим записанный спец.символ
                fprintf(translated, "%c", (char) letter); // запись символа
            } else { // если слово не пустое , осуществялем поиск
                serch(translated, word, (char) letter); // функция поиска
                free(word); // освобождение памяти
                word = (char *) calloc(30, sizeof(char));// выделеение памяти
                i = 0; // обнуление перемннной
            }
        }
        else // Если не спец.символ, то записывем в слово
        {
            word[i] = (char)letter;  // запись в перменную word
            i++; // переход на новый индекс
        }
    }
    printf("\n");
    printf("Текст успешно переведён!\n");
}