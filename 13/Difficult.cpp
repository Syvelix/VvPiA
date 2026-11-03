#include <iostream>
using std::cin, std::cout, std::endl, std::stod;
#include <format>
using std::format;
#include <string>
using std::string, std::getline;
#include <algorithm>
using std::find, std::distance;

class Calc
{
    const string OPERS{"+-/*"};
    const string allowed{"0123456789-+*/()"};
    string problem{""};
    string goodExpr{""};

    public:
        //Дебаг
        string getProblem()
        {
            return problem;
        }

        void setProblem()
        {
            cout << "Введите выражение\t";
            getline(cin, problem);
        }

        double solve()
        {
            spaceKill();
            string checkstr = symlVal();
            if (problem == "")
            {
                cout << "Задано пустое выражение\n";
                return -1;
            }
            if (checkstr != "ёё")
            {
                cout << format("Неверный символ \"{}\" в выражении", checkstr);
            }
            
            unbracket();

            return 0;
        }

    void spaceKill()
    {
        string newProblem{""};
        for (char lt : problem)
        {
            newProblem += lt != ' ' ? format("{}", lt) : "";
        }
        problem = newProblem;
    }

    string symlVal()
    {
        for (char lt : problem)
        {
           if (find(allowed.begin(), allowed.end(), lt) == allowed.end())
           {
                return format("{}", lt);
           }
        }
        return "ёё";
    }

    void makeExprGood(string expr)
    {
        cout << expr << endl;
        for (size_t i = 0; i < expr.size(); i++)
        {
            if (expr.at(i) == '*' or expr.at(i) == '/')
            {
                size_t j = i;
                while (j != 0 && OPERS.find(expr.at(j)) != OPERS.npos)
                {
                    j--;
                }
                j -= j != 0 ? 1 : 0;

                goodExpr = expr.substr(j, expr.size() - j) + expr.substr(0, j);
                
                return makeExprGood(goodExpr.substr(j, goodExpr.size() - 1));
            }
        }
        goodExpr += expr.substr(goodExpr.size(), expr.size() - goodExpr.size());
    }

    string calculate(string goodExpr)
    {
        short isFinal = 0;
        for (char op : OPERS)
        {
            isFinal += goodExpr.find(op) == goodExpr.npos ? 1 : 0;
        }
        if (isFinal == 4)
        {
            return goodExpr;
        }

        string num1{"0"};
        string num2{"0"};
        char oper{' '};
        bool first{true};
        
        for (size_t i = 0; i < goodExpr.size(); i++)
        {
            char lt = goodExpr.at(i);
            if (OPERS.find(lt) != OPERS.npos and first)
            {
                oper = lt;
                first = not first;
                continue;
            }
            else if (OPERS.find(lt) != OPERS.npos and not first)
            {
                double semires{0};
                double num1d = stod(num1);
                double num2d = stod(num2);

                switch (oper)
                {
                    case '+':
                        semires = num1d + num2d;
                        break;
                    case '-':
                        semires = num1d - num2d;
                        break;
                    case '*':
                        semires = num1d * num2d;
                        break;
                    case '/':
                        semires = num1d / num2d;
                        break;
                }
                return calculate(format("{}{}", semires, goodExpr.substr(0, i)));
            }

            if (first)
            {
                num1 += lt;
            }
            else
            {
                num2 += lt;
            }
            first = not first;
        }
    }

    void unbracket()
    {
        if (problem == "BAD")
        {
            cout << "Неверное выражение\n";
            return;
        }

        for (size_t i = 0; i < problem.size(); i++)
        {
            if (problem.at(i) == '(')
            {
                size_t lastgood = i;
                for (size_t j = lastgood; j < problem.size(); j++)
                {
                    lastgood = problem.at(j) == '(' ? j : lastgood;
                }

                size_t pos = problem.find(')');
                if (pos == problem.npos)
                {
                    problem = "BAD";
                    return;
                }
                size_t moss = pos;

                cout << format("shit {}", moss);
                makeExprGood(problem.substr(lastgood+1, moss - lastgood + 1));
                
                cout << format("Bad: {}\n", problem.substr(lastgood+1, moss - lastgood + 1));
                cout << format("Good: {}\n", goodExpr);
                problem.replace(lastgood, pos, format("{}{}", calculate(goodExpr), problem.substr(moss, problem.size() - moss - 1)));
                cout << calculate(problem.substr(lastgood, problem.size() - moss - 1)) << endl;
                return unbracket();
            }
        }
        return;
    }
};

int main()
{
    Calc calc = Calc();
    calc.setProblem();
    calc.solve();
    cout << calc.getProblem();

    return 0;
}