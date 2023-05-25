//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "About.h"
#include <iostream>
#include <fstream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}

//Запуск заставки и Оформление таблицы---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{
	Form3= new TForm3(this);//Подключаем заставку
	Form3->ShowModal();//Показ заставки
	Form3->Free();//Закрытие формы
	fill();//Заполнение заголовка таблицы
}

//Перед закрытием формы---------------------------------------------------------------------------
void __fastcall TForm4::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (flag) {//Если произошли изменения
		if(filename=="")//Если файл не существовал
		{
			switch (MessageDlg("Вы хотите сохранить изменения в файле?",mtConfirmation,mbYesNoCancel,0)) {
			case mrYes: N6Click(Sender);//Сохранить как
			case mrNo: Application->Terminate();//Закрыть форму
			}
		}
		else//Если файл уже существует
		{
			switch (MessageDlg("Вы хотите сохранить изменения в файле?",mtConfirmation,mbYesNoCancel,0)) {
			case mrYes: N5Click(Sender);//Сохранить
			case mrNo: Application->Terminate();//Закрыть форму
		   }
		}
	   
   }
}

//Файл->Создать: Создание нового файла---------------------------------------------------------------------------
void __fastcall TForm4::N2Click(TObject *Sender)
{
	if (flag) {//Если произошли изменения
		switch (MessageDlg("Вы хотите сохранить изменения в файле?",mtConfirmation,mbYesNoCancel,0)) {
		case mrYes:
			{
				N5Click(Sender);//Сохранить
				createnew();//Создание нового файла
				break;
			}
		case mrNo:
			{
				createnew();//Создание нового файла
				break;
			}
		}
	}
	else{//Если не было изменений
		createnew();//Создание нового файла
    }
}
//Панель инструментов: Создание нового файла---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton1Click(TObject *Sender)
{
	N2Click(Sender);//Вызов функции создания нового файла
}

//Файл->Открыть: Открытие файла---------------------------------------------------------------------------
void __fastcall TForm4::N3Click(TObject *Sender)
{
	if (OpenDialog1->Execute()) {//Если открыто диалоговое окно
		gridclear();

		TFileStream *fs = new TFileStream(OpenDialog1->FileName, fmOpenRead);//Открываем выбранный файл для чтения
		filename= OpenDialog1->FileName;//Сохраняем имя файла
		int fileSize = fs->Size;//Считываем размер файла
		StringGrid1->RowCount = StringGrid1->RowCount+ fileSize/108;//Определяем количество строк в таблице
		char *buffer;//Вспомогательная строка буффер
		for (int i = 1; i < StringGrid1->RowCount-1; i++) {
			for (int j = 1; j < StringGrid1->ColCount; j++) {
				buffer = new char[dataSize[j-1]];//Создаем переменную нужного массива
				fs->Read(buffer, dataSize[j-1]);//Считываем данные из файла
				StringGrid1->Cells[j][i] = buffer;//Заполняем ячейки таблицы
			}
			StringGrid1->Cells[0][i] = i;//Нумеруем строки
		}
		delete[] buffer;//Очищаем буффер
		delete fs;//Удаляем переменную потокового чтения
	}

	N3->Enabled=false;ToolButton2->Enabled=false;//Открыть
	turnon();//Доступность пунктов меню
	flag = false;//флаг изменения файла
}
//Панель инструментов: Открытие файла---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton2Click(TObject *Sender)
{
	N3Click(Sender);//Вызов функции открытия файла
}

//Файл->Сохранить---------------------------------------------------------------------------
void __fastcall TForm4::N5Click(TObject *Sender)
{
	if(flag){//Если произошли изменения в файле
		if(filename=="")//Если файл ранее не существовал
		{
			N6Click(Sender);//Вызываем функцию сохранения как
		}
		else//Если файл уже существует
		{
			TFileStream *fs = new TFileStream(filename, fmOpenWrite);//Открываем файл для записи
			fs->Size = 0;//Очищаем файл
			save(fs);//Функция сохранения
		}
	}

	flag = false;//Флаг изменений
}
//Панель инструментов: сохранить---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton3Click(TObject *Sender)
{
	N5Click(Sender);//Вызов функции сохранения
}

//Файл->Сохранить как:---------------------------------------------------------------------------
void __fastcall TForm4::N6Click(TObject *Sender)
{
	if(SaveDialog1->Execute()){//Если открыто диалоговое окно
		TFileStream *fs = new TFileStream(SaveDialog1->FileName, fmCreate);//Создаем новый файл
		filename= SaveDialog1->FileName;//Запоминаем имя файла
		save(fs);//Функция сохранения
	}
	flag = false;//Флаг изменений
}

//Файл->Закрыть--------------------------------------------------------------------------
void __fastcall TForm4::N8Click(TObject *Sender)
{
	N2Click(Sender);//Вызов функции создания нового файла
}

