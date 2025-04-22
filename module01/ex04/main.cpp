#include    <string>
#include    <fstream>
#include    <iostream>
#include    <sstream>

int main(int ac, char **argv)
{
    if (ac != 4)
    {
        std::cerr << "Error: Run the file with <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream in;
    in.open(argv[1], std::ios::in);
    if (!in.is_open())
    {
        std::cerr << "Error: cannot open " << argv[1] << std::endl;
        return 1;
    }
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string content = buffer.str();
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
        pos = pos + s2.length();
    }
    std::ofstream out;
    out.open((std::string(argv[1]) + ".replace").c_str(), std::ios::out);
    if (!out.is_open())
    {
        std::cerr << "Error: cannot create " << argv[1] << ".replace" << std::endl;
        return 1;
    }
    out << content;
    return 0;
}
