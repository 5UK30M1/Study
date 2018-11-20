package com.company;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

class SDU
{
	private double y[];
	SDU(int n)
	{
		this.y = new double[n];
		y[0] = 0.0;
		y[1] = 1.0;
		y[2] = 1.0;
	}

	double func(int i, double x, double yt) {
		yt -= y[i];
		switch(i) {
			case 0: return (y[1] + yt);
			case 1: return -(y[0] + yt);
			case 2: return Math.exp(x);
			default: return 0;
		}
	}


	void RK4(double x, double h) {
		double k1[] = new double[y.length];
		double k2[] = new double[y.length];
		double k3[] = new double[y.length];
		for (int i = 0; i < y.length; i++) {
			k1[i] = h * func(i, x, y[i]);
			k2[i] = h * func(i,x + h / 2., y[i] + k1[i] / 2.);
			k3[i] = h * func(i,x + h / 2., y[i] + k2[i] / 2.);
			y[i] = y[i] + 1. / 6. * (k1[i] + 2 * k2[i] + 2 * k3[i] + h * func(i,x + h, y[i] + k3[i]));
		}
	}


	double ans_sample(int i, double x)
	{
		switch(i) {
			case 0: return Math.sin(x);
			case 1: return Math.cos(x);
			case 2: return Math.exp(x);
			default: return 0;
		}
	}

	void tout(double x) {
		double e[] = new double[y.length];
		for (int i = 0; i < y.length; i++) {
			e[i] = Math.abs(this.ans_sample(i, x) - y[i]);
			System.out.format("y%d(%.4f) = %.16f  eps = %.16f  EPS = %.4f %% \n",i,  x, y[i], e[i], Math.abs(100 * e[i] / y[i]));
		}
	}

	void sout(double x) {

		for (int i = 0; i < y.length; i++) {
			System.out.format("  sample y%d((%.4f) = %.16f\n", i, x, this.ans_sample(i,x));
		}
	}
}


class DU
{
	private double y;
	DU()
	{
		this.y = 1.0;
	}

	double gety(){return y;}

	double func(double x, double y) {
		return (y / x) * Math.log(y / x);
	}

	void TR2(double x, double h){
		double yt;
		yt = this.y + h * 1/(y * x);
		this.y = this.y + h / 2. * (func(x,y) + func(x + h, yt));
	}

	void RK4(double x, double h) {
		double k1;
		double k2;
		double k3;
		k1 = h * func(x, y);
		k2 = h * func(x + h / 2., y + k1 / 2.);
		k3 = h * func(x + h / 2., y + k2 / 2.);
		this.y = this.y + 1. / 6. * (k1 + 2 * k2 + 2 * k3 + h * func(x + h, y + k3));
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
		this.y = k0 + 1. / 6. * (k1 + 2 * k2 + 2 * k3 + h * func(z,y));
	}

	double ans_sample(double x)
	{
		return x * Math.exp(1 - x);
	}

	void tout(double x) {
		double e = Math.abs(this.ans_sample(x) - this.y);
		System.out.format("y(%.4f) = %.16f  eps = %.16f  EPS = %.4f %% ", x, this.y, e,  Math.abs(100 * e / this.y)) ;
	}

	void sout(double x) { System.out.format("  sample y(%.4f) = %.16f\n",x, this.ans_sample(x)); }
}

public class Main extends Application {

		@Override public void start(Stage stage) {
			DU obj1 = new DU();
			DU obj2 = new DU();
			double a = 1.0;
			double b = 3.0;
			double h = 0.2/25;
			double x;
			int nt = (int)((b - a) / h);
			h = ((b - a) / nt);
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
			series1.setName("My TR2");
			series2.setName("My RK4");
			series3.setName("Real Ans");
			for(int i = 1; i <= nt; i++)
			{
				x = a + i*h;
				obj1.TR2(x,h);
				obj2.RK4(x,h);
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
