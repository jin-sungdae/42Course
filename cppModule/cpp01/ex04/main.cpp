#include <iostream>
#include <cstring>
#include <fstream>



void replace_str(std::string *str, int first, int length, std::string s2)
{
    int index;
    index = first;
    str->erase(index, length);
    str->insert(index, s2);
}

int main(int ac, char **av)
{
    std::ifstream ifs;
    std::ofstream ofs;
    std::string s1;
    std::string s2;
    std::string newFile;
    std::string temp;

    if (ac == 4)
    {
        ifs.open(av[1]);
        s1 = av[2];
        s2 = av[3];
        newFile =  av[1];
        newFile += ".replace";
        ofs.open(newFile);
        while (std::getline(ifs,temp))
        {
            size_t check = temp.find(s1);
            if (check != std::string::npos)
            {

                replace_str(&temp, temp.find(s1), s1.length(), s2);
                temp += '\n';
                ofs << temp;
            }
            else
            {
                temp += '\n';
                ofs << temp;
            }
        }
    }
}