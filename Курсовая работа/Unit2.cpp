//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//Поиск---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	for (int i=1; i < Form5->StringGrid1->RowCount; i++) {
			Form5->StringGrid1->Rows[i]->Clear();//Очищаем ячейки таблицы
		}
	Form5->StringGrid1->RowCount=2;//Устнавливаем первоначальное количество строк в таблице

	bool flagsearch = false;//Флаг поиска
	Form4->Show();//Показать форму

	int k = 1;//Счётчик строк для таблицы с результатом поиска
	AnsiString searchString="";//Дополнительная строка для определения, есть ли уже в рзеультирующей таблице найденная строка
	for(int i = 1; i < Form4->StringGrid1->RowCount; i++)
	{
		for(int j = 1; j < Form4->StringGrid1->ColCount; j++)
		{
			if(Form4->StringGrid1->Cells[j][i].SubString(1,(Edit1->Text).Length())==Edit1->Text)//Если в ячейке таблицы есть подстрока, которую надо найти
			{
				if(searchString != Form4->StringGrid1->Rows[i]->Strings[0].Trim()){//Если искамая строка таблицы ещё не записана в результирующую таблицу
					Form5->StringGrid1->Rows[k]=Form4->StringGrid1->Rows[i];//Записываем найденную строку в результирующую таблицу
					searchString=Form4->StringGrid1->Rows[i]->Strings[0].Trim();//Запоминаем найденную строку
					Form5->StringGrid1->RowCount=Form5->StringGrid1->RowCount+1;//Увеличиваем количество строк в результирующей таблице
					k++;//Переходим на следующую строку результирующей таблицы
					flagsearch=true;//Флаг поиска
				}
			}
		}
	}
	if (flagsearch == false) {//Если не нашли совпадений
		ShowMessage("Не удаётся найти '" + Edit1->Text + "'");
	}
	else{
		Form5->Show();//Показываем форму с таблицей
	}
}
//Переход на следующий элемент с помощью Enter---------------------------------------------------------------------------
void __fastcall TForm2::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN) {Button1-> SetFocus();}
}
//Устанавливаем фокус на текстовое поле---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
	Edit1->SetFocus();
}
//Переводим в верхний регистр то, что ищем-------------------------------------------------------------------------
void __fastcall TForm2::Edit1Exit(TObject *Sender)
{
	AnsiString text = Edit1->Text;//Получаем текущий текст в edit
	text = text.SubString(1, 1).UpperCase() + text.SubString(2, text.Length() - 1);//Установливаем первую букву в верхний регистр
	Edit1->Text = text;//Обновляем текст в edit
}
//---------------------------------------------------------------------------

