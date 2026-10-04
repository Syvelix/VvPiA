#include <iostream>
using std::cin, std::cout, std::endl;
#include <format>
using std::format;
#include <string>
using std::u16string, std::string, std::getline;
#include <cctype>
using std::tolower;
#include <algorithm>
using std::find, std::begin, std::end;
#include <bitset>
using std::bitset;
#include <vector>
using std::vector;

//Гласные буквы
const string vowels_ru = "аеёиоуыэюяАЕЁИОУЫЭЮЯ";
const string vowels_eng = "aeioquy";

//Список битов русских букв
vector<bitset<16>> get_vowels_ru_bits(const string& vowels_ru)
{
    vector<bitset<16>> vowels_bits;

    for (int i = 0; i < vowels_ru.size(); i += 2)
    {
        bitset<8> first(vowels_ru[i]);
        bitset<8> second(vowels_ru[i + 1]);

        vowels_bits.push_back(bitset<16>((first.to_ulong() << 8) | second.to_ulong()));
    }

    return vowels_bits;
}
const vector<bitset<16>> vowels_ru_bits = get_vowels_ru_bits(vowels_ru);

//Кастыль для вывода русских букв
void cout_2B(string output)
{

    for (int i = 0; i < output.size(); i++)
    {
        bitset<8> bits(output[i]);

        //Если старший бит != 0, то символ не однобайтовый, а значит из кириллицы
        //Символы больше двух байт обрабатывать для задачи будет излишним
        if (bits[7] != 0)
        {
            bitset<8> bits_next(output[i+1]);
            if (find(begin(vowels_ru_bits), end(vowels_ru_bits), bitset<16>((bits.to_ulong() << 8) | bits_next.to_ulong())) != end(vowels_ru_bits))
            {
                cout << '*';
            }
            else
            {
                cout << output[i]<<output[i+1];
            }
            i++;
        }
        else
        {
            if (find(begin(vowels_eng), end(vowels_eng), tolower(output[i])) != end(vowels_eng))
            {
                cout << '*';
                continue;
            }
            cout << output[i];
        }
    }
    cout << endl << endl;
}

int main()
{
    string input;

    cout << "Введите строку для замены гласных на *\t";
    getline(cin, input);

    cout_2B(input);

    return 0;
}