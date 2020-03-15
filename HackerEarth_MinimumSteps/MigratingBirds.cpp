#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <utility>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

std::pair<int, int> flip_pair(const std::pair<int, int> &p)
{
    return std::pair<int, int>(p.second, p.first);
}
// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) {
    map<int, int> KeyValPair = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}};
    
    for_each(arr.begin(), arr.end(), [&](int val)
    {
        KeyValPair[val]++;
    });
    std::multimap<int, int> dst;
std::transform(KeyValPair.begin(), KeyValPair.end(), std::inserter(dst, dst.begin()), flip_pair);
 
      multimap<int, int> :: iterator iter;
    for (iter=dst.begin(); iter!=dst.end(); iter++) 
    {
        // printing the second value first because the 
        // order of (key,value) is reversed in the multimap
        if( iter->first == dst.crbegin()->first)   break;
    }         
   //cout << dst.begin()->second ;
    return iter->second;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
