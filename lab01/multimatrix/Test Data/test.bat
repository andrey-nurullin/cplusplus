REM ����� �ணࠬ�� ��� ��ࠬ��஢
multimatrix.exe
IF NOT ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� � ����� ����� ��ࠬ��஬
multimatrix.exe "" a.txt
IF NOT ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� � ����� ��ࠬ��஬
multimatrix.exe a.txt
IF NOT ERRORLEVEL 1 GOTO err

REM ���������騩 䠩� � ��ࠬ����
multimatrix.exe a.txt nofile.txt
IF NOT ERRORLEVEL 1 GOTO err

REM 䠩� � �����४�묨 ����묨 (��墠⪠ ������)
multimatrix.exe b1.txt a0.txt
IF NOT ERRORLEVEL 1 GOTO err

REM ���४⭮��� १����
multimatrix.exe a1.txt b1.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result1.txt
IF ERRORLEVEL 1 GOTO err

REM ���४⭮��� १����
multimatrix.exe a2.txt b2.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result2.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT
               