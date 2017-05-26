#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{



    Mat input = imread("images/hand.jpg");

    Mat gray;
    cvtColor(input, gray, CV_RGB2GRAY);

    Mat element = getStructuringElement( MORPH_RECT, Size(3,3 ), Point( 0, 0 ) );
    erode(gray,gray, element);

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    findContours( gray, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );

    Mat output;
    cvtColor(gray, output, CV_GRAY2RGB);

    int contour_index = -1;
    int contour_min = 0;
    for(int i = 0; i < contours.size(); i++){
        if(contours.at(i).size()>contour_min){
            contour_min = contours.at(i).size();
            contour_index = i;
        }
    }

    drawContours( output, contours, contour_index, Scalar(255,0,0), 2 );


    imshow("Contour", output);


    waitKey(0);


    return 0;
}
