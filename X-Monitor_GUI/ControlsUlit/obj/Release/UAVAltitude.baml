   M S B A M L   `   `   `  ����   ControlsUnit    ControlsUnit.UAVAltitude   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     @d2http://schemas.microsoft.com/expression/blend/2008     -   $	��500��$��80��  � 	Resources   �� Source�� $ UAVAltitudeStyles.xaml?�%    .���� 
������� �� CornerRadius$ 0��$��1q�._��  � ColumnDefinitions �� $��* � � RowDefinitions �� $��0 ��� $��30 ��� $��* ��� $��30 ��� $��0 ��� $��0 �.+��� -   $
��Nalt��$��0��$��3��$��30��$��Bottom=�
�������
�������$��18(�$
��Bold"�$��	Meiryo UI)�$��Center=�$��Center=��� -   $
��Nuav��$��0��$��1��$��30��$	��Top=�
��� ���$��18(�$
��Bold"�$��	Meiryo UI)�$��Center=�$��Center=��� -   $��NNalt��$��0��$��4��$��30��$��Bottom=�
�������
�������$��18(�$
��Bold"�$��	Meiryo UI)�$��Center=�$��Center=��� -   $��NNuav��$��0��$��0��$��30��$	��Top=�
��� ���$��18(�$
��Bold"�$��	Meiryo UI)�$��Center=�$��Center=��� -   $��Offset��$��0��$��5��$��Offset��
���������Z� � $��0��$��2�� �� $��* � �� $��20 ��� $��25 ��� $��* ��� $��25 ��� $��20 �.+�� $��0��$��2�� � Orientation$ Vertical=���Z� ��Z� � -   $��altval��$��0��$��2��$ Vertical=�   RectangleProgressBar#��[  
��� � �$��	0,30,0,18q� � Maximum ��  �� ElementName$ Waypoint�� �� Path$ Maximum�	 � Minimum	 �� $ Waypoint��$ Minimum���Z� ��Z� �� -   $
��Home��
 �� TickPlacement$
 TopLeft=�$ 30Q�$		 -10Q�  AltHomeStyle#��[ 
�������$��2�� � SmallChange$ 1Q� �� TickFrequency$ 5Q��� -	   $��Waypoint��$y�Hidden=�$
 TopLeft=�$ 30Q�$		 -10Q�  AltTargetStyle#��[ 
�������$��2��$ 1Q�$ 5Q� � Value �� $ Dummy��$ Value��� -
   $��WaypointAct��$y�Hidden=�$
 TopLeft=�$ 30Q�$		 -10Q�  ActAltTargetStyle#��[ 
�������$��2��$ 1Q�$ 5Q��� -   $	��Uav��$
 TopLeft=�$ 30Q�$		 -10Q�  ActAltStyle#��[ 
�������$��2��$ 1Q�$ 5Q��� -   $��Dummy��$
 TopLeft=�$ 30Q�$		 -10Q�  DummySliderStyle#��[ 
�������$��2��$ 1Q�$ 5Q��� $��0��$��0��$��7��
�������$��2q��� -   $��WaypointUp10Border��$��0��$��0��
�������$��1q��� -   $��WaypointUpBorder��$��0��$��1��
�������$��1q��� -   $��WaypointDownBorder��$��0��$��3��
�������$��1q��� -   $��WaypointDown10Border��$��0��$��4��
�������$��1q��� -   $��WaypointUp10��$��WaypointUp10�� �� IsPressAndHoldEnabled .  $��0��$��0��$��2q�
���������Z�  J� OpacityMask ��  �� ImageSource$ Resources/up10.png���� -   $��
WaypointUp��$��
WaypointUp�� .  $��0��$��1��
�������
���������Z�  �� $ Resources/up.png���� -   $��WaypointDown��$��WaypointDown�� .  $��0��$��3��
�������
���������Z�  �� $ Resources/down.png���� -   $��WaypointDown10��$��WaypointDown10�� .  $��0��$��4��
�������
���������Z�  �� $ Resources/down10.png��