#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RAND 25

/**
 * Функция ввода числа с дополнительной валидацией 
 * 
 * @return int
 */
int scanNumber(void)
{
    int result = 0;
    int num    = 0;

    printf("Введите число N: ");
    scanf("%d", &num);
    getchar();

    if (num > MAX_RAND || num < 1) {
        printf("Число не может быть меньше единицы или больше %d \n", MAX_RAND);
        num = scanNumber();
    }
    result = num;

    return result;
}

/**
 * Получение случайного символа [A-Z, 0-9]
 * 
 * @return char
 */
char generateChar(void)
{
    // 48-57 => [0-9]
    // 65-90 => [A-Z]

    int  randomCode = 48 + rand()%42;
    char result;
    
    if (randomCode > 57 && randomCode < 65)
        randomCode = generateChar();
    else
        result = (char)randomCode;

    return result;
}

/**
 * Получение строки из случайных символов [A-Z, 0-9] 
 * 
 * @param int lenght
 * 
 * @return char*
 */
char* generateString(int lenght)
{
    char* result = malloc(sizeof(char) * (MAX_RAND + 1));

    for (int i = 0; i < lenght; i++) {
        result[i] = generateChar();
    }

    result[lenght] = '\0';
    return result;
}

/**
 * Заменяет все цифры в строке на введенный символ
 * 
 * @param char* string
 * @param char  replace
 * 
 * @return char*
 */
char* replaceDigits(char* string, char replace)
{
    char* result = string;
    int   lenght = strlen(string);

    // 48-57 => [0-9]

    for (int i = 0; i < lenght; i++) {
        if ((int)string[i] >= 48 && (int)string[i] <= 57)
            result[i] = replace;
    }

    return result;
}

/**
 * Заменяет все буквы в строке на введенный символ
 * 
 * @param char* string
 * @param char  replace
 * 
 * @return char*
 */
char* replaceLetters(char* string, char replace)
{
    char* result = string;
    int   lenght = strlen(string);

    // 65-90 => [A-Z]

    for (int i = 0; i < lenght; i++) {
        if ((int)string[i] >= 65 && (int)string[i] <= 90 )
            result[i] = replace;
    }

    return result;
}

/**
 * Заменяет искомый в строке на введенный во всех местах
 * 
 * @param char* string
 * @param char  search
 * 
 * @return int
 */
int countSymbol(char* string, char search)
{
    int result = 0;
    int lenght = strlen(string);

    for (int i = 0; i < lenght; i++) {
        if (string[i] == search)
            result++;
    }

    return result;
}

int main()
{
    int   N    = 0;
    char* str  = malloc(sizeof(char) * MAX_RAND);
    char  sym1 = 'A';
    char  sym2 = 'B';

    fflush(stdin);

    N   = scanNumber();
    str = generateString(N);

    printf("%s\n", str);

    // Замена букв
    printf("Введите символ для замены всех букв: ");
    scanf("%c", & sym1);
    getchar();
    str = replaceLetters(str, sym1);

    // Замена цифр
    printf("Введите символ для замены всех цифр: ");
    scanf("%c", & sym2);
    getchar();
    str = replaceDigits(str, sym2);

    // Итоговая строка
    printf("Итоговая строка: %s\n", str);
    printf("Символов %c: %d\n", sym1, countSymbol(str, sym1));
    printf("Символов %c: %d\n", sym2, countSymbol(str, sym2));

    return 0;
}
