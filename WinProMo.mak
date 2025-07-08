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
MTL=mktyplib.exe
RSC=rc.exe
CPP=cl.exe

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

ALL : "..\Release\WinProMo.exe"

CLEAN : 
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DynamicElementListDlg.obj"
	-@erase "$(INTDIR)\DynamicPropertyDlg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\PropertyScrollFrame.obj"
	-@erase "$(INTDIR)\PropertyScrollView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\WinProMo.obj"
	-@erase "$(INTDIR)\WinProMo.pch"
	-@erase "$(INTDIR)\WinProMo.res"
	-@erase "..\Release\WinProMo.exe"

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
# ADD LINK32 ../WinPromo/Release/WinProMo.lib /nologo /subsystem:windows /machine:I386 /out:"../Release/WinProMo.exe"
LINK32_FLAGS=../WinPromo/Release/WinProMo.lib /nologo /subsystem:windows\
 /incremental:no /pdb:"$(OUTDIR)/WinProMo.pdb" /machine:I386\
 /out:"../Release/WinProMo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DynamicElementListDlg.obj" \
	"$(INTDIR)\DynamicPropertyDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PropertyScrollFrame.obj" \
	"$(INTDIR)\PropertyScrollView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WinProMo.obj" \
	"$(INTDIR)\WinProMo.res"

"..\Release\WinProMo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

ALL : "..\Debug\WinProMo.exe"

CLEAN : 
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DynamicElementListDlg.obj"
	-@erase "$(INTDIR)\DynamicPropertyDlg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\PropertyScrollFrame.obj"
	-@erase "$(INTDIR)\PropertyScrollView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\WinProMo.obj"
	-@erase "$(INTDIR)\WinProMo.pch"
	-@erase "$(INTDIR)\WinProMo.res"
	-@erase "$(OUTDIR)\WinProMo.pdb"
	-@erase "..\Debug\WinProMo.exe"
	-@erase "..\Debug\WinProMo.ilk"

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
# ADD LINK32 ../WinPromo/Debug/WinProMo.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../Debug/WinProMo.exe"
LINK32_FLAGS=../WinPromo/Debug/WinProMo.lib /nologo /subsystem:windows\
 /incremental:yes /pdb:"$(OUTDIR)/WinProMo.pdb" /debug /machine:I386\
 /out:"../Debug/WinProMo.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DynamicElementListDlg.obj" \
	"$(INTDIR)\DynamicPropertyDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PropertyScrollFrame.obj" \
	"$(INTDIR)\PropertyScrollView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WinProMo.obj" \
	"$(INTDIR)\WinProMo.res"

"..\Debug\WinProMo.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	"..\WinProMo\ProMoEditor\ProMoClipboardHandler.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoEntityContainer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	"..\WinProMo\WinProMoDoc.h"\
	"..\WinProMo\WinProMoPluginInterface.h"\
	".\ChildFrm.h"\
	".\DynamicElementListDlg.h"\
	".\DynamicPropertyDlg.h"\
	".\MainFrm.h"\
	".\PropertyScrollFrame.h"\
	".\PropertyScrollView.h"\
	".\StdAfx.h"\
	".\WinProMo.h"\
	

"$(INTDIR)\WinProMo.obj" : $(SOURCE) $(DEP_CPP_WINPR) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

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
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEditor.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramLine.h"\
	"..\WinProMo\DiagramEditor\DiagramMenu.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\HitParams.h"\
	"..\WinProMo\DiagramEditor\HitParamsRect.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	"..\WinProMo\ProMoEditor\ProMoClipboardHandler.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoEdgeView.h"\
	"..\WinProMo\ProMoEditor\ProMoEditor.h"\
	"..\WinProMo\ProMoEditor\ProMoEntityContainer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	"..\WinProMo\WinProMoDoc.h"\
	"..\WinProMo\WinProMoPluginInterface.h"\
	"..\WinProMo\WinProMoView.h"\
	".\DynamicElementListDlg.h"\
	".\DynamicPropertyDlg.h"\
	".\MainFrm.h"\
	".\PropertyScrollFrame.h"\
	".\PropertyScrollView.h"\
	".\StdAfx.h"\
	".\WinProMo.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEditor.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramLine.h"\
	"..\WinProMo\DiagramEditor\DiagramMenu.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\HitParams.h"\
	"..\WinProMo\DiagramEditor\HitParamsRect.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	"..\WinProMo\ProMoEditor\ProMoClipboardHandler.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoEdgeView.h"\
	"..\WinProMo\ProMoEditor\ProMoEditor.h"\
	"..\WinProMo\ProMoEditor\ProMoEntityContainer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	"..\WinProMo\WinProMoDoc.h"\
	"..\WinProMo\WinProMoPluginInterface.h"\
	"..\WinProMo\WinProMoView.h"\
	".\ChildFrm.h"\
	".\DynamicElementListDlg.h"\
	".\DynamicPropertyDlg.h"\
	".\MainFrm.h"\
	".\PropertyScrollFrame.h"\
	".\PropertyScrollView.h"\
	".\StdAfx.h"\
	".\WinProMo.h"\
	

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
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEditor.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramMenu.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\PropertyItem\CustomPropertyItem.h"\
	"..\WinProMo\PropertyItem\PropertyItem.h"\
	"..\WinProMo\PropertyItem\TypedPropertyItem.h"\
	"..\WinProMo\PropertyItem\TypedPropertyItem.hxx"\
	"..\WinProMo\StdAfx.h"\
	".\DynamicPropertyDlg.h"\
	".\PropertyScrollFrame.h"\
	".\PropertyScrollView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DynamicPropertyDlg.obj" : $(SOURCE) $(DEP_CPP_DYNAM) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PropertyScrollView.cpp
DEP_CPP_PROPE=\
	".\PropertyScrollFrame.h"\
	".\PropertyScrollView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\PropertyScrollView.obj" : $(SOURCE) $(DEP_CPP_PROPE) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PropertyScrollFrame.cpp
DEP_CPP_PROPER=\
	".\PropertyScrollFrame.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\PropertyScrollFrame.obj" : $(SOURCE) $(DEP_CPP_PROPER) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DynamicElementListDlg.cpp
DEP_CPP_DYNAMI=\
	".\DynamicElementListDlg.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DynamicElementListDlg.obj" : $(SOURCE) $(DEP_CPP_DYNAMI) "$(INTDIR)"\
 "$(INTDIR)\WinProMo.pch"


# End Source File
# End Target
# End Project
################################################################################
