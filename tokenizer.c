#include <stdio.h>
#include <ctype.h>
#include <string.h>

int opFunc(char* ex, int newIndex){
    int i= newIndex; // have loop start at the index of the string where the operator from main loop starts
    while (ex[i] != '\0'){
        if(ex[i] == '('){
            printf("left parenthesis: \"(\"\n");
        } else if(ex[i] == ')'){
            printf("right parenthesis: \")\"\n");
        } else if (ex[i] == '['){
            printf("left bracket : \"[\"\n");
        } else if(ex[i] == ']'){
            printf("right bracket: \"]\"\n");
        } else if(ex[i] == '.'){
            printf("structure member: \".\"\n");
        } else if (ex[i] == '-' && ex[i+1] == '>'){
            printf("structure pointer: \"->\"\n");
            i++;
        } else if (ex[i] == ','){
            printf("comma: \",\"\n");
        } else if(ex[i]== '~'){
            printf("ls complement: \"~\"\n");
        }else if (ex[i] == '=' && ex[i+1] == '='){
            printf("equality test: \"==\"\n");
            i++;
        }else if (ex[i] == '='){
            printf("assignment: \"=\"\n"); 
        } else if (ex[i] == '!' && ex[i+1] == '='){
            printf("inequality test: \"!=\"\n");  
            i++;
        } else if(ex[i] == '!'){
            printf("negate: \"!\"\n");

        } else if (ex[i] == '>' && ex[i+1] == '>' && ex[i+2] == '='){
            printf("shift right equals: \">>=\"\n");
            i += 2;
        } else if (ex[i] == '<' && ex[i+1] == '<' && ex[i+2] == '='){
            printf("shift left equals: \"<<=\"\n");
            i += 2;
        } else if(ex[i] == '>' && ex[i+1] == '>' && ex[i+2] != '='){ //Problem here
            printf("shift right: \">>\"\n");
            i++;    
        } else if(ex[i] == '<' && ex[i+1] == '<' && ex[i+2] != '='){
            printf("shift left: \"<<\"\n");
            i++;
        } else if (ex[i] == '<' && ex[i+1] != '='){
            printf("less than test: \"<\"\n");
        } else if (ex[i] == '>' && ex[i+1] != '='){
            printf("greater than test: \">\"\n");
        } else if (ex[i] == '<' && ex[i+1] == '='){
            printf("less than or equal test: \"<=\"\n");
            i++;
        } else if (ex[i] == '>' && ex[i+1] == '='){
            printf("greater than or equal test: \">=\"\n");
            i++;
        } else if (ex[i] == '&' && ex[i+1] == '&'){
            printf("logical AND: \"&&\"\n");    
            i++;
        } else if (ex[i] == '&' && ex[i+1] == '='){
            printf("bitwise AND equals: \"&=\" \n");
            i++;
        } else if (ex[i] == '&' && ex[i+1] != '='){//add  && ex[i+1] != '&' maybe? For &&
            printf("AND/address operator: \"&\"\n");
        } else if (ex[i] == '-' && ex[i+1] != '-' && ex[i+1] != '='){
            printf("minus/subtract operator: \"-\"\n");
        } else if (ex[i] == '*' && ex[i+1] != '='){
            printf("multiply/dereference operator: \"*\"\n");    
        } else if (ex[i] == '+' && ex[i+1] == '='){
            printf("plus equals: \"+=\"\n");
            i++;
        } else if (ex[i] == '+' && ex[i+1] != '+'){
            printf("addition: \"+\"\n");
        } else if (ex[i] == '+' && ex[i+1] == '+'){
            printf("increment: \"++\"\n");
            i++;
        } else if (ex[i] == '-' && ex[i+1] == '-'){
            printf("decrement: \"--\"\n");
            i++;    
        } else if (ex[i] == '-' && ex[i+1] == '='){
            printf("minus equals: \"-=\"\n");
            i++;
        } else if (ex[i] == '*' && ex[i+1] == '='){
            printf("times equals: \"*=\"\n");
            i++;
        } else if (ex[i] == '/' && ex[i+1] == '='){
            printf("divide equals: \"/=\"\n");
            i++;
        } else if (ex[i] == '%' && ex[i+1] == '='){
            printf("mod equals: \"%%=\"\n");
            i++;
        } else if (ex[i] == '^' && ex[i+1] == '='){
            printf("bitwise XOR equals: \"^=\"\n");
             i++;
        } else if (ex[i] == '|' && ex[i+1] == '='){
            printf("bitwise OR equals: \"|=\"\n");
            i++;
        } else if (ex[i] == '^' && ex[i+1] != '='){
            printf("bitwise XOR: \"^\"\n");
        } else if(ex[i] == '|' && ex[i+1] != '=' && ex[i+1] != '|'){
            printf("bitwise OR: \"|\"\n");
        } else if (ex[i] == '/'){
            printf("division: \"/\"\n");
        } else if (ex[i] == '|' && ex[i+1] == '|'){
            printf("logical OR: \"||\"\n");
            i++;
        } else if (ex[i] == '&' && ex[i+1] == '&'){
            printf("logical AND: \"&&\"\n");    
            i++;
        } else if (ex[i] == '?'){
            printf("conditional true: \"?\"\n");
        } else if (ex[i] == ':'){
            printf("conditional false: \":\"\n");
        }else {
            break;
        } 
        i++;
    }
    return i; // function returns new index that main loop will now start at
}

