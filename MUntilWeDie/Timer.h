#pragma once

class Timer
{
private:
	float _timeScale;		//����ð� ����
	float _timeElapsed;		//������ �ð��� ����ð��� �����
	bool _isHardware;		//���� Ÿ�̸� ���� ����

	__int64 _curTime;			// ���� �ð�
	__int64 _lastTime;			// ���� �ð�
	__int64 _periodFrequency;	// �ð� �ֱ�

	unsigned long _frameRate;
	unsigned long _FPSFrameCount;
	float _FPSTimeElapsed;
	float _worldTime;
public:
	HRESULT init(void);
	// ���� �ð��� ���
	void tick(float lockFPS = 0.0f);

	// ���� FPS
	unsigned long getFrameRate(char* str = nullptr) const;
	// ������ �ð��� ���� �ð��� �����
	inline float getElapsedTime(void) const { return _timeElapsed; }
	// ��ü ��� �ð�
	inline float getWorldTime(void) const { return _worldTime; }

	Timer() {}
	~Timer() {}
};