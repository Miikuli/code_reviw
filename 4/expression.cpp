// FIX ME задача на по шаблону

/*
 * //Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения,
 * //не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
 * //Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
 * //определяется следующим образом(функция M возвращает максимальный из своих параметров,
 * //а функция m — минимальный) :
 * //        <выражение> :: = <цифра> | M(<выражение>, <выражение>) | m(<выражение>, <выражение>)
*/

/*
 * Продолжение задачи №4
 * Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения,
 * не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
 * Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
 * определяется следующим образом(функция M возвращает максимальный из своих параметров,
 * а функция m — минимальный) :
 *         <выражение> :: = <цифра> | M(<выражение>, <выражение>) | m(<выражение>, <выражение>)
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <sstream>

using namespace std;

//FIXME: неправильное именование функции
//bool evaluate(const string& expr);
bool Evaluate(const string& expr);

/**
 * Рекурсивно разбивает строку по разделителю
 * @param s Исходная строка
 * @param delimiter Разделитель
 * @param start Начальная позиция (по умолчанию 0)
 * @return Вектор подстрок
 */
 //FIXME: неправильное именование функции
//vector<string> splitRecursive(const string& s, char delimiter, size_t start = 0) {
vector<string> SplitRecursive(const string& s, char delimiter, size_t start = 0) 
// FIX ME: Фигурная скобка должна быть на новой строке (строка 46, 51, 59, 61)
{
    vector<string> result;
    size_t pos = s.find(delimiter, start);

    if (pos != string::npos) 
    {
        result.push_back(s.substr(start, pos - start));

        vector<string> remaining = SplitRecursive(s, delimiter, pos + 1);

        result.insert(result.end(), remaining.begin(), remaining.end());
    }
    else 
    {
        if (start < s.length()) 
        {
            result.push_back(s.substr(start));
        }
    }

    return result;
}

/**
 * Рекурсивно вычисляет AND для списка выражений
 * @param expressions Вектор выражений
 * @param index Текущий индекс (по умолчанию 0)
 * @return Результат вычисления AND
 */
 //FIXME: неправильное именование функции
//bool evaluateAnd(const vector<string>& expressions, size_t index = 0) {
bool EvaluateAnd(const vector<string>& expressions, size_t index = 0) 
// FIX ME: Фигурная скобка должна быть на новой строке (строка 80, 82, 87)
{
    if (index >= expressions.size()) 
    {
        return true;
    }

    if (!Evaluate(expressions[index])) 
    {
        return false;
    }

    return EvaluateAnd(expressions, index + 1);
}

/**
 * Рекурсивно вычисляет OR для списка выражений
 * @param expressions Вектор выражений
 * @param index Текущий индекс (по умолчанию 0)
 * @return Результат вычисления OR
 */
 //FIXME: неправильное именование функции
//bool evaluateOr(const vector<string>& expressions, size_t index = 0) {
bool EvaluateOr(const vector<string>& expressions, size_t index = 0) 
// FIX ME: Фигурная скобка должна быть на новой строке (строка 105, 107, 112)
{
    if (index >= expressions.size()) 
    {
        return false;
    }

    if (Evaluate(expressions[index])) 
    {
        return true;
    }

    return EvaluateOr(expressions, index + 1);
}

/**
 * Вычисляет значение целочисленного выражения
 * @param expression Строка с выражением
 * @return Результат вычисления выражения
 */
//FIXME: неправильное именование функции
//bool evaluate(const string& expr) {
bool Evaluate(const string& expr) 
// FIX ME: Фигурная скобка должна быть на новой строке (строка 128, 130, 134, 138, 145)
{
    if (expr == "T") 
    {
        return true;
    }
    else if (expr == "F") 
    {
        return false;
    }
    else if (expr.substr(0, 3) == "And") 
    {
        // Убираем "And(" и ")"
        string params = expr.substr(4, expr.size() - 5);
        vector<string> sub_exprs = SplitRecursive(params, ',');
        return EvaluateAnd(sub_exprs);
    }
    else if (expr.substr(0, 2) == "Or") 
    {
        // Убираем "Or(" и ")"
        string params = expr.substr(3, expr.size() - 4);
        vector<string> sub_exprs = SplitRecursive(params, ',');
        return EvaluateOr(sub_exprs);
    }

    return false;
}

/**
 * Основная функция для выполнения задания
 */
void Recur23() {
    string expr;
    cin >> expr;
    bool result = Evaluate(expr);
    cout << (result ? "T" : "F") << endl;
}

int main() {
    //FIXME: Не рекомендуется использовать setlocale для кириллицы
    //setlocale(LC_ALL, "ru");
    Recur23();
}
