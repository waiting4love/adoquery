//---------------------------------------------------------------------------

#ifndef blobH
#define blobH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.DBActns.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
//---------------------------------------------------------------------------
class Tfm_Blob : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TTabSheet *TabSheet5;
        TButton *Button1;
        TButton *Button2;
        TButton *Button4;
        TDBMemo *DBMemo1;
        TDBImage *DBImage1;
        TDBRichEdit *DBRichEdit1;
        TDBRichEdit *DBRichEdit2;
        TDBMemo *DBMemo2;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TOpenPictureDialog *OpenPictureDialog1;
        TSavePictureDialog *SavePictureDialog1;
        TButton *Button3;
        TToolBar *ToolBar1;
        TComboBox *ComboBox1;
        TToolButton *ToolButton2;
        TComboBox *ComboBox2;
        TComboBox *ComboBox3;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TPopupMenu *PopupMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TImageList *ImageList1;
        TColorDialog *ColorDialog1;
        TActionList *ActionList1;
        TEditCopy *EditCopy1;
        TEditCut *EditCut1;
        TEditDelete *EditDelete1;
        TEditPaste *EditPaste1;
        TEditSelectAll *EditSelectAll1;
        TEditUndo *EditUndo1;
        TPopupMenu *PopupMenu2;
        TMenuItem *Undo1;
        TMenuItem *N9;
        TMenuItem *Cut1;
        TMenuItem *Copy1;
        TMenuItem *Paste1;
        TMenuItem *Cut2;
        TMenuItem *N10;
        TMenuItem *SelectAll1;
	TButton *Button5;
	TDataSetPrior *DataSetPrior1;
	TDataSetNext *DataSetNext1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall PageControl1Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall DBRichEdit1SelectionChange(TObject *Sender);
        void __fastcall ComboBox3Change(TObject *Sender);
        void __fastcall PopupMenu1Popup(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall DBImage1DblClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfm_Blob(TComponent* Owner);
        TDataSource *DS;
        AnsiString Fieldname;
//        TMDIChild *OpChild;
        TField * Field;
        void FreePage(void);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm_Blob *fm_Blob;
//---------------------------------------------------------------------------
#endif
