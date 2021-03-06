#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include<opencv2/videoio.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void processFrameAndUpdateGUI();

public:
    explicit MainWindow(QWidget *parent = 0);
    double getCurrentFrame();
    double getNumberOfFrames();
    double getFrameRate();

    ~MainWindow();

private slots:
    void on_loadButton_clicked();

    void on_playButton_clicked();

    void on_pushButton_3_clicked();

    QString getFormattedTime(int timeInSeconds);

    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderReleased();

    void on_horizontalSlider_sliderMoved(int position);
    void setCurrentFrame( int frameNumber);


    void on_actionOpen_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    cv::Mat matOriginal;
    cv::VideoCapture capWebcam;
    QImage qimgOriginal;
    QTimer* qtimer;
};

#endif // MAINWINDOW_H
