 PAGE 110,100
 TITLE 'ADD35+35'

STACKSG SEGMENT STACK 'STACK'
    DW 32H DUP(0)       
STACKSG ENDS            

DATASG SEGMENT 'DATA'
    DATA1 DB 35H    ; 35
    DATA2 DB 32H    ; 32
    DATA3 DB ?      ;must be 67
DATASG ENDS            

CODESG SEGMENT 'CODE'
    ASSUME SS:STACKSG, DS:DATASG, CS:CODESG
MAIN PROC FAR
    MOV AX,DATASG        
    MOV DS,AX          
                       
    MOV BL,DATA1       
    MOV AL,DATA2       
    ADD AL,BL          
    MOV DATA3,AL       
                    
    MOV AX,4C00H       
    INT 21H          
MAIN ENDP              
CODESG ENDS           
    END MAIN           
