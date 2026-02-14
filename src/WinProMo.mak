# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=WinProMo - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to WinProMo - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "WinProMo - Win32 Release" && "$(CFG)" !=\
 "WinProMo - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "WinProMo.mak" CFG="WinProMo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WinProMo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "WinProMo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "WinProMo - Win32 Debug"
CPP=cl.exe
MTL=mktyplib.exe
RSC=rc.exe

!IF  "$(CFG)" == "WinProMo - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\Release\WinProMo.exe"

CLEAN : 
	-@erase "$(INTDIR)\CanvasSizeDialog.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DynamicElementListDlg.obj"
	-@erase "$(INTDIR)\DynamicPropertyDlg.obj"
	-@erase "$(INTDIR)\ExportDlg.obj"
	-@erase "$(INTDIR)\GridSizeDialog.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\OleSrvItem.obj"
	-@erase "$(INTDIR)\ProMoAppAuto.obj"
	-@erase "$(INTDIR)\ProMoDiagramAuto.obj"
	-@erase "$(INTDIR)\ProMoDiagramsAuto.obj"
	-@erase "$(INTDIR)\PropertyScrollFrame.obj"
	-@erase "$(INTDIR)\PropertyScrollView.obj"
	-@erase "$(INTDIR)\SelectDocumentTypeDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\WinProMo.obj"
	-@erase "$(INTDIR)\WinProMo.pch"
	-@erase "$(INTDIR)\WinProMo.res"
	-@erase "$(INTDIR)\WinProMoDoc.obj"
	-@erase "$(INTDIR)\WinProMoView.obj"
	-@erase "..\..\Release\WinProMo.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/WinProMo.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/WinProMo.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/WinProMo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 ../../WinPromo/src/Release/WinProMo.lib /nologo /subsystem:windows /machine:I386 /out:"../../Release/WinProMo.exe"
LINK32_FLAGS=../../WinPromo/src/Release/WinProMo.lib /nologo /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)/WinProMo.pdb" /machine:I386\
 /out:"../../Release/WinProMo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CanvasSizeDialog.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DynamicElementListDlg.obj" \
	"$(INTDIR)\DynamicPropertyDlg.obj" \
	"$(INTDIR)\ExportDlg.obj" \
	"$(INTDIR)\GridSizeDialog.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\OleSrvItem.obj" \
	"$(INTDIR)\ProMoAppAuto.obj" \
	"$(INTDIR)\ProMoDiagramAuto.obj" \
	"$(INTDIR)\ProMoDiagramsAuto.obj" \
	"$(INTDIR)\PropertyScrollFrame.obj" \
	"$(INTDIR)\PropertyScrollView.obj" \
	"$(INTDIR)\SelectDocumentTypeDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WinProMo.obj" \
	"$(INTDIR)\WinProMo.res" \
	"$(INTDIR)\WinProMoDoc.obj" \
	"$(INTDIR)\WinProMoView.obj"

"..\..\Release\WinProMo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WinProMo - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\..\Debug\WinProMo.exe"

CLEAN : 
	-@erase "$(INTDIR)\CanvasSizeDialog.obj"
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DynamicElementListDlg.obj"
	-@erase "$(INTDIR)\DynamicPropertyDlg.obj"
	-@erase "$(INTDIR)\ExportDlg.obj"
	-@erase "$(INTDIR)\GridSizeDialog.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\OleSrvItem.obj"
	-@erase "$(INTDIR)\ProMoAppAuto.obj"
	-@erase "$(INTDIR)\ProMoDiagramAuto.obj"
	-@erase "$(INTDIR)\ProMoDiagramsAuto.obj"
	-@erase "$(INTDIR)\PropertyScrollFrame.obj"
	-@erase "$(INTDIR)\PropertyScrollView.obj"
	-@erase "$(INTDIR)\SelectDocumentTypeDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\WinProMo.obj"
	-@erase "$(INTDIR)\WinProMo.pch"
	-@erase "$(INTDIR)\WinProMo.res"
	-@erase "$(INTDIR)\WinProMoDoc.obj"
	-@erase "$(INTDIR)\WinProMoView.obj"
	-@erase "$(OUTDIR)\WinProMo.pdb"
	-@erase "..\..\Debug\WinProMo.exe"
	-@erase "..\..\Debug\WinProMo.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GR /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/WinProMo.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/WinProMo.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/WinProMo.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 ../../WinPromo/src/Debug/WinProMo.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../../Debug/WinProMo.exe"
