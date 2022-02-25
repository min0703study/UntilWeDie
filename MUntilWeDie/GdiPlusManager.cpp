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

void GdiPlusManager::drawCProgressBar(HDC hdc, float x, float y, float width, float height, float value, float maxValue) {

	using namespace Gdiplus;
	float _value = value / (maxValue / 100);
	// fill the background
	const float startY = y;
	const float penWidth = 32.0f;
	const float dashOffset = -559.0f + (float(_value) * 559.0f * 0.01f);

	std::vector<float> dashPattern;
	dashPattern.push_back(559.0f / penWidth);
	dashPattern.push_back(559.0f / penWidth);

	Gdiplus::GraphicsPath path;
	path.StartFigure();
	path.AddBezier(Gdiplus::PointF(99.99999, 11.05255 + startY),
		Gdiplus::PointF(51.31296, 11.05255 + startY),
		Gdiplus::PointF(11.05254, 51.31297 + startY),
		Gdiplus::PointF(11.05254, 100 + startY));
	path.AddBezier(Gdiplus::PointF(11.05254, 100 + startY),
		Gdiplus::PointF(11.05254, 148.6871 + startY),
		Gdiplus::PointF(51.31297, 188.9475 + startY),
		Gdiplus::PointF(99.99999, 188.9475 + startY));
	path.AddBezier(Gdiplus::PointF(99.99999, 188.9475 + startY),
		Gdiplus::PointF(148.687, 188.9475 + startY),
		Gdiplus::PointF(188.9474, 149.1552 + startY),
		Gdiplus::PointF(188.9474, 100 + startY));
	path.AddBezier(Gdiplus::PointF(188.9474, 100 + startY),
		Gdiplus::PointF(188.9474, 50.84483 + startY),
		Gdiplus::PointF(149.1552, 11.05255 + startY),
		Gdiplus::PointF(99.99998, 11.05255 + startY));
	path.CloseFigure();

	Gdiplus::Pen pen(Gdiplus::Color(255, 0, 0, 0));
	pen.SetWidth(penWidth);
	pen.SetDashOffset(dashOffset / penWidth);

	const Gdiplus::LineCap lineCapStart = Gdiplus::LineCapFlat;
	const Gdiplus::LineCap lineCapEnd = Gdiplus::LineCapFlat;
	const Gdiplus::DashCap dashCap = Gdiplus::DashCapFlat;

	pen.SetLineCap(lineCapStart, lineCapEnd, dashCap);

	const Gdiplus::LineJoin lineJoin = Gdiplus::LineJoinMiter;
	pen.SetLineJoin(lineJoin);
	pen.SetMiterLimit(4.0f);

	// configure dash style to custom (meaning that dash pattern should be used)
	pen.SetDashStyle(Gdiplus::DashStyleCustom);

	// configure dash pattern
	pen.SetDashPattern(&dashPattern[0], dashPattern.size());

	// draw the path using GDI+
	Gdiplus::Graphics graphics(hdc);
	graphics.DrawPath(&pen, &path);
}

void GdiPlusManager::release()
{
	
}
