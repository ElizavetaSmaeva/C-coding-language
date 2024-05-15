
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

struct QuadraticEquation {
    double a, b, c;
};

struct Student {
    std::string name;
    bool isGoodStudent;
};

void solveQuadraticEquation(QuadraticEquation eq, double& x1, double& x2) {
    double D = eq.b * eq.b - 4 * eq.a * eq.c;
    if (D < 0) {
        x1 = x2 = 0;
    } else {
        x1 = (-eq.b + sqrt(D)) / (2 * eq.a);
        x2 = (-eq.b - sqrt(D)) / (2 * eq.a);
    }
}

bool isCorrectSolution(QuadraticEquation eq, double x1, double x2) {
    return eq.a * x1 * x1 + eq.b * x1 + eq.c == 0 && eq.a * x2 * x2 + eq.b * x2 + eq.c == 0;
}

int main() {
    std::vector<Student> students;
    std::vector<std::string> solutions;

    // Генерируем список студентов с разными успеваемостями
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        Student s;
        s.name = "Student" + std::to_string(i);
        int r = rand() % 3;
        if (r == 0) {
            s.isGoodStudent = true;
        } else {
            s.isGoodStudent = false;
        }
        students.push_back(s);
    }

    // Читаем задачи из файла
    std::ifstream file("quadratic_equations.txt");
    if (file.is_open()) {
        QuadraticEquation eq;
        while (file >> eq.a >> eq.b >> eq.c) {
            double x1, x2;
            solveQuadraticEquation(eq, x1, x2);
            for (int i = 0; i < students.size(); ++i) {
                if (students[i].isGoodStudent) {
                    solutions.push_back(std::to_string(eq.a) + "x^2 + " + std::to_string(eq.b) + "x + " + std::to_string(eq.c) + "   solution: " + std::to_string(x1) + " and " + std::to_string(x2) + "   " + students[i].name);
                } else {
                    if (rand() % 2 == 0) {
                        if (isCorrectSolution(eq, x1, x2)) {
                            solutions.push_back(std::to_string(eq.a) + "x^2 + " + std::to_string(eq.b) + "x + " + std::to_string(eq.c) + "   solution: " + std::to_string(x1) + " and " + std::to_string(x2) + "   " + students[i].name);
                        }
                    } else {
                        solutions.push_back(std::to_string(eq.a) + "x^2 + " + std::to_string(eq.b) + "x + " + std::to_string(eq.c) + "   solution: 0   " + students[i].name);
                    }
                }
            }
        }
        file.close();
    }

    // Проверяем письма и записываем в таблицу
    std::vector<std::pair<std::string, int>> results;
    for (int i = 0; i < solutions.size(); ++i) {
        std::string name = solutions[i].substr(solutions[i].find_last_of(" ") + 1);
        bool found = false;
        for (int j = 0; j < results.size(); ++j) {
            if (results[j].first == name) {
                found = true;
                results[j].second++;
                break;
            }
        }
        if (!found) {
            results.push_back(std::make_pair(name, 1));
        }
    }

    // Публикуем таблицу успеваемости
    std::cout << "Student    Successful solutions\n";
    for (const auto& res : results) {
        std::cout << res.first << "    " << res.second << "\n";
    }

    return 0;
}
