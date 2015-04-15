// TestQuery.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include "QueryResult.h"
#include "TextQuery.h"
#include <fstream>
#include <iostream>

using namespace std;

ostream &print(ostream &os, const QueryResult& qr)
{
	os << qr.sought << "occurs " << qr.lines->size() << " ";
	for (auto item : *qr.lines)
	{
		os << "\t(line " << item + 1 << ")" << *(qr.file->begin() + item) << endl;
	}
	return os;
}


void runQueries(ifstream &ifstream)
{
	TextQuery tq(ifstream);
	while (true)
	{
		cout << "input a word to look for, or q to quit" << endl;
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s));
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream ifs;
	ifs.open("data.txt", ios::in|ios::beg);
	runQueries(ifs);
	return 0;
}

