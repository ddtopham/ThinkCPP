#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>
#include "matrix.h"
using std::vector;distances
using std::string;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
class Set {
private:
  vector<string> elements;
  int numElements;

public:
  Set (int n);

  int find (const string& s) const;
  int add (const string& s);
  string getElement (int i) const;
  int getNumElements () const;
};

Set::Set (int n)
{
  vector<string> temp (n);
  elements = temp;
  numElements = 0;
}

int Set::find (const string& s) const
{
  for (int i=0; i<numElements; i++) {
    if (elements[i] == s) return i;
  }
  return -1;
}

int Set::add (const string& s)
{
  // if the element is already in the set, return its index
  int index = find (s);
  if (index != -1) return index;

  // if the vector is full, double its size
  if (numElements == elements.size()) {
    elements.resize (elements.size() * 2);
  }

  // add the new elements and return its index
  index = numElements;
  elements[index] = s;
  numElements++;
  return index;
}

string Set::getElement (int i) const
{
  if (i < numElements) {
    return elements[i];
  } else {
    cout << "Set index out of range." << endl;
    exit (1);
  }
}

int Set::getNumElements () const
{
  return numElements;
}

int find (const string& s, char c, int i)
{
  while (i<s.size()) {
    if (s[i] == c) return i;
    i = i + 1;
  }
  return -1;
}

int convertToInt (const string& s)
{
  string digitString = "";

  for (int i=0; i<s.size(); i++) {
    if (isdigit (s[i])) {
      digitString += s[i];
    }
  }
  return atoi (digitString.c_str());
}

void processLine (const string& line, Set& cities, matrix<int>& distances)
{
  // the character we are looking for is a quotation mark
  char quote = '\"';

  // store the indices of the quotation marks in a vector
  vector<int> quoteIndex (4);

  // find the first quotation mark using the built-in find
  quoteIndex[0] = line.find (quote);

  // find the other quotation marks using the find from Chapter 7
  for (int i=1; i<4; i++) {
    quoteIndex[i] = find (line, quote, quoteIndex[i-1]+1);
  }

  // break the line up into substrings
  int len1 = quoteIndex[1] - quoteIndex[0] - 1;
  string city1 = line.substr (quoteIndex[0]+1, len1);
  int len2 = quoteIndex[3] - quoteIndex[2] - 1;
  string city2 = line.substr (quoteIndex[2]+1, len2);
  int len3 = line.size() - quoteIndex[2] - 1;
  string distString = line.substr (quoteIndex[3]+1, len3);
  int dist = convertToInt (distString);

  int index1 = cities.add (city1);
  int index2 = cities.add (city2);

  distances[index1][index2] = dist;
  distances[index2][index1] = dist;
}

int main ()
{
  string name;
  string line;
  int x;
  ifstream infile ("distances");
  ofstream outfile ("temp");
  Set cities (2);

  matrix<int> distances (50, 50, 0);

  if (infile.good() == false || outfile.good() == false) {
    cout << "Unable to open one of the files." << endl;
    exit (1);
  }

  while (true) {
    getline (infile, line);
    if (infile.eof()) break;
    processLine (line, cities, distances);
  }


  for (int i=0; i<cities.getNumElements(); i++) {
    cout << cities.getElement(i) << "\t";

    for (int j=0; j<=i; j++) {
      cout << distances[i][j] << "\t";
    }
    cout << endl;
  }

  cout << "\t";
  for (int i=0; i<cities.getNumElements(); i++) {
    cout << cities.getElement(i) << "\t";
  }
  cout << endl;
}

