C task: (attached file.txt is related with this task)

 

The task must be performed using the C language, in console mode, without additional visual elements such as forms or text boxes. You can use any compiler just to run the program result on a Windows workstation.

An executable file and program code are required to verify the results. The files must be archived in .zip or .rar format.

 

Please do not use "string" and "long long" types in solving the task as well as "goto" statement or "malloc" function (do not use memory allocation).

 

The task is designed to test the basic knowledge of C and the skills of code building structure.

 

Task.

 

The attached .txt file contains a table of card numbers, which contains the following fields:

1. Range Start;

2. Range End;

3. Name.

[Range Start] and [Range End] fields can be from 1 to 16 characters (digits) long.

 

The task of the program is following:

1. Require a 16-digit card number.

The char [n] type (symbol array) must be used to enter, verify and process the card number to test knowledge of arrays and pointers.

If the card number is entered incorrectly, display an appropriate error message and return to entering the card number.

2. Check that the entry corresponding to the entered card number is found in the text file (check the first n digits of the entered number, where n = number of digits in the corresponding column in the file.txt file).

For example, the first line of the file contains the following information: "400000000000;499999999999;VISA;"

This means that the card number entered corresponds to this line if the number created from the first 12 digits of the card number is within the range: >=400000000000 and <=499999999999. If the number entered does not match any line in the file, display an appropriate error message on the screen for 2 seconds and return to step 1.

3. Request to enter the amount in the format "nnnn.mm", where "nnnn" is 1 to 4 digits of amount in euros, but "mm" is 2 digits of amount in cents.

If the amount is entered incorrectly, display an appropriate error message and return to the amount entry.

4. Save the card number entered, "Name" field corresponding to the number from the “task.txt” and the entered amount in the "trans.txt" file.

5. Return to step 1.