LINK32_FLAGS=../../WinPromo/src/Debug/WinProMo.lib /nologo /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)/WinProMo.pdb" /debug /machine:I386\
 /out:"../../Debug/WinProMo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CanvasSizeDialog.obj" \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DynamicElementListDlg.obj" \
	"$(INTDIR)\DynamicPropertyDlg.obj" \
	"$(INTDIR)\ExportDlg.obj" \
	"$(INTDIR)\GridSizeDialog.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\OleSrvItem.obj" \
	"$(INTDIR)\ProMoAppAuto.obj" \
	"$(INTDIR)\ProMoDiagramAuto.obj" \
	"$(INTDIR)\ProMoDiagramsAuto.obj" \
	"$(INTDIR)\PropertyScrollFrame.obj" \
	"$(INTDIR)\PropertyScrollView.obj" \
	"$(INTDIR)\SelectDocumentTypeDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WinProMo.obj" \
	"$(INTDIR)\WinProMo.res" \
	"$(INTDIR)\WinProMoDoc.obj" \
	"$(INTDIR)\WinProMoView.obj"

"..\..\Debug\WinProMo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "WinProMo - Win32 Release"
# Name "WinProMo - Win32 Debug"

!IF  "$(CFG)" == "WinProMo - Win32 Release"

!ELSEIF  "$(CFG)" == "WinProMo - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "WinProMo - Win32 Release"

!ELSEIF  "$(CFG)" == "WinProMo - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\WinProMo.cpp
DEP_CPP_WINPR=\
	"..\..\WinProMo\src\Automation\ProMoAppAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoAppChildAuto.h"\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramClipboardHandler.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEditor.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntityContainer.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramLine.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramMenu.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParams.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParamsRect.h"\
	"..\..\WinProMo\src\DiagramEditor\Tokenizer.h"\
	"..\..\WinProMo\src\DiagramEditor\UndoItem.h"\
	"..\..\WinProMo\src\FileUtils\DibHelper.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\GeometryUtils\GeometryHelper.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoClipboardHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoCmdHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoControlFactory.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEditor.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntityContainer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoLabel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoProperty.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoRenderer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	"..\..\WinProMo\src\WinProMoPluginInterface.h"\
	".\Automation\..\stdafx.h"\
	".\Automation\..\WinProMo.h"\
	".\Automation\..\WinProMoDoc.h"\
	".\ChildFrm.h"\
	".\DynamicElementListDlg.h"\
	".\DynamicPropertyDlg.h"\
	".\MainFrm.h"\
	".\PropertyScrollFrame.h"\
	".\PropertyScrollView.h"\
	".\WinProMoView.h"\
	

"$(INTDIR)\WinProMo.obj" : $(SOURCE) $(DEP_CPP_WINPR) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\Automation\..\stdafx.h"\
	

!IF  "$(CFG)" == "WinProMo - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/WinProMo.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\WinProMo.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "WinProMo - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/WinProMo.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\WinProMo.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	"..\..\WinProMo\src\Automation\ProMoAppAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoAppChildAuto.h"\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramClipboardHandler.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEditor.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntityContainer.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramLine.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramMenu.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParams.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParamsRect.h"\
	"..\..\WinProMo\src\DiagramEditor\Tokenizer.h"\
	"..\..\WinProMo\src\DiagramEditor\UndoItem.h"\
	"..\..\WinProMo\src\FileUtils\DibHelper.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\GeometryUtils\GeometryHelper.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoClipboardHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoCmdHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoControlFactory.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEditor.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntityContainer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoLabel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoProperty.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoRenderer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	"..\..\WinProMo\src\WinProMoPluginInterface.h"\
	".\Automation\..\stdafx.h"\
	".\Automation\..\WinProMo.h"\
	".\Automation\..\WinProMoDoc.h"\
	".\DynamicElementListDlg.h"\
	".\DynamicPropertyDlg.h"\
	".\MainFrm.h"\
	".\PropertyScrollFrame.h"\
	".\PropertyScrollView.h"\
	".\WinProMoView.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	"..\..\WinProMo\src\Automation\ProMoAppAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoAppChildAuto.h"\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramClipboardHandler.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEditor.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntityContainer.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramLine.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramMenu.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParams.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParamsRect.h"\
	"..\..\WinProMo\src\DiagramEditor\Tokenizer.h"\
	"..\..\WinProMo\src\DiagramEditor\UndoItem.h"\
	"..\..\WinProMo\src\FileUtils\DibHelper.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\GeometryUtils\GeometryHelper.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoClipboardHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoCmdHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoControlFactory.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEditor.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntityContainer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoLabel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoProperty.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoRenderer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	"..\..\WinProMo\src\WinProMoPluginInterface.h"\
	".\Automation\..\stdafx.h"\
	".\Automation\..\WinProMo.h"\
	".\Automation\..\WinProMoDoc.h"\
	".\ChildFrm.h"\
	".\DynamicElementListDlg.h"\
	".\DynamicPropertyDlg.h"\
	".\MainFrm.h"\
	".\PropertyScrollFrame.h"\
	".\PropertyScrollView.h"\
	".\SelectDocumentTypeDlg.h"\
	".\WinProMoView.h"\
	

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WinProMo.rc
DEP_RSC_WINPRO=\
	".\res\Toolbar.bmp"\
	".\res\WinProMo.ico"\
	".\res\WinProMo.rc2"\
	".\res\WinProMoDoc.ico"\
	

