# cc.ps1 — VC++ 6.0 单文件编译运行脚本
#
# 用法:
#   .\cc.ps1 cpp\p01_hello.cpp        编译 + 运行
#   .\cc.ps1 cpp\p01_hello.cpp -Only  只编译不运行
#
# 为什么需要这个脚本:
#   VC6 的 IDE 里，单文件必须建工程(.dsp)才能 Build 出 exe。
#   但命令行 cl.exe 可以直接编译单个 .cpp —— 本脚本封装所需环境变量。
#
# 必需条件:
#   PATH 必须同时包含 VC98\Bin(cl.exe/link.exe) 和
#   MSDev98\Bin(MSPDB60.DLL)，缺后者会报 0xC0000135。

param(
    [Parameter(Mandatory = $true, Position = 0)]
    [string]$Source,

    [switch]$Only
)

$ErrorActionPreference = 'Stop'

# ---- 按实际安装位置修改 ----
$VCDIR    = 'D:\Downloads\VC6.0 完整绿色版\VC98'
$MSDEVDIR = 'D:\Downloads\VC6.0 完整绿色版\Common\MSDev98\Bin'

if (-not (Test-Path "$VCDIR\Bin\cl.exe")) {
    Write-Host "[错误] 找不到 cl.exe，请检查 `$VCDIR = $VCDIR" -ForegroundColor Red
    exit 1
}
if (-not (Test-Path "$MSDEVDIR\MSPDB60.DLL")) {
    Write-Host "[错误] 找不到 MSPDB60.DLL，请检查 `$MSDEVDIR = $MSDEVDIR" -ForegroundColor Red
    exit 1
}

if (-not (Test-Path $Source)) {
    Write-Host "[错误] 源文件不存在: $Source" -ForegroundColor Red
    exit 1
}

# 设置环境
$env:PATH    = "$VCDIR\Bin;$MSDEVDIR;$env:PATH"
$env:INCLUDE = "$VCDIR\Include;$VCDIR\ATL\Include;$VCDIR\MFC\Include"
$env:LIB     = "$VCDIR\Lib;$VCDIR\MFC\Lib"

$srcPath = (Resolve-Path $Source).Path
$srcDir  = Split-Path $srcPath -Parent
$srcName = Split-Path $srcPath -Leaf
$baseName = [System.IO.Path]::GetFileNameWithoutExtension($srcName)
$exePath = Join-Path $srcDir "$baseName.exe"

Write-Host ''
Write-Host "===== 编译 $srcName =====" -ForegroundColor Cyan

Push-Location $srcDir
try {
    & "$VCDIR\Bin\cl.exe" /nologo $srcName
    $code = $LASTEXITCODE
}
finally {
    Pop-Location
}

if ($code -ne 0) {
    Write-Host ''
    Write-Host "[失败] 编译未通过，见上方错误信息" -ForegroundColor Red
    exit 1
}

if (-not (Test-Path $exePath)) {
    Write-Host "[失败] 编译通过但未生成 exe" -ForegroundColor Red
    exit 1
}

if ($Only) {
    Write-Host ''
    Write-Host "[成功] 已生成: $exePath" -ForegroundColor Green
    exit 0
}

Write-Host ''
Write-Host "===== 运行 $baseName.exe =====" -ForegroundColor Cyan
Write-Host ''
& $exePath
Write-Host ''
Write-Host '===== 结束 =====' -ForegroundColor DarkGray
