   M S B A M L   `   `   `  ����   	X-Monitor!    XMonitor_GUI.WaypointWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     X TXceed.Wpf.Toolkit, Version=2.2.0.0, Culture=neutral, PublicKeyToken=3e4669d2f30244f44xctk)http://schemas.xceed.com/wpf/xaml/toolkit  -   $
��Main��$	��432��$	��220��  �� IsPressAndHoldEnabled  .  ���	#FF5A4D66.��(� .���� -   $��Window�� �� Orientation$ Vertical=�$��Center=�$��Center=�$	��464��.+��� $��Center=�.+��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�$	��239��.+��� $��70��$��Cycle��$��Center=�
�������$��Right=�$	��0,2q��� -   $��M_IfRenwuxunhuan_Action��
�������
���   �$��Light"�$��50���� $��70��$��Reback��$��Center=�
�������$��Right=�$	��0,2q��� -   $��M_Ifreback_Action��
�������
���   �$��Light"�$��49���� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� $��70��$��	Autoangle��$��Center=�
�������$��Right=�$	��0,2q��� -   $��M_JiaoduAuto_Make��
�������
���   �$��Light"�$��50���� .+��� 
�������$��0,5,0,5q�$��1���� $��1��$ 
Horizontal=�$
��Left=�$��0,0,0,0q� J� RenderTransformOrigin$ 0.5,0.5&�z�V� .~���  �� ScaleY$ -1Q��� �� T� .+��� $��70��$��X��
�������$��0��$	��Top=�$��Right=�$  Xceed.Wpf.Toolkit.DoubleUpDown  -   $��PostionLatDis��$	��100���  �Xceed.Wpf.Toolkit.NumericUpDown`1[[System.Nullable`1[[System.Double, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   	Increment$ 1X��  �Xceed.Wpf.Toolkit.Primitives.UpDownBase`1[[System.Nullable`1[[System.Double, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]]   Value$ 0X�$��0,0,0,30q�$ 0.5,0.5&�z�V� .~��� $ -1Q��� �� T� �� $	��[m]��
�������$��0,0,0,30q�$ 0.5,0.5&�z�V� .~��� $ -1Q��� �� T� �� $��0��$ 
Horizontal=�$
��Left=�$��0,0,0,0q�.+��� $��70��$��Y��
�������$��Right=�$��0,0,0,30q�$ 0.5,0.5&�z�V� .~��� $ -1Q��� �� T�   -   $��PostionLngDis��$	��100��$ 1X�$ 0X�$��0,0,0,30q�$ 0.5,0.5&�z�V� .~��� $ -1Q��� �� T� �� $	��[m]��
�������$��0,0,0,30q��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�$	��238��.+��� -   $��PostionAltCheck��$��70��$��Height��
�������$��Right=�  -	   $��
PostionAlt��$��50��$ 1X�$ 0X��� $	��[m]��$��0,0,44,0q�
��������� -
   $��M_IfGaoduzizhu_Action��
�������
���   �$��Light"�$��44���� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�$	��235��.+��� -   $��PostionAziCheck��$��70��$	��Yaw��
�������$��Center=�$��Right=�$	��0,2q�  -   $��
PostionAzi��   Maximum$	 360X�   Minimum$ 0X�$��50��$ 1X�$ 0X��� $��[deg]��$��Center=�$��0,2,34,2q�
�������$��39���� -   $��M_IfHangxiangzizhu_Action��
�������
���   �$��Light"�$��44���� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�$	��238��.+��� -   $��PostionLatCheck��$��70��$	��Lat��
�������$��30��$	��Top=�$��Right=�  -   $��
PostionLat��$	��100��$ 90X�$	 -90X�$ 0.000001X�$ 0X�$��30��$	��Top=��� $��[deg]��
��������� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�$	��238��.+��� -   $��PostionLngCheck��$��70��$	��Lng��
�������$��Right=�  -   $��
PostionLng��$	��100��$	 180X�$
 -180X�$ 0.000001X�$ 0X��� $��[deg]��
�������$��45���� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -   $��PostionSpeedCheck��$��70��$��	Hovertime��
�������$��Center=�$��Right=�  -   $��PostionSpeed��$	 255X�$ 0X�$	��100��$	 0.5X�$ 0X��� $	��[s]��$��Center=�
��������� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -   $��Hengxiangsudu_Set��$��70��$��	Hori__Vel��
�������$��Center=�$��Right=�  -   $��Hengxiangsudu��$	 100X�$ 0X�$	��100��$	 0.5X�$ 0X��� $��[m/s]��$��Center=�
��������� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -   $��Xiangshangsudu_Set��$��70��$��Up__Vel��
�������$��Center=�$��Right=�  -   $��Xiangshangsudu��$	 100X�$ 0X�$	��100��$	 0.5X�$ 0X��� $��[m/s]��$��Center=�
��������� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -   $��Xiangxiasudu_Set��$��70��$��	Down__Vel��
�������$��Center=�$��Right=�  -   $��Xiangxiasudu��$	 100X�$ 0X�$	��100��$	 0.5X�$ 0X��� $��[m/s]��$��Center=�
��������� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� $��70��$��	Takephoto��$��Center=�
�������$��Right=�$	��0,2q��� -   $��M_IfPaizhao_Action��
�������
���   �$��Light"�$	��100���� $��Center=�$��0��$ 0.5,0.5&�.+��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -   $��
M_Imu_Data��$��70��$
��IMU:��
�������$��30��$	��Top=�$
��Left=��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -   $��
M_Imu_Roll��$��70��$
��Roll��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q��� -   $��M_Imu_Pitch��$��70��$��Pitch��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q��� -   $��	M_Imu_Yaw��$��70��$	��Yaw��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -   $��M_Gyro_Data��$��70��$��
陀螺仪:��
�������$��30��$	��Top=�$
��Left=��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -    $��M_Gyro_RollRate��$��70��$��RollRate��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q��� -!   $��M_Gyro_PitchRate��$��70��$��	PitchRate��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q��� -"   $��M_Gyro_YawRate��$��70��$��YawRate��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -#   $��
M_Acc_Data��$��70��$��加速度计:��
�������$��30��$	��Top=�$
��Left=��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -$   $��M_Acc_X��$��70��$
��XAcc��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q��� -%   $��M_Acc_Y��$��70��$
��YAcc��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q��� -&   $��M_Acc_Z��$��70��$
��ZAcc��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -'   $��
M_Mag_Data��$��70��$��
地磁计:��
�������$��30��$	��Top=�$
��Left=��� $��30��$ 
Horizontal=�$
��Left=�$��0,0,0,5q�.+��� -(   $��M_Mag_X��$��70��$
��XMag��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q��� -)   $��M_Mag_Y��$��70��$
��YMag��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q��� -*   $��M_Mag_Z��$��70��$
��ZMag��
�������$��30��$	��Top=�$
��Left=�$��10,0,0,0q�� $	��210��$��6��� -+   $
��Mode��$	��210��$��1��