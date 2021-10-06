#include <json/json.h>

#include <Eigen/Eigen>
#include <fstream>
#include <iostream>
#include <vector>

#include "logger/logger.hpp"
#include "printer.h"

using string = std::string;

template <class T> using vector = std::vector<T>;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    Logger::Init(argv[0]);

    Json::Value root;

    std::ifstream jsonFile("test_examples/json_example.json", std::ios::binary);

    Eigen::Vector3d v;
    v.setZero();
    LOG(INFO) << v;
    v << 1, 2, 3;
    LOG(INFO) << v;

    Eigen::Vector3d vv{2, 3, 4};
    LOG(INFO) << vv;

    LOG(INFO) << v * vv.transpose();
    LOG(INFO) << vv.dot(v);

    if (!jsonFile.is_open()) {
        LOG(FATAL) << "Error opening";
        return 0;
    }

    jsonFile >> root;
    const auto encoding = root["encoding"].asString();
    LOG(ERROR) << encoding;

    const auto& plugInsJson = root["plug-ins"];
    vector<string> plugIns;
    for (const auto& itr : plugInsJson) {
        plugIns.emplace_back(itr.asString());
    }

    for (const auto& str : plugIns) {
        LOG(WARNING) << str;
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
        LOG(INFO) << Logger::CYAN << p.first << ": " << p.second << Logger::END;
    }

    Printer::Printer p;
    p.SetCode(123);
    p.Print();
    Logger::Stop();
}