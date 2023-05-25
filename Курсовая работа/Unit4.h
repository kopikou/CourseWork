//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include "Unit1.h"
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TStringGrid *StringGrid1;
	TMenuItem *N24;
	TMenuItem *N26;
	TMenuItem *N27;
	TMenuItem *N28;
	TImageList *ImageList1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TPopupMenu *PopupMenu1;
	TMenuItem *N20;
	TMenuItem *N21;
	TMenuItem *N22;
	TButton *Button1;
	TComboBox *ComboBox1;
	TMenuItem *N23;
	TMenuItem *N25;
	TMenuItem *N29;
	TPopupMenu *PopupMenu2;
	TMenuItem *N30;
	TMenuItem *N31;
	TMenuItem *N32;
	TMenuItem *N33;
	TMenuItem *N34;
	TLabel *Label1;
	void __fastcall N17Click(TObject *Sender);
	void __fastcall N18Click(TObject *Sender);
	void __fastcall N19Click(TObject *Sender);
   	void __fastcall N10Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N12Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall N14Click(TObject *Sender);
	void __fastcall ToolButton7Click(TObject *Sender);
	void __fastcall N13Click(TObject *Sender);
	void __fastcall ToolButton6Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N24Click(TObject *Sender);
	void __fastcall ToolButton9Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall N27Click(TObject *Sender);
	void __fastcall N28Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N33Click(TObject *Sender);
	void __fastcall N34Click(TObject *Sender);
	void __fastcall StringGrid1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall N32Click(TObject *Sender);


	//void __fastcall StringGrid1Popup(TObject *Sender)

