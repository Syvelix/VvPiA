#include <iostream>
#include <format>
#include <string>
#include <stdexcept>
using std::cin, std::cout, std::endl, std::stod, std::format;
using std::string, std::getline, std::invalid_argument, std::out_of_range;

class Calc
{
    const string OPERS{"+-/*"};
    const string allowed{"0123456789.-+*/()"};
    const string ERROR_MSG{"\nНеверный аргумент"};
    string problem{""};

    bool falseout(const string& value) const
    {
        cout << format("{}: {}", ERROR_MSG, value) << endl;
        return false;
    }

    //Можно ли привести string к double
    bool is_double(const string& value) const
    {
        size_t pos{0};
        try
        {
            stod(value, &pos);
        }
        catch (const invalid_argument&)
        {
            return falseout(value);
        }
        catch (const out_of_range&)
        {
            return falseout(value);
        }

        if (pos != value.size())
        {
            return falseout(value);
        }
        return true;
    }

    bool isNumCh(char c) const
    { 
        return (c >= '0' && c <= '9') || c == '.'; 
    }
    bool isOper(char c) const
    {
        return OPERS.find(c) != string::npos; 
    }

    //Считает выражение БЕЗ скобок. Результат кладёт в out.
    bool calculate(string expr, string& out) const
    {
        while (true)
        {
            //Сначала * или /
            size_t op = string::npos;
            for (size_t i = 0; i < expr.size(); i++)
                if (expr[i] == '*' || expr[i] == '/') 
                { 
                    op = i; break; 
                }

            //Потом бинарное + или -
            if (op == string::npos)
                for (size_t i = 1; i < expr.size(); i++)
                    if ((expr[i] == '+' || expr[i] == '-') and isNumCh(expr[i - 1])) 
                    {
                        op = i; 
                        break; 
                    }

            if (op == string::npos) break;

            if (op == 0 || !isNumCh(expr[op - 1])) 
            {
                return falseout("Нет левого операнда");
            }

            //Левый операнд
            size_t l = op;
            while (l > 0 && isNumCh(expr[l - 1]))
            {
                l--;
            }
            if (l > 0 and (expr[l - 1] == '-' or expr[l - 1] == '+') and (l == 1 || isOper(expr[l - 2]))) 
            {
                l--;
            }

            //Правый операнд
            size_t r = op + 1;
            if (r < expr.size() and (expr[r] == '-' or expr[r] == '+')) 
            {
                r++;
            }
            size_t digitsStart = r;
            while (r < expr.size() and isNumCh(expr[r]))
            {
                r++;
            }
            if (r == digitsStart) 
            {
                return falseout("Нет правого операнда");
            }

            string left  = expr.substr(l, op - l);
            string right = expr.substr(op + 1, r - op - 1);
            if (!is_double(left) || !is_double(right))
            {
                return false;
            }

            double a = stod(left);
            double b = stod(right);
            double res{0};
            switch (expr[op])
            {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/':
                    if (b == 0) 
                    {
                        return falseout("Деление на ноль");
                    }
                    res = a / b;
                    break;
            }
            expr.replace(l, r - l, format("{:.12f}", res));
        }

        if (!is_double(expr))
        {
            return false;
        }
        out = expr;
        return true;
    }

    bool unbracket()
    {
        while (true)
        {
            size_t pos = problem.find(')');
            if (pos == string::npos)
            {
                if (problem.find('(') != string::npos)
                {
                    return falseout("В выражении не хватает закрывающей скобки");
                }
                return true;
            }
            size_t lastgood = problem.rfind('(', pos);
            if (lastgood == string::npos)
            {
                return falseout("В выражении не хватает открывающей скобки");
            }

            string inner = problem.substr(lastgood + 1, pos - lastgood - 1);
            if (inner == "") 
            {
                return falseout("Пустые скобки");
            }
        
            if (lastgood > 0 and isNumCh(problem[lastgood - 1])) 
            {
                return falseout("Нет знака перед (");
            }

            if (pos + 1 < problem.size() and isNumCh(problem[pos + 1])) 
            {
                return falseout("Нет знака после )");
            }

            string res;
            if (!calculate(inner, res)) return false;
            problem.replace(lastgood, pos - lastgood + 1, res);
        }
    }
    void spaceKill()
    {
        string newProblem;
        for (char lt : problem)
            if (lt != ' ') newProblem += lt;
        problem = newProblem;
    }

    bool isRun()
    {
        return problem != "&";
    }

    //Возвращает первый недопустимый символ если он есть
    char symlVal()
    {
        size_t i = problem.find_first_not_of(allowed);
        return i == string::npos ? '\0' : problem[i];
    }

public:

    string getProblem() 
    { 
        return problem; 
    }

    void setProblem()
    {
        cout << "Введите выражение\t";
        getline(cin, problem);
    }

    void killProblem()
    {
        problem = "";
    }

    //true при успехе, результат в result
    bool solve(double& result, bool& run)
    {
        spaceKill();
        run = isRun();
        if (not run)
        {
            return false;
        }

        if (problem.empty())
        {
            cout << "Задано пустое выражение\n";
            return false;
        }
        if (char bad = symlVal(); bad != '\0')
        {
            cout << format("Неверный символ \"{}\" в выражении\n", bad);
            return false;
        }

        if (!unbracket()) return false;

        string final;
        if (!calculate(problem, final)) return false;

        problem = final;
        result = stod(final);
        return true;
    }
};

int main()
{
    Calc calc;
    bool run = true;
    while (run)
    {
        calc.setProblem();
        double result{0};
        if (calc.solve(result, run))
        {
            cout << format("Результат: {}", result) << endl;
        }
        calc.killProblem();
    }
    
    return 0;
}