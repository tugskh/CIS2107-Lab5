/*

    Number converter

    Menu
    Convert between integer, binary, octal and hexadecimal

    This program should accept numeric values in hexadecimal,
    decimal, octal and binary formats as:

        Hex 0x0 to 0xFFFFFFFF
        Dec 0 to 4294967295
        Oct o0 to o37777777777
        Bin b0 to b11111111111111111111111111111111

    After a value is input the code in main will interpret the
    data types above an process the conversion to an unsigned
    int.  The unsigned int will be used to convert the input to
    strings containing hexadecimal, octal and binary strings.

*/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>


//int input_to_decimal(char *input);
unsigned int bin_to_uint(char *input);
unsigned int oct_to_uint(char *input);
unsigned int hex_to_uint(char *input);
unsigned int dec_to_uint(char *input);
void uint_to_hex(unsigned int n, char *output);
void uint_to_oct(unsigned int n, char *output);
void uint_to_bin(unsigned int n, char *output);


int error = 0;


int main(){

    char input[50];
    unsigned int n = 0;
    char output[50];
    
    //char input[50] = "b10011000010";
    //printf("%d\n\n", bin_to_uint(input));
    
    //unsigned int n = 1218;
    //uint_to_bin(n, output);
    //printf("%s\n", output);
    

    // Write code here to test your functions
    // Uncomment code below when done

    printf("Enter a binary, octal, decimal or hexadecimal number\n");
    printf("convert > ");
    gets(input);

    // Detect input data type
    // Hexadecimal
    if(input[0] == '0' && input[1] == 'x'){
        n = hex_to_uint(input);
    }
    // Decimal
    else if(input[0] >= '0' && input[0] <= '9'){
        n = dec_to_uint(input);
    }
    // Octal
    else if(input[0] == 'o'){
        n = oct_to_uint(input);
    }
    // Binary
    else if(input[0] == 'b'){
        n = bin_to_uint(input);
    }
    // Unknown
    else{
        printf("ERROR: Unknown data type: %s\n", input);
    }

    // Print results
    printf("The decimal value of %s is %u\n", input, n);
    uint_to_hex(n, output);
    printf("The hexadecimal value of %s is %s\n", input, output);
    uint_to_oct(n, output);
    printf("The octal value of %s is %s\n", input, output);
    uint_to_bin(n, output);
    printf("The binary value of %s is %s\n", input, output);


    return 0;
}


/*
    This function converts the value part of the hex
    string to an unsigned integer value.  The first
    two chars are 0x, which tells that the string is
    in hex.  Start processing the value at index 2 until
    the null, calculating the int value as you would on
    paper.  Try on paper first.
*/
// Convert a hexadecimal char array to uint
unsigned int hex_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    // Declare and set multiplier to 1
    int mul = 1;
    // Declare iterator
    int i;

    // Loop through value part of input string
    for(i = strlen(input)-1; i>=2; i--){
        // If between 0 and 9 add 0 to 9 to res with multiplier
	if(input[i] >= '0' && input[i] <= '9'){
			res = res + (input[i] - '0')*mul;
			//mul = mul*16;
		}
        // If between A and F add 10 to 15 to res with multiplier
	else if(input[i] >= 'A' && input[i] <= 'F'){
		res = res + (input[i] - 'A' + 10)*mul;
		//mul = mul*16;
	}
        // Error - exit
	else{
		printf("Not a valid hexadecimal number\n");
		exit(0);
	}
        // Advance multiplier to next position value
	mul = mul*16;
	}
    return res;
}


/*
    Copy hex_to_uint() and modify for decimal input.
*/
// Convert a unsigned integer char array to uint
unsigned int dec_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    
    // Declare and set multiplier to 1
    int mul = 1;
    // Declare iterator
    int i;

    // Loop through value part of input string
    for(i = strlen(input)-1; i>=0; i--){
        // If between 0 and 9 add 0 to 9 to res with multiplier
	if(input[i] >= '0' && input[i] <= '9'){
			res = res + (input[i] - '0')*mul;
			//mul = mul*16;
		}
        // Error - exit
	else{
		printf("Not a valid number\n");
		exit(0);
	}
        // Advance multiplier to next position value
	mul = mul*10;
	}

	
    return res;
}


