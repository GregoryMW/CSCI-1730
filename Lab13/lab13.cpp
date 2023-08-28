#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<std::string> words;
  string temp;
  multimap<string, string> m;

  while (getline(cin, temp))
    {
      if (find(words.begin(), words.end(), temp) != words.end())
	{
	  m.insert(pair<string, string>(temp, temp));
	}
      else
	{
	  m.insert(pair<string, string>(temp, temp));
	  words.push_back(temp);
	}
    }

  for(size_t i = 0, e = words.size(); i != e; ++i)
    {
      cout << m.count(words[i]) << " " << words[i] << endl;
    }
  return 0;
}
