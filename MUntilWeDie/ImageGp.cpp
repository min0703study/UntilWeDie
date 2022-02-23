#include "Stdafx.h"
#include "ImageGp.h"

HRESULT ImageGp::init(string fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	if (_imageInfo != NULL) this->release();

	_image = new Gdiplus::Image(wstring(fileName.begin(), fileName.end()).c_str());

	if (_image == nullptr)
	{
		release();
		return E_FAIL;
	}

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;

	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;

	_imageInfo->maxFrameX = maxFrameX - 1;
	_imageInfo->maxFrameY = maxFrameY - 1;
	
	_imageInfo->frameWidth = width / maxFrameX;
	_imageInfo->frameHeight = height / maxFrameY;

	return S_OK;
}

void ImageGp::release()
{
	SAFE_DELETE(_imageInfo);
	SAFE_DELETE(_image);
}
