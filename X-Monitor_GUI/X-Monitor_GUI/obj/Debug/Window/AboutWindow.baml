   M S B A M L   `   `   `  ����  	X-Monitor    XMonitor_GUI.AboutWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   ;metro)http://schemas.codeplex.com/elysium/theme     5   	     � Title$  AboutWindow��5   	   $	��500��6   $	��650��6*      WindowBackgroundBrush#���   66    � WindowStyle$
 None=�6k    � WindowStartupLocation$ CenterScreen=�6~    � Icon$/ )/X-Monitor;component/Resources/minisv.ico��6�    � 	Resources 5       �� Source�� 5   
   $ ../MainWindowStyles.xaml?�6   %    '  !System.Windows.Shell.WindowChrome   WindowChrome 5
        5         CaptionHeight$ 50Q�6      ResizeBorderThickness$ 5q�6$   .��5      � 	 � RowDefinitions	 5   
   �� 5      $��30 �6   �� 5      $	��120 �6   �� 5      $��* �6   �� 5      $��50 �6   �� 5      $��50 �6   �� 5      $��5 �6   
 � ColumnDefinitions
 5   
   �� 5      $��5 �6   �� 5      $	��100 �6   �� 5      $��* �6   �� 5      $	��200 �6   �� 5      $��5 �6   .+�5   
   �� $��3��6   $��0��6%    �� Orientation$ 
Horizontal=�62   $��Right=�5      $	��Top=�5       $��30��65   $��30��6A   .+�5!      �� -   5        $��r��5!        CaptionButtonStyleKey#���  6!   $��20(�6Q   
�������$��30��6�   5"      �� 5#      $��3��6   $��1��6   .+�5$      �� $��5,0,5,0q�6   $	��Top=�6   $9��3/X-Monitor;component/Resources/minisurveyorlogo.png��64   �� 5%      -   5        $��http://mini-surveyor.com/��5%      $
��Left=�6/   $��Bottom=�6J   $	��200��6e   ���	#FFEFAC27$��	Meiryo UI)�6�   $��12(�6�   $
��Bold"�6�   $��24��6�   $��Center=�6�   6�   �� 5&      -   5        $��http://www.acsl.co.jp/��5&      $
��Left=�6,   $	��Top=�6G   $	��200��6_   ���	#FFEFAC27$��	Meiryo UI)�6�   $��12(�6�   $
��Bold"�6�   $��24��6�   $��Center=�6�   6�   5'      �� 5(      $��3��6   $��2��6   .+�5)      �� -   5        $��XMonitorVer��5)      $��0,20,0,0q�6   $��1. X-Monitor Ver ��60   ���	#FFEFAC27$��	Meiryo UI)�6c   $��12(�6z   $
��Bold"�6�   �� 5*      -   5        $��	APFCVer_L��5*      $��0q�6   $��2. APFC(L) Ver ��6'   ���	#FFEFAC27$��	Meiryo UI)�6X   $��12(�6o   $
��Bold"�6}   �� 5+      -   5        $��	APFCVer_H��5+      $��0q�6   $��3. APFC(H) Ver ��6'   ���	#FFEFAC27$��	Meiryo UI)�6X   $��12(�6o   $
��Bold"�6}   5,      �� 5-      $��1��6
   $��About��6   $
��Left=�6*   $	��Top=�6E   
�������$��18(�6p   $��82��6~   $
��Bold"�6�   �� 5.   
   -   5         ��Name$ 	AboutText��5.   T   $��1��6   $��1��6"   $��2��6/   $��4��6C   $	��***��6g    �� AcceptsReturn .  �� TextWrapping$
 Wrap=�6�   " �� VerticalScrollBarVisibility$
 Auto=�6�   �� 5/      -   5        $��更新確認��5/      $
��Left=�6   $	��Top=�65   $	��142��6M   $��3��6Y   $��	29,10,0,0q�6i   $��3��6|   $��35��6�   
�������
�������$��18(�6�   ��6�   Z� 6�   �� 50      -	   5        $��	閉じる��50      $
��Left=�6   $	��Top=�64   $	��142��6L   $��3��6X   $��	29,10,0,0q�6h   $��4��6{   $��35��6�   
�������
�������$��18(�6�   ��6�   Z� 6�   51      52      