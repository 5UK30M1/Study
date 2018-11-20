package com.company;

class Matrix{
    private double a[];
    private double b[];
    private double c[];
    private double d[];
    private double T[];

    Matrix(double tmp[],double con){
        a = new double[tmp.length];
        b = new double[tmp.length];
        c = new double[tmp.length];
        d = new double[tmp.length];
        T = new double[tmp.length];
        a[2] = 0.4;
        b[1] = -6.0 * con;
        c[1] = 0.5;
        for(int i = 1; i < tmp.length; i++) {
            if(i > 2) a[i] = a[i - 1] + 0.1;
            if(i > 1) b[i] = b[i - 1] - (0.1 * con);
            if(i > 1 && i < tmp.length - 1) c[i] = c[i - 1] + 0.2;
            d[i] = tmp[i];
        }
    }
    void Thomas(){
        for(int i = 2; i < a.length; i++){
            b[i] = b[i] - a[i] * c[i - 1] / b[i - 1];
            d[i] = d[i] - a[i] * d[i - 1] / b[i - 1];
        }
        T[a.length - 1] = d[a.length - 1] / b[a.length - 1];
        for (int i = a.length - 2; i >= 1; i--) {
            T[i] = (d[i] - c[i] * T[i + 1]) / b[i];
        }
    }
    void asnOut(){
        System.out.println();
        for (int i = 1; i < T.length; i++) {
            System.out.println("T(" + i + ") = " + T[i]);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        double c1 = 1.0;
        double T1[] = {0, 1.6, 1.97, 2.36, 2.71, 3.02, 3.29, 3.52, 3.71, 3.86, 6.96};
        Matrix obj1 = new Matrix(T1,c1);
        obj1.Thomas();
        obj1.asnOut();
        double c2 = 0.1;
        double T2[] = {0, -0.020, -0.226, -0.430, -0.692, -1.012, -1.390, -1.826, -2.320, -2.872, -0.492};
        Matrix obj2 = new Matrix(T2,c2);
        obj2.Thomas();
        obj2.asnOut();
        double c3 = 0.001;
        double T3[] = {0, -0.19820, -0.46756, -0.73690, -1.06622, -1.45552, -1.90480, -2.41406, -2.98330, -3.61252,
        -1.31172};
        Matrix obj3 = new Matrix(T3,c3);
        obj3.Thomas();
        obj3.asnOut();
    }
}
