
PATH="h:/sharecode/yueqian/5month/2week/6day/1t"

EXEC="C:/Keil_v5/UV4/UV4.exe"

$EXEC  -b $PATH/temp.uvprojx -j0 -t T01 -o $PATH/.vscode/uv4.log


$EXEC  -f $PATH/temp.uvprojx -j0 -t T01 -o $PATH/.vscode/uv4.log
