#include <iostream>
using namespace std;
void newLine ()
{
  cout << endl;
}

void threeLine ()
{
  newLine ();  newLine ();  newLine ();
}

void nLines (int n) {
  if (n > 0) {
    cout << endl;
    nLines (n-1);
  }
}

int main ()
{
  cout << "First Line." << endl;
  nLines (3);
  cout << "Second Line." << endl;
}