//Файл->Выход---------------------------------------------------------------------------
void __fastcall TForm4::N10Click(TObject *Sender)
{
	this->Close();//Закрытие формы
	bool CanClose=true;
	FormCloseQuery(Sender,CanClose);//Вызов функции перед закрытием формы
}

//Правка->Добавить данные---------------------------------------------------------------------------
void __fastcall TForm4::N12Click(TObject *Sender)
{
	Form1->Button1->Caption="Добавить";//Изменить название кнопки на форме
	Form1->Caption="Добавление";//Изменить название формы
	Form1->Show();//Показать форму

	flag = true;//Флаг изменений
	N5->Enabled=true;ToolButton3->Enabled=true;//Доступность "Сохранить"
	turnon();//Доступность пунктов меню
}
//Панель инструментов: Добавить данные---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton5Click(TObject *Sender)
{
	N12Click(Sender);//Вызов функции добавления данных
}

//Правка->Редактировать данные---------------------------------------------------------------------------
void __fastcall TForm4::N14Click(TObject *Sender)
{
	int nm = StringGrid1->Selection.Top;//Установить фокус на ячейку
	Form1->Button1->Caption="Редактировать";//Изменить название кнопки на форме
	Form1->Caption="Редактирование";//Изменить название формы

	editfill(nm);//Заполнение формы данными из таблицы

	Form1->Show();//Показать форму

	flag=true;//Флаг изменений
	N5->Enabled=true;ToolButton3->Enabled=true;//Доступность "Сохранить"
}
//Панель инструментов: Редактировать данные---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton7Click(TObject *Sender)
{
	N14Click(Sender);//Вызов функции редактирования данных
}

//Правка->Удалить данные---------------------------------------------------------------------------
void __fastcall TForm4::N13Click(TObject *Sender)
{
	int nm  = StringGrid1->Selection.Top;//Установить фокус на ячейку
	switch (MessageDlg("Вы хотите удалить '" + StringGrid1->Cells[1][nm] + "'?",mtConfirmation,mbYesNo,0)) {
	case mrYes:
		{
			for (int i = nm;i < StringGrid1-> RowCount-1;++i) {
				StringGrid1-> Rows[i] = StringGrid1-> Rows[i+1];//Смещаем все строки на одну вверх
			}
			StringGrid1->RowCount--;//Уменьшаем количество строк в таблице
			rownumber();//Восстанавливаем нумерацию строк
			break;
		}
	}
	N5->Enabled=true;ToolButton3->Enabled=true;//Доступность "Сохранить"
	if(StringGrid1-> RowCount==2){//Если количество строк равно 2
		N3->Enabled=true;ToolButton2->Enabled=true;//Доступность "Открыть"
		turnoff();//Недоступность пунктов меню
	}
	flag = true;//Флаг изменений
}
//Панель инструментов:Удалить данные---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton6Click(TObject *Sender)
{
	N13Click(Sender);//Вызов функции удаления данных
}

//Обработка->Поиск---------------------------------------------------------------------------
void __fastcall TForm4::N24Click(TObject *Sender)
{
	Form2->Show();//Открыть форму
}
//Панель инструментов: Поиск---------------------------------------------------------------------------
void __fastcall TForm4::ToolButton9Click(TObject *Sender)
{
	N24Click(Sender);//Вызов функции поиска
}

//Сортировка по возрастанию---------------------------------------------------------------------------
void __fastcall TForm4::N27Click(TObject *Sender)
{
	int nm = StringGrid1->Selection.Left;//Устанавливаем фокус на столбец
	if(StringGrid1->Cells[nm][0]=="Дата рождения" || StringGrid1->Cells[nm][0]=="Дата приёма на работу")//Если сортировка по дате
		sortData(sort_up, nm,data_date);//Сортировка по возрастанию, для дат
	else//Если сортировка для строк
		sortData(sort_up, nm,data_str);//Сортировка по возрастанию, для строк

	flag = true;//Флаг изменений
	N5->Enabled=true;ToolButton3->Enabled=true;//Доступность "Сохранить"
}
//Сортировка по убыванию---------------------------------------------------------------------------
void __fastcall TForm4::N28Click(TObject *Sender)
{
	int nm = StringGrid1->Selection.Left;//Устанавливаем фокус на столбец
	if(StringGrid1->Cells[nm][0]=="Дата рождения" || StringGrid1->Cells[nm][0]=="Дата приёма на работу")//Если сортировка по дате
		sortData(sort_down, nm,data_date);//Сортировка по убыванию, для дат
	else//Если сортировка для строк
		sortData(sort_down, nm,data_str);//Сортировка по убыванию, для строк

	flag = true;//Флаг изменений
	N5->Enabled=true;ToolButton3->Enabled=true;//Доступность "Сохранить"
}

