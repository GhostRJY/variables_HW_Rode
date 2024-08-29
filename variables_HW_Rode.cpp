#include <iostream>
#include<iomanip>


template <typename T>
void avgValue(T a, T b, T c)
{
    std::cout << "average from a, b, c is " << (a + b + c) / 3 << std::endl;
}

template <typename T>
void powValue(T value, int grade)
{
    T result = 1;
    for(size_t i{ 0 }; i < grade; ++i)
        result *= value;

    std::cout << value << " в степени " << grade << " = " << result<<'\n';
}

void circleSquare()
{
    const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862;
    double radius{};
    std::cout << "введите радиус окружности ->";
    std::cin >> radius;

    std::cout << "\nПлощадь окружности с радиусом " << radius 
        << " равен " << std::setprecision(15)<< PI * radius * radius<<'\n';

}

void exchangeCurs()
{
    unsigned short choice{};
    double grn{};
    const double dollars{ 40 }, euros{ 41.7 }, bitcoin{ dollars * 1000 };
    std::cout << "Введите кол-во гривен ->";
    std::cin >> grn;
    std::cout << "\nВыберите валюту (1-доллары, 2-евро, 3-биткоин) ->";
    std::cin >> choice;

    std::cout << grn << " составляет\n";
        
    switch(choice) {
        case 1: 
            std::cout << grn / dollars << " долларов\n";
            break;
        case 2:
            std::cout << grn / euros << " евро\n";
            break;
        case 3:
            std::cout << grn / bitcoin << " биткоинов\n";
            break;
        default:
            std::cout << "нет такой валюты!!!\n";
            
    }
}

void kmToMiles(int km)
{
    double miles{ km * 0.62137 };
    double seaMiles{ km * 0.539957 };

    std::cout << km << " км составляет " << miles << " миль и " << seaMiles << " морских миль\n";
}

void percentValue(int percent, double value){
    std::cout << percent << " процентов от числа " << value << " = " << value * percent / 100 << '\n';
}

template <typename T>
void changeVariable(T& a, T& b)
{
    //с доп переменной
    /*T temp{ a };
    a = b;
    b = temp;*/
    
    //без доп переменной
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

}

//фун-ия переворота чисел любой длины
void mirrorValue(int& userValue)
{
    int temp = userValue;
    int counter{ 0 };
    
    //вычисляем кол-во цифр в значении
    while(temp != 0) {
        temp /= 10;
        ++counter;
    }

    //сохраняем число которое нужно перевернуть
    temp = userValue;
    //обнуляю пользовательское число
    userValue = 0;

    //получаю перевернутое число
    while(temp != 0) {
        userValue += (temp % 10) * std::pow(10, --counter);
        temp /= 10;
    }
}

int main()
{
    
    
    //1.	Написать программу, которая находит среднее арифметическое значение трёх вещественных чисел.
    //avgValue(1, 2, 3);
    
    //2.	Пользователь вводит число и степень.Программа вычисляет указанную степень этого числа(пригодится функция pow).
    //powValue(2, 3);
    
    //3.	Написать программу, которая  предлагает пользователю ввести радиус окружности, а затем считает площадь и длину этой окружности.Число Pi задать в программе как вещественную константу.
    //circleSquare();
    
    //4.	Написать программу, которая  предоставляет пользователю возможность ввести с клавиатуры количество гривен, и переводит это количество в доллары, евро и биткоины.
    //exchangeCurs();
    
    //5.	Написать программу, которая переводит километры в сухопутные и морские мили.
    //kmToMiles(100);
    
    //6.	Написать программу, которая находит процент P от числа N.
    //percentValue(10, 200);
            
    //8.	Поменять местами значения переменных a и b, сначала с использованием дополнительной третьей переменной, а затем – без.
    /*int a{10}, b{30};
    
    std::cout << "Переменная a = " << a << " переменная b = " << b << '\n';
    changeVariable(a, b);
   
    std::cout << "Переменная a = " << a << " переменная b = " << b << std::endl;*/

    //9.	Ввести с клавиатуры 3 - значное число и «перевернуть» его(например, ввести 357 – получить и вывести 753).
    int userValue{};
    std::cout << "введите число ->";
    std::cin >> userValue;

    mirrorValue(userValue);
    
    std::cout << '\n' << userValue << "\nХА - ХА, Я перевернул твое число!!!\n";


    return 0;
}
