   M S B A M L   `   `   `  ���� D  @X-Monitor, Version=1.2.1.4, Culture=neutral, PublicKeyToken=null9!clr-namespace:XMonitor_GUI.WindowXMonitor_GUI.Window  [ WSystem.Windows.Forms, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089Y@clr-namespace:System.Windows.Forms;assembly=System.Windows.FormsSystem.Windows.Forms G CControlsUnit, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullA0clr-namespace:ControlsUnit;assembly=ControlsUnitControlsUnit     XMonitor_GUI.DataWindow   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     4window!clr-namespace:XMonitor_GUI.Window     Y UDynamicDataDisplay, Version=0.3.0.0, Culture=neutral, PublicKeyToken=5b7d744a7263923f=d34http://research.microsoft.com/DynamicDataDisplay/1.0  Lforms@clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms  CControlsUnit0clr-namespace:ControlsUnit;assembly=ControlsUnit  -   $��Window��  � Title$  
DataWindow��$	��600��$	��700��$	��600��$	��700�� � Icon$0 */X-Monitor;component/Resources/minisv3.ico��   WindowBackgroundBrush#���    � WindowStyle$
 None=� � WindowStartupLocation$ CenterScreen=� � 	Resources  �� Source�� $ ../MainWindowStyles.xaml?�%    '  !System.Windows.Shell.WindowChrome   WindowChrome      CaptionHeight$ 50Q�   ResizeBorderThickness$ 5q�.��� 	 � ColumnDefinitions	 �� $��5 ��� $��* ��� $��5 �
 � RowDefinitions
 �� $��5 ��� $��50 ��� $��* ��� $��50 ��� $��50 ��� $��5 �.+��� $��1��$��1��$��UAV详细信息��$
��Left=�$	��Top=�
�������$��32(�$��	Meiryo UI)�$
��Bold"��� $��1��$��1�� �� Orientation$ 
Horizontal=�$��Right=�$	��Top=�$��50��$��37��.+��� -   $��r��  CaptionButtonStyleKey#���  $��32(�
��������� $��2��$��1��
�������
�������.@��� -    ��Name$ TabItem0��$��Health Data��
�������.���� $ Vertical=�.+��� $��	Processor��.���� $ Vertical=�.+��� $ 
Horizontal=�.+��� $��5,0,5,0q�$"��Lower Level MCU Proc. Time :��$��10(�$	��160��� $	��150��$��20��.+�� -   $��LowLvMcuProcTimeBar�� � Minimum$ 0Q� � Maximum$	 100Q� � Value$ 50Q�(� .���� -   $��LowLvMcuProcTimeText��$��0%�� �� TextAlignment$ Center=��� $��5,0,5,0q�$#��Higher Level MCU Proc. Time :��$��10(�$	��160��� $	��150��$��20��.+�� -   $��HighLvMcuProcTimeBar��$ 0Q�$	 100Q�$ 50Q�(� .���� -   $��HighLvMcuProcTimeText��$��0%��$ Center=��� $��LowerLevelMCU��.���� $ Vertical=�.+��� $ 
Horizontal=�.+��� $��5,0,5,0q�$!��RC Receiver Communication :��$��10(�$	��160��� $	��150��$��20��.+�� -   $&�� LLMCU_RcReceiverCommunicationBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -	   $'��!LLMCU_RcReceiverCommunicationText��$
��0/15��$ Center=��� $��5,0,5,0q�$��RC Receiver Reception :��$��10(�$	��160��� $	��150��$��20��.+�� -
   $"��LLMCU_RcReceiverReceptionBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -   $#��LLMCU_RcReceiverReceptionText��$
��0/15��$ Center=��� $ 
Horizontal=�.+��� $��5,0,5,0q�$!��Gyro Sensor Communication :��$��10(�$	��160��� $	��150��$��20��.+�� -   $&�� LLMCU_GyroSensorCommunicationBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -   $'��!LLMCU_GyroSensorCommunicationText��$
��0/15��$ Center=��� $��5,0,5,0q�$��Gyro Sensor Measurement :��$��10(�$	��160��� $	��150��$��20��.+�� -   $$��LLMCU_GyroSensorMeasurementBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -   $%��LLMCU_GyroSensorMeasurementText��$
��0/15��$ Center=��� $2��,LowerLevelMCU - HigherLevelMCU Communication��.���� $ Vertical=�.+��� $ 
Horizontal=�.+��� $��5,0,5,0q�$��Low ---> High :��$��10(�$	��160��� $	��150��$��20��.+�� -   $��McuComm_LowToHighBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -   $��McuComm_LowToHighText��$
��0/15��$ Center=��� $��5,0,5,0q�$��Low <--- High :��$��10(�$	��160��� $	��150��$��20��.+�� -   $��McuComm_HighToLowBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -   $��McuComm_HighToLowText��$
��0/15��$ Center=��� $��HigherLevelMCU��.���� $ Vertical=�.+��� $ 
Horizontal=�.+��� $��5,0,5,0q�$��IMU Communication :��$��10(�$	��160��� $	��150��$��20��.+�� -   $��HLMCU_IMUCommunicationBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -   $ ��HLMCU_IMUCommunicationText��$
��0/15��$ Center=��� $��5,0,5,0q�$��IMU Gyro Measurement :��$��10(�$	��160��� $	��150��$��20��.+�� -   $!��HLMCU_IMUGyroMeasurementBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -   $"��HLMCU_IMUGyroMeasurementText��$
��0/15��$ Center=��� $ 
Horizontal=�.+��� $��	325,0,5,0q�$��IMU Acc Measurement :��$��10(�$	��160��� $	��150��$��20��.+�� -   $ ��HLMCU_IMUAccMeasurementBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -   $!��HLMCU_IMUAccMeasurementText��$
��0/15��$ Center=��� $ 
Horizontal=�.+��� $��	325,0,5,0q�$��IMU Mag Measurement :��$��10(�$	��160��� $	��150��$��20��.+�� -   $ ��HLMCU_IMUMagMeasurementBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -   $!��HLMCU_IMUMagMeasurementText��$
��0/15��$ Center=��� $ 
Horizontal=�.+��� $��5,0,5,0q�$"��Pres. Sensor Communication :��$��10(�$	��160��� $	��150��$��20��.+�� -   $&�� HLMCU_PresSensorCommunicationBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -   $'��!HLMCU_PresSensorCommunicationText��$
��0/15��$ Center=��� $��5,0,5,0q�$ ��Pres. Sensor Measurement :��$��10(�$	��160��� $	��150��$��20��.+�� -   $$��HLMCU_PresSensorMeasurementBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -   $%��HLMCU_PresSensorMeasurementText��$
��0/15��$ Center=��� $ 
Horizontal=�.+��� $��5,0,5,0q�$"��GPS Receiver Communication :��$��10(�$	��160��� $	��150��$��20��.+�� -    $'��!HLMCU_GpsReceiverCommunicationBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -!   $(��"HLMCU_GpsReceiverCommunicationText��$
��0/15��$ Center=��� $��5,0,5,0q�$��GPS Measurement :��$��10(�$	��160��� $	��150��$��20��.+�� -"   $��HLMCU_GpsMeasurementBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -#   $��HLMCU_GpsMeasurementText��$
��0/15��$ Center=��� $0��*UAV - Ground Control Station Communication��.���� $ Vertical=�.+��� $ 
Horizontal=�.+��� $��5,0,5,0q�$��UAV ---> GCS :��$��10(�$	��160��� $	��150��$��20��.+�� -$   $��MainLink_UavToGcsBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -%   $��MainLink_UavToGcsText��$
��0/15��$ Center=��� $��5,0,5,0q�$��UAV <--- GCS :��$��10(�$	��160��� $	��150��$��20��.+�� -&   $��MainLink_GcsToUavBar��$ 0Q�$ 15Q�$ 5Q�(� .���� -'   $��MainLink_GcsToUavText��$
��0/15��$ Center=��� -(   $ TabItem2��$��UAV Data��
�������.��&   System.Windows.Controls.DataGrid  -)     Name$ UAVListView��$��1��   
IsReadOnly . $��16(�   Columns 0  *System.Windows.Controls.DataGridTextColumn  ,  &System.Windows.Controls.DataGridColumn   Header$  ��1  +System.Windows.Controls.DataGridBoundColumn   Binding �� *Name+  $ 纬度�� �� *Lat+  $ 经度�� �� *Lon+  $ 高度�� �� *Alt+  $ 方位�� �� *Yaw+�� -*   $ TabItem1��$��	Data Lsit��
�������.���� -+   $��TagList��$��2��$��2��$��3q� �� SelectionMode$ Multiple=� �� View �� .P��� $	��XML�� �� DisplayMemberBinding ��  �� Path$ XMLTag��� $��Value�� �� $ Value��� $��Content�� �� $ Contents��� -,   $��FlightLogFilePath��$��3��$��1��$��0,5,0,5q�$�� ��$��Center=�$ �� HorizontalScrollBarVisibility$
 Auto=��� $��1��$��4��$ 
Horizontal=�$��Center=�$��Right=�.+��� --   $��关闭��$��18(�$	��100��
�������
�������
���   �$��	Meiryo UI)�$��10,5,5,5q