#include <iostream>
#include <math.h>
using namespace std;

int HCF(int n, int d);

class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction() : numerator{0}, denominator{1} {}
    Fraction(int n, int d)
    {
        numerator = n;
        denominator = d;
    }
    Fraction(const Fraction &other)
    {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }
    Fraction operator+(const Fraction &f2)
    {
        Fraction res;
        res.numerator = (this->numerator * f2.denominator) + (this->denominator * f2.numerator);
        res.denominator = this->denominator * f2.denominator;
        int cd = HCF(res.numerator, res.denominator);
        res.numerator /= cd;
        res.denominator /= cd;
        return res;
    }

    Fraction operator-(const Fraction &f2)
    {
        Fraction res;
        res.numerator = (this->numerator * f2.denominator) - (this->denominator * f2.numerator);
        res.denominator = this->denominator * f2.denominator;
        int cd = HCF(res.numerator, res.denominator);
        res.numerator /= cd;
        res.denominator /= cd;
        return res;
    }

    Fraction operator*(const Fraction &f2)
    {
        Fraction res;
        res.numerator = this->numerator * f2.numerator;
        res.denominator = this->denominator * f2.denominator;
        int cd = HCF(res.numerator, res.denominator);
        res.numerator /= cd;
        res.denominator /= cd;
        return res;
    }

    Fraction operator/(const Fraction &f2)
    {
        Fraction res;
        res.numerator = this->numerator * f2.denominator;
        res.denominator = this->denominator * f2.numerator;
        int cd = HCF(res.numerator, res.denominator);
        res.numerator /= cd;
        res.denominator /= cd;
        return res;
    }

    friend Fraction operator+(int val, Fraction f);
    friend Fraction operator+(Fraction f, int val);
    friend istream &operator>>(istream &in, Fraction &f);
    friend ostream &operator<<(ostream &out, Fraction &f);

    void operator=(const Fraction &f2)
    {
        this->numerator = f2.numerator;
        this->denominator = f2.denominator;
    }

    bool operator==(const Fraction &f2)
    {
        if ((this->numerator * f2.denominator) == (this->denominator * f2.numerator))
            return true;
        return false;
    }

    bool operator!=(const Fraction &f2)
    {
        if ((this->numerator * f2.denominator) != (this->denominator * f2.numerator))
            return true;
        return false;
    }

    bool operator<(const Fraction &f2)
    {
        if ((this->numerator * f2.denominator) < (this->denominator * f2.numerator))
            return true;
        return false;
    }

    bool operator>(const Fraction &f2)
    {
        if ((this->numerator * f2.denominator) > (this->denominator * f2.numerator))
            return true;
        return false;
    }

    bool operator<=(const Fraction &f2)
    {
        if ((this->numerator * f2.denominator) <= (this->denominator * f2.numerator))
            return true;
        return false;
    }

    bool operator>=(const Fraction &f2)
    {
        if ((this->numerator * f2.denominator) >= (this->denominator * f2.numerator))
            return true;
        return false;
    }

    void display()
    {
        cout << "Fraction: " << numerator << "/" << denominator << endl;
    }
};

istream &operator>>(istream &in, Fraction &f)
{
    cout << "Enter Numerator & Denominator: ";
    in >> f.numerator >> f.denominator;
    return in;
}

ostream &operator<<(ostream &out, Fraction &f)
{
    out << "Fraction: " << f.numerator << "/" << f.denominator << endl;
    return out;
}

Fraction operator+(Fraction f, int val)
{
    Fraction res;
    res.numerator = val * f.denominator + f.numerator;
    res.denominator = f.denominator;
    int cd = HCF(res.numerator, res.denominator);
    res.numerator /= cd;
    res.denominator /= cd;
    return res;
}

Fraction operator+(int val, Fraction f)
{
    Fraction res;
    res.numerator = val * f.denominator + f.numerator;
    res.denominator = f.denominator;
    int cd = HCF(res.numerator, res.denominator);
    res.numerator /= cd;
    res.denominator /= cd;
    return res;
}

void fractionMenu()
{
    cout << "-----Operator Overloading------\n";
    cout << "1 - Fraction Addition\n";
    cout << "2 - Fraction Subtraction\n";
    cout << "3 - Fraction Multiplication\n";
    cout << "4 - Fraction Division\n";
    cout << "5 - Fraction equality check!\n";
    cout << "6 - Fraction inequality check!\n";
    cout << "7 - Check: F1 < F2\n";
    cout << "8 - Check: F1 > f2\n";
    cout << "9 - Check: F1 >= f2\n";
    cout << "10 - Check: F1 <= f2\n";
    cout << "11 - int + Fraction\n";
    cout << "12 - Fraction + int\n";
    cout << "13 - Return\n";
    cout << "Enter Choice: ";
}

class Complex
{
    double real;
    double complex;

public:
    Complex() : real{0}, complex{0} {}
    Complex(double r, double c) : real{r}, complex{c} {}
    Complex(Complex &c)
    {
        real = c.real;
        complex = c.complex;
    }
    void setData(double r, double c)
    {
        real = r;
        complex = c;
    }
    void operator=(const Complex &other)
    {
        this->real = other.real;
        this->complex = other.complex;
    }
    Complex operator+(const Complex &c2)
    {
        Complex res;
        res.real = this->real + c2.real;
        res.complex = this->complex + c2.complex;

        return res;
    }
    Complex operator-(const Complex &c2)
    {
        Complex res;
        res.real = c2.real - this->real;
        res.complex = c2.complex - this->complex;

        return res;
    }

