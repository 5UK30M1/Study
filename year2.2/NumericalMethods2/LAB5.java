package  com.company;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

import java.util.ArrayList;


public class Main extends Application{
    static int N = 30;
    static double p = 2;
    static double R1 = 0.1;
    static double R2 = 0.5;
    static double delta = (R2-R1)/N;
    static double g = 8.0 * 100000;
    static double h = 500;
    static double Tinf = 20;
    static double T0 = 20;
    static double k = 60;
    static double alfa = 0.005;
    static double beta = 0.25;
    static int[] t = new int[]{5, 10, 15, 20, 25, 50};
    static double del = beta * delta * delta / alfa;
    static double Al, Ar;


    static double[][] Tgraf = new double[t.length][N+1];


    public static double[] solve(int Tfin){
        int Nt = (int)(Tfin/del);
        double dt = Tfin/Nt;

        double[] Tn = new double[N+1];
        double[] Tnp = new double[N+1];
        for (int i = 0; i < N+1; i++) {
            Tn[i] = T0;
        }

        for (int j = 1; j < Nt; j++) {
            for (int i = 1; i < N; i++) {
                Tnp[i] = Tn[i] * (1 - 2 * beta) +
                        Tn[i - 1] * (1. - ((p * delta) / 2. / (R1 + i * delta))) * beta +
                        Tn[i + 1] * (1. + ((p * delta) / 2. / (R1 + i * delta))) * beta +
                        (g * delta * delta / k) * beta;
            }

            Tnp[0] = T0 ;

            Ar = Tn[N - 1] + 2 * delta * h / k * Tinf - 2 * delta * h / k * Tn[N];
            Tnp[N] = Tn[N] * (1 - 2 * beta) +
                    Tn[N - 1] * (1. - p * delta / 2. / R2) * beta +
                    Ar * (1. + p * delta / 2. / R2) * beta +
                    (g * delta * delta / k) * beta;

            for (int i = 0; i < N+1; i++) {
                Tn[i] = Tnp[i];
            }
        }
        return Tn;
    }

    public static void main(String... args){
        for (int tk = 0; tk < t.length; tk++) {
            Tgraf[tk] = solve(t[tk]);
        }
        launch(args);
    }


    public  void outputTable(double[] T){
        System.out.printf("|   x   |          T           |\n");
        for (int i = 0; i <= N; i++) {
            System.out.printf("| %5.3f | %18.16f |\n", 0.2 + i * delta, T[i]);
        }
        System.out.println();
    }

    @Override
    public void start(Stage stage) {
        stage.setTitle("Line Chart Sample");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X Axis");
        //creating the chart
        final LineChart<Number,Number> lineChart =
                new LineChart<Number,Number>(xAxis,yAxis);

        lineChart.setTitle("DE graph");
        lineChart.setMinWidth(1200);
        lineChart.setMinHeight(700);
        lineChart.setCreateSymbols(false);


        //Prepare XYChart.Series objects by setting data
        XYChart.Series series1 = new XYChart.Series();
        series1.setName("5");
        XYChart.Series series2 = new XYChart.Series();
        series2.setName("10");
        XYChart.Series series3 = new XYChart.Series();
        series3.setName("15");
        XYChart.Series series4 = new XYChart.Series();
        series4.setName("20");
        XYChart.Series series5 = new XYChart.Series();
        series5.setName("25");
        XYChart.Series series6 = new XYChart.Series();
        series6.setName("50");



        for (int i = 0; i <= N; i++) {
            series1.getData().add(new XYChart.Data(R1+i*delta, Tgraf[0][i]));
        }

        for (int i = 0; i <= N; i++) {
            series2.getData().add(new XYChart.Data(R1+i*delta, Tgraf[1][i]));
        }

        for (int i = 0; i <= N; i++) {
            series3.getData().add(new XYChart.Data(R1+i*delta, Tgraf[2][i]));
        }

        for (int i = 0; i <= N; i++) {
            series4.getData().add(new XYChart.Data(R1+i*delta, Tgraf[3][i]));
        }

        for (int i = 0; i <= N; i++) {
            series5.getData().add(new XYChart.Data(R1+i*delta, Tgraf[4][i]));
        }

        for (int i = 0; i <= N; i++) {
            series6.getData().add(new XYChart.Data(R1+i*delta, Tgraf[5][i]));
        }


        //Setting the data to Line chart
        lineChart.getData().add(series1);
        lineChart.getData().add(series2);
        lineChart.getData().add(series3);
        lineChart.getData().add(series4);
        lineChart.getData().add(series5);
        lineChart.getData().add(series6);


        //Creating p Group object
        Group root = new Group(lineChart);

        //Creating p scene object
        Scene scene = new Scene(root, 1280,720);

        //Setting title to the Stage
        stage.setTitle("Laba5");
        //Adding scene to the stage
        stage.setScene(scene);

        //Displaying the contents of the stage
        stage.show();

    }
}
