unit UnitResidualMenterSST;
// ����� ����������� ������� �� ����� ����������.

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, VclTee.TeeGDIPlus, VCLTee.TeEngine,
  VCLTee.Series, Vcl.ExtCtrls, VCLTee.TeeProcs, VCLTee.Chart;

type
  TFormResidualSST = class(TForm)
    Chart1: TChart;
    Series1: TFastLineSeries;
    Series2: TFastLineSeries;
    Series3: TFastLineSeries;
    Series4: TFastLineSeries;
    Series5: TFastLineSeries;
    Series6: TFastLineSeries;
    Timer1: TTimer;

    procedure ApplicationEvents1Message(var Msg: tagMSG; var Handled: Boolean);
    procedure Timer1Timer(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
    brun_visibleSST : Boolean;
  end;

var
  FormResidualSST: TFormResidualSST;

implementation

{$R *.dfm}

uses VisualUnit;

// ������ ����� �������������.
procedure TFormResidualSST.ApplicationEvents1Message(var Msg: tagMSG;
  var Handled: Boolean);
begin
    if (msg.message=WM_SYSCOMMAND)and(msg.wParam=SC_MINIMIZE)
   then
      msg.message:=0;
end;



procedure TFormResidualSST.Timer1Timer(Sender: TObject);
var
   f : TStringList; // ���������� ���� ������ TStringList
   i : Integer;
   fmin, fmax : Real;
   s, sub, subx : string;
begin
    // �������� ����� ����������� ������ �������.
    f:=TStringList.Create();

      try
       if brun_visibleSST then
       begin

       if (Laplas.egddata.itemper=0) then
       begin
          if (FileExists('statistic_convergence.txt')) then
          begin
             f.LoadFromFile('statistic_convergence.txt');

             if (FormatSettings.DecimalSeparator=',') then
             begin
                // �������� ��� ����� � ����� �� �������.
                for i:=0 to f.Count-1 do
                begin
                   s:=f.Strings[i];
                   f.Strings[i]:=StringReplace(s,'.',',',[rfReplaceAll]);
                end;
             end;

             // ������ ��� ������ ����� ����������.
             FormResidualSST.Chart1.SeriesList[0].Clear;
             FormResidualSST.Chart1.SeriesList[1].Clear;
             FormResidualSST.Chart1.SeriesList[2].Clear;
             FormResidualSST.Chart1.SeriesList[3].Clear;
             FormResidualSST.Chart1.SeriesList[4].Clear;
             FormResidualSST.Chart1.SeriesList[5].Clear;
             for i:=2 to f.Count-1 do
             begin
                fmin:=20.0;
                fmax:=120.0;
                s:=Trim(f.Strings[i]);
                subx:=Trim(Copy(s,1,Pos(' ',s)));
                s:=Trim(Copy(s,Pos(' ',s),Length(s)));
                sub:=Trim(Copy(s,1,Pos(' ',s)));
                if (StrToFloat(sub)<fmin) then
                begin
                   fmin:=StrToFloat(sub);
                end;
                if (StrToFloat(sub)>fmax) then
                begin
                   fmax:=StrToFloat(sub);
                end;
                FormResidualSST.Chart1.SeriesList[0].AddXY(StrToFloat(subx),StrToFloat(sub),subx,clred);
                s:=Trim(Copy(s,Pos(' ',s),Length(s)));
                sub:=Trim(Copy(s,1,Pos(' ',s)));
                if (length(sub)>0) then
                begin
                   if (StrToFloat(sub)<fmin) then
                   begin
                      fmin:=StrToFloat(sub);
                   end;
                   if (StrToFloat(sub)>fmax) then
                   begin
                      fmax:=StrToFloat(sub);
                   end;
                   FormResidualSST.Chart1.SeriesList[1].AddXY(StrToFloat(subx),StrToFloat(sub),subx,clgreen);

                   s:=Trim(Copy(s,Pos(' ',s),Length(s)));
                   sub:=Trim(Copy(s,1,Pos(' ',s)));
                   if (length(sub)>0) then
                   begin
                      if (StrToFloat(sub)<fmin) then
                      begin
                         fmin:=StrToFloat(sub);
                      end;
                      if (StrToFloat(sub)>fmax) then
                      begin
                         fmax:=StrToFloat(sub);
                      end;
                      FormResidualSST.Chart1.SeriesList[2].AddXY(StrToFloat(subx),StrToFloat(sub),subx,clgreen);
                      s:=Trim(Copy(s,Pos(' ',s),Length(s)));
                      sub:=Trim(Copy(s,1,Pos(' ',s)));
                      if (length(sub)>0) then
                      begin
                         if (StrToFloat(sub)<fmin) then
                         begin
                            fmin:=StrToFloat(sub);
                         end;
                         if (StrToFloat(sub)>fmax) then
                         begin
                            fmax:=StrToFloat(sub);
                         end;
                         FormResidualSST.Chart1.SeriesList[3].AddXY(StrToFloat(subx),StrToFloat(sub),subx,clblue);
                         s:=Trim(Copy(s,Pos(' ',s),Length(s)));
                         if (pos(' ',Trim(s))=0) then
                         begin
                            sub:=s;
                         end
                          else
                         begin
                            sub:=Trim(Copy(s,1,Pos(' ',s)));
                         end;
                         if (length(sub)>0) then
                         begin
                            if (StrToFloat(sub)<fmin) then
                            begin
                               fmin:=StrToFloat(sub);
                            end;
                            if (StrToFloat(sub)>fmax) then
                            begin
                               fmax:=StrToFloat(sub);
                            end;
                            FormResidualSST.Chart1.SeriesList[4].AddXY(StrToFloat(subx),StrToFloat(sub),subx,clOlive);
                            s:=Trim(Copy(s,Pos(' ',s),Length(s)));
                            if (pos(' ',Trim(s))=0) then
                            begin
                               sub:=s;
                            end
                              else
                            begin
                               sub:=Trim(Copy(s,1,Pos(' ',s)));
                            end;
                            if (length(sub)>0) then
                            begin
                               if (StrToFloat(sub)<fmin) then
                               begin
                                  fmin:=StrToFloat(sub);
                               end;
                               if (StrToFloat(sub)>fmax) then
                               begin
                                  fmax:=StrToFloat(sub);
                               end;
                               FormResidualSST.Chart1.SeriesList[5].AddXY(StrToFloat(subx),StrToFloat(sub),subx,clOlive);
                            end;
                       end
                        else
                       begin
                          // TODO
                          // ����� ������ ����� ������ ��� ��������.
                       end;
                   end;
                end;
            end
            else
            begin
               // TODO
               // ����� ������.
            end;
            FormResidualSST.Chart1.LeftAxis.Minimum:=1e-3*fmin;
            FormResidualSST.Chart1.LeftAxis.Maximum:=1e3*fmax;
         end;
         // ��� ������� ��������� �����, ��� ����� ��� ����������
         // �� ��� ����� ��������� ��������� ����������.
         //Formresidual.Show;
      end
      else
      begin
         // ���� ���� �� ������ �� �� ���� ������ ��������� ���������.
         //MainMemo.Lines.Add('statistic_convergence.txt not found.');
      end;
     end;
       end;

     except
        brun_visibleSST:=false;

      end;

    f.Free;
end;

end.
