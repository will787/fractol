#include "../includes/fractol.h"

int main(int argc, char **argv)
{
    t_f *frac;
    frac = (t_f *)malloc(sizeof(t_f));
    if(argc != 2)
        return 0;
    validate(argv[1],frac);  
    window_fractol(frac, argv[1]);
    return(0);
}