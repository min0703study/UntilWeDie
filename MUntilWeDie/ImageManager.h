#pragma once

#include "SingletonBase.h"

class Animation;
class ImageBase;

class ImageManager : public SingletonBase <ImageManager>
{
private:
	//������ ���� �̹��� ��
	typedef map<string, ImageBase*> mapImageList;

	//������ ���� �̹��� ����� �ݺ���
	typedef map<string, ImageBase*>::iterator mapImageIter;;
private:
	mapImageList _mImageList;
public:
	HRESULT init(void);
	void release(void);

	ImageBase* addImage(string strKey, int width, int height);
	ImageBase* addImage(string strKey, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));//���ҽ��� �ƴ϶� ���ϸ����� �����ðž�
	ImageBase* addImage(string strKey, const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(255, 0, 255));
	ImageBase* addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = TRUE, COLORREF transColor = RGB(255, 0, 255));
	ImageBase* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = TRUE, COLORREF transColor = RGB(0, 0, 0));
	//�̹��� Ű������ ã��
	ImageBase* findImage(string strKey);
	//�̹��� Ű������ ����
	bool deleteImage(string strKey);

	//�̹��� ��ü ����
	bool deleteAll();

	//����
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//���� ����
	void alphaRender(string strKey, HDC hdc, BYTE alpha);      //���
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);//���ĳ���� ��
	void alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);//Ŭ���ξ��ķ���

	//������ ����
	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//���� ����
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);
public:
	ImageManager();
	~ImageManager();
};