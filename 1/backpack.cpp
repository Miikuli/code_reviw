// FIX ME задача не шаблону
/*
//Археолог нашел N артефактов.Известны веса(сi) и ценности(di) артефактов.Нужно
//выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг, а их
//общая ценность оказалась максимальной.Известно, что решение единственно.Укажите поряд
//ковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле, в
//первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - ценность
//находок.Вывести так же суммарный вес и общую ценность результата.
*/

/*
Продолжение задания №1
Археолог нашел N артефактов. Известны веса (сi) и ценности (di) артефактов.
Нужно выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг,
а их общая ценность оказалась максимальной. Известно, что решение единственно.
Укажите порядковые номера вещей, которые нужно взять. Исходные данные находятся в текстовом файле,
в первой строке указаны N и Z, а во второй строке значения весов (в кг), в третьей - ценность находок.
Вывести так же суммарный вес и общую ценность результата.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>


/**
 * Сортирует артефакты по весу в порядке возрастания
 * @param weights вектор весов артефактов
 * @param values вектор ценностей артефактов
 */
// FIXME: Нарушение именования функции и параметров
// void insert_sort(std::vector<int>& w, std::vector<int>& p) {
void SortArtifacts(std::vector<int>& weights, std::vector<int>& values) 
{   // FIX ME: Фигурная скобка должна быть на новой строке (строка 34, 37)
    for (int i = 1; i < weights.size(); i++) 
    {
        //int temp = i;
        int current = i;
        while (current - 1 >= 0 && weights[current] < weights[current - 1]) 
        {
            std::swap(weights[current], weights[current - 1]);
            std::swap(values[current], values[current - 1]);
            current--;
        }
    }
}

/**
 * Решает задачу о рюкзаке методом динамического программирования
 * @param capacity вместимость рюкзака
 * @param weights веса артефактов
 * @param values ценности артефактов
 * @param count количество артефактов
 * @return максимальная ценность
 */
// FIXME: Нарушение именования функции и параметров
// int backpack(int W, std::vector<int>& wt, std::vector<int>& val, int n) {
int SolveKnapsackProblem(int capacity, std::vector<int>& weights, std::vector<int>& values, int count) 
// FIX ME: Фигурная скобка должна быть на новой строке (строки 58, 63, 65)
{
    //std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1));
    std::vector<std::vector<int>> value_table(count + 1, std::vector<int>(capacity + 1));
    // Заполнение таблицы
    for (int i = 0; i <= count; i++) 
    {
        for (int w = 0; w <= capacity; w++) 
        {
            if (i == 0 || w == 0) 
            // FIX ME: Однострочные блоки запрещены, нужно использовать фигурные скобки (строки 68, 72, 78)
            {
                value_table[i][w] = 0; // Нет предметов или вес рюкзака равен 0
            }
            else if (weights[i - 1] <= w) 
            {
                // Выбор между включением и исключением текущего предмета
                value_table[i][w] = std::max(values[i - 1] + value_table[i - 1][w - weights[i - 1]],
                    value_table[i - 1][w]);
            }
            else 
            {
                // Текущий предмет не вмещается в рюкзак
                value_table[i][w] = value_table[i - 1][w];
            }
        }
    }
    return value_table[count][capacity];
}


// FIXME: Отсутствовала функция чтения данных из файла, хотя по заданию данные должны читаться из файла
/**
 * Функция для чтения данных из файла.
 *
 * @param filename - имя файла.
 * @param num_items - количество артефактов.
 * @param max_capacity - максимальный вес.
 * @param weights - вектор весов артефактов.
 * @param values - вектор ценностей артефактов.
 */
std::pair<int, int> ReadDataFromFile(const std::string& filename, std::vector<int>& weights, std::vector<int>& values) 
{ 
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        throw std::runtime_error("Не удалось открыть файл с данными");
    }

    int artifact_count, max_weight;
    file >> artifact_count >> max_weight;

    weights.resize(artifact_count);
    values.resize(artifact_count);

    for (int i = 0; i < artifact_count; ++i) {
        file >> weights[i];
    }

    for (int i = 0; i < artifact_count; ++i) {
        file >> values[i];
    }

    file.close();
    return { artifact_count, max_weight };
}


int main()
{
    // FIXME: Не рекомендуется использовать setlocale для кириллицы
    // setlocale(LC_ALL, "ru");
    // Лучше использовать Unicode (UTF-8)
    // FIXME: В оригинальном коде данные вводились вручную, хотя по заданию должны читаться из файла
    const std::string filename = "artifacts.txt";
    std::vector<int> profit;
    std::vector<int> weight;
    std::pair<int, int> result = ReadDataFromFile(filename, weight, profit);

    // FIXME: Нарушение именования переменных
    //int n, W;
    int num_artifacts = result.first;
    int capacity = result.second;

    std::cout << "Прочитано " << num_artifacts << " артефактов с максимальным весом "
        << capacity << std::endl;

    SortArtifacts(weight, profit);
    std::cout << "Максимальная возможная стоимость вещей, уместимых в рюкзак: " << SolveKnapsackProblem(capacity, weight, profit, num_artifacts) << std::endl;

    return 0;
}
