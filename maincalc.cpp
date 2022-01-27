//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#include <math.h>
#pragma hdrstop
#include <sstream>
#include "maincalc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
 #define PI 3.14159265
 double round (double x);
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

long double x=0;
long double y=0;
 long double z=0;
 char D='0';
 bool q=false;
bool r=false;
 long double round(long double d)
{
   double id = int(d);
   return (d<0) ? ((id - d < 0.5) ? id : id-1) : ((d - id < 0.5) ? id : id+1);
}
//---------------------------------------------------------------------------
int F(AnsiString SS,char check)
 {   std::string s = SS.c_str();
return std::count(s.begin(), s.end(), check);

 }

   void A(AnsiString num)
   {
     if (r==false) q=true;
     if (q==true) Form1->Edit1->Text=num;
  else Form1-> Edit1->Text=Form1->Edit1->Text+num;
     q=false;
     r=true;

   }

void cnt()
{
if (D=='0') return;
y=StrToFloat(Form1->Edit1->Text.c_str());
if (D=='+') z=x+y;
else if (D=='-') z=x-y;
else if (D=='*') z=x*y;
else if (D=='/')
{
if (y==0) z=0;
 else z=x/y;
 }
 else if (D=='P') z=pow(x,y);
x=z;
Form1->Edit1->Text=FloatToStr(z);
q=false;
r=false;
D='0';
  Form1->Edit1->SetFocus();

      Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;
}

void S(char N)
{
if (r==true) cnt();
x=StrToFloat(Form1->Edit1->Text.c_str());
D=N;
r=false;
q=true;
Form1->Edit1->SetFocus();
   Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;
}

 void __fastcall TForm1::Button2Click(TObject *Sender)
{
A("2");
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
A("3");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
A("4");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
A("5");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
A("6");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
A("7");   
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
A("8");   
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
A("9");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
A("0");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
if (F(Form1->Edit1->Text,DecimalSeparator)==1) return;
else Edit1->Text= Edit1->Text+DecimalSeparator;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button19Click(TObject *Sender)
{
cnt();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button14Click(TObject *Sender)
{
S('+');
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button15Click(TObject *Sender)
{
S('-');
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button16Click(TObject *Sender)
{
S('*');
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button17Click(TObject *Sender)
{
S('/');
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
A("1");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button18Click(TObject *Sender)
{
x=0;
y=0;
z=0;
D='0';
q=false;
r=false;
Edit1->Text="0";
Form1->Edit1->SetFocus();
  Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
DecimalSeparator = ',';

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
long double k=StrToFloat(Edit1->Text);
k=k*k;
Edit1->Text=FloatToStr(k);
        Form1->Edit1->SetFocus();
    Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
long double l=StrToFloat(Edit1->Text);
l=sqrt(l);
Edit1->Text=FloatToStr(l);
      Form1->Edit1->SetFocus();
               Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key=='1') A("1");
else if (Key=='2') A("2");
else if (Key=='3') A("3");
else if (Key=='4') A("4");
else if (Key=='5') A("5");
else if (Key=='6') A("6");
else if (Key=='7') A("7");
else if ((Key=='8')&&(!Shift.Contains(ssShift))) A("8");
else if (Key=='9') A("9");
else if (Key=='0') A("0");
else if (Key==8)
{
Edit1->Text = Edit1->Text.Delete(Edit1->Text.Length(), 1);
}
else if (Key==13) cnt();
else if (Key==107) S('+');
else if (Key==187) S('+');
else if (Key==109) S('-');
else if ((Key==189)&&(Shift.Contains(ssShift))) cnt();
else if ((Key==189)&&(!Shift.Contains(ssShift))) S('-');
else if (Key==106) S('*');
else if ((Key==56)&&(Shift.Contains(ssShift))) S('*');
else if (Key==111) S('/');
else if (Key==191) S('/');
if (Edit1->Text =="") Edit1->Text=0;
   Form1->Edit1->SetFocus();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button20Click(TObject *Sender)
{
long double u=StrToFloat(Edit1->Text);
u=-u;
Edit1->Text=FloatToStr(u);
        Form1->Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
 long double k=StrToFloat(Edit1->Text);
Edit1->Text=FloatToStr(sin(k* PI / 180));
  Form1->Edit1->SetFocus();
     Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
 long double k=StrToFloat(Edit1->Text);
Edit1->Text=FloatToStr(cos(k* PI / 180));
Form1->Edit1->SetFocus();
    Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
  long double k=StrToFloat(Edit1->Text);
 Edit1->Text=FloatToStr(tan(k* PI / 180));
Form1->Edit1->SetFocus();
     Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::Button24Click(TObject *Sender)
{
    long double k=StrToFloat(Edit1->Text);
 Edit1->Text=FloatToStr(abs(k));
 Form1->Edit1->SetFocus();
      Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button25Click(TObject *Sender)
{
     long double k=StrToFloat(Edit1->Text);
 Edit1->Text=FloatToStr(floor(k));
   Form1->Edit1->SetFocus();
      Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button26Click(TObject *Sender)
{
   long double k=StrToFloat(Edit1->Text);
 Edit1->Text=FloatToStr(ceil(k));
  Form1->Edit1->SetFocus();
       Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button27Click(TObject *Sender)
{
S('P');
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button28Click(TObject *Sender)
{
     long double k=StrToFloat(Edit1->Text);
 Edit1->Text=FloatToStr(round(k));
   Form1->Edit1->SetFocus();
      Form1->Edit1->SelStart=Form1->Edit1->Text.Length();
      Form1->Edit1->SelLength=0;
}
//---------------------------------------------------------------------------

