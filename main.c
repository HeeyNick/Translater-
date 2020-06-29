#include "translate.h"


int main() {
    system("chcp 65001"); // Смена кодировки в терминале для вывода русского языка

    FILE* un_translate, * vocabulary, * translated;
    vocabulary = fopen("Dictionary.txt", "rt"); // чтений файла
    un_translate = fopen("text_rus.txt", "rt");
    translated = fopen ("text_eng.txt", "w");
    if (vocabulary == NULL ) // проверка на успешность открытия файла
    {
        printf("Не удалось открыть файл(");
        return -1;
    }
    if (un_translate == NULL ) // проверка на успешность открытия файла
    {
        printf("Не удалось открыть файл( Текст для перевода )");
        return -1;
    }
    int i = 0;
    for (i = 0; i < SIZE ; i++)
    {
        fscanf(vocabulary,"%s %s", mass_of_letter[i].word_rus, mass_of_letter[i].word_eng);
    }

    translate_words(un_translate,translated); // функция перевода текста


    fclose(un_translate);
    fclose(translated);

    return 0;
}
