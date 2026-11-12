#include <iostream>
using std::cout, std::cin, std::endl;
#include <format>
using std::format;
#include <exception>
using std::range_error;
#include <random>
using std::random_device, std::mt19937, std::uniform_int_distribution;

class PoolAllocator
{
    unsigned long SIZE;
    int* pool;
    int* current = nullptr;

    public:
        PoolAllocator(unsigned long SIZE)
        {
            this->SIZE = SIZE;
            pool = new int[SIZE]{0};
            cout << format("Создан пул размера {}\n", SIZE);
        }

        PoolAllocator()
        {
            SIZE = 15;
            pool = new int[SIZE]{0};
            cout << "Размер не задан, создан пул размера 15\n";
        }

        PoolAllocator(const PoolAllocator&) = delete;
        PoolAllocator& operator=(const PoolAllocator&) = delete;

        ~PoolAllocator()
        {
            delete[] pool;
            cout << "Деструктор выполнен\n\n";
        }

        void add(int number, unsigned long index)
        {
            is_OOR(index);

            pool[index] = number;
            cout << format("Элемент №{} = {} добавлен в пул\n", index, number);
        }

        void remove(unsigned long index)
        {
            is_OOR(index);

            pool[index] = 0;
            current = nullptr;
            cout << format("Ячейка {} освобождена\n", index);
        }

        void allocate(unsigned long index)
        {
            is_OOR(index);

            current = &pool[index];
            cout << format("Элемент №{} = {} выбран текущим\n", index, *current);
        }

        void deallocate()
        {
            current = nullptr;
            cout << "Текущий элемент сброшен\n";
        }
        
        int allocated()
        {
            if (current == nullptr)
            {
                throw "Нет выбранного элемента";
            }
            return *current;
        }

        int size()
        {
            return SIZE;
        }

    void is_OOR(unsigned long index)
    {
        if (index < 0 or index >= SIZE)
        {
            throw range_error("Индекс за границей пула");
        }
    }
};

int main()
{
    PoolAllocator pool1 = PoolAllocator();
    PoolAllocator pool2 = PoolAllocator(26);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(100, 1200);

    cout << "Заполняю пул случайными числами\n";
    for (int i = 0; i < pool2.size(); i++)
    {
        pool2.add(dis(gen), i);
    }
    cout << "Пул заполнен\n";

    cout << "Выбираю элемент №24\n";
    pool2.allocate(24);
    
    cout << "Удаляю элемент №24\n";
    pool2.remove(24);

    //cout << "Пытаюсь получить доступ к удалённому элементу\n";
    //cout << pool2.allocated() << endl;

    cout << "Выбираю элемент №17\n";
    pool2.allocate(17);

    cout << "Получаю доступ к элементу №17";
    cout << pool2.allocated() << endl;

    cout << "Снимаю текущий элемент\n";
    pool2.deallocate();

    //cout << "Пытаюсь получить доступ без выбранного элемента\n";
    //cout << pool2.allocated();

    return 0;
}