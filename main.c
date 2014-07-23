/****************************************************************/
/* File : llips_exemple.c                                       */
/* Description :                                                */
/*   Main functions to demonstrate LLIPS possibility            */
/*                                                              */
/* Author : MPE                                                 */
/*                                                              */
/****************************************************************/

/****************************************************************/
/**           Includes                                          */
/****************************************************************/
#include "includes.h"

/****************************************************************/
/**           Global variables                                  */
/****************************************************************/

/****************************************************************/
/**           Functions                                         */
/****************************************************************/
int main(int argc, char *argv[])
{
    CPU_INT16U bench_counter = 1000;
    clock_t start, finish;
    double duration;

    CPU_INT16S mouvement = 0;

    t_img img_in1,img_in2,img_out1;
    CPU_CHAR img_diff_1_2=0;
    t_area change_1_2;

    CPU_CHAR inputfilename1[32];
    CPU_CHAR inputfilename2[32];

    start = clock();
    int tolerance, quantity;
    if (argc >= 3)
    {
        sscanf (argv[1],"%s",inputfilename1);
        sscanf (argv[2],"%s",inputfilename2);
        //getting filename
        if (argc >= 5)
        {

            //getting comparison parameters
            sscanf (argv[3],"%d",&tolerance);
            sscanf (argv[4],"%d",&quantity);
            if ((tolerance < 0) || (tolerance > 100))
            {
                printf ("tolerance %d out of bound, using default value : %d\n",tolerance,DEFAULT_TOLERANCE);
                tolerance = DEFAULT_TOLERANCE;
            }
            if ((quantity < 0) || (quantity > 1000))
            {
                printf ("quantity %d out of bound, using default value : %d\n",quantity,DEFAULT_QUANTITY);
                quantity = DEFAULT_QUANTITY ;

            }
        }else
        {
            tolerance = DEFAULT_TOLERANCE;
            quantity = DEFAULT_QUANTITY;
        }
    }else
    {

        sprintf((char *)inputfilename1,IMG_IN_1);
        sprintf((char *)inputfilename2,IMG_IN_2);
        tolerance = DEFAULT_TOLERANCE;
        quantity = DEFAULT_QUANTITY;
        //printf("USAGE: %s <tolerance in percent> <quantity of pixel in perthousand> [opt:DEBUG]\nIncorrect Using default value\n",argv[0]);
    }

    init_img(&img_in1);
    init_img(&img_in2);
    init_img(&img_out1);

    load_img(inputfilename1, &img_in1);
    load_img(inputfilename2, &img_in2);

    while(bench_counter--)
    {

        img_diff_1_2 = search_diff((CPU_CHAR)tolerance,(CPU_CHAR)quantity,&img_in1,&img_in2,&img_out1,&change_1_2);
        if((img_diff_1_2 & DIFF_HIGH_QUANTITY)!=0)
        {
            //calculate center of diff aera, relatively to image center
            //mouvement on left is negative
            //mouvement on left is positive
            mouvement = (((change_1_2.BotLeft.x/2 + change_1_2.BotRight.x/2)*100)/img_in1.wi)-50 ;

        }else
        {

            mouvement = 0;
        }

    }
    printf( "%d\n", mouvement );


/*********************************************************************************/
/*********************************************************************************/
/*********************************************************************************/
/*********************************************************************************/
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f\n", duration );

    return 0;
}

