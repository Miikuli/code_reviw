// FIX ME задача на по шаблону

/*
 * //К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько
 * //имеется чисел из N(1 < N < 20, N + K < 26) разрядов таких, что в их записи не содержится более
 * //трех подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
 * //представьте в виде вещественного числа.
*/

/*
 * Продолжение задачи №3
 * К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько
 * имеется чисел из N(1 < N < 20, N + K < 26) разрядов таких, что в их записи не содержится более
 * трех подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
 * представьте в виде вещественного числа.
*/


#include <iostream>
// FIXME: Заголовок <vector> не используется

using namespace std;


//FIXME: лучше вынести логику в отдельные функции
/**
 * Проверяет корректность входных параметров
 * @param base Основание системы счисления (2 ≤ base ≤ 10)
 * @param digits Количество разрядов (1 < digits < 20)
 * @return true если параметры корректны, false в противном случае
 * @throws Не выбрасывает исключений, но выводит сообщения об ошибках в cerr
 */
bool validateInput(int base, int digits) 
{
    if (base < 2 || base > 10) 
    {
        cerr << "Ошибка: основание должно быть 2-10\n";
        return false;
    }
    if (digits <= 1 || digits >= 20) 
    {
        cerr << "Ошибка: количество разрядов должно быть 2-19\n";
        return false;
    }
    if (base + digits >= 26) 
    {
        cerr << "Ошибка: K + N должно быть < 26\n";
        return false;
    }
    return true;
}


/**
 * Подсчитывает количество K-ичных N-разрядных чисел без двух+ подряд нулей
 * @param base Основание системы счисления (2 ≤ base ≤ 10)
 * @param digits Количество разрядов (1 < digits < 20)
 * @return Количество допустимых чисел в виде вещественного числа
 * @throws overflow_error при переполнении вычислений
 * @note Использует динамическое программирование для подсчета:
 *       - endsWithNonZero: числа, оканчивающиеся не на 0
 *       - endsWithOneZero: числа, оканчивающиеся на один 0
 */
double countValidNumbers(int base, int digits) 
{
    //FIXME: Нет проверки на переполнение
    constexpr int max_ll = numeric_limits<int>::max();

    // FIXME: Неправильные именования переменных и переменных
    //int nz, oz, tz, _tz, _oz, _nz;
    // FIXME: Переменные могут быть определены при объявлении
    int endsWithNonZero = base - 1;
    int endsWithOneZero = 1;

    for (int i = 2; i <= digits; ++i) 
    {
        
        if (endsWithNonZero > max_ll / (base - 1) ||
            endsWithOneZero > max_ll / (base - 1)) 
        {
            throw overflow_error("Возможное переполнение при вычислениях");
        }

        int newNonZero = (endsWithNonZero + endsWithOneZero) * base;
        int newOneZero = endsWithNonZero;

        
        if (newNonZero < 0 || newOneZero < 0) 
        {
            throw overflow_error("Произошло переполнение");
        }

        endsWithNonZero = newNonZero;
        endsWithOneZero = newOneZero;
    }

    return static_cast<double>(endsWithNonZero + endsWithOneZero);
}

int main() 
{
    try 
    {
        //FIXME: Неправильное именование пременных
        //int K, N;
        int base, digits;

        cout << "Введите основание системы счисления (2-10): ";
        cin >> base;
        cout << "Введите количество разрядов (2-19): ";
        cin >> digits;

        if (!validateInput(base, digits)) 
        {
            return 1;
        }

        double result = countValidNumbers(base, digits);
        cout.precision(15);
        cout << "Количество подходящих чисел: " << result << "\n";

    }
    catch (const exception& e) 
    {
        cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
