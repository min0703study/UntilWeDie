#include "Stdafx.h"
#include "ImageManager.h"
#include "ImageBase.h"

HRESULT ImageManager::init(void)
{
	return S_OK;
}

void ImageManager::release(void)
{
	this->deleteAll();
}

ImageBase* ImageManager::addImage(string strKey, int width, int height)
{
	//�߰��Ϸ��� �̹����� �����ϴ��� Ű������ Ȯ��
	ImageBase* img = findImage(strKey);

	if (img) return img;//������ ��ȯ

	img = new ImageBase;
	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//_mImageList.insert(pair<string, Image*>(strKey, img));
	_mImageList.insert(make_pair(strKey, img));//���� ��������

	return img;
}

ImageBase* ImageManager::addImage(string strKey, const char * fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	ImageBase* img = findImage(strKey);

	if (img) return img;//������ ��ȯ

	img = new ImageBase;
	if (FAILED(img->init(fileName, width, height, isTrans, transColor)))//������ ����
	{
		cout << "�̹��� ���� ���� : " << strKey << endl;
		SAFE_DELETE(img);
		return NULL;
	}

	//_mImageList.insert(pair<string, Image*>(strKey, img));
	_mImageList.insert(make_pair(strKey, img));//���� ��������

	return img;
}

ImageBase* ImageManager::addImage(string strKey, const char * fileName, float x, float y, int width, int height, BOOL isTrans, COLORREF transColor)
{
	ImageBase* img = findImage(strKey);

	if (img) return img;//������ ��ȯ

	img = new ImageBase;
	if (FAILED(img->init(fileName, x, y, width, height, isTrans, transColor)))//������ ����
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//_mImageList.insert(pair<string, Image*>(strKey, img));
	_mImageList.insert(make_pair(strKey, img));//���� ��������

	return img;
}

ImageBase* ImageManager::addFrameImage(string strKey, const char * fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	ImageBase* img = findImage(strKey);

	if (img) return img;//������ ��ȯ

	img = new ImageBase;
	if (FAILED(img->init(fileName, width, height, maxFrameX, maxFrameY, isTrans, transColor)))//������ ����
	{
		cout << "�̹��� ���� ���� : " << strKey << endl;
		SAFE_DELETE(img);
		return NULL;
	}

	//_mImageList.insert(pair<string, Image*>(strKey, img));
	_mImageList.insert(make_pair(strKey, img));//���� ��������

	return img;
}

ImageBase* ImageManager::addFrameImage(string strKey, const char * fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	ImageBase* img = findImage(strKey);

	if (img) return img;//������ ��ȯ

	img = new ImageBase;
	if (FAILED(img->init(fileName, x, y, width, height, maxFrameX, maxFrameY, isTrans, transColor)))//������ ����
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//_mImageList.insert(pair<string, Image*>(strKey, img));
	_mImageList.insert(make_pair(strKey, img));//���� ��������

	return img;
}

ImageBase * ImageManager::findImage(string strKey)
{
	auto key = _mImageList.find(strKey);

	//�˻��� Ű�� ã�Ҵٸ�
	if (key != _mImageList.end())
	{
		return key->second;
	}
	else {
		cout << "�̹��� �˻� ���� : " << strKey << endl;
	}
	//�˻��� Ű�� �̹����� ��ã�Ҵٸ� ����
	return nullptr;
}

bool ImageManager::deleteImage(string strKey)
{
	auto key = _mImageList.find(strKey);
	if (key != _mImageList.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);

		return true;
	}
	return false;
}

bool ImageManager::deleteAll()
{
	auto iter = _mImageList.begin();//   mapImageIter iter = _mImageList.begin();�� �� �˾ƺ��⽱��

	for (; iter != _mImageList.end();)
	{
		if (iter->second != NULL)
		{
			iter->second->release();//�������� �����ְڴ�
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	_mImageList.clear();
	return true;
}
////////////////////////
// �Ϲ� ����         //
/////////////////////
void ImageManager::render(string strKey, HDC hdc)
{
	ImageBase* img = findImage(strKey);
	if (img) img->render(hdc);
}

void ImageManager::render(string strKey, HDC hdc, int destX, int destY)
{
	ImageBase* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY);
}

void ImageManager::render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	ImageBase* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}
////////////////////////
// ���� ����         //
/////////////////////
void ImageManager::alphaRender(string strKey, HDC hdc, BYTE alpha)
{
	ImageBase* img = findImage(strKey);
	if (img) img->alphaRender(hdc, alpha);
}

void ImageManager::alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha)
{
	ImageBase* img = findImage(strKey);
	if (img) img->alphaRender(hdc, destX, destY, alpha);
}

void ImageManager::alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	ImageBase* img = findImage(strKey);
	if (img) img->alphaRender(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight, alpha);
}
////////////////////////
// ������ ����         //
/////////////////////
void ImageManager::frameRender(string strKey, HDC hdc, int destX, int destY)
{
	ImageBase* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY);
}

void ImageManager::frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	ImageBase* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}

void ImageManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	ImageBase* img = findImage(strKey);
	if (img) img->loopRender(hdc, drawArea, offsetX, offsetY);
}

void ImageManager::loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{
	ImageBase* img = findImage(strKey);
	if (img) img->loopAlphaRender(hdc, drawArea, offsetX, offsetY, alpha);
}

ImageManager::ImageManager()
{
}

ImageManager::~ImageManager()
{
}