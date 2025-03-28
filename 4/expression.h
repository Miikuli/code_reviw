/*
 * Продолжение задачи №4
 * Заголовочные файлы
 * Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения,
 * не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
 * Вывести значение целочисленного выражения, заданного в виде строки S.Выражение
 * определяется следующим образом(функция M возвращает максимальный из своих параметров,
 * а функция m — минимальный) :
 *         <выражение> :: = <цифра> | M(<выражение>, <выражение>) | m(<выражение>, <выражение>)
*/


#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>
#include <vector>
#include <string>

/**
 * @file expression_evaluator.h
 * @brief Вычисление специальных выражений с функциями M (максимум) и m (минимум)
 */

 /**
  * Рекурсивно разбивает строку по разделителю
  * @param s Исходная строка
  * @param delimiter Разделитель
  * @param start Начальная позиция (по умолчанию 0)
  * @return Вектор подстрок
  */
std::vector<std::string> SplitRecursive(const std::string& s, char delimiter, size_t start = 0);

/**
 * Рекурсивно вычисляет AND для списка выражений
 * @param expressions Вектор выражений
 * @param index Текущий индекс (по умолчанию 0)
 * @return Результат вычисления AND
 */
bool EvaluateAnd(const std::vector<std::string>& expressions, size_t index = 0);

/**
 * @brief Вычисляет дизъюнкцию (OR) списка выражений
 * @param expressions Вектор выражений для вычисления
 * @param index Текущий индекс (по умолчанию 0)
 * @return true если хотя бы одно выражение истинно, иначе false
 *
 * @note Особые случаи:
 *   evaluateOr({}) → false (пустая дизъюнкция)
 *   evaluateOr({"F","T"}) → true
 */
bool EvaluateOr(const std::vector<std::string>& expressions, size_t index = 0);

/**
 * Вычисляет значение целочисленного выражения
 * @param expression Строка с выражением
 * @return Результат вычисления выражения
 */
 //FIXME: неправильное именование функции
 //bool evaluate(const string& expr) {
bool Evaluate(const std::string& expr);

#endif  // EXPRESSION_H_
