REM ����� �ணࠬ�� ��� ��ࠬ��஢
findtext.exe
IF NOT ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� � ����� ��ࠬ��஬
findtext.exe file_name
IF NOT ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� � ���⮩ ��ப�� � ����⢥ ������ �� ��ࠬ��஢
findtext.exe ""
IF NOT ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� � ���⮩ ��ப�� � ����⢥ ������ �� ��ࠬ��஢
findtext.exe "test1.txt" ""
IF NOT ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� � ���������騬 ������ 䠩��
findtext.exe -123
IF NOT ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� ���४�� ��ࠬ��஬
findtext.exe "test1.txt" "��ப�" > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result1.txt
IF ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� ���४�� ��ࠬ��஬
findtext.exe "test1.txt" "��ப�" > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result2.txt
IF ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� ���४�� ��ࠬ��஬
findtext.exe "test1.txt" "������� ��ப�" > output.txt
IF NOT ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� ���४�� ��ࠬ��஬
findtext.exe "test2.txt" "�� �諨" > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result3.txt
IF ERRORLEVEL 1 GOTO err

REM ����� �ணࠬ�� ���४�� ��ࠬ��஬
findtext.exe "Onegin.txt" "�㪠" > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result4.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT
