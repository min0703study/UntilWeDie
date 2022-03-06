#include "Stdafx.h"
#include "GdiPlusManager.h"
#include "ImageGp.h"

HRESULT GdiPlusManager::init()
{
	fontFamily = new FontFamily(GAME_FONT);
	centerFormat.SetAlignment(StringAlignmentCenter);

	return S_OK;
}

ImageGp* GdiPlusManager::findImage(string strKey)
{
	auto key = _mImageList.find(strKey);
	if (key != _mImageList.end())
	{
		return key->second;
	}

	return nullptr;
}

ImageGp* GdiPlusManager::addFrameImage(string strKey, const string fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	ImageGp* img = findImage(strKey);
	if (img) return img;

	img = new ImageGp();
	if (FAILED(img->init(fileName, width, height, maxFrameX, maxFrameY, isTrans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));
}

void GdiPlusManager::frameRender(HDC hdc, string strKey, float x, float y)
{
	ImageGp* img = findImage(strKey);
	if (!img) return;

	Graphics gh(hdc);
	ImageAttributes imageAtt;

	imageAtt.SetColorKey(
		Color(255, 0, 255),
		Color(255, 0, 255),
		ColorAdjustTypeDefault
	);

	Gdiplus::RectF rcf = Gdiplus::RectF(x, y, img->getFrameWidth(), img->getFrameHeight());

	gh.DrawImage(
		img->getImage(),
		rcf,
		0, 0, 
		img->getWidth(), 
		img->getHeight(),
		UnitPixel,
		&imageAtt);
}

void GdiPlusManager::drawText(HDC hdc, std::wstring message, float x, float y, int size, Color color)
{
	Graphics gh(hdc);
	Font        font(fontFamily, size, FontStyleRegular, UnitPixel);
	SolidBrush  solidBrush(color);
	gh.DrawString(message.c_str(), -1, &font, PointF(x, y), &solidBrush);
}


void GdiPlusManager::drawCProgressBar(HDC hdc, float startX, float startY, int size, float value, float maxValue) {

	using namespace Gdiplus;

	//민채영 - 디테일 조정
	startX += 0.2;

	Gdiplus::GraphicsPath path;
	path.StartFigure();
	path.AddBezier(Gdiplus::PointF(startX, (size * 4) + startY),
		Gdiplus::PointF(startX + size, (size * 4) + startY),
		Gdiplus::PointF(startX + (size * 2), (size * 3) + startY),
		Gdiplus::PointF(startX + (size * 2), (size * 2) + startY));
	path.AddBezier(Gdiplus::PointF(startX + (size * 2), (size * 2) + startY),
		Gdiplus::PointF(startX + (size * 2), size + startY),
		Gdiplus::PointF(startX + size, startY),
		Gdiplus::PointF(startX, startY));
	path.AddBezier(Gdiplus::PointF(startX, startY),
		Gdiplus::PointF(startX - size, startY),
		Gdiplus::PointF(startX - (size * 2), size + startY),
		Gdiplus::PointF(startX - (size * 2), (size * 2) + startY));
	path.AddBezier(Gdiplus::PointF(startX - (size * 2), (size * 2) + startY),
		Gdiplus::PointF(startX - (size * 2), (size * 3) + startY),
		Gdiplus::PointF(startX - size, (size * 4) + startY),
		Gdiplus::PointF(startX, (size * 4) + startY));
	path.CloseFigure();
	
	Gdiplus::Pen pen(C_DASH_PROGRESS_BAR);
	const float penWidth = 6.0f;
	pen.SetWidth(penWidth);

	float curValue = value / (maxValue / 110);
	curValue += 0.2;
	float dashPattern[2] = { curValue * 0.1, (110 - curValue) * 0.1};

	pen.SetDashPattern(&dashPattern[0], 2);

	Gdiplus::Pen bgPen(Color(50, 0, 0, 0));
	bgPen.SetWidth(penWidth);

	Gdiplus::Graphics graphics(hdc);
	graphics.DrawPath(&bgPen, &path);
	graphics.DrawPath(&pen, &path);
}

void GdiPlusManager::release()
{
	
}
