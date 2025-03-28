//Во всех заданиях данной подгруппы предполагается, что исходные строки, определяющие выражения, 
//не содержат пробелов.При выполнении заданий не следует использовать оператор цикла.
//Вывести значение логического выражения, заданного в виде строки S.Выражение определяется следующим 
//образом(«T» — True, «F» — False) :
//    <выражение> :: = T | F | And(<параметры>) | Or(<параметры>)
//    <параметры> :: = <выражение> | <выражение>, <параметры>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <sstream>

using namespace std;

bool evaluate(const string& expr);

vector<string> splitRecursive(const string& s, char delimiter, size_t start = 0) {
    vector<string> result;
    size_t pos = s.find(delimiter, start);

    if (pos != string::npos) {
        result.push_back(s.substr(start, pos - start));

        vector<string> remaining = splitRecursive(s, delimiter, pos + 1);

        result.insert(result.end(), remaining.begin(), remaining.end());
    }
    else {
        if (start < s.length()) {
            result.push_back(s.substr(start));
        }
    }

    return result;
}

bool evaluateAnd(const vector<string>& expressions, size_t index = 0) {
    if (index >= expressions.size()) {
        return true;
    }

    if (!evaluate(expressions[index])) {
        return false;
    }

    return evaluateAnd(expressions, index + 1);
}

bool evaluateOr(const vector<string>& expressions, size_t index = 0) {
    if (index >= expressions.size()) {
        return false;
    }

    if (evaluate(expressions[index])) {
        return true;
    }

    return evaluateOr(expressions, index + 1);
}

bool evaluate(const string& expr) {
    if (expr == "T") {
        return true;
    }
    else if (expr == "F") {
        return false;
    }
    else if (expr.substr(0, 3) == "And") {
        // Убираем "And(" и ")"
        string params = expr.substr(4, expr.size() - 5);
        vector<string> sub_exprs = splitRecursive(params, ',');
        return evaluateAnd(sub_exprs);
    }
    else if (expr.substr(0, 2) == "Or") {
        // Убираем "Or(" и ")"
        string params = expr.substr(3, expr.size() - 4);
        vector<string> sub_exprs = splitRecursive(params, ',');
        return evaluateOr(sub_exprs);
    }
    return false; 
}

void Recur23() {
    string expr;
    cin >> expr;
    bool result = evaluate(expr);
    cout << (result ? "T" : "F") << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    Recur23();
}