    friend istream &operator>>(istream &in, Complex &c);
    friend ostream &operator<<(ostream &out, Complex &c);

    bool operator==(const Complex &c2)
    {
        if ((this->real == c2.real) && (this->complex == c2.complex))
            return true;
        return false;
    }
    bool operator!=(const Complex &c2)
    {
        if ((this->real == c2.real) && (this->complex == c2.complex))
            return false;
        return true;
    }
    Complex operator*(const Complex &c2)
    {
        Complex res;

        res.real = (this->real * c2.real) - (this->complex * c2.complex);
        res.complex = (this->real * c2.complex) + (this->complex * c2.real);

        return res;
    }
    void display()
    {
        cout << real << " + " << "(" << complex << "i)" << endl;
    }
};

istream &operator>>(istream &in, Complex &c)
{
    cout << "Enter Real & Imaginary Part: ";
    in >> c.real >> c.complex;
    return in;
}
ostream &operator<<(ostream &out, Complex &c)
{
    out << c.real << " + " << "(" << c.complex << "i)" << endl;
    return out;
}

void complexMenu()
{
    cout << "1 - Complex Addition\n";
    cout << "2 - Complex Subtraction\n";
    cout << "3 - Complex Multiplication\n";
    cout << "4 - Equality Check!\n";
    cout << "5 - Inequality Check!\n";
    cout << "6 - Return\n";
    cout << "Enter Choice: ";
}

class Polynomial
{
    float *coeff;
    int *power;
    int size;

public:
    Polynomial() : coeff{nullptr}, power{nullptr}, size{0} {}
    Polynomial(int s)
    {
        size = s;
        coeff = new float[size];
        power = new int[size];
    }
    Polynomial(const Polynomial &other)
    {
        size = other.size;
        coeff = new float[size];
        power = new int[size];

        for (int i = 0; i < size; i++)
        {
            coeff[i] = other.coeff[i];
            power[i] = other.power[i];
        }
    }

    void setData()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << "Enter Coefficient & Power at " << i + 1 << " idx: ";
            cin >> coeff[i] >> power[i];
        }
    }

    void display()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << coeff[i] << "x^" << power[i];
            if (i < size - 1)
                cout << " + ";
        }
        cout << endl;
    }

    Polynomial &operator=(const Polynomial &other)
    {
        if (this != &other)
        {
            delete[] coeff;
            delete[] power;

            size = other.size;
            coeff = new float[size];
            power = new int[size];

            for (int i = 0; i < size; i++)
            {
                coeff[i] = other.coeff[i];
                power[i] = other.power[i];
            }
        }
        return *this;
    }

    Polynomial operator+(const Polynomial &p) const
    {
        Polynomial res(this->size + p.size);
        int idx = 0;
        for (int i = 0; i < this->size; i++)
        {
            res.coeff[idx] = this->coeff[i];
            res.power[idx] = this->power[i];
            idx++;
        }

        for (int i = 0; i < p.size; i++)
        {
            res.coeff[idx] = p.coeff[i];
            res.power[idx] = p.power[i];
            idx++;
        }

        for (int i = 0; i < res.size; i++)
        {
            for (int j = i + 1; j < res.size; j++)
            {
                if (res.power[i] == res.power[j])
                {
                    res.coeff[i] += res.coeff[j];
                    for (int k = j; k + 1 < res.size; k++)
                    {
                        res.coeff[k] = res.coeff[k + 1];
                        res.power[k] = res.power[k + 1];
                    }
                    res.size--;
                    j--;
                }
            }
        }
        return res;
    }

    Polynomial operator+(int val) const
    {
        Polynomial res(this->size + 1);
        int idx = 0;
        for (int i = 0; i < this->size; i++)
        {
            res.coeff[idx] = this->coeff[i];
            res.power[idx] = this->power[i];
            idx++;
        }
        res.coeff[idx] = val;
        res.power[idx] = 0;

        for (int i = 0; i < res.size; i++)
        {
            for (int j = i + 1; j < res.size; j++)
            {
                if (res.power[i] == res.power[j])
                {
                    res.coeff[i] += res.coeff[j];
                    for (int k = j; k + 1 < res.size; k++)
                    {
                        res.coeff[k] = res.coeff[k + 1];
                        res.power[k] = res.power[k + 1];
                    }
                    res.size--;
                    j--;
                }
            }
        }
        return res;
    }

    friend Polynomial operator+(int val, const Polynomial &p);

    Polynomial operator-(const Polynomial &p)
    {
        Polynomial res(this->size + p.size);
        int idx = 0;
        for (int i = 0; i < this->size; i++)
        {
            res.coeff[idx] = this->coeff[i];
            res.power[idx] = this->power[i];
            idx++;
        }

        for (int i = 0; i < p.size; i++)
        {
            res.coeff[idx] = p.coeff[i];
            res.power[idx] = p.power[i];
            idx++;
        }

        for (int i = 0; i < res.size; i++)
        {
            for (int j = i + 1; j < res.size; j++)
            {
                if (res.power[i] == res.power[j])
                {
                    res.coeff[i] -= res.coeff[j];
                    for (int k = j; k + 1 < res.size; k++)
                    {
                        res.coeff[k] = res.coeff[k + 1];
                        res.power[k] = res.power[k + 1];
                    }
                    res.size--;
                    j--;
                }
            }
        }
        return res;
    }

    Polynomial operator*(const Polynomial &p)
    {
        Polynomial res(this->size * p.size);
        int idx = 0;

        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < p.size; j++)
            {
                res.coeff[idx] = this->coeff[i] * p.coeff[j];
                res.power[idx] = this->power[i] + p.power[j];
                idx++;
            }
        }

        for (int i = 0; i < res.size; i++)
        {
            for (int j = i + 1; j < res.size; j++)
            {
                if (res.power[i] == res.power[j])
                {
                    res.coeff[i] += res.coeff[j];
                    for (int k = j; k + 1 < res.size; k++)
                    {
                        res.coeff[k] = res.coeff[k + 1];
                        res.power[k] = res.power[k + 1];
                    }
                    res.size--;
                    j--;
                }
            }
        }
        return res;
    }

    friend istream &operator>>(istream &in, Polynomial &p);
    friend ostream &operator<<(ostream &out, Polynomial &p);

    bool operator==(const Polynomial &p)
    {
        if (this->size != p.size)
            return false;
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < p.size; j++)
            {
                if (this->power[i] == p.power[j])
                {
                    if (this->coeff[i] != p.coeff[j])
                        return false;
                    break;
                }
            }
        }
        return true;
    }

    bool operator!=(const Polynomial &p)
    {
        if (*this == p)
            return false;
        return true;
    }

    int evaluate(int x)
    {
        int res = 0;
        for (int i = 0; i < size; i++)
        {
            res += coeff[i] * pow(x, power[i]);
        }
        return res;
    }

    Polynomial differentiate()
    {
        for (int i = 0; i < size; i++)
        {
            this->coeff[i] *= this->power[i];
            if (this->power[i] != 0)
                this->power[i] = this->power[i] - 1;
            else
                this->power[i] = 0;
        }
        return *this;
    }

    Polynomial integration()
    {
        for (int i = 0; i < size; i++)
        {
            this->coeff[i] /= (this->power[i] + 1);
            this->power[i] += 1;
        }
        return *this;
    }

    ~Polynomial()
    {
        delete[] coeff;
        delete[] power;
    }
};

