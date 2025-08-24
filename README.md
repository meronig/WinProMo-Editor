# WinProMo-Editor

WinProMo-Editor is a plugin-based visual editor that makes use of the WinProMo library.

# Compiling

Before compiling this project, make sure that: 

* You cloned this repository, the one of the WinProMo library (https://github.com/meronig/WinProMo) and, optionally the ones containing any other plugin module.

* The folders containing the repositories are siblings.

* The folder containing the WinProMo library is named ``WinProMo'' (without quotation marks).

* You already compiled the WinProMo library and, optionally, any other plugin module.

To compile WinProMo-Editor, you will need Microsoft Visual C++, the Microsoft Foundation Classes library, and Microsoft Windows SDK. The freely available Community version of Visual Studio 2022 can satisfy these dependencies.

A Microsoft Visual C++ 2022 project file (WinProMo-App.vcxproj) is included in this repository. For older versions of Microsoft Visual C++, you will have to create your own project file. WinProMo-Editor can be compiled with Microsoft Visual C++ 4.0 onwards (really!). Depending on the version of Microsoft Visual C++ being used, the resulting DLL can run under Microsoft Windows 95/NT 3.51 up to Windows 11, on any supported target architecture. However, WinProMo-Editor has been extensively tested only under Microsoft Windows 10/11 x64.

Note that, if no plugin has been compiled, or the resulting DLL is not present in the folder containing the WinProMo-Editor executable, WinProMo-Editor will run, but you will not be able to select any diagram model when creating a new document. Also note that WinProMo, WinProMo-Editor, and all plugins must be compiled with the same version of Microsoft Visual C++ for the same target architecture. Otherwise, WinProMo-Editor may crash or malfunction.

# Acknowledgements

Copyright © 2025 Technical University of Denmark

This computer program makes use of the CDiagramEditor public domain souce code by Johan Rosengren, Abstrakt Mekanik AB: http://www.abstraktmekanik.se/freebies.html

Microsoft Visual Studio, Microsoft Visual C++, Microsoft Foundation Classes (MFC) and Microsoft Windows are trademarks of the Microsoft group of companies.