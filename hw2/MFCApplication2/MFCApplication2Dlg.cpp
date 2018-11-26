
// MFCApplication2Dlg.cpp : 實作檔
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "opencv2\opencv.hpp"
#include <cstdio>

#pragma warning(disable:4996)

using namespace cv;
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 對話方塊



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, adad);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication2Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication2Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication2Dlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 訊息處理常式

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void drawHistImg(const Mat &src, Mat &dst) {
	int histSize = 256;
	float histMaxValue = 0;
	for (int i = 0; i<histSize; i++) {
		float tempValue = src.at<float>(i);
		if (histMaxValue < tempValue) {
			histMaxValue = tempValue;
		}
	}

	float scale = (0.9 * 256) / histMaxValue;
	for (int i = 0; i<histSize; i++) {
		int intensity = static_cast<int>(src.at<float>(i)*scale);
		line(dst, Point(i, 255), Point(i, 255 - intensity), Scalar(0));
	}
}

void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src = imread("./images/plant.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	int histSize = 256;
	float range[] = { 0, 255 };
	const float* histRange = { range };
	Mat histImg;
	calcHist(&src, 1, 0, Mat(), histImg, 1, &histSize, &histRange);

	Mat showHistImg(256, 256, CV_8UC1, Scalar(255));
	drawHistImg(histImg, showHistImg);
	imshow("window1", src);
	imshow("window2", showHistImg);
}


void CMFCApplication2Dlg::OnBnClickedButton2()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src = imread("./images/plant.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst;
	equalizeHist(src, dst);
	int histSize = 256;
	float range[] = { 0, 255 };
	const float* histRange = { range };
	Mat histImg;
	calcHist(&dst, 1, 0, Mat(), histImg, 1, &histSize, &histRange);

	Mat showHistImg(256, 256, CV_8UC1, Scalar(255));
	drawHistImg(histImg, showHistImg);
	imshow("window1", dst);
	imshow("window2", showHistImg);
}

void CMFCApplication2Dlg::OnBnClickedButton3()
{
	Mat src, src_gray;
	src = imread("./images/q2_train.jpg", CV_LOAD_IMAGE_COLOR);
	cvtColor(src, src_gray, CV_BGR2GRAY);
	GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
	vector<Vec3f> circles;

	HoughCircles(src_gray, circles, CV_HOUGH_GRADIENT, 1, 40, 58, 16, 14, 26);

	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0);
	}

	namedWindow("Hough Circle Transform Demo", CV_WINDOW_AUTOSIZE);
	imshow("Hough Circle Transform Demo", src);

}

const int hueBinMaxValue = 175;
int hueBinValue = 175;
void CMFCApplication2Dlg::OnBnClickedButton4()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src, src_gray;
	src = imread("./images/q2_train.jpg", CV_LOAD_IMAGE_COLOR);
	imshow("first", src);
	cvtColor(src, src_gray, CV_BGR2GRAY);
	GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
	vector<Vec3f> circles;

	Mat mask = Mat::zeros(src.rows, src.cols, CV_8UC1);
	for (int i = 0; i<mask.cols; i++)
		for (int j = 0; j<mask.rows; j++)
			mask.at<uchar>(Point(i, j)) = 0;

	HoughCircles(src_gray, circles, CV_HOUGH_GRADIENT, 1, 40, 58, 16, 14, 26);

	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
//		circle(mask, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		circle(mask, center, radius, Scalar(255, 255, 255),-1);
	}

	Mat image;
	src.copyTo(image, mask);
	imshow("Hough Circle Transform Demo", image);

	Mat  hsvImage;
	cvtColor(image, hsvImage, COLOR_BGR2HSV);
	

	Mat hue;
	hue.create(hsvImage.size(), hsvImage.depth());
	int ch[] = { 0, 0 };
	mixChannels(&hsvImage, 1, &hue, 1, ch, 1);
	MatND hist;

	int histsize = MAX(hueBinValue, 2);
	float hue_range[] = { 5,180 };
	const float* ranges = { hue_range };
	calcHist(&hue, 1, 0, Mat(), hist, 1, &histsize, &ranges, true, false);
	normalize(hist, hist, 0, 255, NORM_MINMAX, -1, Mat());

	int w = 400;
	int h = 400;
	int bin_w = cvRound((double)w / histsize);
	Mat histImage = Mat::zeros(w, h, CV_8UC3);
	for (int i = 0; i < hueBinValue; i++)
	{
		rectangle(histImage, Point(i*bin_w, h), Point((i + 1)*bin_w, h - cvRound(hist.at<float>(i)*h / 255.0)), Scalar(255, 255, 255), -1);
	}
	imshow("HistImage", histImage);

}

void CMFCApplication2Dlg::OnBnClickedButton5()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src, src_gray;
	src = imread("./images/q2_train.jpg", CV_LOAD_IMAGE_COLOR);
	imshow("first", src);
	cvtColor(src, src_gray, CV_BGR2GRAY);
	GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
	vector<Vec3f> circles;

	Mat mask = Mat::zeros(src.rows, src.cols, CV_8UC1);
	for (int i = 0; i<mask.cols; i++)
		for (int j = 0; j<mask.rows; j++)
			mask.at<uchar>(Point(i, j)) = 0;

	HoughCircles(src_gray, circles, CV_HOUGH_GRADIENT, 1, 40, 58, 16, 14, 26);

	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(mask, center, radius, Scalar(255, 255, 255), -1);
	}

	Mat image;
	src.copyTo(image, mask);



	Mat  hsvImage;
	cvtColor(image, hsvImage, COLOR_BGR2HSV);

	int hueBinNum = 30;
	int saturationBinNum = 32;
	int histSize[] = { hueBinNum, saturationBinNum };
	float hueRanges[] = { 103, 121 };
	float saturationRanges[] = { 48, 190 };
	const float* ranges[] = { hueRanges, saturationRanges };
	MatND dstHist;
	int channels[] = { 0, 1 };
	calcHist(&hsvImage,1,channels,Mat(),dstHist,2,histSize,ranges,true,false);
	normalize(dstHist, dstHist, 0, 255, NORM_MINMAX, -1, Mat());
	MatND backProjection;
	Mat fimg;
	fimg = imread("./images/q2_test.jpg", CV_LOAD_IMAGE_COLOR);
	cvtColor(fimg, fimg, COLOR_BGR2HSV);
	
	calcBackProject(&fimg, 1, channels, dstHist, backProjection, ranges, 1, true);

	imshow("BackProjection", backProjection);
}

