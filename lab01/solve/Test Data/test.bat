REM ����� �ணࠬ�� ��� ��ࠬ��஢
solve.exe
IF NOT ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� � ����� ��ࠬ��஬
solve.exe 2.2
IF NOT ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� � ���� ��ࠬ��ࠬ�
solve.exe 2.3 -3.04
IF NOT ERRORLEVEL 1 GOTO err

REM �����樥�� � = 0
findtext.exe 0 3 -4 
IF NOT ERRORLEVEL 1 GOTO err

REM ����⢨⥫��� ��୥� ���
findtext.exe 2 1 2
IF NOT ERRORLEVEL 1 GOTO err

REM ��୨ ࠢ��
solve.exe 1 2 1 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result1.txt
IF ERRORLEVEL 1 GOTO err

REM 2 ����
solve.exe 1 1 -2 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result2.txt
IF ERRORLEVEL 1 GOTO err

REM 2 ����⢨⥫��� ����
solve.exe 4.234 32.1983 -25.32 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result3.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT
               