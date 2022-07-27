#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

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
            std::string name = linel.substr(first + 1, last - first);
            std::string val1 = linel.substr(last + 1, last2 - last);
            std::string val2 = linel.substr(linel.find(".") + 1);
            name.pop_back();

            std::string val3 = std::to_string(std::stof(val1) + std::stof(val2));

            variables[name] = val3;
        }
    }

    std::cout << "\n";
    return 0;
}
