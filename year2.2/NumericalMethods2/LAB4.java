package com.company;

class Sphere {
    int N = 40;
    double Ra = 0.1;
    double Rb = 0.5;
    double g = 8.0e5;
    int Ta = 20;
    int T = 20;
    int h = 500;
    int k = 60;
    int p = 2;
    double delta = (Rb - Ra) / N;
    int coun1 = N;
    double X1;
    double Y1;
    double mas_b[] = new double[N + 1];
    double mas_a[] = new double[N + 1];
    double mas_c[] = new double[N + 1];
    double mas_d[] = new double[N + 1];
    double mas_T[] = new double[N + 1];

    Sphere(){

        for (int i = 1; i < N; i++)
        {
            mas_a[i] = (1 - (p*delta / 2.) / (Ra + i*delta));
            mas_b[i] = -2;
            mas_c[i] = (1 + (p*delta / 2.) / (Ra + i*delta));
            mas_d[i] = -g *delta * delta / k;
        }

        mas_b[0] = 1;
        mas_c[0] = 0;
        mas_d[0] = Ta;

        mas_b[N] = -2 -(2*delta*h)/k *(1+(p*delta/2)/Rb);
        mas_a[N] = 2;
        mas_d[N] = -g*delta*delta / k - 2 * h*delta /k * T*(1+(p*delta/2)/Rb);

    }

    void Thomas()
    {
        for (int i = 1; i<N+1; i++) {
            mas_b[i] = mas_b[i] - (mas_a[i] * mas_c[i - 1]) / mas_b[i - 1];
            mas_d[i] = mas_d[i] - (mas_a[i] * mas_d[i - 1]) / mas_b[i - 1];
        }

        mas_T[N] = mas_d[N] / mas_b[N];
        for (int i = N - 1; i >= 0; i--)
            mas_T[i] = (mas_d[i] - mas_c[i] * mas_T[i + 1]) / mas_b[i];
    }

    void Out()
    {
        double krok = 0;

        System.out.format("|  r    |    T    |\n");
        for (int i = 0; i <= N; i++)
        {
            System.out.format("| %.3f | %7.3f |\n", Ra + krok, mas_T[i]);
            krok += delta;
        }

    }
}

public class Main {

    public static void main(String[] args) {
        Sphere obj = new Sphere();
        obj.Thomas();
        obj.Out();
    }
}
