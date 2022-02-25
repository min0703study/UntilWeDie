#pragma once
#include "SingletonBase.h"

#define GAME_FONT L"Leferi Base Type Bold"

using namespace Gdiplus;

class ImageGp;

class GdiPlusManager : public SingletonBase<GdiPlusManager>
{
private:
	typedef map<string, ImageGp*> mapImageList;
	typedef map<string, ImageGp*>::iterator mapImageIter;

	mapImageList _mImageList;

	FontFamily*  fontFamily;
	StringFormat centerFormat;

public:
	HRESULT init();

	ImageGp * findImage(string strKey);
	ImageGp * addFrameImage(string strKey, const string fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor);

	void frameRender(HDC hdc, string strKey, float x, float y);

	void drawCProgressBar(HDC hdc, float x, float y, float width, float height, float value, float maxValue);

	void release();
};

