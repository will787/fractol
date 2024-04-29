/* 

#include "../includes/fractol.h"


// z = z^2 - C* i;

// se o numero complexo estiver numa crescente infinita logo ele estará fora do desenho de mandelbrot
// agora se ele alternar o valor dele ficando entre 0 e -1, ele estará dentro do desenho

// então quando ele está numa crescente infinita diferente de -1 ele estará fora do desenho, 
//caso contrário entrará no desenho ficando no loop entre 0 e -1

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

    c.real = 0.25;
    c.i = 0.4;
    int i = 0;
    while(i < WIDTH){
        tmp_real = (z.real * z.real) - (z.i * z.i); //z.x^2 - z.y^2
        z.i = 2 * z.real * z.i;

        z.real = tmp_real;

        z.real += c.real;
        z.i += c.i;

        printf("iteração n -> :%d, real: %f imaginary: %f\n", i, z.real, z.i); 
        i++;
    }
}


//Zn = Zn-1^2 + c

*/