//Вычисление количества сотрудников, принятых на работу в .... году---------------------------------------------------------------------------
void __fastcall TForm4::N32Click(TObject *Sender)
{
	Button1->Visible=true;//доступ к кнопке
	Label1->Visible=true;//Доступ к заголовку
	ComboBox1->Items->Clear();//Очищаем список
	ComboBox1->Visible=true;//Выбор года
	ComboBox1->SetFocus();//Устновить фокус на выпадающий список

	for(int i=1;i<StringGrid1->RowCount-1;i++){
		AnsiString dop =  StringGrid1->Cells[8][i];//Присваиваем значение ячейки строке
		AnsiString dop1 =  dop.SubString(7,10);//Отделяем год от даты
		if (ComboBox1->Items->IndexOf(dop1) < 0) //Проверяем, нет ли такого элемента уже в списке combobox
			ComboBox1->Items->Add(dop1);//Добавляем
	}
}
//Вычисление количества сотрудников, принятых на работу в .... году---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	if(ComboBox1->ItemIndex>-1){//Если выбрано что-то из списка
		int k = 0;//Количество сотрудников
		for(int i=1;i<StringGrid1->RowCount-1;i++){
			AnsiString dop =  StringGrid1->Cells[8][i];//Присваиваем значение ячейки строке
			AnsiString dop1 =  dop.SubString(7,10);//Отделяем год от даты
			if(dop1==ComboBox1->Items->Strings[ComboBox1->ItemIndex])//Если год есть в списке
				k++;//Считаем количество сотрудников
	}
	ShowMessage("Количество сотрудников, принятых на работу в "+ComboBox1->Items->Strings[ComboBox1->ItemIndex]+" году: "+k);
	}
	else{//Если ничего не выбрано
	ShowMessage("Выберите год из списка, чтобы рассчитать количество сотрудников");
	}
	ComboBox1->Text="Год";//Устанавливаем заголовок
}
//Вычисление среднего возраста---------------------------------------------------------------------------
void __fastcall TForm4::N33Click(TObject *Sender)
{
	ComboBox1->Visible=false;//Выбор года
	Button1->Visible=false;//Доступ кнопки
	Label1->Visible=false;//Заголовок

	int c = StringGrid1->RowCount-2;//Количество сотрудников
	int s = 0;//Суммарный возраст
	for(int i=1;i<StringGrid1->RowCount-1;i++){
		AnsiString dop =  StringGrid1->Cells[4][i];//Присваиваем значение ячейки строке
		AnsiString dop1 =  dop.SubString(7,10);//Отделяем год от даты
		s += (2023-StrToInt(dop1));//Суммируем возраст на сегодняшний год
		}
	ShowMessage("Средний возраст сотрудников: "+IntToStr(s/c));
}
//Вычисление % сотрудников с высшим образованием---------------------------------------------------------------------------
void __fastcall TForm4::N34Click(TObject *Sender)
{
	ComboBox1->Visible=false;//Выбор года
	Button1->Visible=false;//Доступ кнопки
	Label1->Visible=false;//Заголовок

	int cnt = 0;//Количество сотрудников с высшим образованием(3)
	for(int i=1;i<StringGrid1->RowCount-1;i++){
	AnsiString dop = StringGrid1->Cells[6][i];//Присваиваем значение ячейки строке
		if(dop=="Высшее"){//Если высшее образование
			++cnt;//Увеличиваем количество сотрудников с высшим образованием
		}
	}
	ShowMessage("Процент сотрудников с высшим образованием: "+IntToStr(cnt*100/(StringGrid1->RowCount-2))+"%");
}

//Справка->Задание: открытие текствого файла---------------------------------------------------------------------------
void __fastcall TForm4::N17Click(TObject *Sender)
{
	WinExec("C:\\Windows\\system32\\notepad.exe E:\\Embarcadero\\Studio\\Projects\\Курсовая работа\\files\\task.txt", SW_SHOW);
}
//Справка->О программе: открытие текствого файла---------------------------------------------------------------------------
void __fastcall TForm4::N18Click(TObject *Sender)
{
	AboutBox->Show();
}
//Справка->Посмотреть справку: открытие текствого файла---------------------------------------------------------------------------
void __fastcall TForm4::N19Click(TObject *Sender)
{
	WinExec("C:\\Windows\\system32\\notepad.exe E:\\Embarcadero\\Studio\\Projects\\Курсовая работа\\files\\Ref.txt", SW_SHOW);
}

//Определение контекстного меню---------------------------------------------------------------------------
void __fastcall TForm4::StringGrid1MouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	if(Button==mbRight){//Если нажата ПКМ
		TGridCoord coord = StringGrid1->MouseCoord(X, Y); //Получаем координаты ячейки
		StringGrid1->Row = coord.Y;//Перемещаем курсор в строку выделенной ячейки
		StringGrid1->Col = coord.X;//Перемещаем курсор в столбец выделенной ячейки

		int row = StringGrid1->Row;//Записываем номер выделенной строки
		if (row <StringGrid1->RowCount-1)//Если её номер меньше количества строк
			StringGrid1->PopupMenu = PopupMenu1;//Контекстное меню номер 1
		else
			StringGrid1->PopupMenu = PopupMenu2;//Конеткстное меню номер 2
	}
}

//---------------------------------------------------------------------------

