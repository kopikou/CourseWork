//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <ctype.h>
#include "Unit1.h"
#include "Unit4.h"
#include <algorithm>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//Когда форма появляется---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
	Edit1->SetFocus();//Устанавливаем фокус на первое поле
}
//Обработка добавления и редактирования---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form4->Show();//Открыть форму
	Form1->Close();//Закрыть форму
	int nm;
	if (Form1->Caption=="Добавление"){//Если форма для добавления данных
		nm = Form4->StringGrid1->RowCount-1;//Номер последней строки
		Form4->StringGrid1->Cells[0][nm]=IntToStr(nm);//Нумерация добавленной строки
		Form4->StringGrid1->RowCount=Form4->StringGrid1->RowCount+1;//Дополнительная строка
	}
	else//Если форма для редактирования
	{
		nm = Form4->StringGrid1->Selection.Top;//Установить фокус на строке
	}

	//Заполнение таблицы введёнными значениями
	Form4->StringGrid1->Cells[0][nm]=nm;
	Form4->StringGrid1->Cells[1][nm]=Edit1->Text;
	Form4->StringGrid1->Cells[2][nm]=Edit2->Text;
	Form4->StringGrid1->Cells[3][nm]=Edit3->Text;
	Form4->StringGrid1->Cells[4][nm]=FormatDateTime("dd.mm.yyyy", DateTimePicker1->Date);
	Form4->StringGrid1->Cells[5][nm]=Edit5->Text+Edit9->Text;
	Form4->StringGrid1->Cells[6][nm]=ComboBox1->Items->Strings[ComboBox1->ItemIndex];
	Form4->StringGrid1->Cells[7][nm]=Edit7->Text;
	Form4->StringGrid1->Cells[8][nm]=FormatDateTime("dd.mm.yyyy", DateTimePicker2->Date);

	//Очищение поля ввода
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	DateTimePicker1->Date=Date();
	Edit5->Clear();
	ComboBox1->Text=ComboBox1->Items->Strings[-1];
	Edit7->Clear();
	DateTimePicker2->Date=Date();
	Edit9->Clear();
}
//Коррекстность номера паспорта---------------------------------------------------------------------------
void __fastcall TForm1::Edit5Exit(TObject *Sender)
{
	AnsiString data = Edit5->Text;
	int i;
	if(data.Length() != 4 || !TryStrToInt(data,i))//Если <> 4 символов и есть буквы
		{
			ShowMessage("Неверный формат номера паспорта (4 цифр)");
			Edit5->SetFocus();//Установить фокус на это поле
		}
}
//Коррекстность серии паспорта---------------------------------------------------------------------------
void __fastcall TForm1::Edit9Exit(TObject *Sender)
{
	AnsiString data = Edit9->Text;
	int i;
	if(data.Length() != 6 || !TryStrToInt(data,i))//Если <> 6 символов и есть буквы
		{
			ShowMessage("Неверный формат серии паспорта (6 цифр)");
			Edit5->SetFocus();//Установить фокус на это поле
		}
}

//Переход на следующий элемент с помощью Enter---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {Edit2-> SetFocus();}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {Edit3-> SetFocus();}
}
//---------------------------------------------------------------------------
 void __fastcall TForm1::Edit3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {DateTimePicker1-> SetFocus();}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DateTimePicker1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {Edit5-> SetFocus();}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit5KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {Edit9-> SetFocus();}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit9KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {ComboBox1-> SetFocus();}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {Edit7-> SetFocus();}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit7KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {DateTimePicker2-> SetFocus();}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DateTimePicker2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {Button1-> SetFocus();}
}

//Верхний регистр для Фамилии---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
	AnsiString text = Edit1->Text;//Получаем текущий текст в edit
	text = text.SubString(1, 1).UpperCase() + text.SubString(2, text.Length() - 1);//Установливаем первую букву в верхний регистр
	Edit1->Text = text;//Обновляем текст в edit
}
//Верхний регистр для Имени---------------------------------------------------------------------------
void __fastcall TForm1::Edit2Exit(TObject *Sender)
{
	AnsiString text = Edit2->Text;//Получаем текущий текст в edit
	text = text.SubString(1, 1).UpperCase() + text.SubString(2, text.Length() - 1);//Установливаем первую букву в верхний регистр
	Edit2->Text = text;//Обновляем текст в edit
}
//Верхний регистр для Отчества---------------------------------------------------------------------------
void __fastcall TForm1::Edit3Exit(TObject *Sender)
{
	AnsiString text = Edit3->Text;//Получаем текущий текст в edit
	text = text.SubString(1, 1).UpperCase() + text.SubString(2, text.Length() - 1);//Установливаем первую букву в верхний регистр
	Edit3->Text = text;//Обновляем текст в edit
}
//Верхний регистр для Должности---------------------------------------------------------------------------
void __fastcall TForm1::Edit7Exit(TObject *Sender)
{
	AnsiString text = Edit7->Text;//Получаем текущий текст в edit
	text = text.SubString(1, 1).UpperCase() + text.SubString(2, text.Length() - 1);//Установливаем первую букву в верхний регистр
	Edit7->Text = text;//Обновляем текст в edit
}
//---------------------------------------------------------------------------