private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
    AnsiString filename;//Имя файла
	int dataSize[8]={ 15,15,15,11,11,10,20,11 }; //= 108 Размеры данных в бинарном файле
	bool flag=false;//Чтобы определить были ли какие-то изменения в файле

	//Доступность пунктов меню---------------------------------------------------------------------------
	void turnon(){
		N6->Enabled=true;//Сохранить как
		N8->Enabled=true;//Закрыть
		N13->Enabled=true;ToolButton6->Enabled=true;N21->Enabled=true;//Удалить
		N14->Enabled=true;ToolButton7->Enabled=true;N20->Enabled=true;//Редактировать
		N24->Enabled=true;ToolButton9->Enabled=true;N30->Enabled=true;//Поиск
		N26->Enabled=true;N23->Enabled=true;//Сортировка
		N31->Enabled=true;//Расчёты

		ComboBox1->Visible=false;//Выбор года
		Button1->Visible=false;//Доступ кнопки
        Label1->Visible=false;
	}

	//Недоступность пунктов меню---------------------------------------------------------------------------
	void turnoff(){
		N5->Enabled=false;ToolButton3->Enabled=false;//Сохранить
		N6->Enabled=false;//Сохранить как
		N8->Enabled=false;//Закрыть
		N13->Enabled=false;ToolButton6->Enabled=false;N21->Enabled=false;//Удалить
		N14->Enabled=false;ToolButton7->Enabled=false;N20->Enabled=false;//Редактировать
		N24->Enabled=false;ToolButton9->Enabled=false;N30->Enabled=false;//Поиск
		N26->Enabled=false;N23->Enabled=false;//Сортировка
		N31->Enabled=false;//Рассчёт

		ComboBox1->Visible=false;//Выбор года
		Button1->Visible=false;//Доступ кнопки
		Label1->Visible=false;
	}

	//Заполнение заголовка таблицы---------------------------------------------------------------------------
	void fill(){
		StringGrid1->Cells[1][0]="Фамилия";//Заголовок таблицы
		StringGrid1->ColWidths[1] = 200;//Размер, отводимы под слово
		StringGrid1->Cells[2][0]="Имя";
		StringGrid1->ColWidths[2] = 200;
		StringGrid1->Cells[3][0]="Отчество";
		StringGrid1->ColWidths[3] = 200;
		StringGrid1->Cells[4][0]="Дата рождения";
		StringGrid1->ColWidths[4] = 175;
		StringGrid1->Cells[5][0]="Паспортные данные";
		StringGrid1->ColWidths[5] = 240;
		StringGrid1->Cells[6][0]="Образование";
		StringGrid1->ColWidths[6] = 150;
		StringGrid1->Cells[7][0]="Должность";
		StringGrid1->ColWidths[7] = 200;
		StringGrid1->Cells[8][0]="Дата приёма на работу";
		StringGrid1->ColWidths[8] = 250;
		StringGrid1->Cells[0][0]="№";
		StringGrid1->ColWidths[0] = 50;
	}

	//Редактирование: заполнение полей---------------------------------------------------------------------------
	void editfill(int nm){
		Form1->Edit1->Text=StringGrid1->Cells[1][nm];//Edit присваиваем значение ячейки таблицы
		Form1->Edit2->Text=StringGrid1->Cells[2][nm];
		Form1->Edit3->Text=StringGrid1->Cells[3][nm];
		Form1->DateTimePicker1->Date=StrToDate(StringGrid1->Cells[4][nm]);
		Form1->Edit5->Text=StringGrid1->Cells[5][nm].SubString(1,4);
		Form1->Edit9->Text=StringGrid1->Cells[5][nm].SubString(5,10);
		Form1->ComboBox1->Text=StringGrid1->Cells[6][nm];
		Form1->Edit7->Text=StringGrid1->Cells[7][nm];
		Form1->DateTimePicker2->Date=StrToDate(StringGrid1->Cells[8][nm]);
	}

	//Сохранение---------------------------------------------------------------------------
	void save(TFileStream *fs){
		for (int i = 1; i < StringGrid1->RowCount-1; i++)
		{
			for (int j = 1; j < StringGrid1->ColCount; j++)
			{
				AnsiString str = StringGrid1->Cells[j][i];
				fs->Write(str.c_str(), dataSize[j-1]);//Записываем данные из ячеек в файл: строка заданной длины
			}
		}
		delete fs;//Удалить элемент потокового ввода
	}

	//Перечисление для функции сортировки---------------------------------------------------------------------------
	enum Sort{
		sort_up, //По возрастанию
		sort_down, //По убыванию
	};
	//Перечисление для определения типа сортируемых данных---------------------------------------------------------------------------
	enum Data{
		data_date, //Дата
		data_str, //Строка
	};
	//Функция сортировки---------------------------------------------------------------------------
	void sortData(Sort type,int nm,Data tip){
		if(type == sort_up){//Если сортировка по возрастанию
			if(tip == data_str){//Если сравниваем строки
				TStringList* dop = new TStringList;//Создаем вспомогательную строку
				for(int i=1;i<StringGrid1->RowCount-1;i++){
					for(int j = 1;j<StringGrid1->RowCount-i-1;j++){
						if(StringGrid1->Cells[nm][j]>StringGrid1->Cells[nm][j+1]){//Сравниваем две ячейки
							bubble(dop,j);//Сортировка пузырьком
						}
					}
				}
				delete dop;//Удаляем вспомогательную строку
				rownumber();//Возобновляем нумерацию
			}
			else if(tip == data_date){//Если сравниваем даты
				TStringList* dop = new TStringList;//Создаем вспомогательную строку
				for(int i=1;i<StringGrid1->RowCount-1;i++){
					for(int j = 1;j<StringGrid1->RowCount-i-1;j++){

						TDateTime data1= StringGrid1->Cells[nm][j];//Приводим значение ячейки к дате
						TDateTime data2= StringGrid1->Cells[nm][j+1];
						if(data1>data2){//Сравниваем даты
							bubble(dop,j);//Сортировка пузырьком
						}
					}
				}
				delete dop;//Удаляем вспомогательную строку
				rownumber();//Возобновляем нумерацию
			}
		}
		else if(type == sort_down){//Если сортировка по убыванию
			if(tip == data_str){//Если сравниваем строки
				TStringList* dop = new TStringList;//Создаем вспомогательную строку
				for(int i=1;i<StringGrid1->RowCount-1;i++){
					for(int j = 1;j<StringGrid1->RowCount-i-1;j++){
						if(StringGrid1->Cells[nm][j]<StringGrid1->Cells[nm][j+1]){//Сравниваем две ячейки
							bubble(dop,j);//Сортировка пузырьком
						}
					}
				}
				delete dop;//Удаляем вспомогательную строку
				rownumber();//Возобновляем нумерацию
			}
			else if(tip == data_date){//Если сравниваем даты
				TStringList* dop = new TStringList;//Создаем вспомогательную строку
				for(int i=1;i<StringGrid1->RowCount-1;i++){
					for(int j = 1;j<StringGrid1->RowCount-i-1;j++){

						TDateTime data1= StringGrid1->Cells[nm][j];//Приводим значение ячейки к дате
						TDateTime data2= StringGrid1->Cells[nm][j+1];
						if(data1<data2){//Сравниваем даты
							bubble(dop,j);//Сортировка пузырьком
						}
					}
				}
				delete dop;//Удаляем вспомогательную строку
				rownumber();//Возобновляем нумерацию
			}
		}
	}
	//Функция нумерации строк в таблице---------------------------------------------------------------------------
	void rownumber(){
        for (int i = 1; i < StringGrid1->RowCount-1; i++) {
			StringGrid1->Cells[0][i] = i;//Присваиваем ячейке значение номера строки
		}
	}
	//Сортировка пузырьком---------------------------------------------------------------------------
	void bubble(TStringList* dop,int j){
		dop->Add(StringGrid1->Rows[j]->Text);//Переставляем значения местами с помощью вспомогательного элемента
		StringGrid1->Rows[j]=StringGrid1->Rows[j+1];
		StringGrid1->Rows[j+1]->Text= dop->Strings[0];
		dop->Delete(0);//очищаем вспомогательный элемент
	}
	//Функция очистки таблицы---------------------------------------------------------------------------
	void gridclear(){
		for (int i=1; i < StringGrid1->RowCount; i++) {
			StringGrid1->Rows[i]->Clear();//Очищаем ячейки
		}
		StringGrid1->RowCount=2;//Устнавливаем первоначальное количество строк
	}

	//Функция создания нового файла---------------------------------------------------------------------------
	void createnew(){
		gridclear();//Очистить таблицу
		N3->Enabled=true;ToolButton2->Enabled=true;//Доступность "Открыть"
		turnoff();//Недоступность пунктов меню
	}
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
