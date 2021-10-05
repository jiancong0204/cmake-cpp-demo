#include <json/json.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "printer.h"

using string = std::string;

template <class T> using vector = std::vector<T>;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    Json::Value root;

    std::ifstream jsonFile("test_examples/json_example.json", std::ios::binary);

    if (!jsonFile.is_open()) {
        cout << "Error opening" << endl;
        return 0;
    }

    jsonFile >> root;
    const auto encoding = root["encoding"].asString();
    cout << encoding << endl;

    const auto& plugInsJson = root["plug-ins"];
    vector<string> plugIns;
    for (const auto& itr : plugInsJson) {
        plugIns.emplace_back(itr.asString());
    }

    for (const auto& str : plugIns) {
        cout << str << endl;
    }

    const auto& indentJson = root["indent"];
    const auto members = indentJson.getMemberNames();
    vector<std::pair<string, string>> indent;
    for (const auto& mem : members) {
        string name = static_cast<string>(mem);
        const auto value = indentJson[mem].asString();
        indent.emplace_back(std::make_pair(name, value));
    }

    for (const auto& p : indent) {
        cout << p.first << ": " << p.second << endl;
    }
}