#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

const char* keys = 
{
	"{i|input| |The source image}"
	"{o|outdir| |The output directory}"
};

int main(int argc, const char** argv)
{
	cv::CommandLineParser parser(argc, argv, keys);
	std::string infile = parser.get<std::string>("input");
	std::string outdir = parser.get<std::string>("outdir");
	std::string cascade_file = "haarcascade_frontalface_alt.xml";

	cv::CascadeClassifier cascade;
	if (!cascade.load(cascade_file))
		return -1;

	cv::Mat src = cv::imread(infile);
	if (src.empty())
	{
		std::cout << cv::format("Error: cannot load source image!\n");
		return -1;
	}

	cv::Mat gray;
	cv::cvtColor(src, gray, CV_BGR2GRAY);
	cv::equalizeHist(gray, gray);

	std::vector<cv::Rect> faces;
	cascade.detectMultiScale(gray, faces, 1.2, 3);

	std::cout << cv::format("0, %s (%dx%d)\n", infile.c_str(), src.cols, src.rows);

	cv::Mat src_copy = src.clone();
	for (int i = 0; i < faces.size(); i++)
	{
		std::string outfile(cv::format("%s/face-%d.jpg", outdir.c_str(), i+1));
		cv::Rect r = faces[i];
		cv::rectangle(src, r, CV_RGB(0,255,0), 2);
		cv::imwrite(outfile, src_copy(r));
		cv::imwrite(infile, src);
		std::cout << cv::format("%d, %s (%dx%d)\n", i+1, outfile.c_str(), r.width, r.height);
	}

	return 0;
}

