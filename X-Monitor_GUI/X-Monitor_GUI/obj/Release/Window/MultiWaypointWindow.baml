   M S B A M L   `   `   `  ���� D  @X-Monitor, Version=1.2.1.4, Culture=neutral, PublicKeyToken=null9!clr-namespace:XMonitor_GUI.WindowXMonitor_GUI.Window  [ WSystem.Windows.Forms, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089Y@clr-namespace:System.Windows.Forms;assembly=System.Windows.FormsSystem.Windows.Forms G CControlsUnit, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullA0clr-namespace:ControlsUnit;assembly=ControlsUnitControlsUnit &     XMonitor_GUI.MultiWaypointWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     4window!clr-namespace:XMonitor_GUI.Window     Y UDynamicDataDisplay, Version=0.3.0.0, Culture=neutral, PublicKeyToken=5b7d744a7263923f=d34http://research.microsoft.com/DynamicDataDisplay/1.0  Lforms@clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms  CControlsUnit0clr-namespace:ControlsUnit;assembly=ControlsUnit  -   $��Window��  � Title$  MultiWaypointWindow��$	��600��$	��700��$	��600��$	��700�� � Icon$0 */X-Monitor;component/Resources/minisv3.ico��   WindowBackgroundBrush#���    � WindowStyle$
 None=� � WindowStartupLocation$ CenterScreen=� � 	Resources  �� Source�� $ ../MainWindowStyles.xaml?�%    '  !System.Windows.Shell.WindowChrome   WindowChrome      CaptionHeight$ 50Q�   ResizeBorderThickness$ 5q�.��� 	 � ColumnDefinitions	 �� $��5 ��� $��* ��� $��5 �
 � RowDefinitions
 �� $��5 ��� $��50 ��� $��* ��� $��50 ��� $��50 ��� $��5 �.+��� $��1��$��1��$��飞行计划��$
��Left=�$	��Top=�
�������$��32(�$��	Meiryo UI)�$
��Bold"��� $��1��$��1�� �� Orientation$ 
Horizontal=�$��Right=�$	��Top=�$��50��$��37��.+��� -   $��r��  CaptionButtonStyleKey#���  $��32(�
��������� -    ��Name$ WaypointListView��$��2��$��1������  �� View �� .P��� $�� �� �� DisplayMemberBinding �� *Sub+�� $��ID�� �� *ID+�� $
��Name�� �� *Name+�� $��x�� �� *x+�� $��y�� �� *y+�� $��Height�� �� *Height+�� $��Heading�� �� *	Heading+�� $
��Wait�� �� *Wait+�� $��Function�� �� *
Function+�� $��Speed�� �� *Speed+�� -   $��FlightPlanFilePath��$��3��$��1��$��0,5,0,5q�$�� ��$��Center=�$ �� HorizontalScrollBarVisibility$
 Auto=��� $��1��$��4��$ 
Horizontal=�$��Center=�$��Right=�.+��� -   $��关闭��$��18(�$	��100��
�������
�������
���   �$��	Meiryo UI)�$��10,5,5,5q