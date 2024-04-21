#include "../includes/fractol.h"

typedef struct s_complex
{
    double real; // x
    double i; //y

} t_complex;


int main(void)
{
    t_complex z;
    t_complex c;
    double tmp_real;

    z.real = 0;
    z.i = 0;

    c.real = 5;
    c.i = 2;
    int i = 0;
    while( i < 42){
        tmp_real = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.real * z.i;

        z.real = tmp_real;

        z.real += c.real;
        z.i += c.i;

        printf("iteração n -> :%d, real: %f imaginary: %f\n", i, z.real, z.i); 
        i++; 
    }
}