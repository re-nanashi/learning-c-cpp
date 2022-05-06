#include <iostream>

using namespace std;

class Rectangle
{
public:
    Rectangle();
    Rectangle(int width, int length);
    ~Rectangle() {}
    int GetWidth() const { return its_width_; }
    int GetLength() const { return its_length_; }

private:
    int its_width_;
    int its_length_;
};

Rectangle::Rectangle()
{
    its_width_ = 5;
    its_length_ = 10;
}

Rectangle::Rectangle(int width, int length)
{
    its_width_ = width;
    its_length_ = length;
}

int main()
{
    Rectangle rect_one;
    cout << "rect_one width: " << rect_one.GetWidth() << endl;
    cout << "rect_one length: " << rect_one.GetLength() << endl;

    int a_width, a_length;
    cout << "Enter a width: ";
    cin >> a_width;
    cout << "\nEnter a length: ";
    cin >> a_length;

    Rectangle rect_two(a_width, a_length);
    cout << "\nrect_two width: " << rect_two.GetWidth() << endl;
    cout << "rect_two length: " << rect_two.GetLength() << endl;

    return 0;
}