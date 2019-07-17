#pragma once

#include "DBUtils.h"

namespace PPOlaba3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SQLite;
	using namespace System::Text;
	using namespace cliext;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			db = gcnew DBUtils();
			data = gcnew vector<pair<String^, DataTable^>^>(0);
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menu;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGrid;
	private: System::Windows::Forms::ComboBox^  comboBox;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  ColText;
	private: System::Windows::Forms::TextBox^  DataText;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  searchButton;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ColText = (gcnew System::Windows::Forms::TextBox());
			this->DataText = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// menu
			// 
			this->menu->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->addToolStripMenuItem, this->deleteToolStripMenuItem
			});
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(544, 24);
			this->menu->TabIndex = 0;
			this->menu->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->addToolStripMenuItem->Text = L"Add";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deleteToolStripMenuItem_Click);
			// 
			// dataGrid
			// 
			this->dataGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid->Location = System::Drawing::Point(0, 27);
			this->dataGrid->Margin = System::Windows::Forms::Padding(0);
			this->dataGrid->Name = L"dataGrid";
			this->dataGrid->Size = System::Drawing::Size(544, 241);
			this->dataGrid->TabIndex = 1;
			this->dataGrid->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGrid_CellLeave);
			this->dataGrid->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &MyForm::dataGrid_DataError);
			// 
			// comboBox
			// 
			this->comboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox->Location = System::Drawing::Point(398, 267);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(146, 21);
			this->comboBox->TabIndex = 2;
			this->comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 270);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"ColName";
			// 
			// ColText
			// 
			this->ColText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->ColText->Location = System::Drawing::Point(68, 268);
			this->ColText->Name = L"ColText";
			this->ColText->Size = System::Drawing::Size(100, 20);
			this->ColText->TabIndex = 4;
			// 
			// DataText
			// 
			this->DataText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->DataText->Location = System::Drawing::Point(211, 268);
			this->DataText->Name = L"DataText";
			this->DataText->Size = System::Drawing::Size(100, 20);
			this->DataText->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(175, 271);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Data";
			// 
			// searchButton
			// 
			this->searchButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->searchButton->Location = System::Drawing::Point(327, 268);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(54, 20);
			this->searchButton->TabIndex = 7;
			this->searchButton->Text = L"search";
			this->searchButton->UseVisualStyleBackColor = true;
			this->searchButton->Click += gcnew System::EventHandler(this, &MyForm::searchButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(544, 291);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->DataText);
			this->Controls->Add(this->ColText);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->dataGrid);
			this->Controls->Add(this->menu);
			this->MainMenuStrip = this->menu;
			this->MinimumSize = System::Drawing::Size(560, 330);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DB Reader";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		DBUtils ^db;
		vector<pair<String^, DataTable^>^> ^data;	// таблицы из выбранной бд

	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenFileDialog ^open = gcnew OpenFileDialog();
		if (open->ShowDialog() != Windows::Forms::DialogResult::OK)
			return;
	
		try
		{
			db->Open(open->FileName);
		}
		catch (const Exception ^e)
		{
			MessageBox::Show("Can't open database");
		}

		this->ReadData();
	}

	// обновляем всю бд
	private: System::Void ReadData()
	{
		// очищаем
		this->comboBox->Items->Clear();
		this->dataGrid->DataSource = nullptr;
		data->clear();

		try
		{
			data = db->GetData();
		}
		catch (const Exception ^e)
		{			
			MessageBox::Show("Can't read data");
			return;
		}

		for (int i = 0; i < data->size(); i++)
		{
			this->comboBox->Items->Add(data[i]->first);
		}
	
		if (this->comboBox->SelectedIndex == -1)
			this->comboBox->SelectedIndex = 0;
		
		this->dataGrid->DataSource = data[0]->second;
	};

	// обновляем конкретную таблицу
	private: System::Void ReadTable(String ^tableName)
	{
		DataTable ^dataTable = gcnew DataTable();
		
		try
		{
			dataTable = db->GetTable(tableName);
		}
		catch (const Exception ^e)
		{
			MessageBox::Show("Can't read table");
		}

		// обновляем запись в векторе всех данных
		for (int i = 0; i < data->size(); i++)
		{
			if (tableName == data[i]->first)
				data[i]->second = dataTable;
		}

		this->dataGrid->DataSource = dataTable;
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			db->Open("phones.db");
		}
		catch (const Exception ^e)
		{
			MessageBox::Show("Can't open database");
		}

		this->ReadData();
	}

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Close();
	}

	private: System::Void comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		try
		{
			this->dataGrid->DataSource = data[this->comboBox->SelectedIndex]->second;	// индексация в массиве совпадает с индексацией в combobox
		}
		catch (const Exception ^e)
		{
			MessageBox::Show("table doesn't exists");
		}
	}

	private: System::Void addToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		try
		{
			db->AddRow(this->comboBox->SelectedItem->ToString());
		}
		catch (const Exception ^e)
		{
			MessageBox::Show("Can't add data");
		}	

		this->ReadTable(this->comboBox->SelectedItem->ToString());
	}
	
	private: System::Void deleteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		try
		{
			db->DeleteRow(this->comboBox->SelectedItem->ToString());
		}
		catch (const Exception ^e)
		{
			MessageBox::Show("Can't delete data");
		}

		this->ReadTable(this->comboBox->SelectedItem->ToString());
	}

	private: System::Void dataGrid_CellLeave(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{
		try
		{
			db->UpdateItem(dataGrid->CurrentCell->ColumnIndex, Convert::ToInt32(dataGrid->Rows[dataGrid->CurrentCell->RowIndex]->Cells[0]->Value->ToString()),	//получили правильный id
				comboBox->SelectedItem->ToString(), dataGrid->CurrentCell->Value->ToString());
		}
		catch (const Exception ^e)
		{
			MessageBox::Show("Can't update data");
		}
	}

	private: System::Void dataGrid_DataError(System::Object^  sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^  e) 
	{
		MessageBox::Show("invalid value");
	}

	private: System::Void searchButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		DataTable ^table = gcnew DataTable();	// не заносим в data, ведь это временный фильтр

		try
		{
			table = db->Find(comboBox->SelectedItem->ToString(), ColText->Text, DataText->Text);
		}
		catch (const Exception ^e)
		{
			dataGrid->DataSource = data[this->comboBox->SelectedIndex]->second;
			return;
		}

		dataGrid->DataSource = table;
	}
};
}
