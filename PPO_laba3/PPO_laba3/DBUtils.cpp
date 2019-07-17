#include "DBUtils.h"


DBUtils::DBUtils()
{
	db = gcnew SQLiteConnection();
}

DBUtils::~DBUtils()
{
	db->Close();
}

Void DBUtils::Open(String ^name)
{
	db->Close();
	db->ConnectionString = "Data Source=\"" + name + "\"";
	db->Open();
}

Void DBUtils::Close()
{
	db->Close();
}

vector<pair<String^, DataTable^>^>^ DBUtils::GetData()
{
	vector<pair<String^, DataTable^>^> ^data = gcnew vector<pair<String^, DataTable^>^>(0);

	SQLiteCommand ^cmdSelect = db->CreateCommand();
	cmdSelect->CommandText = "select name from sqlite_master;";
	SQLiteDataReader ^reader = cmdSelect->ExecuteReader();

	String ^str;
	while (reader->Read())
	{
		for (int i = 0; i < reader->FieldCount; i++)
		{
			str = reader->GetValue(i)->ToString();
			if (str == "sqlite_sequence")	// служебная таблица
				continue;

			SQLiteDataAdapter ^adapter = gcnew SQLiteDataAdapter("SELECT * from " + str, db);
			DataTable ^table = gcnew DataTable();
			adapter->Fill(table);
			data->push_back(gcnew pair<String^, DataTable^>(str, table));
		}
	}

	return data;
}

DataTable^ DBUtils::GetTable(String ^tableName)
{
	SQLiteDataAdapter ^adapter = gcnew SQLiteDataAdapter("SELECT * from " + tableName, db);
	DataTable ^table = gcnew DataTable();
	adapter->Fill(table);
	return table;
}

Void DBUtils::AddRow(String ^tableName)
{
	SQLiteCommand ^cmd = db->CreateCommand();
	cmd->CommandText = "select * from " + tableName + " ;";
	SQLiteDataReader ^reader = cmd->ExecuteReader();

	SQLiteCommand ^cmdInsert = db->CreateCommand();
	cmdInsert->CommandText = "INSERT INTO " + tableName + " VALUES(";
	for (int i = 0; i < reader->FieldCount - 1; i++)
		cmdInsert->CommandText += "NULL, ";
		
	cmdInsert->CommandText += "NULL); ";
	
	cmdInsert->ExecuteNonQuery();
}

Void DBUtils::DeleteRow(String ^tableName)
{
	SQLiteCommand ^cmd = db->CreateCommand();
	cmd->CommandText = "select * from " + tableName + " ;";
	SQLiteDataReader ^reader = cmd->ExecuteReader();

	SQLiteCommand ^cmdDelete = db->CreateCommand();
	cmdDelete->CommandText = "DELETE FROM " + tableName + " WHERE id = (SELECT MAX(id) FROM " + tableName + ");";
	cmdDelete->ExecuteNonQuery();
}

Void DBUtils::UpdateItem(int col, int id, String ^tableName, String ^newdata)

{
	SQLiteCommand ^cmd = db->CreateCommand();
	cmd->CommandText = "select * from " + tableName + " ;";
	SQLiteDataReader ^reader = cmd->ExecuteReader();

	if (newdata == "")
		newdata = "NULL";

	SQLiteCommand ^cmdUpdate = db->CreateCommand();
	cmdUpdate->CommandText = "UPDATE " + tableName + " SET " + reader->GetName(col) + " = '" + newdata + "' WHERE id = " + Convert::ToString(id) +";";
	cmdUpdate->ExecuteNonQuery();
}

DataTable^ DBUtils::Find(String ^tableName, String ^colName, String ^dataName)
{
	if (dataName == "" || colName == "")
		throw gcnew Exception;

	SQLiteDataAdapter ^adapter = gcnew SQLiteDataAdapter("SELECT * FROM " + tableName +
														" WHERE " + colName + " = '" + dataName + "' ;" , db);

	DataTable ^table = gcnew DataTable();
	adapter->Fill(table);
	return table;
}
