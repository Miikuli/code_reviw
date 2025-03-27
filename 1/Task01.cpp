//�������� ����� N ����������.�������� ����(�i) � ��������(di) ����������.�����
//������� ����� ������������ ��������� �����, ����� ��������� �� ��� �� �������� Z ��, � ��
//����� �������� ��������� ������������.��������, ��� ������� �����������.������� �����
//����� ������ �����, ������� ����� �����.�������� ������ ��������� � ��������� �����, �
//������ ������ ������� N � Z, � �� ������ ������ �������� �����(� ��), � ������� - ��������
//�������.������� ��� �� ��������� ��� � ����� �������� ����������.

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
    // ���������� �������
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; // ��� ��������� ��� ��� ������� ����� 0
            else if (wt[i - 1] <= w)
                // ����� ����� ���������� � ����������� �������� ��������
                dp[i][w] = std::max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                // ������� ������� �� ��������� � ������
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
        std::cout << "������� ����� ������� >=0 ";
        std::cin >> W;
    } while (W <= 0);

    do {
        std::cout << "������� ���-�� ���������� >=0 ";
        std::cin >> n;
    } while (n <= 0);


    std::cout << "���������� ������� ��������� ����������";
    
    std::vector<int> profit(n);
    std::vector<int> weight(n);

    for (int i = 0; i < n; i++) {
        std::cout << std::endl<< "��� " << i + 1 << ": ";
        std::cin >> weight[i];
        std::cout << std::endl << "��������� " << i + 1 << ": ";
        std::cin >> profit[i];
    }
    insert_sort(weight, profit);
    std::cout << "������������ ��������� ��������� �����, ��������� � ������: " << backpack(W, weight, profit, n)<< std::endl;

    return 0;
}
