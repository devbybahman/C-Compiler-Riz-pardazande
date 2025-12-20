STACKSG SEGMENT STACK 'STACK'
    DW 32H DUP(0)       
STACKSG ENDS            

DATASG SEGMENT 'DATA'
    
    DATA1 DB 'mY NAME is Bahman'   ;17 bit with space
    DATA2 DB 17 DUP(?)
    
DATASG ENDS            

CODESG SEGMENT 'CODE'
    ASSUME SS:STACKSG, DS:DATASG, CS:CODESG
MAIN PROC FAR
    MOV AX,DATASG        
    MOV DS,AX          
            
    LEA SI,DATA1     ;address dt1 to SI
    LEA DI,DATA2     ;address dt2 to DI
    MOV CX,17
L1:MOV AL,[SI]      
    CMP AL,'a'   ; compare AL and 'a'=97   
    JB OVER      ; if ascii code AL was kamtar az 'a' bood yani ya addad ya harf bozorg ya space=32  : we did not need to change to big   so jump to OVER : save it 
    CMP AL,'z'   ; z=122  
    JA OVER      ; if was bozorgtar az 122 bood pas karish nadarim  
    and AL,11011111B ;if resid inja pas harf bozorg boode 
    ;baraye tabdil be horof kochak => OR AL,00100000B 
 ;save results    
OVER:MOV [DI],AL  
    INC SI
    INC DI
    LOOP L1
    
 
    MOV AX,4C00H       
    INT 21H          
MAIN ENDP              
CODESG ENDS           
    END MAIN           
