#include <itba.h>


#define ITBA_DIM 45

static char * itbaLogo[] = {
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"**************************::::-*-:.::::::::::=****-:.:.::::::-=************::::******************************************",
"***************************:    *:             *+**              =*********     :****************************************",
"****************************    *=====-    :=====**    -====-     *******=       ****************************************",
"*******************************+******+    -******=    +*****:    ******+    *    =**************************************",
"***************************.-+********+    -******=    **--:.   :+*****+    +**.   =*************************************",
"***************************    -******+    -******=    +*+:    :=******.   -***+    +************************************",
"***************************    .******:    -******=    :+**=-.    =***:              +***********************************",
"***************************    .*******    ******=     ******:    +*-               .+***********************************",
"***************************    .******+    +******=    -+++++*-    *=    :------=*:   .**********************************",
"***************************    .******+    =******=              .++    -**********.   :*********************************",
"***************************....:******+....=******+..........::+***:...:***********+....=********************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
"*************************************************************************************************************************",
};


 void printLogo(){
    call_sys_clear();
    for(int i =0; i < ITBA_DIM; i++){
        call_sys_drawWord(itbaLogo[i]);
        call_sys_commandEnter();
    }
 }