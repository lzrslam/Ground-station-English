   M S B A M L   `   `   `  ����   	Y-Planner    Y_Planner.AboutWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089` \RibbonControlsLibrary, Version=3.5.41019.1, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35H 9http://schemas.microsoft.com/winfx/2006/xaml/presentation      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     ;metro)http://schemas.codeplex.com/elysium/theme       � Title$  AboutWindow��$	��500��$	��650��   WindowBackgroundBrush#���    � WindowStyle$
 None=� � WindowStartupLocation$ CenterScreen=� � Icon$9 3/Y-Planner;component/Resources/minisurveyorlogo.png�� � 	Resources  �� Source�� $ ../MainWindowStyles.xaml?�%    '  !System.Windows.Shell.WindowChrome   WindowChrome      CaptionHeight# ZJ�%  System.Windows.SystemParameters"   WindowResizeBorderThickness	   ResizeBorderThickness#	 Z .��� 
 � RowDefinitions
 �� $��30 ��� $	��120 ��� $��* ��� $��50 ��� $��5 � � ColumnDefinitions �� $��5 ��� $	��100 ��� $��* ��� $	��200 ��� $��5 �.+��� $��3��$��0�� �� Orientation$ 
Horizontal=�$��Right=�$	��Top=�$��30��$��30��.+��� -   $��r��  CaptionButtonStyleKey#���  $��20(�
���   �$��30���� $��1��$��About��$
��Left=�$	��Top=�$��18(�$��82��$
��Bold"��� $��3��$��1��.+��� $��3��$��1��$��5,0,5,0q�$	��Top=�$��60��$	��150������  �� Color$ Black�� �� Opacity$	 0.8Q� J� OpacityMask ��  �� ImageSource$9 3/Y-Planner;component/Resources/minisurveyorlogo.png���� -   $��http://aydreone.com/��$
��Left=�$��Bottom=�$	��200�����	#FFEFAC27$��	Meiryo UI)�$��12(�$
��Bold"�$��24��$��Center=��� -   $0��*南京傲翼飞控智能科技有限公司��$
��Left=�$	��Top=�$	��200�����	#FFEFAC27$��	Meiryo UI)�$��12(�$
��Bold"�$��24��$��Center=��� $��3��$��2��.+��� -   $��YPlannerVer��$��0,20,0,0q�$��1. Y-Planner Ver �����	#FFEFAC27$��	Meiryo UI)�$��12(�$
��Bold"��� -   $��APFCVer��$��0q�$��2. APFC Ver �����	#FFEFAC27$��	Meiryo UI)�$��12(�$
��Bold"��� -    ��Name$ 	AboutText��$��1��$��1��$��2��$��3��$	��***�� �� AcceptsReturn .  �� TextWrapping$
 Wrap=�" �� VerticalScrollBarVisibility$
 Auto=��� -   $��关闭��$
��Left=�$	��Top=�$	��142��$��3��$��	29,10,0,0q�$��3��$��35��$��18(���Z� 