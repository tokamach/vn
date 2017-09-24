#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <stack>
#include <map>

#include "ast.hpp"

using std::string;
using std::ifstream;
using std::vector;
using std::regex;
using std::stack;
using std::map;

namespace Parlex
{
    enum class ScopeFrame
    {
	Setup,
	Section,
	Keyword,
	Menu,
	Root,
	None
    };

    struct Token
    {
	string val;
	string cat;
    };
    
    class Lexer
    {
    public:
	Lexer(ifstream* _file);
	vector<Token> lex();

    private:
	bool advance();
	bool advance(char c);
	void back();
	void back(int n);

	ifstream* file;
	vector<Token> tokens;
	string cur;
	map<string, regex> regex_list;
	stack<ScopeFrame> context;
    };
    
    class Parser
    {
    public:
	//Finite State Machine variables
	bool inSetup;
	bool inLabel;
	std::string labelName;
	
	Parser(vector<Token> tokVec);
	
	AST* parse();
    };
    
}
