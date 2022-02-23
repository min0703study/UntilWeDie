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

void GdiPlusManager::release()
{
	
}
