package com.company;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

class DU
{
    private double y, k0, k1, k2, k3, k4, k5;
    DU() { this.y = 1.0; }

    void acceleration(double x, double h) {
        k1 = func(x, RK4(x - h, h));
        k2 = func(x, RK4(x - 2*h, h));
        k3 = func(x, RK4(x - 3*h, h));
        k4 = func(x, RK4(x - 4*h, h));
        k5 = func(x, RK4(x - 5*h, h));
    }

    double gety(){return y;}

    double func(double x, double y) {
        return (y / x) * Math.log(y / x);
    }

    void AB6(double x, double h){
        k0 = func(x, y);
        this.y = this.y + h / 1440. * (4277 * k0 - 7923 * k1 + 9982 * k2 - 7298 * k3 + 2877 * k4 - 475 * k5);
        k5 = k4;
        k4 = k3;
        k3 = k2;
        k2 = k1;
        k1 = k0;
    }

    double RK4(double x, double h) {
        double k1;
        double k2;
        double k3;
        k1 = h * func(x, y);
        k2 = h * func(x + h / 2., y + k1 / 2.);
        k3 = h * func(x + h / 2., y + k2 / 2.);
        return this.y + 1. / 6. * (k1 + 2 * k2 + 2 * k3 + h * func(x + h, y + k3));
    }

    void RK4E(double x, double h) {
        double k0 = y;
        double k1, k2, k3, z;
        k1 = h * func(x, y);
        this.y = k0 + k1/2.;
        z = x + h/2.;
        k2 = func(z, y) * h;
        this.y = k0 + k2/2.;
        k3 = h * func(z,y);
        this.y = k0 + k3;
        z = x + h;
        this.y = k0 + 1. / 6. * (k1 + 2 * k2 + 2 * k3 + h * func(z, y));
    }

    double ans_sample(double x)
    {
        return x * Math.exp(1 - x);
    }

    void tout(double x) {
        double e = Math.abs(this.ans_sample(x) - this.y);
        System.out.format("y(%.4f) = %.16f  eps = %.16f  EPS = %.4f %% ", x, this.y, e,  Math.abs(100 * e / this.y)) ;
    }

    void sout(double x) { System.out.format("  sample y((%.4f) = %.16f\n",x, this.ans_sample(x)); }
}

public class Main extends Application {
    @Override public void start(Stage stage) {
        double a = 1.0;
        double b = 3.0;
        double h = 0.2/25;
        DU obj1 = new DU();
        DU obj2 = new DU();
        double x;
        int nt = (int)((b - a) / h);
        h = ((b - a) / nt);
        obj1.acceleration(a,h);
        stage.setTitle("Line Chart Sample");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X Axis");
        //creating the chart
        final LineChart<Number,Number> lineChart =
                new LineChart<Number,Number>(xAxis,yAxis);

        lineChart.setTitle("DE graph");
        lineChart.setCreateSymbols(false);
        XYChart.Series series1 = new XYChart.Series();
        XYChart.Series series2 = new XYChart.Series();
        XYChart.Series series3 = new XYChart.Series();
        series1.setName("My AB6");
        series2.setName("My RK4");
        series3.setName("Real Ans");

        for(int i = 1; i <= nt; i++) {
            x = a + i*h;
            obj1.AB6(x,h);
            obj2.RK4E(x,h);
            System.out.print("1) ");
            //obj3.RK4(x,h);
            //obj3.tout(x);
            //obj3.sout(x);
            obj1.tout(x);
            System.out.print("  2) ");
            obj2.tout(x);
            //System.out.println("\n");
            obj1.sout(x);
            series1.getData().add(new XYChart.Data(x, obj1.gety()));
            series2.getData().add(new XYChart.Data(x, obj2.gety()));
            series3.getData().add(new XYChart.Data(x, obj2.ans_sample(x)));
        }

        Scene scene  = new Scene(lineChart,1280,720);
        lineChart.getData().add(series1);
        lineChart.getData().add(series2);
        lineChart.getData().add(series3);

        stage.setScene(scene);
        stage.show();
    }
}
