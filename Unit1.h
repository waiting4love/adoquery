//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.Win.ADODB.hpp>
#include <Data.DB.hpp>
#include <Vcl.DbGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TADOQuery *ADOQuery1;
	TDataSource *DataSource1;
	TPanel *Panel1;
	TMemo *Memo1;
	TPanel *Panel2;
	TPanel *Panel3;
	TListBox *ListBox1;
	TPanel *Panel4;
	TDBGrid *DBGrid1;
	TDBNavigator *DBNavigator1;
	TSplitter *Splitter1;
	TListBox *ListBox2;
	TButton *Button1;
	TButton *Button2;
	TPopupMenu *PopupMenu1;
	TMenuItem *Select1;
	TMenuItem *CreateTable1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *MIN1;
	TMenuItem *MAX1;
	TMenuItem *SUM1;
	TMenuItem *AVG1;
	TMenuItem *COUNT1;
	TStatusBar *StatusBar1;
    TEdit *edtConStr;
	TADOConnection *ADOConnection1;
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall Memo1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall ListBox1DblClick(TObject *Sender);
	void __fastcall ListBox2DblClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall COUNT1Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
