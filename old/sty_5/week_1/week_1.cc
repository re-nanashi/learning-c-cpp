#include <iostream>

using namespace std;

enum CHOICE
{
    DrawRect = 1,
    GetArea,
    GetPerim,
    ChangeDimensions,
    Quit
};

//Rect class declaration
class Rectangle
{
public:
    //constructors
    Rectangle(int width, int height);
    ~Rectangle() {}

    //accessors
    int GetHeight() const { return its_height_; }
    int GetWidth() const { return its_width_; }
    int GetArea() const { return its_height_ * its_width_; }
    int GetPerim() const { return 2 * its_height_ + 2 * its_width_; }
    void SetSize(int new_width, int new_height);

private:
    int its_width_;
    int its_height_;
};

Rectangle::Rectangle(int width, int height)
{
    its_width_ = width;
    its_height_ = height;
}

void Rectangle::SetSize(int new_width, int new_height)
{
    its_width_ = new_width;
    its_height_ = new_height;
}

int DoMenu();
void DoDrawRect(Rectangle);
void DoGetArea(Rectangle);
void DoGetPerim(Rectangle);

int main()
{
    Rectangle the_rect(30, 5);

    int choice = DrawRect;

    int f_quit = false;

    while (!f_quit)
    {
        choice = DoMenu();

        if (choice < DrawRect || choice > Quit)
        {
            cout << "\nInvalid Choice, try again. ";
            cout << endl
                 << endl;
            continue;
        }

        switch (choice)
        {
        case DrawRect:
            DoDrawRect(the_rect);
            break;
        case GetArea:
            DoGetArea(the_rect);
            break;
        case GetPerim:
            DoGetPerim(the_rect);
            break;
        case ChangeDimensions:
            int new_length, new_width;
            cout << "\nNew width: ";
            cin >> new_width;
            cout << "New height: ";
            cin >> new_length;

            the_rect.SetSize(new_width, new_length);
            DoDrawRect(the_rect);
            break;
        case Quit:
            f_quit = true;
            cout << "\nExiting..." << endl
                 << endl;
            break;

        default:
            cout << "Error in choice!" << endl;
            f_quit = true;
            break;
        }
    }

    return 0;
}

int DoMenu()
{
    int choice;

    cout << endl
         << endl;
    cout << " ** Menu *** " << endl;
    cout << "(1) Draw Rectangle" << endl;
    cout << "(2) Area" << endl;
    cout << "(3) Perimeter" << endl;
    cout << "(4) Resize" << endl;
    cout << "(5) Quit" << endl;

    cin >> choice;
    return choice;
}

void DoDrawRect(Rectangle the_rect)
{
    int height = the_rect.GetHeight();
    int width = the_rect.GetWidth();

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void DoGetArea(Rectangle the_rect)
{
    cout << "Area: " << the_rect.GetArea() << endl;
}

void DoGetPerim(Rectangle the_rect)
{
    cout << "Permiter: " << the_rect.GetPerim() << endl;
}