"$(INTDIR)\WinProMo.res" : $(SOURCE) $(DEP_RSC_WINPRO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DynamicPropertyDlg.cpp
DEP_CPP_DYNAM=\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramLine.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParams.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParamsRect.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoLabel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoProperty.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	".\Automation\..\stdafx.h"\
	".\DynamicPropertyDlg.h"\
	".\PropertyScrollFrame.h"\
	".\PropertyScrollView.h"\
	

"$(INTDIR)\DynamicPropertyDlg.obj" : $(SOURCE) $(DEP_CPP_DYNAM) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PropertyScrollView.cpp
DEP_CPP_PROPE=\
	".\Automation\..\stdafx.h"\
	".\PropertyScrollFrame.h"\
	".\PropertyScrollView.h"\
	

"$(INTDIR)\PropertyScrollView.obj" : $(SOURCE) $(DEP_CPP_PROPE) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PropertyScrollFrame.cpp
DEP_CPP_PROPER=\
	".\Automation\..\stdafx.h"\
	".\PropertyScrollFrame.h"\
	

"$(INTDIR)\PropertyScrollFrame.obj" : $(SOURCE) $(DEP_CPP_PROPER) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DynamicElementListDlg.cpp
DEP_CPP_DYNAMI=\
	".\Automation\..\stdafx.h"\
	".\DynamicElementListDlg.h"\
	

"$(INTDIR)\DynamicElementListDlg.obj" : $(SOURCE) $(DEP_CPP_DYNAMI) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WinProMoView.cpp
DEP_CPP_WINPROM=\
	"..\..\WinProMo\src\Automation\ProMoAppAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoAppChildAuto.h"\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramClipboardHandler.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEditor.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntityContainer.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramLine.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramMenu.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParams.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParamsRect.h"\
	"..\..\WinProMo\src\DiagramEditor\Tokenizer.h"\
	"..\..\WinProMo\src\DiagramEditor\UndoItem.h"\
	"..\..\WinProMo\src\FileUtils\DibHelper.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\GeometryUtils\GeometryHelper.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoClipboardHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoCmdHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoControlFactory.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEditor.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntityContainer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoLabel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoProperty.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoRenderer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	"..\..\WinProMo\src\WinProMoPluginInterface.h"\
	".\Automation\..\stdafx.h"\
	".\Automation\..\WinProMo.h"\
	".\Automation\..\WinProMoDoc.h"\
	".\CanvasSizeDialog.h"\
	".\ExportDlg.h"\
	".\GridSizeDialog.h"\
	".\WinProMoView.h"\
	

"$(INTDIR)\WinProMoView.obj" : $(SOURCE) $(DEP_CPP_WINPROM) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\GridSizeDialog.cpp
DEP_CPP_GRIDS=\
	".\Automation\..\stdafx.h"\
	".\GridSizeDialog.h"\
	

"$(INTDIR)\GridSizeDialog.obj" : $(SOURCE) $(DEP_CPP_GRIDS) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\OleSrvItem.cpp
DEP_CPP_OLESR=\
	"..\..\WinProMo\src\Automation\ProMoAppAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoAppChildAuto.h"\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramClipboardHandler.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEditor.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntityContainer.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramLine.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramMenu.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParams.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParamsRect.h"\
	"..\..\WinProMo\src\DiagramEditor\Tokenizer.h"\
	"..\..\WinProMo\src\DiagramEditor\UndoItem.h"\
	"..\..\WinProMo\src\FileUtils\DibHelper.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\GeometryUtils\GeometryHelper.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoClipboardHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoCmdHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoControlFactory.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEditor.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntityContainer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoLabel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoProperty.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoRenderer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	"..\..\WinProMo\src\WinProMoPluginInterface.h"\
	".\Automation\..\stdafx.h"\
	".\Automation\..\WinProMo.h"\
	".\Automation\..\WinProMoDoc.h"\
	".\OleSrvItem.h"\
	

"$(INTDIR)\OleSrvItem.obj" : $(SOURCE) $(DEP_CPP_OLESR) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\SelectDocumentTypeDlg.cpp
DEP_CPP_SELEC=\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramClipboardHandler.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEditor.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntityContainer.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramLine.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramMenu.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParams.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParamsRect.h"\
	"..\..\WinProMo\src\DiagramEditor\Tokenizer.h"\
	"..\..\WinProMo\src\DiagramEditor\UndoItem.h"\
	"..\..\WinProMo\src\FileUtils\DibHelper.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\GeometryUtils\GeometryHelper.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoClipboardHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoCmdHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoControlFactory.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEditor.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntityContainer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoLabel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoProperty.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoRenderer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	"..\..\WinProMo\src\WinProMoPluginInterface.h"\
	".\Automation\..\stdafx.h"\
	".\Automation\..\WinProMo.h"\
	".\SelectDocumentTypeDlg.h"\
	

"$(INTDIR)\SelectDocumentTypeDlg.obj" : $(SOURCE) $(DEP_CPP_SELEC) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WinProMoDoc.cpp
DEP_CPP_WINPROMO=\
	"..\..\WinProMo\src\Automation\ProMoAppAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoAppChildAuto.h"\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\Automation\ProMoDiagramAutoAbs.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramClipboardHandler.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEditor.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntityContainer.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramLine.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramMenu.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParams.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParamsRect.h"\
	"..\..\WinProMo\src\DiagramEditor\Tokenizer.h"\
	"..\..\WinProMo\src\DiagramEditor\UndoItem.h"\
	"..\..\WinProMo\src\FileUtils\DibHelper.h"\
	"..\..\WinProMo\src\FileUtils\FileParser.h"\
	"..\..\WinProMo\src\FileUtils\FileSerializer.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\GeometryUtils\GeometryHelper.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoClipboardHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoCmdHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoControlFactory.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEditor.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntityContainer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoLabel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoProperty.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoRenderer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	"..\..\WinProMo\src\WinProMoPluginInterface.h"\
	".\Automation\..\stdafx.h"\
	".\Automation\..\WinProMo.h"\
	".\Automation\..\WinProMoDoc.h"\
	".\Automation\ProMoDiagramAuto.h"\
	".\OleSrvItem.h"\
	".\WinProMoView.h"\
	

"$(INTDIR)\WinProMoDoc.obj" : $(SOURCE) $(DEP_CPP_WINPROMO) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CanvasSizeDialog.cpp
DEP_CPP_CANVA=\
	".\Automation\..\stdafx.h"\
	".\CanvasSizeDialog.h"\
	

"$(INTDIR)\CanvasSizeDialog.obj" : $(SOURCE) $(DEP_CPP_CANVA) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ExportDlg.cpp
DEP_CPP_EXPOR=\
	".\Automation\..\stdafx.h"\
	".\ExportDlg.h"\
	

"$(INTDIR)\ExportDlg.obj" : $(SOURCE) $(DEP_CPP_EXPOR) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Automation\ProMoDiagramAuto.cpp
DEP_CPP_PROMO=\
	"..\..\WinProMo\src\Automation\ProMoAppAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoAppChildAuto.h"\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\Automation\ProMoDiagramAutoAbs.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramClipboardHandler.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEditor.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntityContainer.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramLine.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramMenu.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParams.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParamsRect.h"\
	"..\..\WinProMo\src\DiagramEditor\Tokenizer.h"\
	"..\..\WinProMo\src\DiagramEditor\UndoItem.h"\
	"..\..\WinProMo\src\FileUtils\DibHelper.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\GeometryUtils\GeometryHelper.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoClipboardHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoCmdHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoControlFactory.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEditor.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntityContainer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoLabel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoProperty.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoRenderer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	"..\..\WinProMo\src\WinProMoPluginInterface.h"\
	".\Automation\..\stdafx.h"\
	".\Automation\..\WinProMo.h"\
	".\Automation\..\WinProMoDoc.h"\
	".\Automation\ProMoDiagramAuto.h"\
	
NODEP_CPP_PROMO=\
	".\Automation\stdafx.h"\
	

"$(INTDIR)\ProMoDiagramAuto.obj" : $(SOURCE) $(DEP_CPP_PROMO) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Automation\ProMoDiagramsAuto.cpp

!IF  "$(CFG)" == "WinProMo - Win32 Release"

DEP_CPP_PROMOD=\
	"..\..\WinProMo\src\Automation\ProMoAppAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoAppChildAuto.h"\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\Automation\ProMoDiagramAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoDiagramsAutoAbs.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramClipboardHandler.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEditor.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntityContainer.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramLine.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramMenu.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParams.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParamsRect.h"\
	"..\..\WinProMo\src\DiagramEditor\Tokenizer.h"\
	"..\..\WinProMo\src\DiagramEditor\UndoItem.h"\
	"..\..\WinProMo\src\FileUtils\DibHelper.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\GeometryUtils\GeometryHelper.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoClipboardHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoCmdHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoControlFactory.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEditor.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntityContainer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoLabel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoProperty.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoRenderer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	"..\..\WinProMo\src\WinProMoPluginInterface.h"\
	".\Automation\..\stdafx.h"\
	".\Automation\..\WinProMo.h"\
	".\Automation\..\WinProMoDoc.h"\
	".\Automation\ProMoDiagramAuto.h"\
	".\Automation\ProMoDiagramsAuto.h"\
	
NODEP_CPP_PROMOD=\
	".\Automation\stdafx.h"\
	

"$(INTDIR)\ProMoDiagramsAuto.obj" : $(SOURCE) $(DEP_CPP_PROMOD) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "WinProMo - Win32 Debug"

DEP_CPP_PROMOD=\
	"..\..\WinProMo\src\Automation\ProMoAppAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoAppChildAuto.h"\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\Automation\ProMoDiagramAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoDiagramsAutoAbs.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramClipboardHandler.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntityContainer.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\Tokenizer.h"\
	"..\..\WinProMo\src\DiagramEditor\UndoItem.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoClipboardHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntityContainer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	"..\..\WinProMo\src\WinProMoPluginInterface.h"\
	".\Automation\..\stdafx.h"\
	".\Automation\..\WinProMo.h"\
	".\Automation\..\WinProMoDoc.h"\
	".\Automation\ProMoDiagramAuto.h"\
	".\Automation\ProMoDiagramsAuto.h"\
	
NODEP_CPP_PROMOD=\
	".\Automation\stdafx.h"\
	

"$(INTDIR)\ProMoDiagramsAuto.obj" : $(SOURCE) $(DEP_CPP_PROMOD) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Automation\ProMoAppAuto.cpp
DEP_CPP_PROMOA=\
	"..\..\WinProMo\src\Automation\ProMoAppAutoAbs.h"\
	"..\..\WinProMo\src\Automation\ProMoAppChildAuto.h"\
	"..\..\WinProMo\src\Automation\ProMoAutomationHost.h"\
	"..\..\WinProMo\src\Automation\ProMoDiagramAutoAbs.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramClipboardHandler.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEditor.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntity.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramEntityContainer.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramLine.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramMenu.h"\
	"..\..\WinProMo\src\DiagramEditor\DiagramPropertyDlg.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParams.h"\
	"..\..\WinProMo\src\DiagramEditor\HitParamsRect.h"\
	"..\..\WinProMo\src\DiagramEditor\Tokenizer.h"\
	"..\..\WinProMo\src\DiagramEditor\UndoItem.h"\
	"..\..\WinProMo\src\FileUtils\DibHelper.h"\
	"..\..\WinProMo\src\FileUtils\VariantWrapper.h"\
	"..\..\WinProMo\src\GeometryUtils\DoublePoint.h"\
	"..\..\WinProMo\src\GeometryUtils\DoubleRect.h"\
	"..\..\WinProMo\src\GeometryUtils\GeometryHelper.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoBlockView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoClipboardHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoCmdHandler.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoControlFactory.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEdgeView.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEditor.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntity.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoEntityContainer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoLabel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoModel.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoProperty.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoPropertyOwner.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoRenderer.h"\
	"..\..\WinProMo\src\ProMoEditor\ProMoView.h"\
	"..\..\WinProMo\src\StdAfx.h"\
	"..\..\WinProMo\src\WinProMoPluginInterface.h"\
	".\Automation\..\stdafx.h"\
	".\Automation\..\WinProMo.h"\
	".\Automation\..\WinProMoDoc.h"\
	".\Automation\ProMoAppAuto.h"\
	".\Automation\ProMoDiagramAuto.h"\
	".\Automation\ProMoDiagramsAuto.h"\
	
NODEP_CPP_PROMOA=\
	"..\WinProMo\src\Automation\ProMoAppAutoAbs.h"\
	"..\WinProMo\src\Automation\ProMoDiagramsAutoAbs.h"\
	".\Automation\stdafx.h"\
	

"$(INTDIR)\ProMoAppAuto.obj" : $(SOURCE) $(DEP_CPP_PROMOA) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
# End Target
# End Project
################################################################################
