/*  
 *  CS 2024 ass02
 *  Author: Palash A. [pa334]
 *  Date: September 5, 2019
 *
 */

#include <iostream>

using namespace std;

class Rectangle {
  private:
    int mWidth;
    int mHeight;

  public:

    Rectangle() { mWidth = 0; mHeight = 0; }

    void setDimensions(int width, int height) {
      mWidth = width;
      mHeight = height;
      if (width < 0 || height < 0) { 
        mWidth = 0; 
        mHeight = 0;
      } // Reset rectangle as invalid input
    }

    int area() { return mWidth*mHeight; }

    int circumference() { return 2*(mWidth+mHeight); }

    void print() { cout << "Rectangle(" << mWidth << "," << mHeight << ")\n"; }
};

int main(int argc, char* argv[]) {
  Rectangle rect = Rectangle();
  rect.print();
  int w,h;
  cout << "Enter width: ";
  cin >> w;
  cout << "Enter height: ";
  cin >> h;
  rect.setDimensions(w,h);
  rect.print();
  cout << "Area: " << rect.area() << endl;
  cout << "Circumference: " << rect.circumference() << endl; 
  return 0;
}

// To run: $ clang -lstdc++ -o ass02 ass02.cpp