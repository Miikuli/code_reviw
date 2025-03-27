/* Продолжение задания №1
Заголовочный файл для задачи о рюкзаке.
Археолог нашел N артефактов. Известны веса (сi) и ценности (di) артефактов.
Нужно выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг,
а их общая ценность оказалась максимальной.
*/

#ifndef BACKPACK_H
#define BACKPACK_H

#include <vector>
#include <fstream>

/**
 * Сортировка вставками векторов весов и ценностей.
 * @param weights Вектор весов артефактов
 * @param values Вектор ценностей артефактов
 */
void InsertSort(std::vector<int>& weights, std::vector<int>& values);

/**
 * Решает задачу о рюкзаке методом динамического программирования.
 * @param capacity Вместимость рюкзака
 * @param weights Вектор весов артефактов
 * @param values Вектор ценностей артефактов
 * @param num_artifacts Количество артефактов
 * @return Максимальная ценность, которую можно унести в рюкзаке
 */
int SolveKnapsack(int capacity, std::vector<int>& weights, std::vector<int>& values, int num_artifacts);

/**
 * Функция для чтения данных из файла.
 *
 * @param filename - имя файла.
 * @param num_items - количество артефактов.
 * @param max_capacity - максимальный вес.
 * @param weights - вектор весов артефактов.
 * @param values - вектор ценностей артефактов.
 */
void ReadFromFile(const std::string& filename, int& num_items, int& max_capacity, std::vector<int>& weights, std::vector<int>& values);


#endif // BACKPACK_H
