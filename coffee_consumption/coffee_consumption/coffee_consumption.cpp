// coffee_consumption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <algorithm>

using namespace std;

bool isNumber(const string& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int main()
{
    vector<string> sentences =
    { "Auckland,Jan,420",
        "Auckland,Feb,368",
        "Auckland,Mar,345",
        "Auckland,Apl,758",
        "Auckland,May,158",
        "Auckland,Jun,358",
        "Auckland,Jul,957",
        "Auckland,Aus,106",
        "Auckland,Sep,746",
        "Auckland,Oct,486",
        "Auckland,Nov,175",
        "Auckland,Dec,856",
        "Chrischurch,Jan,457",
        "Chrischurch,Feb,346",
        "Chrischurch,Mar,467",
        "Chrischurch,Apl,327",
        "Chrischurch,May,204",
        "Chrischurch,Jun,565",
        "Chrischurch,Jul,654",
        "Chrischurch,Aus,486",
        "Chrischurch,Sep,540",
        "Chrischurch,Oct,346",
        "Chrischurch,Nov,396",
        "Chrischurch,Dec,296",
        "Hamilton,Jan,653",
        "Hamilton,Feb,346",
        "Hamilton,Mar,574",
        "Hamilton,Apl,396",
        "Hamilton,May,238",
        "Hamilton,Jun,395",
        "Hamilton,Jul,947",
        "Hamilton,Aus,385",
        "Hamilton,Sep,395",
        "Hamilton,Oct,206",
        "Hamilton,Nov,394",
        "Hamilton,Dec,395",
    };

    vector<string> city;

    for (auto words : sentences) {
        stringstream  ss(words);
        string str;
        while (getline(ss, str, ',')) {
            if (!count(city.begin(), city.end(), str) || isNumber(str)) {
                city.push_back(str);
            }
            if ((str == "Jan") || (str == "Feb") || (str == "Mar") || (str == "Apl") || (str == "May") || (str == "Jun") || (str == "Jul") || (str == "Aus") || (str == "Sep") || (str == "Oct") || (str == "Nov") || (str == "Dec")) {
                city.pop_back();
            }
            if (isNumber(str) && isNumber(city[city.size() - 2])) {
                city.pop_back();
                int temp = stoi(str) + stoi(city.back());
                city.pop_back();
                city.push_back(to_string(temp));
            }
        }
    }

    //display result
    for (auto word : city) {
        if (isNumber(word)) {
            int average = stoi(word) / 12;
            cout << word << "," << to_string(average) << endl;
        }
        else {
            cout << word << ",";
        }

    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
