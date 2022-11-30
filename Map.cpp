#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;
int main()
{
    map<string, int> populationMap;
    populationMap.insert({"China", 1339});


    map<string,int>::iterator iter = populationMap.end();
    populationMap.erase(iter);
    cout << "Size of populationMap: " << populationMap.size() << '\n';
    for (iter = populationMap.begin(); iter != populationMap.end(); ++iter)
    {
        cout << iter->first << ": "
             << iter->second << " million\n";
    }
    string country("Indonesia");
    iter = populationMap.find(country);
    if (iter != populationMap.end())
        cout << country << "'s populations is "
             << iter->second << " million\n";
    else
        cout << "Key is not in populationMap" << '\n';
    populationMap.clear();
}