/*
    Copy dec_to_uint() and modify for octal input.
*/
// Convert a octal char array to uint
unsigned int oct_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    
    // Declare and set multiplier to 1
    int mul = 1;
    // Declare iterator
    int i;

    // Loop through value part of input string
    for(i = strlen(input)-1; i>=1; i--){
        // If between 0 and 9 add 0 to 9 to res with multiplier
	if(input[i] >= '0' && input[i] <= '9'){
			res = res + (input[i] - '0')*mul;
		}
        // Error - exit
	else{
		printf("Not a valid octal number\n");
		exit(0);
	}
        // Advance multiplier to next position value
	mul = mul*8;
	}

    return res;
}


/*
    Copy oct_to_uint() and modify for binary input.
*/
// Convert a binary char array to unsigned int
unsigned int bin_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    
    // Declare and set multiplier to 1
    int mul = 1;
    // Declare iterator
    int i;

    // Loop through value part of input string
    for(i = strlen(input)-1; i>=1; i--){
        // If between 0 and 9 add 0 to 9 to res with multiplier
	if(input[i] >= '0' && input[i] <= '9'){
			res = res + (input[i] - '0')*mul;
		}
        // Error - exit
	else{
		printf("Not a valid octal number\n");
		exit(0);
	}
        // Advance multiplier to next position value
	mul = mul*2;
	}

    return res;
}


/*
    This function converts from unsigned int to a hex
    char array.  Try this on paper before coding.
*/
// Convert a unsigned integer char array to hexadecimal
void uint_to_hex(unsigned int n, char *output){
    // Declare a uint for remainder

    // Declare an int for division

    // Declare a char array buffer

    // Use a loop to generate a hex string - string will be reverse

    // Get last hex char

    // Put null at end of buffer

    // Copy 0x to output string

    // Copy chars from buffer in reverse order to output string
    
    
    int i = 0;
    char store[50];
	
	while(n > 15){
	
		int mod = n%16;
		n = n/16;
		
		
		if(mod >=0 && mod <=9){
			store[i++] = mod + '0';
		}
		else if (mod>=10 && mod <= 15){
			store[i++] = mod - 10 + 'A';
		}
			
		
	}
	
	if(n >=0 && n <=9){
		store[i++] = n +'0';
	}
	else if(n>=10 && n <= 15){
		store[i++] = n - 10 +'A';
		
	}
		
	store[i] = '\0';
	
	output[0] = '0';
	output[1] = 'x';
	
	for(i=2; i<strlen(store)+2; i++){
		output[i] = store[(strlen(store))-i+1];
	}
	
	output[i] = '\0';
	
	//printf("The hexadecimal number is %s\n", output);

    return;
}


/*
    Copy uint_to_hex() and modify for octal
*/
// Convert a unsigned integer char array to octal
void uint_to_oct(unsigned int n, char *output){

    int i = 0;
    char store[50];
	
	while(n > 7){
	
		int mod = n%8;
		n = n/8;
		
		/*
		if(mod >=0 && mod <=8){
			store[i++] = mod + '0';
		}*/
		store[i++] = mod + '0';
			
		
	}
	/*
	if(n >=0 && n <=9){
		store[i++] = n +'0';
	}*/
	store[i++] = n + '0';
		
	store[i] = '\0';
	
	output[0] = 'o';
	
	for(i=1; i<strlen(store)+1; i++)
		output[i] = store[(strlen(store))-i];
	
	output[i] = '\0';
	
	//printf("The octal number is %s\n", output);

    return;
}


/*
    Copy uint_to_oct() and modify for binary
*/
// Convert a unsigned integer char array to binary
void uint_to_bin(unsigned int n, char *output){
    int i = 0;
    char store[50];
	
	while(n > 1){
	
		int mod = n%2;
		n = n/2;
		
		/*
		if(mod >=0 && mod <=8){
			store[i++] = mod + '0';
		}*/
		store[i++] = mod + '0';
			
		
	}
	/*
	if(n >=0 && n <=9){
		store[i++] = n +'0';
	}*/
	store[i++] = n + '0';
		
	store[i] = '\0';
	
	output[0] = 'b';
	for(i=1; i<strlen(store)+1; i++)
		output[i] = store[(strlen(store))-i];
	
	output[i] = '\0';
	
	//printf("The binary number is %s\n", output);
    return;
}

