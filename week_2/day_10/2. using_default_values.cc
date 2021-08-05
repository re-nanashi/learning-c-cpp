#include <iostream>

using namespace std;

//Rectangle class declaration
class Rectangle
{
public:
    //constructors
    Rectangle(int width, int height);
    ~Rectangle() {}
    void DrawShape(int a_width, int a_height, bool use_current_vals = false) const;

private:
    int its_width_;
    int its_height_;
};

//Constructor implementation
Rectangle::Rectangle(int width, int height) : its_width_(width), its_height_(height) {}

//default values used for third parameter
void Rectangle::DrawShape(int a_width, int a_height, bool use_current_value) const
{
    int print_width;
    int print_height;

    if (use_current_value == true)
    {
        print_width = its_width_;
        print_height = its_height_;
    }
    else
    {
        print_width = a_width;
        print_height = a_height;
    }

    for (int i = 0; i < print_height; ++i)
    {
        for (int j = 0; j < print_width; ++j)
        {
            cout << "*";
        }

        cout << endl;
    }
}

//Driver program to demonstrate overloaded functions
int main()
{
    //initialize a rectangle to 30,5
    Rectangle the_rect(30, 5);
    cout << "DrawShape(0, 0, true)..." << endl;
    the_rect.DrawShape(0, 0, true);

    cout << "DrawShape(40,2)..." << endl;
    the_rect.DrawShape(40, 2);

    return 0;
}