
// MFCApplication1Dlg.cpp : 實作檔
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "opencv2\opencv.hpp"

#pragma warning(disable:4996)

using namespace cv;


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


// CMFCApplication1Dlg 對話方塊



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication1Dlg::OnBnClickedButton10)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication1Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication1Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CMFCApplication1Dlg::OnEnChangeEdit4)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 訊息處理常式

BOOL CMFCApplication1Dlg::OnInitDialog()
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

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//1.1
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	IplImage* img = cvLoadImage("./images/dog.bmp");
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	printf("height = %d\n", img->height);
	printf("width = %d\n", img->width);
	cvShowImage("Example1", img);
}

//1.2
void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat testcolor = imread("./images/color.png", CV_LOAD_IMAGE_COLOR);
	int rows = testcolor.rows;
	int cols = testcolor.cols;

	Mat leftimg(rows, cols, CV_8UC3);

	cvtColor(testcolor, testcolor, COLOR_RGB2BGR);
	for (int i = 0; i < testcolor.rows; i++) {
		for (int j = 0; j < testcolor.cols; j++) {
			leftimg.at<Vec3b>(i, j)[0] = testcolor.at<Vec3b>(i, j)[2];
			leftimg.at<Vec3b>(i, j)[1] = testcolor.at<Vec3b>(i, j)[0];
			leftimg.at<Vec3b>(i, j)[2] = testcolor.at<Vec3b>(i, j)[1];
		}
	}
	cvtColor(leftimg, leftimg, COLOR_BGR2RGB);
	imshow("src_image1", testcolor);
	imshow("src_image2", leftimg);
}

//1.3
void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat img, fimg;
	img = imread("./images/dog.bmp");
	flip(img, fimg, 1);
	imshow("Image", img);
	imshow("Flip Image", fimg);
}
//1.4
Mat blend1, blend2, mix;
int slider;

void on_trackbar(int val, void*) {
	double alpha = (double)val / 100.0;
	double beta = (1.0 - alpha);

	addWeighted(blend1, alpha, blend2, beta, 0.0, mix);
	imshow("trackbar", mix);
}

void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	blend1 = imread("./images/dog.bmp");
	flip(blend1, blend2, 1);
	slider = 0;
	int slidermax = 100;
	namedWindow("trackbar", 0);
	createTrackbar("ratio", "trackbar", &slider, slidermax, on_trackbar);
	on_trackbar(slider, 0);
	waitKey(0);
	destroyWindow("trackbar");
}

//2
Mat mag, angle;
int slider2, slider3;

void on_trackbar2(int, void*) {
	Mat magx = Mat::zeros(mag.rows, mag.cols, CV_8U);
	threshold(mag, magx, slider2, 255, THRESH_BINARY);
	imshow("trackbar", magx);
}

void on_trackbar3(int, void*) {
	Mat ang(angle.rows, angle.cols, CV_8U, Scalar(0));
	int ag;
	for (int i = 0; i < angle.rows - 1; i++) {
		for (int j = 0; j < angle.cols - 1; j++) {
			if (slider3 < 10) {
				ag = 10 - slider3;
				if(angle.at<double>(i, j) < slider3 +10 || angle.at<double>(i, j) > 360 - ag)
					ang.at<uchar>(i, j) = 255;
			}
			else if (slider3 > 350) {
				ag = 360 - slider3;
				if (angle.at<double>(i, j) > slider3 -10 || angle.at<double>(i, j) < 10-ag)
					ang.at<uchar>(i, j) = 255;
			}
			else {
				if (angle.at<double>(i, j) > slider3 - 10 && angle.at<double>(i, j) < slider3 + 10)
					ang.at<uchar>(i, j) = 255;
			}
		}
	}
	imshow("direction", ang);
}

