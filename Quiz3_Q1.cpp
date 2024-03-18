// IN THE QUESTION P3'S REPRESENTATION IS WRONG: (3,5) --> 5X+3 NOT 3X + 5 SO ANSWER FOR MULTIPLY(P2,P3) --> IS (6,16,13,5) NOT (10, 16, 11, 3)
#include <iostream>
#include <vector>
using namespace std;

class Polynomial
{
private:
    vector<double> coefficients;

public:
    Polynomial(vector<double> c)
    {
        coefficients = c;
    }
    void print()
    {
        for (int i = 0; i < coefficients.size(); i++)
        {
            cout << coefficients[i] << " ";
        }
    }
    int getCoefficient(int i)
    {
        return coefficients[i];
    }
    int getDegree()
    {
        return coefficients.size();
    }
};

Polynomial add(Polynomial p, Polynomial q)
{
    vector<double> c;
    int i = 0;
    if (p.getDegree() > q.getDegree())
    {
        while (i < q.getDegree())
        {
            c.push_back(p.getCoefficient(i) + q.getCoefficient(i));
            i++;
        }
        while (i < p.getDegree())
        {
            c.push_back(p.getCoefficient(i));
            i++;
        }
    }
    else
    {
        while (i < p.getDegree())
        {
            c.push_back(p.getCoefficient(i) + q.getCoefficient(i));
            i++;
        }
        while (i < q.getDegree())
        {
            c.push_back(q.getCoefficient(i));
            i++;
        }
    }
    Polynomial r(c);
    return r;
}

Polynomial multiply(Polynomial p, Polynomial q)
{
    vector<double> c;
    for (int i = 0; i < p.getDegree() + q.getDegree() - 1; i++)
    {
        c.push_back(0);
    }
    for (int i = 0; i < p.getDegree(); i++)
    {
        for (int j = 0; j < q.getDegree(); j++)
        {
            c[i + j] = c[i + j] + p.getCoefficient(i) * q.getCoefficient(j);
        }
    }
    Polynomial r(c);
    return r;
}

int main()
{
    vector<double> c = {2, 2, 1};
    Polynomial p(c);
    vector<double> c2 = {3, 5};
    Polynomial q(c2);
    Polynomial r = multiply(p, q);
    r.print();
}