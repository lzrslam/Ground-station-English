   M S B A M L   `   `   `  ���� [  WHelixToolkit.Wpf, Version=2014.2.11.1, Culture=neutral, PublicKeyToken=52aa3500039caf0dM8clr-namespace:HelixToolkit.Wpf;assembly=HelixToolkit.WpfHelixToolkit.Wpf   	X-Monitor!   XMonitor_GUI.PilotLogWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     ;metro)http://schemas.codeplex.com/elysium/theme     Jhelix8clr-namespace:HelixToolkit.Wpf;assembly=HelixToolkit.Wpf       � Title$  AboutWindow��$	��500��$	��650��   WindowBackgroundBrush#���    � WindowStyle$
 None=� � WindowStartupLocation$ CenterScreen=� � Icon$/ )/X-Monitor;component/Resources/minisv.ico�� � 	Resources  �� Source�� $ ../MainWindowStyles.xaml?�%    '  !System.Windows.Shell.WindowChrome   WindowChrome      CaptionHeight# ZJ�%  System.Windows.SystemParameters"   WindowResizeBorderThickness	   ResizeBorderThickness#	 Z .��� 
 � ColumnDefinitions
 �� $��5 ��� $��* ��� $��* ��� $��5 � � RowDefinitions �� $��5 ��� $��50 ��� $��* ��� $��50 ��� $��5 �.+��� $��1��$��1��$��飞行员日志��$
��Left=�$	��Top=�
�������$��32(�$��	Meiryo UI)�$
��Bold"��� $��2��$��1�� �� Orientation$ 
Horizontal=�$��Right=�$	��Top=�$��50��$��37��.+��� -   $��Close��$��r��  CaptionButtonStyleKey#���  $��32(�
��������� $��2��$��1��$��2��
�������.@��� $��日志�� �� 
IsSelected . 
�������
�������.��� 
 �� $��* � �� $	��100 ��� $	��100 ��� $��* �.+��� $��0��$��0��$��	ユーザ��$��2��$��	0,0,0.4,0q�.��� 
 �� $��70 ��� $��* � �� $��40 ��� $��40 ��� $��* �.+��� $��0��$��0��$��	操作者��$��Right=�$��Center=�$��18(��� -   $��	PilotName��$��1��$��0��$��1q�$��18(��� $��0��$��1��$��	监视者��$��Right=�$��Center=�$��18(��� -   $��MonitorName��$��1��$��1��$��1q�$��18(��� $��0��$��1��$��环境��$��2��$��	0,0,0.4,0q�.��� 
 �� $��70 ��� $	��200 ��� $��70 ��� $	��200 ��� $��* � �� $��40 ��� $��40 ��� $��* �.+��� $��0��$��0��$��场所��$��Right=�$��Center=�$��18(��� -   $��Place��$��1��$��0��$��4��$��1q�$��18(��� $��0��$��1��$��天气��$��Right=�$��Center=�$��18(��� -   $��Weather��$��1��$��1��$��1q�$��18(��� $��2��$��1��$��风速��$��Right=�$��Center=�$��18(��� -   $
��Wind��$��3��$��1��$��1q�$��18(��� $��4��$��1��$��[km/s]��$��Right=�$��Center=�$��18(��� $��0��$��2��$��内容��$��2��$��	0,0,0.4,0q�.��� 
 �� $��80 ��� $��* � �� $��40 ��� $��* �.+��� $��0��$��0��$��日期��$��Right=�$��Center=�$��18(�(  "System.Windows.Controls.DatePicker  -   $��DatePicker1��$��1��$��0��$��1q�$��18(�&   System.Windows.Controls.Calendar  -   $��	calender1��$y�Hidden=��� $��0��$��1��$��2��$��1q� �� AcceptsReturn .  �� TextWrapping$
 Wrap=�" �� VerticalScrollBarVisibility$
 Auto=��� $��飞行前确认事项��
�������
�������.��� 
 �� $��* � �� $��* ��� $��* �.+��� $��0��$��0��$��必须事项��$��2��.��� 
 �� $��* � �� $��* �.+��� -	   $��	MustCheck�� �� SelectionMode$ Multiple=� �� View �� .P���   	FirstCell �� CellTemplate# [  �� Width$ 30���� $��No��$ 30�� �� DisplayMemberBinding ��  �� Path$ No��� $��项目��$	 600�� �� $
 Name��� $��0��$��1��$��任意事项��$��2��.��� 
 �� $��* � �� $��* �.+��� -
   $��	DiscCheck��$ Multiple=� �� .P��� # [ $ 30���� $��No��$ 30�� �� $ No��� $��项目��$	 600�� �� $
 Name��� $��2��$��3��$ 
Horizontal=�$��Center=�$��Right=�.+��� -   $��OK��$��OK��$��18(�$	��100��
�������
�������
���   �$��	Meiryo UI)�$��5q