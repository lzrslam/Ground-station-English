﻿#pragma checksum "..\..\..\CustomMarkers\Waypoint.xaml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "ADE93AB7DD8EFE2D7F4B4EFE02901979A9E05D8F"
//------------------------------------------------------------------------------
// <auto-generated>
//     此代码由工具生成。
//     运行时版本:4.0.30319.42000
//
//     对此文件的更改可能会导致不正确的行为，并且如果
//     重新生成代码，这些更改将会丢失。
// </auto-generated>
//------------------------------------------------------------------------------

using Microsoft.Windows.Controls;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Controls.Ribbon;
using System.Windows.Data;
using System.Windows.Documents;
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


namespace Y_Planner.CustomMarkers {
    
    
    /// <summary>
    /// Waypoint
    /// </summary>
    public partial class Waypoint : System.Windows.Controls.UserControl, System.Windows.Markup.IComponentConnector {
        
        
        #line 8 "..\..\..\CustomMarkers\Waypoint.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal Y_Planner.CustomMarkers.Waypoint Main;
        
        #line default
        #line hidden
        
        
        #line 17 "..\..\..\CustomMarkers\Waypoint.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Grid FlickArea;
        
        #line default
        #line hidden
        
        
        #line 82 "..\..\..\CustomMarkers\Waypoint.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas myCanvas;
        
        #line default
        #line hidden
        
        
        #line 86 "..\..\..\CustomMarkers\Waypoint.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Image icon;
        
        #line default
        #line hidden
        
        
        #line 88 "..\..\..\CustomMarkers\Waypoint.xaml"
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
            System.Uri resourceLocater = new System.Uri("/Y-Planner;component/custommarkers/waypoint.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\..\CustomMarkers\Waypoint.xaml"
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
            this.Main = ((Y_Planner.CustomMarkers.Waypoint)(target));
            
            #line 9 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.Unloaded += new System.Windows.RoutedEventHandler(this.UAVWayPoint_Unloaded);
            
            #line default
            #line hidden
            
            #line 9 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.Loaded += new System.Windows.RoutedEventHandler(this.UAVWayPoint_Loaded);
            
            #line default
            #line hidden
            
            #line 10 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.MouseEnter += new System.Windows.Input.MouseEventHandler(this.MarkerControl_MouseEnter);
            
            #line default
            #line hidden
            
            #line 10 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.MouseLeave += new System.Windows.Input.MouseEventHandler(this.MarkerControl_MouseLeave);
            
            #line default
            #line hidden
            
            #line 11 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.MouseMove += new System.Windows.Input.MouseEventHandler(this.UAVWayPoint_MouseMove);
            
            #line default
            #line hidden
            
            #line 11 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.MouseLeftButtonUp += new System.Windows.Input.MouseButtonEventHandler(this.UAVWayPoint_MouseLeftButtonUp);
            
            #line default
            #line hidden
            
            #line 11 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.MouseLeftButtonDown += new System.Windows.Input.MouseButtonEventHandler(this.UAVWayPoint_MouseLeftButtonDown);
            
            #line default
            #line hidden
            
            #line 12 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.TouchEnter += new System.EventHandler<System.Windows.Input.TouchEventArgs>(this.MarkerControl_TouchEnter);
            
            #line default
            #line hidden
            
            #line 12 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.TouchLeave += new System.EventHandler<System.Windows.Input.TouchEventArgs>(this.MarkerControl_TouchLeave);
            
            #line default
            #line hidden
            
            #line 13 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.TouchDown += new System.EventHandler<System.Windows.Input.TouchEventArgs>(this.MarkerControl_TouchDown);
            
            #line default
            #line hidden
            
            #line 13 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.TouchUp += new System.EventHandler<System.Windows.Input.TouchEventArgs>(this.MarkerControl_TouchUp);
            
            #line default
            #line hidden
            
            #line 13 "..\..\..\CustomMarkers\Waypoint.xaml"
            this.Main.TouchMove += new System.EventHandler<System.Windows.Input.TouchEventArgs>(this.MarkerControl_TouchMove);
            
            #line default
            #line hidden
            return;
            case 2:
            this.FlickArea = ((System.Windows.Controls.Grid)(target));
            return;
            case 3:
            this.myCanvas = ((System.Windows.Controls.Canvas)(target));
            return;
            case 4:
            this.icon = ((System.Windows.Controls.Image)(target));
            return;
            case 5:
            this.Number = ((System.Windows.Controls.Label)(target));
            return;
            }
            this._contentLoaded = true;
        }
    }
}

