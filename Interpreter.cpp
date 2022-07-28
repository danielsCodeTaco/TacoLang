#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int main(const int argc, const char* argv[])
{
    const char* fileNameChar = argv[1];
    const std::string fileName(fileNameChar); //get filename

    std::ifstream file;
    file.open(fileName.c_str());
    std::string fileContent((std::istreambuf_iterator<char>(file)),
        (std::istreambuf_iterator<char>()));
    std::istringstream iss(fileContent); //open file and turn into string

    std::map<std::string, std::string> variables; //make variables map

    //std::cout << "Successfully opened file " + fileName + "\n";
    //std::cout << "File contents: " + fileContent + "\n\n";

    for (std::string line55; std::getline(iss, line55); ) {
        std::string linel = line55;

        //std::cout << "current line = " + line55;

        if (linel.find("show") != std::string::npos) { //show command
            int pos = linel.find(":");
            bool isVar = false;
            std::string varValue = "";

            std::string printValue = linel.substr(pos + 1);

            if (printValue != "newLine") {
                for (auto i = variables.begin(); i != variables.end(); i++) {
                    //std::cout << "i->first = " + i->first + ";\ni->second = " + i->second + ";\nprintValue = " + printValue + ";\n";
                    if (i->first == printValue) {
                        isVar = true;
                        varValue = i->second;
                    }
                }
            }
            else {
                isVar = true;
                varValue = "\n";
            }

            if (!isVar) {
                std::cout << linel.substr(pos + 1);
            }
            else {
                std::cout << varValue;
            }

            //std::cout << "found show( function";
        }
        else if (linel.find("var") != std::string::npos) { //create variable command
            unsigned first = linel.find(":");
            unsigned last = linel.find(",");
            std::string name = linel.substr(first + 1, last-first);
            std::string val = linel.substr(linel.find(",") + 1);
            name.pop_back();

            variables[name] = val;
        }
        else if (linel.find("add") != std::string::npos) { //addition
            unsigned first = linel.find(":");
            unsigned last = linel.find(",");
            unsigned last2 = linel.find(".");

            bool isVar1 = false;
            std::string var1Value = "";
            bool isVar2 = false;
            std::string var2Value = "";

            std::string name = linel.substr(first + 1, last - first);
            std::string val1 = linel.substr(last + 1, last2 - last);
            std::string val2 = linel.substr(linel.find(".") + 1);
            std::string val3;
            val1.pop_back();
            name.pop_back();

            for (auto i = variables.begin(); i != variables.end(); i++) {
                if (i->first == val1) {
                    isVar1 = true;
                    var1Value = i->second;
                }
                if (i->first == val2) {
                    isVar2 = true;
                    var2Value = i->second;
                }
                //std::cout << "i->first = " + i->first + ";\ni->second = " + i->second + ";\nvar1Value = " + var1Value + ";\nvar2Value = " + var2Value + ";\n" + "isVar1 = " + std::to_string(isVar1) + ";\n" + "isVar2 = " + std::to_string(isVar2) + ";\n" + "val1 = " + val1 + ";\n" + "val2 = " + val2 + ";\n";
            }

            if (isVar1 == 1 && isVar2 == 0) {
                val3 = to_string(stof(var1Value) + stof(val2));
            }
            if (isVar1 == 1 && isVar2 == 1) {
                val3 = to_string(stof(var1Value) + stof(var2Value));
            }
            if (isVar1 == 0 && isVar2 == 1) {
                val3 = to_string(stof(val1) + stof(var2Value));
            }
            if (isVar1 == 0 && isVar2 == 0) {
                val3 = to_string(stof(val1) + stof(val2));
            }

            //std::cout << "name = " + name + ";\n" + "val3 = " + val3 + ";\n";
            variables[name] = val3;
        }
        else if (linel.find("subtract") != std::string::npos) { //subtraction
            unsigned first = linel.find(":");
            unsigned last = linel.find(",");
            unsigned last2 = linel.find(".");

            bool isVar1 = false;
            std::string var1Value = "";
            bool isVar2 = false;
            std::string var2Value = "";

            std::string name = linel.substr(first + 1, last - first);
            std::string val1 = linel.substr(last + 1, last2 - last);
            std::string val2 = linel.substr(linel.find(".") + 1);
            std::string val3;
            val1.pop_back();
            name.pop_back();

            for (auto i = variables.begin(); i != variables.end(); i++) {
                if (i->first == val1) {
                    isVar1 = true;
                    var1Value = i->second;
                }
                if (i->first == val2) {
                    isVar2 = true;
                    var2Value = i->second;
                }
                //std::cout << "i->first = " + i->first + ";\ni->second = " + i->second + ";\nvar1Value = " + var1Value + ";\nvar2Value = " + var2Value + ";\n" + "isVar1 = " + std::to_string(isVar1) + ";\n" + "isVar2 = " + std::to_string(isVar2) + ";\n" + "val1 = " + val1 + ";\n" + "val2 = " + val2 + ";\n";
            }

            if (isVar1 == 1 && isVar2 == 0) {
                val3 = to_string(stof(var1Value) - stof(val2));
            }
            if (isVar1 == 1 && isVar2 == 1) {
                val3 = to_string(stof(var1Value) - stof(var2Value));
            }
            if (isVar1 == 0 && isVar2 == 1) {
                val3 = to_string(stof(val1) - stof(var2Value));
            }
            if (isVar1 == 0 && isVar2 == 0) {
                val3 = to_string(stof(val1) - stof(val2));
            }

            //std::cout << "name = " + name + ";\n" + "val3 = " + val3 + ";\n";
            variables[name] = val3;
        }
        else if (linel.find("multiply") != std::string::npos) { //multiplication
            unsigned first = linel.find(":");
            unsigned last = linel.find(",");
            unsigned last2 = linel.find(".");

            bool isVar1 = false;
            std::string var1Value = "";
            bool isVar2 = false;
            std::string var2Value = "";

            std::string name = linel.substr(first + 1, last - first);
            std::string val1 = linel.substr(last + 1, last2 - last);
            std::string val2 = linel.substr(linel.find(".") + 1);
            std::string val3;
            val1.pop_back();
            name.pop_back();

            for (auto i = variables.begin(); i != variables.end(); i++) {
                if (i->first == val1) {
                    isVar1 = true;
                    var1Value = i->second;
                }
                if (i->first == val2) {
                    isVar2 = true;
                    var2Value = i->second;
                }
                //std::cout << "i->first = " + i->first + ";\ni->second = " + i->second + ";\nvar1Value = " + var1Value + ";\nvar2Value = " + var2Value + ";\n" + "isVar1 = " + std::to_string(isVar1) + ";\n" + "isVar2 = " + std::to_string(isVar2) + ";\n" + "val1 = " + val1 + ";\n" + "val2 = " + val2 + ";\n";
            }

            if (isVar1 == 1 && isVar2 == 0) {
                val3 = to_string(stof(var1Value) * stof(val2));
            }
            if (isVar1 == 1 && isVar2 == 1) {
                val3 = to_string(stof(var1Value) * stof(var2Value));
            }
            if (isVar1 == 0 && isVar2 == 1) {
                val3 = to_string(stof(val1) * stof(var2Value));
            }
            if (isVar1 == 0 && isVar2 == 0) {
                val3 = to_string(stof(val1) * stof(val2));
            }

            //std::cout << "name = " + name + ";\n" + "val3 = " + val3 + ";\n";
            variables[name] = val3;
        }
        else if (linel.find("divide") != std::string::npos) { //division
            unsigned first = linel.find(":");
            unsigned last = linel.find(",");
            unsigned last2 = linel.find(".");

            bool isVar1 = false;
            std::string var1Value = "";
            bool isVar2 = false;
            std::string var2Value = "";

            std::string name = linel.substr(first + 1, last - first);
            std::string val1 = linel.substr(last + 1, last2 - last);
            std::string val2 = linel.substr(linel.find(".") + 1);
            std::string val3;
            val1.pop_back();
            name.pop_back();

            for (auto i = variables.begin(); i != variables.end(); i++) {
                if (i->first == val1) {
                    isVar1 = true;
                    var1Value = i->second;
                }
                if (i->first == val2) {
                    isVar2 = true;
                    var2Value = i->second;
                }
                //std::cout << "i->first = " + i->first + ";\ni->second = " + i->second + ";\nvar1Value = " + var1Value + ";\nvar2Value = " + var2Value + ";\n" + "isVar1 = " + std::to_string(isVar1) + ";\n" + "isVar2 = " + std::to_string(isVar2) + ";\n" + "val1 = " + val1 + ";\n" + "val2 = " + val2 + ";\n";
            }

            if (isVar1 == 1 && isVar2 == 0) {
                val3 = to_string(stof(var1Value) / stof(val2));
            }
            if (isVar1 == 1 && isVar2 == 1) {
                val3 = to_string(stof(var1Value) / stof(var2Value));
            }
            if (isVar1 == 0 && isVar2 == 1) {
                val3 = to_string(stof(val1) / stof(var2Value));
            }
            if (isVar1 == 0 && isVar2 == 0) {
                val3 = to_string(stof(val1) / stof(val2));
            }

            //std::cout << "name = " + name + ";\n" + "val3 = " + val3 + ";\n";
            variables[name] = val3;
        }
        else if (linel.find("power") != std::string::npos) { //power
            unsigned first = linel.find(":");
            unsigned last = linel.find(",");
            unsigned last2 = linel.find(".");

            bool isVar1 = false;
            std::string var1Value = "";
            bool isVar2 = false;
            std::string var2Value = "";

            std::string name = linel.substr(first + 1, last - first);
            std::string val1 = linel.substr(last + 1, last2 - last);
            std::string val2 = linel.substr(linel.find(".") + 1);
            std::string val3;
            val1.pop_back();
            name.pop_back();

            for (auto i = variables.begin(); i != variables.end(); i++) {
                if (i->first == val1) {
                    isVar1 = true;
                    var1Value = i->second;
                }
                if (i->first == val2) {
                    isVar2 = true;
                    var2Value = i->second;
                }
                //std::cout << "i->first = " + i->first + ";\ni->second = " + i->second + ";\nvar1Value = " + var1Value + ";\nvar2Value = " + var2Value + ";\n" + "isVar1 = " + std::to_string(isVar1) + ";\n" + "isVar2 = " + std::to_string(isVar2) + ";\n" + "val1 = " + val1 + ";\n" + "val2 = " + val2 + ";\n";
            }

            if (isVar1 == 1 && isVar2 == 0) {
                val3 = to_string(pow(stof(var1Value), stof(val2)));
            }
            if (isVar1 == 1 && isVar2 == 1) {
                val3 = to_string(pow(stof(var1Value), stof(var2Value)));
            }
            if (isVar1 == 0 && isVar2 == 1) {
                val3 = to_string(pow(stof(val1), stof(var2Value)));
            }
            if (isVar1 == 0 && isVar2 == 0) {
                val3 = to_string(pow(stof(val1), stof(val2)));
            }

            //std::cout << "name = " + name + ";\n" + "val3 = " + val3 + ";\n";
            variables[name] = val3;
        }
        else if (linel.find("sqrt") != std::string::npos) { //square rooting
            unsigned first = linel.find(":");
            unsigned last = linel.find(",");

            bool isVar1 = false;
            std::string var1Value = "";

            std::string name = linel.substr(first + 1, last - first);
            std::string val1 = linel.substr(linel.find(",") + 1);
            std::string val2;
            name.pop_back();

            for (auto i = variables.begin(); i != variables.end(); i++) {
                //std::cout << "i->first = " + i->first + ";\ni->second = " + i->second + ";\nvar1Value = " + var1Value + ";\n" + "isVar1 = " + std::to_string(isVar1) + ";\n" + "val1 = " + val1 + ";\n" + "val2 = " + val2 + ";\n";
                if (i->first == val1) {
                    isVar1 = true;
                    var1Value = i->second;
                }
            }

            std::cout << "isVar1 = " + std::to_string(isVar1) + ";\n" + "var1Value = " + var1Value + ";\n" + "val1 = " + val1 + ";\n";
            if (isVar1 == 1) {
                val2 = to_string(sqrt(stof(var1Value)));
            }
            if (isVar1 == 0) {
                val2 = to_string(sqrt(stof(val1)));
            }

            std::cout << "name = " + name + ";\n" + "val2 = " + val2 + ";\n";
            variables[name] = val2;
        }
        else if (linel.find("input") != std::string::npos) { //input command
            unsigned first = linel.find(":");
            unsigned last = linel.find(",");
            std::string name = linel.substr(first + 1);
            std::string prompt = linel.substr(last + 1, last - first);
            name.pop_back();

            std::cout << prompt;
            std::string answer;
            std::cin >> answer;
            variables[name] = answer;
            //std::cout << "name = " + name + ";\n" + "prompt = " + prompt + ";\n" + "answer = " + answer;
        }
    }

    std::cout << "\n";
    system("pause");
    return 0;
}
