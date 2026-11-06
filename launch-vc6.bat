@echo off
rem ============================================================
rem  launch-vc6.bat  -  启动 VC++ 6.0（含完整编译环境）
rem
rem  为什么需要这个：
rem    explorer.exe 是开机启动的，它的环境变量是旧的。
rem    从资源管理器双击 .dsw 启动的 VC6 会继承旧环境，
rem    导致找不到 cl.exe（Error spawning cl.exe）或
rem    找不到头文件（no include path set）。
rem  本脚本先设好 PATH/INCLUDE/LIB，再启动 VC6。
rem  用法：双击本文件；或 launch-vc6.bat "D:\VC6\cpp\ch01\ch01.dsw"
rem ============================================================

set VCDIR=D:\VC6Tool\VC98
set MSDEVDIR=D:\VC6Tool\Common\MSDev98\Bin

set PATH=%VCDIR%\Bin;%MSDEVDIR%;%PATH%
set INCLUDE=%VCDIR%\Include;%VCDIR%\ATL\Include;%VCDIR%\MFC\Include
set LIB=%VCDIR%\Lib;%VCDIR%\MFC\Lib

if "%~1"=="" (
    start "" "%MSDEVDIR%\MSDEV.EXE"
) else (
    start "" "%MSDEVDIR%\MSDEV.EXE" "%~1"
)