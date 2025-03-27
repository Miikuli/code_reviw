//Археолог нашел N артефактов.Известны веса(сi) и ценности(di) артефактов.Нужно
//выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг, а их
//общая ценность оказалась максимальной.Известно, что решение единственно.Укажите поряд
//ковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле, в
//первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - ценность
//находок.Вывести так же суммарный вес и общую ценность результата.

#include <iostream>
#include <vector>


void insert_sort(std::vector<int>& w, std::vector<int>& p) {
    for (int i = 1; i < w.size(); i++) {
        int temp = i;
        while (temp - 1 >= 0 && w[temp] < w[temp - 1]) {
            std::swap(w[temp], w[temp - 1]);
            std::swap(p[temp], p[temp - 1]);
            temp--;
        }
        
    }
}

int backpack(int W, std::vector<int>& wt, std::vector<int>& val, int n) {

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1));
    // Заполнение таблицы
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; // нет предметов или вес рюкзака равен 0
            else if (wt[i - 1] <= w)
                // Выбор между включением и исключением текущего предмета
                dp[i][w] = std::max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                // Текущий предмет не вмещается в рюкзак
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main()
{
    setlocale(LC_ALL, "ru");

    int n, W;

    do {
        std::cout << "Введите объем рюкзака >=0 ";
        std::cin >> W;
    } while (W <= 0);

    do {
        std::cout << "Введите кол-во артефактов >=0 ";
        std::cin >> n;
    } while (n <= 0);


    std::cout << "Поочередно вводите параметры артефактов";
    
    std::vector<int> profit(n);
    std::vector<int> weight(n);

    for (int i = 0; i < n; i++) {
        std::cout << std::endl<< "Вес " << i + 1 << ": ";
        std::cin >> weight[i];
        std::cout << std::endl << "стоимость " << i + 1 << ": ";
        std::cin >> profit[i];
    }
    insert_sort(weight, profit);
    std::cout << "Максимальная возможная стоимость вещей, уместимых в рюкзак: " << backpack(W, weight, profit, n)<< std::endl;

    return 0;
}
