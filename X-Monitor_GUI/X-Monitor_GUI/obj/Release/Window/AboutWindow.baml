   M S B A M L   `   `   `  ����   	X-Monitor    XMonitor_GUI.AboutWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     ;metro)http://schemas.codeplex.com/elysium/theme       � Title$  AboutWindow��$	��500��$	��650��   WindowBackgroundBrush#���    � WindowStyle$
 None=� � WindowStartupLocation$ CenterScreen=� � Icon$0 */X-Monitor;component/Resources/minisv3.ico�� � 	Resources  �� Source�� $ ../MainWindowStyles.xaml?�%    '  !System.Windows.Shell.WindowChrome   WindowChrome      CaptionHeight$ 50Q�   ResizeBorderThickness$ 5q�.��� 	 � RowDefinitions	 �� $��30 ��� $	��120 ��� $��* ��� $��50 ��� $��50 ��� $��5 �
 � ColumnDefinitions
 �� $��5 ��� $	��100 ��� $��* ��� $	��200 ��� $��5 �.+��� $��3��$��0�� �� Orientation$ 
Horizontal=�$��Right=�$	��Top=�$��30��$��30��.+��� -   $��r��  CaptionButtonStyleKey#���  $��20(�
�������$��30���� $��3��$��1��.+��� $��5,0,5,0q�$	��Top=�$9��3/X-Monitor;component/Resources/minisurveyorlogo.png���� -   $��http://www.aydrone.com/��$
��Left=�$��Bottom=�$	��200�����	#FFEFAC27$��	Meiryo UI)�$��12(�$
��Bold"�$��24��$��Center=��� -   $0��*南京傲翼飞控智能科技有限公司��$
��Left=�$	��Top=�$	��200�����	#FFEFAC27$��	Meiryo UI)�$��12(�$
��Bold"�$��24��$��Center=��� $��3��$��2��.+��� -   $��XMonitorVer��$��0,20,0,0q�$��1. X-Monitor Ver �����	#FFEFAC27$��	Meiryo UI)�$��12(�$
��Bold"��� -   $��	APFCVer_L��$��0q�$��2. APFC(L) Ver �����	#FFEFAC27$��	Meiryo UI)�$��12(�$
��Bold"��� -   $��	APFCVer_H��$��0q�$��3. APFC(H) Ver �����	#FFEFAC27$��	Meiryo UI)�$��12(�$
��Bold"��� $��1��$��About��$
��Left=�$	��Top=�
�������$��18(�$��82��$
��Bold"��� -    ��Name$ 	AboutText��$��1��$��1��$��2��$��4��$	��***�� �� AcceptsReturn .  �� TextWrapping$
 Wrap=�" �� VerticalScrollBarVisibility$
 Auto=��� -   $��确定��$
��Left=�$	��Top=�$	��142��$��3��$��	29,10,0,0q�$��3��$��35��
�������
�������$��18(���Z� �� -	   $��关闭��$
��Left=�$	��Top=�$	��142��$��3��$��	29,10,0,0q�$��4��$��35��
�������
�������$��18(���Z� 