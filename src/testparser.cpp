#include <iostream>
#include <fstream>
#include <vector>

#include "parlex.hpp"

using std::ifstream;
using std::vector;

int main()
{
    ifstream *f = new ifstream("test.txt");
    Parlex::Lexer l(f);
    vector<Parlex::Token> v = l.lex();

    for(auto e : v)
    {
	std::cout << e.val << " : " << e.cat << std::endl;
    }
}
