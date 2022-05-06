// static is accessible to all template class of the same type
#include <iostream>

template <typename T> class TestStatic
{
  public:
    static int staticVal;
};

// NOTE: static member initialization. IMPORTANT
template <typename T> int TestStatic<T>::staticVal;

int main()
{
    using std::cout;
    using std::endl;

    TestStatic<int> intInstance;
    cout << "Setting staticVal for intInstance to 2011" << endl;
    intInstance.staticVal = 2011;

    TestStatic<double> dbInstance;
    cout << "Setting staticVal for dbInstance to 1011" << endl;
    dbInstance.staticVal = 1011;

    cout << "intInstance.staticVal = " << intInstance.staticVal << endl;
    cout << "dbInstance.staticVal = " << dbInstance.staticVal << endl;

    return 0;
}
