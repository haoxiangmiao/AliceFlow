object AddBlockForm: TAddBlockForm
  Left = 374
  Top = 167
  AutoSize = True
  Caption = 'Add Block'
  ClientHeight = 569
  ClientWidth = 371
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panelglobalconteiner: TPanel
    Left = 0
    Top = 0
    Width = 371
    Height = 569
    Color = clMoneyGreen
    ParentBackground = False
    TabOrder = 0
    object RadioGroupglobalconteiner: TRadioGroup
      Left = 0
      Top = 13
      Width = 369
      Height = 52
      Caption = 'size and properties block'
      Columns = 3
      ItemIndex = 0
      Items.Strings = (
        'Info'
        'Geometry'
        'Properties')
      TabOrder = 0
      OnClick = RadioGroupglobalconteinerClick
    end
    object Panelinfo: TPanel
      Left = 9
      Top = 71
      Width = 352
      Height = 434
      Color = clMoneyGreen
      ParentBackground = False
      TabOrder = 1
      object lblset_trans: TLabel
        Left = 11
        Top = 136
        Width = 84
        Height = 13
        Caption = 'Set Transparency'
      end
      object lbltransparent: TLabel
        Left = 16
        Top = 163
        Width = 57
        Height = 13
        Caption = 'Transparent'
      end
      object lblOpaque: TLabel
        Left = 88
        Top = 212
        Width = 38
        Height = 13
        Caption = 'Opaque'
      end
      object lblTransparentlab: TLabel
        Left = 176
        Top = 212
        Width = 57
        Height = 13
        Caption = 'Transparent'
      end
      object lbltransparencyvalue: TLabel
        Left = 160
        Top = 169
        Width = 6
        Height = 13
        Caption = '0'
      end
      object LabelLineWidth: TLabel
        Left = 24
        Top = 240
        Width = 48
        Height = 13
        Caption = 'LineWidth'
      end
      object GBname: TGroupBox
        Left = 8
        Top = 17
        Width = 313
        Height = 49
        Caption = 'block name'
        TabOrder = 0
        object Ename: TEdit
          Left = 8
          Top = 16
          Width = 289
          Height = 21
          TabOrder = 0
        end
      end
      object GroupBoxPriority: TGroupBox
        Left = 11
        Top = 71
        Width = 185
        Height = 49
        Caption = 'Priority'
        TabOrder = 1
        object EditPriority: TEdit
          Left = 13
          Top = 25
          Width = 156
          Height = 21
          TabOrder = 0
        end
      end
      object btncolor: TButton
        Left = 160
        Top = 126
        Width = 41
        Height = 25
        Caption = 'color'
        TabOrder = 2
        OnClick = btncolorClick
      end
      object scrlbrtrans1: TScrollBar
        Left = 89
        Top = 188
        Width = 145
        Height = 17
        PageSize = 0
        TabOrder = 3
        OnChange = scrlbrtrans1Change
      end
      object CheckBoxVisible: TCheckBox
        Left = 224
        Top = 96
        Width = 97
        Height = 17
        Caption = 'Visible'
        Checked = True
        State = cbChecked
        TabOrder = 4
      end
      object ComboBoxLineWidth: TComboBox
        Left = 88
        Top = 237
        Width = 36
        Height = 21
        ItemIndex = 0
        TabOrder = 5
        Text = '1'
        Items.Strings = (
          '1'
          '2'
          '3'
          '4'
          '5'
          '6')
      end
    end
    object Bapply: TButton
      Left = 272
      Top = 522
      Width = 75
      Height = 25
      Caption = 'Apply'
      TabOrder = 2
      OnClick = BapplyClick
    end
    object PanelGeometry: TPanel
      Left = 9
      Top = 71
      Width = 352
      Height = 434
      Color = clMoneyGreen
      ParentBackground = False
      TabOrder = 3
      Visible = False
      object LabelGeometryType: TLabel
        Left = 32
        Top = 24
        Width = 66
        Height = 13
        Caption = 'geometry type'
      end
      object LabelPlane: TLabel
        Left = 30
        Top = 52
        Width = 27
        Height = 13
        Caption = 'Plane'
        Visible = False
      end
      object GBsizeBlock: TGroupBox
        Left = 20
        Top = 84
        Width = 312
        Height = 141
        Caption = 'size block'
        Color = clMoneyGreen
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        object LxS: TLabel
          Left = 8
          Top = 16
          Width = 12
          Height = 13
          Caption = 'xS'
        end
        object LyS: TLabel
          Left = 8
          Top = 48
          Width = 12
          Height = 13
          Caption = 'yS'
        end
        object LzS: TLabel
          Left = 8
          Top = 80
          Width = 12
          Height = 13
          Caption = 'zS'
        end
        object LxE: TLabel
          Left = 134
          Top = 23
          Width = 12
          Height = 13
          Caption = 'xE'
        end
        object LyE: TLabel
          Left = 134
          Top = 48
          Width = 12
          Height = 13
          Caption = 'yE'
        end
        object LzE: TLabel
          Left = 134
          Top = 85
          Width = 12
          Height = 13
          Caption = 'zE'
        end
        object Label1: TLabel
          Left = 104
          Top = 16
          Width = 16
          Height = 13
          Caption = 'mm'
        end
        object Label2: TLabel
          Left = 104
          Top = 48
          Width = 16
          Height = 13
          Caption = 'mm'
        end
        object Label3: TLabel
          Left = 104
          Top = 80
          Width = 16
          Height = 13
          Caption = 'mm'
        end
        object Label4: TLabel
          Left = 276
          Top = 24
          Width = 16
          Height = 13
          Caption = 'mm'
        end
        object Label5: TLabel
          Left = 274
          Top = 61
          Width = 16
          Height = 13
          Caption = 'mm'
        end
        object Label6: TLabel
          Left = 274
          Top = 80
          Width = 16
          Height = 13
          Caption = 'mm'
        end
        object ExS: TEdit
          Left = 32
          Top = 16
          Width = 57
          Height = 21
          TabOrder = 0
        end
        object EyS: TEdit
          Left = 32
          Top = 48
          Width = 57
          Height = 21
          TabOrder = 1
        end
        object EzS: TEdit
          Left = 32
          Top = 77
          Width = 57
          Height = 21
          TabOrder = 2
        end
        object ExE: TEdit
          Left = 205
          Top = 16
          Width = 65
          Height = 21
          TabOrder = 3
        end
        object EyE: TEdit
          Left = 205
          Top = 43
          Width = 65
          Height = 21
          TabOrder = 4
        end
        object EzE: TEdit
          Left = 205
          Top = 80
          Width = 65
          Height = 21
          TabOrder = 5
        end
        object CheckBoxCylinder2Prism: TCheckBox
          Left = 24
          Top = 112
          Width = 96
          Height = 17
          Caption = 'Cylinder2Prism'
          TabOrder = 6
        end
        object CheckBoxFixedCylinder: TCheckBox
          Left = 140
          Top = 107
          Width = 97
          Height = 17
          Caption = 'Fixed Cylinder'
          TabOrder = 7
        end
      end
      object ComboBoxgeometrytype: TComboBox
        Left = 112
        Top = 16
        Width = 193
        Height = 21
        ItemIndex = 0
        TabOrder = 1
        Text = 'Prism'
        OnChange = ComboBoxgeometrytypeChange
        Items.Strings = (
          'Prism'
          'Cylinder'
          'Polygon')
      end
      object ComboBoxPlane: TComboBox
        Left = 72
        Top = 44
        Width = 54
        Height = 21
        ItemIndex = 0
        TabOrder = 2
        Text = 'XY'
        Visible = False
        Items.Strings = (
          'XY'
          'XZ'
          'YZ')
      end
      object GBPolygonGeom: TGroupBox
        Left = 18
        Top = 84
        Width = 314
        Height = 157
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = 'Location'
        TabOrder = 3
        Visible = False
        object Labeldim1: TLabel
          Left = 139
          Top = 27
          Width = 48
          Height = 13
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = 'Labeldim1'
        end
        object Labeldimx: TLabel
          Left = 139
          Top = 53
          Width = 47
          Height = 13
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = 'Labeldimx'
        end
        object Labeldimy: TLabel
          Left = 139
          Top = 75
          Width = 47
          Height = 13
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = 'Labeldimy'
        end
        object Labeldimz: TLabel
          Left = 139
          Top = 99
          Width = 47
          Height = 13
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = 'Labeldimz'
        end
        object LabelnameH: TLabel
          Left = 11
          Top = 32
          Width = 31
          Height = 13
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = 'Height'
        end
        object Labelx: TLabel
          Left = 11
          Top = 53
          Width = 31
          Height = 13
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = 'Labelx'
        end
        object Labely: TLabel
          Left = 11
          Top = 80
          Width = 31
          Height = 13
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = 'Labely'
        end
        object Labelz: TLabel
          Left = 13
          Top = 107
          Width = 31
          Height = 13
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = 'Labelz'
        end
        object ListBoxvert: TListBox
          Left = 168
          Top = 16
          Width = 137
          Height = 107
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          ItemHeight = 13
          TabOrder = 0
          OnClick = ListBoxvertClick
        end
        object ButtonAdd: TButton
          Left = 176
          Top = 133
          Width = 50
          Height = 17
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = 'Add'
          TabOrder = 1
          OnClick = ButtonAddClick
        end
        object ButtonRemove: TButton
          Left = 240
          Top = 133
          Width = 50
          Height = 17
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = 'Remove'
          TabOrder = 2
          OnClick = ButtonRemoveClick
        end
        object EditHeight: TEdit
          Left = 48
          Top = 27
          Width = 81
          Height = 21
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          TabOrder = 3
          Text = 'EditHeight'
        end
        object Editx: TEdit
          Left = 50
          Top = 51
          Width = 81
          Height = 21
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          TabOrder = 4
          Text = 'Editx'
        end
        object Edity: TEdit
          Left = 50
          Top = 75
          Width = 81
          Height = 21
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          TabOrder = 5
          Text = 'Edity'
        end
        object Editz: TEdit
          Left = 48
          Top = 99
          Width = 81
          Height = 21
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          TabOrder = 6
          Text = 'Editz'
        end
      end
    end
    object PanelProperties: TPanel
      Left = 9
      Top = 71
      Width = 352
      Height = 434
      Color = clMoneyGreen
      ParentBackground = False
      TabOrder = 4
      Visible = False
      object RadioGroupType: TRadioGroup
        Left = 10
        Top = 16
        Width = 289
        Height = 51
        Caption = 'Block type'
        Color = clMoneyGreen
        Columns = 3
        ItemIndex = 0
        Items.Strings = (
          'SOLID'
          'HOLLOW'
          'FLUID')
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        OnClick = RadioGroupTypeClick
      end
      object Panel1: TPanel
        Left = 9
        Top = 79
        Width = 288
        Height = 78
        Color = clMoneyGreen
        ParentBackground = False
        TabOrder = 1
        object Label7: TLabel
          Left = 16
          Top = 16
          Width = 99
          Height = 13
          Caption = 'Surface specification'
        end
        object ButtonRadiation: TButton
          Left = 13
          Top = 35
          Width = 75
          Height = 25
          Caption = 'Radiation'
          TabOrder = 0
          OnClick = ButtonRadiationClick
        end
      end
      object GroupBoxPropBl: TGroupBox
        Left = 11
        Top = 169
        Width = 313
        Height = 184
        Caption = 'Thermal specification'
        Color = clMoneyGreen
        ParentBackground = False
        ParentColor = False
        TabOrder = 2
        object LMN: TLabel
          Left = 16
          Top = 48
          Width = 3
          Height = 13
          Color = clMoneyGreen
          ParentColor = False
        end
        object lblmateril: TLabel
          Left = 16
          Top = 29
          Width = 71
          Height = 13
          Caption = 'material name :'
        end
        object Labelpowerinfo: TLabel
          Left = 143
          Top = 42
          Width = 74
          Height = 13
          Caption = 'LabelPowerInfo'
        end
        object GBmaterial: TGroupBox
          Left = 13
          Top = 76
          Width = 289
          Height = 105
          Caption = 'Material'
          Color = clMoneyGreen
          ParentBackground = False
          ParentColor = False
          TabOrder = 0
          object RGSelect: TRadioGroup
            Left = 7
            Top = 16
            Width = 226
            Height = 49
            Caption = 'Define '
            Color = clMoneyGreen
            Columns = 2
            ItemIndex = 0
            Items.Strings = (
              'Program Library'
              'User-Defined')
            ParentColor = False
            TabOrder = 0
            OnClick = RGSelectClick
          end
          object BEditApply: TButton
            Left = 239
            Top = 21
            Width = 41
            Height = 81
            Caption = 'Edit'
            TabOrder = 1
            OnClick = BEditApplyClick
          end
          object CBselectAction: TComboBox
            Left = 8
            Top = 72
            Width = 225
            Height = 21
            TabOrder = 2
            Text = 'Edit Current Material'
            Items.Strings = (
              'Edit Current Material'
              'Create New Material'
              'Select Project Material ')
          end
        end
        object GBPower: TGroupBox
          Left = 231
          Top = 21
          Width = 65
          Height = 49
          Caption = 'Power'
          Color = clMoneyGreen
          ParentBackground = False
          ParentColor = False
          TabOrder = 1
          object ButtonTransient: TButton
            Left = 3
            Top = 13
            Width = 54
            Height = 25
            Caption = 'Edit'
            TabOrder = 0
            OnClick = ButtonTransientClick
          end
        end
      end
    end
  end
  object dlgColorcube: TColorDialog
    Left = 224
    Top = 528
  end
end
