#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;
int main ()
{
  string first;
  first = "Hello, ";
  string second = "world.";
  first[0] = 'J';
  cout << first << second << endl;

  string fruit = "banana";
  int length = fruit.length();
  int count = 0;

  int index = 0;
  while (index < length) {
    if (fruit[index] == 'a') {
      count++;
    }
    index++;
  }
  cout << count << endl;

  double x = 1.0;
  cout << ++x << endl;

  string bakedGood = " nut bread";

  char letter = 'J';
  string suffix = "ack";
  while (letter <= 'Q') {
    cout << letter + suffix << endl;
    letter++;
  }

  string greeting = "Hello, world.";
  greeting[0] = 'J';
  int last = greeting.length() -1;
  greeting[last] = '!';
  cout << greeting << endl;

  string word;
  cin >> word;
  if (word < "banana") {
    cout << "Your word, " << word << ", comes before banana." << endl;
  } else if (word > "banana") {
    cout << "Your word, " << word << ", comes after banana." << endl;
  } else {
    cout << "Yes, we have no bananas!" << endl;
  }

  letter = 'a';
  letter = toupper (letter);
  if (isalpha(letter)) {
    cout << "The character " << letter << " is a letter." << endl;
  }
}

