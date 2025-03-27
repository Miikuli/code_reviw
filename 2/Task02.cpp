//Хромой король.На квадратной доске расставлены монеты, достоинством от 1 до 100. 
//Хромой король, находящийся в правом нижнем углу, мечтает попасть в левый верхний.
//При этом он может передвигаться только в клетку слева или сверху и хочет, чтобы сумма всех
//монет, оказавшихся у него на пути, была бы максимальной.Определить эту сумму и путь, каким
//образом должен двигаться король, чтобы ее собрать.Ввод и вывод организовать при помощи
//текстовых файлов.Формат входных данных : в первой строке входного файла записано число 
//N - размер доски(1 < N < 80).Далее следует N строк, каждая из которых содержит N целых чисел,
//представляющих доску.В первую строку выходного файл нужно вывести единственное число :
//максимальную сумму, а во второй строке вывести путь в виде строки символов, обозначив сим
//волом L движение влево, а символом U - движение вверх.

#include <fstream>  
#include <iostream>  
#include <vector>  
#include <string>  
using namespace std;
int n;
void Solve(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<char>>& put)
{
    int max;
    b[n - 1][n - 1] = a[n - 1][n - 1];
    for (int i = n - 2;i >= 0;i--)
    {
        b[i][n - 1] = b[i + 1][n - 1] + a[i][n - 1];
        put[i][n - 1] = 'U';
    }
    for (int j = n - 2;j >= 0;j--)
    {
        b[n - 1][j] = b[n - 1][j + 1] + a[n - 1][j];
        put[n - 1][j] = 'L';
    }
    for (int i = n - 2;i >= 0;i--)
    {
        for (int j = n - 2;j >= 0;j--)
        {
            if (b[i + 1][j] > b[i][j + 1])
            {
                max = b[i + 1][j];
                put[i][j] = 'U';
            }
            else
            {
                max = b[i][j + 1];
                put[i][j] = 'L';
            }
            b[i][j] = max + a[i][j];
        }
    }
}
void p(vector<vector<char>>& put, string& put1)
{
    int i = 0;
    int j = 0;
    while (i < n - 1 || j < n - 1)
    {
        if (put[i][j] == 'U')
        {
            put1 = put1 + "U ";
            i++;
        }
        else if (put[i][j] == 'L')
        {
            put1 = put1 + "L ";
            j++;
        }
    }
    reverse(put1.begin(), put1.end());
}
int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream f1("a.txt", ios::in);
    ofstream f2("b.txt", ios::out);
    f1 >> n;
    vector<vector<int>> pole1(n, vector<int>(n));
    vector<vector<int>> pole2(n, vector<int>(n));
    vector<vector<char>> put(n, vector<char>(n));
    string put1;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            f1 >> pole1[i][j];
        }
    }
    Solve(pole1, pole2, put);
    f2 << "Максимальная сумма монет, которую может собрать король: " << pole2[0][0] << '\n';
    p(put, put1);
    f2 << "Путь: " << put1;
    f1.close();
    f2.close();
    cout << "Программа завершена. Ответ записан в файл b.txt";
    return 0;
}