//		3.1
int imagewidth=2040;
int imageheight=2040;
Mat cameraMatrix;
Mat distCoeffs;
vector<Mat> rvecs, tvecs;

boolean donecla = false;

vector<vector<Point3f>> objectPoints;
vector<vector<Point2f>> imagePoints;

void CMFCApplication2Dlg::OnBnClickedButton6()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src[15];
	Mat img[15];
	Mat show[15];
	char* filename = (char*)malloc(100);
	char* tmp = (char*)malloc(100);

	vector<Point2f> imageCorners;
	vector<Point3f> objectCorners;
	Size boardSize(11, 8);
	Size imageSize(imagewidth, imageheight);

	for (int i = 0; i<boardSize.height; i++) {
		for (int j = 0; j<boardSize.width; j++)
		{
			objectCorners.push_back(Point3f(i, j, 0.0f));
		}
	}

	for (int i = 0; i<15; i++) {
		sprintf(filename, "./images/CameraCalibration/");
		sprintf(tmp, "%d.bmp", i+1);
		strcat(filename, tmp);
		src[i] = imread(filename, 0);
		img[i] = imread(filename, 1);

		bool found = findChessboardCorners(src[i], boardSize, imageCorners);

		cornerSubPix(src[i], imageCorners, Size(5, 5), Size(-1, -1),
			TermCriteria(TermCriteria::MAX_ITER +TermCriteria::EPS,
			30,0.1)); 

		if (imageCorners.size() == boardSize.area()) {
			imagePoints.push_back(imageCorners);
			objectPoints.push_back(objectCorners);
		}
		drawChessboardCorners(img[i], boardSize, imageCorners, found);
		resize(img[i], show[i], Size(img[i].cols*0.4, img[i].rows*0.4));
		cvNamedWindow(tmp);
		imshow(tmp, show[i]);

		int key;
		key = cvWaitKey(5);
	}
	donecla = true;
}

//		3.2

void CMFCApplication2Dlg::OnBnClickedButton7()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	if (donecla) {
		Size imageSize(imagewidth, imageheight);
		calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, 0);
		cout << endl << "intrinsic" << endl << cameraMatrix;
	}
	else {
		printf("run 3.1 first\n");
	}
}

//		3.3
void CMFCApplication2Dlg::OnBnClickedButton8()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int index = adad.GetCurSel();
	if (donecla) {
		Mat rotation_matrix;
		Rodrigues(rvecs[index], rotation_matrix);
		printf("\n\nextrinsic_matrix\n");
		printf("[");
		for (int i = 0; i<3; i++) {
			for (int j = 0; j<3; j++) {
				printf("%f ,", rotation_matrix.at<double>(i, j));
				if (j == 2) {
					printf("%f ;\n", tvecs.at(index).at<double>(i));
				}
			}
		}
		printf("]\n");

	}
	else {
		printf("run 3.1 first\n");
	}
}

//		3.4
void CMFCApplication2Dlg::OnBnClickedButton9()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	if (donecla) {
		printf("\n distortion matrix\n");
		printf("[");
		for (int i = 0; i<5; i++) {
			printf("%f ", distCoeffs.at<double>(i));
			if (i != 4)
				printf(",");
		}
		printf(";]\n");
	}
	else {
		printf("run 3.1 first\n");
	}
}

//		4
void CMFCApplication2Dlg::OnBnClickedButton10()
{
	// TODO: 在此加入控制項告知處理常式程式碼

	vector<Point3f> cube = {
		Point3f(0,0,0),Point3f(0,2,0),Point3f(2,2,0),Point3f(2,0,0),
		Point3f(0,0,2),Point3f(0,2,2),Point3f(2,2,2),Point3f(2,0,2),
	};

	char* filename = (char*)malloc(100);
	char* tmp = (char*)malloc(100);

	if (donecla) {
		cvNamedWindow("AR", CV_WINDOW_AUTOSIZE);
		vector<Point2f> projectedPoints;

		for (int index = 0; index < 15; index++) {
			sprintf(filename, "./images/CameraCalibration/");
			sprintf(tmp, "%d.bmp", index + 1);
			strcat(filename, tmp);

			Mat img = imread(filename, CV_LOAD_IMAGE_COLOR);

			projectPoints(cube, rvecs[index], tvecs[index], cameraMatrix, distCoeffs, projectedPoints);

			for (int j = 0; j<4; j++) {
				line(img, projectedPoints[j], projectedPoints[(j + 1) % 4], Scalar(0, 255, 255), 10);
				line(img, projectedPoints[j + 4], projectedPoints[(j + 1) % 4 + 4], Scalar(255, 255, 0), 10);
				line(img, projectedPoints[j], projectedPoints[j + 4], Scalar(255, 0, 255), 10);
			}

			Mat dst; //創立目標影像
			resize(img, dst, Size(img.cols*0.4, img.rows*0.4));

			imshow("AR", dst);
			cvWaitKey(500);
		}
	}
	else
		printf("please run 3.2 first to get coefficient\n");
}
