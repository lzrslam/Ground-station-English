   M S B A M L   `   `   `  ����   	X-Monitor"    XMonitor_GUI.HomePointWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     X TXceed.Wpf.Toolkit, Version=2.2.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f44xctk)http://schemas.xceed.com/wpf/xaml/toolkit  -   $
��Main��$	��480��$	��210�����	#FF5A4D66  �� IsPressAndHoldEnabled  .  .��(� .���� -   $��Window�� �� Orientation$ Vertical=����	#FF5A4D66$��Center=�$��Center=�.+��� $��Center=�.+��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� $	��170��$
��Home�����	#FF505050$��Center=�$
��Left=��� $��Center=�$	��GPS��$��Right=�$��Center=��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -   $��PostionLatCheck��$��70��$��经度��
�������$��30��$	��Top=�$��Right=�$  Xceed.Wpf.Toolkit.DoubleUpDown  -   $��
PostionLat��$	��100���  �Xceed.Wpf.Toolkit.Primitives.UpDownBase`1[[System.Nullable`1[[System.Double, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   Maximum$ 90X�   Minimum$	 -90X��  �Xceed.Wpf.Toolkit.NumericUpDown`1[[System.Nullable`1[[System.Double, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   	Increment$ 0.000001X�   Value$ 0X��� $��[deg]�����	#FFF9EEEE�� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� $��70��$��X��
�������$��30��$	��Top=�$��Right=�  -   $��PostionLatDis��$	��100��$ 1X�$ 0X��� $	��[m]�����	#FFF1E5E5�� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -   $��PostionLngCheck��$��70��$��纬度��
�������$��Right=�  -   $��
PostionLng��$	��100��$	 180X�$
 -180X�$ 0.000001X�$ 0X��� $��[deg]�����	#FFF5ECEC�� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� $��70��$��Y��
�������$��Right=�  -   $��PostionLngDis��$	��100��$ 1X�$ 0X��� $	��[m]�����	#FFF7ECEC�� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -	   $��PostionAltCheck��$��70��$��高度��
�������$��Right=�  -
   $��
PostionAlt��$	��100��$ 1X�$ 0X��� $	��[m]�����	#FFFBF3F3�� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -   $��PostionAziCheck��$��70��$��方位��
�������$��Center=�$��Right=�  -   $��
PostionAzi��$	 180X�$
 -180X�$	��100��$ 1X�$ 0X��� $��[deg]��$��Center=����	#FFFBF1F1�� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -   $��PostionSpeedCheck��$��70��$��速度��
�������$��Center=�$��Right=�  -   $��PostionSpeed��$ 10X�$	 0.1X�$	��100��$	 0.5X�$ 2X��� $��[m/s]��$��Center=����	#FFF9F1F1� $	��210��$	��200�� � ColumnDefinitions �� $��* ��� $��* ��� $��* � � RowDefinitions �� $��* ��� $��* ��� $��* �.+��� -   $��AziDownBorder��$��5,5,5,5q�$��0��$��0��$��2q���Z� �� -   $��LatUpBorder��$��5,5,5,5q�$��1��$��0��$��2q���Z� �� -   $��AziUpBorder��$��5,5,5,5q�$��2��$��0��$��2q���Z� �� -   $��LngDownBorder��$��5,5,5,5q�$��0��$��1��$��2q���Z� �� -   $��MarkerSetBorder��$��5,5,5,5q�$��1��$��1��$��2q���Z� �� -   $��LngUpBorder��$��5,5,5,5q�$��2��$��1��$��2q���Z� �� -   $��AltDownBorder��$��5,5,5,5q�$��0��$��2��$��2q���Z� �� -   $��LatDownBorder��$��5,5,5,5q�$��1��$��3��$��2q���Z� �� -   $��AltUpBorder��$��5,5,5,5q�$��2��$��4��$��2q���Z� �� -   $��AltUp��$��+��$��5,5,5,5q�$��2��$��2��
�������$��	Meiryo UI)�$��40(�$
��Bold"�$��Center=�$��Center=�$��2q���Z� �� -   $��AltDown��$��-��$��5,5,5,5q�$��0��$��2��
�������$��	Meiryo UI)�$��40(�$
��Bold"�$��Center=�$��Center=�$��2q���Z� �� -   $��AziUp��$��15q�$��2��$��0��
�������$��2q�
������� J� OpacityMask �� 	 �� ImageSource$.	 (/X-Monitor;component/Resources/rghtR.png���� -   $��AziDown��$��15q�$��0��$��0��
�������$��2q�
������� �� $.	 (/X-Monitor;component/Resources/leftR.png���� -   $��LatUp��$��5q�$��1��$��0��
�������$��2q�
���������Z�  �� $+	 %/X-Monitor;component/Resources/up.png���� -   $��LatDown��$��5q�$��1��$��2��
�������$��2q�
����������	#FF150F0F �� $-	 '/X-Monitor;component/Resources/down.png���� -   $��LngUp��$��5q�$��2��$��1��
�������$��2q�
������� �� $.	 (/X-Monitor;component/Resources/right.png���� -   $��LngDown��$��5q�$��0��$��1��
�������$��2q�
������� �� $-	 '/X-Monitor;component/Resources/left.png���� -    $��	MarkerSet��$��5q�$��1��$��1��
�������$��2q�
������� �� $.	 (/X-Monitor;component/Resources/maker.png���� $��設定��$��30��$��	10,1,10,1q