#pragma once
class ImageGp
{
public:
	enum IMAGE_LOAD_KIND // � ������� �������ž�?
	{
		LOAD_RESOURCE = 0,      // ���ҽ��� �����ð���
		LOAD_FILE,            //���Ϸ� �����ð���
		LOAD_EMPTY,            //�� ��Ʈ������ �����ð���
		LOAD_END            // �� �����ð���
	};

	typedef struct tagImage
	{
		float			x;
		float			y;
		int            currentFrameX;
		int            currentFrameY;
		int            maxFrameX;
		int            maxFrameY;
		int            frameWidth;
		int            frameHeight;
		BYTE         loadType;   //�̹����� �ε� Ÿ��

		tagImage()
		{
			x = y = 0;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO   _imageInfo;
	Gdiplus::Image* _image;
public:
	HRESULT init(string fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor);
	void release();

	inline float getX(void) { return _imageInfo->x; }
	inline void setX(float x) { _imageInfo->x = x; }

	// �̹��� Y ��ǥ
	inline float getY(void) { return _imageInfo->y; }
	inline void setY(float y) { _imageInfo->y = y; }

	// �̹��� ����, ���� ũ��
	inline int getWidth(void) {
		return _image->GetWidth();
	}
	inline int getHeight(void) {
		return _image->GetHeight();
	}

	
	//������ X
	inline int getFrameX(void) { return _imageInfo->currentFrameX; }
	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}
	}

	//������ Y
	inline int getFrameY(void) { return _imageInfo->currentFrameY; }
	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}
	}

	// �̹��� 1������ ����, ���� ũ��
	inline int getFrameWidth(void) { return _imageInfo->frameWidth; }
	inline int getFrameHeight(void) { return _imageInfo->frameHeight; }

	// �ִ� ������ x, y ����
	inline int getMaxFrameX(void) { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY(void) { return _imageInfo->maxFrameY; }

	inline Gdiplus::Image* getImage(void) { return _image; }

	ImageGp() {};
	~ImageGp() {};
};
