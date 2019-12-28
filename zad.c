#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double reverse_f1(double x)
{
    return log(exp(-x)+2);
}
double reverse_f2(double x)
{
    return exp((cos(log(x))-sin(log(x)))/2);
}
double f1(double x)
{
    return exp(x)-exp(-x)-2;
}
double f2(double x)
{
    return sin(log(x))-cos(log(x))+2*log(x);
}


double derivative(double (*f)(double), double x)
{
   const double delta = 1.0e-6;
    double x1 = x - delta;
    double x2 = x + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}

double dih(double (*F)(double), double a, double b,double eps) 
{
    double c;
    int i = 0;
    //if(F(a)*F(b)>0)
    //{
      //  printf("on line not x");
        //return 0;
    //}
    while (fabs(a - b) > eps&& i < 200) {
        c = (a + b) / 2;
        if ((F(a) * F(c)) > 0) 
        {
            a = c;
        }
        if ((F(b) * F(c)) > 0) 
        {
            b = c;
        }
        i++;
    }
    c = (a + b) / 2;
    return c;
}

double newton(double(*F)(double), double a, double b,double eps)
{
    double x = ((a + b) / 2);
    double x0;
    double res;
    int iter = 0;
    const double delta = 1.0e-6;
    double dif = (derivative(F,(a+delta))-derivative(F,(a-delta))*(a+2*delta-a+2*delta))/pow((a+2*delta-a+2*delta),2);
    if (F(a)*dif <= 0 && F(b)*dif <=0)
        return (NAN);
    do
    {
        res = x;
        x = (x - (F(x) / derivative(F, x))) ;
        iter++;
    } while (fabs(res - x) > eps && iter < 20000);
    return x;

    double c;
    if(F(a)*dif>0||F(b)*dif>0)
    {
        
         c = ((a + b) / 2);
        int i = 0;
        while (i < 200) 
        {
            c = (c - (F(c) / derivative(F, c))) ;
            i++;
            if((F(c))<eps)
            {
                return c;
            }
        }
    }
    else
    {
        printf("Method not converge");
        return 0;
    }
return c;
}

double iter(double(*F)(double), double a, double b, double eps)
{
    double x = (a + b) / 2;
    double res;
    int iter = 0;
    if (fabs(derivative(F, x))>=1)
        return 0;
    do
    {
        res = x;
        x = F(x);
        iter++;
    } while (fabs(x - res) >= eps && iter < 20000);
    return x;
}

int main(void)
{
    double a1=0,b1=1,a2=1,b2=3, eps1 = 0.001, eps2 = 0.001;
    double(*function)(double x);
    function = f1;
    if(f1(a1)*f1(b1)>0)
    {
        return 0;
    }
    if(f2(a2)*f2(b2)>0)
    {
        return 0;
    }
    printf("dihotomia1  fu %f\n",dih(function, a1, b1, eps1) );
    printf("newton1     fu %f\n", newton(function, a1, b1, eps1));
    function = reverse_f1;
    printf("iter1       fu %f \n", iter(function, a1, b1, eps1));
    function = f2;
    printf("dihotomia2  fu %f\n",dih(function, a2, b2, eps2) );
    printf("newton2     fu %f\n", newton(function, a2, b2, eps2));
    function = reverse_f2;
    printf("iter2     fu %f \n", iter(function, a2, b2, eps2));
    return 0;
}