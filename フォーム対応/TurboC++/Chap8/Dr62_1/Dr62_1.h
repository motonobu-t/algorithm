//---------------------------------------------------------------------------

#ifndef Dr62_1H
#define Dr62_1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TButton *Button1;
	TPaintBox *PaintBox1;
	void __fastcall Button1Click(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
