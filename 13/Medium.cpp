//Вариант 13

#include <iostream>
using std::cout, std::cin, std::endl, std::stoi;
#include <string>
using std::string, std::getline;
#include <format>
using std::format;
#include <exception>
using std::invalid_argument, std::out_of_range;
#include <random>
using std::random_device, std::mt19937, std::uniform_int_distribution;

const string ERROR_MSG = "\nНеверный аргумент";

bool falseout(string value)
{
    cout << format("{}: {}", ERROR_MSG, value) << endl;
    return false;
}

bool is_int(string value)
{

    size_t pos;
    try
    {
        stoi(value, &pos);
    }
    catch (const invalid_argument& e)
    {
        return falseout(value);
    }
    catch(const out_of_range& e)
    {
        return falseout(value);
    }

    if (pos != value.size())
    {
        return falseout(value);
    }
            
    return true;
}

class Stack
{
    private:
        int* arr;
        int top = -1;
        int capacity{0};

    public:
        Stack (int a_capacity)
        {
            capacity = a_capacity;
            arr = new int[capacity];
        }

        void push(int el)
        {
            if (isFull())
            {
                cout << "Стек заполнен\n";
                return;
            }

            top++;
            arr[top] = el;
        }

        int pop()
        {
            if (top == -1)
            {
                cout << "Массив пуст, возвращаю 0\n";
                return 0;
            }

            top--;
            return arr[top + 1];
        }

        int peek(int pos)
        {
            if (pos > top)
            {
                cout << "Индекс за пределами массива, возвращаю 0\n";
                return 0;
            }
            return arr[pos];
        }

        bool isEmpty()
        {
            if (top == -1)
            {
                return true;
            }
            return false;
        }

        bool isFull()
        {
            if (top == capacity - 1)
            {
                return true;
            }
            return false;
        }

        void print()
        {
            if (top == -1)
            {
                cout << "Массив пуст\n";
                return;
            }

            string strArr = "Массив:\n\t{";
            for (int i = 0; i <= top; i++)
            {
                strArr += format(" {},", arr[i]);
            }
            strArr.erase(strArr.size() - 1);
            strArr += " }\n";

            cout << strArr;
        }

        int getCapacity()
        {
            return capacity;
        }

        int getTop()
        {
            return top;
        }
};

int main()
{
    string input;
    bool temp = false;
    while (not temp)
    {
        cout << "Введите размер стека\t";
        getline(cin, input);
        temp = is_int(input);
        if (temp)
        {
            temp = (stoi(input) >= 10 ? true : [](){cout << "Размер стека не должен быть меньше 10\n"; return false;}());
        }
    }

    Stack stack = Stack(stoi(input));
    cout << format("Создан стек с максимальным размером {}\n\n", stack.getCapacity());

    cout << format("Пуст ли стек?\n{}\n\n", stack.isEmpty());

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(10000, 99999);

    cout << "Заполняю стек случайными пятизначными числами\n";
    for (int i = 0; i < stack.getCapacity(); i++)
    {
        stack.push(dis(gen));
    }
    stack.print();

    cout << format("\nПолон ли стек?\n{}\n", stack.isFull());\
    cout << "Пытаюсь добавить элемент в полный массив\n";
    stack.push(12);


    cout << format("Пятый элемент стека равен {}\n", stack.peek(4));
    cout << format("Текущий размер стека: {}\n", stack.getTop());
    cout << format("Возвращаю последний элемент стека и удаляю его: {}\n", stack.pop());
    cout << format("Текущий размер стека: {}\n", stack.getTop());
    
    stack.print();
    
    return 0;
}