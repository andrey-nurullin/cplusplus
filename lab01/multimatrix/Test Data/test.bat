REM запуск программы без параметров
multimatrix.exe
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с одним пустым параметром
multimatrix.exe "" a.txt
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с одним параметром
multimatrix.exe a.txt
IF NOT ERRORLEVEL 1 GOTO err

REM несуществующий файл в параметрах
multimatrix.exe a.txt nofile.txt
IF NOT ERRORLEVEL 1 GOTO err

REM файл с некорректными данными (нехватка данных)
multimatrix.exe b1.txt a0.txt
IF NOT ERRORLEVEL 1 GOTO err

REM корректность результата
multimatrix.exe a1.txt b1.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result1.txt
IF ERRORLEVEL 1 GOTO err

REM корректность результата
multimatrix.exe a2.txt b2.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result2.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT
               