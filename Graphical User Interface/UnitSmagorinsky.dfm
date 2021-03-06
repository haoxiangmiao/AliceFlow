object FormSmagorinsky: TFormSmagorinsky
  Left = 470
  Top = 132
  AutoSize = True
  Caption = 'Smagorinsky Model'
  ClientHeight = 481
  ClientWidth = 425
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panelmain: TPanel
    Left = 0
    Top = 0
    Width = 425
    Height = 481
    Color = clMoneyGreen
    TabOrder = 0
    object CBcorrectnonuniformgrid: TCheckBox
      Left = 216
      Top = 16
      Width = 161
      Height = 17
      Caption = 'correction for non-uniform grid'
      TabOrder = 0
    end
    object CBSmagLilly: TCheckBox
      Left = 216
      Top = 40
      Width = 177
      Height = 17
      Caption = 'include Smagorinsky-Lilly Model'
      TabOrder = 1
    end
    object GBsurfacerougnessparam: TGroupBox
      Left = 8
      Top = 360
      Width = 201
      Height = 113
      Caption = 'surface roughness'
      Color = clMoneyGreen
      ParentColor = False
      TabOrder = 2
      object Panrougness: TPanel
        Left = 8
        Top = 40
        Width = 185
        Height = 65
        Color = clMoneyGreen
        TabOrder = 0
        object LRoughness: TLabel
          Left = 8
          Top = 16
          Width = 54
          Height = 13
          Caption = 'Roughness'
        end
        object Lroghness: TLabel
          Left = 144
          Top = 16
          Width = 31
          Height = 13
          Caption = 'micron'
        end
        object Lpower: TLabel
          Left = 8
          Top = 40
          Width = 60
          Height = 13
          Caption = 'power model'
        end
        object Eroughnessmicron: TEdit
          Left = 72
          Top = 8
          Width = 65
          Height = 21
          TabOrder = 0
        end
        object CBpowermodel: TComboBox
          Left = 72
          Top = 32
          Width = 49
          Height = 21
          ItemIndex = 0
          TabOrder = 1
          Text = '1'
          Items.Strings = (
            '1'
            '2')
        end
      end
      object CBsurfaceroughness: TCheckBox
        Left = 8
        Top = 16
        Width = 153
        Height = 17
        Caption = 'include surface roughness'
        TabOrder = 1
        OnClick = CBsurfaceroughnessClick
      end
    end
    object BApply: TButton
      Left = 328
      Top = 408
      Width = 75
      Height = 25
      Caption = 'Apply'
      TabOrder = 3
      OnClick = BApplyClick
    end
    object GBSwirlDominatedFlow: TGroupBox
      Left = 216
      Top = 64
      Width = 201
      Height = 97
      Caption = 'Swirl Dominated Flow'
      TabOrder = 4
      object CBSwirlAmendment: TCheckBox
        Left = 8
        Top = 24
        Width = 105
        Height = 17
        Caption = 'Swirl Amendment'
        TabOrder = 0
        OnClick = CBSwirlAmendmentClick
      end
      object PanRichardson: TPanel
        Left = 8
        Top = 48
        Width = 185
        Height = 41
        Color = clMoneyGreen
        TabOrder = 1
        object LRiMult: TLabel
          Left = 8
          Top = 12
          Width = 100
          Height = 13
          Caption = 'Richardson multiplyer'
        end
        object ERimult: TEdit
          Left = 112
          Top = 12
          Width = 65
          Height = 21
          TabOrder = 0
        end
      end
    end
    object GBSelectiveSmagorinsky: TGroupBox
      Left = 216
      Top = 168
      Width = 201
      Height = 225
      Caption = 'Selective Smagorinsky Model'
      TabOrder = 5
      object CBSelectiveSmagorinsky: TCheckBox
        Left = 8
        Top = 24
        Width = 169
        Height = 17
        Caption = 'include Selective Smagorinsky'
        TabOrder = 0
        OnClick = CBSelectiveSmagorinskyClick
      end
      object PSelectiveSmag: TPanel
        Left = 8
        Top = 48
        Width = 185
        Height = 169
        Color = clMoneyGreen
        TabOrder = 1
        object LselectiveAngle: TLabel
          Left = 8
          Top = 8
          Width = 74
          Height = 13
          Caption = 'Selective Angle'
        end
        object Ldegree: TLabel
          Left = 88
          Top = 32
          Width = 33
          Height = 13
          Caption = 'degree'
        end
        object RGtypefiltr: TRadioGroup
          Left = 8
          Top = 56
          Width = 137
          Height = 105
          Caption = 'Type FILTR'
          ItemIndex = 2
          Items.Strings = (
            'VOLUME AVERAGE'
            'TRAPEZOIDAL'
            'SIMPSON')
          TabOrder = 0
        end
        object Eangle: TEdit
          Left = 8
          Top = 24
          Width = 73
          Height = 21
          TabOrder = 1
        end
      end
    end
    object GBConstSmagorinsky: TGroupBox
      Left = 8
      Top = 8
      Width = 201
      Height = 345
      Caption = 'Const  Smagorinsky'
      TabOrder = 6
      object PanelCs: TPanel
        Left = 8
        Top = 24
        Width = 129
        Height = 41
        Color = clMoneyGreen
        TabOrder = 0
        object Lsmagconst: TLabel
          Left = 8
          Top = 8
          Width = 22
          Height = 24
          Caption = 'Cs'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Esmagconst: TEdit
          Left = 40
          Top = 8
          Width = 81
          Height = 21
          TabOrder = 0
        end
      end
      object CBDynamicStress: TCheckBox
        Left = 8
        Top = 72
        Width = 185
        Height = 25
        Caption = 'Dynamic Stress (Germano [1991])'
        TabOrder = 1
        OnClick = CBDynamicStressClick
      end
      object PanelLimitersCs: TPanel
        Left = 8
        Top = 104
        Width = 169
        Height = 225
        Color = clMoneyGreen
        TabOrder = 2
        object CBLimitersCs: TCheckBox
          Left = 8
          Top = 8
          Width = 97
          Height = 17
          Caption = 'Limiters for  Cs'
          TabOrder = 0
          OnClick = CBLimitersCsClick
        end
        object Panel_user_limiters: TPanel
          Left = 8
          Top = 32
          Width = 145
          Height = 73
          Color = clMoneyGreen
          TabOrder = 1
          object LminCs: TLabel
            Left = 8
            Top = 16
            Width = 31
            Height = 13
            Caption = 'min Cs'
          end
          object LmaxCs: TLabel
            Left = 8
            Top = 48
            Width = 34
            Height = 13
            Caption = 'max Cs'
          end
          object EminCs: TEdit
            Left = 48
            Top = 8
            Width = 89
            Height = 21
            TabOrder = 0
          end
          object EmaxCs: TEdit
            Left = 48
            Top = 40
            Width = 89
            Height = 21
            TabOrder = 1
          end
        end
        object RGtypefiltrGermanoModel: TRadioGroup
          Left = 8
          Top = 112
          Width = 153
          Height = 105
          Caption = 'Type FILTR Germano Model'
          ItemIndex = 2
          Items.Strings = (
            'VOLUME AVERAGE'
            'TRAPEZOIDAL'
            'SIMPSON')
          TabOrder = 2
        end
      end
    end
  end
end
