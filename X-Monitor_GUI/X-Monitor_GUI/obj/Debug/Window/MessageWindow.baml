   M S B A M L   `   `   `  ����  	X-Monitor     XMonitor_GUI.MessageWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   -   5          � Title$  MessageWindow��5   	   $	��420��6   $	��500��6,    � Icon$/ )/X-Monitor;component/Resources/minisv.ico��68      WindowBackgroundBrush#���   6i    � WindowStyle$
 None=�6�    � WindowStartupLocation$ CenterScreen=�6�    � 	Resources 5       �� Source�� 5      $ ../MainWindowStyles.xaml?�6   %    '  !System.Windows.Shell.WindowChrome   WindowChrome 5	        5
         CaptionHeight$ 50Q�6      ResizeBorderThickness$ 5q�6$   .��5      � 	 � ColumnDefinitions	 5      �� 5      $��5 �6   �� 5      $��* �6   �� 5      $��* �6   �� 5      $��5 �6   
 � RowDefinitions
 5      �� 5      $��5 �6   �� 5      $��50 �6   �� 5      $��* �6   �� 5      $��50 �6   �� 5      $��5 �6   .+�5      �� $��1��6
   $��1��6   $��メッセージ��6'   $
��Left=�67   $	��Top=�6R   
�������$��32(�6}   $��	Meiryo UI)�6�   $
��Bold"�6�   �� 5      $��2��6   $��1��6    �� Orientation$ 
Horizontal=�6,   $��Right=�5      $	��Top=�5      $��50��61   $��37��6=   .+�5       �� -   5        $��r��5         CaptionButtonStyleKey#���  6   $��32(�6H   
�������6j   5!      �� 5"      $��2��6   $��1��6   $��2��6,   $��5q�6@   .+�5#      �� $��更新��6   $
��Left=�6   $	��Top=�63   
�������$��24(�6^   $��	Meiryo UI)�6l   �� 5$      -   5        $��
UpdataText��5$      $	��100��6    �� AcceptsReturn .  �� TextWrapping$
 Wrap=�6A   " �� VerticalScrollBarVisibility$
 Auto=�6U   �� 5%      $��お知らせ��6   $
��Left=�6   $	��Top=�65   
�������$��24(�6`   $��	Meiryo UI)�6n   �� 5&      -   5        $��MessageText��5&      $	��100��6     . $
 Wrap=�6B   $
 Auto=�6V   5'      �� 5(      -   5        $��1��5(      $��3��6   $'��!次回更新まで表示しない��6*   
�������$��16(�6T   $
��Left=�6b   $��Center=�6}   6�   �� 5*      $��2��6   $��3��6   $ 
Horizontal=�6,   $��Center=�5+      $��Right=�65   .+�5,      �� -   5        $��OK��5,      $��18(�6   $	��100��6'   
�������
�������
���   �$��	Meiryo UI)�6n   $��5q�6�   6�   5-      5.      5/      