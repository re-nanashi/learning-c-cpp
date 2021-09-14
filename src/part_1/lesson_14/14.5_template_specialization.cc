#include <iostream>

template <typename T1 = int, typename T2 = double> class HoldsPair
{
  public:
    HoldsPair(const T1 &val1, const T2 &val2) : value1(val1), value2(val2)
    {
    }
    const T1 &GetFirstValue() const
    {
        return value1;
    }

    const T2 &GetSecondValue() const
    {
        return value2;
    }

  private:
    T1 value1;
    T2 value2;
};

// specialized template for int
template <> class HoldsPair<int, int>
{
  public:
    HoldsPair(const int &val1, const int &val2) : value1(val1), value2(val2)
    {
    }

    const int &GetFirstValue() const
    {
        std::cout << "Returning integer " << value1 << std::endl;
        return value1;
    }

  private:
    int value1;
    int value2;
    std::string strFun;
};

int main()
{
    HoldsPair<int, int> pairIntInt(222, 333);
    pairIntInt.GetFirstValue();

    return 0;
}