void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat gray = imread("./images/M8.jpg", CV_LOAD_IMAGE_COLOR);
	cvtColor(gray, gray, COLOR_RGB2GRAY);
	Mat gsmooth;
	GaussianBlur(gray, gsmooth, Size(3, 3), 0, 0);
	imshow("gsmooth", gsmooth);

	Mat vertical(gsmooth.rows, gsmooth.cols, CV_8U, Scalar(0));
	Mat verf(gsmooth.rows, gsmooth.cols, CV_64F);
	for (int i = 1; i < gsmooth.rows - 1; i++) {
		for (int j = 1; j < gsmooth.cols - 1; j++) {
			int value1 = gsmooth.at<uchar>(i - 1, j - 1) * 1;
			int value2 = gsmooth.at<uchar>(i, j - 1) * 2;
			int value3 = gsmooth.at<uchar>(i + 1, j - 1) * 1;
			int value4 = gsmooth.at<uchar>(i - 1, j + 1) * -1;
			int value5 = gsmooth.at<uchar>(i, j + 1) * -2;
			int value6 = gsmooth.at<uchar>(i + 1, j + 1) * -1;
			int vto = value1 + value2 + value3 + value4 + value5 + value6;
			verf.at<double>(i, j) = (double)vto;
			if (vto < 0) {
				vto = -vto;
			}
			vertical.at<uchar>(i, j) = vto;
		}
	}
	normalize(vertical, vertical, 0, 255, NORM_MINMAX);
	//	threshold(vertical, vertical, 40, 255, THRESH_BINARY);
	imshow("v", vertical);

	Mat horizontal(gsmooth.rows, gsmooth.cols, CV_8U, Scalar(0));
	Mat horf(gsmooth.rows, gsmooth.cols, CV_64F);

	for (int i = 1; i < gsmooth.rows - 1; i++) {
		for (int j = 1; j < gsmooth.cols - 1; j++) {
			int hvalue1 = gsmooth.at<uchar>(i - 1, j - 1) * 1;
			int hvalue2 = gsmooth.at<uchar>(i - 1, j) * 2;
			int hvalue3 = gsmooth.at<uchar>(i - 1, j + 1) * 1;
			int hvalue4 = gsmooth.at<uchar>(i + 1, j - 1) * -1;
			int hvalue5 = gsmooth.at<uchar>(i + 1, j) * -2;
			int hvalue6 = gsmooth.at<uchar>(i + 1, j + 1) * -1;
			int hvto = hvalue1 + hvalue2 + hvalue3 + hvalue4 + hvalue5 + hvalue6;
			horf.at<double>(i, j) = (double)hvto;
			if (hvto < 0) {
				hvto = -hvto;
			}
			horizontal.at<uchar>(i, j) = hvto;
		}
	}
	normalize(horizontal, horizontal, 0, 255, NORM_MINMAX);
	//	threshold(horizontal, horizontal, 40, 255, THRESH_BINARY);
	imshow("h", horizontal);

	mag = Mat::zeros(gsmooth.rows, gsmooth.cols, CV_8U);
	//magnitude(horizontal, vertical, mag);
	mag = (horizontal + vertical)/2;
	imshow("m", mag);
	
	phase(horf,verf,angle,true);
//	normalize(angle, angle, 0, 255, NORM_MINMAX);
//	angle.convertTo(angle, CV_8UC1);
//	imshow("a", angle);

	int slidermax3 = 360;
	namedWindow("direction", 0);
	createTrackbar("dirratio", "direction", &slider3, slidermax3, on_trackbar3);
	on_trackbar3(slider3, 0);

	int slidermax2 = 255;
	namedWindow("trackbar", 0);
	createTrackbar("ratio", "trackbar", &slider2, slidermax2, on_trackbar2);
	on_trackbar2(slider2, 0);
	waitKey(0);
}

//3
void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	IplImage* g1 = cvLoadImage("./images/pyramids_Gray.jpg");
	assert(g1->width % 4 == 0 && g1->height % 4 == 0);
	IplImage* g2 = cvCreateImage(cvSize(g1->width / 2, g1->height / 2), g1->depth, g1->nChannels);
	IplImage* g3 = cvCreateImage(cvSize(g2->width / 2, g2->height / 2), g2->depth, g2->nChannels);
	cvPyrDown(g1, g2, CV_GAUSSIAN_5x5);
	cvPyrDown(g2, g3, CV_GAUSSIAN_5x5);
	IplImage *u2 = cvCreateImage(cvSize(g3->width * 2, g3->height * 2), g3->depth, g3->nChannels);
	IplImage *u1 = cvCreateImage(cvSize(g2->width * 2, g2->height * 2), g2->depth, g2->nChannels);
	cvPyrUp(g3, u2, CV_GAUSSIAN_5x5);
	cvPyrUp(g2, u1, CV_GAUSSIAN_5x5);
	IplImage *l2 = cvCreateImage(cvSize(g3->width * 2, g3->height * 2), g3->depth, g3->nChannels);
	IplImage *l1 = cvCreateImage(cvSize(g2->width * 2, g2->height * 2), g2->depth, g2->nChannels);
	cvSub(g2, u2, l2);
	cvSub(g1, u1, l1);
	IplImage *i2 = cvCreateImage(cvSize(g3->width * 2, g3->height * 2), g3->depth, g3->nChannels);
	IplImage *i1 = cvCreateImage(cvSize(g2->width * 2, g2->height * 2), g2->depth, g2->nChannels);
	cvAdd(u2, l2, i2);
	cvAdd(u1, l1, i1);
	//	cvNamedWindow("g1", CV_WINDOW_AUTOSIZE);
	//	cvShowImage("g1", g1);
	cvNamedWindow("g2", CV_WINDOW_AUTOSIZE);
	cvShowImage("g2", g2);
	//	cvNamedWindow("g3", CV_WINDOW_AUTOSIZE);
	//	cvShowImage("g3", g3);
	cvNamedWindow("l1", CV_WINDOW_AUTOSIZE);
	cvShowImage("l1", l1);
	//	cvNamedWindow("l2", CV_WINDOW_AUTOSIZE);
	//	cvShowImage("l2", l2);
	cvNamedWindow("i1", CV_WINDOW_AUTOSIZE);
	cvShowImage("i1", i1);
	cvNamedWindow("i2", CV_WINDOW_AUTOSIZE);
	cvShowImage("i2", i2);
}

