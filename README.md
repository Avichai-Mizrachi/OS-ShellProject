## OS-Ex2: "SHELL"

Submitters:


1. Avichai Mizrachi
2. Maya Rom

Makefile - our makefile include default and clean.

<img width="501" alt="1" src="https://user-images.githubusercontent.com/118835480/235328876-847d7e60-b6a0-4fe1-a043-613c005544ce.png">



Part A :


Part a include 2 parts,

The first one is "cmp" method which compare two files, and return “0” if they are equal, and “1” if not (return an INT).
The tool will support -v flag for verbose output. By this we mean that the tool will print “equal” or
“distinct”, in addition to returning the int value.
The toll will support -i flag, that mean “ignore case” so “AAA” and “aaa” meaning equals.
Usage: ./cmp <file1> <file2> -v

<img width="840" alt="Screenshot 2023-05-01 at 2 49 53" src="https://user-images.githubusercontent.com/118835480/235382119-72e2a23b-24f8-44de-a546-935024b6c64d.png">

<img width="365" alt="Screenshot 2023-05-01 at 2 52 35" src="https://user-images.githubusercontent.com/118835480/235382135-138b08d4-93ec-457c-b8c3-2305d8fb5657.png">

<img width="358" alt="Screenshot 2023-05-01 at 2 52 44" src="https://user-images.githubusercontent.com/118835480/235382141-009afa25-fc19-4a9d-8d53-287f723809a4.png">


The second one is "copy" method copy a file to another place and/or name.
Which will return “0” on success, or “1” on failure (return an INT).
The tool will create a new file, if it does not exist, but it will not overwrite a file if it do exist.
the tool will support -v flag, that will output “success” if the file is copied, or “target file exist” if this is
the case, or “general failure” on some other problem (in addition to the returned INT value).
The tool will support -f flag (that means force), that allows to overwrite the target file
Usage: ./copy <file1> <file2> -v

<img width="836" alt="Screenshot 2023-04-30 at 2 24 04" src="https://user-images.githubusercontent.com/118835480/235328894-23580e0f-f067-4dac-87d1-da819f89ddbf.png">


Part B:


We wrote two libraries - codecA and codecB.
We have two codding methods.
Method a, named codecA: covert all lower case chars to upper case, and all upper case to lower case.
All other chars will remain unchanged.
Method b, named codecB: convert all chars to the 3-rd next char (adding a number of 3 to the ascii
val).
The libraries support “encode” and “decode” methods.
Usage : encode/decode <codec> <message>

Example: “./encode codecA aaaBBB” will return “AAAbbb”

<img width="757" alt="Screenshot 2023-04-30 at 2 29 33" src="https://user-images.githubusercontent.com/118835480/235328921-f449c1c7-48c8-4519-a7b2-9dca4aad0b5e.png">


Example: “./decode codecB EEEddd” will return “BBBaaa”

<img width="768" alt="Screenshot 2023-04-30 at 2 30 13" src="https://user-images.githubusercontent.com/118835480/235328930-119c2aa4-5d2b-484c-a3d6-7848a5091e17.png">


Part C:


Part C (52 pts):
We wrote a shell program named stshell.
It supports in Ctrl+C, redirect output with ">" and ">>",
,allow piping with "|", at least for 2 following pipes and "exit" command.

Example: “ls -l | grep aaa | wc”

<img width="668" alt="Screenshot 2023-04-30 at 2 35 24" src="https://user-images.githubusercontent.com/118835480/235328978-49155041-4f73-4420-8477-52556bb15408.png">

<img width="661" alt="Screenshot 2023-04-30 at 2 35 45" src="https://user-images.githubusercontent.com/118835480/235328981-7523be73-d843-4e01-a828-10d73d8cc641.png">

<img width="662" alt="Screenshot 2023-04-30 at 2 37 08" src="https://user-images.githubusercontent.com/118835480/235328987-98b1dfb7-fdf8-4589-a4d5-65d01e1f08b7.png">

<img width="665" alt="Screenshot 2023-04-30 at 2 37 52" src="https://user-images.githubusercontent.com/118835480/235328993-0a0fd062-c247-434f-9208-6675f0cb99b7.png">


