﻿#pragma checksum "..\..\..\CustomMarkers\MultiWaypoint.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "EEBEF8D3E71DA153498EA1E590E6C398"
//------------------------------------------------------------------------------
// <auto-generated>
//     此代码由工具生成。
//     运行时版本:4.0.30319.18444
//
//     对此文件的更改可能会导致不正确的行为，并且如果
//     重新生成代码，这些更改将会丢失。
// </auto-generated>
//------------------------------------------------------------------------------

using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms.Integration;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;


namespace XMonitor_GUI.CustomMarkers {
    
    
    /// <summary>
    /// MultiWaypoint
    /// </summary>
    public partial class MultiWaypoint : System.Windows.Controls.UserControl, System.Windows.Markup.IComponentConnector {
        
        
        #line 14 "..\..\..\CustomMarkers\MultiWaypoint.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Image icon;
        
        #line default
        #line hidden
        
        
        #line 15 "..\..\..\CustomMarkers\MultiWaypoint.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas canv;
        
        #line default
        #line hidden
        
        
        #line 16 "..\..\..\CustomMarkers\MultiWaypoint.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label Number;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/X-Monitor;component/custommarkers/multiwaypoint.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\..\CustomMarkers\MultiWaypoint.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            
            #line 8 "..\..\..\CustomMarkers\MultiWaypoint.xaml"
            ((XMonitor_GUI.CustomMarkers.MultiWaypoint)(target)).Unloaded += new System.Windows.RoutedEventHandler(this.UAVWayPoint_Unloaded);
            
            #line default
            #line hidden
            
            #line 9 "..\..\..\CustomMarkers\MultiWaypoint.xaml"
            ((XMonitor_GUI.CustomMarkers.MultiWaypoint)(target)).MouseEnter += new System.Windows.Input.MouseEventHandler(this.MarkerControl_MouseEnter);
            
            #line default
            #line hidden
            
            #line 9 "..\..\..\CustomMarkers\MultiWaypoint.xaml"
            ((XMonitor_GUI.CustomMarkers.MultiWaypoint)(target)).MouseLeave += new System.Windows.Input.MouseEventHandler(this.MarkerControl_MouseLeave);
            
            #line default
            #line hidden
            
            #line 10 "..\..\..\CustomMarkers\MultiWaypoint.xaml"
            ((XMonitor_GUI.CustomMarkers.MultiWaypoint)(target)).TouchEnter += new System.EventHandler<System.Windows.Input.TouchEventArgs>(this.MarkerControl_TouchEnter);
            
            #line default
            #line hidden
            
            #line 10 "..\..\..\CustomMarkers\MultiWaypoint.xaml"
            ((XMonitor_GUI.CustomMarkers.MultiWaypoint)(target)).TouchLeave += new System.EventHandler<System.Windows.Input.TouchEventArgs>(this.MarkerControl_TouchLeave);
            
            #line default
            #line hidden
            return;
            case 2:
            this.icon = ((System.Windows.Controls.Image)(target));
            return;
            case 3:
            this.canv = ((System.Windows.Controls.Canvas)(target));
            return;
            case 4:
            this.Number = ((System.Windows.Controls.Label)(target));
            return;
            }
            this._contentLoaded = true;
        }
    }
}
