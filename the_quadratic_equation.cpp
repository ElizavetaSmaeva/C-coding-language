#include <iostream> // подключаем cin/cout
#include <cmath> // подключаем sqrt
#include <string>
using namespace std;
 
class CppStudio {
  private: // спецификатор доступа private
    int a, b, c, d; 
    double x1,x2;
    string s;
  public: /* список методов доступных другим функциям и объектам программы */
    void data_entry(string s) // функция (метод класса) выводящая сообщение на экран
    {
        cout << s << "\n";
    }
    void setRatio(int U_a, int U_b, int U_c) // установка даты в формате дд.мм.гг
    {
        a = U_a; // инициализация a
        b = U_b; // инициализация b
        c = U_c; // инициализация c
    }
    void discriminant() // функция (метод класса) подсчитывающая дискриминант
    {
        d = b * b - 4 * a * c; // Рассчитываем дискриминант
    }
    void roots1() // функция (метод класса) 
    {
        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        s = "x1 = " + std::to_string(x1) + "\n" + "x2 = " + std::to_string(x2) + "\n";
        //return s;
    }
    void roots2() // функция (метод класса) 
    {
        x1 = -(b / (2 * a));
        s = "x1 = x2 = " + std::to_string(x1) + "\n";
       // return s;
    }
    void roots3() // функция (метод класса) 
    {
        s = "D < 0, Действительных корней уравнения не существует";
        //return s;
    }
    void message() // установка даты в формате дд.мм.гг
    {
        cout << s;
    }
        
};
 
int main()
{
  double a,b,c,d,x1,x2;// Объявляем переменные с плавающей точкой.
  string s;
  cout << "Введите a\n"; // Вводим исходные данные
  cin >> a;
  cout << "Введите b\n";
  cin >> b;
  cout << "Введите c\n";
  cin >> c;
  CppStudio objCppstudio; // объявление объекта
  objCppstudio.setRatio(a, b, c); // инициализация коэффициентов
  objCppstudio.discriminant(); // вызов функции класса discriminant
  if (d > 0) // Условие при дискриминанте больше нуля
  {
    objCppstudio.roots1();
  }
  if (d == 0) // Условие для дискриминанта равного нулю
  {
    objCppstudio.roots2();
  }
  if (d < 0) // Условие при дискриминанте меньше нуля
    objCppstudio.roots3();
  
  objCppstudio.message(); // вызов функции класса message
}