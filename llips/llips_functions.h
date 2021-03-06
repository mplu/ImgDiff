/****************************************************************/
/* Light Library for Image ProcesS                              */
/* File : llips_constrastdetect.h                               */
/* Description :                                                */
/*   About contrast and edge detection on image                 */
/*                                                              */
/* Author : MPE                                                 */
/*                                                              */
/****************************************************************/

/****************************************************************/
/**           Define                                            */
/****************************************************************/

/****************************************************************/
/**           Global variables                                  */
/****************************************************************/

/****************************************************************/
/**           Prototypes                                        */
/****************************************************************/
CPU_INT32U min(CPU_INT32U a,CPU_INT32U b);
CPU_INT32U max(CPU_INT32U a,CPU_INT32U b);
CPU_INT08U **createTableINT08U(CPU_INT16S nbLin, CPU_INT16S nbCol);
CPU_FP64 **createTableFP64(CPU_INT16S nbLin, CPU_INT16S nbCol);
CPU_VOID freeTableINT08U(CPU_INT08U **tab);
CPU_VOID freeTableFP64(CPU_FP64 **tab);
int compare (const CPU_VOID * a, const CPU_VOID * b);
