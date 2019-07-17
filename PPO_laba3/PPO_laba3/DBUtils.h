#pragma once

#include <cliext/vector>
#include <cliext/algorithm>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::Data::SQLite;
using namespace cliext;
using namespace System::Data;


ref class DBUtils
{
private:
	SQLiteConnection ^db;

public:
	DBUtils();
	~DBUtils();

	Void Open(String^ );
	Void Close();
	vector<pair<String^, DataTable^>^>^ GetData();
	DataTable^ GetTable(String^ );
	Void AddRow(String^ );
	Void DeleteRow(String^ );
	Void UpdateItem(int, int, String^, String^ );
	DataTable^ Find(String^, String^ , String^ );
};