istream &operator>>(istream &in, Polynomial &p);
ostream &operator<<(ostream &out, Polynomial &p);
Polynomial operator+(int val, const Polynomial &p);

void polynomialMenu()
{
    cout << "1 - Polynomial Addition\n";
    cout << "2 - Polynomial Subtraction\n";
    cout << "3 - Polynomial Multiplication\n";
    cout << "4 - Polynomial Evaluation\n";
    cout << "5 - int + Polynomial\n";
    cout << "6 - Polynomial + int\n";
    cout << "7 - Polynomial Equality Check!\n";
    cout << "8 - Polynomial Inequality Check!\n";
    cout << "9 - Differentiate Polynomial\n";
    cout << "10 - Integrate Polynomial\n";
    cout << "11 - Return\n";
    cout << "Enter Choice: ";
}

class Sets
{
    int *set;
    int size;

public:
    Sets() : set{nullptr}, size{0} {}
    Sets(int s)
    {
        size = s;
        set = new int[size];
    }
    Sets(const Sets &other)
    {
        size = other.size;
        set = new int[size];
        for (int i = 0; i < size; i++)
        {
            set[i] = other.set[i];
        }
    }
    void operator=(const Sets &other)
    {
        if (this != &other)
        {
            delete[] set;
            size = other.size;
            set = new int[size];
            for (int i = 0; i < size; i++)
            {
                set[i] = other.set[i];
            }
        }
    }
    Sets operator*(const Sets &s2)
    {
        Sets res(this->size + s2.size);
        int idx = 0;
        for (int i = 0; i < this->size; i++)
        {
            res.set[idx] = this->set[i];
            idx++;
        }
        for (int i = 0; i < s2.size; i++)
        {
            bool found = false;
            for (int j = 0; j < this->size; j++)
            {
                if (s2.set[i] == this->set[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                res.set[idx] = s2.set[i];
                idx++;
            }
        }
        res.size = idx;
        return res;
    }
    Sets operator+(const Sets &s2)
    {
        Sets res(this->size);
        int idx = 0;
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < s2.size; j++)
            {
                if (this->set[i] == s2.set[j])
                {
                    res.set[idx] = this->set[i];
                    idx++;
                    break;
                }
            }
        }
        res.size = idx;
        return res;
    }
    Sets operator-(const Sets &s2)
    {
        Sets res(this->size);
        int idx = 0;
        for (int i = 0; i < this->size; i++)
        {
            bool found = false;
            for (int j = 0; j < s2.size; j++)
            {
                if (this->set[i] == s2.set[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                res.set[idx] = this->set[i];
                idx++;
            }
        }
        res.size = idx;
        return res;
    }
    Sets &operator++()
    {
        for (int i = 0; i < size; i++)
        {
            set[i]++;
        }
        return *this;
    }
    bool operator==(const Sets &s2)
    {
        if (this->size != s2.size)
            return false;
        for (int i = 0; i < this->size; i++)
        {
            bool found = false;
            for (int j = 0; j < s2.size; j++)
            {
                if (this->set[i] == s2.set[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }
    bool operator<(const Sets &s2)
    {
        if (this->size >= s2.size)
            return false;
        for (int i = 0; i < this->size; i++)
        {
            bool found = false;
            for (int j = 0; j < s2.size; j++)
            {
                if (this->set[i] == s2.set[j])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }

    friend bool operator==(int val, const Sets &s);
    friend istream &operator>>(istream &in, Sets &s);
    friend ostream &operator<<(ostream &out, Sets &s);
    ~Sets()
    {
        delete[] set;
    }
};

bool operator==(int val, const Sets &s)
{
    if (s.size != 1)
        return false;
    if (s.set[0] == val)
        return true;
    return false;
}
istream &operator>>(istream &in, Sets &s)
{
    cout << "Enter size of set: ";
    in >> s.size;
    s.set = new int[s.size];
    cout << "Enter elements of set: " << endl;
    for (int i = 0; i < s.size; i++)
    {
        in >> s.set[i];
    }
    return in;
}
ostream &operator<<(ostream &out, Sets &s)
{
    out << "Set: { ";
    for (int i = 0; i < s.size; i++)
    {
        out << s.set[i] << " ";
    }
    out << "}" << endl;
    return out;
}

void setsMenu()
{
    cout << "1 - Intersection of Sets\n";
    cout << "2 - Union of Sets\n";
    cout << "3 - Difference of Sets\n";
    cout << "4 - Equality Check!\n";
    cout << "5 - Single Element Check!\n";
    cout << "6 - Subset Check!\n";
    cout << "7 - Increment Operation\n";
    cout << "8 - Return\n";
    cout << "Enter Choice: ";
}

class Matrix
{
    int **m;
    int rows;
    int cols;
    int LCM(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        int lcm = 1;
        int div = 2;
        while (a > 1 || b > 1)
        {
            if (a % div == 0 && b % div == 0)
            {
                lcm *= div;
                a /= div;
                b /= div;
            }
            else if (a % div == 0)
            {
                lcm *= div;
                a /= div;
            }
            else if (b % div == 0)
            {
                lcm *= div;
                b /= div;
            }
            else
            {
                div++;
            }
        }
        return lcm;
    }
    void regrowCol(int size)
    {
        int new_s = size + 1;
        int **ptr = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            ptr[i] = new int[new_s];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ptr[i][j] = m[i][j];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            delete[] m[i];
        }
        delete[] m;
        m = ptr;
    }
    void regrowRow(int size)
    {
        int new_s = size + 1;
        int **ptr = new int *[new_s];
        for (int i = 0; i < new_s; i++)
        {
            ptr[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ptr[i][j] = m[i][j];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            delete[] m[i];
        }
        delete[] m;
        m = ptr;
    }
    void shrinkRow(int idx)
    {
        int **ptr = new int *[rows - 1];
        for (int i = 0; i < rows - 1; i++)
        {
            ptr[i] = new int[cols];
        }
        int newI = 0;
        for (int i = 0; i < rows; i++)
        {
            if (i == idx)
                continue;
            for (int j = 0; j < cols; j++)
            {
                ptr[newI][j] = m[i][j];
            }
            newI++;
        }
        for (int i = 0; i < rows; i++)
        {
            delete[] m[i];
        }
        delete[] m;
        m = ptr;
    }
    void shrinkCol(int idx)
    {
        int **ptr = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            ptr[i] = new int[cols - 1];
        }
        for (int i = 0; i < rows; i++)
        {
            int newJ = 0;
            for (int j = 0; j < cols; j++)
            {
                if (j == idx)
                    continue;
                ptr[i][newJ] = m[i][j];
                newJ++;
            }
        }
        for (int i = 0; i < rows; i++)
        {
            delete[] m[i];
        }
        delete[] m;
        m = ptr;
    }

public:
    Matrix() : m{nullptr}, rows{0}, cols{0} {}
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        m = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            m[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                m[i][j] = 0;
            }
        }
    }
    Matrix(const Matrix &other)
    {
        if ((this) != &(other))
        {
            rows = other.rows;
            cols = other.cols;
            m = new int *[rows];
            for (int i = 0; i < rows; i++)
            {
                m[i] = new int[cols];
            }
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    m[i][j] = other.m[i][j];
                }
            }
        }
    }
    Matrix(int val)
    {
        rows = 1;
        cols = 1;
        m = new int *[rows];
        m[0] = new int[cols];
        m[0][0] = val;
    }

    void input()
    {
        cout << "Enter elements of matrix: ";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> m[i][j];
            }
        }
    }

    Matrix &operator=(const Matrix &other)
    {
        if (this == &other)
            return *this;
        for (int i = 0; i < rows; i++)
        {
            delete[] m[i];
        }
        delete[] m;
        rows = other.rows;
        cols = other.cols;
        m = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            m[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                m[i][j] = other.m[i][j];
            }
        }
        return *this;
    }
    Matrix operator+(const Matrix &m1)
    {
        if (cols != m1.cols || rows != m1.rows)
        {
            return *this;
        }
        Matrix res(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res.m[i][j] = this->m[i][j] + m1.m[i][j];
            }
        }
        return res;
    }
    Matrix operator-(const Matrix &m1)
    {
        if (cols != m1.cols || rows != m1.rows)
        {
            return *this;
        }
        Matrix res(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res.m[i][j] = this->m[i][j] - m1.m[i][j];
            }
        }
        return res;
    }
    Matrix operator*(const Matrix &m1)
    {
        if (cols != m1.rows)
        {
            return *this;
        }
        Matrix res(rows, m1.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m1.cols; j++)
            {
                res.m[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    res.m[i][j] += this->m[i][k] * m1.m[k][j];
                }
            }
        }
        return res;
    }
    Matrix operator*(int scalar)
    {
        Matrix res(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res.m[i][j] = this->m[i][j] * scalar;
            }
        }
        return res;
    }
    Matrix operator/(int scalar)
    {
        if (scalar == 0)
        {
            return *this;
        }
        Matrix res(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res.m[i][j] = this->m[i][j] / scalar;
            }
        }
        return res;
    }
    Matrix operator-()
    {
        Matrix res(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res.m[i][j] = -this->m[i][j];
            }
        }
        return res;
    }

    bool operator==(const Matrix &other)
    {
        if ((rows == other.rows) && (cols == other.cols))
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (m[i][j] != other.m[i][j])
                        return false;
                }
            }
            return true;
        }
        return false;
    }
    bool operator!=(const Matrix &other)
    {
        if ((rows == other.rows) && (cols == other.cols))
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (m[i][j] != other.m[i][j])
                        return true;
                }
            }
            return false;
        }
        return true;
    }

    Matrix &operator++()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                m[i][j] = m[i][j] + 1;
            }
        }
        return *this;
    }
    Matrix operator++(int)
    {
        Matrix temp = *this;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                m[i][j] = m[i][j] + 1;
            }
        }
        return temp;
    }
    Matrix &operator--()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                m[i][j] = m[i][j] - 1;
            }
        }
        return *this;
    }
    Matrix operator--(int)
    {
        Matrix temp = *this;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                m[i][j] = m[i][j] - 1;
            }
        }
        return temp;
    }

    void addRow()
    {
        regrowRow(rows);
        cout << "Enter elements of new Row: ";
        for (int i = 0; i < cols; i++)
        {
            cin >> m[rows][i];
        }
        rows++;
    }
    void addCol()
    {
        regrowCol(cols);
        cout << "Enter Elements of New Col: ";
        for (int i = 0; i < rows; i++)
        {
            cin >> m[i][cols];
        }
        cols++;
    }
    void deleteRow(int idx)
    {
        if (idx < 0 || idx >= rows)
        {
            cout << "Invalid row index" << endl;
            return;
        }
        shrinkRow(idx);
        rows--;
    }
    void deleteCol(int idx)
    {
        if (idx < 0 || idx >= cols)
        {
            cout << "Invalid column index" << endl;
            return;
        }
        shrinkCol(idx);
        cols--;
    }

    Matrix transpose()
    {
        Matrix res(cols, rows);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res.m[i][j] = m[j][i];
            }
        }
        return res;
    }
    Matrix getMinorMatrix(int r, int c)
    {
        Matrix res(rows - 1, cols - 1);
        int newI = 0;
        for (int i = 0; i < rows; i++)
        {
            if (i == r)
                continue;
            int newJ = 0;
            for (int j = 0; j < cols; j++)
            {
                if (j == c)
                    continue;
                res.m[newI][newJ] = m[i][j];
                newJ++;
            }
            newI++;
        }
        return res;
    }
    Matrix power(int exp)
    {
        Matrix res(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res.m[i][j] = pow(m[i][j], exp);
            }
        }
        return res;
    }
    Matrix zeroMatrixGenerator()
    {
        Matrix res(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res.m[i][j] = 0;
            }
        }
        return res;
    }

    Matrix &upperTriangularMatrix()
    {
        if (rows != cols)
            return *this;
        int pivot;
        int lcm;
        for (int i = 0; i < rows; i++)
        {
            pivot = m[i][i];
            if (pivot == 0)
                continue;
            for (int k = i + 1; k < rows; k++)
            {
                if (m[k][i] == 0)
                    continue;
                lcm = LCM(pivot, m[k][i]);
                int val1 = lcm / abs(pivot);
                int val2 = lcm / abs(m[k][i]);
                if ((pivot < 0) != (m[k][i] < 0))
                    val1 = -val1;
                for (int l = 0; l < cols; l++)
                {
                    m[k][l] = val2 * m[k][l] - val1 * m[i][l];
                }
            }
        }
        return *this;
    }

    Matrix &lowerTriangularMatrix()
    {
        if (rows != cols)
            return *this;
        int pivot;
        int lcm;
        for (int i = 0; i < rows; i++)
        {
            pivot = m[i][i];
            if (pivot == 0)
                continue;
            for (int k = 0; k < i; k++)
            {
                if (m[k][i] == 0)
                    continue;
                lcm = LCM(pivot, m[k][i]);
                int val1 = lcm / abs(pivot);
                int val2 = lcm / abs(m[k][i]);
                if ((pivot < 0) != (m[k][i] < 0))
                    val1 = -val1;
                for (int l = 0; l < cols; l++)
                {
                    m[k][l] = val2 * m[k][l] - val1 * m[i][l];
                }
            }
        }
        return *this;
    }

    int determinant()
    {
        if (rows != cols)
            return -1;
        Matrix copy = *this;
        copy.upperTriangularMatrix();
        int det = 1;
        for (int i = 0; i < copy.rows; i++)
        {
            det *= copy.m[i][i];
        }
        return det;
    }

    Matrix inverse()
    {
        if (rows != cols)
            return *this;
        int det = determinant();
        if (det == 0)
        {
            cout << "Matrix is singular" << endl;
            return *this;
        }
        Matrix res(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == j)
                    res.m[i][j] = 1;
                else
                    res.m[i][j] = 0;
            }
        }
        int pivot;
        int lcm;
        for (int i = 0; i < rows; i++)
        {
            pivot = m[i][i];
            if (pivot == 0)
                continue;
            for (int k = 0; k < rows; k++)
            {
                if (k == i)
                    continue;
                if (m[k][i] == 0)
                    continue;
                lcm = LCM(pivot, m[k][i]);
                int val1 = lcm / abs(pivot);
                int val2 = lcm / abs(m[k][i]);
                if ((pivot < 0) != (m[k][i] < 0))
                    val1 = -val1;
                for (int l = 0; l < cols; l++)
                {
                    m[k][l] = val2 * m[k][l] - val1 * m[i][l];
                    res.m[k][l] = val2 * res.m[k][l] - val1 * res.m[i][l];
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            int div = m[i][i];
            for (int j = 0; j < cols; j++)
            {
                m[i][j] /= div;
                res.m[i][j] /= div;
            }
        }
        return res;
    }

    double trace()
    {
        if (rows == cols)
        {
            double sum = 0;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (i == j)
                    {
                        sum += m[i][j];
                    }
                }
            }
            return sum;
        }
        return -1;
    }

    bool isSquare()
    {
        if (rows == cols)
            return true;
        return false;
    }
    bool isIdentity()
    {
        if (rows != cols)
            return false;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == j)
                {
                    if (m[i][j] != 1)
                        return false;
                }
                else
                {
                    if (m[i][j] != 0)
                        return false;
                }
            }
        }
        return true;
    }
    bool isSymmetric()
    {
        if (rows != cols)
            return false;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (m[i][j] != m[j][i])
                    return false;
            }
        }
        return true;
    }

    void display()
    {
        cout << "Matrix Result\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }

    friend ostream &operator<<(ostream &out, const Matrix &m);
    friend istream &operator>>(istream &in, Matrix &m);

    ~Matrix()
    {
        if (m == nullptr)
            return;
        for (int i = 0; i < rows; i++)
        {
            delete[] m[i];
        }
        delete[] m;
    }
};