//4.1
void CMFCApplication1Dlg::OnBnClickedButton7()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src = imread("./images/QR.png", CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst;
	threshold(src, dst, 80, 255, THRESH_BINARY);
	imshow("origin", src);
	imshow("threshold", dst);
}

//4.2
void CMFCApplication1Dlg::OnBnClickedButton8()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	Mat src = imread("./images/QR.png", CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst2;
	adaptiveThreshold(src, dst2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 19, -1);
	imshow("origin", src);
	imshow("threshold2", dst2);
}


void CMFCApplication1Dlg::OnBnClickedButton9()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CEdit* pBoxOne1, *pBoxOne2, *pBoxOne3, *pBoxOne4;
	pBoxOne1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	pBoxOne2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	pBoxOne3 = (CEdit*)GetDlgItem(IDC_EDIT3);
	pBoxOne4 = (CEdit*)GetDlgItem(IDC_EDIT4);
	CString str1, str2, str3, str4;
	pBoxOne1->GetWindowText(str1);
	pBoxOne2->GetWindowText(str2);
	pBoxOne3->GetWindowText(str3);
	pBoxOne4->GetWindowText(str4);
	double angle = _tstof(str1);
	double scale = _tstof(str2);
	double tx = _tstoi(str3);
	double ty = _tstoi(str4);

	Mat src = imread("./images/OriginalTransform.png");
	Mat dst1 = Mat::zeros(src.rows, src.cols, src.type());
	Mat dst2 = Mat::zeros(src.rows, src.cols, src.type());

	//設定旋轉中心、旋轉角度和縮放倍率
	Point center = Point(130, 125);
	Mat rot_mat = getRotationMatrix2D(center, angle, scale);
	warpAffine(src, dst1, rot_mat, dst1.size());

	Mat T = Mat::zeros(2, 3, CV_32FC1);

	T.at<float>(0, 0) = 1;
	T.at<float>(0, 2) = (float)tx;
	T.at<float>(1, 1) = 1;
	T.at<float>(1, 2) = (float)ty;
	warpAffine(dst1, dst2, T, dst2.size());

	imshow("origin", src);
	imshow("Affine_2", dst2);
}

//5.2
int index = 0;
Point TopLeft(-1, -1);
Point TopRight(-1, -1);
Point DownRight(-1, -1);
Point DownLeft(-1, -1);

Mat fimg;
void onMouse(int Event, int x, int y, int, void*) {
	if (Event == CV_EVENT_LBUTTONDOWN) {
		if (index == 0) {
			TopLeft.x = x;
			TopLeft.y = y;
			index++;
		}
		else if (index == 1) {
			TopRight.x = x;
			TopRight.y = y;
			index++;
		}
		else if (index == 2) {
			DownRight.x = x;
			DownRight.y = y;
			index++;
		}
		else if (index == 3) {
			index = 0;
			DownLeft.x = x;
			DownLeft.y = y;
			Point2f t1[] = { TopLeft,DownLeft,TopRight,DownRight};
			Point2f t2[] = { Point2f(20,20),Point2f(20,450),Point2f(450,20),Point2f(450,450)};
			Mat pm1 = getPerspectiveTransform(t1, t2);
			Mat pm2,end;
			warpPerspective(fimg, pm2, pm1, fimg.size(), INTER_LINEAR);

			end = pm2(Rect(0, 0, 450, 450)); //裁切
			namedWindow("result", WINDOW_NORMAL);
			imshow("result", end);
		}
	}
}


void CMFCApplication1Dlg::OnBnClickedButton10()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	namedWindow("img", WINDOW_NORMAL);
	setMouseCallback("img", onMouse, NULL);
	fimg = imread("./images/OriginalPerspective.png");
	imshow("img", fimg);
}


void CMFCApplication1Dlg::OnEnChangeEdit1()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
}


void CMFCApplication1Dlg::OnEnChangeEdit2()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
}


void CMFCApplication1Dlg::OnEnChangeEdit3()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
}


void CMFCApplication1Dlg::OnEnChangeEdit4()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
}