int wordFunc(char* str, int newIndex){ // have loop start at the index of the string where the operator we found in main starts
    static char token[1000]; //temp string to add each part of token to
    char *poin2 = str;
    int i = newIndex; // have loop start at the index of the string where the letter from main loop starts

    while(*(poin2 + i) != '\0'){
        if(isalpha(*(poin2 + i))){ // if its a letter, add to token string to be printed out at end 
            strncat(token, &(*(poin2 + i)), 1);
            i++;
        } else if (isdigit(*(poin2 + i))){
            strncat(token, &(*(poin2 + i)), 1); // if its a num, add to token string to be printed out at end 
            i++;
        } 
        else {
            break;
        } 
    }
    
    if(strcmp(token, "sizeof") == 0 && !isdigit(str[i+6])){
        printf("sizeof: \"sizeof\"\n");
    } else {
        printf("word: \"%s\"\n", token); // if not num or letter, print, break, return new index to main loop
    }
    memset(token,0,strlen(token)); //reset token for next time function runs
    return i; // function returns new index that main loop will now start at
    
}

int numberFunc(char* str, int newIndex){ // have loop start at the index of the string where the operator we found in main starts
    static char token[1000]; //temp string to add each token to
    char *ptr = token;
    char *temp = str;
    int i = newIndex; // have loop start at the index of the string where the num from main loop starts
    while (str[i]!= '\0'){
        if(str[i] == '.' && isdigit(str[i+1])){ //check if token is floating num
            strncat(token, &str[i], 1); 
            i++; //increment to skip the decimal after adding it to the string
            while (str[i]!= '\0'){
                if ((str[i] == 'e' || str[i] == 'E') && str[i+1] == '-' && isdigit(str[i+2])){ //e-10 power
                    strncat(token, &str[i], 1); 
                    strncat(token, &str[i+1], 1);
                    i=i+2;
                    while(str[i]!= '\0'){
                            if (isalpha(str[i])  || !isdigit(str[i]) || isspace(str[i])){
                                printf("floating point: \"%s\"\n", token);
                                memset(token,0,strlen(token));
                                return i;
                            } else{
                                strncat(token, &str[i], 1);
                                i++;
                            }
                        }
                } 
                else if ((str[i] == 'e' || str[i] == 'E') && str[i+1] == '+' && isdigit(str[i+2])){ //e+10 power
                    strncat(token, &str[i], 1); 
                    strncat(token, &str[i+1], 1);
                    i=i+2;
                    while(str[i]!= '\0'){
                            if (isalpha(str[i])  || !isdigit(str[i]) || isspace(str[i])){
                                printf("floating point: \"%s\"\n", token);
                                memset(token,0,strlen(token));
                                return i;
                            } else{
                                strncat(token, &str[i], 1);
                                i++;
                            }
                    }
                } 
                else if ((str[i] == 'e' || str[i] == 'E') && isdigit(str[i+1])){
                    strncat(token, &str[i], 1);
                    i++;
                    while(str[i]!= '\0'){
                            if (isalpha(str[i])  || !isdigit(str[i]) || isspace(str[i])){
                                printf("floating point: \"%s\"\n", token);
                                memset(token,0,strlen(token));
                                return i;
                            } else{
                                strncat(token, &str[i], 1);
                                i++;
                            }
                        }
                }
                else if(!isdigit(str[i])){ //break if not a number
                    break;
                } 
                else {
                   strncat(token, &str[i], 1); 
                   i++;
                }
            }if (strstr(token, "e") ||strstr(token, "E") ){
                    printf("floating point: \"%s\"\n", token);
                    memset(token,0,strlen(token)); //reset token for next time function runs
                    return i;
                } else {
                    printf("floating point: \"%s\"\n", token);
                    memset(token,0,strlen(token)); //reset token for next time function runs
                    return i;
                }
        } 
        else if(str[i] == '0' && (str[i+1] == 'x' || str[i+1] == 'X')){ //check if token is hex
           
            if (strlen(ptr) != 0){
                strncat(token, &str[i], 1); 
                i++;
            }
            else {
                strncat(token, &str[i], 1);
                strncat(token, &str[i+1], 1);
                i=i+2; // skip 0 and x/X indexes
                while(str[i] != '\0'){
                switch(str[i]){ // can only be hex if after 0x there is (A-f) (a-f) (1-9)
                    case 'A':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case 'a':
                        strncat(token, &str[i], 1);
                        i++;
                        break;
                    case 'B':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case 'b':
                        strncat(token, &str[i], 1);
                        i++;
                        break;
                    case 'C':
                        strncat(token, &str[i], 1);
                        i++;
                        break;
                    case 'c':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case 'D':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case 'd':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case 'E':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case 'e':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case 'F':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case 'f':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
		    case '0':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case '1':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case '2':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case '3':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case '4':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case '5':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case '6':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case '7':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case '8':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    case '9':
                        strncat(token, &str[i], 1); 
                        i++;
                        break;
                    default :
                        goto EndWhile;
                }
                
                }
                EndWhile: ;
                printf("hexadecimal integer: \"%s\"\n", token);
                memset(token,0,strlen(token));
                break;
            }
            
        }if (str[i] == '0' && str[i+1] == '.' && isdigit(str[i+2])){ //account for 0.0 being floating
            if(strlen(ptr) != 0){
               strncat(token, &str[i], 1); 
                i++; 
            } else {
                strncat(token, &str[i], 1); 
                strncat(token, &str[i+1], 1); 
                i=i+2;
                while(str[i]!= '\0'){
                    if(!isdigit(str[i])){
                        break;
                    } else if(isdigit(str[i]) && str[i+1] == '\0'){
                       strncat(token, &str[i], 1);
                       printf("floating point: \"%s\"\n", token);
                       memset(token,0,strlen(token));
                       i++;
                       return i;
                    } else {
                        strncat(token, &str[i], 1);
                        i++;
                    }
                }
                printf("floating point: \"%s\"\n", token); 
                memset(token,0,strlen(token)); //reset token for next time function runs
                i++;
                break; 
            }
        } 
        else if(str[i] == '0' && (!isdigit(str[i+1]) && !isalpha(str[i+1]))){ //if string is just 0 w/delimiter or operator after print as octal
            if(strlen(ptr) != 0){
               strncat(token, &str[i], 1); 
                i++; 
        } else{
            printf("octal integer: \"%d\"\n", 0); 
            i++;
            break;
        }
        }
        else if (str[i] == '0' && isalpha(str[i+1])){ //if string is just 0 w/letter after print as octal
            if(strlen(ptr) != 0){
               strncat(token, &str[i], 1); 
                i++; 
            } 
            else if(str[i+1] != 'x' && str[i+1] != 'X'){
                strncat(token, &str[i], 1); 
                printf("octal integer: \"%s\"\n", token); 
                memset(token,0,strlen(token)); //reset token for next time function runs
                i++;
                break;
            }
            else{
            i++;
        }
        }
        else if (str[i] == '0' && isdigit(str[i+1])){ // check if token is octal
            if(str[i+1] == '8' || str[i+1] == '9'){ //not octal
                strncat(token, &str[i], 1);
                i++;      
            }
            else if(strlen(ptr) != 0){ //if str is not null then that means this 0 is already part of a number think 102 so not octal
                strncat(token, &str[i], 1);
                i++; 
            }
            else {
                while (str[i]!= '\0'){
                    if(str[i] == '.' && isdigit(str[i+1])){ //check if token is floating num
                    strncat(token, &str[i], 1); 
                    i++; //increment to skip the decimal after adding it to the string
                    while (str[i]!= '\0'){
                        if ((str[i] == 'e' || str[i] == 'E') && str[i+1] == '-' && isdigit(str[i+2])){ //e-10 power
                        strncat(token, &str[i], 1); 
                        strncat(token, &str[i+1], 1);
                        i=i+2;
                        while(str[i]!= '\0'){
                            if (isalpha(str[i])  || !isdigit(str[i]) || isspace(str[i])){
                                printf("floating point: \"%s\"\n", token);
                                memset(token,0,strlen(token));
                                return i;
                            } else{
                                strncat(token, &str[i], 1);
                                i++;
                            }
                        }
                    }
                    else if ((str[i] == 'e' || str[i] == 'E') && str[i+1] == '+' && isdigit(str[i+2])){ //e+10 power
                        strncat(token, &str[i], 1); 
                        strncat(token, &str[i+1], 1);
                        i=i+2;
                        while(str[i]!= '\0'){
                            if (isalpha(str[i])  || !isdigit(str[i]) || isspace(str[i])){
                                printf("floating point: \"%s\"\n", token);
                                memset(token,0,strlen(token));
                                return i;
                            } else{
                                strncat(token, &str[i], 1);
                                i++;
                            }
                        }
                    }
                    else if ((str[i] == 'e' || str[i] == 'E') && isdigit(str[i+1])){
                        strncat(token, &str[i], 1);
                        i++;
                        while(str[i]!= '\0'){
                            if (isalpha(str[i])  || !isdigit(str[i]) || isspace(str[i])){
                                printf("floating point: \"%s\"\n", token);
                                memset(token,0,strlen(token));
                                return i;
                            } else{
                                strncat(token, &str[i], 1);
                                i++;
                            }
                        }
                    }
                    else if(!isdigit(str[i])){ //break if not a number
                        break;
                    } 
                    else {
                        strncat(token, &str[i], 1); 
                    i++;
                    }
                } if (strstr(token, "e") ||strstr(token, "E") ){
                printf("floating point: \"%s\"\n", token);
                memset(token,0,strlen(token)); //reset token for next time function runs
                return i;

                } else{
                printf("floating point: \"%s\"\n", token);
                memset(token,0,strlen(token)); //reset token for next time function runs
                return i;
                }
            }
            else if(str[i+1] == '8' || str[i+1] == '9'){ //not octal
                strncat(token, &str[i], 1);
                i++; 

                while (str[i]!= '\0'){
                    if (!isdigit(str[i])){
                        break;
                    } else{
                       strncat(token, &str[i], 1);
                        i++; 
                    }
                }

            printf("decimal integer: \"%s\"\n", token);
            memset(token,0,strlen(token)); //reset token for next time function runs
            return i;
            }
            else if (!isdigit(str[i])){ //break if not a number
                break;
                } else {
                        strncat(token, &str[i], 1); 
                        i++;
                    }
                }
                printf("octal integer: \"%s\"\n", token);
                memset(token,0,strlen(token)); //reset token for next time function runs
                return i;
            }
        }
        else if(isdigit(str[i]) && str[i+1] == '\0'){
            strncat(token, &str[i], 1);
            printf("decimal integer: \"%s\"\n", token);
            memset(token,0,strlen(token));
            i++;
        }
        else if(isdigit(str[i])){
            strncat(token, &str[i], 1);
            i++;
        } else {
            printf("decimal integer: \"%s\"\n", token);
            memset(token,0,strlen(token)); //reset token for next time function runs
            break;
        }
    }
    return i;
}

int main (int argc, char **argv){

  char str[strlen(argv[1])];
  strcpy(str, argv[1]);

  int i = 0;
  char *ptr = str;

  while (i < strlen(str)){
    if(isspace(*(ptr + i))){ // check if there's a space, if so move to next index
	    i++;
	}else if(str[i] == '\\'){
	  i+=2;	
	}	
	else if (isdigit(str[i])){ //check if char = number, if so call number function
	    i = numberFunc(str, i); // will change i to position(ie. int) that function returns
	} 
	else if (isalpha(str[i])){ //check if char = letter, if so call word function
	    i = wordFunc(str, i); // will change i to position(ie. int) that function returns
	} 
	else { //went through other test cases so char must be an operator
	    i = opFunc(str, i); // will change i to position(ie. int) that function returns
	}
}
  return 0;
}




