istream &operator>>(istream &in, Matrix &m)
{
    cout << "Enter Rows & Cols: ";
    in >> m.rows >> m.cols;
    m.m = new int *[m.rows];
    for (int i = 0; i < m.rows; i++)
    {
        m.m[i] = new int[m.cols];
    }
    cout << "Enter Matrix elements: ";
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            in >> m.m[i][j];
        }
    }
    return in;
}

ostream &operator<<(ostream &out, const Matrix &m)
{
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            out << m.m[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

void matrixMenu()
{
    cout << "1. Add Row\n";
    cout << "2. Add Column\n";
    cout << "3. Delete Row\n";
    cout << "4. Delete Column\n";
    cout << "5. Transpose\n";
    cout << "6. Get Minor Matrix\n";
    cout << "7. Power\n";
    cout << "8. Zero Matrix Generator\n";
    cout << "9. Trace\n";
    cout << "10. Check if Square\n";
    cout << "11. Check if Identity\n";
    cout << "12. Check if Symmetric\n";
    cout << "13. Addition\n";
    cout << "14. Subtraction\n";
    cout << "15. Multiplication\n";
    cout << "16. Scalar Multiplication\n";
    cout << "17. Scalar Division\n";
    cout << "18. Unary Minus\n";
    cout << "19. PreFix Increment\n";
    cout << "20. PreFix Decrement\n";
    cout << "21. PostFix Increment\n";
    cout << "22. PostFix Decrement\n";
    cout << "23. Upper Triangular Matrix\n";
    cout << "24. Lower Triangular Matrix\n";
    cout << "25. Determinant\n";
    cout << "26. Inverse\n";
    cout << "27. Display\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void menu()
{
    cout << "1 - Fraction\n";
    cout << "2 - Complex\n";
    cout << "3 - Polynomials\n";
    cout << "4 - Sets\n";
    cout << "5 - Matrices\n";
    cout << "0 - Exit\n";
    cout << "Enter Choice: ";
}

int main()
{
    int main_choice, choice;
    do
    {
        menu();
        cin >> main_choice;

        if (main_choice == 1)
        {
            Fraction f1, f2;
            cin >> f1 >> f2;
            Fraction res;

            do
            {
                fractionMenu();
                cin >> choice;

                switch (choice)
                {
                case 1:
                    res = f1 + f2;
                    cout << "Fraction Addition....." << endl;
                    cout << res;
                    break;
                case 2:
                    res = f1 - f2;
                    cout << "Fraction Subtraction....." << endl;
                    cout << res;
                    break;
                case 3:
                    res = f1 * f2;
                    cout << "Fraction Multiplication....." << endl;
                    cout << res;
                    break;
                case 4:
                    res = f1 / f2;
                    cout << "Fraction Division....." << endl;
                    cout << res;
                    break;
                case 5:
                    if (f1 == f2)
                        cout << "Fractions are equal!" << endl;
                    else
                        cout << "Fractions are not equal!" << endl;
                    break;
                case 6:
                    if (f1 != f2)
                        cout << "Fractions are not equal!" << endl;
                    else
                        cout << "Fractions are equal!" << endl;
                    break;
                case 7:
                    if (f1 < f2)
                        cout << "Fraction 1 is less than Fraction 2" << endl;
                    else
                        cout << "Fraction 1 is not less than Fraction 2" << endl;
                    break;
                case 8:
                    if (f1 > f2)
                        cout << "Fraction 1 is greater than Fraction 2" << endl;
                    else
                        cout << "Fraction 1 is not greater than Fraction 2" << endl;
                    break;
                case 9:
                    if (f1 >= f2)
                        cout << "Fraction 1 is greater than or equal to Fraction 2" << endl;
                    else
                        cout << "Fraction 1 is not greater  or equal to Fraction 2" << endl;
                    break;
                case 10:
                    if (f1 <= f2)
                        cout << "Fraction 1 is less than or equal to Fraction 2" << endl;
                    else
                        cout << "Fraction 1 is not less than or equal to Fraction 2" << endl;
                    break;
                case 11:
                    int val;
                    cout << "Enter value: ";
                    cin >> val;
                    res = val + f1;
                    cout << res;
                    break;
                case 12:
                    int val1;
                    cout << "Enter value: ";
                    cin >> val1;
                    res = f1 + val1;
                    cout << res;
                    break;
                case 13:
                    cout << "Returning......." << endl;
                    break;
                default:
                    cout << "Invalid Choice! Try Again...." << endl;
                }
            } while (choice != 13);
        }
        else if (main_choice == 2)
        {
            Complex c1, c2;
            cin >> c1 >> c2;
            Complex res;

            do
            {
                complexMenu();
                cin >> choice;
                switch (choice)
                {
                case 1:
                    res = c1 + c2;
                    cout << "Complex Addition....." << endl;
                    cout << res;
                    break;
                case 2:
                    res = c2 - c1;
                    cout << "Complex Subtraction....." << endl;
                    cout << res;
                    break;
                case 3:
                    res = c1 * c2;
                    cout << "Complex Multiplication....." << endl;
                    cout << res;
                    break;
                case 4:
                    if (c1 == c2)
                        cout << "Complex numbers are Equal!" << endl;
                    else
                        cout << "Complex numbers are not Equal!" << endl;
                    break;
                case 5:
                    if (c1 != c2)
                        cout << "Complex numbers are not Equal!" << endl;
                    else
                        cout << "Complex numbers are Equal!" << endl;
                    break;
                case 6:
                    cout << "Returning....." << endl;
                    break;
                default:
                    cout << "Invalid Choice.... Try Again!" << endl;
                }
            } while (choice != 6);
        }
        else if (main_choice == 3)
        {
            Polynomial p1, p2;
            cin >> p1 >> p2;
            Polynomial res;
            int val, ans;

            do
            {
                polynomialMenu();
                cin >> choice;

                switch (choice)
                {
                case 1:
                    res = p1 + p2;
                    cout << "Addition Result: ";
                    cout << res;
                    break;
                case 2:
                    res = p1 - p2;
                    cout << "Subtraction Result: ";
                    cout << res;
                    break;
                case 3:
                    res = p1 * p2;
                    cout << "Multiplication Result: ";
                    cout << res;
                    break;
                case 4:
                    cout << "Enter Value to evaluate: ";
                    cin >> val;
                    ans = p1.evaluate(val);
                    cout << "Result of Polynomial at x = " << val << ": " << ans << endl;
                    ans = p2.evaluate(val);
                    cout << "Result of Polynomial at x = " << val << ": " << ans << endl;
                    break;
                case 5:
                    cout << "Enter Value for value+Polynomial: ";
                    cin >> val;
                    res = p1 + val;
                    cout << res;
                    break;
                case 6:
                    cout << "Enter Value for value+Polynomial: ";
                    cin >> val;
                    res = val + p1;
                    cout << res;
                    break;
                case 7:
                    if (p1 == p2)
                        cout << "Polynomials are equal!" << endl;
                    else
                        cout << "Polynomials are not equal!" << endl;
                    break;
                case 8:
                    if (p1 != p2)
                        cout << "Polynomials are not equal!" << endl;
                    else
                        cout << "Polynomials are equal!" << endl;
                    break;
                case 9:
                    res = p1.differentiate();
                    cout << "Result of Differentiation: ";
                    cout << res;

                    res = p2.differentiate();
                    cout << "Result of Differentiation: ";
                    cout << res;
                    break;
                case 10:
                    res = p1.integration();
                    cout << "Result of Integration: ";
                    cout << res;

                    res = p2.integration();
                    cout << "Result of Integration: ";
                    cout << res;
                    break;
                case 11:
                    cout << "Returning....." << endl;
                    break;
                default:
                    cout << "Invalid Choice..... Try Again!" << endl;
                }
            } while (choice != 11);
        }
        else if (main_choice == 4)
        {
            Sets s1, s2;
            cin >> s1 >> s2;
            Sets res;
            do
            {
                setsMenu();
                cin >> choice;
                switch (choice)
                {
                case 1:
                    res = s1 + s2;
                    cout << "Intersection of Sets: " << endl;
                    cout << res;
                    break;
                case 2:
                    res = s1 * s2;
                    cout << "Union of Sets: " << endl;
                    cout << res;
                    break;
                case 3:
                    res = s1 - s2;
                    cout << "Difference of Sets: " << endl;
                    cout << res;
                    break;
                case 4:
                    if (s1 == s2)
                        cout << "Sets are Equal!" << endl;
                    else
                        cout << "Sets are not Equal!" << endl;
                    break;
                case 5:
                    int val;
                    cout << "Enter value to check: ";
                    cin >> val;
                    if (val == s1)
                        cout << val << " is present in Set 1" << endl;
                    else
                        cout << val << " is not present in Set 1" << endl;

                    if (val == s2)
                        cout << val << " is present in Set 2" << endl;
                    else
                        cout << val << " is not present in Set 2" << endl;
                    break;
                case 6:
                    if (s1 < s2)
                        cout << "Set 1 is a subset of Set 2" << endl;
                    else
                        cout << "Set 1 is not a subset of Set 2" << endl;
                    break;
                case 7:
                    ++s1;
                    ++s2;
                    cout << "After Incrementing....." << endl;
                    cout << "Set 1: " << endl;
                    cout << s1;

                    cout << "Set 2: " << endl;
                    cout << s2;
                    break;
                case 8:
                    cout << "Returning....." << endl;
                    break;
                default:
                    cout << "Invalid Choice..... Try Again!" << endl;
                }
            } while (choice != 8);
        }
        else if (main_choice == 5)
        {
            Matrix m1, m2;
            cin >> m1;
            do
            {
                matrixMenu();
                cin >> choice;
                if (choice == 0)
                {
                    cout << "Exiting..." << endl;
                    break;
                }
                else if (choice == 1)
                {
                    m1.addRow();
                    cout << m1;
                }
                else if (choice == 2)
                {
                    m1.addCol();
                    cout << m1;
                }
                else if (choice == 3)
                {
                    int idx;
                    cout << "Enter Row Index to Delete: ";
                    cin >> idx;
                    m1.deleteRow(idx);
                    cout << m1;
                }
                else if (choice == 4)
                {
                    int idx;
                    cout << "Enter Column Index to Delete: ";
                    cin >> idx;
                    m1.deleteCol(idx);
                    cout << m1;
                }
                else if (choice == 5)
                {
                    Matrix res = m1.transpose();
                    cout << res;
                }
                else if (choice == 6)
                {
                    int r, c;
                    cout << "Enter Row & Column Index for Minor Matrix: ";
                    cin >> r >> c;
                    Matrix res = m1.getMinorMatrix(r, c);
                    cout << res;
                }
                else if (choice == 7)
                {
                    int exp;
                    cout << "Enter Exponent: ";
                    cin >> exp;
                    Matrix res = m1.power(exp);
                    cout << res;
                }
                else if (choice == 8)
                {
                    Matrix res = m1.zeroMatrixGenerator();
                    cout << res;
                }
                else if (choice == 9)
                {
                    double trace = m1.trace();
                    if (trace != -1)
                        cout << "Trace: " << trace << endl;
                    else
                        cout << "Matrix is not square" << endl;
                }
                else if (choice == 10)
                {
                    if (m1.isSquare())
                        cout << "Matrix is Square" << endl;
                    else
                        cout << "Matrix is not Square" << endl;
                }
                else if (choice == 11)
                {
                    if (m1.isIdentity())
                        cout << "Matrix is Identity" << endl;
                    else
                        cout << "Matrix is not Identity" << endl;
                }
                else if (choice == 12)
                {
                    if (m1.isSymmetric())
                        cout << "Matrix is Symmetric" << endl;
                    else
                        cout << "Matrix is not Symmetric" << endl;
                }
                else if (choice == 13)
                {
                    cout << "Enter Second Matrix for Addition: ";
                    cin >> m2;
                    Matrix res = m1 + m2;
                    cout << res;
                }
                else if (choice == 14)
                {
                    cout << "Enter Second Matrix for Subtraction: ";
                    cin >> m2;
                    Matrix res = m1 - m2;
                    cout << res;
                }
                else if (choice == 15)
                {
                    cout << "Enter Second Matrix for Multiplication: ";
                    cin >> m2;
                    Matrix res = m1 * m2;
                    cout << res;
                }
                else if (choice == 16)
                {
                    int scalar;
                    cout << "Enter Scalar for Multiplication: ";
                    cin >> scalar;
                    Matrix res = m1 * scalar;
                    cout << res;
                }
                else if (choice == 17)
                {
                    int scalar;
                    cout << "Enter Scalar for Division: ";
                    cin >> scalar;
                    Matrix res = m1 / scalar;
                    cout << res;
                }
                else if (choice == 18)
                {
                    Matrix res = -m1;
                    cout << res;
                }
                else if (choice == 19)
                {
                    Matrix res = ++m1;
                    cout << "After PreFix Increment: " << endl;
                    cout << res;
                }
                else if (choice == 20)
                {
                    Matrix res = --m1;
                    cout << "After PreFix Decrement: " << endl;
                    cout << res;
                }
                else if (choice == 21)
                {
                    Matrix res = m1++;
                    cout << "After PostFix Increment: " << endl;
                    cout << res;
                }
                else if (choice == 22)
                {
                    Matrix res = m1--;
                    cout << "After PostFix Decrement: " << endl;
                    cout << res;
                }
                else if (choice == 23)
                {
                    m1.upperTriangularMatrix();
                    cout << m1;
                }
                else if (choice == 24)
                {
                    m1.lowerTriangularMatrix();
                    cout << m1;
                }
                else if (choice == 25)
                {
                    int det = m1.determinant();
                    if (det != -1)
                        cout << "Determinant: " << det << endl;
                    else
                        cout << "Matrix is not square" << endl;
                }
                else if (choice == 26)
                {
                    Matrix res = m1.inverse();
                    cout << res;
                }
                else if (choice == 27)
                {
                    m1.display();
                }
                else
                {
                    cout << "Invalid Choice" << endl;
                }
            } while (choice != 0);
        }
        else if (main_choice == 0)
        {
            cout << "Exiting....." << endl;
        }
        else
        {
            cout << "Invalid Choice..... Try Again!" << endl;
        }
    } while (main_choice != 0);
    return 0;
}

int HCF(int n, int d)
{
    int i;
    if (n > d)
        i = d;
    else if (n < d)
        i = n;
    else
        return n;
    for (; i >= 1; i--)
    {
        if ((n % i == 0) && (d % i == 0))
            return i;
    }
    return 1;
}
Polynomial operator+(int val, const Polynomial &p)
{
    return p + val;
}
istream &operator>>(istream &in, Polynomial &p)
{
    cout << "Enter size of polynomial: ";
    in >> p.size;
    p.coeff = new float[p.size];
    p.power = new int[p.size];
    for (int i = 0; i < p.size; i++)
    {
        cout << "Enter Coefficient & Power at " << i + 1 << " idx: ";
        in >> p.coeff[i] >> p.power[i];
    }
    return in;
}
ostream &operator<<(ostream &out, Polynomial &p)
{
    out << "Polynomial: ";
    for (int i = 0; i < p.size; i++)
    {
        out << p.coeff[i] << "x^" << p.power[i];
        if (i < p.size - 1)
            out << " + ";
    }
    out << endl;
    return out;
}
