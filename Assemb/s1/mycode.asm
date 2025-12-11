STACKSG SEGMENT STACK 'STACK'
    DW 32H DUP(0)       
STACKSG ENDS            

DATASG SEGMENT 'DATA'
    
    DATA_IN DB 25H,30H,50H,40H,60H 
    COPY1 DB 5 DUP(?)
    
DATASG ENDS            

CODESG SEGMENT 'CODE'
    ASSUME SS:STACKSG, DS:DATASG, CS:CODESG
MAIN PROC FAR
    MOV AX,DATASG        
    MOV DS,AX          
            
    LEA SI,DATA_IN
    LEA DI,COPY1
    MOV CL,5
   ;MOV CX,5   
  
 L1:MOV AL,[SI] 
    MOV [DI],AL
    INC SI
    INC DI
    DEC CL 
   ;LOOP L1 
    JNZ L1
  
    MOV AX,4C00H       
    INT 21H          
MAIN ENDP              
CODESG ENDS           
    END MAIN           
